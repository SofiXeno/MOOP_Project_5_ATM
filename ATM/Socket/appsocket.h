#ifndef APPSOCKET_H
#define APPSOCKET_H

#include <QObject>
#include <QtWebSockets/QWebSocket>
#include <QJsonDocument>
#include <QJsonObject>

class AppSocket : public QObject
{
    Q_OBJECT
private:
    virtual void doOnConnected();
    virtual void doOnDisconnected();
    virtual void doOnTextMessageReceived(const QJsonObject&) = 0;
    virtual void doOnSslErrors(const QList<QSslError> &errors);

    QJsonObject toJson(const QString&);

public:
    explicit AppSocket(const QUrl &url, QObject *parent = Q_NULLPTR);

    // TODO COPY AND ETC

    virtual ~AppSocket();

    void sendMessage(const QString&, const QString&);

    //void open();
    //void close();

public slots:

    void onConnected() { doOnConnected(); };
    void onDisconnected() { doOnDisconnected(); };
    void onTextMessageReceived(QString message) { doOnTextMessageReceived(toJson(message)); };
    void onSslErrors(const QList<QSslError> &errors) { doOnSslErrors(errors); };

protected:
    QWebSocket* socket_;
};

#endif // APPSOCKET_H
