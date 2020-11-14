#ifndef ATMSELECTOR_H
#define ATMSELECTOR_H

#include <QObject>
#include <QList>

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

    ATMSelector(const ATMSelector&) = delete;
    ATMSelector(const ATMSelector&&) = delete;
    ATMSelector& operator=(const ATMSelector&) = delete;
    ATMSelector& operator=(ATMSelector&&) = delete;

public:
    explicit ATMSelector(QObject *parent = Q_NULLPTR);
    virtual ~ATMSelector();

    QList<ATMParams>* params();
    void refreshATMParams();

   const QList<ATMParams>* getParams() const;

signals:
   void paramsChanged();
   void errorOccured(const QString&);
};

#endif // ATMSELECTOR_H
