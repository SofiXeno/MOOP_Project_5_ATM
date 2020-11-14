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

    void on_cardSettingsButton_clicked();

    void on_cashWithdrawalButton_clicked();

    void on_lineEdit_PIN_editingFinished();

    void on_Button_changePin_clicked();

    void on_Button_otherATMs_clicked();

private:
    Ui::MainWindow *ui;
};

