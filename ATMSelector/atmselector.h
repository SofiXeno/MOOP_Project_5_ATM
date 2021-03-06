#ifndef ATMSELECTOR_H
#define ATMSELECTOR_H

#include <QList>
#include <QObject>

class ATMSelectorSocket;
class ATMParams;
class ATMSelectorWidget;

class ATMSelector: public QObject
{
    Q_OBJECT;

private:
    QList<ATMParams>* params_;

    ATMSelectorSocket* socket_;

    void updateParams(const QList<ATMParams>&);

public:
    ATMSelector(QObject *parent = Q_NULLPTR);

    ~ATMSelector();

   void refreshATMParams();
   bool startATM(const size_t);

signals:
   void paramsChanged();
};

#endif // ATMSELECTOR_H
