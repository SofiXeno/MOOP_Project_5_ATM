#ifndef ATMSELECTORSOCKET_H
#define ATMSELECTORSOCKET_H

#include "ATM/Socket/appsocket.h"
class ATMParams;

class ATMSelectorSocket : public AppSocket
{

    Q_OBJECT

private:
    static QString EVENT_NAME;

    void doOnTextMessageReceived(const QJsonObject &) override;
    QList<ATMParams> parseParams(const QJsonValue&);

public:
    explicit ATMSelectorSocket(QObject *parent = Q_NULLPTR);
    ~ATMSelectorSocket();

    void askForATMParams();

signals:
    void errorOccured(const QString&);
    void receivedATMParams(const QList<ATMParams>&);
};

#endif // ATMSELECTORSOCKET_H
