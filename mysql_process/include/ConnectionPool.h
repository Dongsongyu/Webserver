/*************************************************************************
	> File Name: ConnectionPool.h
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Jan 2025 10:36:08 AM CST
 ************************************************************************/

#pragma once
#include <queue>
#include <mutex>
#include <condition_variable>
#include "MysqlConn.h"
class ConnectionPool {
public:
	static ConnectionPool* getConnectPool();
	ConnectionPool(const ConnectionPool& obj) = delete;
	ConnectionPool& operator=(const ConnectionPool& obj) = delete;
	std::shared_ptr<MysqlConn> getConnectionPool();
	~ConnectionPool();
private:
	ConnectionPool();
	bool parseJsonFile();
	void produceConnection();
	void recycleConnection();
	void addConnection();
	
	std::string m_ip;
	std::string m_user;
	std::string m_passwd;
	std::string m_dbName;
	unsigned short m_port;
	int m_minSize;
	int m_maxSize;
	int m_timeout;
	int m_maxIdTime;
	std::queue<MysqlConn*> m_connectionQ;
	std::mutex m_mutexQ;
	std::condition_variable m_cond;
};