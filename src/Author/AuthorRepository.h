#ifndef AUTHORREPOSITORY_H
#define AUTHORREPOSITORY_H

#include "src/DB/DB.h"
#include "Author.h"
#include <QStandardItemModel>
#include <QList>
#include <QSqlQuery>
#include <QDebug>

class AuthorRepository
{
private:
    static AuthorRepository* _authorRepository;
    QSqlQuery* query;
    AuthorRepository();
public:
    static AuthorRepository* getInstance();
    ~AuthorRepository();
    Author* findFirst();
    QList<Author*> findAll();
    Author* findById(int author_id);
    int count();
    static Author* parse(QSqlQuery* query);
};

#endif // AUTHORREPOSITORY_H
