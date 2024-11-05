//---------------------------------------------------------------------------

#ifndef Unit15H
#define Unit15H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include "Data.h"
#include "Unit16.h"
//---------------------------------------------------------------------------
class TForm15 : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TPopupMenu *PopupMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
private:
    bool SortAscending;
	void DBColumnSizes();	// User declarations
public:		// User declarations
	__fastcall TForm15(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm15 *Form15;
//---------------------------------------------------------------------------
#endif
