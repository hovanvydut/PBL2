#ifndef AUTHORCONTROLLER_H
#define AUTHORCONTROLLER_H

#include "Author.h"
#include "AuthorRepository.h"
#include "AuthorQueryCondition.h"
#include <QDebug>
#include "utils/ArrayListt/ArrayListt.h"
#include "utils/LinkedListt/LinkedListt.h"

class AuthorService
{
private:
    AuthorRepository* authorRepository;
public:
    AuthorService();
    ~AuthorService();
    Author findFirst();
    Listt<Author>* findAll();
    Listt<Author>* findAll(AuthorQueryCondition* conditions);
    Author findById(int author_id);
    int count();
};

#endif // AUTHORCONTROLLER_H
