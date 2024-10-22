//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.WinXPickers.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TEdit *Edit2;
	TComboBox *ComboBox1;
	TDatePicker *DatePicker1;
	TRadioGroup *RadioGroup1;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TButton *Button1;
	TLabel *Label3;
	TEdit *Edit1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Edit2Exit(TObject *Sender);
	void __fastcall Edit4Exit(TObject *Sender);
	void __fastcall Edit6Exit(TObject *Sender);
	void __fastcall Edit5Exit(TObject *Sender);
	void __fastcall Edit3Exit(TObject *Sender);
	void __fastcall LoadStudentData(int student_id);
	void __fastcall DatePicker1CloseUp(TObject *Sender);
	void __fastcall ComboBox1CloseUp(TObject *Sender);
	void __fastcall RadioGroup1Exit(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:
	int id;
	void ClearFields();
	bool IsAllDigits(const String& str);	// User declarations
public:
	  void set_id(int k);		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
