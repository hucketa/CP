//---------------------------------------------------------------------------

#ifndef Unit13H
#define Unit13H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm13 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Login;
	TEdit *Password;
	TButton *Button1;
	TLabel *Label4;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label5;
	TComboBox *ComboBox1;
	TButton *Button2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm13(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm13 *Form13;
//---------------------------------------------------------------------------
#endif
