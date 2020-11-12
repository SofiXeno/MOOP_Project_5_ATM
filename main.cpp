#include <QApplication>
#include "Utility/utilities.h"
#include "ATMSelector/atmselector.h"
#include "ATMSelector/atmselectorwidget.h"
#include "ATM/atm.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ATMSelector selector;
    ATMSelectorWidget widget(&selector);
    widget.show();

  //  selector.refreshATMParams();

    //TODO add alternate launch ATM
    return a.exec();
}
