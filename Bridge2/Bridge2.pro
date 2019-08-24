TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        logger.cpp \
        loggerimpl.cpp \
        main.cpp

HEADERS += \
    logger.h \
    loggerimpl.h
