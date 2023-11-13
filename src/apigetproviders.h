#ifndef APIGETPROVIDERS_H
#define APIGETPROVIDERS_H

#include "apigetquery.h"

class ApiGetProviders : public ApiGetQuery
{
public:
    ApiGetProviders();
    virtual void LaunchGetQuery();
    virtual void InitQuery();
    inline static const QUrl apiUrl{"https://api.nfz.gov.pl/app-itl-api/providers?"};
private:
    virtual bool ValidateParameterInMap();

    QUrl urlRequest;
};

#endif // APIGETPROVIDERS_H
