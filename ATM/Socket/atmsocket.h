#ifndef ATMSOCKET_H
#define ATMSOCKET_H

#include <QObject>
#include "appsocket.h"
#include "ATM/Model/atmcard.h"

class ATMParams;

class ATMSocket: public AppSocket
{
    Q_OBJECT

private:

    static QList<QString> EVENT_STRINGS;
    enum EVENTS { START_ATM, INSERT_CARD, CHECK_PIN, FREE_CARD, SEND_TO_CARD, TAKE_FROM_CARD, CHECK_BAL, CHANGE_PIN };

    void doOnTextMessageReceived(const QJsonObject &) override;

    QJsonObject formJson(const size_t);

public:
    ATMSocket(QObject *parent = Q_NULLPTR);
    ~ATMSocket();

    void askStart(const size_t);
    void askInsertCard(const size_t, const QString&);
    void askFreeCard(const size_t);
    void askValidatePin(const size_t, const size_t);
    void askChangePin(const size_t, const size_t);
    void askSendToCard(const size_t, const QString&, const size_t);
    void askCheckBal(const size_t);
    void askTakeCash(const size_t, const size_t);

signals:
    void replyOnStart(const ATMParams&);
    void replyOnError(const QString&);
    void replyOnInsertedCard(const ATMCard&, const bool);
    void replyOnFreeCard();
    void replyOnValidatePin(const size_t);
    void replyOnChangePin();
    void replyOnSendToCard(const ATMCard&);
    void replyOnCheckBal(const ATMCard&);
    void replyOnTakeCash(const ATMCard&, const long);
};

#endif // ATMSOCKET_H
