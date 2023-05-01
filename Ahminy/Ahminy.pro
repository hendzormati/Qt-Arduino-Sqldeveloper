QT       += core gui
QT += sql
QT += widgets
QT += charts
QT += serialport
QT += printsupport

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
include( $$PWD/../SMTPClient/SMTPClient.pri )
SOURCES += \
    alerteincondie.cpp \
    arduino.cpp \
    connection.cpp \
    dialogp.cpp \
    dialogs.cpp \
    don.cpp \
    excel.cpp \
    historique.cpp \
    incondiesdf.cpp \
    mailingp.cpp \
    main.cpp \
    mainwindow.cpp \
    modifmdp.cpp \
    personnel.cpp \
    qrcode.cpp \
    rfidpers.cpp \
    sdf.cpp \
    stock.cpp \
    stock_stat.cpp \
    vente.cpp

HEADERS += \
    Stock_stat.h \
    alerteincondie.h \
    arduino.h \
    connection.h \
    dialogp.h \
    dialogs.h \
    don.h \
    excel.h \
    historique.h \
    incondiesdf.h \
    mailingp.h \
    mainwindow.h \
    modifmdp.h \
    personnel.h \
    qrcode.h \
    rfidpers.h \
    sdf.h \
    stock.h \
    vente.h

FORMS += \
    alerteincondie.ui \
    dialogp.ui \
    dialogs.ui \
    historique.ui \
    mailingp.ui \
    mainwindow.ui \
    modifmdp.ui \
    vente.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

