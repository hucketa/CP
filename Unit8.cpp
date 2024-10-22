#include <vcl.h>
#pragma hdrstop
#include "Unit8.h"
#pragma package(smart_init)
#include <System.RegularExpressions.hpp>
#pragma resource "*.dfm"
TForm8 *Form8;

__fastcall TForm8::TForm8(TComponent* Owner)
	: TForm(Owner)
{
}

void TForm8::set_id(int k)
{
id = k;
if(id > 0)
{
Button1->Caption = "Замінити";
AnsiString queryStr = "SELECT * FROM school WHERE School_id = :id";
TADOQuery *query = new TADOQuery(NULL);
query->Connection = DataModule1->ADOConnection1;
query->SQL->Text = queryStr;
query->Parameters->ParamByName("id")->Value = id;
query->Open();
if (!query->Eof)
{
LabeledEdit1->Text = query->FieldByName("City")->AsString;
LabeledEdit2->Text = query->FieldByName("Region")->AsString;
LabeledEdit4->Text = query->FieldByName("Email")->AsString;
LabeledEdit5->Text = query->FieldByName("Teacher_PIB")->AsString;

String schoolType = query->FieldByName("Type")->AsString;
schoolType = schoolType.Trim();
ComboBox1->ItemIndex = ComboBox1->Items->IndexOf(schoolType);
}
query->Close();
delete query;
}
else
{
Button1->Caption = "Додати";
LabeledEdit1->Text = "";
LabeledEdit2->Text = "";
LabeledEdit4->Text = "";
LabeledEdit5->Text = "";
ComboBox1->ItemIndex = -1;
}
}




bool TForm8::IsValidUkrainianInput(String input)
{
	for (int i = 1; i <= input.Length(); i++)
	{
		wchar_t c = input[i];
		if (!((c >= L'А' && c <= L'Я') || (c >= L'а' && c <= L'я') ||
		      c == L'І' || c == L'і' || c == L'Ї' || c == L'ї' ||
			  c == L'Є' || c == L'є' || c == L' '))
		{
			return false;
		}
	}
	return true;
}


bool TForm8::IsUniqueValue(String field, String value)
{
	AnsiString queryStr = "SELECT COUNT(*) FROM school WHERE " + field + " = :value";
	TADOQuery *query = new TADOQuery(NULL);
	query->Connection = DataModule1->ADOConnection1;
	query->SQL->Text = queryStr;
	query->Parameters->ParamByName("value")->Value = value;
	query->Open();
	bool isUnique = query->Fields->Fields[0]->AsInteger == 0;
	query->Close();
	delete query;
	return isUnique;
}

void __fastcall TForm8::LabeledEdit1Exit(TObject *Sender)
{
	String input = LabeledEdit1->Text;
	if (!IsValidUkrainianInput(input))
	{
		ShowMessage("Будь ласка, використовуйте тільки українські символи для назви міста.");
		LabeledEdit1->SetFocus();
		return;
	}
}

void __fastcall TForm8::LabeledEdit2Exit(TObject *Sender)
{
	String input = LabeledEdit2->Text;
	if (!IsValidUkrainianInput(input))
	{
		ShowMessage("Будь ласка, використовуйте тільки українські символи для назви області.");
		LabeledEdit2->SetFocus();
		return;
	}
}

void __fastcall TForm8::LabeledEdit4Exit(TObject *Sender)
{
	String input = LabeledEdit4->Text;
	UnicodeString pattern = "^\\w+([-+.']\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$";
	if (!TRegEx::IsMatch(input, pattern))
	{
		ShowMessage("Введіть дійсний e-mail.");
		LabeledEdit4->SetFocus();
		return;
	}
	if (!IsUniqueValue("Email", input))
	{
		ShowMessage("Такий E-mail вже існує в базі даних.");
		LabeledEdit4->SetFocus();
	}
}

void __fastcall TForm8::LabeledEdit5Exit(TObject *Sender)
{
	String input = LabeledEdit5->Text;
	if (!IsValidUkrainianInput(input))
	{
		ShowMessage("Будь ласка, використовуйте тільки українські символи для ПІБ.");
		LabeledEdit5->SetFocus();
		return;
	}
}

void __fastcall TForm8::Button1Click(TObject *Sender)
{
	if (LabeledEdit1->Text.IsEmpty())
	{
		ShowMessage("Будь ласка, введіть назву міста.");
		LabeledEdit1->SetFocus();
		return;
	}
	if (LabeledEdit2->Text.IsEmpty())
	{
		ShowMessage("Будь ласка, введіть назву області.");
		LabeledEdit2->SetFocus();
		return;
	}
	if (LabeledEdit4->Text.IsEmpty())
	{
		ShowMessage("Будь ласка, введіть E-mail.");
		LabeledEdit4->SetFocus();
		return;
	}
	if (LabeledEdit5->Text.IsEmpty())
	{
		ShowMessage("Будь ласка, введіть ПІБ.");
		LabeledEdit5->SetFocus();
		return;
	}
	if (ComboBox1->ItemIndex == -1)
	{
		ShowMessage("Будь ласка, виберіть тип навчального закладу.");
		ComboBox1->SetFocus();
		return;
	}
	AnsiString queryStr;
	if (id > 0)
	{
		queryStr = "UPDATE school SET City = :City, Region = :Region, Type = :Type, Email = :Email, Teacher_PIB = :Teacher_PIB WHERE School_id = :id";
	}
	else
	{
		queryStr = "INSERT INTO school (City, Region, Type, Email, Teacher_PIB) VALUES (:City, :Region, :Type, :Email, :Teacher_PIB)";
	}
	TADOQuery *query = new TADOQuery(NULL);
	query->Connection = DataModule1->ADOConnection1;
	query->SQL->Text = queryStr;
	query->Parameters->ParamByName("City")->Value = LabeledEdit1->Text;
	query->Parameters->ParamByName("Region")->Value = LabeledEdit2->Text;
	query->Parameters->ParamByName("Type")->Value = ComboBox1->Text;
	query->Parameters->ParamByName("Email")->Value = LabeledEdit4->Text;
	query->Parameters->ParamByName("Teacher_PIB")->Value = LabeledEdit5->Text;
	if (id > 0)
		query->Parameters->ParamByName("id")->Value = id;
	query->ExecSQL();
	delete query;
	DataModule1->ADOTable3->Close();
	DataModule1->ADOTable3->Open();
	Close();
}

//---------------------------------------------------------------------------

void __fastcall TForm8::FormShow(TObject *Sender)
{
  if(id>0) ComboBox1->SetFocus();
}
//---------------------------------------------------------------------------

