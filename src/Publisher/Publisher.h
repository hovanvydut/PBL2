#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <QString>
#include <QDate>
#include "base/Entity.h"

class Publisher : public Entity
{
private:
    const int publisher_id;
    QString name;
    QDate created_at;
    QDate updated_at;
    QDate deleted_at;
public:
    Publisher(int=0, QString name = "No Name");
    Publisher(int, QString name, QDate, QDate, QDate);
    ~Publisher();
    int getPublisherId();
    QString getName();
    QDate getCreatedAt();
    QDate getUpdatedAt();
    QDate getDeletedAt();
    virtual void save();
};

#endif // PUBLISHER_H
