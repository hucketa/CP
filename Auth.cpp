//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
 #include <System.RegularExpressions.hpp>
#include "Auth.h"
#include <IniFiles.hpp>
#include <System.IOUtils.hpp>
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
	bool loginSuccess = false;

	try
	{
		String login = LabeledEdit1->Text.Trim();
		String password = LabeledEdit2->Text.Trim();
		String query = "SELECT Role, PIB, Status FROM users WHERE Login = :Login AND Password = :Password";
		DataModule1->ADOQuery1->Close();
		DataModule1->ADOQuery1->SQL->Clear();
		DataModule1->ADOQuery1->SQL->Add(query);
		DataModule1->ADOQuery1->Parameters->ParamByName("Login")->Value = login;
		DataModule1->ADOQuery1->Parameters->ParamByName("Password")->Value = password;
		DataModule1->ADOQuery1->Open();

		if (DataModule1->ADOQuery1->RecordCount == 0)
		{
			ShowMessage("Невірний логін або пароль. Спробуйте ще раз.");
			return;
		}

		int status = DataModule1->ADOQuery1->FieldByName("Status")->AsInteger;
		if (status == 0)
		{
			ShowMessage("Обліковий запис не активний.");
			return;
		}

		String role = DataModule1->ADOQuery1->FieldByName("Role")->AsString;
		String pib = DataModule1->ADOQuery1->FieldByName("PIB")->AsString;
		role_s = role;
		pib_s = pib;
        login_s = login;
		loginSuccess = true;
		ShowMessage("Успішний вхід. Роль користувача: " + role);
	}
	catch (const Exception &e)
	{
		loginSuccess = false;
		return;
	}

	if (loginSuccess)
	{
		try
		{
			String iniFilePath = TPath::Combine(ExtractFilePath(Application->ExeName), "config.ini");
			TIniFile *ini = new TIniFile(iniFilePath);
			bool iniExists = ini->SectionExists("Certificate");
			delete ini;

			if (!iniExists)
			{
				if (role_s != "головний адміністратор")
				{
					loginSuccess = false;
					ShowMessage("Для першого запуску необхідно увійти як головний адміністратор.");
					return;
				}
				else
				{
					if (Form13 == NULL)
					{
						Application->CreateForm(__classid(TForm14), &Form14);
					}
					Form13->Show();
				}
			}
			else
			{
				if (Form3 == NULL)
				{
					Application->CreateForm(__classid(TForm3), &Form3);
				}
				Form3->Show();
			}

			this->Hide();
		}
		catch (const Exception &e)
		{
			loginSuccess = false;
		}
	}
}


String TForm12::get_role(){
	return role_s;
}

String TForm12::get_pib(){
	return pib_s;
}

String TForm12::get_login(){
	return login_s;
}
//---------------------------------------------------------------------------

void __fastcall TForm12::FormShow(TObject *Sender)
{
	LabeledEdit1->Text = "";
	LabeledEdit2->Text = "";
}
//--------------------------------------------------------------------------


void __fastcall TForm12::LabeledEdit1Exit(TObject *Sender)
{
	String login = LabeledEdit1->Text.Trim();
	UnicodeString pattern = L"^[A-Za-z0-9]+$";

	if (!TRegEx::IsMatch(login, pattern))
	{
		ShowMessage("Логін повинен містити тільки англійські букви та цифри.");
		LabeledEdit1->SetFocus();
		return;
	}
}


void __fastcall TForm12::LabeledEdit2Exit(TObject *Sender)
{
	String password = LabeledEdit2->Text.Trim();
	UnicodeString pattern = L"^[A-Za-z0-9]+$";

	if (!TRegEx::IsMatch(password, pattern))
	{
		ShowMessage("Пароль повинен містити тільки англійські букви та цифри.");
		LabeledEdit2->SetFocus();
	}
}
//-----------------------------------------------------------------------

