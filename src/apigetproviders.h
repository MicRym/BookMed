#ifndef APIGETPROVIDERS_H
#define APIGETPROVIDERS_H

#include "apigetquery.h"

class ApiGetProviders : public ApiGetQuery
{
public:
    ApiGetProviders();
    virtual void LaunchGetQuery() {};
private:
    virtual bool ValidateParameterInMap() {return true;};
};

#endif // APIGETPROVIDERS_H
