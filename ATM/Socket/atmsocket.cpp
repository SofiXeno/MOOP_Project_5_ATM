#include "atmsocket.h"
#include "Utility/utilities.h"

QUrl ATMSocket::HOST_URL = Utilities::getInstance().getVariable("ATMSocket_host_url");

QUrl ATMSocket::getHOST_URL()
{
    return HOST_URL;
}

ATMSocket::ATMSocket( QObject *parent):
    AppSocket(HOST_URL,parent)
{}
