#ifndef EXPORT_H
#define EXPORT_H

#ifdef LIBTINYDIGEST_LIBRARY_BUILD
#define EXPORT_LIBRARY_BUILD
#endif

#ifdef _BUILD_WITH_EXECUTABLE
#define EXPORT_API
#else
#if defined(_WIN32) || defined(_WIN64)
#ifdef EXPORT_LIBRARY_BUILD
#define EXPORT_API __declspec(dllexport)
#else
#define EXPORT_API __declspec(dllimport)
#endif
#else
#ifdef EXPORT_LIBRARY_BUILD
#define EXPORT_API __attribute__((visibility("default")))
#else
#define EXPORT_API
#endif
#endif
#endif

#define LIBTINYDIGEST_API EXPORT_API

#endif // EXPORT_H
