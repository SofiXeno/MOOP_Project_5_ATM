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
    long cash_;
    Languages language_;

public:
    static ATMParams fromJson(const QJsonObject&);

    ATMParams(const size_t atm_id, const QString& bank_name,const long money, const Languages lang = UA);

    ATMParams(const ATMParams&);
    ATMParams& operator=(const ATMParams&);

    size_t atmId() const;
    const QString& bankName() const;
    Languages language() const;
    long cash() const;

    void updateCash(const long);
};

#endif // ATMPARAMS_H
