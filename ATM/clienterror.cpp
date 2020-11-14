#include "clienterror.h"

ClientError::ClientError(const QString & er, const ClientError::Codes c, const QString& add):
    error_(er),
    code_(c),
    add_(add)
{}

ClientError::~ClientError()
{}

ClientError::ClientError(const ClientError & c):
    error_(c.error_),
    code_(c.code_),
    add_(c.add_)
{}

ClientError &ClientError::operator=(const ClientError & that)
{
    if(this == &that)
        return *this;
    error_ = that.error_;
    code_ = that.code_;
    add_ = that.add_;
    return *this;
}

ClientError::operator QString() const
{
    QString res(error_ + " with code: " + QString::number(code_));
    if (!add_.isEmpty())
            res += "\nDetails: \n" + add_;
    return res;
}

