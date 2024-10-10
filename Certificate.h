//---------------------------------------------------------------------------

#ifndef CertificateH
#define CertificateH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.WinXPickers.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TCertificates : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TGroupBox *GroupBox1;
	TLabel *Label2;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *Edit2;
	TDatePicker *DatePicker1;
	TEdit *Edit4;
	TButton *Button1;
	TRadioGroup *RadioGroup1;
	TDBGrid *DBGrid2;
	TLabeledEdit *LabeledEdit1;
	TDatePicker *DatePicker2;
	TLabel *Label1;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *Lj1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N11;
private:	// User declarations
public:		// User declarations
	__fastcall TCertificates(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCertificates *Certificates;
//---------------------------------------------------------------------------
#endif
