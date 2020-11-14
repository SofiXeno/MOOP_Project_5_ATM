#include "atmselector.h"
#include "atmselectorwidget.h"
#include "ATM/Socket/atmselectorsocket.h"
#include "ATM/Model/atmparams.h"
#include <QJsonArray>

void ATMSelector::updateParams(const QList<ATMParams> & l)
{
    if (params_ != Q_NULLPTR)
        delete params_;
    params_ = new QList<ATMParams>(l);
    emit paramsChanged();
}

ATMSelector::ATMSelector(QObject *parent):
    QObject(parent),
    params_(Q_NULLPTR),
    socket_(new ATMSelectorSocket())
{
    connect(socket_, &ATMSelectorSocket::receivedATMParams,this, &ATMSelector::updateParams);
    connect(socket_, &ATMSelectorSocket::errorOccured, this, &ATMSelector::errorOccured);
}

ATMSelector::~ATMSelector(){
    socket_->disconnect();
    delete socket_;
    if (params_ != Q_NULLPTR)
        delete params_;
    disconnect();
}

const QList<ATMParams>* ATMSelector::params() const
{
    return params_;
}

QList<ATMParams>* ATMSelector::params()
{
    return params_;
}

void ATMSelector::refreshATMParams()
{
    socket_->askForATMParams();
}
