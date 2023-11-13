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
void ApiGetQuery::AddParameterToMap(std::pair<std::string, std::string> parameter)
{
    parameterMap.insert(parameter);
}
void ApiGetQuery::AddParameterToMap(std::map<std::string, std::string> map)
{
    for(const auto& [key,value]:map)
    {
        parameterMap.insert({key, value});
    }
}
void ApiGetQuery::RemoveParameterFromMap(std::pair<std::string, std::string> parameter)
{
    parameterMap.erase(parameter.first);
}
