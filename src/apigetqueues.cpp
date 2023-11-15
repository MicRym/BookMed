#include "apigetqueues.h"
#include "qeventloop.h"

ApiGetQueues::ApiGetQueues()
{
    qDebug() << "Test ApiGetQueues";
}
void ApiGetQueues::LaunchGetQuery()
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
void ApiGetQueues::InitQuery()
{
    urlRequest = ApiGetQueues::apiUrl;
}
