#include "atm.h"
#include <assert.h>

void ATM::backOnStart(const ATMParams & par)
{
    assert(par_ == Q_NULLPTR);
    par_ = new ATMParams(par);
    emit atmStarted();
}

void ATM::backInsertCard()
{
    assert(card_ == Q_NULLPTR);
    emit cardInserted();
}

void ATM::backFreeCard()
{
    assert(card_ != Q_NULLPTR);
    delete card_;
    card_ = Q_NULLPTR;
    emit cardFree();
}

void ATM::backPinSuccess(const ATMCard2 & card)
{
    assert(card_ == Q_NULLPTR);
    card_ = new ATMCard2(card);
    emit pinSuccess();
}

void ATM::backValidatePin(const size_t counter)
{
    assert(card_ == Q_NULLPTR);
    emit pinValidated(counter);
}

void ATM::backChangePin()
{
    assert(card_ != Q_NULLPTR);
    emit pinChanged();
}

void ATM::backSendToCard(const ATMCard2 & card)
{
    assert(card_ != Q_NULLPTR);
    delete card_;
    card_ = new ATMCard2(card);
    emit cashSend();
}

void ATM::backCheckBal(const ATMCard2 & card)
{
    assert(card_ != Q_NULLPTR);
    delete card_;
    card_ = new ATMCard2(card);
    emit balChecked();
}

void ATM::backTakeCash(const ATMCard2 & card, const long money)
{
    assert(card_ != Q_NULLPTR);
    delete card_;
    card_ = new ATMCard2(card);
    long m = par_->money();
    par_->money() = money;
    emit cashTaken(m - money);
}

void ATM::backError(const QString & error)
{
    emit errorOccured(error);
}

ATM::ATM(const size_t atm_id):
    socket_(new ATMSocket()),
    par_(Q_NULLPTR),
    card_(Q_NULLPTR)
{
    socket_->askStart(atm_id);
}

ATM::~ATM()
{}

void ATM::insertCard(const QString & number)
{
    socket_->askInsertCard(number);
}

void ATM::freeCard()
{
    socket_->askFreeCard();
}

void ATM::validatePin(const size_t pin)
{
    socket_->askValidatePin(pin);
}

void ATM::changePin(const size_t pin)
{
    socket_->askChangePin(pin);
}

void ATM::sendToCard(const QString & number, const size_t sum)
{
    socket_->askSendToCard(number, sum);
}

void ATM::checkBal()
{
    socket_->askCheckBal();
}

void ATM::takeCash(const size_t sum)
{
    socket_->askTakeCash(sum);
}
