//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Students.h"
#include "Main_Window.h"
#include "Help.h"
#include <String.h>w
#include "Data.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm14 *Form14;
//---------------------------------------------------------------------------
__fastcall TForm14::TForm14(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm14::FormCreate(TObject *Sender)
{
    DBColumnSizes();
    Clear->Enabled = false;
	Execute->Enabled = false;
    ComboBox1->Items->Clear();
    ComboBox1->Items->Add("ID-карта");
	ComboBox1->Items->Add("Паперовий");
	DatePicker1->OnChange = CheckFiltersFilled;
	Earlier->OnClick = CheckFiltersFilled;
    Later->OnClick = CheckFiltersFilled;
    ThisDate->OnClick = CheckFiltersFilled;
    Edit5->OnChange = CheckFiltersFilled;
    ComboBox1->OnChange = CheckFiltersFilled;
    RadioGroup1->OnClick = CheckFiltersFilled;
}



//---------------------------------------------------------------------------
void __fastcall TForm14::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
	Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm14::N6Click(TObject *Sender)
{
   this->Hide();
   Form3 = new TForm3(this);
   Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm14::Lj1Click(TObject *Sender)
{
  Help_m = new THelp_m(this);
   Help_m->ShowModal();
   delete Help_m;
}
//---------------------------------------------------------------------------

void __fastcall TForm14::DBColumnSizes(){
	DBGrid1->Columns->Items[0]->Width = 100;
	DBGrid1->Columns->Items[0]->Title->Caption = "Номер паспорту";
	DBGrid1->Columns->Items[1]->Width = 80;
	DBGrid1->Columns->Items[1]->Title->Caption = "Тип паспорту";
	DBGrid1->Columns->Items[2]->Width = 100;
	DBGrid1->Columns->Items[2]->Title->Caption = "ПІБ";
	DBGrid1->Columns->Items[3]->Width = 100;
	DBGrid1->Columns->Items[3]->Title->Caption = "Дата народження";
	DBGrid1->Columns->Items[4]->Width = 60;
	DBGrid1->Columns->Items[4]->Title->Caption = "Стать";
	DBGrid1->Columns->Items[5]->Width = 85;
	DBGrid1->Columns->Items[5]->Title->Caption = "E-mail";
	DBGrid1->Columns->Items[6]->Width = 85;
	DBGrid1->Columns->Items[6]->Title->Caption = "Номер телефону";
	DBGrid1->Columns->Items[7]->Width = 85;
	DBGrid1->Columns->Items[7]->Title->Caption = "Номер посвідчення";
	DBGrid1->Columns->Items[8]->Width = 85;
	DBGrid1->Columns->Items[8]->Title->Caption = "ІПН";
	DBGrid1->Columns->Items[9]->Width = 85;
	DBGrid1->Columns->Items[9]->Title->Caption = "Додаткова помітка";
}

void __fastcall TForm14::N1Click(TObject *Sender)
{
	int id = DBGrid1->DataSource->DataSet->RecNo;
	Form1 = new TForm1(this);
	Form1->set_id(id);
	Form1->ShowModal();
	DataModule1->DataSource1->DataSet->Refresh();
	delete Form1;
}



//---------------------------------------------------------------------------

void __fastcall TForm14::DBGrid1TitleClick(TColumn *Column)
{
	String sortOrder = SortAscending ? " ASC" : " DESC";
	DataModule1->ADOTable1->Sort = Column->Field->FieldName + sortOrder;
	SortAscending = !SortAscending;
}
//---------------------------------------------------------------------------


void __fastcall TForm14::N2Click(TObject *Sender)
{
   Form1 = new TForm1(this);
   Form1->set_id(0);
   Form1->ShowModal();
   DataModule1->DataSource1->DataSet->Refresh();
   delete Form1;
}
//---------------------------------------------------------------------------

void __fastcall TForm14::CheckFiltersFilled(TObject *Sender)
{
    bool isAnyFilterFilled = false;
    if (Earlier->Checked || Later->Checked || ThisDate->Checked) isAnyFilterFilled = true;
    if (RadioGroup1->ItemIndex >= 0) isAnyFilterFilled = true;
	if (!Edit5->Text.Trim().IsEmpty()) isAnyFilterFilled = true;
    if (ComboBox1->ItemIndex >= 0) isAnyFilterFilled = true;
    Execute->Enabled = isAnyFilterFilled;
    Clear->Enabled = isAnyFilterFilled;
}

//---------------------------------------------------------------------------

void __fastcall TForm14::ExecuteClick(TObject *Sender)
{
	DataModule1->ADOTable1->Filtered = false;
	if (Earlier->Checked)
    {
		DataModule1->ADOTable1->Filter = "Birth_date < '" + DatePicker1->Date.FormatString("yyyy-mm-dd") + "'";
    }
    else if (Later->Checked)
    {
        DataModule1->ADOTable1->Filter = "Birth_date > '" + DatePicker1->Date.FormatString("yyyy-mm-dd") + "'";
    }
    else if (ThisDate->Checked)
    {
        DataModule1->ADOTable1->Filter = "Birth_date = '" + DatePicker1->Date.FormatString("yyyy-mm-dd") + "'";
	}
    if (ComboBox1->ItemIndex >= 0)
    {
        if (!DataModule1->ADOTable1->Filter.IsEmpty())
            DataModule1->ADOTable1->Filter += " AND ";
        DataModule1->ADOTable1->Filter += "Passport_type = '" + ComboBox1->Items->Strings[ComboBox1->ItemIndex] + "'";
	}
	if (!Edit5->Text.Trim().IsEmpty())
	{
	if (!DataModule1->ADOTable1->Filter.IsEmpty())
        DataModule1->ADOTable1->Filter += " AND ";
    DataModule1->ADOTable1->Filter += "Email LIKE '%" + Edit5->Text.Trim() + "%'";
	}
    if (RadioGroup1->ItemIndex >= 0)
    {
		String genderFilter = (RadioGroup1->ItemIndex == 0) ? "M" : "F";
        if (!DataModule1->ADOTable1->Filter.IsEmpty())
            DataModule1->ADOTable1->Filter += " AND ";
        DataModule1->ADOTable1->Filter += "Gender = '" + genderFilter + "'";
	}
	DataModule1->ADOTable1->Filtered = true;
}

//---------------------------------------------------------------------------

void __fastcall TForm14::ClearClick(TObject *Sender)
{
    Earlier->Checked = false;
    Later->Checked = false;
    ThisDate->Checked = false;
    RadioGroup1->ItemIndex = -1;
	Edit5->Clear();
    ComboBox1->ItemIndex = -1;
	DatePicker1->Date = TDateTime();
    DataModule1->ADOTable1->Filtered = false;
	DataModule1->ADOTable1->Filter = "";
    Execute->Enabled = false;
	Clear->Enabled = false;
}



