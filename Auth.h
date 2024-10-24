//---------------------------------------------------------------------------

#ifndef AuthH
#define AuthH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include "Data.h"
#include "Main_Window.h"
//---------------------------------------------------------------------------
class TForm12 : public TForm
{
__published:	// IDE-managed Components
	TLabeledEdit *LabeledEdit1;
	TLabeledEdit *LabeledEdit2;
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:
	bool flag;
	String role_s;	// User declarations
public:		// User declarations
	__fastcall TForm12(TComponent* Owner);
	void set_flag(bool k);
	bool get_flag();
	String get_role();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm12 *Form12;
//---------------------------------------------------------------------------
#endif
