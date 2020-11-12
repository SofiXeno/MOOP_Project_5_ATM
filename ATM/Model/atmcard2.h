#ifndef ATMCARD2_H
#define ATMCARD2_H

#include <QJsonObject>

class ATMCard2
{
private:
    long bal_;
    long creditAval_;
    long creditLim_;

    ATMCard2(const long, const long, const long);

public:
    static ATMCard2 fromJson(const QJsonObject&);

    ~ATMCard2();

};

#endif // ATMCARD2_H
