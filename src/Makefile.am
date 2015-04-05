## Process this file with automake to produce Makefile.in
AUTOMAKE_OPTIONS = subdir-objects

AM_CPPFLAGS =
AM_LDFLAGS =

CLEANFILES=
BUILT_SOURCES=

lib_LTLIBRARIES = libterrain.la

libterrain_la_SOURCES =  \
	bitmapexporter.cc \
	blender3dio.cc \
	erosiongenerator.cc \
	heightmapimpl.cc \
	hydraulicerosion.cc \
	noisebase.cc \
	pixmapexporter.cc \
	planediamondsquare.cc \
	planegenerator.cc \
	planeheightmap.cc \
	planemidpointdisplacement.cc \
	planenoisegenerator.cc \
	planesquaregenerator.cc \
	planesquareheightmap.cc \
	planesquarenoisegenerator.cc \
	simplexnoise.cc \
	terragenexporter.cc \
	thermalerosion.cc

include_HEADERS = \
	bitmapexporter.hh \
	blender3dio.hh \
	erosiongenerator.hh \
	generator.hh \
	heightmap.hh \
	heightmapexporter.hh \
	hydraulicerosion.hh \
	pixmapexporter.hh \
	planediamondsquare.hh \
	planegenerator.hh \
	planeheightmap.hh \
	planemidpointdisplacement.hh \
	planenoisegenerator.hh \
	planesquaregenerator.hh \
	planesquareheightmap.hh \
	planesquarenoisegenerator.hh \
	simplexnoise.hh \
	terragenexporter.hh \
	thermalerosion.hh

libterrain_la_CPPFLAGS =
libterrain_la_CXXFLAGS =
libterrain_la_LDFLAGS  =

CLEANFILES += *~

DISTCLEANFILES = ${BUILT_SOURCES}

MAINTAINERCLEANFILES = \
	compile.log

maintainer-clean-local:
	rm -fr $(top_srcdir)/src/Makefile.in \
	       $(top_srcdir)/src/config.h.in
