
/*********************************************************************************************

    This is public domain software that was developed by or for the U.S. Naval Oceanographic
    Office and/or the U.S. Army Corps of Engineers.

    This is a work of the U.S. Government. In accordance with 17 USC 105, copyright protection
    is not available for any work of the U.S. Government.

    Neither the United States Government, nor any employees of the United States Government,
    nor the author, makes any warranty, express or implied, without even the implied warranty
    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE, or assumes any liability or
    responsibility for the accuracy, completeness, or usefulness of any information,
    apparatus, product, or process disclosed, or represents that its use would not infringe
    privately-owned rights. Reference herein to any specific commercial products, process,
    or service by trade name, trademark, manufacturer, or otherwise, does not necessarily
    constitute or imply its endorsement, recommendation, or favoring by the United States
    Government. The views and opinions of authors expressed herein do not necessarily state
    or reflect those of the United States Government, and shall not be used for advertising
    or product endorsement purposes.
*********************************************************************************************/


/****************************************  IMPORTANT NOTE  **********************************

    Comments in this file that start with / * ! or / / ! are being used by Doxygen to
    document the software.  Dashes in these comment blocks are used to create bullet lists.
    The lack of blank lines after a block of dash preceeded comments means that the next
    block of dash preceeded comments is a new, indented bullet list.  I've tried to keep the
    Doxygen formatting to a minimum but there are some other items (like <br> and <pre>)
    that need to be left alone.  If you see a comment that starts with / * ! or / / ! and
    there is something that looks a bit weird it is probably due to some arcane Doxygen
    syntax.  Be very careful modifying blocks of Doxygen comments.

*****************************************  IMPORTANT NOTE  **********************************/


#ifndef VERSION

#define     VERSION     "PFM Software - examGSF V2.33 - 08/27/16"

#endif

/*! <pre>

    Version 1.00
    Jan C. Depner
    04/15/05

    First working version.  Happy tax day :-(


    Version 1.01
    Jan C. Depner
    04/22/05

    Added unit choice in preferences and profiles for data and SVP.


    Version 1.02
    Jan C. Depner
    05/05/05

    Finally got all of the utility library functions working in C++.  Happy Cinco De Mayo!


    Version 1.03
    Jan C. Depner
    05/11/05

    Added a few warning messages for using silly units of measure.


    Version 1.04
    Jan C. Depner
    05/26/05

    Added record and time info in status bar when sliding scroll bar.


    Version 1.05
    Jan C. Depner
    07/27/05

    Fixed plotting bug in dataProfile.


    Version 1.1
    Jan C. Depner
    08/17/05

    Added profile option for select column headers in the main view.  Also, fixed small 
    bug - don't want to check cross track array as it might be a single-beam.


    Version 1.11
    Jan C. Depner
    08/24/05

    Fixed off-by-one error in beamRecs.cpp.


    Version 1.12
    Jan C. Depner
    03/10/06

    Fixed tide type field.


    Version 1.2
    Jan C. Depner
    04/06/06

    Fixed profile paintimg problem.  Replaced QVBox, QHBox, QVGroupBox, QHGroupBox with QVBoxLayout, QHBoxLayout,
    QGroupBox to prepare for Qt 4.


    Version 1.21
    Jan C. Depner
    08/08/06

    Added file mask to input dialog.


    Version 2.0
    Jan C. Depner
    04/23/07

    Qt 4 port.


    Version 2.01
    Jan C. Depner
    08/24/07

    Switched from setGeometry to resize and move.  See Qt4 X11 window geometry documentation.


    Version 2.10
    Jan C. Depner
    10/24/07

    Fixed a number of size issues and added close and help buttons to all dialogs.  This is mostly for Windoze but
    it also makes it nicer in Linux.


    Version 2.11
    Jan C. Depner
    12/22/07

    Added ability to read file on command line without --file option.


    Version 2.12
    Jan C. Depner
    04/01/08

    Added acknowledgments to the Help pulldown menu.


    Version 2.13
    Jan C. Depner
    04/07/08

    Replaced single .h and .hpp files from utility library with include of nvutility.h and nvutility.hpp


    Version 2.14
    Jan C. Depner
    04/13/09

    Use NINT instead of typecasting to NV_INT32 when saving Qt window state.  Integer truncation was inconsistent on Windows.


    Version 2.15
    Jan C. Depner
    04/23/09

    Changed the acknowledgments help to include Qt and a couple of others.


    Version 2.16
    Jan C. Depner
    05/21/09

    Set all QFileDialogs to use List mode instead of Detail mode.


    Version 2.17
    Jan C. Depner
    04/29/10

    Fixed posfix and fixpos calls to use numeric constants instead of strings for type.


    Version 2.18
    Jan C. Depner
    01/06/11

    Correct problem with the way I was instantiating the main widget.  This caused an intermittent error on Windows7/XP.


    Version 2.19
    Jan C. Depner
    06/24/11

    Save and restore last input directory.


    Version 2.20
    Jan C. Depner
    07/22/11

    Using setSidebarUrls function from nvutility to make sure that current working directory (.) and
    last used directory are in the sidebar URL list of QFileDialogs.


    Version 2.21
    Jan C. Depner
    10/21/11

    Added some missing arrays from the gsfSwathBathyPing record.


    Version 2.22
    Jan C. Depner
    11/30/11

    Converted .xpm icons to .png icons.


    Version 2.23
    Jan C. Depner
    05/17/12

    In beam recs we now pre-read the records to get the max number of beams because they may not all
    be the same.


    Version 2.24
    Jan C. Depner (PFM Software)
    12/09/13

    Switched to using .ini file in $HOME (Linux) or $USERPROFILE (Windows) in the ABE.config directory.  Now
    the applications qsettings will not end up in unknown places like ~/.config/navo.navy.mil/blah_blah_blah on
    Linux or, in the registry (shudder) on Windows.


    Version 2.25
    Jan C. Depner (PFM Software)
    03/03/14

    Replaced HMPS flags with NV_GSF flags.


    Version 2.26
    Jan C. Depner (PFM Software)
    03/19/14

    - Straightened up the Open Source acknowledgments.


    Version 2.27
    Jan C. Depner (PFM Software)
    05/27/14

    - Added the new LGPL licensed GSF library to the acknowledgments.


    Version 2.28
    Jan C. Depner (PFM Software)
    07/01/14

    - Replaced all of the old, borrowed icons with new, public domain icons.  Mostly from the Tango set
      but a few from flavour-extended and 32pxmania.


    Version 2.29
    Jan C. Depner (PFM Software)
    07/23/14

    - Switched from using the old NV_INT64 and NV_U_INT32 type definitions to the C99 standard stdint.h and
      inttypes.h sized data types (e.g. int64_t and uint32_t).


    Version 2.30
    Jan C. Depner (PFM Software)
    07/29/14

    - Fixed errors discovered by cppcheck.


    Version 2.31
    Jan C. Depner (PFM Software)
    02/16/15

    - To give better feedback to shelling programs in the case of errors I've added the program name to all
      output to stderr.


    Version 2.32
    Jan C. Depner (PFM Software)
    03/31/15

    - Fixed name filter for GSF files so that it wouldn't find files that don't end in .dNN where NN is numeric.
      This prevents us from seeing, for example, ESRI shape .dbf files in the GSF name list.


    Version 2.33
    Jan C. Depner (PFM Software)
    08/27/16

    - Now uses the same font as all other ABE GUI apps.  Font can only be changed in pfmView Preferences.

</pre>*/
