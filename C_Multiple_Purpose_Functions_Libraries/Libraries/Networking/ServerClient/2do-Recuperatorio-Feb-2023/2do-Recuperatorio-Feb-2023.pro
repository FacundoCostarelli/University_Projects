TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Cliente.c \
        Funciones-Server-Cliente.c \
        Servidor.c \
        sock-lib.c

HEADERS += \
    Funciones-Server-Cliente.h \
    sock-lib.h
