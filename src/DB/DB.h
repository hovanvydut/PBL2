#ifndef DB_H
#define DB_H

#include <QSqlDatabase>
#include <QSqlQuery>

class DB
{
private:
    static DB* instance;
    QSqlDatabase conn;
    QSqlQuery *query;
    DB();
public:
    ~DB();
    static DB* getInstance();
    QSqlQuery* getQuery();

};

#endif // DB_H
