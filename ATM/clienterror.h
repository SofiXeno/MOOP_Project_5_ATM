#ifndef CLIENTERROR_H
#define CLIENTERROR_H

#include <QString>

class ClientError
{
public:
    enum Codes {PARSING_ERROR, SERVER_REPLY_ERROR, UNDEFINED_EVENT, FILE_ERROR, CASH_ERROR};

    QString error_;
    Codes code_;
    QString add_;

public:
    ClientError(const QString&, const Codes, const QString& = QString());
    ~ClientError();
    ClientError(const ClientError&);
    ClientError& operator=(const ClientError&);

    operator QString() const;
};

#endif // CLIENTERROR_H
