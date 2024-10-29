//---------------------------------------------------------------------------

#ifndef ResultsH
#define ResultsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.WinXPickers.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Buttons.hpp>
#include "Data.h"
#include "Unit9.h"
#include <System.RegularExpressions.hpp>
//---------------------------------------------------------------------------
class TForm11 : public TForm
{
__published:	// IDE-managed Components
	TPopupMenu *PopupMenu1;
	TMenuItem *N2;
	TMenuItem *N3;
	TGroupBox *GroupBox1;
	TLabel *Label3;
	TComboBox *ComboBox2;
	TBitBtn *Execute;
	TBitBtn *Clear;
	TCheckBox *ThisDate;
	TDatePicker *DatePicker1;
	TLabeledEdit *LabeledEdit1;
	TDBGrid *DBGrid1;
	TMainMenu *MainMenu1;
	TMenuItem *N6;
	TMenuItem *Lj1;
	TDatePicker *DatePicker2;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall DatePicker1CloseUp(TObject *Sender);
	void __fastcall LabeledEdit1Exit(TObject *Sender);
	void __fastcall ExecuteClick(TObject *Sender);
	void __fastcall ClearClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N6Click(TObject *Sender);
	void __fastcall Lj1Click(TObject *Sender);
	void __fastcall DatePicker2CloseUp(TObject *Sender);
private:
	void __fastcall DBColumnSizes();
	//bool SortAscending;
	void __fastcall CheckFiltersFilled(TObject *Sender);	// User declarations
public:		// User declarations
	__fastcall TForm11(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm11 *Form11;
//---------------------------------------------------------------------------
#endif
