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
    //------------------------------------

    void on_cashTransfersButton_clicked();

    void on_cardBalanceButton_clicked();

    //--------------------------
    void on_num1_4_clicked();

    void on_num2_4_clicked();

    void on_num3_4_clicked();

    void on_num4_4_clicked();

    void on_num5_4_clicked();

    void on_num6_4_clicked();

    void on_num7_4_clicked();

    void on_num8_4_clicked();

    void on_num9_4_clicked();

    void on_num0_4_clicked();

    void on_clearOne_4_clicked();

    void on_clearButton_page4_clicked();

    void on_okButton_page4_clicked();

    void on_backButton_page4_clicked();
   //------------------------------------


    void on_num1_2_clicked();

    void on_num2_2_clicked();

    void on_num3_2_clicked();

    void on_num4_2_clicked();

    void on_num5_2_clicked();

    void on_num6_2_clicked();

    void on_num7_2_clicked();

    void on_num8_2_clicked();

    void on_num9_2_clicked();

    void on_num0_2_clicked();

    void on_clearOne_clicked();

    void on_backButton_page2_clicked();

    void on_okButton_page2_clicked();

private:
    Ui::MainWindow *ui;
};

