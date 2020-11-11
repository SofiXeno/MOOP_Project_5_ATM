#include "utilities.h"
#include <QFile>
#include <qiodevice.h>
#include <QTextStream>
#include <QDebug>


Utilities::Utilities()
{
    QString f = "../config.json";
    QFile file(f);
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

QString Utilities::getVariable(const QString &name)
{
    if(!map_.contains(name))
    {
       // TODO THROW SOMETHING
        return QString();
    }
    return map_[name].toString();
}
