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

    //static QString CONFIG_PATH;

    QMap<QString, QVariant> map_;

public:
    static Utilities& getInstance();

    QString getVariable(const QString& name);
    QString getVariable(const QString& name, const QString& sub);
};

#endif // UTILITIES_H
