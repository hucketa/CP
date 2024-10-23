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
#include <Vcl.Buttons.hpp>
#include "Help.h"
#include "Main_Window.h"
#include "Data.h"
#include "Unit10.h"
//---------------------------------------------------------------------------
class TCertificates : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid2;
	TPopupMenu *PopupMenu1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *Lj1;
	TGroupBox *GroupBox1;
	TLabeledEdit *LabeledEdit1;
	TDatePicker *DatePicker1;
	TCheckBox *Later;
	TCheckBox *ThisDate;
	TCheckBox *Earlier;
	TLabel *Label4;
	TBitBtn *Execute;
	TBitBtn *Clear;
	TBitBtn *BitBtn1;
	void __fastcall N1Click(TObject *Sender);
	void __fastcall Lj1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall DatePicker1CloseUp(TObject *Sender);
	void __fastcall LabeledEdit1Exit(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ExecuteClick(TObject *Sender);
	void __fastcall ClearClick(TObject *Sender);
	void __fastcall DBGrid2TitleClick(TColumn *Column);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
private:
	void DBColumnSizes();
	bool SortAscending;	// User declarations
public:		// User declarations
	__fastcall TCertificates(TComponent* Owner);
	void __fastcall CheckFiltersFilled(TObject *Sender);
};
//---------------------------------------------------------------------------
extern PACKAGE TCertificates *Certificates;
//---------------------------------------------------------------------------
#endif
