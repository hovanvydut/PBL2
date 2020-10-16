#include "DB.h"

DB* DB::instance = nullptr;

DB::DB()
{
    QString connectString = "DRIVER={SQL Server};SERVER=ADMINISTRATOR, 1433;DATABASE=LibraryManagement;Trusted=true;";
    this->conn = QSqlDatabase::addDatabase("QODBC");
    this->conn.setDatabaseName(connectString);
    this->conn.open();
    this->query = new QSqlQuery(this->conn);
}

DB* DB::getInstance() {
    if(instance == nullptr) {
        instance = new DB();
    }
    return instance;
}

DB::~DB()
{
    this->conn.close();
}

QSqlQuery* DB::getQuery() {
    return this->query;
}
