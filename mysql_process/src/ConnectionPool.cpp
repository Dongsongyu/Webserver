/*************************************************************************
	> File Name: ConnectionPool.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Jan 2025 10:36:15 AM CST
 ************************************************************************/

#include "ConnectionPool.h"
#include <jsoncpp/json/json.h>
#include <fstream>
#include <thread>

ConnectionPool* ConnectionPool::getConnectPool() {
	static ConnectionPool pool;
	return &pool;
}

bool ConnectionPool::parseJsonFile() {
	std::ifstream ifs("dbconf.json");
	Json::Reader rd;
	Json::Value root;
	rd.parse(ifs, root);
	if (root.isObject()) {
		m_ip = root["ip"].asString();
		m_port = root["port"].asInt();
		m_user = root["userName"].asString();
		m_passwd = root["password"].asString();
		m_dbName = root["dbName"].asString();
		m_minSize = root["minSize"].asInt();
		m_maxSize = root["maxSize"].asInt();
		m_timeout = root["timeout"].asInt();
		return true;
	}
	return false;
}

void ConnectionPool::produceConnection() {
	while(true) {
		std::unique_lock<std::mutex> locker(m_mutexQ);
		while(m_connectionQ.size() >= m_minSize) {
			m_cond.wait(locker);
		}
		addConnection();
		m_cond.notify_all();
	}
}

void ConnectionPool::recycleConnection() {
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::lock_guard<std::mutex> locker(m_mutexQ);
		while (m_connectionQ.size() > m_minSize) {
			MysqlConn *conn = m_connectionQ.front();
			if (conn->getAliveTime() >= m_maxIdleTime) {
				m_connectionQ.pop();
				delete conn;
			}
			else {
				break;
			}
		}
	}
}

void ConnectionPool::addConnection() {
	MysqlConn *conn = new MysqlConn;
	conn->connect(m_user, m_passwd, m_dbName, m_ip, m_port);
	//记录时间戳
	conn->refreshAliveTime();
	m_connectionQ.push(conn);
}

std::shared_ptr<MysqlConn> ConnectionPool::getConnectionPool() {
	std::unique_lock<std::mutex> locker(m_mutexQ);
	while (m_connectionQ.empty()) {
		if (std::cv_status::timeout == m_cond.wait_for(locker, std::chrono::milliseconds(m_timeout))) {
			if (m_connectionQ.empty()) {
				//return nullptr;
				continue;
			}
		}
	}
	std::shared_ptr<MysqlConn> connptr(m_connectionQ.front(), [this] (MysqlConn* conn) {
		std::lock_guard<std::mutex> locker(m_mutexQ);
		conn->refreshAliveTime();
		m_connectionQ.push(conn);
	});
	m_connectionQ.pop();
	m_cond.notify_all();

	return connptr;
}

ConnectionPool::~ConnectionPool() {
	while (!m_connectionQ.empty()) {
		MysqlConn *conn = m_connectionQ.front();
		m_connectionQ.pop();
		delete conn;
	}
}

ConnectionPool::ConnectionPool() {
	// 加载配置文件
	if (!parseJsonFile()) {
		return ;
	}
	for (int i = 0; i < m_minSize; ++i) {
		addConnection();
	}
	std::thread producer(&ConnectionPool::produceConnection, this);
	std::thread recycler(&ConnectionPool::recycleConnection, this);
	producer.detach();
	recycler.detach();
}
