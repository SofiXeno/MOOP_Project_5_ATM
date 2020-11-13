#ifndef ATM_H
#define ATM_H

#include <QObject>

#include "ATM/Model/atmcard2.h"
#include "ATM/Model/atmparams.h"
#include "ATM/Socket/atmsocket.h"

class ATM : public QObject
{
    Q_OBJECT

protected:
    ATMSocket* socket_;
    ATMParams* par_;
    ATMCard2* card_;

    void backOnStart(const ATMParams&);
    void backInsertCard();
    void backFreeCard();
    void backValidatePin(const size_t);
    void backPinSuccess(const ATMCard2&);
    void backChangePin();
    void backSendToCard(const ATMCard2&);
    void backCheckBal(const ATMCard2&);
    void backTakeCash(const ATMCard2&, const long);

    void backError(const QString&);

public:
    explicit ATM(const size_t);

    virtual ~ATM();

    void insertCard(const QString&);
    void freeCard();
    void validatePin(const size_t);
    void changePin(const size_t);
    void sendToCard(const QString&, const size_t);
    void checkBal();
    void takeCash(const size_t);

    ATMCard2 *card() const;

signals:
    void atmStarted();
    void cardInserted();
    void cardFree();
    void pinValidated(const size_t);
    void pinSuccess();
    void pinChanged();
    void cashSend();
    void balChecked();
    void cashTaken(long money);
    void errorOccured(const QString&);
};

#endif // ATM_H
