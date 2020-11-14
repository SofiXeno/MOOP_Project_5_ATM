#include "atmsocket.h"
#include "Utility/utilities.h"
#include "ATM/Model/atmparams.h"
#include "ATM/Model/atmcard2.h"
#include "ATM/clienterror.h"
#include <QJsonArray>
#include <QVariant>
#include <QJsonValue>

QList<QString> ATMSocket::EVENT_STRINGS = Utility::getInstance().getStringArr("ATMSocket_events");

void ATMSocket::doOnTextMessageReceived(const QJsonObject & in)
{
    //TO REMOVE
    qDebug() << "Received json (ATMSelectorSocket):\n" << QJsonDocument(in).toBinaryData() << "\n\n";
    //TO REMOVE

    if(in.isEmpty())
        qFatal("%s", QString(ClientError("ATMSocket on receive empty error",
                               ClientError::PARSING_ERROR, QJsonDocument(in).toBinaryData())).constData());

    QJsonValue er(in["error"]);
    QJsonValue ev(in["event"]);
    QJsonValue pl(in["payload"]);
    if(er.isNull()
            || ev.isNull() || ev.isUndefined() || !ev.isString()
            // check payload enters
            || pl.isNull() || pl.isUndefined() || !pl.isObject())
        qFatal("%s", QString(ClientError("ATMSocket on receive json error",
                               ClientError::PARSING_ERROR, QJsonDocument(in).toBinaryData())).constData());
    if(!er.isUndefined() && er.isString())
    {
        qDebug() << "error ATMScoket: \n" << er.toString() << "\n\n";
        emit replyOnError(er.toString());
        return;
    }
    QJsonObject obj = pl.toObject();
    switch (EVENT_STRINGS.indexOf(ev.toString())) {
        case EVENTS::START_ATM:
            emit replyOnStart(ATMParams::fromJson(obj));
            break;
        case EVENTS::INSERT_CARD:
                emit replyOnInsertedCard();
                break;
        case EVENTS::CHECK_PIN:
            // error on creating object
                emit replyOnValidatePin(er.toString().toUInt());
                break;
        case EVENTS::SUCCESS_PIN:
                emit replyOnSuccessPin(ATMCard::fromJson(obj));
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
                qFatal("%s", QString(ClientError("ATMSocket on receive json error",
                               ClientError::UNDEFINED_EVENT, QJsonDocument(in).toBinaryData())).constData());
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
