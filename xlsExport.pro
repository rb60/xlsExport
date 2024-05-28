QT -= gui

TEMPLATE = lib
DEFINES += XLSEXPORT_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QXLSX_PARENTPATH=./
QXLSX_HEADERPATH=./header/
QXLSX_SOURCEPATH=./source/
include(./QXlsx.pri)

SOURCES += \
    xlsexport.cpp

HEADERS += \
    TransferData.h \
    exportTypes.h \
    xlsexport.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
