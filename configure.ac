dnl ********************************************************************
dnl Process this file with autoconf to produce a configure script.
dnl ********************************************************************
AC_INIT([libterrain],[0.1])
AC_CONFIG_AUX_DIR([autotools-files])
AC_CONFIG_MACRO_DIR([autotools-files/m4])
AC_CONFIG_HEADERS([src/config.h])

AM_PROG_AR
AM_INIT_AUTOMAKE([-Wall -Werror])
AM_MAINTAINER_MODE

AC_LANG([C++])


dnl ********************************************************************
dnl Checking for standard programs, headers and libraries
dnl ********************************************************************
AC_PROG_CXX
AC_PROG_CC
AM_PROG_CC_C_O
AM_PROG_LIBTOOL
AM_PATH_CPPUNIT



dnl ********************************************************************
dnl Option and variable settings
dnl ********************************************************************

dnl Initial settings of flags variables
CFLAGS="${CFLAGS} -g -Wall -Wextra -D_FORTIFY_SOURCE=2"
CXXFLAGS="${CXXFLAGS} -g -Wall -Wextra -D_FORTIFY_SOURCE=2"
CPPFLAGS="${CPPFLAGS}"
LDFLAGS="${LDFLAGS}"

dnl Full verification activated (handle with care!)
dnl EXTRA_FLAGS= \
dnl         "-pedantic -Weffc++ -Wstrict-overflow -Woverloaded-virtual" \
dnl         "-Wsign-promo -Wabi -Wmissing-declarations -Wconversion"    \
dnl	    "-Wuninitialized -Wcast-align -Wredundant-decls"

dnl Parsing and setting options on compile flags
AC_ARG_ENABLE(werror,
              AS_HELP_STRING([--enable-werror],
			     [compile with -Werror flag (default is no)]),
              ENABLE_WERROR=$enableval,
              ENABLE_WERROR=no)


dnl ********************************************************************
dnl Checking for specific programs, headers and libraries
dnl ********************************************************************

dnl Checking for libnoise
AC_CHECK_HEADERS([noise/noise.h],
                 [],
                 [AC_MSG_ERROR([libnoise header 'noise.h' cannot be found])])

LDFLAGS="${LDFLAGS} -lnoise"

dnl Checking for cppUnit
AC_CHECK_HEADERS([cppunit/TestFixture.h],
                 [],
                 [AC_MSG_ERROR([cppunit cannot be found])])

dnl Checking for Doxygen
AC_CHECK_PROG(HAVE_DOXYGEN, doxygen, true, false)
if test "x$HAVE_DOXYGEN" = "xfalse"; then
   AC_MSG_WARN([API documentation cannot be generated because
   		    Doxygen is not found])
fi

dnl ********************************************************************
dnl Writing files
dnl ********************************************************************
AC_CONFIG_FILES([
	Makefile
	src/Makefile
	test/Makefile
	samples/Makefile
	doc/Makefile
], [ ], [ ])

AC_OUTPUT


dnl ********************************************************************
dnl Display a summary of the configure to the user
dnl ********************************************************************
AC_MSG_NOTICE([
=================================================================
		    Libterrain ${VERSION}
=================================================================
Here is the configuration of the package:
    Installation prefix	     	: ${prefix}
    Source code location	: ${srcdir}

    C Compiler			: ${CC}
    C++ Compiler		: ${CXX}
    CFLAGS			: ${CFLAGS}
    CXXFLAGS			: ${CXXFLAGS}
    CPPFLAGS			: ${CPPFLAGS}
    LDFLAGS			: ${LDFLAGS}

Optional Features:
    Enable werror mode		: ${ENABLE_WERROR}
])
