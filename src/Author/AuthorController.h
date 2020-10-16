#ifndef AUTHORCONTROLLER_H
#define AUTHORCONTROLLER_H

#include "Author.h"
#include "AuthorRepository.h"
#include <QList>

class AuthorController
{
private:
    AuthorRepository* authorRepository;
public:
    AuthorController();
    ~AuthorController();
    Author* findFirst();
    QList<Author*> findAll();
    Author* findById(int author_id);
    int count();
};

#endif // AUTHORCONTROLLER_H
