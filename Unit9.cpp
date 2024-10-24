#include <vcl.h>
#pragma hdrstop
#include "Unit9.h"
#include <System.RegularExpressions.hpp>
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9 *Form9;

__fastcall TForm9::TForm9(TComponent* Owner)
	: TForm(Owner)
{
}

void TForm9::set_id(int k) {
	id = k;
	if (id > 0) {
		Button1->Caption = "Замінити";
		AnsiString queryStr = "SELECT r.Subj_id, r.Condition_id, r.Status, st.PIB, r.Reached_score, r.Attemp_date, "
							 "school.Email, c.Date, c.Max_point, c.Min_r_point, c.Min_point "
							 "FROM result r "
		                     "JOIN student st ON r.Student_id = st.Student_id "
							 "JOIN school ON r.School_id = school.School_id "
							 "JOIN conditions c ON r.Condition_id = c.Condition_id "
							 "WHERE r.Res_id = :id";
		TADOQuery *query = new TADOQuery(NULL);
		query->Connection = DataModule1->ADOConnection1;
		query->SQL->Text = queryStr;
		query->Parameters->ParamByName("id")->Value = id;
		query->Open();

		if (!query->Eof) {
			LabeledEdit1->Text = query->FieldByName("PIB")->AsString;
			LabeledEdit4->Text = query->FieldByName("Reached_score")->AsString;
			int subject_id = query->FieldByName("Subj_id")->AsInteger;
			ComboBox1->ItemIndex = subject_id - 1;
			DatePicker2->Date = query->FieldByName("Date")->AsDateTime;
			String email = query->FieldByName("Email")->AsString;
			ComboBox2->ItemIndex = ComboBox2->Items->IndexOf(email);
			int status = query->FieldByName("Status")->AsInteger;
			RadioGroup1->ItemIndex = (status == 1) ? 0 : 1;
			int maxPoint = query->FieldByName("Max_point")->AsInteger;
			int minPassPoint = query->FieldByName("Min_r_point")->AsInteger;
			int minPoint = query->FieldByName("Min_point")->AsInteger;
			Label5->Caption = "Максимальний: " + IntToStr(maxPoint);
			Label7->Caption = "Прохідний: " + IntToStr(minPassPoint);
			Label6->Caption = "Мінімальний: " + IntToStr(minPoint);
		}

		query->Close();
		delete query;
		Form9->Caption = "Редагування даних";
	} else {
		Button1->Caption = "Додати";
		LabeledEdit1->Text = "";
		LabeledEdit4->Text = "";
		ComboBox1->ItemIndex = -1;
		ComboBox2->ItemIndex = -1;
		DatePicker2->Date = EncodeDate(1990, 1, 1);
		RadioGroup1->ItemIndex = -1;
		Label5->Caption = "Максимальний: -";
		Label7->Caption = "Прохідний: -";
		Label6->Caption = "Мінімальний: -";
		Form9->Caption = "Додавання даних";
	}
}

void __fastcall TForm9::FormCreate(TObject *Sender) {
	if (id == 0) {
		TDateTime checkDate = EncodeDate(1990, 1, 1);
		DatePicker2->Date = checkDate;
	}
	RadioGroup1->Enabled = false;
	ComboBox1->Clear();
	ComboBox2->Clear();
	TADOQuery *query = new TADOQuery(this);
	query->Connection = DataModule1->ADOConnection1;
	try {
		query->SQL->Text = "SELECT Name FROM subject ORDER BY Subject_id";
		query->Open();
		while (!query->Eof) {
			ComboBox1->Items->Add(query->FieldByName("Name")->AsString);
			query->Next();
		}
		query->Close();
		query->SQL->Text = "SELECT Email FROM school ORDER BY School_id";
		query->Open();
		while (!query->Eof) {
			ComboBox2->Items->Add(query->FieldByName("Email")->AsString);
			query->Next();
		}
	} __finally {
		query->Close();
		delete query;
	}
}

void __fastcall TForm9::LabeledEdit1Exit(TObject *Sender) {
	String pib = LabeledEdit1->Text;
	UnicodeString pattern = "^[А-ЯІЇЄҐа-яіїєґ' ]+$";
	if (!TRegEx::IsMatch(pib, pattern)) {
		ShowMessage("ПІБ повинен містити лише українські літери.");
		return;
	}
	TADOQuery *query = new TADOQuery(NULL);
	query->Connection = DataModule1->ADOConnection1;
	query->SQL->Text = "SELECT COUNT(*) AS count FROM student WHERE PIB = :pib";
	query->Parameters->ParamByName("pib")->Value = pib;
	query->Open();
	int count = query->FieldByName("count")->AsInteger;
	if (count == 0) {
		ShowMessage("ПІБ не знайдений у базі даних.");
		query->Close();
		delete query;
		return;
	}
	query->Close();
	delete query;
}

