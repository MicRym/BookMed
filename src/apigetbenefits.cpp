#include "apigetbenefits.h"
#include "qeventloop.h"

ApiGetBenefits::ApiGetBenefits()
{
    qDebug() << "Test ApiGetBenefits";
}
void ApiGetBenefits::LaunchGetQuery()
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
bool ApiGetBenefits::ValidateParameterInMap()
{
    return true;
}
void ApiGetBenefits::InitQuery()
{
    urlRequest = ApiGetBenefits::apiUrl;
}
