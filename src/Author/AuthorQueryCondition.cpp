#include "AuthorQueryCondition.h"

AuthorQueryCondition::AuthorQueryCondition(int limit, int offsetId) {
    this->setLimit(limit);
    this->setOffsetId(offsetId);
}

AuthorQueryCondition::~AuthorQueryCondition() {

}

int AuthorQueryCondition::getLimit() {
    return this->limit;
}

void AuthorQueryCondition::setLimit(int limit) {
    if (limit <= 0) {
        throw "AuthorQueryCondition --> limit is invalid";
    }
    this->limit = limit;
}

int AuthorQueryCondition::getOffsetId() {
    return this->offsetId;
}

void AuthorQueryCondition::setOffsetId(int offsetId) {
    if (offsetId < 0) {
        throw "AuthorQueryCondition --> offsetId is invalid";
    }
    this->offsetId = offsetId;
}


