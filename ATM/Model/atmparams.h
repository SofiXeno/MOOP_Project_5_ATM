#ifndef ATMPARAMS_H
#define ATMPARAMS_H

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
    static ATMParams fromJson(const QJsonObject&);

    ATMParams(const size_t atm_id, const QString& bank_name,
              const bool busy, const bool ready, const long money, const Languages lang = UA);


    ATMParams(const ATMParams&);
    ATMParams& operator=(const ATMParams&);

    size_t& atmId();
    QString& bankName();
    bool& isBusy();
    bool& isReady();
    long& money();
    Languages& language();


};

#endif // ATMPARAMS_H
