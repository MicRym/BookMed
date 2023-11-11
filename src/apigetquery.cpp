#include "apigetquery.h"

ApiGetQuery::ApiGetQuery()
{

}
void ApiGetQuery::FillQueryFromMap()
{
    if(ValidateParameterInMap())
    {
        for (const auto& [key, value] : parameterMap)
        {
            query.addQueryItem(key.c_str(), value.c_str());
        }
    }
    else
    {
        qDebug()<<"There is a problem Sir";
    }
}
