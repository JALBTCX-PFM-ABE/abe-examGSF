
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



/*  examGSF class definitions.  */

#ifndef EXAMGSF_H
#define EXAMGSF_H

#include "examGSFDef.hpp"
#include "version.hpp"
#include "otherRecs.hpp"
#include "beamRecs.hpp"


class examGSF:public QMainWindow
{
  Q_OBJECT 


public:

  examGSF (int32_t *argc = 0, char **argv = 0, QWidget *parent = 0);
  ~examGSF ();


protected:

  OPTIONS         options;

  MISC            misc;

  gsfDataID       gsf_data_id;

  gsfRecords      gsf_record;

  QTableWidget    *gsfTable;

  QHeaderView     *vheader;

  QTableWidgetItem **vhItem;

  otherRecs       *other_recs;

  beamRecs        *beam_recs;

  QScrollBar      *scrollBar;

  QAction         *bHelp;

  QLabel          *filLabel, *sizLabel, *verLabel, *senLabel, *recordLabel, *dataLabel;

  int32_t         gsf_handle, record_num, index_state, index_percent, numrecs, rec_arg_num, depth_units, last_beam_rec,
                  prof_size, start_rec, digits;

  QString         depth_string;

  QString         acknowledgmentsText;

  double          depth_factor;

  double          a0, b0;

  QString         filename;

  int32_t         start, end;

  uint8_t         filearg, display_other;

  QButtonGroup    *bGrp, *bBeamDataGrp, *dGrp;
  QDialog         *prefsD, *profileD;
  QToolButton     *bQuit, *bOpen, *bOther, *bPrefs;

  QStatusBar      *dataBar;


  void envin ();
  void envout ();

  bool eventFilter (QObject *o, QEvent *e);
  void keyPressEvent (QKeyEvent *e);

  void openFile ();

  void readData (int32_t record);

  void populateTable (int32_t row, gsfDataID dataID, gsfRecords record);

  void setUnits ();

  void setHeaders ();


protected slots:

  void slotOpen ();
  void slotQuit ();

  void slotBeamDataClicked (int row);

  void slotScrollBarValueChanged (int value);
  void slotScrollBarSliderMoved (int value);

  void slotOther ();
  void slotHelp ();

  void slotFindPing (int32_t record);
  void slotOtherRecsClosed ();

  void slotDataProfileMouseMove (QMouseEvent *e, double x, double y);

  void slotPrefs ();
  void slotPosClicked (int id);
  void slotDepthClicked (int id);
  void slotClosePrefs ();

  void about ();
  void slotAcknowledgments ();
  void aboutQt ();


 private:
};

#endif
