
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



#ifndef OTHERRECS_H
#define OTHERRECS_H

#include <stdio.h>

#include "examGSFDef.hpp"


class otherRecs:public QDialog
{
  Q_OBJECT 


public:

  otherRecs (QWidget *parent = 0, int32_t gsfHandle = 0, OPTIONS *op = NULL, MISC *mi = NULL);
  ~otherRecs ();


signals:

  void findPingSignal (int32_t record);
  void closedSignal ();


protected:

  OPTIONS         *options;

  MISC            *misc;

  gsfRecords      gsf_record;

  gsfDataID       gsf_data_id;

  int32_t         gsf_handle, numrecs, numhist, numsumm, numcomm, numproc, numsens, numnavi, numsvpr, 
                  numhvnv, numothr, *rid, *rec, digits;

  struct timespec *rec_time;

  QString         id_name[NUM_REC_TYPES];

  QHeaderView     *vheader;

  uint64_t        start_nsec, end_nsec;

  QTableWidget    *otherTable;

  QPushButton     **bExtend, **bFind;

  QButtonGroup    *otherFindGrp, *otherExtendGrp;

  QDialog         *extendD, *svProfileD;

  nvMap           *sv_profile;

  NVMAP_DEF       mapdef;

  NV_F64_COORD2   *svData;

  int32_t         sv_length;

  BOUNDS          sv_bounds;

  QStatusBar      *svBar;

  QLabel          *depLabel, *svLabel;


  uint8_t readRecord (int32_t dataID, int32_t rec_num, gsfDataID *gsf_data_id, gsfRecords *gsf_record);
  void populateTable (int32_t row);
  void closeEvent (QCloseEvent *e);
  void plotSvProfile ();


protected slots:

  void slotCloseOtherRecs ();
  void slotHelp ();
  void slotExtend (int id);
  void slotSvProfileMouseMove (QMouseEvent *e, double x, double y);
  void slotExtendFinished (int result);
  void slotCloseExtend ();
  void plotSvProfile (int32_t recnum);
  void slotPlotProfile (NVMAP_DEF l_mapdef);
  void slotSvProfileFinished (int result);
  void slotCloseProfile ();
  void slotResize (QResizeEvent *e);


private:
};

#endif
