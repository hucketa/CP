//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Conditions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void TForm4::DBColumnSizes(){
	DBGrid1->Columns->Items[0]->Visible = false;
	DBGrid1->Columns->Items[1]->Width = 150;
	DBGrid1->Columns->Items[1]->Title->Caption = "Назва предмету";
	DBGrid1->Columns->Items[2]->Width = 100;
	DBGrid1->Columns->Items[2]->Title->Caption = "Максимальний бал";
	DBGrid1->Columns->Items[3]->Width = 170;
	DBGrid1->Columns->Items[3]->Title->Caption = "Мінімальний прохідний бал";
	DBGrid1->Columns->Items[4]->Width = 100;
	DBGrid1->Columns->Items[4]->Title->Caption = "Мінімальний бал";
	DBGrid1->Columns->Items[5]->Width = 100;
	DBGrid1->Columns->Items[5]->Title->Caption = "Статус";
	DBGrid1->Columns->Items[6]->Width = 100;
	DBGrid1->Columns->Items[6]->Title->Caption = "Дата складання";
}

void __fastcall TForm4::FormShow(TObject *Sender)
{
	DBColumnSizes();
		TADOQuery *Query = new TADOQuery(this);
	Query->Connection = DataModule1->ADOConnection1;
	Query->SQL->Text = "SELECT Subject_id, Name FROM subject";
	Query->Open();
	ComboBox2->Items->Clear();
	while (!Query->Eof)
	{
		ComboBox2->Items->AddObject(Query->FieldByName("Name")->AsString,
									(TObject*)Query->FieldByName("Subject_id")->AsInteger);
		Query->Next();
	}
	delete Query;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm4::Lj1Click(TObject *Sender)
{
   Help_m->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::N1Click(TObject *Sender)
{
   this->Close();
   Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::DBGrid1TitleClick(TColumn *Column)
{
   	String sortOrder = SortAscending ? " ASC" : " DESC";
	DataModule1->ADOQuery2->Sort = Column->Field->FieldName + sortOrder;
	SortAscending = !SortAscending;
}
//---------------------------------------------------------------------------


void __fastcall TForm4::DatePicker2CloseUp(TObject *Sender)
{
	try
	{
		TDateTime selectedDate = DatePicker2->Date;
		TDateTime currentDate = Now();
		if (selectedDate > currentDate)
		{
			throw Exception("Дата не може бути в майбутньому!");
		}
		else if (selectedDate < EncodeDate(1925, 1, 1))
		{
			throw Exception("Дата занадто стара! Виберіть пізнішу дату.");
		}
	}
	catch (const Exception &e)
	{
		ShowMessage(e.Message);
		DatePicker2->Date = Now();
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm4::FormCreate(TObject *Sender)
{
	Execute->Enabled = false;
	Clear->Enabled = false;
	DatePicker2->OnChange = CheckFiltersFilled;
	Earlier->OnClick = CheckFiltersFilled;
	Later->OnClick = CheckFiltersFilled;
	ThisDate->OnClick = CheckFiltersFilled;
	ComboBox2->OnChange = CheckFiltersFilled;
}

//---------------------------------------------------------------------------

void __fastcall TForm4::CheckFiltersFilled(TObject *Sender)
{
	bool isAnyFilterFilled = false;
	if (Earlier->Checked || Later->Checked || ThisDate->Checked)
		isAnyFilterFilled = true;
	if (ComboBox2->ItemIndex >= 0)
		isAnyFilterFilled = true;
	Execute->Enabled = isAnyFilterFilled;
	Clear->Enabled = isAnyFilterFilled;
}


void __fastcall TForm4::ExecuteClick(TObject *Sender)
{
	String query = "SELECT c.Condition_id, s.Name AS Subject_Name, c.Max_point, c.Min_r_point, c.Min_point, "
				   "CASE WHEN c.Status = 1 THEN 1 ELSE 0 END AS Status, "
				   "c.Date "
				   "FROM conditions c "
				   "JOIN subject s ON c.Subject_id = s.Subject_id ";

	String conditions = "";

	if (ThisDate->Checked)
	{
		conditions += "c.Date = :Date ";
	}
	else if (Earlier->Checked && Later->Checked)
	{
		conditions += "c.Date BETWEEN :DateStart AND :DateEnd ";
	}
	else if (Later->Checked)
	{
		conditions += "c.Date > :Date ";
	}
	else if (Earlier->Checked)
	{
		conditions += "c.Date < :Date ";
	}

	if (ComboBox2->ItemIndex >= 0)
	{
		if (!conditions.IsEmpty()) conditions += " AND ";
		conditions += "c.Subject_id = :SubjectID ";
	}

	if (!conditions.IsEmpty())
	{
		query += " WHERE " + conditions;
	}

	query += " ORDER BY c.Date DESC";

	try
	{
		DataModule1->ADOQuery2->Close();
		DataModule1->ADOQuery2->SQL->Clear();
		DataModule1->ADOQuery2->SQL->Add(query);

		TDateTime selectedDate = DatePicker2->Date;

		if (ThisDate->Checked)
		{
			DataModule1->ADOQuery2->Parameters->ParamByName("Date")->Value = selectedDate.FormatString("yyyy-mm-dd");
		}
		else if (Earlier->Checked && Later->Checked)
		{
			DataModule1->ADOQuery2->Parameters->ParamByName("DateStart")->Value = selectedDate - 1;
			DataModule1->ADOQuery2->Parameters->ParamByName("DateEnd")->Value = selectedDate + 1;
		}
		else if (Earlier->Checked || Later->Checked)
		{
			DataModule1->ADOQuery2->Parameters->ParamByName("Date")->Value = selectedDate.FormatString("yyyy-mm-dd");
		}

		if (ComboBox2->ItemIndex >= 0)
		{
			DataModule1->ADOQuery2->Parameters->ParamByName("SubjectID")->Value = (int)ComboBox2->Items->Objects[ComboBox2->ItemIndex];
		}

		DataModule1->ADOQuery2->Open();
		DBColumnSizes();
	}
	catch (const Exception &e)
	{
		ShowMessage("Помилка при фільтрації: " + e.Message);
	}
}


//---------------------------------------------------------------------------


void __fastcall TForm4::ClearClick(TObject *Sender)
{
	DatePicker2->Date = Now();
	Earlier->Checked = false;
	Later->Checked = false;
	ThisDate->Checked = false;
	ComboBox2->ItemIndex = -1;

	Execute->Enabled = false;
	Clear->Enabled = false;

	String query = "SELECT c.Condition_id, s.Name AS Subject_Name, c.Max_point, c.Min_r_point, c.Min_point, "
				   "CASE WHEN c.Status = 1 THEN 1 ELSE 0 END AS Status, "
				   "c.Date "
				   "FROM conditions c "
				   "JOIN subject s ON c.Subject_id = s.Subject_id "
				   "ORDER BY c.Date DESC";

	try
	{
		DataModule1->ADOQuery2->Close();
        DataModule1->ADOQuery2->SQL->Clear();
		DataModule1->ADOQuery2->SQL->Add(query);
        DataModule1->ADOQuery2->Open();

        DBColumnSizes();
	}
    catch (const Exception &e)
	{
        ShowMessage("Помилка при очищенні фільтрів: " + e.Message);
    }
}

//---------------------------------------------------------------------------

void __fastcall TForm4::N2Click(TObject *Sender)
{
   Form5->ShowModal();
   DataModule1->DataSource3->DataSet->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::N3Click(TObject *Sender)
{
   Form5->ShowModal();
   DataModule1->DataSource3->DataSet->Refresh();
}
//---------------------------------------------------------------------------


