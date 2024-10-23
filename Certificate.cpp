//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Certificate.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCertificates *Certificates;
//---------------------------------------------------------------------------
__fastcall TCertificates::TCertificates(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCertificates::N1Click(TObject *Sender)
{
   this->Close();
   Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TCertificates::Lj1Click(TObject *Sender)
{
   Help_m->ShowModal();
}
//---------------------------------------------------------------------------

void TCertificates::DBColumnSizes(){
	DBGrid2->Columns->Items[0]->Visible = false;
	DBGrid2->Columns->Items[1]->Width = 200;
	DBGrid2->Columns->Items[1]->Title->Caption = "ПІБ cтудента";
	DBGrid2->Columns->Items[2]->Width = 100;
	DBGrid2->Columns->Items[2]->Title->Caption = "PIN";
	DBGrid2->Columns->Items[3]->Width = 100;
	DBGrid2->Columns->Items[3]->Title->Caption = "Дата створення";
	DBGrid2->Columns->Items[4]->Width = 150;
	DBGrid2->Columns->Items[4]->Title->Caption = "Дата закінчення";
	DBGrid2->Columns->Items[5]->Width = 150;
	DBGrid2->Columns->Items[5]->Title->Caption = "Статус";
}

void __fastcall TCertificates::FormShow(TObject *Sender)
{
	DBColumnSizes();
}
//---------------------------------------------------------------------------

void __fastcall TCertificates::DatePicker1CloseUp(TObject *Sender)
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
		DatePicker1->Date = Now();
	}
}




//---------------------------------------------------------------------------

void __fastcall TCertificates::LabeledEdit1Exit(TObject *Sender)
{
	try
	{
		String enteredPIN = LabeledEdit1->Text.Trim();
		if (enteredPIN.IsEmpty())
		{
			throw Exception("Поле PIN не може бути порожнім!");
		}
		TADOQuery *query = new TADOQuery(NULL);
		try
		{
			query->Connection = DataModule1->ADOConnection1;
			query->SQL->Text = "SELECT COUNT(*) AS Count FROM Certificate WHERE PIN = :EnteredPIN";
			query->Parameters->ParamByName("EnteredPIN")->Value = enteredPIN;
			query->Open();

			int count = query->FieldByName("Count")->AsInteger;
			if (count <= 0)
			{
				throw Exception("PIN не існує в базі даних!");
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
		LabeledEdit1->SetFocus();
	}
}

//---------------------------------------------------------------------------



void __fastcall TCertificates::FormCreate(TObject *Sender)
{
	Execute->Enabled = false;
	Clear->Enabled = false;
	DatePicker1->OnChange = CheckFiltersFilled;
	Earlier->OnClick = CheckFiltersFilled;
	Later->OnClick = CheckFiltersFilled;
	ThisDate->OnClick = CheckFiltersFilled;
}

//---------------------------------------------------------------------------

void __fastcall TCertificates::CheckFiltersFilled(TObject *Sender)
{
	bool isAnyFilterFilled = false;
	if (Earlier->Checked || Later->Checked || ThisDate->Checked)
		isAnyFilterFilled = true;
	Execute->Enabled = isAnyFilterFilled;
	Clear->Enabled = isAnyFilterFilled;
}


void __fastcall TCertificates::ExecuteClick(TObject *Sender)
{
	String query = "SELECT certificate.Cerf_num, student.PIB, certificate.PIN, certificate.Creation_date, certificate.Effect_time, "
				   "CASE WHEN certificate.Status = 1 THEN 'Дійсний' ELSE 'Не дійсний' END AS Status "
				   "FROM certificate "
				   "JOIN student ON certificate.Student_id = student.Student_id ";

	String conditions = "";
	if (ThisDate->Checked)
		conditions += "certificate.Creation_date = :SelectedDate ";
	else if (Earlier->Checked && Later->Checked)
		conditions += "certificate.Creation_date BETWEEN :DateStart AND :DateEnd ";
	else if (Later->Checked)
		conditions += "certificate.Creation_date > :SelectedDate ";
	else if (Earlier->Checked)
		conditions += "certificate.Creation_date < :SelectedDate ";

	if (!conditions.IsEmpty())
		query += " WHERE " + conditions;

	query += " ORDER BY certificate.Creation_date DESC";

	try
	{
		DataModule1->ADOQuery4->Close();
		DataModule1->ADOQuery4->SQL->Clear();
		DataModule1->ADOQuery4->SQL->Add(query);

		TDateTime selectedDate = DatePicker1->Date;

		if (ThisDate->Checked)
			DataModule1->ADOQuery4->Parameters->ParamByName("SelectedDate")->Value = selectedDate.FormatString("yyyy-mm-dd");
		else if (Earlier->Checked && Later->Checked)
		{
			DataModule1->ADOQuery4->Parameters->ParamByName("DateStart")->Value = selectedDate - 1;
			DataModule1->ADOQuery4->Parameters->ParamByName("DateEnd")->Value = selectedDate + 1;
		}
		else if (Earlier->Checked || Later->Checked)
			DataModule1->ADOQuery4->Parameters->ParamByName("SelectedDate")->Value = selectedDate.FormatString("yyyy-mm-dd");

		DataModule1->ADOQuery4->Open();
		DBColumnSizes();
	}
	catch (const Exception &e)
	{
		ShowMessage("Помилка при фільтрації: " + e.Message);
	}
}


//---------------------------------------------------------------------------

void __fastcall TCertificates::ClearClick(TObject *Sender)
{
	DatePicker1->Date = Now();
	Earlier->Checked = false;
	Later->Checked = false;
	ThisDate->Checked = false;

	Execute->Enabled = false;
	Clear->Enabled = false;

	String query = "SELECT certificate.Cerf_num, student.PIB, certificate.PIN, certificate.Creation_date, certificate.Effect_time, "
				   "CASE WHEN certificate.Status = 1 THEN 'Дійсний' ELSE 'Не дійсний' END AS Status "
				   "FROM certificate "
				   "JOIN student ON certificate.Student_id = student.Student_id "
				   "ORDER BY certificate.Creation_date DESC";

	try
	{
		DataModule1->ADOQuery4->Close();
		DataModule1->ADOQuery4->SQL->Clear();
		DataModule1->ADOQuery4->SQL->Add(query);
		DataModule1->ADOQuery4->Open();

		DBColumnSizes();
	}
	catch (const Exception &e)
	{
		ShowMessage("Помилка при очищенні фільтрів: " + e.Message);
	}
}

//---------------------------------------------------------------------------


void __fastcall TCertificates::DBGrid2TitleClick(TColumn *Column)
{
	String sortOrder = SortAscending ? " ASC" : " DESC";
	DataModule1->ADOQuery4->Sort = Column->Field->FieldName + sortOrder;
	SortAscending = !SortAscending;
}

//---------------------------------------------------------------------------



void __fastcall TCertificates::N3Click(TObject *Sender)
{
   int selected_id = 0;
   if (!DataModule1->DataSource6->DataSet->FieldByName("Cerf_num")->IsNull) {
	   selected_id = DataModule1->DataSource6->DataSet->FieldByName("Cerf_num")->AsInteger;
   }
   Form10->set_id(selected_id);
   Form10->ShowModal();
   DBColumnSizes();
}
//---------------------------------------------------------------------------



void __fastcall TCertificates::N2Click(TObject *Sender)
{
   Form10->set_id(0);
   Form10->ShowModal();
   DBColumnSizes();
}
//---------------------------------------------------------------------------

