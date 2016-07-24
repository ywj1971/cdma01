#-------------------------------------------------
#
# Project created by QtCreator 2016-06-30T17:43:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS += -LC:\mysql-win32\lib -llibmysql

#LIBS += -lmysqlclient

TARGET = cdma
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindlg.cpp \
    scriptdlg.cpp \
    mymysql.cpp \
    insert_dlg.cpp \
    selectdlg.cpp

HEADERS  += mainwindow.h \
    logindlg.h \
    scriptdlg.h \
    mymysql.h \
    insert_dlg.h \
    selectdlg.h

FORMS    += mainwindow.ui \
    logindlg.ui \
    scriptdlg.ui \
    insert_dlg.ui \
    selectdlg.ui

OTHER_FILES +=

RESOURCES += \
    img.qrc
