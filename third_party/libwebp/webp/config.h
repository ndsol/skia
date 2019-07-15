#ifdef __builtin_bswap16
#define HAVE_BUILTIN_BSWAP16 1
#endif

#ifdef __builtin_bswap32
#define HAVE_BUILTIN_BSWAP32 1
#endif

#ifdef __builtin_bswap64
#define HAVE_BUILTIN_BSWAP64 1
#endif

#ifdef __ANDROID__
#define HAVE_CPU_FEATURES_H 1
#endif

#define HAVE_INTTYPES_H 1
#define HAVE_MEMORY_H 1

#ifdef _WIN32

#define HAVE_SHLWAPI_H 1
#define HAVE_WINCODEC_H 1
#define HAVE_WINDOWS_H 1

#else

#define HAVE_DLFCN_H 1

#endif

#define HAVE_STDINT_H 1

#define HAVE_STDLIB_H 1

#define HAVE_STRINGS_H 1

#define HAVE_STRING_H 1

#define HAVE_SYS_STAT_H 1

#define HAVE_SYS_TYPES_H 1

#define HAVE_UNISTD_H 1

#define LT_OBJDIR "@LT_OBJDIR@"

#define PACKAGE "webp"

#define PACKAGE_BUGREPORT ""

#define PACKAGE_NAME "webp"

#define PACKAGE_STRING "webp-1.0.3"

#define PACKAGE_TARNAME "webp"

#define PACKAGE_URL "https://github.com/webmproject/libwebp"

#define PACKAGE_VERSION "1.0.3"

#if 0
// If your platform uses the other PTHREAD_CREATE_JOINABLE name:
#define PTHREAD_CREATE_JOINABLE PTHREAD_CREATE_UNDETACHED
#endif

//#define HAVE_PTHREAD_PRIO_INHERIT 1

#define STDC_HEADERS 1

#define VERSION PACKAGE_VERSION

//#define HAVE_GLUT_GLUT_H 1
//#define HAVE_GL_GLUT_H 1
//#define HAVE_OPENGL_GLUT_H 1
//#define WEBP_HAVE_GL 1
//#define WEBP_HAVE_SDL 1

#ifdef __ARM_NEON
#define WEBP_HAVE_NEON 1
#define WEBP_USE_NEON 1
//#define WEBP_HAVE_NEON_RTCD
#endif

#if defined(_M_AMD64) || defined(_M_X64) || defined(__SSE2__) \
    || defined(__AVX__) || (defined(_M_IX86_FP) && _M_IX86_FP == 2)
#define WEBP_HAVE_SSE2 1
#define WEBP_USE_SSE2 1
#endif
#if defined(__SSE4_1__)
#define WEBP_HAVE_SSE41 1
#define WEBP_USE_SSE41 1
#endif

#define WEBP_NEAR_LOSSLESS 1

#define WEBP_USE_THREAD 1

#ifdef __BIG_ENDIAN__
#define WORDS_BIGENDIAN 1
#endif
