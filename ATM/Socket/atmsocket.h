#ifndef ATMSOCKET_H
#define ATMSOCKET_H

#include <QObject>
#include "appsocket.h"


class ATMSocket: public AppSocket
{
private:

    static QUrl HOST_URL;

public:
    ATMSocket(QObject *parent = Q_NULLPTR);
    static QUrl getHOST_URL();
};

#endif // ATMSOCKET_H
