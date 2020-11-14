#ifndef ATMCARD_H
#define ATMCARD_H

#include <QJsonObject>

class ATMCard
{
private:
    long bal_;
    long creditAval_;
    long creditLim_;

    ATMCard(const long, const long, const long);

public:
    static ATMCard fromJson(const QJsonObject&);

    ~ATMCard();
    ATMCard(const ATMCard&);
    ATMCard& operator=(const ATMCard&);

};

#endif // ATMCARD_H
