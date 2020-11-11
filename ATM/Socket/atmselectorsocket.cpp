#include "atmselectorsocket.h"
#include "ATM/Model/atmparams.h"
#include "Utility/utilities.h"
#include <QJsonArray>

QString ATMSelectorSocket::EVENT_NAME = Utilities::getInstance().getString("ATMSelectorSocket_event_name");

void ATMSelectorSocket::askForATMParams()
{
    sendMessage(EVENT_NAME, "");
}

void ATMSelectorSocket::doOnTextMessageReceived(const QJsonObject & in)
{
    QJsonValue val(in["error"]);
    if(!val.isString())
        emit errorOccured(val.toString());
    else if(in["event"] == EVENT_NAME)
        // TODO Check for exception
        emit receivedATMParams(parseParams(in["payload"]));
    // TODO WRONG MESSAGE RECEIVED

}

QList<ATMParams> ATMSelectorSocket::parseParams(const QJsonValue & val)
{
    // CHECK FOR ERRORS
    QJsonArray ps = val.toArray();
    QList<ATMParams> res;
    for(int i =0; i< ps.size(); ++i)
    {
        res.append(ATMParams::fromJson(ps.at(i)));
        // CATCH ERRORS
    }
    return res;
}

ATMSelectorSocket::ATMSelectorSocket(QObject* parent):
    AppSocket(parent)
{}

ATMSelectorSocket::~ATMSelectorSocket()
{}
