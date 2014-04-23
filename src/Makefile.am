lib_LTLIBRARIES = libzvm_zpipes.la

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libzvm_zpipes.pc

include_HEADERS = zvm_zpipes.h

libzvm_zpipes_la_SOURCES = zvm_zpipes.c

libzvm_zpipes_la_LDFLAGS = -version-info @LTVER@
libzvm_zpipes_la_LIBADD = @ZPIPES_LIBS@ @ZBROKER_LIBS@ @CZMQ_LIBS@


