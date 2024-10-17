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
	DBGrid1->Columns->Items[1]->Title->Caption = "����� ��������";
	DBGrid1->Columns->Items[2]->Width = 250;
	DBGrid1->Columns->Items[2]->Title->Caption = "���� ��������";
	DBGrid1->Columns->Items[3]->Width = 240;
	DBGrid1->Columns->Items[3]->Title->Caption = "��������� �� ������";
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
        DataModule1->ADOQuery1->Parameters->ParamByName("name")->Value = subjectName;  // ������������� ����� ��������
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
                ShowMessage("���� �� ��������: " + imagePath);
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
        ShowMessage("������� ������������ ����������: " + e.Message);
        Image1->Picture->Assign(NULL);
    }
}

//---------------------------------------------------------------------------

void __fastcall TForm7::FormClose(TObject *Sender, TCloseAction &Action)
{
    Action = caFree;
	Application->Terminate();
}
//---------------------------------------------------------------------------




void __fastcall TForm7::N1Click(TObject *Sender)
{
	Form2 = new TForm2(this);
	Form2->set_id(0);
	Form2->Caption = "��������� �����";
	Form2->ShowModal();
	DataModule1->DataSource2->DataSet->Refresh();
	delete Form2;
}
//---------------------------------------------------------------------------

void __fastcall TForm7::N2Click(TObject *Sender)
{
	int id = DBGrid1->DataSource->DataSet->RecNo;
	Form2 = new TForm2(this);
	Form2->Caption = "����������� �����";
	Form2->set_id(id);
	Form2->ShowModal();
	DataModule1->DataSource2->DataSet->Refresh();
	delete Form2;
}
//---------------------------------------------------------------------------

void __fastcall TForm7::N3Click(TObject *Sender)
{
    try
    {
        // ��������� ID ��������� ������ � DBGrid
        int id = DataModule1->DataSource2->DataSet->FieldByName("Subject_id")->AsInteger;

        // ��������, �� ���� ID
        if (id <= 0)
        {
            ShowMessage("������� ����� ��� ���������.");
            return;
        }

        // �������� �������� �������� ������ � ������� 'result'
        DataModule1->ADOQuery1->Close();
        DataModule1->ADOQuery1->SQL->Text = "SELECT COUNT(*) AS Count FROM result WHERE Subj_id = :id";
        DataModule1->ADOQuery1->Parameters->ParamByName("id")->Value = id;
        DataModule1->ADOQuery1->Open();

        int resultDependentCount = DataModule1->ADOQuery1->FieldByName("Count")->AsInteger;

        // �������� �������� �������� ������ � ������� 'conditions'
        DataModule1->ADOQuery1->Close();
        DataModule1->ADOQuery1->SQL->Text = "SELECT COUNT(*) AS Count FROM conditions WHERE Subject_id = :id";
        DataModule1->ADOQuery1->Parameters->ParamByName("id")->Value = id;
        DataModule1->ADOQuery1->Open();

        int conditionsDependentCount = DataModule1->ADOQuery1->FieldByName("Count")->AsInteger;

        // ���� � ������ ������, ���������� ����������� �� ���������� ���������
        if (resultDependentCount > 0 || conditionsDependentCount > 0)
        {
            ShowMessage("��� ����� �� ���� ���� ���������, ������� �� ��������������� � ����� ��������.");
            return;
        }

        // ϳ����������� �� �����������
        if (MessageDlg("�� �������, �� ������ �������� ��� �����?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
        {
            // ��������� SQL-������ �� ���������
            DataModule1->ADOQuery1->Close();
            DataModule1->ADOQuery1->SQL->Text = "DELETE FROM subject WHERE Subject_id = :id";
            DataModule1->ADOQuery1->Parameters->ParamByName("id")->Value = id;
            DataModule1->ADOQuery1->ExecSQL();

            // ��������� DataSet ��� ����������� ���
            DataModule1->DataSource2->DataSet->Refresh();

            ShowMessage("����� ������ ��������.");
        }
    }
    catch (const Exception &e)
    {
        ShowMessage("������� ��������� ������: " + e.Message);
    }
}




void __fastcall TForm7::Lj1Click(TObject *Sender)
{
   Help_m = new THelp_m(this);
   Help_m->ShowModal();
   delete Help_m;
}
//---------------------------------------------------------------------------

void __fastcall TForm7::N6Click(TObject *Sender)
{
   this->Hide();
   Form3 = new TForm3(this);
   Form3->Show();
}
//---------------------------------------------------------------------------

