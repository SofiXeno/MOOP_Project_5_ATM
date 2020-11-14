#include "atmparams.h"
#include "ATM/clienterror.h"
#include <QJsonObject>
#include <QJsonDocument>

ATMParams ATMParams::fromJson(const QJsonObject & obj)
{
    try {
        return ATMParams(obj["atm_id"].toInt(), obj["bank_name"].toString(),
                 obj["busy"].toBool(),  obj["ready"].toBool(),  obj["cash"].toInt(), ATMParams::Languages::UA);
    } catch (...) {
            throw ClientError("ATMParams json error", ClientError::PARSING_ERROR, QJsonDocument(obj).toBinaryData());
     }
}


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

ATMParams::ATMParams(const ATMParams & p):
    atm_id_(p.atm_id_),
    bank_name_(p.bank_name_),
    busy_(p.busy_),
    ready_(p.ready_),
    money_(p.money_),
    language_(p.language_)
{}

ATMParams &ATMParams::operator=(const ATMParams & that)
{
    if(this == &that)
        return *this;
    atm_id_ = that.atm_id_;
    bank_name_ = that.bank_name_;
    busy_ = that.busy_;
    ready_ = that.ready_;
    money_ = that.money_;
    language_ = that.language_;
    return *this;
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
