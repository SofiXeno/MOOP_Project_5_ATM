#ifndef ATMSELECTORWIDGET_H
#define ATMSELECTORWIDGET_H

#include"ATM/Model/atmparams.h"
#include <QMainWindow>

class ATMSelector;

namespace Ui {
class ATMSelectorWidget;
}

class ATMSelectorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ATMSelectorWidget(ATMSelector* out, QWidget *parent = nullptr);
    ~ATMSelectorWidget();

private slots:
    void on_refreshButton__clicked();

private:
    ATMSelector* out_;
    Ui::ATMSelectorWidget *ui_;
};

#endif // ATMSELECTORWIDGET_H
