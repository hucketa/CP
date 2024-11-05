//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit15.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm15 *Form15;
//---------------------------------------------------------------------------
__fastcall TForm15::TForm15(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void TForm15::DBColumnSizes(){
	DBGrid1->Columns->Items[0]->Width = 85;
	DBGrid1->Columns->Items[0]->Title->Caption = "Логін";
	DBGrid1->Columns->Items[1]->Width = 100;
	DBGrid1->Columns->Items[1]->Title->Caption = "Пароль";
	DBGrid1->Columns->Items[2]->Width = 150;
	DBGrid1->Columns->Items[2]->Title->Caption = "Роль";
	DBGrid1->Columns->Items[3]->Width = 175;
	DBGrid1->Columns->Items[3]->Title->Caption = "ПІБ";
	DBGrid1->Columns->Items[4]->Width = 85;
	DBGrid1->Columns->Items[4]->Title->Caption = "Статус";
}

void __fastcall TForm15::FormShow(TObject *Sender)
{
	DBColumnSizes();
}
//---------------------------------------------------------------------------
void __fastcall TForm15::DBGrid1TitleClick(TColumn *Column)
{
	String sortOrder = SortAscending ? " ASC" : " DESC";
	DataModule1->ADOQuery5->Sort = Column->Field->FieldName + sortOrder;
	SortAscending = !SortAscending;
}
//---------------------------------------------------------------------------
void __fastcall TForm15::N1Click(TObject *Sender)
{
	Form16->set_login("");
	Form16->ShowModal();
    DataModule1->ADOQuery5->Close();
	DataModule1->ADOQuery5->Open();
	DBColumnSizes();
}
//---------------------------------------------------------------------------
void __fastcall TForm15::N2Click(TObject *Sender)
{
    DataModule1->DataSource1->DataSet->Refresh();
    String login = DBGrid1->DataSource->DataSet->FieldByName("Login")->AsString;

    TADOQuery *query = new TADOQuery(this);
    query->Connection = DataModule1->ADOConnection1;
    query->SQL->Text = "SELECT Login FROM users WHERE Login = :Login";
    query->Parameters->ParamByName("Login")->Value = login;
    query->Open();

    if (!query->Eof)
    {
		Form16->set_login(login);
		Form16->ShowModal();
		DataModule1->ADOQuery5->Close();
		DataModule1->ADOQuery5->Open();
		DBColumnSizes();
    }
    else
    {
        ShowMessage("Користувача з таким логіном не знайдено.");
    }
    delete query;
}

//---------------------------------------------------------------------------
