//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Certificate.h"
#include <System.DateUtils.hpp>
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
	DBGrid2->Columns->Items[1]->Title->Caption = "ПІБ учасника";
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
	ThisDate->OnClick = CheckFiltersFilled;
	RadioGroup1->OnClick = CheckFiltersFilled;
}

//---------------------------------------------------------------------------

void __fastcall TCertificates::CheckFiltersFilled(TObject *Sender)
{
	bool isAnyFilterFilled = ThisDate->Checked || (RadioGroup1->ItemIndex != -1);
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
    {
		if (DatePicker1->Date > DatePicker2->Date)
        {
            ShowMessage("Дата початку повинна бути раніше дати завершення!");
            return;
		}
        conditions += "certificate.Creation_date BETWEEN :DateStart AND :DateEnd ";
    }

	if (RadioGroup1->ItemIndex != -1)
    {
        if (!conditions.IsEmpty())
            conditions += " AND ";
		int statusValue = RadioGroup1->ItemIndex == 0 ? 1 : 0;
        conditions += "certificate.Status = :Status";
    }

	if (!conditions.IsEmpty())
        query += " WHERE " + conditions;

    query += " ORDER BY certificate.Creation_date DESC";

    try
    {
        DataModule1->ADOQuery4->Close();
		DataModule1->ADOQuery4->SQL->Clear();
		DataModule1->ADOQuery4->SQL->Add(query);

		if (ThisDate->Checked)
		{
			DataModule1->ADOQuery4->Parameters->ParamByName("DateStart")->Value = DatePicker1->Date.FormatString("yyyy-mm-dd");
			DataModule1->ADOQuery4->Parameters->ParamByName("DateEnd")->Value = DatePicker2->Date.FormatString("yyyy-mm-dd");
		}

        if (RadioGroup1->ItemIndex != -1)
		{
			int statusValue = RadioGroup1->ItemIndex == 0 ? 1 : 0;
			DataModule1->ADOQuery4->Parameters->ParamByName("Status")->Value = statusValue;
		}

		DataModule1->ADOQuery4->Open();
		DBColumnSizes();

		int recordCount = DataModule1->ADOQuery4->RecordCount;
		StatusBar1->Panels->Items[0]->Text = "Кількість сертифікатів: " + IntToStr(recordCount);
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
	ThisDate->Checked = false;
	RadioGroup1->ItemIndex = -1;

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
        StatusBar1->Panels->Items[0]->Text = " ";
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

void __fastcall TCertificates::BitBtn1Click(TObject *Sender)
{
	try
	{
		String enteredPIN = LabeledEdit1->Text.Trim();
		String query = "SELECT certificate.Cerf_num, student.PIB, certificate.PIN, certificate.Creation_date, certificate.Effect_time, "
					   "certificate.Student_id, "
					   "CASE WHEN certificate.Status = 1 THEN 'Дійсний' ELSE 'Не дійсний' END AS Status "
					   "FROM certificate "
					   "JOIN student ON certificate.Student_id = student.Student_id "
					   "WHERE certificate.PIN = :PIN";
		DataModule1->ADOQuery1->Close();
		DataModule1->ADOQuery1->SQL->Clear();
		DataModule1->ADOQuery1->SQL->Add(query);
		DataModule1->ADOQuery1->Parameters->ParamByName("PIN")->Value = enteredPIN;
		DataModule1->ADOQuery1->Open();
		if (DataModule1->ADOQuery1->RecordCount > 0)
		{
			String cerf_num = DataModule1->ADOQuery1->FieldByName("Cerf_num")->AsString;
			String pib = DataModule1->ADOQuery1->FieldByName("PIB")->AsString;
			String pin = DataModule1->ADOQuery1->FieldByName("PIN")->AsString;
			String creation_date = DataModule1->ADOQuery1->FieldByName("Creation_date")->AsString;
			String effect_time = DataModule1->ADOQuery1->FieldByName("Effect_time")->AsString;
			int student_id = DataModule1->ADOQuery1->FieldByName("Student_id")->AsInteger;

			String resultQuery = "SELECT result.Reached_score AS Reached_score, result.Subj_id AS SubjectID "
								 "FROM result "
								 "WHERE result.Student_id = :StudentID";
			DataModule1->ADOQuery2->Close();
			DataModule1->ADOQuery2->SQL->Clear();
			DataModule1->ADOQuery2->SQL->Add(resultQuery);
			DataModule1->ADOQuery2->Parameters->ParamByName("StudentID")->Value = student_id;
			DataModule1->ADOQuery2->Open();

			TStringList *results = new TStringList();
			while (!DataModule1->ADOQuery2->Eof)
			{
				int subject_id = DataModule1->ADOQuery2->FieldByName("SubjectID")->AsInteger;
				double reached_score = DataModule1->ADOQuery2->FieldByName("Reached_score")->AsFloat;
				String subjectQuery = "SELECT subject.Name AS Subject, conditions.Max_point AS Max_point, conditions.Min_r_point AS Min_r_point "
									  "FROM subject "
									  "JOIN conditions ON subject.Subject_id = conditions.Subject_id "
									  "WHERE subject.Subject_id = :SubjectID";
				DataModule1->ADOQuery3->Close();
				DataModule1->ADOQuery3->SQL->Clear();
				DataModule1->ADOQuery3->SQL->Add(subjectQuery);
				DataModule1->ADOQuery3->Parameters->ParamByName("SubjectID")->Value = subject_id;
				DataModule1->ADOQuery3->Open();

				if (DataModule1->ADOQuery3->RecordCount > 0)
				{
					String subject = DataModule1->ADOQuery3->FieldByName("Subject")->AsString;
					double max_point = DataModule1->ADOQuery3->FieldByName("Max_point")->AsFloat;
					double min_r_point = DataModule1->ADOQuery3->FieldByName("Min_r_point")->AsFloat;
					double score_200;
					if (reached_score < min_r_point)
					{
						score_200 = 100.0;
					}
					else if (reached_score >= max_point)
					{
						score_200 = 200.0;
					}
					else
					{
						score_200 = 100.0 + ((reached_score - min_r_point) / (max_point - min_r_point)) * 100.0;
					}
					results->Add("<div class='result-item'>");
					results->Add("<p>Предмет: <span class='highlight'>" + subject + "</span></p>");
					results->Add("<p>Набрані бали (200-бальна шкала): <span class='highlight'>" + FloatToStrF(score_200, ffFixed, 7, 2) + "</span></п>");
					results->Add("</div>");
				}
				DataModule1->ADOQuery2->Next();
			}
			SaveDialog1->Filter = "HTML files (*.html)|*.html";
			SaveDialog1->DefaultExt = "html";
			String currentDateTime = FormatDateTime("yyyy_mm_dd_hh_nn_ss", Now());
			SaveDialog1->FileName = Form13->template_name + "_" + currentDateTime + ".html";
			if (SaveDialog1->Execute())
			{
				String filePath = SaveDialog1->FileName;
				TStringList *htmlFile = new TStringList();
				htmlFile->Text = "";
				try
				{
					htmlFile->Add("<!DOCTYPE html>");
					htmlFile->Add("<html lang='uk'>");
					htmlFile->Add("<head>");
					htmlFile->Add("    <meta charset='UTF-8'>");
					htmlFile->Add("    <meta name='viewport' content='width=device-width, initial-scale=1.0'>");
					htmlFile->Add("    <title>Сертифікат НМТ</title>");
					htmlFile->Add("    <style>");
					htmlFile->Add("        body { font-family: Arial, sans-serif; margin: 20px; }");
					htmlFile->Add("        .certificate { border: 5px solid #4CAF50; padding: 20px; max-width: 800px; margin: 0 auto; background-color: #f9f9f9; }");
					htmlFile->Add("        .certificate-header { text-align: center; margin-bottom: 30px; }");
					htmlFile->Add("        .certificate-header h1 { margin: 0; font-size: 28px; color: #333; }");
					htmlFile->Add("        .certificate-header p { margin: 5px 0; font-size: 18px; color: #666; }");
					htmlFile->Add("        .certificate-body { margin-bottom: 30px; }");
					htmlFile->Add("        .certificate-body p { font-size: 18px; margin: 10px 0; }");
					htmlFile->Add("        .certificate-footer { text-align: center; font-size: 16px; color: #777; }");
					htmlFile->Add("        .highlight { font-weight: bold; color: #333; }");
					htmlFile->Add("        .results { margin-top: 20px; padding: 15px; border: 2px solid #ddd; background-color: #f0f0f0; }");
					htmlFile->Add("    </style>");
					htmlFile->Add("</head>");
					htmlFile->Add("<body>");
					htmlFile->Add("    <div class='certificate'>");
					htmlFile->Add("        <div class='certificate-header'>");
					htmlFile->Add("            <h1>Сертифікат НМТ</h1>");
					htmlFile->Add("            <p>Національний Мультипредметний Тест</п>");
					htmlFile->Add("            <p>Дата створення: <span class='highlight'>" + creation_date + "</span></п>");
					htmlFile->Add("        </div>");
					htmlFile->Add("        <div class='certificate-body'>");
					htmlFile->Add("            <p>Номер сертифіката: <span class='highlight'>" + cerf_num + "</span></п>");
					htmlFile->Add("            <p>Прізвище, Ім'я, По батькові: <span class='highlight'>" + pib + "</span></п>");
					htmlFile->Add("            <p>PIN-код: <span class='highlight'>" + pin + "</span></п>");
					htmlFile->Add("            <p>Термін дії сертифіката: <span class='highlight'>" + effect_time + "</span></п>");
					htmlFile->Add("        </div>");
					htmlFile->Add("        <div class='results'>");
					htmlFile->Add("            <h2>Результати за рік</h2>");
					htmlFile->AddStrings(results);
					htmlFile->Add("        </div>");
					htmlFile->Add("    </div>");
					htmlFile->Add("</body>");
					htmlFile->Add("</html>");
					htmlFile->SaveToFile(filePath, TEncoding::UTF8);
					ShowMessage("HTML-файл створено за адресою: " + filePath);
				}
				__finally
				{
					delete htmlFile;
					delete results;
				}
			}
			else
			{
				ShowMessage("Збереження було скасовано.");
			}
		}
		else
		{
			ShowMessage("Дані про сертифікат не знайдено.");
		}
	}
	catch (const Exception &e)
	{
		ShowMessage("Помилка при створенні HTML: " + e.Message);
	}
}

//---------------------------------------------------------------------------

void __fastcall TCertificates::N4Click(TObject *Sender)
{

	bool k =true;
	Form13->setfromCertificate(k);
	Form13->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TCertificates::DatePicker2CloseUp(TObject *Sender)
{
	try
	{
		TDateTime selectedDate = DatePicker2->Date;
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
		DatePicker2->Date = Now();
	}
}
//---------------------------------------------------------------------------

