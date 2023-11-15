#ifndef APIGETQUEUES_H
#define APIGETQUEUES_H

#include "apigetquery.h"

class ApiGetQueues : public ApiGetQuery
{
public:
    ApiGetQueues();
    virtual void LaunchGetQuery();
    virtual void InitQuery();
    inline static const  QUrl apiUrl{"https://api.nfz.gov.pl/app-itl-api/queues?"};
private:
    virtual bool ValidateParameterInMap() {return true;};

    QUrl urlRequest;
};

#endif // APIGETQUEUES_H
