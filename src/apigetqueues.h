#ifndef APIGETQUEUES_H
#define APIGETQUEUES_H

#include "apigetquery.h"

class ApiGetQueues : public ApiGetQuery
{
public:
    ApiGetQueues();
    virtual void LaunchGetQuery() {};
private:
    virtual bool ValidateParameterInMap() {return true;};
};

#endif // APIGETQUEUES_H