void __fastcall TForm9::DatePicker2CloseUp(TObject *Sender) {
	if (ComboBox1->ItemIndex == -1) {
		ShowMessage("Будь ласка, виберіть предмет.");
		return;
	}
	int subject_id = ComboBox1->ItemIndex + 1;
	TDateTime selectedDate = DatePicker2->Date;
	String formattedDate = selectedDate.FormatString("yyyy-mm-dd");

	// Виведення значень для відладки
	ShowMessage("Selected Subject ID: " + IntToStr(subject_id) + ", Selected Date: " + formattedDate);

	TADOQuery *query = new TADOQuery(NULL);
	query->Connection = DataModule1->ADOConnection1;
	query->SQL->Text = "SELECT Max_point, Min_r_point, Min_point FROM conditions WHERE Date = :date AND Subject_id = :subject_id";
	query->Parameters->ParamByName("date")->Value = selectedDate;
	query->Parameters->ParamByName("subject_id")->Value = subject_id;
	query->Open();

	if (!query->Eof) {
		int maxPoint = query->FieldByName("Max_point")->AsInteger;
		int minPassPoint = query->FieldByName("Min_r_point")->AsInteger;
		int minPoint = query->FieldByName("Min_point")->AsInteger;

		// Виведення значень для відладки
		ShowMessage("Max Point: " + IntToStr(maxPoint) + ", Min Passing Point: " + IntToStr(minPassPoint) + ", Min Point: " + IntToStr(minPoint));

		Label5->Caption = "Максимальний: " + IntToStr(maxPoint);
		Label7->Caption = "Прохідний: " + IntToStr(minPassPoint);
		Label6->Caption = "Мінімальний: " + IntToStr(minPoint);
	} else {
		ShowMessage("Для вибраної дати та предмета немає даних у таблиці conditions.");
		Label5->Caption = "Максимальний: -";
		Label7->Caption = "Прохідний: -";
		Label6->Caption = "Мінімальний: -";
	}

	query->Close();
	delete query;
}

void __fastcall TForm9::DatePicker1CloseUp(TObject *Sender) {
	try {
		TDateTime selectedDate = DatePicker1->Date;
		TDateTime currentDate = Now();
		if (selectedDate > currentDate) {
			throw Exception("Дата не може бути в майбутньому!");
		} else if (selectedDate < EncodeDate(1990, 1, 1)) {
			throw Exception("Дата занадто стара! Виберіть пізнішу дату.");
		}
	} catch (const Exception &e) {
		ShowMessage(e.Message);
		DatePicker1->Date = Now();
	}
}

void __fastcall TForm9::LabeledEdit4Exit(TObject *Sender) {
	TDateTime checkDate = EncodeDate(1990, 1, 1);
	if (ComboBox1->ItemIndex == -1 || DatePicker2->Date == checkDate) {
		ShowMessage("Будь ласка, виберіть предмет та дату укладання вимог.");
		return;
	}
	int subject_id = ComboBox1->ItemIndex + 1;
	TDateTime conditionDate = DatePicker2->Date;
	String enteredScoreStr = LabeledEdit4->Text;
	int enteredScore = enteredScoreStr.ToIntDef(-1);

	// Виведення значень для відладки
	ShowMessage("Entered Score: " + IntToStr(enteredScore) + ", Subject ID: " + IntToStr(subject_id) + ", Condition Date: " + conditionDate.FormatString("yyyy-mm-dd"));

	if (enteredScore == -1) {
		ShowMessage("Будь ласка, введіть коректне значення балу.");
		return;
	}

	String formattedDate = conditionDate.FormatString("yyyy-mm-dd");

	TADOQuery *query = new TADOQuery(NULL);
	query->Connection = DataModule1->ADOConnection1;
	query->SQL->Text = "SELECT Max_point, Min_r_point, Min_point FROM conditions WHERE Subject_id = :subject_id AND Date = :date";
	query->Parameters->ParamByName("subject_id")->Value = subject_id;
	query->Parameters->ParamByName("date")->Value = formattedDate;
	query->Open();

	if (!query->Eof) {
		int maxPoint = query->FieldByName("Max_point")->AsInteger;
		int minPassPoint = query->FieldByName("Min_r_point")->AsInteger;
		int minPoint = query->FieldByName("Min_point")->AsInteger;
		ShowMessage("Max Point: " + IntToStr(maxPoint) + ", Min Passing Point: " + IntToStr(minPassPoint) + ", Min Point: " + IntToStr(minPoint));

		if (enteredScore < minPoint) {
			ShowMessage("Введений бал менший за мінімальний.");
		} else if (enteredScore > maxPoint) {
			ShowMessage("Введений бал більший за максимальний.");
		} else {
			if (enteredScore >= minPassPoint) {
				RadioGroup1->ItemIndex = 0;
			} else {
				RadioGroup1->ItemIndex = 1;
			}
		}
	} else {
		ShowMessage("Вимоги для цього предмета та дати не знайдені.");
	}
	query->Close();
	delete query;
}

