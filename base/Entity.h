#ifndef ENTITY_H
#define ENTITY_H

#include <QString>

class Entity
{
protected:
    QString tableName;
    QString primaryColumnName;
public:
    Entity();
    virtual void save() = 0;
    ~Entity();
};

#endif // ENTITY_H
