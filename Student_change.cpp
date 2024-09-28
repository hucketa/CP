//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Student_change.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
    ComboBox1->ItemIndex = 0;
}
//---------------------------------------------------------------------------

