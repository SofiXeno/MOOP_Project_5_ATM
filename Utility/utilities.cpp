#include "utilities.h"
#include <QFile>
#include <qiodevice.h>
#include <QTextStream>
#include <QJsonArray>
#include <QDebug>


Utilities::Utilities()
{
    QFile file( "/Users/sofixeno/Desktop/Booblik/MOOP_Project_5_ATM/config.json");
    if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << file.error();
            exit(-100);
    }
    //ERROR THROW
    QJsonParseError jsonError;
    QJsonDocument json = QJsonDocument::fromJson(file.readAll(),&jsonError);
    if (jsonError.error != QJsonParseError::NoError){
        // TODO THROW ERROR
    }
    // TODO CHECK RESULTS
    map_ = json.toVariant().toMap();
}

Utilities &Utilities::getInstance()
{
    static Utilities instance;
    return instance;
}

QVariant Utilities::getVariable(const QString &name)
{
    if(!map_.contains(name))
    {
       // TODO THROW SOMETHING
        return QString();
    }
    return map_[name];
}

QString Utilities::getString(const QString& name)
{
    // add checks
    return getVariable(name).toString();
}

QList<QString> Utilities::getStringArr(const QString& name)
{
    // ADD CHECKS
    QJsonArray arr(getVariable(name).toJsonArray());
    QList<QString> res;
    for(int i = 0; i< arr.size(); ++i)
        res.append(arr.at(i).toString());
    return res;
}


