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
    QList<ATMParams> parseParams(const QJsonArray&);

    ATMSelectorSocket(const ATMSelectorSocket&) = delete;
    ATMSelectorSocket(ATMSelectorSocket&&) = delete;
    ATMSelectorSocket& operator=(const ATMSelectorSocket&) = delete;
    ATMSelectorSocket& operator=(ATMSelectorSocket&&) = delete;

public:
    explicit ATMSelectorSocket(QObject *parent = Q_NULLPTR);
    virtual ~ATMSelectorSocket();

public slots:
    void askForATMParams();

signals:
    void errorOccured(const QString&);
    void receivedATMParams(const QList<ATMParams>&);
};

#endif // ATMSELECTORSOCKET_H
