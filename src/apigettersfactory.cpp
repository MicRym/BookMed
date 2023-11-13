#include "apigettersfactory.h"
#include "src/apigetbenefits.h"
#include "src/apigetproviders.h"
#include "src/apigetqueues.h"

ApiGettersFactory::ApiGettersFactory()
{

}
std::unique_ptr<ApiGetQuery> ApiGettersFactory::CreateApiGetter(EapiGetQuerryType eApiGetQueryType)
{
    switch (eApiGetQueryType) {
    case EapiGetQuerryType::EApiGetBenefits:
         return std::make_unique<ApiGetBenefits>();
        break;
    case EapiGetQuerryType::EApiGetQueue:
         return std::make_unique<ApiGetQueues>();
          break;
    case EapiGetQuerryType::EApiGetProviders:
        return std::make_unique<ApiGetProviders>();
          break;

    default:
        return nullptr;
    }
}
