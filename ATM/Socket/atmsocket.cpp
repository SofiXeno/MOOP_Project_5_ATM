#include "atmsocket.h"
#include "Utility/utilities.h"
#include "ATM/Model/atmparams.h"
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
                emit replyOnInsertedCard(
                    ATMCard::fromJson(obj),
                    obj["atm_id"].toBool());
                break;
        case EVENTS::CHECK_PIN:
                emit replyOnValidatePin(val.toString().toUInt());
                break;
        case EVENTS::FREE_CARD:
                emit replyOnFreeCard();
                break;
        case EVENTS::SEND_TO_CARD:
                emit replyOnSendToCard(ATMCard::fromJson(obj));
                break;
        case EVENTS::TAKE_FROM_CARD:
                emit replyOnTakeCash(ATMCard::fromJson(obj), obj["atm_cash"].toString().toLong());
                break;
        case EVENTS::CHECK_BAL:
                emit replyOnCheckBal(ATMCard::fromJson(obj));
                break;
        case EVENTS::CHANGE_PIN:
                emit replyOnChangePin();
                break;
        default:
               // throw error
               return;
    }
}

QJsonObject ATMSocket::formJson(const size_t atm_id)
{
    QJsonObject obj;
    obj.insert("atm_id", QString::number(atm_id));
    return obj;
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

void ATMSocket::askInsertCard(const size_t atm_id, const QString & number)
{
    QJsonObject obj = formJson(atm_id);
    obj.insert("number", number);
    sendMessage(EVENT_STRINGS.at(EVENTS::INSERT_CARD), QJsonDocument(obj).toJson());
}

void ATMSocket::askFreeCard(const size_t atm_id)
{
    sendMessage(EVENT_STRINGS.at(EVENTS::FREE_CARD), QString::number(atm_id));
}

void ATMSocket::askValidatePin(const size_t atm_id, const size_t pin)
{
    QJsonObject obj = formJson(atm_id);
    obj.insert("pin", QString::number(pin));
    sendMessage(EVENT_STRINGS.at(EVENTS::CHECK_PIN), QJsonDocument(obj).toJson());
}

void ATMSocket::askChangePin(const size_t atm_id, const size_t pin)
{
    QJsonObject obj = formJson(atm_id);
    obj.insert("pin", QString::number(pin));
    sendMessage(EVENT_STRINGS.at(EVENTS::CHANGE_PIN), QJsonDocument(obj).toJson());
}

void ATMSocket::askSendToCard(const size_t atm_id, const QString & number, const size_t sum)
{
    QJsonObject obj = formJson(atm_id);
    obj.insert("number", number);
    obj.insert("sum", QString::number(sum));
    sendMessage(EVENT_STRINGS.at(EVENTS::SEND_TO_CARD), QJsonDocument(obj).toJson());
}

void ATMSocket::askCheckBal(const size_t atm_id)
{
    sendMessage(EVENT_STRINGS.at(EVENTS::CHECK_BAL), QString::number(atm_id));
}

void ATMSocket::askTakeCash(const size_t atm_id, const size_t sum)
{
    QJsonObject obj = formJson(atm_id);
    obj.insert("sum", QString::number(sum));
    sendMessage(EVENT_STRINGS.at(EVENTS::TAKE_FROM_CARD), QJsonDocument(obj).toJson());
}
