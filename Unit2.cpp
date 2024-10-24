#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Data.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner) : TForm(Owner) {}

void __fastcall TForm2::Edit1Exit(TObject *Sender)
{
	if (Edit1->Text.Trim().IsEmpty())
    {
		ShowMessage("���� '���� �� ����������' �� ���� ���� �������.");
    }
	else if (!FileExists(Edit1->Text))
    {
		ShowMessage("���� ���������� �� �������� �� �������� ������.");
    }
	else if (Edit1->Text.SubString(Edit1->Text.Length() - 3, 4).LowerCase() != ".jpg" &&
			 Edit1->Text.SubString(Edit1->Text.Length() - 3, 4).LowerCase() != ".png")
	{
		ShowMessage("���� ���������� ������� ���� ���������� .jpg ��� .png.");
    }
}

void __fastcall TForm2::Edit2Exit(TObject *Sender)
{
    if (Edit2->Text.Trim().IsEmpty())
    {
		ShowMessage("���� '����� ��������' �� ���� ���� �������.");
    }
    else if (Edit2->Text.Length() > 100)
    {
		ShowMessage("����� �������� �� ���� ������������ 100 �������.");
    }
    else
    {
        try
        {
            String subjectName = Edit2->Text.Trim();

            // �������� �� ���������� Name
            DataModule1->ADOQuery1->Close();
            DataModule1->ADOQuery1->SQL->Text = "SELECT COUNT(*) AS Count FROM subject WHERE Name = :subjectName";
            DataModule1->ADOQuery1->Parameters->ParamByName("subjectName")->Value = subjectName;
            DataModule1->ADOQuery1->Open();

            int count = DataModule1->ADOQuery1->FieldByName("Count")->AsInteger;

			if (count > 0 && id == 0)
			{
				ShowMessage("����� �������� ��� ����. ���� �����, ������� ���� �����.");
            }
        }
        catch (const Exception &e)
        {
			ShowMessage("������� �������� ����������: " + e.Message);
        }
    }
}


void __fastcall TForm2::Edit4Exit(TObject *Sender)
{
	if (Edit4->Text.Length() > 40)
    {
        ShowMessage("���� �� ���� ������������ 40 �������.");
    }
}

void __fastcall TForm2::Button2Click(TObject *Sender)
{
	if (OpenPictureDialog1->Execute())
    {
		Edit1->Text = OpenPictureDialog1->FileName;
		if (!FileExists(Edit1->Text))
        {
            ShowMessage("���� ���������� �� �������� �� �������� ������.");
        }
    }
}

void __fastcall TForm2::set_id(int k)
{
    id = k;
    if (id > 0)
    {
        try
        {
            DataModule1->ADOQuery1->Close();
            DataModule1->ADOQuery1->SQL->Text = "SELECT Image_name, Name, Description FROM subject WHERE Subject_id = :id";
            DataModule1->ADOQuery1->Parameters->ParamByName("id")->Value = id;
            DataModule1->ADOQuery1->Open();

            if (!DataModule1->ADOQuery1->Eof)
            {
                Edit1->Text = DataModule1->ADOQuery1->FieldByName("Image_name")->AsString;
                Edit2->Text = DataModule1->ADOQuery1->FieldByName("Name")->AsString;
                Edit4->Text = DataModule1->ADOQuery1->FieldByName("Description")->AsString;
            }
            else
            {
                ShowMessage("����� � �������� ID �� ��������.");
            }
        }
        catch (const Exception &e)
        {
            ShowMessage("������� ������������ ����� ��� �����������: " + e.Message);
        }
    }
    else
    {
        Edit1->Clear();
        Edit2->Clear();
        Edit4->Clear();
    }
}

void __fastcall TForm2::Button1Click(TObject *Sender)
{
    try
    {
        if (Edit1->Text.Trim().IsEmpty() || Edit2->Text.Trim().IsEmpty() || Edit4->Text.Trim().IsEmpty())
        {
            ShowMessage("�� ���� ������ ���� �������� ����� ���������� ��� ����������.");
            return;
        }

        String imagePath = Edit1->Text.Trim();
        String subjectName = Edit2->Text.Trim();
        String description = Edit4->Text.Trim();

        if (id > 0)  // ���� id ����� 0, �� ��������� �����
        {
            DataModule1->ADOQuery1->Close();
            DataModule1->ADOQuery1->SQL->Text = "UPDATE subject SET Image_name = :imagePath, Name = :subjectName, Description = :description WHERE Subject_id = :id";
            DataModule1->ADOQuery1->Parameters->ParamByName("imagePath")->Value = imagePath;
            DataModule1->ADOQuery1->Parameters->ParamByName("subjectName")->Value = subjectName;
            DataModule1->ADOQuery1->Parameters->ParamByName("description")->Value = description;
            DataModule1->ADOQuery1->Parameters->ParamByName("id")->Value = id;
            DataModule1->ADOQuery1->ExecSQL();

            ShowMessage("����� ������ ��������.");
        }
        else  // ���� id ������� 0, ������ ����� �����
        {
            DataModule1->ADOQuery1->Close();
            DataModule1->ADOQuery1->SQL->Text = "INSERT INTO subject (Image_name, Name, Description) VALUES (:imagePath, :subjectName, :description)";
            DataModule1->ADOQuery1->Parameters->ParamByName("imagePath")->Value = imagePath;
            DataModule1->ADOQuery1->Parameters->ParamByName("subjectName")->Value = subjectName;
            DataModule1->ADOQuery1->Parameters->ParamByName("description")->Value = description;
            DataModule1->ADOQuery1->ExecSQL();

            ShowMessage("����� ����� ������ ������ �� ���� �����.");
        }

		DataModule1->DataSource2->DataSet->Close();
		DataModule1->DataSource2->DataSet->Open();

		Close();
	}
	catch (const Exception &e)
    {
        ShowMessage("������� ������� ������: " + e.Message);
    }
}


void __fastcall TForm2::FormShow(TObject *Sender)
{
	if(id>0) Button1->Caption = "ϳ���������";
	else  Button1->Caption = "������";
}
//---------------------------------------------------------------------------

