/*************************************************************************
	> File Name: 2.ConnectionPool.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Jan 2025 09:04:53 PM CST
 ************************************************************************/

#include <iostream>
#include <memory>
#include <thread>
#include "MysqlConn.h"
#include "ConnectionPool.h"

//1.单线程:使用/不使用连接池
//2.多线程:使用/不使用连接池

void op1(int begin, int end) {
	for (int i = begin; i < end; i++) {
		MysqlConn conn;
		conn.connect("root", "123456", "testdb", "106.54.35.218", 3306);
        char sql[1024] = {0};
        sprintf(sql,"insert into person values(%d, 18, 'man', 'starry')", i);
        conn.update(sql);
	}
}

// void op2(ConnectionPool* pool, int begin, int end) {
//     for (int i = begin; i < end; ++i) {
//         std::shared_ptr<MysqlConn> conn = pool->getConnectionPool();
//         if (!conn) {
//             std::cerr << "Failed to get a connection from the pool!" << std::endl;
//             continue;
//         }
        
//         // 连接成功，打印信息
//         std::cout << "Successfully got a connection from the pool!" << std::endl;

//         char sql[1024] = {0};
//         sprintf(sql, "insert into person values(%d, 18, 'man', 'starry')", i);
//         if (!conn->update(sql)) {
//             std::cerr << "Failed to execute SQL: " << sql << std::endl;
//         } else {
//             std::cout << "SQL executed successfully: " << sql << std::endl;
//         }
//     }
// }

void op2(ConnectionPool* pool, int begin, int end) {
    for (int i = begin; i < end; i++) {
        std::shared_ptr<MysqlConn> conn = pool->getConnectionPool();
        char sql[1024] = {0};
        sprintf(sql, "insert into person values(%d, 18, 'man', 'starry')", i);
        conn->update(sql);
    }
}


void test1() {
#if 0
	//非连接池,单线程,用时 : 14305302961纳秒, 14305 毫秒
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	op1(0, 500);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	auto length = end - begin;
	std::cout << "非连接池,单线程,用时 : " << length.count() << "纳秒, "
			<< length.count() / 1000000 << " 毫秒" << std::endl;
#else
	ConnectionPool* pool = ConnectionPool::getConnectPool();
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    op2(pool, 0, 5);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    auto length = end - begin;
    std::cout << "连接池，单线程，用时：" << length.count() << "纳秒，" << length.count() / 1000000 << "毫秒" << std::endl;
#endif
}

void test2() {
#if 0
	MysqlConn conn;
	conn.connect("root", "123456", "testdb", "106.54.35.218", 3306);
	//非连接池,单线程,用时 : 13374138983纳秒, 13374 毫秒
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	std::thread t1(op1, 0, 100);
	std::thread t2(op1, 100, 200);
	std::thread t3(op1, 200, 300);
	std::thread t4(op1, 300, 400);
	std::thread t5(op1, 400, 500);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	auto length = end - begin;
	std::cout << "非连接池,单线程,用时 : " << length.count() << "纳秒, "
			<< length.count() / 1000000 << " 毫秒" << std::endl;
#else
	ConnectionPool *pool = ConnectionPool::getConnectPool();
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	std::thread t1(op2, pool, 0, 100);
	std::thread t2(op2, pool, 100, 200);
	std::thread t3(op2, pool, 200, 300);
	std::thread t4(op2, pool, 300, 400);
	std::thread t5(op2, pool, 400, 500);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	auto length = end - begin;
	std::cout << "非连接池,单线程,用时 : " << length.count() << "纳秒, "
			<< length.count() / 1000000 << " 毫秒" << std::endl;
#endif
}

int query() {
	MysqlConn conn;
	conn.connect("root", "123456", "testdb", "106.54.35.218", 3306);
	std::string sql = "insert into person(age, sex, name) values(29, 'Male', 'lucy')";
	bool flag = conn.update(sql);
	std::cout << "flag value: " << flag << std::endl;

	sql = "select * from person";
	conn.query(sql);
	while (conn.next()) {
		std::cout << conn.value(0) << ", " 
		<< conn.value(1) << ", " 
		<< conn.value(2) << ", " 
		<< conn.value(3) << std::endl;
	}
	return 0;
}

int main()
{
	//query();
	//test1();
	test2();

	return 0;
}