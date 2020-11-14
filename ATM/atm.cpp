#include "atm.h"
<<<<<<< Updated upstream
#include "ATM/Model/atmparams.h"
#include "ATM/Model/atmcard.h"
#include "ATM/Socket/atmsocket.h"
=======
#include <assert.h>

>>>>>>> Stashed changes

void ATM::backOnStart(const ATMParams & par)
{
    // assert par_ == nullptr;
    par_ = new ATMParams(par);
    emit atmStarted();
}

void ATM::backInsertCard(const ATMCard &, const bool)
{
    emit cardInserted();
}

void ATM::backFreeCard()
{
    emit cardFree();
}

void ATM::backValidatePin(const size_t counter)
{
    emit pinValidated(counter);
}

void ATM::backChangePin()
{
    emit pinChanged();
}

void ATM::backSendToCard(const ATMCard &)
{
    emit cashSend();
}

void ATM::backCheckBal(const ATMCard &)
{
    emit balChecked();
}

void ATM::backTakeCash(const ATMCard &, const long)
{
    emit cashTaken();
}

void ATM::backError(const QString & error)
{
    emit errorOccured(error);
}

ATM::ATM(const size_t atm_id):
    socket_(new ATMSocket()),
    par_(nullptr),
    card_(nullptr)
{
    socket_->askStart(atm_id);
}

ATM::~ATM()
{}

void ATM::insertCard(const QString & number)
{
    socket_->askInsertCard(par_->atmId(), number);
}

void ATM::freeCard()
{
    socket_->askFreeCard(par_->atmId());
}

void ATM::validatePin(const size_t pin)
{
    socket_->askValidatePin(par_->atmId(), pin);
}

void ATM::changePin(const size_t pin)
{
    socket_->askChangePin(par_->atmId(), pin);
}

void ATM::sendToCard(const QString & number, const size_t sum)
{
    socket_->askSendToCard(par_->atmId(), number, sum);
}

void ATM::checkBal()
{
    socket_->askCheckBal(par_->atmId());
}

void ATM::takeCash(const size_t sum)
{
    socket_->askTakeCash(par_->atmId(), sum);
}
