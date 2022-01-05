QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    hangtk.cpp \
    hoadon.cpp \
    khachhang.cpp \
    main.cpp \
    login.cpp \
    menu.cpp \
    nhanvien.cpp \
    phieunhaphang.cpp

HEADERS += \
    hangtk.h \
    hoadon.h \
    khachhang.h \
    login.h \
    menu.h \
    nhanvien.h \
    phieunhaphang.h

FORMS += \
    hangtk.ui \
    hoadon.ui \
    khachhang.ui \
    login.ui \
    menu.ui \
    nhanvien.ui \
    phieunhaphang.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
