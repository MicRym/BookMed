#ifndef APIGETBENEFITS_H
#define APIGETBENEFITS_H

#include "apigetquery.h"

class ApiGetBenefits : public ApiGetQuery
{
public:
    ApiGetBenefits();
    virtual void LaunchGetQuery();
    virtual void InitQuery();
    inline static const QUrl apiUrl{"https://api.nfz.gov.pl/app-itl-api/benefits?"};
private:
    virtual bool ValidateParameterInMap();
    QUrl urlRequest;
};

#endif // APIGETBENEFITS_H
