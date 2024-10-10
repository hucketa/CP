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
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TGroupBox *GroupBox2;
	TGroupBox *GroupBox3;
	TRadioGroup *RadioGroup2;
	TEdit *Edit1;
	TButton *Button1;
	TMenuItem *N15;
	TMenuItem *N16;
	TMenuItem *N3;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N11;
	TDBGrid *DBGrid1;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall N1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
