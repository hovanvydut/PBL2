#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "utils/ArrayListt/ArrayListt.h"
#include "utils/LinkedListt/LinkedListt.h"
#include <src/Author/AuthorQueryCondition.h>
#include <QSqlQuery>
#include "src/DB/DB.h"

template<class T>
class Repository {    
protected:
    QSqlQuery* query;
    Repository();
public:
    static T* getInstance();
    virtual ~Repository();
    virtual Listt<T>* findAll() = 0;
    virtual Listt<T>* findAll(AuthorQueryCondition*) = 0;
    virtual T findById(int) = 0;
    virtual int count() = 0;
    virtual T parse(QSqlQuery*) = 0;
};

template<class T>
Repository<T>::Repository() {
    this->query = DB::getInstance()->getQuery();
}

#endif // REPOSITORY_H
