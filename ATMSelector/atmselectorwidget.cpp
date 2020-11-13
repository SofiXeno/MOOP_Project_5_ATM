#include "atmselectorwidget.h"
#include "ui_atmselectorwidget.h"
#include "atmselector.h"

class ATMParams;

ATMSelectorWidget::ATMSelectorWidget(ATMSelector* out,QWidget *parent) :
    QWidget(parent),
    out_(out),
    ui_(new Ui::ATMSelectorWidget)
{
    ui_->setupUi(this);

    connect(out, &ATMSelector::paramsChanged, this, &ATMSelectorWidget::onParamsUpdated);


ATMSelectorWidget::~ATMSelectorWidget()
{
    delete ui_;
}

void ATMSelectorWidget::onParamsUpdated()
{
    ui_->atmsList->clear();
    const QList<ATMParams> * newAtms(out_->getParams());
    for(int i = 0; i < newAtms->length(); ++i){
        const ATMParams* p = &(newAtms->at(i));
        QString item("АТМ: ");
        item.append(QString::number(p->atmId()));
        item.append(", Банк: ");
        item.append(p->bankName());
        ui_->atmsList->addItem(item);
    }
}

void ATMSelectorWidget::on_refreshButton_clicked()
{
    out_->refreshATMParams();


}
