//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Auth.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm12 *Form12;
//---------------------------------------------------------------------------
__fastcall TForm12::TForm12(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TForm12::Button1Click(TObject *Sender)
{
	try
	{
		String login = LabeledEdit1->Text.Trim();
		String password = LabeledEdit2->Text.Trim();
		String query = "SELECT Role FROM users WHERE Login = :Login AND Password = :Password";
		DataModule1->ADOQuery1->Close();
		DataModule1->ADOQuery1->SQL->Clear();
		DataModule1->ADOQuery1->SQL->Add(query);
		DataModule1->ADOQuery1->Parameters->ParamByName("Login")->Value = login;
		DataModule1->ADOQuery1->Parameters->ParamByName("Password")->Value = password;
		DataModule1->ADOQuery1->Open();
		if (DataModule1->ADOQuery1->RecordCount > 0)
		{
			String role = DataModule1->ADOQuery1->FieldByName("Role")->AsString;
			role_s = role;
			this->set_flag(true);
			this->Close();
		}
		else
		{
			ShowMessage("Невірний логін або пароль. Спробуйте ще раз.");
			this->set_flag(false);
		}
	}
	catch (const Exception &e)
	{
		ShowMessage("Помилка під час входу: " + e.Message);
		this->set_flag(false);
	}
}



//---------------------------------------------------------------------------

void TForm12::set_flag(bool k){
   flag = k;
}


bool TForm12::get_flag(){
	return flag;
}

void __fastcall TForm12::FormShow(TObject *Sender)
{
	flag = false;
}

String TForm12::get_role(){
    return role_s;
}
//---------------------------------------------------------------------------

