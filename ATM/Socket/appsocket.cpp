#include "appsocket.h"
#include "Utility/utilities.h"
#include <QDebug>
#include "ATM/clienterror.h"

QUrl AppSocket::HOST_URL = Utility::getInstance().getString("AppSocket_HOSTNAME");


void AppSocket::doOnConnected()
{
    qDebug() << "connected";
    connect(socket_, &QWebSocket::textMessageReceived,
            this, &AppSocket::onTextMessageReceived);
}

void AppSocket::doOnDisconnected()
{
    // try to connect againg
    disconnect();
    qDebug() << "socket " << socket_ << "\n disconnected!";
}

void AppSocket::doOnSslErrors(const QList<QSslError> &errors)
{
    QString res;
    for(int i = 0; i < errors.size(); ++i)
        res += errors[i].errorString();
    qFatal("%s", res.constData());
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
            qFatal("%s", QString(ClientError("AppSocket to json error",
                                             ClientError::PARSING_ERROR, QJsonDocument(obj).toBinaryData())).constData());
        }
    }
    else
    {
        qFatal("%s", QString(ClientError("AppSocket to json error",
                                         ClientError::PARSING_ERROR, QJsonDocument(obj).toBinaryData())).constData());
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
    disconnect();
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
