#include "atmselectorsocket.h"
#include "ATM/Model/atmparams.h"
#include "Utility/utilities.h"
#include "ATM/clienterror.h"
#include <QJsonArray>

QString ATMSelectorSocket::EVENT_NAME = Utility::getInstance().getString("ATMSelectorSocket_event_name");

void ATMSelectorSocket::askForATMParams()
{
    sendMessage(EVENT_NAME, "");
}

void ATMSelectorSocket::doOnTextMessageReceived(const QJsonObject & in)
{
    //TO REMOVE
    qDebug() << "Received json (ATMSelectorSocket):\n" << QJsonDocument(in).toJson() << "\n\n";
    //TO REMOVE
    QJsonValue ev(in["event"]);
    QJsonValue pl(in["payload"]);
    if(ev.isNull() || ev.isUndefined() || !ev.isString() || pl.isNull() || pl.isUndefined() || !pl.isObject())
        qFatal("%s", QString(ClientError("ATMSelectorSocket on receive json error",
                       ClientError::PARSING_ERROR, QJsonDocument(in).toJson())).toLatin1().constData());
    QJsonObject plobj(pl.toObject());
    QJsonValue er(plobj["error"]);
    QJsonValue ct(plobj["content"]);
    if(ct.isNull() || ct.isUndefined() || !ct.isArray())
        qFatal("%s", QString(ClientError("ATMSelectorSocket on receive json error",
                       ClientError::PARSING_ERROR, QJsonDocument(in).toJson())).toLatin1().constData());
    if(!er.isNull() && !er.isUndefined() && er.isString()) {
        // REMOVE
        qDebug() << "error selector: \n" << er.toString() << "\n\n";
        emit errorOccured(er.toString());
    }
    else if(ev.toString() == EVENT_NAME)
        emit receivedATMParams(parseParams(ct.toArray()));
    else
        qFatal("%s", QString(ClientError("ATMSelectorSocket on receive event error",
                       ClientError::UNDEFINED_EVENT, ev.toString())).toLatin1().constData());
}

QList<ATMParams> ATMSelectorSocket::parseParams(const QJsonArray & ps)
{
    QList<ATMParams> res;
    QJsonValue val;
    for(int i =0; i< ps.size(); ++i)
    {
        val = ps.at(i);
        if(val.isNull() || val.isUndefined() || !val.isObject())
            qFatal("%s", QString(ClientError("ATMSelectorSocket on parsing array error",
                           ClientError::PARSING_ERROR, QJsonDocument(ps).toJson())).toLatin1().constData());
        res.append(ATMParams::fromJson(ps.at(i).toObject()));
    }
    return res;
}

ATMSelectorSocket::ATMSelectorSocket(QObject* parent):
    AppSocket(parent)
{}

ATMSelectorSocket::~ATMSelectorSocket()
{}
