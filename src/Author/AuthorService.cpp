#include "AuthorService.h"

AuthorService::AuthorService()
{
    this->authorRepository = AuthorRepository::getInstance();
}

AuthorService::~AuthorService()
{

}

Author* AuthorService::findFirst() {
    return this->authorRepository->findFirst();
}

QList<Author*> AuthorService::findAll(AuthorQueryCondition* conditions) {
    return this->authorRepository->findAll(conditions);
}

QList<Author*> AuthorService::findAll() {
    return this->authorRepository->findAll();
}

Author* AuthorService::findById(int author_id) {
    if (author_id <= 0) {
        throw "AuthorRepository::findById --> author_id is invalid";
    }
    return this->authorRepository->findById(author_id);
}

int AuthorService::count() {
    return this->authorRepository->count();
}

