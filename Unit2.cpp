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

bool TForm2::IsValidUkrainianText(const String &text) {
    for (int i = 1; i <= text.Length(); i++) {
		wchar_t c = text[i];
		if (!((c >= L'�' && c <= L'�') || (c >= L'�' && c <= L'�') ||
              c == L'�' || c == L'�' || c == L'�' || c == L'�' ||
              c == L'�' || c == L'�' || c == L' ' || c == L'\'' || c == L'-')) {
            return false;
        }
    }
    return true;
}

void __fastcall TForm2::Edit1Exit(TObject *Sender)
{
    if (Edit1->Text.Trim().IsEmpty())
    {
        ShowMessage("���� '���� �� ����������' �� ���� ���� ��������.");
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
        ShowMessage("���� '����� ��������' �� ���� ���� ��������.");
        Edit2->SetFocus();
    }
    else if (Edit2->Text.Length() > 100)
    {
        ShowMessage("����� �������� �� ���� ������������ 100 �������.");
        Edit2->SetFocus();
    }
    else if (!IsValidUkrainianText(Edit2->Text))
    {
        ShowMessage("����� �������� ������� ������ ���� �������� �����, �����, �������� ��� �����.");
        Edit2->SetFocus();
    }
    else
    {
        try
        {
            String subjectName = Edit2->Text.Trim();
            DataModule1->ADOQuery1->Close();
            DataModule1->ADOQuery1->SQL->Text = "SELECT COUNT(*) AS Count FROM subject WHERE Name = :subjectName";
            DataModule1->ADOQuery1->Parameters->ParamByName("subjectName")->Value = subjectName;
            DataModule1->ADOQuery1->Open();

            int count = DataModule1->ADOQuery1->FieldByName("Count")->AsInteger;
            if (count > 0 && id == 0)
            {
                ShowMessage("����� �������� ��� ����. ���� �����, ������� ���� �����.");
                Edit2->SetFocus();
            }
        }
        catch (const Exception &e)
        {
            ShowMessage("������� �������� �����������: " + e.Message);
        }
    }
}

void __fastcall TForm2::Edit4Exit(TObject *Sender)
{
    if (Edit4->Text.Length() > 40)
    {
        ShowMessage("���� �� ���� ������������ 40 �������.");
        Edit4->SetFocus();
    }
    else if (!IsValidUkrainianText(Edit4->Text))
    {
        ShowMessage("���� ������� ������ ���� �������� �����, �����, �������� ��� �����.");
        Edit4->SetFocus();
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
            DataModule1->ADOQuery1->SQL->Text = "SELECT Image_name, Name, Description, Test_sample FROM subject WHERE Subject_id = :id";
            DataModule1->ADOQuery1->Parameters->ParamByName("id")->Value = id;
            DataModule1->ADOQuery1->Open();
            if (!DataModule1->ADOQuery1->Eof)
            {
                Edit1->Text = DataModule1->ADOQuery1->FieldByName("Image_name")->AsString;
                Edit2->Text = DataModule1->ADOQuery1->FieldByName("Name")->AsString;
                Edit4->Text = DataModule1->ADOQuery1->FieldByName("Description")->AsString;
                Edit3->Text = DataModule1->ADOQuery1->FieldByName("Test_sample")->AsString;
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
        Edit3->Clear();
    }
}

void __fastcall TForm2::Button1Click(TObject *Sender)
{
    try
    {
        if (Edit1->Text.Trim().IsEmpty() || Edit2->Text.Trim().IsEmpty() || Edit4->Text.Trim().IsEmpty())
        {
            ShowMessage("�� ���� ������� ���� ��������� ����� ���������� ��� ����������.");
            return;
        }
        String imagePath = Edit1->Text.Trim();
        String subjectName = Edit2->Text.Trim();
        String description = Edit4->Text.Trim();
        String testSamplePath = Edit3->Text.Trim();

        if (id > 0)
        {
            DataModule1->ADOQuery1->Close();
            DataModule1->ADOQuery1->SQL->Text = "UPDATE subject SET Image_name = :imagePath, Name = :subjectName, Description = :description, Test_sample = :testSamplePath WHERE Subject_id = :id";
            DataModule1->ADOQuery1->Parameters->ParamByName("imagePath")->Value = imagePath;
            DataModule1->ADOQuery1->Parameters->ParamByName("subjectName")->Value = subjectName;
            DataModule1->ADOQuery1->Parameters->ParamByName("description")->Value = description;
            if (!testSamplePath.IsEmpty())
                DataModule1->ADOQuery1->Parameters->ParamByName("testSamplePath")->Value = testSamplePath;
            else
                DataModule1->ADOQuery1->Parameters->ParamByName("testSamplePath")->Value = Variant();
            DataModule1->ADOQuery1->Parameters->ParamByName("id")->Value = id;
            DataModule1->ADOQuery1->ExecSQL();
            ShowMessage("����� ������ ��������.");
        }
        else
        {
            DataModule1->ADOQuery1->Close();
            DataModule1->ADOQuery1->SQL->Text = "INSERT INTO subject (Image_name, Name, Description, Test_sample) VALUES (:imagePath, :subjectName, :description, :testSamplePath)";
            DataModule1->ADOQuery1->Parameters->ParamByName("imagePath")->Value = imagePath;
            DataModule1->ADOQuery1->Parameters->ParamByName("subjectName")->Value = subjectName;
            DataModule1->ADOQuery1->Parameters->ParamByName("description")->Value = description;
            if (!testSamplePath.IsEmpty())
                DataModule1->ADOQuery1->Parameters->ParamByName("testSamplePath")->Value = testSamplePath;
            else
                DataModule1->ADOQuery1->Parameters->ParamByName("testSamplePath")->Value = Variant();
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
    if (id > 0) Button1->Caption = "ϳ���������";
    else  Button1->Caption = "������";
}

void __fastcall TForm2::Button3Click(TObject *Sender)
{
    TOpenDialog *OpenDialog = new TOpenDialog(this);
    OpenDialog->Filter = "��������� Word ��� PDF|*.docx;*.pdf";
    if (OpenDialog->Execute())
    {
        Edit3->Text = OpenDialog->FileName;
    }
    delete OpenDialog;
}

void __fastcall TForm2::Edit3Exit(TObject *Sender)
{
    String testSamplePath = Edit3->Text.Trim();

    if (!testSamplePath.IsEmpty() && !FileExists(testSamplePath))
    {
        ShowMessage("���� �� �������� �� �������� ������.");
    }
    else if (!testSamplePath.IsEmpty() &&
             !(testSamplePath.SubString(testSamplePath.Length() - 3, 4).LowerCase() == ".docx" ||
               testSamplePath.SubString(testSamplePath.Length() - 3, 4).LowerCase() == ".pdf"))
    {
        ShowMessage("���� �� ���� � ������ .docx ��� .pdf.");
    }
}

