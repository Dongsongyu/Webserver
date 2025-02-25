/*************************************************************************
	> File Name: MysqlConn.h
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Jan 2025 09:05:32 PM CST
 ************************************************************************/

#pragma once
#include <iostream>
#include <mysql/mysql.h>
#include <chrono>

class MysqlConn {
public:
	//初始化数据库连接
	MysqlConn();
	//释放数据库连接
	~MysqlConn();
	//连接数据库
	bool connect(std::string user, std::string passwd, std::string dbName, std::string ip, unsigned short port = 3306);
	//更新数据库
	bool update(std::string sql);
	//查询数据库
	bool query(std::string sql);
	//遍历查询得到的结果集
	bool next();
	//得到结果集中的字段集
	std::string value(int index);
	//事务操作
	bool transaction();
	//提交事务
	bool commit();
	//事务回滚
	bool rollback();
	//刷新起始的空闲时间点
	void refreshAliveTime();
	//计算连接存活的总时长
	long long getAliveTime();
private:
	void freeResult();
	MYSQL* m_conn = nullptr;//数据库对象
    MYSQL_RES* m_result = nullptr;//数据库结果集
    MYSQL_ROW m_row = nullptr;//结构为MYSQL_ROW的下一行结果
    std::chrono::steady_clock::time_point m_alivetime;  
};
