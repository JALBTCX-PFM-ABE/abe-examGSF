contains(QT_CONFIG, opengl): QT += opengl
QT += 
RC_FILE = examGSF.rc
RESOURCES = icons.qrc
INCLUDEPATH += /c/PFM_ABEv7.0.0_Win64/include
LIBS += -L /c/PFM_ABEv7.0.0_Win64/lib -lgsf -lnvutility -lgdal -lxml2 -lpoppler -liconv -lwsock32
DEFINES += WIN32 NVWIN3X
CONFIG += console
QMAKE_LFLAGS += 
######################################################################
# Automatically generated by qmake (2.01a) Wed Jan 22 14:10:18 2020
######################################################################

TEMPLATE = app
TARGET = examGSF
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += beamRecs.hpp \
           beamRecsHelp.hpp \
           examGSF.hpp \
           examGSFDef.hpp \
           examGSFHelp.hpp \
           otherRecs.hpp \
           otherRecsHelp.hpp \
           profile.hpp \
           version.hpp
SOURCES += beamRecs.cpp examGSF.cpp main.cpp otherRecs.cpp
RESOURCES += icons.qrc