void __fastcall TForm9::ComboBox1CloseUp(TObject *Sender) {
	if (ComboBox1->ItemIndex == -1) {
		ShowMessage("Будь ласка, виберіть предмет.");
		return;
	}
	if (DatePicker2->Date == EncodeDate(1990, 1, 1)) {
		ShowMessage("Будь ласка, виберіть дату.");
		return;
	}
	int subject_id = ComboBox1->ItemIndex + 1;
	TDateTime selectedDate = DatePicker2->Date;
	String formattedDate = selectedDate.FormatString("yyyy-mm-dd");
	ShowMessage("Selected Subject ID: " + IntToStr(subject_id) + ", Selected Date: " + formattedDate);

	TADOQuery *query = new TADOQuery(NULL);
	query->Connection = DataModule1->ADOConnection1;
	query->SQL->Text = "SELECT Max_point, Min_r_point, Min_point FROM conditions WHERE Date = :date AND Subject_id = :subject_id";
	query->Parameters->ParamByName("date")->Value = formattedDate;
	query->Parameters->ParamByName("subject_id")->Value = subject_id;
	query->Open();

	if (!query->Eof) {
		int maxPoint = query->FieldByName("Max_point")->AsInteger;
		int minPassPoint = query->FieldByName("Min_r_point")->AsInteger;
		int minPoint = query->FieldByName("Min_point")->AsInteger;
		ShowMessage("Max Point: " + IntToStr(maxPoint) + ", Min Passing Point: " + IntToStr(minPassPoint) + ", Min Point: " + IntToStr(minPoint));

		Label5->Caption = "Максимальний: " + IntToStr(maxPoint);
		Label7->Caption = "Прохідний: " + IntToStr(minPassPoint);
		Label6->Caption = "Мінімальний: " + IntToStr(minPoint);
	} else {
		ShowMessage("Для вибраної дати та предмета немає даних у таблиці conditions.");
		Label5->Caption = "Максимальний: -";
		Label7->Caption = "Прохідний: -";
		Label6->Caption = "Мінімальний: -";
	}

	query->Close();
	delete query;
}

