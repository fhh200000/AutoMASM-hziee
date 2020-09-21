QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
msvc {
    QMAKE_CFLAGS += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    initwindow.cpp \
    iniutil.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    initwindow.h \
    iniutil.h \
    mainwindow.h \
    vardefs.h

FORMS += \
    initwindow.ui \
    mainwindow.ui

TRANSLATIONS += \
    AutoMASM_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
