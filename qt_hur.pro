QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    qt_button_col.cpp \
    qt_button_slip.cpp \
    qt_button_text.cpp \
    qt_frameless.cpp \
    qt_move.cpp \
    wid_butt.cpp \
    wid_butt_col.cpp \
    wid_home.cpp \
    wid_m1.cpp \
    wid_m2.cpp \
    wid_m2_1.cpp \
    wid_m2_2.cpp \
    wid_m2_3.cpp \
    wid_m2_4.cpp \
    wid_m3.cpp \
    wid_m4.cpp \
    wid_main.cpp \
    wid_menu_dig.cpp \
    wid_move.cpp \
    widget.cpp

HEADERS += \
    c_define.h \
    qt_button_col.h \
    qt_button_slip.h \
    qt_button_text.h \
    qt_frameless.h \
    qt_move.h \
    wid_butt.h \
    wid_butt_col.h \
    wid_home.h \
    wid_m1.h \
    wid_m2.h \
    wid_m2_1.h \
    wid_m2_2.h \
    wid_m2_3.h \
    wid_m2_4.h \
    wid_m3.h \
    wid_m4.h \
    wid_main.h \
    wid_menu_dig.h \
    wid_move.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    map.qrc
