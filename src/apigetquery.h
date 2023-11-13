#ifndef APIGETQUERY_H
#define APIGETQUERY_H
#include <QDebug>
#include <QUrl>
#include <QUrlQuery>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QQmlApplicationEngine>
enum class EapiGetQuerryType{ EApiGetProviders, EApiGetBenefits, EApiGetQueue };

class ApiGetQuery
{
public:
    ApiGetQuery();

    virtual void LaunchGetQuery()=0;
    QString GetResponse() { return response.c_str(); };
    void AddParameterToMap(std::pair<std::string, std::string> parameter);
    void AddParameterToMap(std::map<std::string, std::string> map);
    void RemoveParameterFromMap(std::pair<std::string, std::string> parameter);
    virtual void InitQuery()=0;

protected:
    std::map<std::string, std::string>  parameterMap;
    std::string response;
    QUrlQuery query;
    virtual bool ValidateParameterInMap()=0;
    void FillQueryFromMap();
};

#endif // APIGETQUERY_H
