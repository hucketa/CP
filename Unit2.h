//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TLabel *Label4;
	TEdit *Edit2;
	TEdit *Edit4;
	TButton *Button1;
	TLabel *Label1;
	TEdit *Edit1;
	TButton *Button2;
	TOpenPictureDialog *OpenPictureDialog1;
	TLabel *Label2;
	TButton *Button3;
	TEdit *Edit3;
	TLabel *Label3;
	TOpenTextFileDialog *OpenTextFileDialog1;
	void __fastcall Edit2Exit(TObject *Sender);
	void __fastcall Edit4Exit(TObject *Sender);
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Edit3Exit(TObject *Sender);
private:
	int id;	// User declarations
    bool IsValidUkrainianText(const String &text);
public:
	void __fastcall set_id(int k);		// User declarations
	__fastcall TForm2(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
