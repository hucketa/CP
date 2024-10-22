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


void __fastcall TForm11::DBColumnSizes(){
	DBGrid2->Columns->Items[0]->Visible = false;
	DBGrid2->Columns->Items[1]->Width = 150;
	DBGrid2->Columns->Items[1]->Title->Caption = "ПІБ студента";
	DBGrid2->Columns->Items[2]->Width = 90;
	DBGrid2->Columns->Items[2]->Title->Caption = "Предмет";
	DBGrid2->Columns->Items[3]->Width = 82;
	DBGrid2->Columns->Items[3]->Title->Caption = "Результат";
	DBGrid2->Columns->Items[4]->Width = 82;
	DBGrid2->Columns->Items[4]->Title->Caption = "Максимально";
	DBGrid2->Columns->Items[5]->Width = 82;
	DBGrid2->Columns->Items[5]->Title->Caption = "Прохідний";
	DBGrid2->Columns->Items[6]->Width = 82;
	DBGrid2->Columns->Items[6]->Title->Caption = "Статус";
	DBGrid2->Columns->Items[7]->Width = 82;
	DBGrid2->Columns->Items[7]->Title->Caption = "Дата складання";
	DBGrid2->Columns->Items[8]->Width = 82;
	DBGrid2->Columns->Items[8]->Title->Caption = "Дата укладання умов";
	DBGrid2->Columns->Items[9]->Width = 175;
	DBGrid2->Columns->Items[9]->Title->Caption = "E-mail навчального закладу";
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
    Form9->ShowModal();
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

void __fastcall TForm11::DBGrid2TitleClick(TColumn *Column)
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
        "ORDER BY `" + columnName + "` " + sortOrder;

    try
    {
        DataModule1->ADOQuery3->Close();
        DataModule1->ADOQuery3->SQL->Clear();
        DataModule1->ADOQuery3->SQL->Add(query);
        DataModule1->ADOQuery3->Open();
        DBColumnSizes();
    }
    catch (Exception &e)
    {
        ShowMessage("Помилка сортування: " + e.Message);
    }
}

void __fastcall TForm11::ClearClick(TObject *Sender)
{
	LabeledEdit1->Clear();
    ComboBox2->ItemIndex = -1;
    DatePicker1->Date = TDateTime();
    Earlier->Checked = false;
    Later->Checked = false;
    ThisDate->Checked = false;
	DataModule1->ADOQuery3->Filtered = false;
	DataModule1->ADOQuery3->Filter = "";
	Execute->Enabled = false;
	Clear->Enabled = false;
}

void __fastcall TForm11::ExecuteClick(TObject *Sender)
{
	DataModule1->ADOQuery3->Filtered = false;
    String filterText = "";
    if (Earlier->Checked) {
        filterText += "Attemp_date < '" + DatePicker1->Date.FormatString("yyyy-mm-dd") + "'";
    } else if (Later->Checked) {
        filterText += "Attemp_date > '" + DatePicker1->Date.FormatString("yyyy-mm-dd") + "'";
    } else if (ThisDate->Checked) {
        filterText += "Attemp_date = '" + DatePicker1->Date.FormatString("yyyy-mm-dd") + "'";
    }
    if (!LabeledEdit1->Text.Trim().IsEmpty()) {
        if (!filterText.IsEmpty()) filterText += " AND ";
        filterText += "Student_id IN (SELECT Student_id FROM student WHERE PIB LIKE '%" + LabeledEdit1->Text.Trim() + "%')";
    }
    if (ComboBox2->ItemIndex >= 0) {
        if (!filterText.IsEmpty()) filterText += " AND ";
        filterText += "Subj_id IN (SELECT Subject_id FROM subject WHERE Name = '" + ComboBox2->Text + "')";
    }
    if (!filterText.IsEmpty()) {
        DataModule1->ADOQuery3->Filter = filterText;
        DataModule1->ADOQuery3->Filtered = true;
    } else {
        DataModule1->ADOQuery3->Filtered = false;
	}
}

void __fastcall TForm11::FormCreate(TObject *Sender)
{
    DBColumnSizes();
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

