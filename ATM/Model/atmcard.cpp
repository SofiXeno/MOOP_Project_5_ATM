#include "atmcard.h"

ATMCard ATMCard::fromJson(const QJsonObject & obj)
{
    // check
    return ATMCard(obj["number"].toString(),
                    obj["balance"].toString().toLong(),
                     obj["creditAvaliable"].toString().toLong(),
            obj["creditLimit"].toString().toLong());
}

ATMCard::ATMCard(const QString & number, const long bal, const long credA, const long credL):
    number_(number),
    bal_(bal),
    creditAval_(credA),
    creditLim_(credL)
{}

ATMCard::ATMCard(const QString & number):
    ATMCard(number, 0, 0, 0)
{}

ATMCard::~ATMCard()
{}
