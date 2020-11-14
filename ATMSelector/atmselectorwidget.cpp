#include "atmselectorwidget.h"
#include "ui_atmselectorwidget.h"
#include "atmselector.h"

ATMSelectorWidget::ATMSelectorWidget(ATMSelector* out,QWidget *parent) :
    QWidget(parent),
    out_(out),
    ui_(new Ui::ATMSelectorWidget)
{
    ui_->setupUi(this);
    connect(out, SIGNAL(paramsChanged()), this, SLOT(on_refreshButton__answer()));
}

ATMSelectorWidget::~ATMSelectorWidget()
{
    delete ui_;
}

void ATMSelectorWidget::on_refreshButton__answer()
{
    QString("kek");
}

void ATMSelectorWidget::on_refreshButton__clicked()
{
    out_->refreshATMParams();
}
