QT       += core gui
QT += websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ATM/Socket/appsocket.cpp \
    ATM/Socket/atmselectorsocket.cpp \
    ATM/Socket/atmsocket.cpp \
    ATM/atm.cpp \
    ATM/atmparams.cpp \
    ATMSelector/atmselector.cpp \
    ATMSelector/atmselectorwidget.cpp \
    Utility/utilities.cpp \
    form.cpp \
    form2.cpp \
    form2.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ATM/Socket/appsocket.h \
    ATM/Socket/atmselectorsocket.h \
    ATM/Socket/atmsocket.h \
    ATM/atm.h \
    ATM/atmparams.h \
    ATMSelector/atmselector.h \
    ATMSelector/atmselectorwidget.h \
    Utility/utilities.h \
    form.h \
    form2.h \
    form2.h \
    mainwindow.h

FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui \
    form2.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


HEADERS += \
    ATM/Socket/appsocket.h \
    ATM/Socket/atmselectorsocket.h \
    ATM/Socket/atmsocket.h \
    ATM/atm.h \
    ATM/atmparams.h \
    ATMSelector/atmselector.h \
    ATMSelector/atmselectorwidget.h \
    Utility/utilities.h \
    form.h \
    form2.h

FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


SOURCES += \
    ATM/Socket/appsocket.cpp \
    ATM/Socket/atmselectorsocket.cpp \
    ATM/Socket/atmsocket.cpp \
    ATM/atm.cpp \
    ATM/atmparams.cpp \
    ATMSelector/atmselector.cpp \
    ATMSelector/atmselectorwidget.cpp \
    Utility/utilities.cpp \
    form.cpp \
    form2.cpp \
    main.cpp

HEADERS += \
    ATM/Socket/appsocket.h \
    ATM/Socket/atmselectorsocket.h \
    ATM/Socket/atmsocket.h \
    ATM/atm.h \
    ATM/atmparams.h \
    ATMSelector/atmselector.h \
    ATMSelector/atmselectorwidget.h \
    Utility/utilities.h \
    form.h \
    form2.h \
    form2.h

FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


HEADERS += \
    ATM/Socket/appsocket.h \
    ATM/Socket/atmselectorsocket.h \
    ATM/Socket/atmsocket.h \
    ATM/atm.h \
    ATM/atmparams.h \
    ATMSelector/atmselector.h \
    ATMSelector/atmselectorwidget.h \
    Utility/utilities.h \
    form.h \
    form2.h

FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


HEADERS += \
    ATM/Socket/appsocket.h \
    ATM/Socket/atmselectorsocket.h \
    ATM/Socket/atmsocket.h \
    ATM/atm.h \
    ATM/atmparams.h \
    ATMSelector/atmselector.h \
    ATMSelector/atmselectorwidget.h \
    Utility/utilities.h \
    form.h \
    form2.h

FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


SOURCES += \
    ATM/Socket/appsocket.cpp \
    ATM/Socket/atmselectorsocket.cpp \
    ATM/Socket/atmsocket.cpp \
    ATM/atm.cpp \
    ATM/atmparams.cpp \
    ATMSelector/atmselector.cpp \
    ATMSelector/atmselectorwidget.cpp \
    Utility/utilities.cpp \
    form.cpp \
    form2.cpp \
    main.cpp

HEADERS += \
    ATM/Socket/appsocket.h \
    ATM/Socket/atmselectorsocket.h \
    ATM/Socket/atmsocket.h \
    ATM/atm.h \
    ATM/atmparams.h \
    ATMSelector/atmselector.h \
    ATMSelector/atmselectorwidget.h \
    Utility/utilities.h \
    form.h \
    form2.h \
    form2.h

FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


HEADERS += \
    ATM/Socket/appsocket.h \
    ATM/Socket/atmselectorsocket.h \
    ATM/Socket/atmsocket.h \
    ATM/atm.h \
    ATM/atmparams.h \
    ATMSelector/atmselector.h \
    ATMSelector/atmselectorwidget.h \
    Utility/utilities.h \
    form.h \
    form2.h

FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


