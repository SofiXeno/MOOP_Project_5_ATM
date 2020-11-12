#include "atmparams.h"
#include <QJsonObject>

ATMParams::ATMParams(const size_t atm_id, const QString &bank_name,
                     const bool busy, const bool ready, const long money, const Languages lang):
    atm_id_(atm_id),
    bank_name_(bank_name),
    busy_(busy),
    ready_(ready),
    money_(money),
    language_(lang)
{

}

size_t& ATMParams::atmId()
{
    return atm_id_;
}

QString &ATMParams::bankName()
{
    return bank_name_;
}

bool &ATMParams::isBusy()
{
    return busy_;
}

bool &ATMParams::isReady()
{
    return ready_;
}

long &ATMParams::money()
{
    return money_;
}

ATMParams::Languages &ATMParams::language()
{
    return language_;
}

ATMParams ATMParams::fromJson(const QJsonValue & val)
{
    // CATCH ERRORS
    // CAST INT TO SIZE_T AND LONG!
    QJsonObject obj = val.toObject();
    return ATMParams(obj["atm_id"].toInt(), obj["bank_name"].toString(),
             obj["busy"].toBool(),  obj["ready"].toBool(),  obj["cash"].toInt(), ATMParams::Languages::UA);
}
