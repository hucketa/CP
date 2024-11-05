//---------------------------------------------------------------------------

#ifndef Unit16H
#define Unit16H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include "Data.h"
//---------------------------------------------------------------------------
class TForm16 : public TForm
{
__published:	// IDE-managed Components
	TLabeledEdit *LabeledEdit1;
	TLabeledEdit *LabeledEdit2;
	TLabeledEdit *LabeledEdit3;
	TButton *Button1;
	TLabel *Label1;
	TComboBox *ComboBox1;
	TRadioGroup *RadioGroup1;
	void __fastcall LabeledEdit3Exit(TObject *Sender);
	void __fastcall LabeledEdit1Exit(TObject *Sender);
	void __fastcall LabeledEdit2Exit(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:
	String originalLogin;
	bool isEditMode;
		// User declarations
public:		// User declarations
	__fastcall TForm16(TComponent* Owner);
	void __fastcall set_login(String login);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm16 *Form16;
//---------------------------------------------------------------------------
#endif
