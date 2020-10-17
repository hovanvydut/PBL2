#ifndef AUTHORREPOSITORY_H
#define AUTHORREPOSITORY_H

#include "src/DB/DB.h"
#include "Author.h"
#include <QStandardItemModel>
#include <QList>
#include <QSqlQuery>
#include <QDebug>
#include "AuthorQueryCondition.h"
#include "base/Repository.h"

class AuthorRepository : Repository<Author> {
private:
    static AuthorRepository* _authorRepository;
    QSqlQuery* query;
    AuthorRepository();

public:
    static AuthorRepository* getInstance();
    ~AuthorRepository();
    Author* findFirst();
    QList<Author*> findAll();
    QList<Author*> findAll(AuthorQueryCondition* conditions);
    Author* findById(int author_id);
    int count();
    static Author* parse(QSqlQuery* query);
};

#endif // AUTHORREPOSITORY_H
