#include "Publisher.h"
#include "src/DB/DB.h"

Publisher::Publisher(int publisher_id, QString name): publisher_id(publisher_id) {
    this->name = name;
}

Publisher::Publisher(int publisher_id, QString name, QDate created_at,
                     QDate updated_at, QDate deleted_at): publisher_id(publisher_id) {
    this->name = name;
    this->created_at = created_at;
    this->updated_at = updated_at;
    this->deleted_at = deleted_at;
}

Publisher::~Publisher() {

}

int Publisher::getPublisherId() {
    return this->publisher_id;
}

QString Publisher::getName() {
    return this->name;
}

QDate Publisher::getCreatedAt() {
    return this->created_at;
}

QDate Publisher::getUpdatedAt() {
    return this->getUpdatedAt();
}

QDate Publisher::getDeletedAt() {
    return this->getDeletedAt();
}

void Publisher::save() {

}
