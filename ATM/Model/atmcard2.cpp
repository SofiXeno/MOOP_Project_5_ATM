#include "atmcard2.h"
#include "ATM/clienterror.h"
#include <QJsonDocument>

ATMCard ATMCard::fromJson(const QJsonObject & obj)
{
    try {
        return ATMCard(obj["balance"].toString().toLong(),
                             obj["creditAvaliable"].toString().toLong(),
                              obj["creditLimit"].toString().toLong());
    } catch (...) {
        qFatal(QString(ClientError("ATMCard json error", ClientError::PARSING_ERROR, QJsonDocument(obj).toBinaryData())).toLatin1().constData());
    }
}

ATMCard::ATMCard(const long bal, const long credA, const long credL):
    bal_(bal),
    creditAval_(credA),
    creditLim_(credL)
{}


ATMCard::~ATMCard()
{}

ATMCard::ATMCard(const ATMCard & that)
{
    bal_ = that.bal_;
    creditLim_ = that.creditLim_;
    creditAval_ = that.creditAval_;
}

ATMCard &ATMCard::operator=(const ATMCard & that)
{
    if(this == &that)
        return *this;
    bal_ = that.bal_;
    creditLim_ = that.creditLim_;
    creditAval_ = that.creditAval_;
    return *this;
}
