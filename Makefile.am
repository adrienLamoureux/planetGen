## Process this file with automake to produce Makefile.in
SUBDIRS = . src test samples doc

ACLOCAL_AMFLAGS = -I autotools-files/m4
CLEANFILES =

.PHONY: doc

doc:
	cd doc && $(MAKE) $(AM_MAKEFLAGS) $@

maintainer-clean-local:
	rm -fr $(top_srcdir)/Makefile.in \
	       $(top_srcdir)/aclocal.m4  \
	       $(top_srcdir)/autotools-files/

EXTRA_DIST =      \
        AUTHORS   \
        COPYING   \
        ChangeLog \
        NEWS      \
        README
