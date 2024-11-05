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
#include <System.RegularExpressions.hpp>
#include "Data.h"
#include "Help.h"
#include "Conditions.h"
#include "Students.h"
#include "Subjects.h"
#include "Results.h"
#include "Certificate.h"
#include "School.h"
#include "Auth.h"
#include "Unit15.h"
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
	TCheckBox *ThisDate;
	TGroupBox *Status;
	TGroupBox *Surname_student;
	TRadioGroup *Status_check;
	TEdit *Edit1;
	TMenuItem *N3;
	TBitBtn *Clear;
	TBitBtn *Execute;
	TMenuItem *N2;
	TMenuItem *N4;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N9;
	TDBGrid *DBGrid1;
	TMenuItem *N10;
	TDatePicker *DatePicker2;
	TMenuItem *N14;
	TMenuItem *N15;
	TMenuItem *N11;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall CheckFiltersFilled(TObject *Sender);
	void __fastcall ClearClick(TObject *Sender);
	void __fastcall ExecuteClick(TObject *Sender);
	void __fastcall Lj1Click(TObject *Sender);
	void __fastcall N11Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall DatePicker1CloseUp(TObject *Sender);
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall N9Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall DatePicker2CloseUp(TObject *Sender);
	void __fastcall N14Click(TObject *Sender);
	void __fastcall N15Click(TObject *Sender);
private:
	void UpdateStatusBar(String role, String pib);
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
	void ManageMenuItems(String role);
	void DBColumnMainSizes();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
