#ifndef ATM_H
#define ATM_H

#include "atmparams.h"

class ATM
{
protected:
    ATMParams _par;

private:

    virtual bool doExecute() = 0;
    virtual bool doReadCard() = 0;
    virtual bool doSendToCard() = 0;
    virtual bool doPinChange() = 0;
    virtual bool doTakeCash() = 0;

public:
    explicit ATM(const ATMParams& par);

    ~ATM();

    bool readCard(const QString&);
    bool sendToCard(const QString&, const size_t sum);
    bool pinChange(const QString&);
    bool takeCash(const size_t);

    bool execute();
};

#endif // ATM_H
