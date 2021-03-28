#ifndef GRANTLEE_TEMPLATES_EXPORT_H
#define GRANTLEE_TEMPLATES_EXPORT_H
#include <QtGlobal>

#if defined(GRANTLEE_TEMPLATES_STATIC_DEFINE) || defined(Q_OS_IOS)
#  define GRANTLEE_TEMPLATES_EXPORT
#  define GRANTLEE_TEMPLATES_NO_EXPORT
#elif defined(Q_OS_WIN)
#  ifndef GRANTLEE_TEMPLATES_EXPORT
#    ifdef Grantlee_Templates_EXPORTS
        /* We are building this library */
#      define GRANTLEE_TEMPLATES_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define GRANTLEE_TEMPLATES_EXPORT __declspec(dllimport)
#    endif
#  endif
#  ifndef GRANTLEE_TEMPLATES_NO_EXPORT
#    define GRANTLEE_TEMPLATES_NO_EXPORT
#  endif
#elif defined(Q_OS_ANDROID)
#  ifndef GRANTLEE_TEMPLATES_EXPORT
#    ifdef Grantlee_Templates_EXPORTS
        /* We are building this library */
#      define GRANTLEE_TEMPLATES_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define GRANTLEE_TEMPLATES_EXPORT __attribute__((visibility("default")))
#    endif
#  endif
#  ifndef GRANTLEE_TEMPLATES_NO_EXPORT
#    define GRANTLEE_TEMPLATES_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef GRANTLEE_TEMPLATES_DEPRECATED
#ifdef Q_OS_WIN
#  define GRANTLEE_TEMPLATES_DEPRECATED __declspec(deprecated)
#elif defined(Q_OS_ANDROID)
#  define GRANTLEE_TEMPLATES_DEPRECATED __attribute__ ((__deprecated__))
#endif
#endif

#ifndef GRANTLEE_TEMPLATES_DEPRECATED_EXPORT
#  define GRANTLEE_TEMPLATES_DEPRECATED_EXPORT GRANTLEE_TEMPLATES_EXPORT GRANTLEE_TEMPLATES_DEPRECATED
#endif

#ifndef GRANTLEE_TEMPLATES_DEPRECATED_NO_EXPORT
#  define GRANTLEE_TEMPLATES_DEPRECATED_NO_EXPORT GRANTLEE_TEMPLATES_NO_EXPORT GRANTLEE_TEMPLATES_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef GRANTLEE_TEMPLATES_NO_DEPRECATED
#    define GRANTLEE_TEMPLATES_NO_DEPRECATED
#  endif
#endif

#endif /* GRANTLEE_TEMPLATES_EXPORT_H */
