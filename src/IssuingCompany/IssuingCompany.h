#ifndef ISSUINGCOMPANY_H
#define ISSUINGCOMPANY_H

#include <string>
#include "utils/Date/Date.h"

class IssuingCompany
{
private:
    int issuing_company_id;
    std::string name;
    Date created_at;
    Date updated_at;
    Date deleted_at;

public:
    IssuingCompany();
    ~IssuingCompany();
};

#endif // ISSUINGCOMPANY_H
