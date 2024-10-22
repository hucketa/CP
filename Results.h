//---------------------------------------------------------------------------

#ifndef ResultsH
#define ResultsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.WinXPickers.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Buttons.hpp>
#include "Data.h"
#include "Unit9.h"
#include <System.RegularExpressions.hpp>
//---------------------------------------------------------------------------
class TForm11 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *Lj1;
	TPopupMenu *PopupMenu1;
	TMenuItem *N2;
	TMenuItem *N3;
	TGroupBox *GroupBox1;
	TLabel *Label3;
	TLabel *Label4;
	TComboBox *ComboBox2;
	TBitBtn *Execute;
	TBitBtn *Clear;
	TCheckBox *Earlier;
	TCheckBox *Later;
	TCheckBox *ThisDate;
	TDatePicker *DatePicker1;
	TLabeledEdit *LabeledEdit1;
	TDBGrid *DBGrid1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall DatePicker1CloseUp(TObject *Sender);
	void __fastcall LabeledEdit1Exit(TObject *Sender);
	void __fastcall DBGrid2TitleClick(TColumn *Column);
	void __fastcall ExecuteClick(TObject *Sender);
	void __fastcall ClearClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:
	void __fastcall DBColumnSizes();
    bool SortAscending;
	void __fastcall CheckFiltersFilled(TObject *Sender);	// User declarations
public:		// User declarations
	__fastcall TForm11(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm11 *Form11;
//---------------------------------------------------------------------------
#endif
