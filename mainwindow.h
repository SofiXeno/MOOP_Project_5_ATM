#pragma once

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_insertButton_page0_clicked();

    void on_cashTransfersButton_clicked();

    void on_cardBalanceButton_clicked();

private:
    Ui::MainWindow *ui;
};