void __fastcall TForm9::Button1Click(TObject *Sender)
{
	if (LabeledEdit1->Text.Trim() == "") {
		ShowMessage("Будь ласка, введіть ПІБ.");
		return;
	}
	if (LabeledEdit4->Text.Trim() == "") {
		ShowMessage("Будь ласка, введіть результат.");
		return;
	}
	if (ComboBox1->ItemIndex == -1) {
		ShowMessage("Будь ласка, виберіть навчальну дисципліну.");
		return;
	}
	if (DatePicker2->Date == EncodeDate(1990, 1, 1)) {
		ShowMessage("Будь ласка, виберіть дату укладання умов.");
		return;
	}
	int subject_id = ComboBox1->ItemIndex + 1;
	TDateTime selectedDate = DatePicker2->Date;
	String formattedDate = selectedDate.FormatString("yyyy-mm-dd");
	int reachedScore = LabeledEdit4->Text.ToIntDef(-1);
	int status = RadioGroup1->ItemIndex == 0 ? 1 : 0;
	TADOQuery *studentQuery = new TADOQuery(NULL);
	studentQuery->Connection = DataModule1->ADOConnection1;
	studentQuery->SQL->Text = "SELECT Student_id FROM student WHERE PIB = :pib";
	studentQuery->Parameters->ParamByName("pib")->Value = LabeledEdit1->Text;
	studentQuery->Open();
	int student_id = -1;
	if (!studentQuery->Eof) {
		student_id = studentQuery->FieldByName("Student_id")->AsInteger;
	} else {
		ShowMessage("Студента з таким ПІБ не знайдено.");
		studentQuery->Close();
		delete studentQuery;
		return;
	}
	studentQuery->Close();
	delete studentQuery;
	TADOQuery *schoolQuery = new TADOQuery(NULL);
	schoolQuery->Connection = DataModule1->ADOConnection1;
	schoolQuery->SQL->Text = "SELECT School_id FROM school WHERE Email = :email";
	schoolQuery->Parameters->ParamByName("email")->Value = ComboBox2->Text;
	schoolQuery->Open();
	int school_id = -1;
	if (!schoolQuery->Eof) {
		school_id = schoolQuery->FieldByName("School_id")->AsInteger;
	} else {
		ShowMessage("Школу з таким Email не знайдено.");
		schoolQuery->Close();
		delete schoolQuery;
		return;
	}
	schoolQuery->Close();
	delete schoolQuery;

	// Одержуємо condition_id на основі предмету та дати
	TADOQuery *conditionQuery = new TADOQuery(NULL);
	conditionQuery->Connection = DataModule1->ADOConnection1;
	conditionQuery->SQL->Text = "SELECT Condition_id FROM conditions WHERE Subject_id = :subject_id AND Date = :date";
	conditionQuery->Parameters->ParamByName("subject_id")->Value = subject_id;
	conditionQuery->Parameters->ParamByName("date")->Value = formattedDate;
	conditionQuery->Open();
	int condition_id = -1;
	if (!conditionQuery->Eof) {
		condition_id = conditionQuery->FieldByName("Condition_id")->AsInteger;
	} else {
		ShowMessage("Не знайдено умов для вибраного предмету та дати.");
		conditionQuery->Close();
		delete conditionQuery;
		return;
	}
	conditionQuery->Close();
	delete conditionQuery;
	TADOQuery *query = new TADOQuery(NULL);
	query->Connection = DataModule1->ADOConnection1;

	if (id > 0) {
		query->SQL->Text = "UPDATE result SET Subj_id = :subj_id, Reached_score = :reached_score, Status = :status, Attemp_date = :attemp_date "
						   "WHERE Res_id = :id";
		query->Parameters->ParamByName("id")->Value = id;
	} else {
		query->SQL->Text = "INSERT INTO result (Subj_id, Condition_id, Student_id, Reached_score, Status, School_id, Attemp_date) "
						   "VALUES (:subj_id, :condition_id, :student_id, :reached_score, :status, :school_id, :attemp_date)";
		query->Parameters->ParamByName("student_id")->Value = student_id;
		query->Parameters->ParamByName("school_id")->Value = school_id;
		query->Parameters->ParamByName("condition_id")->Value = condition_id;
	}
	query->Parameters->ParamByName("subj_id")->Value = subject_id;
	query->Parameters->ParamByName("reached_score")->Value = reachedScore;
	query->Parameters->ParamByName("status")->Value = status;
	query->Parameters->ParamByName("attemp_date")->Value = DatePicker2->Date.FormatString("yyyy-mm-dd");

	try {
		query->ExecSQL();
		ShowMessage("Запис успішно збережено.");
	} catch (Exception &e) {
		ShowMessage("Помилка збереження запису: " + e.Message);
	}
	DataModule1->ADOQuery3->Close();
	DataModule1->ADOQuery3->Open();
	query->Close();
	delete query;
}



//---------------------------------------------------------------------------

void __fastcall TForm9::LabeledEdit1SubLabelClick(TObject *Sender)
{
	Form14->isMinimalView = true;
	Form14->ToggleView();
	Form14->Update();
	Form14->ShowModal();
	Form14->isMinimalView = false;
	Form14->ToggleView();
	Form14->AutoSize = true;
	Form14->Update();
}




//---------------------------------------------------------------------------




void __fastcall TForm9::Label2Click(TObject *Sender)
{
	Form4->isMinimalView = true;
	Form4->ToggleView();
	Form4->Update();
	Form4->ShowModal();
	Form4->isMinimalView = false;
	Form4->ToggleView();
	Form4->AutoSize = true;
	Form4->Update();
}
//---------------------------------------------------------------------------

