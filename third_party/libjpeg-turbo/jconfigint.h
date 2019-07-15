/* libjpeg-turbo build number */
#define BUILD  "Build string (default: 20191201)"

/* Compiler's inline keyword */
#undef inline

/* How to obtain function inlining. */
#ifdef _MSC_VER

#define INLINE __forceinline
#define SIZEOF_SIZE_T 8
//#define HAVE_BUILTIN_CTZL

#else

#define INLINE __inline__ __attribute__((always_inline))
/* The size of `size_t', as computed by sizeof. */
#define SIZEOF_SIZE_T 8
/* Define if your compiler has __builtin_ctzl() and sizeof(unsigned long) == sizeof(size_t). */
#define HAVE_BUILTIN_CTZL

#endif

/* Define to the full name of this package. */
#define PACKAGE_NAME  "libjpeg-turbo"

/* Version number of package */
#define VERSION  "2.0.3"

#ifdef _MSC_VER
/* Define to 1 if you have the <intrin.h> header file. */
#define HAVE_INTRIN_H

#if (SIZEOF_SIZE_T == 8)
#define HAVE_BITSCANFORWARD64
#elif (SIZEOF_SIZE_T == 4)
#define HAVE_BITSCANFORWARD
#endif
#endif
