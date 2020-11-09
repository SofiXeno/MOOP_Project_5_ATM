#include "atmselectorsocket.h"
#include "Utility/utilities.h"
#include <QJsonArray>

QUrl ATMSelectorSocket::HOST_URL = Utilities::getInstance().getVariable("ATMSelectorSocket_host_url");
QString ATMSelectorSocket::EVENT_NAME = Utilities::getInstance().getVariable("ATMSelectorSocket_event_name");

QUrl ATMSelectorSocket::getHOST_URL()
{
    return HOST_URL;
}

QString ATMSelectorSocket::getEVENT_NAME()
{
    return EVENT_NAME;
}

void ATMSelectorSocket::askForATMParams()
{
    sendMessage(EVENT_NAME, "");
}

void ATMSelectorSocket::doOnTextMessageReceived(const QJsonObject & in)
{
    if(!in.isEmpty() && in["event"] == EVENT_NAME)
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
        res.append(ATMParams::jsonToObject(ps.at(i)));
        // CATCH ERRORS
    }
    return res;
}

ATMSelectorSocket::ATMSelectorSocket(QObject* parent):
    AppSocket(HOST_URL, parent)
{}

ATMSelectorSocket::~ATMSelectorSocket()
{}
