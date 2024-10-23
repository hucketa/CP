//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Results.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm11 *Form11;
//---------------------------------------------------------------------------
__fastcall TForm11::TForm11(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm11::DBColumnSizes() {
	if (DBGrid1->Columns->Count >= 10) {
		DBGrid1->Columns->Items[0]->Visible = false;
		DBGrid1->Columns->Items[1]->Width = 150;
		DBGrid1->Columns->Items[1]->Title->Caption = "ПІБ студента";
		DBGrid1->Columns->Items[2]->Width = 90;
		DBGrid1->Columns->Items[2]->Title->Caption = "Предмет";
		DBGrid1->Columns->Items[3]->Width = 82;
		DBGrid1->Columns->Items[3]->Title->Caption = "Результат";
		DBGrid1->Columns->Items[4]->Width = 82;
		DBGrid1->Columns->Items[4]->Title->Caption = "Максимально";
		DBGrid1->Columns->Items[5]->Width = 82;
		DBGrid1->Columns->Items[5]->Title->Caption = "Прохідний";
		DBGrid1->Columns->Items[6]->Width = 82;
		DBGrid1->Columns->Items[6]->Title->Caption = "Статус";
		DBGrid1->Columns->Items[7]->Width = 82;
		DBGrid1->Columns->Items[7]->Title->Caption = "Дата складання";
		DBGrid1->Columns->Items[8]->Width = 82;
		DBGrid1->Columns->Items[8]->Title->Caption = "Дата укладання умов";
		DBGrid1->Columns->Items[9]->Width = 175;
		DBGrid1->Columns->Items[9]->Title->Caption = "E-mail навчального закладу";
	} else {
		ShowMessage("Недостатньо стовпців у таблиці.");
	}
}




void __fastcall TForm11::FormShow(TObject *Sender)
{
	DBColumnSizes();
	ComboBox2->Clear();
	TADOQuery *query = new TADOQuery(this);
	query->Connection = DataModule1->ADOConnection1;
	try
	{
        query->SQL->Text = "SELECT Name FROM subject ORDER BY Subject_id";
        query->Open();
        while (!query->Eof)
        {
			ComboBox2->Items->Add(query->FieldByName("Name")->AsString);
            query->Next();
        }
	}
    __finally
	{
        query->Close();
        delete query;
	}
}

//---------------------------------------------------------------------------


void __fastcall TForm11::N2Click(TObject *Sender)
{
	Form9->set_id(0);
	Form9->ShowModal();
	DBColumnSizes();
}
//---------------------------------------------------------------------------

void __fastcall TForm11::DatePicker1CloseUp(TObject *Sender)
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
		ShowMessage(e.Message);
		DatePicker1->Date = Now();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm11::LabeledEdit1Exit(TObject *Sender)
{
	String pib = LabeledEdit1->Text;
	UnicodeString pattern = "^[А-ЯІЇЄҐа-яіїєґ' ]+$";
	if (!TRegEx::IsMatch(pib, pattern)) {
		ShowMessage("ПІБ повинен містити лише українські літери.");
		LabeledEdit1->SetFocus();
		return;
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm11::CheckFiltersFilled(TObject *Sender)
{
	bool isAnyFilterFilled = false;
	if (Earlier->Checked || Later->Checked || ThisDate->Checked) isAnyFilterFilled = true;
	if (!LabeledEdit1->Text.Trim().IsEmpty()) isAnyFilterFilled = true;
	if (ComboBox2->ItemIndex >= 0) isAnyFilterFilled = true;
	Execute->Enabled = isAnyFilterFilled;
	Clear->Enabled = isAnyFilterFilled;
}

void __fastcall TForm11::ClearClick(TObject *Sender)
{
    // Очищення полів
    LabeledEdit1->Clear();
    ComboBox2->ItemIndex = -1;
	DatePicker1->Date = Now();
    Earlier->Checked = false;
    Later->Checked = false;
	ThisDate->Checked = false;

    // Скидання фільтра
    DataModule1->ADOQuery3->Filtered = false;
    DataModule1->ADOQuery3->Filter = "";

    // Очищення та перезавантаження даних
    DataModule1->ADOQuery3->Close();
    DataModule1->ADOQuery3->SQL->Clear();

    // Запит для завантаження всіх записів без фільтрів
    DataModule1->ADOQuery3->SQL->Add(
        "SELECT r.Res_id, "
        "st.PIB, "
		"sub.Name, "
		"r.Reached_score, "
        "c.Max_point, "
		"c.Min_r_point, "
        "CASE WHEN r.Status = 1 THEN 'Зараховано' ELSE 'Не зараховано' END AS Status, "
		"r.Attemp_date, "
        "c.Date, "
		"school.Email "
        "FROM result r "
        "JOIN student st ON r.Student_id = st.Student_id "
		"JOIN subject sub ON r.Subj_id = sub.Subject_id "
		"JOIN conditions c ON r.Condition_id = c.Condition_id "
		"JOIN school ON r.School_id = school.School_id "
		"ORDER BY r.Attemp_date DESC");

	DataModule1->ADOQuery3->Open();

    // Деактивація кнопок "Виконати" і "Очистити", оскільки всі поля пусті
	Execute->Enabled = false;
	Clear->Enabled = false;
}



void __fastcall TForm11::ExecuteClick(TObject *Sender)
{
    String query = "SELECT r.Res_id, "
                   "st.PIB, "
                   "sub.Name, "
                   "r.Reached_score, "
                   "c.Max_point, "
                   "c.Min_r_point, "
                   "CASE WHEN r.Status = 1 THEN 'Зараховано' ELSE 'Не зараховано' END AS Status, "
                   "r.Attemp_date, "
                   "c.Date, "
                   "school.Email "
                   "FROM result r "
                   "JOIN student st ON r.Student_id = st.Student_id "
                   "JOIN subject sub ON r.Subj_id = sub.Subject_id "
                   "JOIN conditions c ON r.Condition_id = c.Condition_id "
                   "JOIN school ON r.School_id = school.School_id ";

    String conditions = "";

    // Фільтрація за датою
    if (Earlier->Checked || Later->Checked || ThisDate->Checked)
    {
        if (ThisDate->Checked)
        {
            conditions += "r.Attemp_date = :Date ";
        }
        else if (Earlier->Checked && Later->Checked)
        {
            conditions += "r.Attemp_date BETWEEN :DateStart AND :DateEnd ";
        }
        else if (Earlier->Checked)
        {
            conditions += "r.Attemp_date < :Date ";
        }
        else if (Later->Checked)
        {
            conditions += "r.Attemp_date > :Date ";
        }
    }

    // Фільтрація за ПІБ студента
    if (!LabeledEdit1->Text.Trim().IsEmpty())
    {
        if (!conditions.IsEmpty()) conditions += " AND ";
        conditions += "st.PIB LIKE :PIB ";  // Використовуємо правильне поле 'PIB'
    }

    // Фільтрація за предметом
    if (ComboBox2->ItemIndex >= 0)
    {
        if (!conditions.IsEmpty()) conditions += " AND ";
        conditions += "sub.Name = :Subject ";
    }

    // Додавання умов до запиту
    if (!conditions.IsEmpty())
    {
        query += " WHERE " + conditions;
    }

    query += " ORDER BY r.Attemp_date DESC";

    try
    {
        DataModule1->ADOQuery3->Close();
        DataModule1->ADOQuery3->SQL->Clear();
        DataModule1->ADOQuery3->SQL->Add(query);

        // Передача параметрів для дати
        if (ThisDate->Checked || Earlier->Checked || Later->Checked)
        {
            TDateTime selectedDate = DatePicker1->Date;
            if (ThisDate->Checked)
            {
                DataModule1->ADOQuery3->Parameters->ParamByName("Date")->Value = selectedDate.FormatString("yyyy-mm-dd");
            }
            else if (Earlier->Checked && Later->Checked)
            {
                DataModule1->ADOQuery3->Parameters->ParamByName("DateStart")->Value = selectedDate - 1;
                DataModule1->ADOQuery3->Parameters->ParamByName("DateEnd")->Value = selectedDate + 1;
            }
            else
            {
                DataModule1->ADOQuery3->Parameters->ParamByName("Date")->Value = selectedDate.FormatString("yyyy-mm-dd");
            }
        }

        // Передача параметра для ПІБ
        if (!LabeledEdit1->Text.Trim().IsEmpty())
        {
            String pibFilter = "%" + LabeledEdit1->Text.Trim() + "%";  // Додаємо символи % для LIKE
            DataModule1->ADOQuery3->Parameters->ParamByName("PIB")->Value = pibFilter;  // Використовуємо 'PIB'
        }

        // Передача параметра для предмету
        if (ComboBox2->ItemIndex >= 0)
        {
            DataModule1->ADOQuery3->Parameters->ParamByName("Subject")->Value = ComboBox2->Text;
        }

        DataModule1->ADOQuery3->Open();
        DBColumnSizes();  // Якщо є метод для налаштування розмірів колонок
    }
    catch (Exception &e)
    {
        ShowMessage("Помилка при фільтрації: " + e.Message);
    }
}



void __fastcall TForm11::FormCreate(TObject *Sender)
{
	DBColumnSizes();
	DatePicker1->Date = Now();
	Clear->Enabled = false;
	Execute->Enabled = false;
	ComboBox2->OnChange = CheckFiltersFilled;
	DatePicker1->OnChange = CheckFiltersFilled;
	Earlier->OnClick = CheckFiltersFilled;
	Later->OnClick = CheckFiltersFilled;
	ThisDate->OnClick = CheckFiltersFilled;
	LabeledEdit1->OnChange = CheckFiltersFilled;
}
//---------------------------------------------------------------------------

void __fastcall TForm11::DBGrid1TitleClick(TColumn *Column)
{
	String columnName = Column->FieldName;
	static bool sortAsc = true;
	String sortOrder = sortAsc ? "ASC" : "DESC";
	sortAsc = !sortAsc;
	String query =
		"SELECT r.Res_id, st.PIB, sub.Name, r.Reached_score, c.Max_point, c.Min_r_point, "
		"CASE WHEN r.Status = 1 THEN 'Зараховано' ELSE 'Не зараховано' END AS Status, "
		"r.Attemp_date, c.Date, school.Email "
		"FROM result r "
		"JOIN student st ON r.Student_id = st.Student_id "
		"JOIN subject sub ON r.Subj_id = sub.Subject_id "
		"JOIN conditions c ON r.Condition_id = c.Condition_id "
		"JOIN school ON r.School_id = school.School_id "
		"ORDER BY " + columnName + " " + sortOrder;
	try
	{
		DataModule1->ADOQuery3->Close();
		DataModule1->ADOQuery3->SQL->Clear();
		DataModule1->ADOQuery3->SQL->Add(query);
		DataModule1->ADOQuery3->Open();
		DBColumnSizes(); // Оновлюємо розмір колонок, якщо потрібно
	}
	catch (Exception &e)
	{
		ShowMessage("Помилка сортування: " + e.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm11::N3Click(TObject *Sender)
{
   int selected_id = 0;
   if (!DataModule1->DataSource5->DataSet->FieldByName("Res_id")->IsNull) {
	   selected_id = DataModule1->DataSource5->DataSet->FieldByName("Res_id")->AsInteger;
   }
   Form9->set_id(selected_id);
   Form9->ShowModal();
   DBColumnSizes();
}
//---------------------------------------------------------------------------

void __fastcall TForm11::N6Click(TObject *Sender)
{
   this->Close();
   Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm11::Lj1Click(TObject *Sender)
{
    Help_m->ShowModal();
}
//---------------------------------------------------------------------------

