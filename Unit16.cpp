#include <vcl.h>
#include <System.RegularExpressions.hpp>
#pragma hdrstop

#include "Unit16.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm16 *Form16;

__fastcall TForm16::TForm16(TComponent* Owner)
	: TForm(Owner)
{

}

void __fastcall TForm16::set_login(String login)
{
	originalLogin = login;

	if (login.IsEmpty())
	{
		LabeledEdit1->Text = "";
		LabeledEdit2->Text = "";
		LabeledEdit3->Text = "";
		ComboBox1->ItemIndex = -1;
		RadioGroup1->ItemIndex = -1;
		isEditMode =false;
	}
	else
	{
		String query = "SELECT Login, Password, Role, PIB, Status FROM users WHERE Login = :Login";
		DataModule1->ADOQuery1->Close();
		DataModule1->ADOQuery1->SQL->Clear();
		DataModule1->ADOQuery1->SQL->Add(query);
		DataModule1->ADOQuery1->Parameters->ParamByName("Login")->Value = login;
		DataModule1->ADOQuery1->Open();

		if (DataModule1->ADOQuery1->RecordCount > 0)
		{
			LabeledEdit1->Text = DataModule1->ADOQuery1->FieldByName("Login")->AsString;
			LabeledEdit2->Text = DataModule1->ADOQuery1->FieldByName("Password")->AsString;
			String role = DataModule1->ADOQuery1->FieldByName("Role")->AsString;
			for (int i = 0; i < ComboBox1->Items->Count; i++)
			{
				if (ComboBox1->Items->Strings[i] == role)
				{
					ComboBox1->ItemIndex = i;
					break;
				}
			}
			LabeledEdit3->Text = DataModule1->ADOQuery1->FieldByName("PIB")->AsString;
			int status = DataModule1->ADOQuery1->FieldByName("Status")->AsInteger;
			RadioGroup1->ItemIndex = (status == 1) ? 0 : 1;
			isEditMode = true;
		}
		else
		{
			LabeledEdit1->Text = "";
			LabeledEdit2->Text = "";
			LabeledEdit3->Text = "";
			ComboBox1->ItemIndex = -1;
			RadioGroup1->ItemIndex = -1;
		}

		DataModule1->ADOQuery1->Close();
	}
}



void __fastcall TForm16::LabeledEdit3Exit(TObject *Sender)
{
	String pib = LabeledEdit3->Text.Trim();
	UnicodeString pattern = L"^[А-ЯІЇЄҐа-яіїєґ'\\s]+$";

	if (!TRegEx::IsMatch(pib, pattern))
	{
		ShowMessage("Поле 'ПІБ' повинно містити тільки українські літери, пробіли та апострофи.");
		LabeledEdit3->SetFocus();
	}
}


void __fastcall TForm16::LabeledEdit1Exit(TObject *Sender)
{
	String login = LabeledEdit1->Text.Trim();
	UnicodeString pattern = L"^[A-Za-z0-9]+$";
	if (!TRegEx::IsMatch(login, pattern))
	{
		ShowMessage("Логін повинен містити тільки англійські букви та цифри.");
		LabeledEdit1->SetFocus();
		return;
	}
	if (login == originalLogin)
	{
		return;
	}
	String query = "SELECT COUNT(*) AS UserCount FROM users WHERE Login = :Login";
	DataModule1->ADOQuery1->Close();
	DataModule1->ADOQuery1->SQL->Clear();
	DataModule1->ADOQuery1->SQL->Add(query);
	DataModule1->ADOQuery1->Parameters->ParamByName("Login")->Value = login;
	DataModule1->ADOQuery1->Open();

	if (DataModule1->ADOQuery1->FieldByName("UserCount")->AsInteger > 0)
	{
		ShowMessage("Цей логін вже існує. Будь ласка, виберіть інший.");
		LabeledEdit1->SetFocus();
	}
	DataModule1->ADOQuery1->Close();
}



void __fastcall TForm16::LabeledEdit2Exit(TObject *Sender)
{
	String password = LabeledEdit2->Text.Trim();
	UnicodeString pattern = L"^[A-Za-z0-9]+$";

	if (!TRegEx::IsMatch(password, pattern))
	{
		ShowMessage("Пароль повинен містити тільки англійські букви та цифри.");
		LabeledEdit2->SetFocus();
	}
}

void __fastcall TForm16::FormShow(TObject *Sender)
{
	RadioGroup1->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TForm16::Button1Click(TObject *Sender)
{
	String login = LabeledEdit1->Text.Trim();
	String password = LabeledEdit2->Text.Trim();
	String pib = LabeledEdit3->Text.Trim();
	String role = ComboBox1->Text;
	int status = (RadioGroup1->ItemIndex == 0) ? 1 : 0;
	if (login.IsEmpty() || password.IsEmpty() || pib.IsEmpty() || role.IsEmpty())
	{
		ShowMessage("Будь ласка, заповніть всі обов'язкові поля.");
		return;
	}
	try
	{
		if (isEditMode)
		{
			String query = "UPDATE users SET Login = :Login, Password = :Password, Role = :Role, PIB = :PIB, Status = :Status WHERE Login = :OriginalLogin";
			DataModule1->ADOQuery1->Close();
			DataModule1->ADOQuery1->SQL->Clear();
			DataModule1->ADOQuery1->SQL->Add(query);
			DataModule1->ADOQuery1->Parameters->ParamByName("Login")->Value = login;
			DataModule1->ADOQuery1->Parameters->ParamByName("Password")->Value = password;
			DataModule1->ADOQuery1->Parameters->ParamByName("Role")->Value = role;
			DataModule1->ADOQuery1->Parameters->ParamByName("PIB")->Value = pib;
			DataModule1->ADOQuery1->Parameters->ParamByName("Status")->Value = status;
			DataModule1->ADOQuery1->Parameters->ParamByName("OriginalLogin")->Value = originalLogin;
			DataModule1->ADOQuery1->ExecSQL();
			ShowMessage("Користувач успішно оновлений.");
		}
		else
		{
			String query = "INSERT INTO users (Login, Password, Role, PIB, Status) VALUES (:Login, :Password, :Role, :PIB, :Status)";
			DataModule1->ADOQuery1->Close();
			DataModule1->ADOQuery1->SQL->Clear();
			DataModule1->ADOQuery1->SQL->Add(query);
			DataModule1->ADOQuery1->Parameters->ParamByName("Login")->Value = login;
			DataModule1->ADOQuery1->Parameters->ParamByName("Password")->Value = password;
			DataModule1->ADOQuery1->Parameters->ParamByName("Role")->Value = role;
			DataModule1->ADOQuery1->Parameters->ParamByName("PIB")->Value = pib;
			DataModule1->ADOQuery1->Parameters->ParamByName("Status")->Value = status;
			DataModule1->ADOQuery1->ExecSQL();
			ShowMessage("Користувач успішно доданий.");
		}
		this->Close();
	}
	catch (const Exception &e)
	{
		ShowMessage("Помилка при збереженні користувача: " + e.Message);
	}
}

//---------------------------------------------------------------------------




