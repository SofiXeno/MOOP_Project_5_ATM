#include "utilities.h"
#include <QFile>
#include <qiodevice.h>
#include <QTextStream>
#include <QJsonArray>
#include <QDebug>


Utility::Utility()
{
    QFile file("../config.json");
    if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << file.errorString();
            throw UtilityError(file.errorString(), UtilityError::FILE_ERROR);
    }
    QJsonParseError jsonError;
    QJsonDocument json = QJsonDocument::fromJson(file.readAll(),&jsonError);
    if (jsonError.error != QJsonParseError::NoError)
        throw UtilityError(jsonError.errorString(), UtilityError::PARSING_ERROR);
    map_ = new QMap<QString, QVariant>(json.toVariant().toMap());
}

Utility &Utility::getInstance()
{
    static Utility instance;
    return instance;
}

QVariant Utility::getVariable(const QString &name)
{
    if(!map_->contains(name))
        throw UtilityError(name, UtilityError::GETTING_ERROR);
    return (*map_)[name];
}

QString Utility::getString(const QString& name)
{
    return getVariable(name).toString();
}

QList<QString> Utility::getStringArr(const QString& name)
{
    QJsonArray arr(getVariable(name).toJsonArray());
    QList<QString> res;
    for(int i = 0; i< arr.size(); ++i)
        res.append(arr.at(i).toString());
    return res;
}



Utility::UtilityError::UtilityError(const QString & error, const Utility::UtilityError::ErrorCodes code):
    error_(error),
    code_(code)
{}

Utility::UtilityError::UtilityError(const Utility::UtilityError & that)
{
    error_ = that.error_;
    code_ = that.code_;
}

Utility::UtilityError::~UtilityError()
{}

const QString& Utility::UtilityError::error() const
{
    return error_;
}

Utility::UtilityError::ErrorCodes Utility::UtilityError::code() const
{
    return code_;
}

Utility::UtilityError::operator QString() const
{
    return this->error_ + " with code: " + this->code_;
}

Utility::UtilityError &Utility::UtilityError::operator=(const Utility::UtilityError & that)
{
    if(this == &that)
        return *this;
    error_ = that.error_;
    code_ = that.code_;
    return *this;
}
