//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <SysUtils.hpp>
#include "Main_Window.h"
#include "Data.h"
#include "Help.h"
#include "Students.h"
#include "Subjects.h"
#include "Certificate.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Timer1Timer(TObject *Sender)
{
	 StatusBar1->Panels->Items[1]->Text = DateTimeToStr(Now());
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormCreate(TObject *Sender)
{

	StatusBar1->Panels->Items[1]->Text = DateTimeToStr(Now());
	Clear->Enabled = false;
	Execute->Enabled = false;
	DatePicker1->OnChange = CheckFiltersFilled;
    Earlier->OnClick = CheckFiltersFilled;
    Later->OnClick = CheckFiltersFilled;
    ThisDate->OnClick = CheckFiltersFilled;
	Status_check->OnClick = CheckFiltersFilled;
	Edit1->OnChange = CheckFiltersFilled;
}

//---------------------------------------------------------------------------

void __fastcall TForm3::DBGrid1TitleClick(TColumn *Column)
{
   String columnName = Column->FieldName;
   static bool sortAsc = true;
   String sortOrder = sortAsc ? "ASC" : "DESC";
   sortAsc = !sortAsc;

   String query = "SELECT s.PIB, "
				  "r.Attemp_date, "
				  "CASE WHEN r.Status = 1 THEN 'Здано' ELSE 'Не здано' END, "
				  "subj.Name, "
				  "r.Reached_score "
				  "FROM Result r "
				  "JOIN Student s ON r.Student_id = s.Student_id "
				  "JOIN Subject subj ON r.Subj_id = subj.Subject_id "
				  "ORDER BY `" + columnName + "` " + sortOrder;

   try
   {
       DataModule1->MainQuery->Close();
       DataModule1->MainQuery->SQL->Clear();
       DataModule1->MainQuery->SQL->Add(query);
       DataModule1->MainQuery->Open();
       DBColumnSizes();
   }
   catch (Exception &e)
   {
       ShowMessage("Помилка сортування: " + e.Message);
   }
}
//Працює на 100% (сортування по кліку назва колонки)

//---------------------------------------------------------------------------

void TForm3::DBColumnSizes(){
	DBGrid1->Columns->Items[0]->Width = 150;
	DBGrid1->Columns->Items[0]->Title->Caption = "ПІБ";
	DBGrid1->Columns->Items[1]->Width = 100;
	DBGrid1->Columns->Items[1]->Title->Caption = "Дата складання";
	DBGrid1->Columns->Items[2]->Width = 60;
	DBGrid1->Columns->Items[2]->Title->Caption = "Статус";
	DBGrid1->Columns->Items[3]->Width = 125;
	DBGrid1->Columns->Items[3]->Title->Caption = "Предмет";
	DBGrid1->Columns->Items[4]->Width = 85;
	DBGrid1->Columns->Items[4]->Title->Caption = "Результат";
}
//функція для оформлення таблиці

void __fastcall TForm3::CheckFiltersFilled(TObject *Sender)
{
	bool isAnyFilterFilled = false;
	if (Earlier->Checked || Later->Checked || ThisDate->Checked) isAnyFilterFilled = true;
	if (Status_check->ItemIndex >= 0) isAnyFilterFilled = true;
	if (!Edit1->Text.Trim().IsEmpty()) isAnyFilterFilled = true;
	Execute->Enabled = isAnyFilterFilled;
	Clear->Enabled = isAnyFilterFilled;
}
//активація і деактивація кнопок


void __fastcall TForm3::FormShow(TObject *Sender)
{
	DBColumnSizes();
}
//встановлення при запуску форми
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall TForm3::ClearClick(TObject *Sender)
{
  	DatePicker1->Date = Now();
	Earlier->Checked = false;
	Later->Checked = false;
	ThisDate->Checked = false;
	Status_check->ItemIndex = -1;
	Edit1->Text = "";
	Execute->Enabled = false;
	Clear->Enabled = false;
	String query = "SELECT s.PIB, "
				   "r.Attemp_date, "
				   "CASE WHEN r.Status = 1 THEN 'Здано' ELSE 'Не здано' END, "
				   "subj.Name, "
				   "r.Reached_score "
				   "FROM Result r "
				   "JOIN Student s ON r.Student_id = s.Student_id "
				   "JOIN Subject subj ON r.Subj_id = subj.Subject_id "
				   "ORDER BY r.Attemp_date DESC";

	try
	{
		DataModule1->MainQuery->Close();
		DataModule1->MainQuery->SQL->Clear();
		DataModule1->MainQuery->SQL->Add(query);
		DataModule1->MainQuery->Open();
		DBColumnSizes();
	}
	catch (Exception &e)
	{
		ShowMessage("Помилка при скиданні фільтрів: " + e.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::ExecuteClick(TObject *Sender)
{
  String query = "SELECT s.PIB, "
				   "r.Attemp_date, "
                   "CASE WHEN r.Status = 1 THEN 'Здано' ELSE 'Не здано' END, "
                   "subj.Name, "
                   "r.Reached_score "
				   "FROM Result r "
                   "JOIN Student s ON r.Student_id = s.Student_id "
                   "JOIN Subject subj ON r.Subj_id = subj.Subject_id ";
	String conditions = "";

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

	if (Status_check->ItemIndex == 0)
	{
		if (!conditions.IsEmpty()) conditions += " AND ";
		conditions += "r.Status = 1 ";
	}
	else if (Status_check->ItemIndex == 1)
	{
		if (!conditions.IsEmpty()) conditions += " AND ";
		conditions += "r.Status = 0 ";
	}

	if (!Edit1->Text.Trim().IsEmpty())
	{
		if (!conditions.IsEmpty()) conditions += " AND ";
		conditions += "s.PIB LIKE :Surname ";
	}

	if (!conditions.IsEmpty())
	{
		query += " WHERE " + conditions;
	}

	query += " ORDER BY r.Attemp_date DESC";

	try
	{
		DataModule1->MainQuery->Close();
		DataModule1->MainQuery->SQL->Clear();
		DataModule1->MainQuery->SQL->Add(query);

		if (ThisDate->Checked || Earlier->Checked || Later->Checked)
		{
			TDateTime selectedDate = DatePicker1->Date;
			if (ThisDate->Checked)
			{
				DataModule1->MainQuery->Parameters->ParamByName("Date")->Value = selectedDate.FormatString("yyyy-mm-dd");
			}
			else if (Earlier->Checked && Later->Checked)
			{
				DataModule1->MainQuery->Parameters->ParamByName("DateStart")->Value = selectedDate - 1;
				DataModule1->MainQuery->Parameters->ParamByName("DateEnd")->Value = selectedDate + 1;
			}
			else
			{
				DataModule1->MainQuery->Parameters->ParamByName("Date")->Value = selectedDate.FormatString("yyyy-mm-dd");
			}
		}

		if (!Edit1->Text.Trim().IsEmpty())
		{
			DataModule1->MainQuery->Parameters->ParamByName("Surname")->Value = "%" + Edit1->Text.Trim() + "%";
		}

		DataModule1->MainQuery->Open();
		DBColumnSizes();
	}
	catch (Exception &e)
	{
		ShowMessage("Помилка при фільтрації: " + e.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Lj1Click(TObject *Sender)
{
   Help_m = new THelp_m(this);
   Help_m->ShowModal();
   delete Help_m;
}



void __fastcall TForm3::N11Click(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N2Click(TObject *Sender)
{
	Form3->Hide();
	Form14 = new TForm14(this);
	Form14->ShowModal();
}

//---------------------------------------------------------------------------

void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N4Click(TObject *Sender)
{
   Form3->Hide();
   Form7 = new TForm7(this);
   Form7->ShowModal();
}
//---------------------------------------------------------------------------

