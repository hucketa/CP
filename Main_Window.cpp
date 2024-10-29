//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <SysUtils.hpp>
#include "Main_Window.h"
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
	ThisDate->OnClick = CheckFiltersFilled;
	Status_check->OnClick = CheckFiltersFilled;
	Edit1->OnChange = CheckFiltersFilled;
	UpdateStatusBar("����������");
}

//---------------------------------------------------------------------------

void TForm3::DBColumnSizes(){
	DBGrid1->Columns->Items[0]->Width = 150;
	DBGrid1->Columns->Items[0]->Title->Caption = "ϲ�";
	DBGrid1->Columns->Items[1]->Width = 100;
	DBGrid1->Columns->Items[1]->Title->Caption = "���� ���������";
	DBGrid1->Columns->Items[2]->Width = 60;
	DBGrid1->Columns->Items[2]->Title->Caption = "������";
	DBGrid1->Columns->Items[3]->Width = 125;
	DBGrid1->Columns->Items[3]->Title->Caption = "�������";
	DBGrid1->Columns->Items[4]->Width = 85;
	DBGrid1->Columns->Items[4]->Title->Caption = "���������";
}

void __fastcall TForm3::CheckFiltersFilled(TObject *Sender)
{
	bool isAnyFilterFilled = false;
	if (ThisDate->Checked) isAnyFilterFilled = true;
	if (Status_check->ItemIndex >= 0) isAnyFilterFilled = true;
	if (!Edit1->Text.Trim().IsEmpty()) isAnyFilterFilled = true;
	Execute->Enabled = isAnyFilterFilled;
	Clear->Enabled = isAnyFilterFilled;
}

void __fastcall TForm3::FormShow(TObject *Sender)
{
	DBColumnSizes();
	String tmp_role = "User";
	UpdateStatusBar(tmp_role);
	ManageMenuItems(tmp_role);
	Application->ProcessMessages();
}

