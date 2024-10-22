//---------------------------------------------------------------------------

#ifndef SchoolH
#define SchoolH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include "Data.h"
#include "Help.h"
#include "Unit8.h"
#include "Main_Window.h"
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N6;
	TMenuItem *Lj1;
	TPopupMenu *PopupMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TDBGrid *DBGrid1;
	void __fastcall Lj1Click(TObject *Sender);
	void __fastcall N6Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
private:
	void __fastcall DBColumnSizes();
	bool SortAscending;// User declarations
public:		// User declarations
	__fastcall TForm6(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
