#ifndef B3API_H
#define B3API_H

#ifdef _MSC_VER
#  define BULLET_SHARED_EXPORT __declspec(dllexport)
#  define BULLET_SHARED_IMPORT __declspec(dllimport)
#  define BULLET_STATIC_EXPORT
#  define BULLET_STATIC_IMPORT
#else
#  define BULLET_SHARED_EXPORT
#  define BULLET_SHARED_IMPORT
#  define BULLET_STATIC_EXPORT
#  define BULLET_STATIC_IMPORT
#endif

#ifdef BULLET_SHARED
#  define BULLET_EXPORT BULLET_SHARED_EXPORT
#  define BULLET_IMPORT BULLET_SHARED_IMPORT
#else
#  define BULLET_EXPORT BULLET_STATIC_EXPORT
#  define BULLET_IMPORT BULLET_STATIC_IMPORT
#endif

#endif // B3API_H
