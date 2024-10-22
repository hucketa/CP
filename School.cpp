//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "School.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TForm6::Lj1Click(TObject *Sender)
{
	Help_m->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm6::N6Click(TObject *Sender)
{
	this->Close();
	Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::DBColumnSizes(){
	DBGrid1->Columns->Items[0]->Visible = false;
	DBGrid1->Columns->Items[1]->Width = 90;
	DBGrid1->Columns->Items[1]->Title->Caption = "Місто";
	DBGrid1->Columns->Items[2]->Width = 150;
	DBGrid1->Columns->Items[2]->Title->Caption = "Регіон";
	DBGrid1->Columns->Items[3]->Width = 90;
	DBGrid1->Columns->Items[3]->Title->Caption = "Тип";
	DBGrid1->Columns->Items[4]->Width = 140;
	DBGrid1->Columns->Items[4]->Title->Caption = "E-mail";
	DBGrid1->Columns->Items[5]->Width = 150;
	DBGrid1->Columns->Items[5]->Title->Caption = "ПІБ відповідального";
}

void __fastcall TForm6::FormShow(TObject *Sender)
{
   DBColumnSizes();
}

//---------------------------------------------------------------------------
void __fastcall TForm6::N3Click(TObject *Sender) {
	try {
		int id = DataModule1->ADOTable3->FieldByName("School_id")->AsInteger;
		if (id <= 0) {
            ShowMessage("Виберіть запис для видалення.");
            return;
		}
		DataModule1->ADOQuery1->Close();
		DataModule1->ADOQuery1->SQL->Text = "SELECT COUNT(*) AS Count FROM result WHERE School_id = :id";
		DataModule1->ADOQuery1->Parameters->ParamByName("id")->Value = id;
		DataModule1->ADOQuery1->Open();
		int resultDependentCount = DataModule1->ADOQuery1->FieldByName("Count")->AsInteger;
		DataModule1->ADOQuery1->Close();
        if (resultDependentCount > 0) {
            ShowMessage("Цей запис не може бути видалений, оскільки він використовується в таблиці 'result'.");
            return;
		}
        if (MessageDlg("Ви впевнені, що хочете видалити цей запис?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
			try {
				DataModule1->ADOQuery1->Close();
				DataModule1->ADOQuery1->SQL->Text = "DELETE FROM school WHERE School_id = :id";
				DataModule1->ADOQuery1->Parameters->ParamByName("id")->Value = id;
				DataModule1->ADOQuery1->ExecSQL();
                ShowMessage("Запис успішно видалено.");
				DataModule1->ADOTable3->Close();
				DataModule1->ADOTable3->Open();
            }
            catch (const Exception &e) {
                ShowMessage("Помилка при видаленні запису: " + e.Message);
            }
        }
    }
    catch (const Exception &e) {
        ShowMessage("Помилка видалення запису: " + e.Message);
	}
	DBColumnSizes();
}



//---------------------------------------------------------------------------
void __fastcall TForm6::N1Click(TObject *Sender)
{
	Form8->set_id(0);
	Form8->Caption = "Додавання даних";
	Form8->ShowModal();
	DBColumnSizes();
}
//---------------------------------------------------------------------------
void __fastcall TForm6::N2Click(TObject *Sender)
{
	int school_id = DataModule1->ADOTable3->FieldByName("School_id")->AsInteger;
	Form8->set_id(school_id);
	Form8->Caption = "Редагування даних";
	Form8->ShowModal();
	DBColumnSizes();
}

//---------------------------------------------------------------------------
void __fastcall TForm6::DBGrid1TitleClick(TColumn *Column)
{
	String sortOrder = SortAscending ? " ASC" : " DESC";
	DataModule1->ADOTable3->Sort = Column->Field->FieldName + sortOrder;
	SortAscending = !SortAscending;
}
//---------------------------------------------------------------------------
