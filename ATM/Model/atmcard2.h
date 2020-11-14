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

    static ATMCard2 fromJson(const QJsonObject&);
    const long& bal() const;
    const long& creditAval() const;
    const long& creditLim() const;


    static ATMCard fromJson(const QJsonObject&);


    ~ATMCard();
    ATMCard(const ATMCard&);
    ATMCard& operator=(const ATMCard&);

};

#endif // ATMCARD_H
