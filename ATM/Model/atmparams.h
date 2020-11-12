#ifndef ATMPARAMS_H
#define ATMPARAMS_H

#include <QString>
#include <QJsonValue>

class ATMParams
{
public:
    enum Languages {UA = 1, EN = 2};

private:
    size_t atm_id_;
    QString bank_name_;
    bool busy_;
    bool ready_;
    long money_;
    Languages language_;

public:
    ATMParams(const size_t atm_id, const QString& bank_name,
              const bool busy, const bool ready, const long money, const Languages lang);

    size_t& atmId();
    QString& bankName();
    bool& isBusy();
    bool& isReady();
    long& money();
    Languages& language();

    static ATMParams fromJson(const QJsonValue&);

};

#endif // ATMPARAMS_H
