#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Data.h"
#include <DateUtils.hpp>
#include <System.RegularExpressions.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TForm1::set_id(int k) {
    id = k;
}

void __fastcall TForm1::LoadStudentData(int student_id)
{
	TADOQuery *query = new TADOQuery(this);
    query->Connection = DataModule1->ADOConnection1;

    query->SQL->Text = "SELECT * FROM student WHERE Student_id = :Student_id";
    query->Parameters->ParamByName("Student_id")->Value = student_id;

    try {
        query->Open();

		if (!query->Eof) {
            Edit2->Text = query->FieldByName("Passport_num")->AsString;
            ComboBox1->Text = query->FieldByName("Passport_type")->AsString;
            Edit1->Text = query->FieldByName("PIB")->AsString;
            DatePicker1->Date = query->FieldByName("Birth_date")->AsDateTime;
            RadioGroup1->ItemIndex = (query->FieldByName("Gender")->AsString == "M") ? 0 : 1;
            Edit5->Text = query->FieldByName("Email")->AsString;
            Edit3->Text = query->FieldByName("Phone_num")->AsString;
            Edit6->Text = query->FieldByName("EduCerf_num")->AsString;
            Edit4->Text = query->FieldByName("PN")->AsString;
            Edit7->Text = query->FieldByName("Additional")->AsString;
        } else {
            ShowMessage("Студента з вказаним ID не знайдено.");
        }
    }
    __finally {
        query->Close();
        delete query;
    }
}

void __fastcall TForm1::FormShow(TObject *Sender)
{
    if (id == 0) {
		Form1->Caption = "Додавання даних";
		Button1->Caption = "Додати";
		ClearFields();
    } else {
        Form1->Caption = "Редагування даних";
        LoadStudentData(id);
	}
}

void __fastcall TForm1::Edit2Exit(TObject *Sender)
{
	if (Edit2->Text.Length() < 8 || Edit2->Text.Length() > 20) {
		ShowMessage("Номер паспорта повинен бути від 8 до 20 символів.");
		Edit2->SetFocus();
		return;
	}
	TADOQuery *checkQuery = new TADOQuery(this);
	checkQuery->Connection = DataModule1->ADOConnection1;
	checkQuery->SQL->Text = "SELECT COUNT(*) AS Cnt FROM student WHERE Passport_num = :Passport_num AND (Student_id <> :Student_id OR :Student_id IS NULL)";
	checkQuery->Parameters->ParamByName("Passport_num")->Value = Edit2->Text;
	checkQuery->Parameters->ParamByName("Student_id")->Value = id;
	checkQuery->Open();
	if (checkQuery->FieldByName("Cnt")->AsInteger > 0)
	{
		ShowMessage("Цей номер паспорта вже існує.");
		Edit2->SetFocus();
	}
	checkQuery->Close();
	delete checkQuery;
}

void __fastcall TForm1::Edit3Exit(TObject *Sender)
{
	if (Edit3->Text.Length() < 10 || Edit3->Text.Length() > 15) {
		ShowMessage("Номер телефону повинен бути від 10 до 15 символів.");
		Edit3->SetFocus();
		return;
	}
	TADOQuery *checkQuery = new TADOQuery(this);
	checkQuery->Connection = DataModule1->ADOConnection1;
	checkQuery->SQL->Text = "SELECT COUNT(*) AS Cnt FROM student WHERE Phone_num = :Phone_num AND (Student_id <> :Student_id OR :Student_id IS NULL)";
	checkQuery->Parameters->ParamByName("Phone_num")->Value = Edit3->Text;
	checkQuery->Parameters->ParamByName("Student_id")->Value = id;
	checkQuery->Open();
	if (checkQuery->FieldByName("Cnt")->AsInteger > 0)
	{
		ShowMessage("Цей номер телефону вже існує.");
		Edit3->SetFocus();
	}
	checkQuery->Close();
	delete checkQuery;
}

void __fastcall TForm1::Edit4Exit(TObject *Sender)
{
	if (Edit4->Text.Length() != 10) {
		ShowMessage("ІПН повинен містити 10 цифр.");
		Edit4->SetFocus();
		return;
	}
	TADOQuery *checkQuery = new TADOQuery(this);
	checkQuery->Connection = DataModule1->ADOConnection1;
	checkQuery->SQL->Text = "SELECT COUNT(*) AS Cnt FROM student WHERE PN = :PN AND (Student_id <> :Student_id OR :Student_id IS NULL)";
	checkQuery->Parameters->ParamByName("PN")->Value = Edit4->Text;
	checkQuery->Parameters->ParamByName("Student_id")->Value = id;
	checkQuery->Open();
	if (checkQuery->FieldByName("Cnt")->AsInteger > 0)
	{
		ShowMessage("Цей ІПН вже існує.");
		Edit4->SetFocus();
	}
	checkQuery->Close();
	delete checkQuery;
}


