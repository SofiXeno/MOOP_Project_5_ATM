#ifndef ATMSELECTORSOCKET_H
#define ATMSELECTORSOCKET_H

#include "appsocket.h"
#include "ATM/atmparams.h"

class ATMSelectorSocket : public AppSocket
{

    Q_OBJECT

private:

    static QUrl HOST_URL;
    static QString EVENT_NAME;

    void doOnTextMessageReceived(const QJsonObject &) override;

    QList<ATMParams> parseParams(const QJsonValue&);

public:
    explicit ATMSelectorSocket(QObject *parent = Q_NULLPTR);
    ~ATMSelectorSocket();
    static QUrl getHOST_URL();
    static QString getEVENT_NAME();

    void askForATMParams();

signals:
    void receivedATMParams(const QList<ATMParams>&);
};

#endif // ATMSELECTORSOCKET_H
