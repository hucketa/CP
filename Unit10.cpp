//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit10.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm10 *Form10;
//---------------------------------------------------------------------------
__fastcall TForm10::TForm10(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm10::LabeledEdit1SubLabelClick(TObject *Sender)
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
void __fastcall TForm10::LabeledEdit1Exit(TObject *Sender)
{
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
//---------------------------------------------------------------------------
void __fastcall TForm10::LabeledEdit2Exit(TObject *Sender)
{
	try
	{
		String enteredPIN = LabeledEdit2->Text.Trim();

		if (enteredPIN.IsEmpty())
		{
			throw Exception("Поле PIN не може бути порожнім!");
		}

		TADOQuery *query = new TADOQuery(NULL);
		try
		{
			query->Connection = DataModule1->ADOConnection1;
			query->SQL->Text = "SELECT COUNT(*) AS Count FROM certificate WHERE PIN = :EnteredPIN";
			query->Parameters->ParamByName("EnteredPIN")->Value = enteredPIN;
			query->Open();

			int count = query->FieldByName("Count")->AsInteger;

			if (count > 0)
			{
				throw Exception("Цей PIN вже існує в базі даних! Введіть інший.");
			}
		}
		__finally
		{
			delete query;
		}
	}
	catch (const Exception &e)
	{
		ShowMessage(e.Message);
	}
}

//---------------------------------------------------------------------------
void __fastcall TForm10::DatePicker2CloseUp(TObject *Sender)
{
	try
	{
		TDateTime creationDate = DatePicker1->Date;
		TDateTime registrationDate = DatePicker2->Date;
		if (registrationDate < EncodeDate(1990, 1, 1))
		{
			throw Exception("Дата реєстрації повинна бути не ранішою за 01.01.1990!");
		}
		if (registrationDate <= creationDate)
		{
			throw Exception("Дата реєстрації повинна бути пізніше за дату створення!");
		}
	}
	catch (const Exception &e)
	{
		ShowMessage("Помилка: " + e.Message);
	}


}

void TForm10::set_id(int k)
{
	id = k;

	if (id == 0)
	{
		LabeledEdit1->Text = "";
		LabeledEdit2->Text = "";
		RadioGroup1->ItemIndex = -1;
		TDateTime defaultDate = EncodeDate(1990, 1, 1);
		DatePicker1->Date = defaultDate;
		DatePicker2->Date = defaultDate;
		Form10->Caption = "Додавання даних";
	}
	else
	{
		TADOQuery *query = new TADOQuery(NULL);
		try
		{
			query->Connection = DataModule1->ADOConnection1;
			query->SQL->Text = "SELECT c.PIN, c.Status, c.Creation_date, c.Effect_time, s.PIB "
							   "FROM certificate c "
							   "JOIN student s ON c.Student_id = s.Student_id "
							   "WHERE c.Cerf_num = :id";
			query->Parameters->ParamByName("id")->Value = id;
			query->Open();

			if (!query->Eof)
			{
				LabeledEdit1->Text = query->FieldByName("PIB")->AsString;
				LabeledEdit2->Text = query->FieldByName("PIN")->AsString;

				int status = query->FieldByName("Status")->AsInteger;
				if (status == 1)
				{
					RadioGroup1->ItemIndex = 0;
				}
				else
				{
					RadioGroup1->ItemIndex = 1;
				}

				DatePicker2->Date = query->FieldByName("Effect_time")->AsDateTime;
				DatePicker1->Date = query->FieldByName("Creation_date")->AsDateTime;
			}
		}
		__finally
		{
			delete query;
		}
		Form10->Caption = "Редагування даних";
	}
}





//---------------------------------------------------------------------------
void __fastcall TForm10::DatePicker1CloseUp(TObject *Sender)
{
	try
	{
		TDateTime selectedDate = DatePicker1->Date;
		TDateTime currentDate = Now();
		if (selectedDate > currentDate)
		{
			throw Exception("Дата не може бути в майбутньому!");
		}
		else if (selectedDate < EncodeDate(1990, 1, 1))
		{
			throw Exception("Дата занадто стара! Виберіть пізнішу дату.");
		}
	}
	catch (const Exception &e)
	{
		ShowMessage("Помилка: " + e.Message);
	}
}


//---------------------------------------------------------------------------
void __fastcall TForm10::FormCreate(TObject *Sender)
{
	TDateTime date = EncodeDate(1990, 1, 1);
	DatePicker1->Date = date;
	DatePicker2->Date = date;
}
//---------------------------------------------------------------------------
void __fastcall TForm10::Button1Click(TObject *Sender)
{
	try
	{
		String pib = LabeledEdit1->Text.Trim();
		String pin = LabeledEdit2->Text.Trim();
		TDateTime creationDate = DatePicker1->Date;
		TDateTime effectTime = DatePicker2->Date;
		int status = RadioGroup1->ItemIndex == 0 ? 1 : 0;
		if (pib.IsEmpty())
		{
			throw Exception("Поле ПІБ не може бути порожнім!");
		}
		if (pin.IsEmpty())
		{
			throw Exception("Поле PIN не може бути порожнім!");
		}
		if (effectTime > creationDate)
		{
			throw Exception("Дата реєстрації повинна бути пізніше за дату створення!");
		}
		TADOQuery *query = new TADOQuery(NULL);
		try
		{
			query->Connection = DataModule1->ADOConnection1;
			query->SQL->Text = "SELECT Student_id FROM student WHERE PIB = :pib";
			query->Parameters->ParamByName("pib")->Value = pib;
			query->Open();

			if (query->Eof)
			{
				throw Exception("ПІБ не знайдений у базі даних.");
			}

			int student_id = query->FieldByName("Student_id")->AsInteger;
			query->Close();

			// Перетворення дат у формат MySQL 'yyyy-mm-dd'
			String creationDateStr = creationDate.FormatString("yyyy-mm-dd");
			String effectTimeStr = effectTime.FormatString("yyyy-mm-dd");

			// Додавання або редагування запису в таблиці certificate
			if (id == 0) // Додавання нового запису
			{
				query->SQL->Text = "INSERT INTO certificate (Student_id, PIN, Creation_date, Effect_time, Status) "
								   "VALUES (:student_id, :pin, :creationDate, :effectTime, :status)";
			}
			else // Редагування існуючого запису
			{
				query->SQL->Text = "UPDATE certificate SET Student_id = :student_id, PIN = :pin, Creation_date = :creationDate, "
								   "Effect_time = :effectTime, Status = :status WHERE Cerf_num = :id";
				query->Parameters->ParamByName("id")->Value = id;
			}

			query->Parameters->ParamByName("student_id")->Value = student_id;
			query->Parameters->ParamByName("pin")->Value = pin;
			query->Parameters->ParamByName("creationDate")->Value = creationDateStr;
			query->Parameters->ParamByName("effectTime")->Value = effectTimeStr;
			query->Parameters->ParamByName("status")->Value = status;

			query->ExecSQL();

			ShowMessage("Операція успішно виконана!");
			Form10->Close();
		}
		__finally
		{
			delete query;
		}
	}
	catch (const Exception &e)
	{
		ShowMessage("Помилка: " + e.Message);
	}
	DataModule1->ADOQuery4->Close();
	DataModule1->ADOQuery4->Open();
}


//---------------------------------------------------------------------------
