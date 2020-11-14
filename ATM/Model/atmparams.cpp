#include "atmparams.h"
#include "ATM/clienterror.h"
#include <QJsonObject>
#include <QJsonDocument>

ATMParams ATMParams::fromJson(const QJsonObject & obj)
{
    try {
        return ATMParams(obj["atm_id"].toInt(), obj["bank_name"].toString(),
                 obj["cash"].toInt(), ATMParams::Languages::UA);
    } catch (...) {
        qFatal(QString(ClientError("ATMParams json error", ClientError::PARSING_ERROR, QJsonDocument(obj).toBinaryData())).toLatin1().constData());
     }
}


ATMParams::ATMParams(const size_t atm_id, const QString &bank_name, const long cash, const Languages lang):
    atm_id_(atm_id),
    bank_name_(bank_name),
    cash_(cash),
    language_(lang)
{

}

ATMParams::ATMParams(const ATMParams & p):
    atm_id_(p.atm_id_),
    bank_name_(p.bank_name_),
    cash_(p.cash_),
    language_(p.language_)
{}

ATMParams &ATMParams::operator=(const ATMParams & that)
{
    if(this == &that)
        return *this;
    atm_id_ = that.atm_id_;
    bank_name_ = that.bank_name_;
    cash_ = that.cash_;
    language_ = that.language_;
    return *this;
}

const size_t ATMParams::atmId() const
{
    return atm_id_;
}

const QString &ATMParams::bankName() const
{
    return bank_name_;
}


ATMParams::Languages ATMParams::language() const
{
    return language_;
}

long ATMParams::cash() const
{
    return cash_;
}

void ATMParams::updateCash(const long cash)
{
    cash_ = cash;
}

