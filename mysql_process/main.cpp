/*************************************************************************
	> File Name: 2.ConnectionPool.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Jan 2025 09:04:53 PM CST
 ************************************************************************/

#include <iostream>
#include <memory>
#include "MysqlConn.h"

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
	query();

	return 0;
}