void __fastcall TForm1::Edit5Exit(TObject *Sender)
{
    String email = Edit5->Text;
    UnicodeString pattern = "^\\w+([-+.']\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$";

    if (!TRegEx::IsMatch(email, pattern)) {
        ShowMessage("Введіть дійсний e-mail.");
		Edit5->SetFocus();
		return;
	}
	TADOQuery *checkQuery = new TADOQuery(this);
	checkQuery->Connection = DataModule1->ADOConnection1;
	checkQuery->SQL->Text = "SELECT COUNT(*) AS Cnt FROM student WHERE Email = :Email AND (Student_id <> :Student_id OR :Student_id IS NULL)";
	checkQuery->Parameters->ParamByName("Email")->Value = Edit5->Text;
	checkQuery->Parameters->ParamByName("Student_id")->Value = id;
	checkQuery->Open();
	if (checkQuery->FieldByName("Cnt")->AsInteger > 0)
	{
		ShowMessage("Цей e-mail вже існує.");
		Edit5->SetFocus();
	}
	checkQuery->Close();
	delete checkQuery;
}

void __fastcall TForm1::Edit6Exit(TObject *Sender)
{
	if (Edit6->Text.IsEmpty()) {
        ShowMessage("Поле сертифікату освіти не може бути пустим.");
        Edit6->SetFocus();
        return;
	}
	TADOQuery *checkQuery = new TADOQuery(this);
	checkQuery->Connection = DataModule1->ADOConnection1;
	checkQuery->SQL->Text = "SELECT COUNT(*) AS Cnt FROM student WHERE EduCerf_num = :EduCerf_num AND (Student_id <> :Student_id OR :Student_id IS NULL)";
	checkQuery->Parameters->ParamByName("EduCerf_num")->Value = Edit6->Text;
	checkQuery->Parameters->ParamByName("Student_id")->Value = id;
	checkQuery->Open();
	if (checkQuery->FieldByName("Cnt")->AsInteger > 0)
	{
		ShowMessage("Цей номер сертифіката про освіту вже існує.");
		Edit6->SetFocus();
	}
	checkQuery->Close();
	delete checkQuery;
}


void __fastcall TForm1::DatePicker1CloseUp(TObject *Sender)
{
	try
	{
		TDateTime selectedDate = DatePicker1->Date;
		TDateTime currentDate = Now();
		if (selectedDate > currentDate)
		{
			throw Exception("Дата не може бути в майбутньому!");
		}
		else if (selectedDate < EncodeDate(1925, 1, 1))
		{
			throw Exception("Дата занадто стара! Виберіть пізнішу дату.");
		}
		int birthYear = YearOf(selectedDate);
		int currentYear = YearOf(currentDate);
		int yearsDiff = currentYear - birthYear;
		if (currentDate < EncodeDate(currentYear, MonthOf(selectedDate), DayOf(selectedDate)))
		{
			yearsDiff--;
		}
		if (yearsDiff < 16)
		{
			throw Exception("Для здачі НМТ потрібно мати мінімум 16 років.");
		}
	}
	catch (const Exception &e)
	{
		ShowMessage(e.Message);
		DatePicker1->Date = Now();
	}
}



void __fastcall TForm1::ComboBox1CloseUp(TObject *Sender)
{
	if (ComboBox1->Text.IsEmpty() || ComboBox1->ItemIndex == -1) {
		ShowMessage("Будь ласка, оберіть тип паспорта.");
        ComboBox1->SetFocus();
    }
}

void __fastcall TForm1::RadioGroup1Exit(TObject *Sender)
{
	if (RadioGroup1->ItemIndex == -1) {
		ShowMessage("Будь ласка, оберіть стать.");
		RadioGroup1->SetFocus();
	}
}

