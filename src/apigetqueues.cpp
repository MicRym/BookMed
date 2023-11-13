#include "apigetqueues.h"

ApiGetQueues::ApiGetQueues()
{
    qDebug() << "Test ApiGetQueues";
}
void ApiGetQueues::InitQuery()
{
    urlRequest = ApiGetQueues::apiUrl;
}
