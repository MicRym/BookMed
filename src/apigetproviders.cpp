#include "apigetproviders.h"
#include "qeventloop.h"

ApiGetProviders::ApiGetProviders()
{
    qDebug() << "Test ApiGetProviders";
}
void ApiGetProviders::LaunchGetQuery()
{
    QNetworkAccessManager manager;
    InitQuery();
    FillQueryFromMap();

    urlRequest.setQuery(query);
    qDebug()<<urlRequest;
    QNetworkRequest request(urlRequest);
    QNetworkReply *reply = manager.get(request);
    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    QByteArray response_data = reply->readAll();
    response = response_data;
    qDebug()<<response;
}
bool ApiGetProviders::ValidateParameterInMap()
{
    return true;
}
void ApiGetProviders::InitQuery()
{
    urlRequest = ApiGetProviders::apiUrl;
}
