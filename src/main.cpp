// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QDebug>
#include "app_environment.h"
#include "import_qml_components_plugins.h"
#include "import_qml_plugins.h"
#include "src/apigettersfactory.h"
#include <cstdio>
#include <memory>
typedef std::pair<std::string, std::string> ApiGetParameter;
int main(int argc, char *argv[])
{
    set_qt_environment();

    QGuiApplication app(argc, argv);
    /*QNetworkAccessManager manager;
    QUrl urlReq("https://api.nfz.gov.pl/app-itl-api/queues?");
    QUrlQuery query;
    query.addQueryItem("page", "1");
    query.addQueryItem("limit", "10");
    query.addQueryItem("format", "json");
    query.addQueryItem("case", "1");
    query.addQueryItem("province", "15");
    query.addQueryItem("benefit", "PORADNIA AUDIOLOGICZNA");
    urlReq.setQuery(query);
    qDebug() << urlReq;
    QNetworkRequest request(urlReq);
    QNetworkReply *reply = manager.get(request);*/
    ApiGettersFactory factory;
    std::unique_ptr<ApiGetQuery> getQuery;
    getQuery.reset();
    getQuery = factory.CreateApiGetter(EapiGetQuerryType::EApiGetBenefits);
    getQuery->AddParameterToMap(ApiGetParameter{"page","1"});
    getQuery->AddParameterToMap(ApiGetParameter{"limit","10"});
    getQuery->AddParameterToMap(ApiGetParameter{"format","json"});
    getQuery->AddParameterToMap(ApiGetParameter{"name","poradnia"});
    getQuery->AddParameterToMap(ApiGetParameter{"api-version","1.3"});
    getQuery->LaunchGetQuery();
    getQuery.reset();

    getQuery = factory.CreateApiGetter(EapiGetQuerryType::EApiGetQueue);
    getQuery->AddParameterToMap(ApiGetParameter{"page","1"});
    getQuery->AddParameterToMap(ApiGetParameter{"limit","10"});
    getQuery->AddParameterToMap(ApiGetParameter{"foramt","json"});
    getQuery->AddParameterToMap(ApiGetParameter{"case","1"});
    getQuery->AddParameterToMap(ApiGetParameter{"province","15"});
    getQuery->AddParameterToMap(ApiGetParameter{"benefit","PORADANIA AUDIOLOGICZNA"});
    getQuery->AddParameterToMap(ApiGetParameter{"benefitForChildren","false"});
    getQuery->AddParameterToMap(ApiGetParameter{"api-version","1.3"});
    getQuery->LaunchGetQuery();
    getQuery.reset();
    getQuery = factory.CreateApiGetter(EapiGetQuerryType::EApiGetProviders);
    getQuery->AddParameterToMap(ApiGetParameter{"page","1"});
    getQuery->AddParameterToMap(ApiGetParameter{"limit","10"});
    getQuery->AddParameterToMap(ApiGetParameter{"format","json"});
    getQuery->AddParameterToMap(ApiGetParameter{"name","Audiolog"});
    getQuery->AddParameterToMap(ApiGetParameter{"province","15"});
    getQuery->AddParameterToMap(ApiGetParameter{"api-version","1.3"});
    getQuery->LaunchGetQuery();
    getQuery.reset();
    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:Main/main.qml"_qs);
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    engine.addImportPath(QCoreApplication::applicationDirPath() + "/qml");
    engine.addImportPath(":/");

    engine.load(url);

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }
  /*  QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    QByteArray response_data = reply->readAll();
    QString response(response_data);
    qDebug() << response;*/

    return app.exec();
}
