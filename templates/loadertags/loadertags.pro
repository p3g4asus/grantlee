QT += gui

TEMPLATE = lib
CONFIG += plugin static c++11 hide_symbols
DEFINES += QT_NO_CAST_TO_ASCII QT_NO_CAST_FROM_ASCII QT_STRICT_ITERATORS QT_NO_URL_CAST_FROM_STRING QT_NO_CAST_FROM_BYTEARRAY QT_NO_KEYWORDS QT_USE_QSTRINGBUILDER QT_DISABLE_DEPRECATED_BEFORE=0x050d00
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += ../lib
ios: INCLUDEPATH += ../lib/ios
SOURCES += \
    block.cpp \
    blockcontext.cpp \
    extends.cpp \
    include.cpp \
    loadertags.cpp
HEADERS += \
    block.h \
    blockcontext.h \
    extends.h \
    include.h \
    loadertags.h

target.path = $$OUT_PWD/..
!isEmpty(target.path): INSTALLS += target

QMAKE_POST_LINK=$(MAKE) install

