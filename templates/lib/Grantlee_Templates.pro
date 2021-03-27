QT -= gui

TEMPLATE = lib
CONFIG += staticlib c++11 hide_symbols


INCLUDEPATH += ../scriptabletags

DEFINES += QT_NO_CAST_TO_ASCII QT_NO_CAST_FROM_ASCII QT_STRICT_ITERATORS QT_NO_URL_CAST_FROM_STRING QT_NO_CAST_FROM_BYTEARRAY QT_NO_KEYWORDS QT_USE_QSTRINGBUILDER QT_DISABLE_DEPRECATED_BEFORE=0x050d00 QT_QML_LIB

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../scriptabletags/scriptablecontext.cpp \
    ../scriptabletags/scriptablefilter.cpp \
    ../scriptabletags/scriptablefilterexpression.cpp \
    ../scriptabletags/scriptablenode.cpp \
    ../scriptabletags/scriptableparser.cpp \
    ../scriptabletags/scriptablesafestring.cpp \
    ../scriptabletags/scriptabletags.cpp \
    ../scriptabletags/scriptabletemplate.cpp \
    ../scriptabletags/scriptablevariable.cpp \
    abstractlocalizer.cpp \
    cachingloaderdecorator.cpp \
    context.cpp \
    customtyperegistry.cpp \
    engine.cpp \
    filter.cpp \
    filterexpression.cpp \
    lexer.cpp \
    metatype.cpp \
    node.cpp \
    nodebuiltins.cpp \
    nulllocalizer.cpp \
    outputstream.cpp \
    parser.cpp \
    qtlocalizer.cpp \
    rendercontext.cpp \
    safestring.cpp \
    template.cpp \
    templateloader.cpp \
    textprocessingmachine.cpp \
    typeaccessors.cpp \
    util.cpp \
    variable.cpp

HEADERS += \
    ../scriptabletags/scriptablecontext.h \
    ../scriptabletags/scriptablefilter.h \
    ../scriptabletags/scriptablefilterexpression.h \
    ../scriptabletags/scriptablenode.h \
    ../scriptabletags/scriptableparser.h \
    ../scriptabletags/scriptablesafestring.h \
    ../scriptabletags/scriptabletags.h \
    ../scriptabletags/scriptabletemplate.h \
    ../scriptabletags/scriptablevariable.h \
    abstractlocalizer.h \
    cachingloaderdecorator.h \
    context.h \
    customtyperegistry_p.h \
    engine.h \
    engine_p.h \
    exception.h \
    filter.h \
    filterexpression.h \
    grantlee_tags_p.h \
    grantlee_templates.h \
    lexer_p.h \
    metaenumvariable_p.h \
    metatype.h \
    node.h \
    nodebuiltins_p.h \
    nulllocalizer_p.h \
    outputstream.h \
    parser.h \
    pluginpointer_p.h \
    qtlocalizer.h \
    rendercontext.h \
    safestring.h \
    statemachine_p.h \
    taglibraryinterface.h \
    template.h \
    template_p.h \
    templateloader.h \
    textprocessingmachine_p.h \
    token.h \
    typeaccessor.h \
    util.h \
    variable.h

ios: HEADERS += ios/grantlee_config_p.h \
    ios/grantlee_templates_export.h \
    ios/grantlee_test_export.h \
    ios/grantlee_version.h
ios: INCLUDEPATH += ios
target.path = $$OUT_PWD/..
hfiles.files = abstractlocalizer.h \
    cachingloaderdecorator.h \
    context.h \
    engine.h \
    exception.h \
    filter.h \
    filterexpression.h \
    metatype.h \
    node.h \
    outputstream.h \
    parser.h \
    qtlocalizer.h \
    rendercontext.h \
    safestring.h \
    taglibraryinterface.h \
    template.h \
    templateloader.h \
    typeaccessor.h \
    token.h \
    util.h \
    variable.h
hfiles.path = $$OUT_PWD/../../qdomyos-zwift/3rdParty/include/grantlee
!isEmpty(target.path): INSTALLS += target hfiles

QMAKE_POST_LINK=$(MAKE) install
