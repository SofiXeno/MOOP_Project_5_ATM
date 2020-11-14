#include "utilities.h"
#include "ATM/clienterror.h"
#include <QFile>
#include <qiodevice.h>
#include <QTextStream>
#include <QJsonArray>
#include <QDebug>

Utility::Utility()
{

    QFile file( "/Users/sofixeno/Desktop/Booblik/MOOP_Project_5_ATM/config.json");
    if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << file.error();
            exit(-100);
    }
    //ERROR THROW

    QFile file("../config.json");
    if (!file.open(QIODevice::ReadOnly))
        qFatal("%s", QString(ClientError("Utilities on open file error",
                                       ClientError::FILE_ERROR, file.errorString())).constData());

    QJsonParseError jsonError;
    QJsonDocument json = QJsonDocument::fromJson(file.readAll(),&jsonError);
    if (jsonError.error != QJsonParseError::NoError)
        qFatal("%s", QString(ClientError("Utilities parsing file error",
                                       ClientError::PARSING_ERROR, jsonError.errorString())).toLatin1().constData());
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
        qFatal("%s", QString(ClientError("Utilities on getting variable",
                                       ClientError::FILE_ERROR, name)).constData());
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
