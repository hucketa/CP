//---------------------------------------------------------------------------

#ifndef StudentsH
#define StudentsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.WinXPickers.hpp>
#include <Vcl.Menus.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.DBCtrls.hpp>
#include "Main_Window.h"
#include "Help.h"
#include <String.h>
#include <System.RegularExpressions.hpp>
#include "Data.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
class TForm14 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *Lj1;
	TDBGrid *DBGrid1;
	TMenuItem *N6;
	TPopupMenu *PopupMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TLabel *Label2;
	TDatePicker *DatePicker1;
	TRadioGroup *RadioGroup1;
	TButton *Button1;
	TLabel *Label3;
	TLabel *Label7;
	TEdit *Edit5;
	TBitBtn *Clear;
	TBitBtn *Execute;
	TCheckBox *Earlier;
	TCheckBox *Later;
	TCheckBox *ThisDate;
	TComboBox *ComboBox1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall N6Click(TObject *Sender);
	void __fastcall Lj1Click(TObject *Sender);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall ExecuteClick(TObject *Sender);
	void __fastcall ClearClick(TObject *Sender);
	void __fastcall DatePicker1CloseUp(TObject *Sender);
	void __fastcall Edit5Exit(TObject *Sender);

private:
	bool SortAscending;	// User declarations
	void __fastcall CheckFiltersFilled(TObject *Sender);
public:		// User declarations
	__fastcall TForm14(TComponent* Owner);
	void __fastcall TForm14::DBColumnSizes();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm14 *Form14;
//---------------------------------------------------------------------------
#endif
