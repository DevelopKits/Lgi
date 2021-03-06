#!/usr/bin/make
#
# This makefile generated by LgiIde
# http://www.memecode.com/lgi.php
#

.SILENT :

CC = g++
Target = lgikde3
ifndef Build
	Build = Release
endif
Gui = X
BuildDir = $(Build)$(Gui)

Flags = -fPIC -w -fno-inline
Defs= -DLINUX -D_REENTRANT -D$(Gui)WIN

ifeq ($(Build),Debug)
	Defs += -D_DEBUG
	Flags += -g
	Tag = d
else
	Flags += -s -Os
endif

# Libraries
Libs = \
			-static-libgcc \
			-lpthread \
			-lstdc++ \
			-L/opt/kde3/lib \
			-L/usr/lib/qt3/lib \
			-lkdecore \
			-lkdeui \
			-lkio \
			-lqt-mt

# Includes
Inc =		-I/usr/include/X11\
			-I/usr/include/X11/Xft\
			-I/usr/include/X11/extensions\
			-I/usr/include/freetype2 \
			-I../../../include/common \
			-I../../../include/linux/X \
			-I/opt/kde3/include \
			-I/usr/include/kde \
			-I/usr/include/qt3 \
			-I/usr/lib/qt3/include

# Dependencies
Depends =	LgiKde.o

# Target
TargetFile = lib$(Target)$(Tag).so
$(TargetFile) : outputfolder $(Depends)
	@echo Linking $(TargetFile) [$(Gui)/$(Build)]...
	$(CC) -shared \
		-Wl,-soname,$(TargetFile),-export-dynamic,-R. \
		-o $(BuildDir)/$(TargetFile) \
		$(addprefix $(BuildDir)/,$(Depends)) \
		$(Libs)
	@echo Done.

# Create the output folder
outputfolder :
	-mkdir -p $(BuildDir) 2> /dev/null

