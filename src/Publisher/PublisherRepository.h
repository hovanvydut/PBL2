#ifndef PUBLISHERREPOSITORY_H
#define PUBLISHERREPOSITORY_H

#include "src/Publisher/Publisher.h"
#include "base/Repository.h"
#include "utils/ArrayListt/ArrayListt.h"
#include "utils/LinkedListt/LinkedListt.h"
#include "src/Author/AuthorQueryCondition.h"
#include <QSqlQuery>

class PublisherRepository
{
private:
    QSqlQuery* query;
public:
    PublisherRepository();
    ~PublisherRepository();
    Listt<Publisher>* findAll();
    Listt<Publisher>* findAll(AuthorQueryCondition* conditions);
    Publisher findById(int publisher_id);
    int count();
};

#endif // PUBLISHERREPOSITORY_H
