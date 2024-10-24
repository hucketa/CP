//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Certificate.h"
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
	DBGrid2->Columns->Items[1]->Title->Caption = "ПІБ cтудента";
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
	DatePicker1->OnChange = CheckFiltersFilled;
	Earlier->OnClick = CheckFiltersFilled;
	Later->OnClick = CheckFiltersFilled;
	ThisDate->OnClick = CheckFiltersFilled;
}

//---------------------------------------------------------------------------

void __fastcall TCertificates::CheckFiltersFilled(TObject *Sender)
{
	bool isAnyFilterFilled = false;
	if (Earlier->Checked || Later->Checked || ThisDate->Checked)
		isAnyFilterFilled = true;
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
		conditions += "certificate.Creation_date = :SelectedDate ";
	else if (Earlier->Checked && Later->Checked)
		conditions += "certificate.Creation_date BETWEEN :DateStart AND :DateEnd ";
	else if (Later->Checked)
		conditions += "certificate.Creation_date > :SelectedDate ";
	else if (Earlier->Checked)
		conditions += "certificate.Creation_date < :SelectedDate ";

	if (!conditions.IsEmpty())
		query += " WHERE " + conditions;

	query += " ORDER BY certificate.Creation_date DESC";

	try
	{
		DataModule1->ADOQuery4->Close();
		DataModule1->ADOQuery4->SQL->Clear();
		DataModule1->ADOQuery4->SQL->Add(query);

		TDateTime selectedDate = DatePicker1->Date;

		if (ThisDate->Checked)
			DataModule1->ADOQuery4->Parameters->ParamByName("SelectedDate")->Value = selectedDate.FormatString("yyyy-mm-dd");
		else if (Earlier->Checked && Later->Checked)
		{
			DataModule1->ADOQuery4->Parameters->ParamByName("DateStart")->Value = selectedDate - 1;
			DataModule1->ADOQuery4->Parameters->ParamByName("DateEnd")->Value = selectedDate + 1;
		}
		else if (Earlier->Checked || Later->Checked)
			DataModule1->ADOQuery4->Parameters->ParamByName("SelectedDate")->Value = selectedDate.FormatString("yyyy-mm-dd");

		DataModule1->ADOQuery4->Open();
		DBColumnSizes();
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
	Earlier->Checked = false;
	Later->Checked = false;
	ThisDate->Checked = false;

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
		// Отримуємо PIN-код з LabeledEdit1
		String enteredPIN = LabeledEdit1->Text.Trim();

		// Запит на отримання інформації про сертифікат
		String query = "SELECT certificate.Cerf_num, student.PIB, certificate.PIN, certificate.Creation_date, certificate.Effect_time, "
					   "CASE WHEN certificate.Status = 1 THEN 'Дійсний' ELSE 'Не дійсний' END AS Status "
					   "FROM certificate "
					   "JOIN student ON certificate.Student_id = student.Student_id "
					   "WHERE certificate.PIN = :PIN";  // Використовуємо PIN замість Cerf_num

		DataModule1->ADOQuery1->Close();
		DataModule1->ADOQuery1->SQL->Clear();
		DataModule1->ADOQuery1->SQL->Add(query);
		DataModule1->ADOQuery1->Parameters->ParamByName("PIN")->Value = enteredPIN; // передаємо PIN з LabeledEdit1
		DataModule1->ADOQuery1->Open();

		if (DataModule1->ADOQuery1->RecordCount > 0)
		{
			// Отримуємо дані про сертифікат
			String cerf_num = DataModule1->ADOQuery1->FieldByName("Cerf_num")->AsString;
			String pib = DataModule1->ADOQuery1->FieldByName("PIB")->AsString;
			String pin = DataModule1->ADOQuery1->FieldByName("PIN")->AsString;
			String creation_date = DataModule1->ADOQuery1->FieldByName("Creation_date")->AsString;
			String effect_time = DataModule1->ADOQuery1->FieldByName("Effect_time")->AsString;

			// Запит для отримання результатів студента
			String resultQuery = "SELECT subject.Name AS Subject, conditions.Date AS Attemp_date, "
								"conditions.Max_point AS Max_point, conditions.Min_r_point AS Reached_score "
								"FROM conditions "
								"JOIN subject ON conditions.Subject_id = subject.Subject_id "
								"WHERE conditions.Status = 1"; // Використовуємо умовні дані замість таблиці 'results'

			DataModule1->ADOQuery2->Close();
			DataModule1->ADOQuery2->SQL->Clear();
			DataModule1->ADOQuery2->SQL->Add(resultQuery);
			DataModule1->ADOQuery2->Open();

			// Перевіряємо результати
			TStringList *results = new TStringList();
			while (!DataModule1->ADOQuery2->Eof)
			{
				String subject = DataModule1->ADOQuery2->FieldByName("Subject")->AsString;
				String attemp_date = DataModule1->ADOQuery2->FieldByName("Attemp_date")->AsString;
				String reached_score = DataModule1->ADOQuery2->FieldByName("Reached_score")->AsString;

				results->Add("<div class='result-item'>");
				results->Add("<p>Предмет: <span class='highlight'>" + subject + "</span></p>");
				results->Add("<p>Дата спроби: <span class='highlight'>" + attemp_date + "</span></p>");
				results->Add("<p>Набрані бали: <span class='highlight'>" + reached_score + "</span></p>");
				results->Add("</div>");

				DataModule1->ADOQuery2->Next();
			}

			// Відкриваємо SaveDialog для вибору місця збереження
			SaveDialog1->Filter = "HTML files (*.html)|*.html";
			SaveDialog1->DefaultExt = "html";
			if (SaveDialog1->Execute())
			{
				String filePath = SaveDialog1->FileName;
				TStringList *htmlFile = new TStringList();
				htmlFile->Text = "";  // Очищаємо вміст перед додаванням

				try
				{
					// Генерація HTML
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
					htmlFile->Add("            <p>Національний Мультипредметний Тест</p>");
					htmlFile->Add("            <p>Дата створення: <span class='highlight'>" + creation_date + "</span></p>");
					htmlFile->Add("        </div>");
					htmlFile->Add("        <div class='certificate-body'>");
					htmlFile->Add("            <p>Номер сертифіката: <span class='highlight'>" + cerf_num + "</span></p>");
					htmlFile->Add("            <p>Прізвище, Ім'я, По батькові: <span class='highlight'>" + pib + "</span></p>");
					htmlFile->Add("            <p>PIN-код: <span class='highlight'>" + pin + "</span></p>");
					htmlFile->Add("            <p>Термін дії сертифіката: <span class='highlight'>" + effect_time + "</span></p>");
					htmlFile->Add("        </div>");
					htmlFile->Add("        <div class='results'>");
					htmlFile->Add("            <h2>Результати за рік</h2>");
					htmlFile->AddStrings(results);
					htmlFile->Add("        </div>");
					htmlFile->Add("    </div>");
					htmlFile->Add("</body>");
					htmlFile->Add("</html>");

					// Запис у файл з кодуванням UTF-8
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

