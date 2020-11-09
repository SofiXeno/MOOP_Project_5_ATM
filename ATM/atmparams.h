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
    size_t bank_id_;
    QString bank_name_;
    bool busy_;
    bool ready_;
    long money_;
    Languages language_;


public:

    ATMParams(const size_t atm_id, const size_t bank_id, const QString& bank_name,
              const bool busy, const bool ready, const long money, const Languages lang);

    size_t atmId() const;
    size_t bankId() const;
    const QString& bankName() const;
    bool isBusy() const;
    bool isReady() const;
    long money() const;
    Languages language() const;

    void setLanguage(const Languages);

    static ATMParams jsonToObject(const QJsonValue&);

};

#endif // ATMPARAMS_H
