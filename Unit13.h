//---------------------------------------------------------------------------

#ifndef Unit13H
#define Unit13H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TForm13 : public TForm
{
__published:	// IDE-managed Components
	TLabeledEdit *LabeledEdit1;
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall LabeledEdit1Exit(TObject *Sender);
private:
	bool __fastcall LoadTemplateFromIni();
	void __fastcall SaveTemplateToIni();	// User declarations
public:
	String template_name;		// User declarations
	__fastcall TForm13(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm13 *Form13;

//---------------------------------------------------------------------------
#endif
