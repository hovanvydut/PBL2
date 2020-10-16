#include "AuthorController.h"

AuthorController::AuthorController()
{
    this->authorRepository = AuthorRepository::getInstance();
}

AuthorController::~AuthorController()
{

}

Author* AuthorController::findFirst() {
    return this->authorRepository->findFirst();
}

QList<Author*> AuthorController::findAll() {
    return this->authorRepository->findAll();
}

Author* AuthorController::findById(int author_id) {
    if (author_id <= 0) {
        throw "AuthorRepository::findById --> author_id is invalid";
    }
    return this->authorRepository->findById(author_id);
}

int AuthorController::count() {
    return this->authorRepository->count();
}

