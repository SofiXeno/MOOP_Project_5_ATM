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

<<<<<<< Updated upstream
size_t ATMParams::atmId() const
=======
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

const size_t& ATMParams::atmId() const
>>>>>>> Stashed changes
{
    return atm_id_;
}

void ATMParams::setLanguage(const ATMParams::Languages lang)
{
    language_ = lang;
}

ATMParams ATMParams::fromJson(const QJsonValue & val)
{
    // CATCH ERRORS
    // CAST INT TO SIZE_T AND LONG!
    QJsonObject obj = val.toObject();
    return ATMParams(obj["atm_id"].toInt(), obj["bank_name"].toString(),
             obj["busy"].toBool(),  obj["ready"].toBool(),  obj["cash"].toInt(), ATMParams::Languages::UA);
}