HEADERS += \
    ATM/Socket/appsocket.h \
    ATM/Socket/atmselectorsocket.h \
    ATM/Socket/atmsocket.h \
    ATM/atm.h \
    ATM/atmparams.h \
    ATMSelector/atmselector.h \
    ATMSelector/atmselectorwidget.h \
    Utility/utilities.h \
    form.h \
    form2.h

FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


HEADERS += \
    ATM/Socket/appsocket.h \
    ATM/Socket/atmselectorsocket.h \
    ATM/Socket/atmsocket.h \
    ATM/atm.h \
    ATM/atmparams.h \
    ATMSelector/atmselector.h \
    ATMSelector/atmselectorwidget.h \
    Utility/utilities.h \
    form.h \
    form2.h

FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


SOURCES += \
    ATM/Socket/appsocket.cpp \
    ATM/Socket/atmselectorsocket.cpp \
    ATM/Socket/atmsocket.cpp \
    ATM/atm.cpp \
    ATM/atmparams.cpp \
    ATMSelector/atmselector.cpp \
    ATMSelector/atmselectorwidget.cpp \
    Utility/utilities.cpp \
    form.cpp \
    form2.cpp \
    main.cpp

HEADERS += \
    ATM/Socket/appsocket.h \
    ATM/Socket/atmselectorsocket.h \
    ATM/Socket/atmsocket.h \
    ATM/atm.h \
    ATM/atmparams.h \
    ATMSelector/atmselector.h \
    ATMSelector/atmselectorwidget.h \
    Utility/utilities.h \
    form.h \
    form2.h \
    form2.h

FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


HEADERS += \
    ATM/Socket/appsocket.h \
    ATM/Socket/atmselectorsocket.h \
    ATM/Socket/atmsocket.h \
    ATM/atm.h \
    ATM/atmparams.h \
    ATMSelector/atmselector.h \
    ATMSelector/atmselectorwidget.h \
    Utility/utilities.h \
    form.h \
    form2.h

FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


HEADERS += \
    ATM/Socket/appsocket.h \
    ATM/Socket/atmselectorsocket.h \
    ATM/Socket/atmsocket.h \
    ATM/atm.h \
    ATM/atmparams.h \
    ATMSelector/atmselector.h \
    ATMSelector/atmselectorwidget.h \
    Utility/utilities.h \
    form.h \
    form2.h

FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


SOURCES += \
    ATM/Socket/appsocket.cpp \
    ATM/Socket/atmselectorsocket.cpp \
    ATM/Socket/atmsocket.cpp \
    ATM/atm.cpp \
    ATM/atmparams.cpp \
    ATMSelector/atmselector.cpp \
    ATMSelector/atmselectorwidget.cpp \
    Utility/utilities.cpp \
    form.cpp \
    form2.cpp \
    main.cpp

HEADERS += \
    ATM/Socket/appsocket.h \
    ATM/Socket/atmselectorsocket.h \
    ATM/Socket/atmsocket.h \
    ATM/atm.h \
    ATM/atmparams.h \
    ATMSelector/atmselector.h \
    ATMSelector/atmselectorwidget.h \
    Utility/utilities.h \
    form.h \
    form2.h \
    form2.h

FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


HEADERS += \
    ATM/Socket/appsocket.h \
    ATM/Socket/atmselectorsocket.h \
    ATM/Socket/atmsocket.h \
    ATM/atm.h \
    ATM/atmparams.h \
    ATMSelector/atmselector.h \
    ATMSelector/atmselectorwidget.h \
    Utility/utilities.h \
    form.h \
    form2.h

FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


HEADERS += \
    ATM/Socket/appsocket.h \
    ATM/Socket/atmselectorsocket.h \
    ATM/Socket/atmsocket.h \
    ATM/atm.h \
    ATM/atmparams.h \
    ATMSelector/atmselector.h \
    ATMSelector/atmselectorwidget.h \
    Utility/utilities.h \
    form.h \
    form2.h

FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro


FORMS += \
    ATMSelector/atmselectorwidget.ui \
    form.ui \
    form2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    config.json \
    img/atm-250.png \
    img/bagel_90x95.png

SUBDIRS += \
    ../BooblikBank/BooblikBank.pro
