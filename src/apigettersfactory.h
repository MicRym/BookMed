
#ifndef APIGETTERSFACTORY_H

#define APIGETTERSFACTORY_H


#include "src/apigetquery.h"
#include <cstdio>
#include <memory>
class ApiGettersFactory
{
public:
    ApiGettersFactory();    
    std::unique_ptr<ApiGetQuery> CreateApiGetter(EapiGetQuerryType eApiGetQueryType);

};

#endif // APIGETTERSFACTORY_H
