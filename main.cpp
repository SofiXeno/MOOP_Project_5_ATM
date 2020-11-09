#include <QApplication>
#include "Utility/utilities.h"
#include "ATMSelector/atmselector.h"
#include "ATMSelector/atmselectorwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ATMSelector* selector = new ATMSelector();
    ATMSelectorWidget widget(selector);
    widget.show();


    //TODO add alternate launch ATM

    return a.exec();
}