void __fastcall TForm3::ClearClick(TObject *Sender)
{
	DatePicker1->Date = Now();
	ThisDate->Checked = false;
	Status_check->ItemIndex = -1;
	Edit1->Text = "";
	Execute->Enabled = false;
	Clear->Enabled = false;
	String query = "SELECT s.PIB, "
				   "r.Attemp_date, "
				   "CASE WHEN r.Status = 1 THEN '�����' ELSE '�� �����' END, "
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
		ShowMessage("������� ��� ������� �������: " + e.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::ExecuteClick(TObject *Sender)
{
    String query = "SELECT s.PIB, r.Attemp_date, CASE WHEN r.Status = 1 THEN '�����' ELSE '�� �����' END AS Status, subj.Name, r.Reached_score "
                   "FROM Result r "
                   "JOIN Student s ON r.Student_id = s.Student_id "
                   "JOIN Subject subj ON r.Subj_id = subj.Subject_id ";
    String conditions = "";

	if (ThisDate->Checked && DatePicker1->Date != TDateTime() && DatePicker2->Date != TDateTime())
	{
		if ((double)DatePicker1->Date <= (double)DatePicker2->Date)
		{
			conditions += "r.Attemp_date BETWEEN :DateStart AND :DateEnd ";
		}
		else
		{
			ShowMessage("���� ���� ��������� �� ���� ����� �� ���������!");
			return;
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

        if (ThisDate->Checked && DatePicker1->Date != TDateTime() && DatePicker2->Date != TDateTime())
        {
            DataModule1->MainQuery->Parameters->ParamByName("DateStart")->Value = DatePicker1->Date.FormatString("yyyy-mm-dd");
            DataModule1->MainQuery->Parameters->ParamByName("DateEnd")->Value = DatePicker2->Date.FormatString("yyyy-mm-dd");
        }

        if (!Edit1->Text.Trim().IsEmpty())
        {
            DataModule1->MainQuery->Parameters->ParamByName("Surname")->Value = "%" + Edit1->Text.Trim() + "%";
        }

        DataModule1->MainQuery->Open();
        DBColumnSizes();
    }
    catch (const Exception &e)
    {
        ShowMessage("������� ��� ����������: " + e.Message);
    }
}

//---------------------------------------------------------------------------

void __fastcall TForm3::Lj1Click(TObject *Sender)
{
   Help_m->ShowModal();
}



void __fastcall TForm3::N11Click(TObject *Sender)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N2Click(TObject *Sender)
{
	Form14->ShowModal();
}

void __fastcall TForm3::N4Click(TObject *Sender)
{
   Form7->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N3Click(TObject *Sender)
{
   Form4->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::DatePicker1CloseUp(TObject *Sender)
{
	try
	{
		TDateTime selectedDate = DatePicker1->Date;
		TDateTime currentDate = Now();
		if (selectedDate > currentDate)
		{
			throw Exception("���� �� ���� ���� � �����������!");
		}
		else if(selectedDate < EncodeDate(1925, 1, 1))
		{
			throw Exception("���� ������� �����! ������� ����� ����.");
		}
	}
	catch (const Exception &e)
	{
		ShowMessage(e.Message);
		DatePicker1->Date = Now();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Edit1Exit(TObject *Sender)
{
    String pib = Edit1->Text;
    UnicodeString pattern = "^[�-��-�����������'\\s-]+$";
	if (!TRegEx::IsMatch(pib, pattern)) {
		ShowMessage("������ ������ ϲ� ���������� ����� �������.");
    }
}

//---------------------------------------------------------------------------



void __fastcall TForm3::N9Click(TObject *Sender)
{
    Form6->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N5Click(TObject *Sender)
{
	Form11->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::DBGrid1TitleClick(TColumn *Column)
{
    String columnName = Column->FieldName;
    static bool sortAsc = true;
    String sortOrder = sortAsc ? "ASC" : "DESC";
    sortAsc = !sortAsc;

    String query =
        "SELECT s.PIB, "
        "r.Attemp_date, "
        "CASE WHEN r.Status = 1 THEN '�����' ELSE '�������' END AS Status, "
        "subj.Name, "
        "r.Reached_score "
        "FROM Result r "
        "JOIN Student s ON r.Student_id = s.Student_id "
        "JOIN Subject subj ON r.Subj_id = subj.Subject_id "
		"ORDER BY " + columnName + " " + sortOrder;

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
        ShowMessage("������� ����������: " + e.Message);
    }
}


void __fastcall TForm3::N1Click(TObject *Sender)
{
    Certificates->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::UpdateStatusBar(String role)
{
	if (role == "�������� ����")
	{
		StatusBar1->Panels->Items[2]->Text = "�������� ��������: ������ ������ �� ����� ��������";
	}
	else if (role == "�������� ��������")
	{
		StatusBar1->Panels->Items[2]->Text = "�������� ��������: ������ �� ���������� ��������";
	}
	else if (role == "�������� ����������")
	{
		StatusBar1->Panels->Items[2]->Text = "�������� ����������: ������ �� ���������� � �����������";
	}
	else
	{
		StatusBar1->Panels->Items[2]->Text = "������� ����: ��������� ������";
	}
}

void TForm3::ManageMenuItems(String role)
{
    	Form7->N1->Enabled = false;//��������
		Form7->N2->Enabled = false;//��������
		Form7->N3->Enabled = false;//��������
		Form14->N1->Enabled = false;//���
		Form14->N2->Enabled = false;//���
		Form4->N3->Enabled = false;//�����
		Form4->N2->Enabled = false;//�����
		Form6->N1->Enabled = false;//�����
		Form6->N2->Enabled = false;//�����
		Form6->N3->Enabled = false;//�����
		Certificates->N3->Enabled = false;
		Certificates->N2->Enabled = false;
		Certificates->N4->Enabled = false;
		Certificates->BitBtn1->Enabled = false;
		Form11->N3->Enabled = false;//����������
		Form11->N2->Enabled = false;//����������
	if (role == "�������� ����")
	{
		Form7->N1->Enabled = false;//��������
		Form7->N2->Enabled = false;//��������
		Form7->N3->Enabled = false;//��������
		Form14->N1->Enabled = true;//���
		Form14->N2->Enabled = true;//���
		Form4->N3->Enabled = false;//�����
		Form4->N2->Enabled = false;//�����
		Form6->N1->Enabled = false;//�����
		Form6->N2->Enabled = false;//�����
		Form6->N3->Enabled = false;//�����
		Form4->N2->Enabled = false;//�����
		Certificates->N3->Enabled = false;
		Certificates->N2->Enabled = false;
		Certificates->N4->Enabled = false;
		Certificates->BitBtn1->Enabled = false;
		Form11->N3->Enabled = false;//����������
		Form11->N2->Enabled = false;//����������
	}
	else if (role == "�������� ��������")
	{
		Form7->N1->Enabled = true;//��������
		Form7->N2->Enabled = true;//��������
		Form7->N3->Enabled = true;//��������
		Form14->N1->Enabled = false;//���
		Form14->N2->Enabled = false;//���
		Form4->N3->Enabled = true;//�����
		Form4->N2->Enabled = true;//�����
		Form6->N1->Enabled = true;//�����
		Form6->N2->Enabled = true;//�����
		Form6->N3->Enabled = true;//�����
		Certificates->N3->Enabled = false;
		Certificates->N2->Enabled = false;
		Certificates->BitBtn1->Enabled = false;
		Certificates->N4->Enabled = false;
		Form11->N3->Enabled = false;//����������
		Form11->N2->Enabled = false;//����������
	}
	else if (role == "�������� ����������")
	{
		Form7->N1->Enabled = false;//��������
		Form7->N2->Enabled = false;//��������
		Form7->N3->Enabled = false;//��������
		Form14->N1->Enabled = false;//���
		Form14->N2->Enabled = false;//���
		Form4->N3->Enabled = false;//�����
		Form4->N2->Enabled = false;//�����
		Form6->N1->Enabled = false;//�����
		Form6->N2->Enabled = false;//�����
		Form6->N3->Enabled = false;//�����
		Certificates->N3->Enabled = true;
		Certificates->N2->Enabled = true;
		Certificates->N4->Enabled = true;
		Certificates->BitBtn1->Enabled = true;
		Form11->N3->Enabled = true;//����������
		Form11->N2->Enabled = true;
		//����������
	}
}



//---------------------------------------------------------------------------

void __fastcall TForm3::N12Click(TObject *Sender)
{
	Form12->ShowModal();
	if (Form12->get_flag())
	{
		UpdateStatusBar(Form12->get_role());
		ManageMenuItems(Form12->get_role());
		Application->ProcessMessages();
	}
	else
	{
		ShowMessage("����������� �� �������. ������ ��������.");
        String user = "user";
		UpdateStatusBar(user);
		ManageMenuItems(user);
		Application->ProcessMessages();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N13Click(TObject *Sender)
{
		String user = "user";
		UpdateStatusBar(user);
		ManageMenuItems(user);
		Application->ProcessMessages();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::DatePicker2CloseUp(TObject *Sender)
{
   try
	{
		TDateTime selectedDate = DatePicker2->Date;
		TDateTime currentDate = Now();
		if (selectedDate > currentDate)
		{
			throw Exception("���� �� ���� ���� � �����������!");
		}
		else if(selectedDate < EncodeDate(1925, 1, 1))
		{
			throw Exception("���� ������� �����! ������� ����� ����.");
		}
	}
	catch (const Exception &e)
	{
		ShowMessage(e.Message);
		DatePicker2->Date = Now();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N14Click(TObject *Sender)
{
    Application->Terminate();
}
//---------------------------------------------------------------------------

