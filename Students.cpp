//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "Students.h"
TForm14 *Form14;
//---------------------------------------------------------------------------
__fastcall TForm14::TForm14(TComponent* Owner)
	: TForm(Owner)
{
    isMinimalView = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm14::FormCreate(TObject *Sender)
{
	if(!isMinimalView){
	Clear->Enabled = false;
	Execute->Enabled = false;
	ComboBox1->Items->Clear();
	ComboBox1->Items->Add("ID-карта");
	ComboBox1->Items->Add("Паперовий");
	DatePicker1->OnChange = CheckFiltersFilled;
	ThisDate->OnClick = CheckFiltersFilled;
	Edit5->OnChange = CheckFiltersFilled;
	ComboBox1->OnChange = CheckFiltersFilled;
	RadioGroup1->OnClick = CheckFiltersFilled;
	}
	ToggleView();
	DBColumnSizes();

}



//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm14::N6Click(TObject *Sender)
{
   this->Close();
   Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm14::Lj1Click(TObject *Sender)
{
   Help_m->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm14::DBColumnSizes(){
	DBGrid1->Columns->Items[0]->Visible = false;
	DBGrid1->Columns->Items[1]->Width = 100;
	DBGrid1->Columns->Items[1]->Title->Caption = "Номер паспорту";
	DBGrid1->Columns->Items[2]->Width = 80;
	DBGrid1->Columns->Items[2]->Title->Caption = "Тип паспорту";
	DBGrid1->Columns->Items[3]->Width = 100;
	DBGrid1->Columns->Items[3]->Title->Caption = "ПІБ";
	DBGrid1->Columns->Items[4]->Width = 100;
	DBGrid1->Columns->Items[4]->Title->Caption = "Дата народження";
	DBGrid1->Columns->Items[5]->Width = 60;
	DBGrid1->Columns->Items[5]->Title->Caption = "Стать";
	DBGrid1->Columns->Items[6]->Width = 85;
	DBGrid1->Columns->Items[6]->Title->Caption = "E-mail";
	DBGrid1->Columns->Items[7]->Width = 85;
	DBGrid1->Columns->Items[7]->Title->Caption = "Номер телефону";
	DBGrid1->Columns->Items[8]->Width = 85;
	DBGrid1->Columns->Items[8]->Title->Caption = "Номер посвідчення";
	DBGrid1->Columns->Items[9]->Width = 85;
	DBGrid1->Columns->Items[9]->Title->Caption = "ІПН";
	DBGrid1->Columns->Items[10]->Width = 85;
	DBGrid1->Columns->Items[10]->Title->Caption = "Додаткова помітка";
}

void __fastcall TForm14::N1Click(TObject *Sender)
{
	DataModule1->DataSource1->DataSet->Refresh();
	String passport_num = DBGrid1->DataSource->DataSet->FieldByName("Passport_num")->AsString;
	TADOQuery *query = new TADOQuery(this);
	query->Connection = DataModule1->ADOConnection1;
	query->SQL->Text = "SELECT Student_id FROM student WHERE Passport_num = :Passport_num";
	query->Parameters->ParamByName("Passport_num")->Value = passport_num;
	query->Open();
	if (!query->Eof) {
		int student_id = query->FieldByName("Student_id")->AsInteger;
		Form1->Caption = "Редагування даних";
		Form1->set_id(student_id);
		Form1->ShowModal();
		DataModule1->DataSource1->DataSet->Refresh();
	}
	else {
		ShowMessage("Студента з таким паспортом не знайдено.");
	}
	delete query;
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
	Form1->Caption = "Додавання даних";
	Form1->set_id(0);
	Form1->ShowModal();
	DataModule1->DataSource1->DataSet->Refresh();
}




//---------------------------------------------------------------------------

void __fastcall TForm14::CheckFiltersFilled(TObject *Sender)
{
	bool isAnyFilterFilled = false;
	if (ThisDate->Checked) isAnyFilterFilled = true;
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
	if (ThisDate->Checked && DatePicker1->Date != TDateTime() && DatePicker2->Date != TDateTime())
    {
        if ((double)DatePicker1->Date <= (double)DatePicker2->Date)
        {
			String dateStart = "#" + DatePicker1->Date.FormatString("yyyy-mm-dd") + "#";
            String dateEnd = "#" + DatePicker2->Date.FormatString("yyyy-mm-dd") + "#";
            DataModule1->ADOTable1->Filter = "Birth_date >= " + dateStart + " AND Birth_date <= " + dateEnd;
        }
		else
        {
            ShowMessage("Дата початку повинна бути раніше дати завершення!");
            return;
		}
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
		DataModule1->ADOTable1->Filter += "Email LIKE '*" + Edit5->Text.Trim() + "*'";
	}
	if (RadioGroup1->ItemIndex >= 0)
	{
		String genderFilter = (RadioGroup1->ItemIndex == 0) ? "M" : "F";
		if (!DataModule1->ADOTable1->Filter.IsEmpty())
			DataModule1->ADOTable1->Filter += " AND ";
		DataModule1->ADOTable1->Filter += "Gender = '" + genderFilter + "'";
	}
	DataModule1->ADOTable1->Filtered = true;
	DBColumnSizes();
}






//---------------------------------------------------------------------------
void __fastcall TForm14::ClearClick(TObject *Sender)
{
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



void __fastcall TForm14::DatePicker1CloseUp(TObject *Sender)
{
	 try
	{
		TDateTime selectedDate = DatePicker1->Date;
		TDateTime currentDate = Now();
		if (selectedDate > currentDate)
		{
			throw Exception("Дата не може бути в майбутньому!");
		}
		else if(selectedDate < EncodeDate(1925, 1, 1))
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

void __fastcall TForm14::Edit5Exit(TObject *Sender)
{
	String email = Edit5->Text;
	UnicodeString pattern = "^\\w+([-+.']\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$";
	if (!TRegEx::IsMatch(email, pattern)) {
		ShowMessage("Введіть дійсний e-mail.");
	}
}
//---------------------------------------------------------------------------

void TForm14::ToggleView()
{
	if (isMinimalView)
	{
		Form14->AutoSize = true;
		for (int i = 0; i < Form14->MainMenu1->Items->Count; i++)
		{
			Form14->MainMenu1->Items->Items[i]->Enabled = false;
		}
		Form14->Caption = "Учасники НМТ";

        for (int i = 0; i < Form14->ControlCount; i++)
		{
            if (Form14->Controls[i] != Form14->DBGrid1)
			{
				Form14->Controls[i]->Visible = false;
            }
        }
    }
    else
	{
		Form14->AutoSize = false;
		for (int i = 0; i < Form14->MainMenu1->Items->Count; i++)
		{
			Form14->MainMenu1->Items->Items[i]->Enabled = true;
		}
		Form14->Caption = "Робота з інформацією про учасників НМТ";

        for (int i = 0; i < Form14->ControlCount; i++)
        {
			Form14->Controls[i]->Visible = true;
		}
	}
}






void __fastcall TForm14::DatePicker2CloseUp(TObject *Sender)
{
     try
	{
		TDateTime selectedDate = DatePicker2->Date;
		TDateTime currentDate = Now();
		if (selectedDate > currentDate)
		{
			throw Exception("Дата не може бути в майбутньому!");
		}
		else if(selectedDate < EncodeDate(1925, 1, 1))
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

