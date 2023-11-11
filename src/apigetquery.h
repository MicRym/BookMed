#ifndef APIGETQUERY_H
#define APIGETQUERY_H
#include "qnetworkreply.h"
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

protected:
    std::map<std::string, std::string>  parameterMap;
    std::string response;
    QUrl apiUrl;
    QUrl urlRequest;
    QUrlQuery query;
    void SetApiUrl(std::string url) { apiUrl =QUrl(QString(url.c_str())); };
    virtual bool ValidateParameterInMap()=0;
    void FillQueryFromMap();

};

#endif // APIGETQUERY_H
