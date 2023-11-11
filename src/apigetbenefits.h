#ifndef APIGETBENEFITS_H
#define APIGETBENEFITS_H

#include "apigetquery.h"

class ApiGetBenefits : public ApiGetQuery
{
public:
    ApiGetBenefits();
    virtual void LaunchGetQuery();
private:
    virtual bool ValidateParameterInMap();
};

#endif // APIGETBENEFITS_H
