#ifndef LIBTINYDIGEST_EXPORT_H
#define LIBTINYDIGEST_EXPORT_H

#define _LIBTINYDIGEST_BUILD_WITH_EXECUTABLE

#ifdef _LIBTINYDIGEST_BUILD_WITH_EXECUTABLE
#define LIBTINYDIGEST_API
#else
#if defined(_WIN32) || defined(_WIN64)
#ifdef LIBTINYDIGEST_LIBRARY_BUILD
#define LIBTINYDIGEST_API __declspec(dllexport)
#else
#define LIBTINYDIGEST_API __declspec(dllimport)
#endif
#else
#ifdef LIBTINYDIGEST_LIBRARY_BUILD
#define LIBTINYDIGEST_API  __attribute__((visibility("default")))
#else
#define LIBTINYDIGEST_API
#endif
#endif
#endif

#endif // LIBTINYDIGEST_EXPORT_H