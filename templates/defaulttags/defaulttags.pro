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
    autoescape.cpp \
    comment.cpp \
    cycle.cpp \
    debug.cpp \
    defaulttags.cpp \
    filtertag.cpp \
    firstof.cpp \
    for.cpp \
    if.cpp \
    ifchanged.cpp \
    ifequal.cpp \
    load.cpp \
    mediafinder.cpp \
    now.cpp \
    range.cpp \
    regroup.cpp \
    spaceless.cpp \
    templatetag.cpp \
    widthratio.cpp \
    with.cpp
HEADERS += \
    autoescape.h \
    comment.h \
    cycle.h \
    debug.h \
    defaulttags.h \
    filtertag.h \
    firstof.h \
    for.h \
    if.h \
    if_p.h \
    ifchanged.h \
    ifequal.h \
    load.h \
    mediafinder.h \
    now.h \
    range.h \
    regroup.h \
    spaceless.h \
    templatetag.h \
    widthratio.h \
    with.h

target.path = $$OUT_PWD/..
!isEmpty(target.path): INSTALLS += target

QMAKE_POST_LINK=$(MAKE) install
