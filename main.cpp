#include <QApplication>
#include "Utility/utilities.h"
#include "ATMSelector/atmselector.h"
#include "ATMSelector/atmselectorwidget.h"
#include "ATM/atm.h"

#include "mainwindow.h"

#include <QDebug>



//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    ATMSelector selector;
//    ATMSelectorWidget widget(&selector);
//    widget.show();

//  //  selector.refreshATMParams();

//    //TODO add alternate launch ATM
//    return a.exec();
//}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    ATMSelector selector;
    ATMSelectorWidget widget(&selector);
    widget.show();

    //qDebug() << Utility::UtilityError("", Utility::UtilityError::ErrorCodes::FILE_ERROR);

  //  selector.refreshATMParams();

    //TODO add alternate launch ATM

    return a.exec();
}
