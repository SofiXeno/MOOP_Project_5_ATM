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

    //-------------Input card number page-----------------------
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

   //---------------PIN input page---------------------

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

     void on_lineEdit_PIN_editingFinished();

    //----------------Main menu page-------------------

     void on_cashTransfersButton_clicked();

     void on_cardBalanceButton_clicked();

    void on_cardSettingsButton_clicked();

    void on_cashWithdrawalButton_clicked();

    //---------------Settings page---------------------

    void on_Button_changePin_clicked();

    void on_Button_otherATMs_clicked();

    void on_Button_20grn_clicked();

    void on_Button_50grn_clicked();

    void on_Button_100grn_clicked();

    void on_Button_200grn_clicked();

    void on_Button_500grn_clicked();

    void on_Button_1000grn_clicked();

    void on_backButton_page5_clicked();

    void on_Button_AnySum_clicked();

    void on_num1_6_clicked();

    void on_num2_6_clicked();

    void on_num3_6_clicked();

    void on_num4_6_clicked();

    void on_num5_6_clicked();

    void on_num6_6_clicked();

    void on_num7_6_clicked();

    void on_num8_6_clicked();

    void on_num9_6_clicked();

    void on_num00_6_clicked();

    void on_num0_6_clicked();

    void on_clearOne_6_clicked();

    void on_clearButton_page6_clicked();

    void on_backButton_page6_clicked();

    void on_okButton_page6_clicked();

    void on_num1_3_clicked();

    void on_num2_3_clicked();

    void on_num3_3_clicked();

    void on_num4_3_clicked();

    void on_num5_3_clicked();

    void on_num6_3_clicked();

    void on_num7_3_clicked();

    void on_num8_3_clicked();

    void on_num9_3_clicked();

    void on_num0_3_clicked();

    void on_clearOne_3_clicked();

    void on_clearButton_page3_clicked();

    void on_okButton_page3_clicked();

private:
    Ui::MainWindow *ui;
};

