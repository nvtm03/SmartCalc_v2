QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller/controller.cpp \
    main.cpp \
    view/mainwindow.cpp \
    model/model.cpp \
    plot/plot.cpp \
    qcustomplot.cpp

HEADERS += \
    controller/controller.h \
    view/mainwindow.h \
    model/model.h \
    qcustomplot.h \
    plot/plot.h

FORMS += \
    view/mainwindow.ui \
    plot/plot.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target





