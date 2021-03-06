#ifndef AUTHOR_H
#define AUTHOR_H

#include "utils/Date/Date.h"
#include <QDate>

class Author
{
private:
    int author_id;
    QString name;
    QDate created_at;
    QDate updated_at;
    QDate deleted_at;

public:
    Author();
    Author(int author_id, QString name, QDate created_at,
           QDate updated_at, QDate deleted_at);
    ~Author();
    int getId();
    QString getName() const;
    QDate getCreatedAt();
    QDate getUpdatedAt();
    QDate getDeletedAt();
    friend bool operator == (Author, Author);
    friend bool operator == (Author&, Author&);
//    friend bool operator == (Author*, Author*);
};

#endif // AUTHOR_H
