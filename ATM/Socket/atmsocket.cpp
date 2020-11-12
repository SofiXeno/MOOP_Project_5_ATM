#include "atmsocket.h"
#include "Utility/utilities.h"
#include "ATM/Model/atmparams.h"
#include "ATM/Model/atmcard2.h"
#include <QJsonArray>
#include <QVariant>
#include <QJsonValue>

QList<QString> ATMSocket::EVENT_STRINGS = Utilities::getInstance().getStringArr("ATMSocket_events");

void ATMSocket::doOnTextMessageReceived(const QJsonObject & in)
{
    if(in.isEmpty())
        // TODO THROW error
        return;
    // CHECK FOR WRONG
    int i = EVENT_STRINGS.indexOf(in["event"].toString());
    if (i == -1)
        // THROW ERROR
        return;
    // CHECK FOR ERROR
    QJsonValue val(in["error"]);
    if(val.isString())
    {
        emit replyOnError(val.toString());
        return;
    }
    val = in["payload"];
    // may cause error
    QJsonObject obj = val.toObject();
    switch (i) {
        case EVENTS::START_ATM:
            emit replyOnStart(ATMParams::fromJson(obj));
            break;
        case EVENTS::INSERT_CARD:
                emit replyOnInsertedCard();
                break;
        case EVENTS::CHECK_PIN:
            // error on creating object
                emit replyOnValidatePin(val.toString().toUInt());
                break;
        case EVENTS::SUCCESS_PIN:
                emit replyOnSuccessPin(ATMCard2::fromJson(obj));
                break;
        case EVENTS::FREE_CARD:
                emit replyOnFreeCard();
                break;
        case EVENTS::SEND_TO_CARD:
                emit replyOnSendToCard(ATMCard2::fromJson(obj));
                break;
        case EVENTS::TAKE_FROM_CARD:
                emit replyOnTakeCash(ATMCard2::fromJson(obj), obj["atm_cash"].toString().toLong());
                break;
        case EVENTS::CHECK_BAL:
                emit replyOnCheckBal(ATMCard2::fromJson(obj));
                break;
        case EVENTS::CHANGE_PIN:
                emit replyOnChangePin();
                break;
        default:
               // throw error
               return;
    }
}

ATMSocket::ATMSocket(QObject *parent):
    AppSocket(parent)
{}

ATMSocket::~ATMSocket()
{}

// a lot of duplicates

void ATMSocket::askStart(const size_t atm_id)
{
    sendMessage(EVENT_STRINGS.at(EVENTS::START_ATM), QString::number(atm_id));
}

void ATMSocket::askInsertCard(const QString & number)
{
    sendMessage(EVENT_STRINGS.at(EVENTS::INSERT_CARD), number);
}

void ATMSocket::askFreeCard()
{
    sendMessage(EVENT_STRINGS.at(EVENTS::FREE_CARD), "");
}

void ATMSocket::askValidatePin(const size_t pin)
{
    sendMessage(EVENT_STRINGS.at(EVENTS::CHECK_PIN), QString::number(pin));
}

void ATMSocket::askChangePin(const size_t pin)
{
    sendMessage(EVENT_STRINGS.at(EVENTS::CHANGE_PIN), QString::number(pin));
}

void ATMSocket::askSendToCard(const QString & number, const size_t sum)
{
    QJsonObject obj;
    obj.insert("number", number);
    obj.insert("sum", QString::number(sum));
    sendMessage(EVENT_STRINGS.at(EVENTS::SEND_TO_CARD), QJsonDocument(obj).toJson());
}

void ATMSocket::askCheckBal()
{
    sendMessage(EVENT_STRINGS.at(EVENTS::CHECK_BAL), "");
}

void ATMSocket::askTakeCash(const size_t sum)
{
    sendMessage(EVENT_STRINGS.at(EVENTS::TAKE_FROM_CARD), QString::number(sum));

}
