#include "apigetbenefits.h"
#include "qeventloop.h"

ApiGetBenefits::ApiGetBenefits()
{
    qDebug() << "Test ApiGetBenefits";
    SetApiUrl("https://api.nfz.gov.pl/app-itl-api/benefits?");
    parameterMap.insert({"page","1"});
    parameterMap.insert({"limit","10"});
    parameterMap.insert({"format","json"});
    parameterMap.insert({"name","poradnia"});
    parameterMap.insert({"api-version","1.3"});
    urlRequest = apiUrl;
}
void ApiGetBenefits::LaunchGetQuery()
{
    QNetworkAccessManager manager;
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
