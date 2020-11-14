#ifndef ATMSOCKET_H
#define ATMSOCKET_H

#include <QObject>
#include "appsocket.h"

class ATMCard;
class ATMParams;

class ATMSocket: public AppSocket
{
    Q_OBJECT

private:

    static QList<QString> EVENT_STRINGS;
    enum EVENTS { START_ATM, INSERT_CARD, CHECK_PIN, SUCCESS_PIN, FREE_CARD, SEND_TO_CARD, TAKE_FROM_CARD, CHECK_BAL, CHANGE_PIN };

    void doOnTextMessageReceived(const QJsonObject &) override;
    QJsonObject formJson(const size_t);


    ATMSocket(const ATMSocket&) = delete;
    ATMSocket(ATMSocket&&) = delete;
    ATMSocket& operator=(const ATMSocket&) = delete;
    ATMSocket& operator=(ATMSocket&&) = delete;

public:
    explicit ATMSocket(QObject *parent = Q_NULLPTR);
    virtual ~ATMSocket();

public slots:
    void askStart(const size_t);
    void askInsertCard(const QString&);
    void askFreeCard();
    void askValidatePin(const size_t);
    void askChangePin(const size_t);
    void askSendToCard(const QString&, const size_t);
    void askCheckBal();
    void askTakeCash(const size_t);

signals:
    void replyOnStart(const ATMParams&);
    void replyOnError(const QString&);
    void replyOnInsertedCard();
    void replyOnFreeCard();
    void replyOnValidatePin(const size_t);
    void replyOnSuccessPin(const ATMCard&);
    void replyOnChangePin();
    void replyOnSendToCard(const ATMCard&);
    void replyOnCheckBal(const ATMCard&);
    void replyOnTakeCash(const ATMCard&, const long);
};

#endif // ATMSOCKET_H
