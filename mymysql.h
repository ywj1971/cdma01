#ifndef MYMYSQL_H
#define MYMYSQL_H

#include <windows.h>
#include <C:\mysql-win32\include\mysql.h>
#include <QStandardItemModel>

//#include <mysql/mysql.h>

class mymysql
{
public:
    mymysql();
    ~mymysql();
    int sqlConnect(const char *HostName, const char *User, const char *Password, const char *DBname);
    const char *geterror();
    void sql_disconnect();
    int sql_exec(const char *SQL);
    int sql_open(const char *SQL,QStandardItemModel **p);



private:
    MYSQL *connection;
    MYSQL mysql;
    char buf[1024];
};

#endif // MYMYSQL_H
