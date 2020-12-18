
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



#ifndef _EXAMGSF_DEF_H_
#define _EXAMGSF_DEF_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <getopt.h>
#include <cmath>

#include "nvutility.h"
#include "nvutility.hpp"

#include "pfm.h"
#include "gsf.h"
#include "gsf_indx.h"
#include "profile.hpp"


#include <QtCore>
#include <QtGui>
#if QT_VERSION >= 0x050000
#include <QtWidgets>
#endif


#define         EXAM_X_SIZE                 1200
#define         EXAM_Y_SIZE                 625
#define         BEAM_X_SIZE                 1200
#define         BEAM_Y_SIZE                 400
#define         OTHER_X_SIZE                800
#define         OTHER_Y_SIZE                600
#define         EXTENDED_X_SIZE             500
#define         EXTENDED_Y_SIZE             400
#define         PROFILE_X_SIZE              1200
#define         PROFILE_Y_SIZE              300
#define         SVP_X_SIZE                  200
#define         SVP_Y_SIZE                  600
#define         PAGE_SIZE                   12
#define         GSF_COLUMNS                 15
#define         HALF_PAGE                   (PAGE_SIZE / 2)


//  The OPTIONS structure contains all those variables that can be saved to the
//  users examGSF QSettings.
    
typedef struct
{
  int32_t     position_form;              //  Position format number
  int32_t     width;                      //  Main window width
  int32_t     height;                     //  Main window height
  int32_t     window_x;                   //  Main window x position
  int32_t     window_y;                   //  Main window y position
  int32_t     beam_width;                 //  Beam window width
  int32_t     beam_height;                //  Beam window height
  int32_t     beam_window_x;              //  Beam window x position
  int32_t     beam_window_y;              //  Beam window y position
  int32_t     other_width;                //  Other window width
  int32_t     other_height;               //  Other window height
  int32_t     other_window_x;             //  Other window x position
  int32_t     other_window_y;             //  Other window y position
  int32_t     extended_width;             //  Extended window width
  int32_t     extended_height;            //  Extended window height
  int32_t     extended_window_x;          //  Extended window x position
  int32_t     extended_window_y;          //  Extended window y position
  int32_t     profile_width;              //  Profile window width
  int32_t     profile_height;             //  Profile window height
  int32_t     profile_window_x;           //  Profile window x position
  int32_t     profile_window_y;           //  Profile window y position
  int32_t     svp_width;                  //  SVP window width
  int32_t     svp_height;                 //  SVP window height
  int32_t     svp_window_x;               //  SVP window x position
  int32_t     svp_window_y;               //  SVP window y position
  int32_t     depth_units;                //  0=meters, 1=feet, 2=fathoms, 3=cubits, 4=willetts
  QString     input_dir;                  //  Last directory searched for GSF files
  QFont       font;                       //  Font used for all ABE GUI applications
} OPTIONS;


// General stuff.

typedef struct
{
  QString     depth_string[5];            //  0=(meters), 1=(feet), 2=(fathoms), 3=(cubits), 4=(willetts)
  float       depth_factor[5];            //  0=1.00000, 1=3.28084, 2=0.54681, 3=0.44196, 4=16.4042
  char        progname[256];              /*  This is the program name.  It will be used in all output to stderr so that shelling programs
                                              will know what program printed out the error message.  */
} MISC;


#endif
