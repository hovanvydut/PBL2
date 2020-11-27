#ifndef AUTHORREPOSITORY_H
#define AUTHORREPOSITORY_H

#include "src/DB/DB.h"
#include "Author.h"
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QDebug>
#include "AuthorQueryCondition.h"
#include "utils/ArrayListt/ArrayListt.h"
#include "utils/LinkedListt/LinkedListt.h"
#include "base/Repository.h"

class AuthorRepository {
private:
    static AuthorRepository* _authorRepository;
    QSqlQuery* query;
    AuthorRepository();

public:
    static AuthorRepository* getInstance();
    ~AuthorRepository();
    Author findFirst();
    Listt<Author>* findAll();
    Listt<Author>* findAll(AuthorQueryCondition* conditions);
    Author findById(int author_id);
    int count();
    Author parse(QSqlQuery* query);
};

#endif // AUTHORREPOSITORY_H
