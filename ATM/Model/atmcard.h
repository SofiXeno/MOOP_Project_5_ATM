#ifndef ATMCARD_H
#define ATMCARD_H

#include <QString>
#include <QJsonObject>

class ATMCard
{
private:
    QString number_;
    long bal_;
    long creditAval_;
    long creditLim_;

public:
    static ATMCard fromJson(const QJsonObject&);

    ATMCard(const QString&, const long, const long, const long);
    ATMCard(const QString&);

    ~ATMCard();
};

#endif // ATMCARD_H
