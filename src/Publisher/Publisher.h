#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <string>
#include "utils/Date/Date.h"

class Publisher
{
private:
    int publisher_id;
    std::string name;
    Date created_at;
    Date updated_at;
    Date deleted_at;
public:
    Publisher();
    ~Publisher();
};

#endif // PUBLISHER_H
