//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <SysUtils.hpp>
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Timer1Timer(TObject *Sender)
{
	 StatusBar1->Panels->Items[1]->Text = DateTimeToStr(Now());
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormCreate(TObject *Sender)
{
    StatusBar1->Panels->Items[1]->Text = DateTimeToStr(Now());
}

