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
    ui->lineEdit_cardNum->setInputMask("9999-9999-9999-9999");
    ui->lineEdit_PIN->setInputMask("9999");
    ui->lineEdit_attemptNum->setInputMask("9");
}

MainWindow::~MainWindow()
{
    delete ui;
}


//page 1 -- insert card
void MainWindow::on_insertButton_page0_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(4);
}

//------------------------------------------------
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
//--------------------------------------------------------



//page 2 -- enter card number after insertion
void MainWindow::on_num1_4_clicked()
{
    ui->lineEdit_cardNum->insert("1");
}

void MainWindow::on_num2_4_clicked()
{
    ui->lineEdit_cardNum->insert("2");
}

void MainWindow::on_num3_4_clicked()
{
    ui->lineEdit_cardNum->insert("3");
}

void MainWindow::on_num4_4_clicked()
{
    ui->lineEdit_cardNum->insert("4");
}

void MainWindow::on_num5_4_clicked()
{
    ui->lineEdit_cardNum->insert("5");
}

void MainWindow::on_num6_4_clicked()
{
    ui->lineEdit_cardNum->insert("6");
}

void MainWindow::on_num7_4_clicked()
{
    ui->lineEdit_cardNum->insert("7");
}

void MainWindow::on_num8_4_clicked()
{
    ui->lineEdit_cardNum->insert("8");
}

void MainWindow::on_num9_4_clicked()
{
    ui->lineEdit_cardNum->insert("9");
}

void MainWindow::on_num0_4_clicked()
{
    ui->lineEdit_cardNum->insert("0");
}

void MainWindow::on_clearOne_4_clicked()
{
    ui->lineEdit_cardNum->backspace();
}

void MainWindow::on_clearButton_page4_clicked()
{
    ui->lineEdit_cardNum->clear();
}

void MainWindow::on_okButton_page4_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(2);
}

void MainWindow::on_backButton_page4_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(0);
}


//page enter PIN after card insertion (3d page)
void MainWindow::on_num1_2_clicked()
{
    ui->lineEdit_PIN->insert("1");
}

void MainWindow::on_num2_2_clicked()
{
    ui->lineEdit_PIN->insert("2");
}

void MainWindow::on_num3_2_clicked()
{
    ui->lineEdit_PIN->insert("3");
}

void MainWindow::on_num4_2_clicked()
{
    ui->lineEdit_PIN->insert("4");
}

void MainWindow::on_num5_2_clicked()
{
    ui->lineEdit_PIN->insert("5");
}

void MainWindow::on_num6_2_clicked()
{
    ui->lineEdit_PIN->insert("6");
}

void MainWindow::on_num7_2_clicked()
{
    ui->lineEdit_PIN->insert("7");
}

void MainWindow::on_num8_2_clicked()
{
    ui->lineEdit_PIN->insert("8");
}

void MainWindow::on_num9_2_clicked()
{
    ui->lineEdit_PIN->insert("9");
}

void MainWindow::on_num0_2_clicked()
{
    ui->lineEdit_PIN->insert("0");
}

void MainWindow::on_clearOne_clicked()
{
    ui->lineEdit_PIN->backspace();
}

void MainWindow::on_backButton_page2_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(4);
}

void MainWindow::on_okButton_page2_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(1);
}
//сделать проверку пина
