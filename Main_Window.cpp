//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <SysUtils.hpp>
#include "Main_Window.h"
#include "Data.h"
#include "Certificate.h"
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


//---------------------------------------------------------------------------

void __fastcall TForm3::DBGrid1TitleClick(TColumn *Column)
{
	String fieldName = Column->FieldName;
	DataModule1->ADOTable1->Close();
	DataModule1->ADOTable1->IndexFieldNames = fieldName;
	DataModule1->ADOTable1->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N1Click(TObject *Sender)
{
	  TCertificates *certificatesForm = new TCertificates(this);
    certificatesForm->Show(); // Показываем окно
    this->Hide(); // Скрываем текущее окно
}

//---------------------------------------------------------------------------

