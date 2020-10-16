#include "Author.h"

Author::Author()
{

}

Author::Author(int author_id, QString name, QDate created_at,
               QDate updated_at, QDate deleted_at) {
    if (author_id <= 0) {
        throw "Author::Author --> author_id is invalid";
    }
    this->author_id = author_id;
    this->name = name;
    this->created_at = created_at;
    this->updated_at = updated_at;
    this->deleted_at = deleted_at;
}

Author::~Author()
{

}

int Author::getId() {
    return this->author_id;
}

QString Author::getName() {
    return this->name;
}

QDate Author::getCreatedAt() {
    return this->created_at;
}

QDate Author::getUpdatedAt() {
    return this->updated_at;
}

QDate Author::getDeletedAt() {
    return this->deleted_at;
}

