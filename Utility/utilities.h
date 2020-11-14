#ifndef UTILITIES_H
#define UTILITIES_H

#include <QString>
#include <QJsonDocument>
#include <QMap>
#include <iostream>

using namespace std;

class Utility
{
private:
    Utility();

    Utility(const Utility&) = delete;
    Utility(Utility&&) = delete;
    Utility& operator=(const Utility&) = delete;
    Utility& operator=(Utility&&) = delete;

    QMap<QString, QVariant>* map_;

    QVariant getVariable(const QString& name);

public:
    static Utility& getInstance();

    QString getString(const QString& name);
    QList<QString> getStringArr(const QString& name);

    class UtilityError{
        public:
        enum ErrorCodes {FILE_ERROR, PARSING_ERROR, GETTING_ERROR};
        private:
            QString error_;
            ErrorCodes code_;

        public:
            UtilityError(const QString&, const ErrorCodes);
            UtilityError(const UtilityError&);
            ~UtilityError();
            const QString& error() const;
            ErrorCodes code() const;
            operator QString() const;
            UtilityError& operator=(const UtilityError&);
    };
};


#endif // UTILITIES_H
