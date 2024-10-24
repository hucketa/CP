//---------------------------------------------------------------------------

#ifndef Unit5H
#define Unit5H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.WinXPickers.hpp>
#include "Data.h"
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TLabel *Label2;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *Edit2;
	TDatePicker *DatePicker1;
	TRadioGroup *RadioGroup1;
	TEdit *Edit4;
	TEdit *Edit6;
	TButton *Button1;
	TComboBox *ComboBox1;
	TLabel *Label1;
	void __fastcall DatePicker1CloseUp(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:
	int id;	// User declarations
public:		// User declarations
	__fastcall TForm5(TComponent* Owner);
	void set_id(int k);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif
