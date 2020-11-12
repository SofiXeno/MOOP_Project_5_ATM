#include "atmcard2.h"

ATMCard2 ATMCard2::fromJson(const QJsonObject & obj)
{
    // check
    return ATMCard2(obj["balance"].toString().toLong(),
                     obj["creditAvaliable"].toString().toLong(),
                      obj["creditLimit"].toString().toLong());
}

ATMCard2::ATMCard2(const long bal, const long credA, const long credL):
    bal_(bal),
    creditAval_(credA),
    creditLim_(credL)
{}


ATMCard2::~ATMCard2()
{}
