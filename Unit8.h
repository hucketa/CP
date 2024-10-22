#ifndef Unit8H
#define Unit8H

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include "Data.h"

//---------------------------------------------------------------------------

class TForm8 : public TForm
{
__published:	// IDE-managed Components
	TLabeledEdit *LabeledEdit1;
	TLabeledEdit *LabeledEdit2;
	TLabeledEdit *LabeledEdit4;
	TLabeledEdit *LabeledEdit5;
	TButton *Button1;
	TComboBox *ComboBox1;
	TLabel *Label1;
	void __fastcall LabeledEdit1Exit(TObject *Sender);
	void __fastcall LabeledEdit2Exit(TObject *Sender);
	void __fastcall LabeledEdit4Exit(TObject *Sender);
	void __fastcall LabeledEdit5Exit(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);

private:
	bool IsUniqueValue(String field, String value);
	bool IsValidUkrainianInput(String input);
	int id;
public:
	__fastcall TForm8(TComponent* Owner);
	void set_id(int k);
};

//---------------------------------------------------------------------------
extern PACKAGE TForm8 *Form8;
//---------------------------------------------------------------------------
#endif

