//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit9.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9 *Form9;
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm9::FormShow(TObject *Sender)
{
	/*ComboBox1->Clear();
    ComboBox2->Clear();
    TADOQuery *query = new TADOQuery(this);
    query->Connection = DataModule1->ADOConnection1;
    try
    {
        query->SQL->Text = "SELECT Name FROM subject ORDER BY Subject_id";
        query->Open();
        while (!query->Eof)
        {
            ComboBox1->Items->Add(query->FieldByName("Name")->AsString);
            query->Next();
        }
        query->Close();
        query->SQL->Text = "SELECT Email FROM school ORDER BY School_id";
        query->Open();
        while (!query->Eof)
        {
            ComboBox2->Items->Add(query->FieldByName("Email")->AsString);
            query->Next();
        }
    }
    __finally
    {
        query->Close();
        delete query;
    }*/
}

//---------------------------------------------------------------------------

