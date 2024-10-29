//---------------------------------------------------------------------------

#ifndef ConditionsH
#define ConditionsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.WinXPickers.hpp>
#include "Help.h"
#include <Data.DB.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "Data.h"
#include "Unit5.h"
#include <Vcl.Menus.hpp>
#include <Vcl.WinXPickers.hpp>
#include <Vcl.Buttons.hpp>
#include "Main_Window.h"
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TMainMenu *MainMenu1;
	TMenuItem *Lj1;
	TMenuItem *N1;
	TGroupBox *GroupBox1;
	TComboBox *ComboBox2;
	TLabel *Label3;
	TDatePicker *DatePicker2;
	TBitBtn *Execute;
	TBitBtn *Clear;
	TCheckBox *ThisDate;
	TPopupMenu *PopupMenu1;
	TMenuItem *N2;
	TMenuItem *N3;
	TDatePicker *DatePicker1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Lj1Click(TObject *Sender);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall DatePicker2CloseUp(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ExecuteClick(TObject *Sender);
	void __fastcall ClearClick(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall DatePicker1CloseUp(TObject *Sender);
private:
	bool SortAscending;
	void DBColumnSizes();
	void __fastcall CheckFiltersFilled(TObject *Sender);
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
	bool isMinimalView;
	void TForm4::ToggleView();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
