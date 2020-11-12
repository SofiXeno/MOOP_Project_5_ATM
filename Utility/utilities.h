#ifndef UTILITIES_H
#define UTILITIES_H

#include <QString>
#include <QJsonDocument>
#include <QMap>

class Utilities
{
private:
    Utilities();
    Utilities(const Utilities&);
    Utilities& operator=(const Utilities&);

    QMap<QString, QVariant> map_;

    QVariant getVariable(const QString& name);

public:
    static Utilities& getInstance();

    QString getString(const QString& name);
    QList<QString> getStringArr(const QString& name);

};

#endif // UTILITIES_H
