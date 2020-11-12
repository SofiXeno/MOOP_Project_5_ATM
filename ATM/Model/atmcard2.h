#ifndef ATMCARD2_H
#define ATMCARD2_H

#include <QJsonObject>

class ATMCard2
{
private:
    QString number_;
    long bal_;
    long creditAval_;
    long creditLim_;

public:
    static ATMCard2 fromJson(const QJsonObject&);

    ATMCard2(const QString&, const long, const long, const long);
    ATMCard2(const QString&);

    ~ATMCard2();

};

#endif // ATMCARD2_H
