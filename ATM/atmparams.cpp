#include "atmparams.h"
#include <QJsonObject>

ATMParams::ATMParams(const size_t atm_id, const size_t bank_id, const QString &bank_name,
                     const bool busy, const bool ready, const long money, const Languages lang):
    atm_id_(atm_id),
    bank_id_(bank_id),
    bank_name_(bank_name),
    busy_(busy),
    ready_(ready),
    money_(money),
    language_(lang)
{

}

void ATMParams::setLanguage(const ATMParams::Languages lang)
{
    language_ = lang;
}

ATMParams ATMParams::jsonToObject(const QJsonValue & val)
{
    // CATCH ERRORS
    // CAST INT TO SIZE_T AND LONG!
    QJsonObject obj = val.toObject();
    return ATMParams(obj["id"].toInt(), obj["bank"].toInt(), obj["bank_name"].toString(),
             obj["busy"].toBool(),  obj["ready"].toBool(),  obj["cash"].toInt(), ATMParams::Languages::UA);
}
