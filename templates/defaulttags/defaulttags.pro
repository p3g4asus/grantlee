QT -= gui

TEMPLATE = lib
CONFIG += plugin c++11 hide_symbols
ios:CONFIG += static
DEFINES += QT_NO_CAST_TO_ASCII QT_NO_CAST_FROM_ASCII QT_STRICT_ITERATORS QT_NO_URL_CAST_FROM_STRING QT_NO_CAST_FROM_BYTEARRAY QT_NO_KEYWORDS QT_USE_QSTRINGBUILDER QT_DISABLE_DEPRECATED_BEFORE=0x050d00
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += ../lib ../lib/autogen
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

ios:OS_NAME = ios
android:OS_NAME = android
windows:OS_NAME = windows
outtrg.path = $$OUT_PWD/../install/lib/$${OS_NAME}
android: outtrg.files = $$OUT_PWD/libdefaulttags_arm64-v8a.so $$OUT_PWD/libdefaulttags_armeabi-v7a.so
ios: outtrg.files = $$OUT_PWD/libdefaulttags.a
outtrg.CONFIG = no_check_exist
target.CONFIG = no_check_exist no_default_install no_build
target.path = $$OUT_PWD/../install/lib
message($$OUT_PWD/../install/lib/$${OS_NAME})
INSTALLS = outtrg
ANDROID_ABIS = armeabi-v7a arm64-v8a
LIBS += -lGrantlee_Templates_$${ANDROID_TARGET_ARCH} -L $$OUT_PWD/../install/lib/$${OS_NAME}
QMAKE_POST_LINK=$(MAKE) install
