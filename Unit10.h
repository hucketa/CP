//---------------------------------------------------------------------------

#ifndef Unit10H
#define Unit10H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.WinXPickers.hpp>
#include "Students.h"
#include "Data.h"
//---------------------------------------------------------------------------
class TForm10 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TLabel *Label2;
	TDatePicker *DatePicker1;
	TButton *Button1;
	TRadioGroup *RadioGroup1;
	TLabeledEdit *LabeledEdit1;
	TLabeledEdit *LabeledEdit2;
	TLabel *Label1;
	TDatePicker *DatePicker2;
	void __fastcall LabeledEdit1SubLabelClick(TObject *Sender);
	void __fastcall LabeledEdit1Exit(TObject *Sender);
	void __fastcall LabeledEdit2Exit(TObject *Sender);
	void __fastcall DatePicker1CloseUp(TObject *Sender);
	void __fastcall DatePicker2CloseUp(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:
	int id;	// User declarations
public:		// User declarations
	__fastcall TForm10(TComponent* Owner);
	void set_id(int k);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm10 *Form10;
//---------------------------------------------------------------------------
#endif
