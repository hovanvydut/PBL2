#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include "utils/Date/Date.h"

class Category
{
private:
    int categories_id;
    std::string name;
    Date created_at;
    Date updated_at;
    Date deleted_at;

public:
    Category();
    ~Category();
};

#endif // CATEGORY_H
