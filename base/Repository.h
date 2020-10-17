#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QList>
#include <src/Author/AuthorQueryCondition.h>

template<typename T>

class Repository {    
public:
    Repository();
//    virtual static T* getInstance() = 0;
    ~Repository();
    virtual QList<T*> findAll() = 0;
    virtual QList<T*> findAll(AuthorQueryCondition*) = 0;
    virtual T* findById(int) = 0;
    virtual int count() = 0;
//    virtual T* parse(QSqlQuery*) = 0;
};

#endif // REPOSITORY_H
