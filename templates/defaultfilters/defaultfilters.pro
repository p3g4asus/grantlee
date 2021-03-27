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
    datetime.cpp \
    defaultfilters.cpp \
    integers.cpp \
    lists.cpp \
    logic.cpp \
    misc.cpp \
    stringfilters.cpp

HEADERS += \
    datetime.h \
    defaultfilters.h \
    integers.h \
    lists.h \
    logic.h \
    misc.h \
    stringfilters.h


target.path = $$OUT_PWD/..
hfiles.path = $$OUT_PWD/../../qdomyos-zwift/3rdParty/include/grantlee/defaultfilters
hfiles.files = \
    datetime.h \
    defaultfilters.h \
    integers.h \
    lists.h \
    logic.h \
    misc.h \
    stringfilters.h

!isEmpty(target.path): INSTALLS += target hfiles
QMAKE_POST_LINK=$(MAKE) install
