#include "atmcard2.h"

ATMCard2 ATMCard2::fromJson(const QJsonObject & obj)
{
    // check
    return ATMCard2(obj["number"].toString(),
                    obj["balance"].toString().toLong(),
                     obj["creditAvaliable"].toString().toLong(),
            obj["creditLimit"].toString().toLong());
}

ATMCard2::ATMCard2(const QString & number, const long bal, const long credA, const long credL):
    number_(number),
    bal_(bal),
    creditAval_(credA),
    creditLim_(credL)
{}

ATMCard2::ATMCard2(const QString & number):
    number_(number),
    bal_(0),
    creditAval_(0),
    creditLim_(0)
{}

ATMCard2::~ATMCard2()
{}
