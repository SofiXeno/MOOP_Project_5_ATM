#include "atmcard2.h"

ATMCard2 ATMCard2::fromJson(const QJsonObject & obj)
{
    // check
    return ATMCard2(obj["balance"].toString().toLong(),
                     obj["creditAvaliable"].toString().toLong(),
            obj["creditLimit"].toString().toLong());
}

const long &ATMCard2::bal() const
{
    return bal_;
}

const long &ATMCard2::creditAval() const
{
    return creditAval_;
}

const long &ATMCard2::creditLim() const
{
    return creditLim_;
}

ATMCard2::ATMCard2(const long bal, const long credA, const long credL):
    bal_(bal),
    creditAval_(credA),
    creditLim_(credL)
{}


ATMCard2::~ATMCard2()
{}
