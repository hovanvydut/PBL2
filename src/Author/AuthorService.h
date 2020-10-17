#ifndef AUTHORCONTROLLER_H
#define AUTHORCONTROLLER_H

#include "Author.h"
#include "AuthorRepository.h"
#include <QList>
#include "AuthorQueryCondition.h"
#include <QDebug>

class AuthorService
{
private:
    AuthorRepository* authorRepository;
public:
    AuthorService();
    ~AuthorService();
    Author* findFirst();
    QList<Author*> findAll();
    QList<Author*> findAll(AuthorQueryCondition* conditions);
    Author* findById(int author_id);
    int count();
};

#endif // AUTHORCONTROLLER_H