# Clean out targets
clean :
	rm -f $(BuildDir)/*.o $(BuildDir)/$(TargetFile)
	@echo Cleaned $(BuildDir)

LgiKde.o : ./LgiKde.cpp /usr/include/qt3/qstring.h \
	/usr/include/kde/kapplication.h \
	/usr/include/kde/kservice.h \
	/usr/include/kde/kuserprofile.h \
	/usr/include/kde/kglobalsettings.h \
	/usr/include/kde/kglobal.h \
	/usr/include/kde/klocale.h \
	../../../include/linux/X/LgiWinManGlue.h
	@echo $(<F) [$(Gui)]
	$(CC) $(Inc) $(Flags) $(Defs) -c $< -o $(BuildDir)/$(@F)

klocale.h : /usr/include/qt3/qstring.h \
	/usr/include/kde/kdelibs_export.h

LgiWinManGlue.h : ../../../include/common/LgiDefs.h \
	../../../include/common/GMem.h \
	../../../include/common/GArray.h \
	../../../include/common/LgiClass.h

kglobalsettings.h : /usr/include/qt3/qstring.h \
	/usr/include/qt3/qcolor.h \
	/usr/include/qt3/qfont.h \
	/usr/include/kde/kdelibs_export.h

qcolor.h : /usr/include/qt3/qwindowdefs.h \
	/usr/include/qt3/qstringlist.h

qfont.h : /usr/include/qt3/qwindowdefs.h \
	/usr/include/qt3/qstring.h

qwindowdefs.h : /usr/include/qt3/qobjectdefs.h \
	/usr/include/qt3/qstring.h \
	/usr/include/qt3/qnamespace.h

qobjectdefs.h : /usr/include/qt3/qglobal.h

qglobal.h : /usr/include/qt3/qconfig.h \
	/usr/include/qt3/qmodules.h \
	/usr/include/qt3/qfeatures.h

kapplication.h : /usr/include/kde/kdeversion.h \
	/usr/include/kde/kdelibs_export.h \
	/usr/include/qt3/qapplication.h \
	/usr/include/qt3/qpixmap.h \
	/usr/include/kde/kinstance.h

qapplication.h : /usr/include/qt3/qdesktopwidget.h \
	/usr/include/qt3/qasciidict.h \
	/usr/include/qt3/qpalette.h \
	/usr/include/qt3/qtranslator.h \
	/usr/include/qt3/qstrlist.h \
	/usr/include/qt3/qstringlist.h

kinstance.h : /usr/include/qt3/qstring.h \
	/usr/include/kde/kdelibs_export.h

qdesktopwidget.h : /usr/include/qt3/qwidget.h

qstrlist.h : /usr/include/qt3/qstring.h \
	/usr/include/qt3/qptrlist.h \
	/usr/include/qt3/qdatastream.h

qdatastream.h : /usr/include/qt3/qiodevice.h \
	/usr/include/qt3/qstring.h

qtranslator.h : /usr/include/qt3/qobject.h \
	/usr/include/qt3/qvaluelist.h

qvaluelist.h : /usr/include/qt3/qtl.h \
	/usr/include/qt3/qshared.h \
	/usr/include/qt3/qdatastream.h \
	/usr/include/qt3/qwinexport.h

qtl.h : /usr/include/qt3/qglobal.h \
	/usr/include/qt3/qtextstream.h \
	/usr/include/qt3/qstring.h

qshared.h : /usr/include/qt3/qglobal.h

qtextstream.h : /usr/include/qt3/qiodevice.h \
	/usr/include/qt3/qstring.h

qnamespace.h : /usr/include/qt3/qglobal.h

qwidget.h : /usr/include/qt3/qwindowdefs.h \
	/usr/include/qt3/qobject.h \
	/usr/include/qt3/qpaintdevice.h \
	/usr/include/qt3/qpalette.h \
	/usr/include/qt3/qfont.h \
	/usr/include/qt3/qfontmetrics.h \
	/usr/include/qt3/qfontinfo.h \
	/usr/include/qt3/qsizepolicy.h \
	/usr/include/qt3/qwinexport.h

qsizepolicy.h : /usr/include/qt3/qglobal.h

qasciidict.h : /usr/include/qt3/qgdict.h \
	/usr/include/qt3/qwinexport.h

qfontmetrics.h : /usr/include/qt3/qfont.h \
	/usr/include/qt3/qrect.h

qrect.h : /usr/include/qt3/qsize.h \
	/usr/include/qt3/qwinexport.h

qgdict.h : /usr/include/qt3/qptrcollection.h \
	/usr/include/qt3/qstring.h

qptrcollection.h : /usr/include/qt3/qglobal.h

qobject.h : /usr/include/qt3/qobjectdefs.h \
	/usr/include/qt3/qwindowdefs.h \
	/usr/include/qt3/qstring.h \
	/usr/include/qt3/qevent.h \
	/usr/include/qt3/qnamespace.h \
	/usr/include/qt3/qwinexport.h

qevent.h : /usr/include/qt3/qwindowdefs.h \
	/usr/include/qt3/qregion.h \
	/usr/include/qt3/qnamespace.h \
	/usr/include/qt3/qmime.h \
	/usr/include/qt3/qpair.h

qpair.h : /usr/include/qt3/qglobal.h \
	/usr/include/qt3/qdatastream.h

qmime.h : /usr/include/qt3/qwindowdefs.h \
	/usr/include/qt3/qmap.h \
	/usr/include/qt3/qptrlist.h

qmap.h : /usr/include/qt3/qglobal.h \
	/usr/include/qt3/qshared.h \
	/usr/include/qt3/qdatastream.h \
	/usr/include/qt3/qpair.h \
	/usr/include/qt3/qvaluelist.h \
	/usr/include/qt3/qwinexport.h

kglobal.h : /usr/include/kde/kdelibs_export.h \
	/usr/include/kde/kinstance.h

GMem.h : ../../../include/common/LgiDefs.h \
	../../../include/common/LgiInc.h

GArray.h : ../../../include/common/LgiDefs.h

kdeversion.h : /usr/include/kde/kdelibs_export.h

qiodevice.h : /usr/include/qt3/qglobal.h \
	/usr/include/qt3/qcstring.h

qcstring.h : /usr/include/qt3/qmemarray.h \
	/usr/include/qt3/qwinexport.h

qmemarray.h : /usr/include/qt3/qgarray.h \
	/usr/include/qt3/qwinexport.h

qstring.h : /usr/include/qt3/qcstring.h \
	/usr/include/qt3/qwinexport.h

qgarray.h : /usr/include/qt3/qshared.h

kservice.h : /usr/include/qt3/qstringlist.h \
	/usr/include/qt3/qmap.h \
	/usr/include/qt3/qvariant.h \
	/usr/include/kde/kicontheme.h \
	/usr/include/kde/ksycocaentry.h

ksycocaentry.h : /usr/include/kde/ksycocatype.h \
	/usr/include/qt3/qstringlist.h \
	/usr/include/kde/ksharedptr.h

ksharedptr.h : /usr/include/kde/kdelibs_export.h

kicontheme.h : /usr/include/qt3/qstring.h \
	/usr/include/qt3/qstringlist.h \
	/usr/include/qt3/qptrlist.h \
	/usr/include/kde/kdelibs_export.h

qvariant.h : /usr/include/qt3/qstring.h \
	/usr/include/qt3/qvaluelist.h \
	/usr/include/qt3/qstringlist.h \
	/usr/include/qt3/qmap.h

kuserprofile.h : /usr/include/qt3/qmap.h \
	/usr/include/qt3/qstring.h \
	/usr/include/qt3/qptrlist.h \
	/usr/include/qt3/qvaluelist.h \
	/usr/include/kde/kservice.h

qptrlist.h : /usr/include/qt3/qglist.h \
	/usr/include/qt3/qwinexport.h

qglist.h : /usr/include/qt3/qptrcollection.h

qstringlist.h : /usr/include/qt3/qvaluelist.h \
	/usr/include/qt3/qstring.h \
	/usr/include/qt3/qstrlist.h

qregion.h : /usr/include/qt3/qshared.h \
	/usr/include/qt3/qrect.h

LgiClass.h : ../../../include/common/LgiInc.h

qfontinfo.h : /usr/include/qt3/qfont.h

qsize.h : /usr/include/qt3/qpoint.h

qpoint.h : /usr/include/qt3/qwindowdefs.h \
	/usr/include/qt3/qwinexport.h

kdelibs_export.h : /usr/include/kde/kdemacros.h \
	/usr/include/qt3/qglobal.h

qpaintdevice.h : /usr/include/qt3/qwindowdefs.h \
	/usr/include/qt3/qrect.h

qpalette.h : /usr/include/qt3/qwindowdefs.h \
	/usr/include/qt3/qcolor.h \
	/usr/include/qt3/qshared.h \
	/usr/include/qt3/qbrush.h

qbrush.h : /usr/include/qt3/qcolor.h \
	/usr/include/qt3/qshared.h

qpixmap.h : /usr/include/qt3/qpaintdevice.h \
	/usr/include/qt3/qcolor.h \
	/usr/include/qt3/qstring.h \
	/usr/include/qt3/qnamespace.h

VPATH=%.cpp \
	$(BuildDir)

