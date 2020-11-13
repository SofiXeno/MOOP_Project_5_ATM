#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "ATM/Model/atmcard2.h"
#include "ATM/atm.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_insertButton_page0_clicked()
{
     ui->mainStackedWidget->setCurrentIndex(4);
}


void MainWindow::on_cashTransfersButton_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(4);
}

void MainWindow::on_cardBalanceButton_clicked()
{





//    QMessageBox::information(this,"Баланс по картці", );
//    QMessageBox msgBox;
//    msgBox.setText("The document has been modified.");
}
