QT       += core gui
QT       += core
QT       += serialport
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    historial.cpp \
    main.cpp \
    mainwindow.cpp \
    mediciones.cpp \
    pacientes.cpp \
    ventanaconexion.cpp

HEADERS += \
    historial.h \
    mainwindow.h \
    mediciones.h \
    pacientes.h \
    ui_historial.h \
    ui_mediciones.h \
    ui_pacientes.h \
    ui_ventanaconexion.h \
    ventanaconexion.h

FORMS += \
    historial.ui \
    mainwindow.ui \
    mediciones.ui \
    pacientes.ui \
    ventanaconexion.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
