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
    qDebug() << "Received json (ATMSelectorSocket):\n" << QJsonDocument(in).toBinaryData() << "\n\n";
    //TO REMOVE
    QJsonValue val(in["error"]);
    QJsonValue ev(in["event"]);
    QJsonValue pl(in["payload"]);
    if(val.isNull()
            || ev.isNull() || ev.isUndefined() || !ev.isString()
            // check payload enters
            || pl.isNull() || pl.isUndefined() || !pl.isArray())
        qFatal("%s", QString(ClientError("ATMSelectorSocket on receive json error",
                       ClientError::PARSING_ERROR, QJsonDocument(in).toBinaryData())).constData());
    else if(!val.isUndefined() && val.isString()) {
        // REMOVE
        qDebug() << "error selector: \n" << val.toString() << "\n\n";
        emit errorOccured(val.toString());
    }
    else if(ev.toString() == EVENT_NAME)
        emit receivedATMParams(parseParams(pl.toArray()));
    else
        qFatal("%s", QString(ClientError("ATMSelectorSocket on receive event error",
                       ClientError::UNDEFINED_EVENT, ev.toString())).constData());
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
                           ClientError::PARSING_ERROR, QJsonDocument(ps).toBinaryData())).constData());
        res.append(ATMParams::fromJson(ps.at(i).toObject()));
    }
    return res;
}

ATMSelectorSocket::ATMSelectorSocket(QObject* parent):
    AppSocket(parent)
{}

ATMSelectorSocket::~ATMSelectorSocket()
{}
