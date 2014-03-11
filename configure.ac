# Required initializer
AC_PREREQ(2.59)
AC_INIT(zvm-zpipes, 1.0.0)

AC_CONFIG_AUX_DIR(config)
AC_CONFIG_MACRO_DIR(config)

AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_SRCDIR([src/zvm_zpipes.c])
AC_CONFIG_HEADER([config.h])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AM_PROG_AS
AC_PROG_LIBTOOL
PKG_PROG_PKG_CONFIG

# Get initial flags
ORIG_CFLAGS="${CFLAGS:-}"
ORIG_CPPFLAGS="${CPPFLAGS:-}"
ORIG_CXXFLAGS="${CXXFLAGS:-}"

DEBUG_CFLAGS="-O2 -DNDEBUG"

# Library interface version
LTVER="0:0:0"

# Checks for libraries.
PKG_CHECK_MODULES([ZPIPES], libzpipesclient)
PKG_CHECK_MODULES([CZMQ], libczmq)

# Set CFLAGS
CFLAGS="${DEBUG_CFLAGS} ${ORIG_CFLAGS} ${ZPIPES_CFLAGS} ${CZMQ_FLAGS}"

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

AC_SUBST(PACKAGE_VERSION)
AC_SUBST(LTVER)
AC_SUBST(ZPIPES_LIBS)

# Checks for library functions.
AC_CHECK_FUNCS([strcasecmp strspn strstr])

# Write config.status and the Makefile
AC_OUTPUT([Makefile src/Makefile src/libzvm_zpipes.pc])
