#include "mymysql.h"
#include <QMessageBox>
#include <string.h>


mymysql::mymysql()
{
    mysql_init(&mysql);
    connection = NULL;
    memset(buf,0,sizeof(buf));
}

mymysql::~mymysql()
{
    if(connection)
    {
        mysql_close(connection);

    }
}

int mymysql::sqlConnect(const char *HostName, const char *User, const char *Password, const char *DBname)
{
    connection = mysql_real_connect(&mysql,HostName,User,Password,DBname,0,0,0);
    if(connection == NULL)
    {
        memset(buf,0,sizeof(buf));
        strcpy(buf,mysql_error(&mysql));
        //        QMessageBox::information(0,"��ʾ",);
        return -1;
    }
    else
    {
        mysql_query(connection,"set names utf8");
        //        mysql_query(connection,"set names utf8");
        return 0;
    }
}

const char *mymysql::geterror()
{
    return buf;
}

void mymysql::sql_disconnect()
{
    if(connection)
    {
        mysql_close(connection);
        connection = NULL;
    }
}

int mymysql::sql_exec(const char *SQL)
{
    if(mysql_query(connection,SQL) != 0)
    {
        memset(buf,0,sizeof(buf));
        strcpy(buf,mysql_error(&mysql));
        return -1;
    }
    return 0;
}

int mymysql::sql_open(const char *SQL, QStandardItemModel **p)
{
    if(mysql_query(connection,SQL) != 0)
    {
        memset(buf,0,sizeof(buf));
        strcpy(buf,mysql_error(&mysql));
        return -1;
    }

    MYSQL_RES *result = mysql_store_result(connection);
    if(result == NULL)
    {
        memset(buf,0,sizeof(buf));
        strcpy(buf,mysql_error(&mysql));
        return -1;
    }
    int rowcount = mysql_affected_rows(connection);//SQL���ִ�к��ж�����
    int fieldcount =  mysql_field_count(connection);//SQL���ִ�к��ж�����

    *p = new QStandardItemModel(rowcount,fieldcount);

    MYSQL_FIELD * field;

    int i = 0;
    int j = 0;
    for(i = 0; i<fieldcount; i++)
    {
        field = mysql_fetch_field(result);
        (*p)->setHeaderData(i,Qt::Horizontal,field->name);
    }
    for(i = 0;i < rowcount;i++)//ѭ������ÿһ��

    {
        MYSQL_ROW row = mysql_fetch_row(result);
        for(j=0;j<fieldcount;j++) //ѭ������ÿһ��
        {
            (*p)->setData((*p)->index(i,j,QModelIndex()),row[j]);
            // QMessageBox::information(0,"",row[j]);
        }
    }
    mysql_free_result(result);
    return 0;
}

