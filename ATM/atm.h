#ifndef ATM_H
#define ATM_H

#include <QObject>
#include "ATM/Model/atmparams.h"

class ATMSocket;
class ATMCard;

class ATM : public QObject
{
    Q_OBJECT

protected:
    ATMSocket* socket_;
    ATMParams* par_;
    ATMCard* card_;

    void backOnStart(const ATMParams&);
    void backInsertCard(const ATMCard&, const bool);
    void backFreeCard();
    void backValidatePin(const size_t);
    void backChangePin();
    void backSendToCard(const ATMCard&);
    void backCheckBal(const ATMCard&);
    void backTakeCash(const ATMCard&, const long);

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

<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
signals:
    void atmStarted();
    void cardInserted();
    void cardFree();
    void pinValidated(const size_t);
    void pinChanged();
    void cashSend();
    void balChecked();
    void cashTaken();
    void errorOccured(const QString&);
};

#endif // ATM_H
