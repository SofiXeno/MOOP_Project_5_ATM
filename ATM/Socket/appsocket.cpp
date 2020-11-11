#include "appsocket.h"
#include "Utility/utilities.h"

QUrl AppSocket::HOST_URL = Utilities::getInstance().getString("ATMSelectorSocket_host_url");



void AppSocket::doOnConnected()
{
    qDebug() << "connected";
    connect(socket_, &QWebSocket::textMessageReceived,
            this, &AppSocket::onTextMessageReceived);
}

void AppSocket::doOnDisconnected()
{

}

void AppSocket::doOnSslErrors(const QList<QSslError> &errors)
{
    Q_UNUSED(errors);

    // TODO Deal with errors

    // WARNING: Never ignore SSL errors in production code.
    // The proper way to handle self-signed certificates is to add a custom root
    // to the CA store.

    socket_->ignoreSslErrors();
}

QJsonObject AppSocket::toJson(const QString & str)
{
    QJsonObject obj;
    QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8());
    if(!doc.isNull())
    {
        if(doc.isObject())
        {
            obj = doc.object();
        }
        else
        {
            // TODO THROW ERROR
            qDebug() << "Document is not an object" << endl;
        }
    }
    else
    {
        // TODO THROW ERROR
        qDebug() << "Invalid JSON...\n" << str << endl;
    }

    return obj;
}

AppSocket::AppSocket(QObject *parent):
    QObject(parent),
    socket_(new QWebSocket())
{
    connect(socket_, &QWebSocket::connected, this, &AppSocket::onConnected);

    typedef void (QWebSocket:: *sslErrorsSignal)(const QList<QSslError> &);
    connect(socket_, static_cast<sslErrorsSignal>(&QWebSocket::sslErrors),
        this, &AppSocket::onSslErrors);

    socket_->open(QUrl(HOST_URL));
}

AppSocket::~AppSocket()
{
    socket_->close();
    delete socket_;
}

void AppSocket::sendMessage(const QString & event, const QString& content)
{
    QJsonObject payload;
    payload["content"] = content;
    QJsonObject message;
    message["event"] = event;
    message["payload"] = payload;
    QJsonDocument doc(message);
    QByteArray bytes = doc.toJson();
    socket_->sendTextMessage(QString(bytes));
}
