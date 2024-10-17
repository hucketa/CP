//---------------------------------------------------------------------------

#ifndef Main_WindowH
#define Main_WindowH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.WinXPickers.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N5;
	TStatusBar *StatusBar1;
	TTimer *Timer1;
	TMenuItem *Lj1;
	TGroupBox *GroupBox1;
	TDatePicker *DatePicker1;
	TCheckBox *Earlier;
	TCheckBox *ThisDate;
	TCheckBox *Later;
	TGroupBox *Status;
	TGroupBox *Surname_student;
	TRadioGroup *Status_check;
	TEdit *Edit1;
	TMenuItem *N15;
	TMenuItem *N16;
	TMenuItem *N3;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N11;
	TDBGrid *DBGrid1;
	TBitBtn *Clear;
	TBitBtn *Execute;
	TMenuItem *N2;
	TMenuItem *N4;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall FormShow(TObject *Sender);
	//void __fastcall ExecuteClick(TObject *Sender);
	void __fastcall CheckFiltersFilled(TObject *Sender);
	//void __fastcall ClearClick(TObject *Sender);
	void __fastcall ClearClick(TObject *Sender);
	void __fastcall ExecuteClick(TObject *Sender);
	void __fastcall Lj1Click(TObject *Sender);
	void __fastcall N11Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:
	void DBColumnSizes();	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
