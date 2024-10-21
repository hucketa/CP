//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Subjects.h"
#include "Unit2.h"
#include "Help.h"
#include "Main_window.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm7::DBColumnSizes(){
	DBGrid1->Columns->Items[0]->Visible = false;
	DBGrid1->Columns->Items[1]->Width = 100;
	DBGrid1->Columns->Items[1]->Title->Caption = "Назва предмету";
	DBGrid1->Columns->Items[2]->Width = 250;
	DBGrid1->Columns->Items[2]->Title->Caption = "Опис предмету";
	DBGrid1->Columns->Items[3]->Width = 240;
	DBGrid1->Columns->Items[3]->Title->Caption = "Посилання на зразок";
}
void __fastcall TForm7::FormCreate(TObject *Sender)
{
   DBColumnSizes();
}
//---------------------------------------------------------------------------

void __fastcall TForm7::DBGrid1TitleClick(TColumn *Column)
{
	String sortOrder = SortAscending ? " ASC" : " DESC";
	DataModule1->ADOTable2->Sort = Column->Field->FieldName + sortOrder;
	SortAscending = !SortAscending;
}
//---------------------------------------------------------------------------

void __fastcall TForm7::DBGrid1CellClick(TColumn *Column)
{
    try
	{
		String subjectName = DataModule1->DataSource2->DataSet->FieldByName("Name")->AsString;
        DataModule1->ADOQuery1->Close();
        DataModule1->ADOQuery1->SQL->Text = "SELECT Image_name FROM subject WHERE Name = :name";
        DataModule1->ADOQuery1->Parameters->ParamByName("name")->Value = subjectName;  // Використовуємо назву предмета
		DataModule1->ADOQuery1->Open();
        if (!DataModule1->ADOQuery1->FieldByName("Image_name")->IsNull)
        {
			String imagePath = DataModule1->ADOQuery1->FieldByName("Image_name")->AsString;
            if (FileExists(imagePath))
            {
                Image1->Picture->LoadFromFile(imagePath);
            }
            else
            {
                ShowMessage("Файл не знайдено: " + imagePath);
                Image1->Picture->Assign(NULL);
            }
        }
        else
        {
            Image1->Picture->Assign(NULL);
        }
    }
    catch (const Exception &e)
    {
        ShowMessage("Помилка завантаження зображення: " + e.Message);
        Image1->Picture->Assign(NULL);
    }
}

void __fastcall TForm7::N1Click(TObject *Sender)
{
	Form2->set_id(0);
	Form2->Caption = "Додавання даних";
	Form2->ShowModal();
	DataModule1->DataSource2->DataSet->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm7::N2Click(TObject *Sender)
{
	String name = DBGrid1->DataSource->DataSet->FieldByName("Name")->AsString;
	TADOQuery *query = new TADOQuery(this);
	query->Connection = DataModule1->ADOConnection1;
	query->SQL->Text = "SELECT Subject_id FROM subject WHERE Name = :Name";
	query->Parameters->ParamByName("Name")->Value = name;
	query->Open();
	int id = query->FieldByName("Subject_id")->AsInteger;
	Form2->Caption = "Редагування даних";
	Form2->set_id(id);
	Form2->ShowModal();
	DataModule1->DataSource2->DataSet->Refresh();
	delete query;
}

//---------------------------------------------------------------------------

void __fastcall TForm7::N3Click(TObject *Sender)
{
	try
	{
		int id = DataModule1->DataSource2->DataSet->FieldByName("Subject_id")->AsInteger;
        if (id <= 0)
        {
            ShowMessage("Виберіть запис для видалення.");
			return;
		}
        DataModule1->ADOQuery1->Close();
        DataModule1->ADOQuery1->SQL->Text = "SELECT COUNT(*) AS Count FROM result WHERE Subj_id = :id";
        DataModule1->ADOQuery1->Parameters->ParamByName("id")->Value = id;
		DataModule1->ADOQuery1->Open();
		int resultDependentCount = DataModule1->ADOQuery1->FieldByName("Count")->AsInteger;
        DataModule1->ADOQuery1->Close();
        DataModule1->ADOQuery1->SQL->Text = "SELECT COUNT(*) AS Count FROM conditions WHERE Subject_id = :id";
        DataModule1->ADOQuery1->Parameters->ParamByName("id")->Value = id;
		DataModule1->ADOQuery1->Open();
		int conditionsDependentCount = DataModule1->ADOQuery1->FieldByName("Count")->AsInteger;
		if (resultDependentCount > 0 || conditionsDependentCount > 0)
        {
            ShowMessage("Цей запис не може бути видалений, оскільки він використовується в інших таблицях.");
            return;
		}
        if (MessageDlg("Ви впевнені, що хочете видалити цей запис?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
		{
            DataModule1->ADOQuery1->Close();
            DataModule1->ADOQuery1->SQL->Text = "DELETE FROM subject WHERE Subject_id = :id";
            DataModule1->ADOQuery1->Parameters->ParamByName("id")->Value = id;
			DataModule1->ADOQuery1->ExecSQL();
            DataModule1->DataSource2->DataSet->Refresh();

            ShowMessage("Запис успішно видалено.");
        }
    }
    catch (const Exception &e)
    {
        ShowMessage("Помилка видалення запису: " + e.Message);
    }
}




void __fastcall TForm7::Lj1Click(TObject *Sender)
{
   Help_m->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm7::N6Click(TObject *Sender)
{
    this->Close();
   Form3->Show();
}
//---------------------------------------------------------------------------