bool TForm1::IsAllDigits(const String& str)
{
    for (int i = 1; i <= str.Length(); ++i)
    {
		if (!isdigit(str[i]))
            return false;
	}
    return true;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (Edit2->Text.IsEmpty() || ComboBox1->Text.IsEmpty() || Edit1->Text.IsEmpty() ||
		DatePicker1->Date > Date() || Edit5->Text.IsEmpty() || Edit3->Text.IsEmpty() ||
		Edit6->Text.IsEmpty() || Edit4->Text.IsEmpty() || RadioGroup1->ItemIndex == -1)
	{
		ShowMessage("Не всі обов'язкові поля заповнені.");
		return;
	}
	if (ComboBox1->Text != "ID-карта" && ComboBox1->Text != "Паперовий")
	{
		ShowMessage("Невірний тип паспорта. Допустимі значення: 'ID-карта' або 'Паперовий'.");
        return;
	}
	if (!Edit3->Text.IsEmpty() && !IsAllDigits(Edit3->Text))
    {
		ShowMessage("Телефонний номер повинен містити тільки цифри.");
        return;
	}
	TADOQuery *query = new TADOQuery(this);
	query->Connection = DataModule1->ADOConnection1;
	try {
		if(id == 0) {
			query->SQL->Text = "INSERT INTO student (Passport_num, Passport_type, PIB, Birth_date, Gender, Email, Phone_num, EduCerf_num, PN, Additional) "
							   "VALUES (:Passport_num, :Passport_type, :PIB, :Birth_date, :Gender, :Email, :Phone_num, :EduCerf_num, :PN, :Additional)";
		} else {
			query->SQL->Text = "UPDATE student SET Passport_num = :Passport_num, Passport_type = :Passport_type, PIB = :PIB, "
			                   "Birth_date = :Birth_date, Gender = :Gender, Email = :Email, Phone_num = :Phone_num, "
							   "EduCerf_num = :EduCerf_num, PN = :PN, Additional = :Additional WHERE Student_id = :Student_id";
			query->Parameters->ParamByName("Student_id")->Value = id;
		}

		query->Parameters->ParamByName("Passport_num")->Value = Edit2->Text;
		query->Parameters->ParamByName("Passport_type")->Value = ComboBox1->Text;
		query->Parameters->ParamByName("PIB")->Value = Edit1->Text;
		TDate birthDate = DatePicker1->Date;
		String birthDateString = birthDate.FormatString("yyyy-mm-dd");
		query->Parameters->ParamByName("Birth_date")->Value = birthDateString;
		query->Parameters->ParamByName("Gender")->Value = (RadioGroup1->ItemIndex == 0) ? "M" : "F";
		query->Parameters->ParamByName("Email")->Value = Edit5->Text;
		query->Parameters->ParamByName("Phone_num")->Value = Edit3->Text;
		query->Parameters->ParamByName("EduCerf_num")->Value = Edit6->Text;
		query->Parameters->ParamByName("PN")->Value = Edit4->Text;
		query->Parameters->ParamByName("Additional")->Value = Edit7->Text;

		query->ExecSQL();
		ShowMessage(id == 0 ? "Дані успішно додані!" : "Дані успішно оновлені!");
	}
	__finally {
		delete query;
	}
	DataModule1->DataSource1->DataSet->Close();
	DataModule1->DataSource1->DataSet->Open();
	Close();
}



 void TForm1::ClearFields()
{
	Edit1->Text = "";
	Edit2->Text = "";
	Edit3->Text = "";
	Edit4->Text = "";
    Edit5->Text = "";
	Edit6->Text = "";
	Edit7->Text = "";
	ComboBox1->ItemIndex = -1;
	DatePicker1->Date = Now();
    RadioGroup1->ItemIndex = -1;
}

void __fastcall TForm1::Edit1Exit(TObject *Sender)
{
	String pib = Edit1->Text;
    UnicodeString pattern = "^[А-ЯІЇЄҐа-яіїєґ' ]+$";

    // Перевірка на коректність введених даних
    if (!TRegEx::IsMatch(pib, pattern)) {
        ShowMessage("ПІБ повинен містити лише українські літери.");
		Edit1->SetFocus();
        return;
    }

    // Перевірка на унікальність ПІБ
    TADOQuery *checkQuery = new TADOQuery(this);
    checkQuery->Connection = DataModule1->ADOConnection1;

    // SQL-запит для перевірки наявності ПІБ в базі, виключаючи поточного студента
    checkQuery->SQL->Text = "SELECT COUNT(*) AS Cnt FROM student WHERE PIB = :PIB AND (Student_id <> :Student_id OR :Student_id IS NULL)";
	checkQuery->Parameters->ParamByName("PIB")->Value = Edit1->Text;
    checkQuery->Parameters->ParamByName("Student_id")->Value = id; // Виключаємо поточного студента

    try {
        checkQuery->Open();
        if (checkQuery->FieldByName("Cnt")->AsInteger > 0) {
            ShowMessage("Студент з таким ПІБ вже існує.");
            Edit1->SetFocus();
        }
    }
    __finally {
        checkQuery->Close();
        delete checkQuery;
    }
}

//---------------------------------------------------------------------------

