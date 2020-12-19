TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        menu.cpp \
        rwfunc.cpp

HEADERS += \
    menu.hpp \
    rwfunc.hpp

DISTFILES += \
    Vrental.db
