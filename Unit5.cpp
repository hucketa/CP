//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
    : TForm(Owner)
{
}

void TForm5::set_id(int k) {
    if (k == 0) {
        Form5->Caption = "Додавання даних";
        Button1->Caption = "Додати";
        RadioGroup1->ItemIndex = -1;
        Edit2->Text = "";
        Edit4->Text = "";
        Edit6->Text = "";
        DatePicker1->Date = Date();
        ComboBox1->ItemIndex = -1;
        ComboBox1->Text = "";
        TADOQuery *Query = new TADOQuery(this);
        Query->Connection = DataModule1->ADOConnection1;
        Query->SQL->Text = "SELECT Subject_id, Name FROM subject";
        Query->Open();
        ComboBox1->Items->Clear();
        while (!Query->Eof)
        {
            ComboBox1->Items->AddObject(Query->FieldByName("Name")->AsString,
                                        (TObject*)Query->FieldByName("Subject_id")->AsInteger);
            Query->Next();
        }
        delete Query;
    } else {
        Form5->Caption = "Редагування даних";
        Button1->Caption = "Підтвердити";
        TADOQuery *query = new TADOQuery(this);
        TADOQuery *Query = new TADOQuery(this);
        Query->Connection = DataModule1->ADOConnection1;
        Query->SQL->Text = "SELECT Subject_id, Name FROM subject";
        Query->Open();
        ComboBox1->Items->Clear();
        while (!Query->Eof)
        {
            ComboBox1->Items->AddObject(Query->FieldByName("Name")->AsString,
                                        (TObject*)Query->FieldByName("Subject_id")->AsInteger);
            Query->Next();
        }
        delete Query;
        query->Connection = DataModule1->ADOConnection1;
        query->SQL->Text = "SELECT Status, Max_point, Min_r_point, Min_point, Date, Subject_id FROM conditions WHERE Condition_id = :Condition_id";
        query->Parameters->ParamByName("Condition_id")->Value = k;
        query->Open();
        if (!query->Eof) {
            RadioGroup1->ItemIndex = query->FieldByName("Status")->AsInteger;
            Edit2->Text = query->FieldByName("Max_point")->AsString;
            Edit6->Text = query->FieldByName("Min_r_point")->AsString;
            Edit4->Text = query->FieldByName("Min_point")->AsString;
            DatePicker1->Date = query->FieldByName("Date")->AsDateTime;
            int subject_id = query->FieldByName("Subject_id")->AsInteger;
            for (int i = 0; i < ComboBox1->Items->Count; i++) {
                if ((int)ComboBox1->Items->Objects[i] == subject_id) {
                    ComboBox1->ItemIndex = i;
                    break;
                }
            }
        }
        query->Close();
        delete query;
    }
    id = k;
}

//---------------------------------------------------------------------------
void __fastcall TForm5::DatePicker1CloseUp(TObject *Sender)
{
    try
    {
        TDateTime selectedDate = DatePicker1->Date;
        TDateTime currentDate = Now();
        if (selectedDate > currentDate)
        {
            ShowMessage("Дата не може бути в майбутньому!");
            DatePicker1->SetFocus();
            throw Exception("");
        }
        else if (selectedDate < EncodeDate(1999, 1, 1))
        {
            ShowMessage("Дата занадто стара! Виберіть пізнішу дату.");
            DatePicker1->SetFocus();
            throw Exception("");
        }
    }
    catch (const Exception &e)
    {
        DatePicker1->Date = Now();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button1Click(TObject *Sender) {
    if (RadioGroup1->ItemIndex == -1) {
        ShowMessage("Будь ласка, виберіть статус.");
        RadioGroup1->SetFocus();
        return;
    }
    if (Edit2->Text.IsEmpty()) {
        ShowMessage("Будь ласка, введіть максимальний бал.");
        Edit2->SetFocus();
        return;
    }
    if (Edit4->Text.IsEmpty()) {
        ShowMessage("Будь ласка, введіть мінімальний бал.");
        Edit4->SetFocus();
        return;
    }
    if (Edit6->Text.IsEmpty()) {
        ShowMessage("Будь ласка, введіть мінімальний рейтинг.");
        Edit6->SetFocus();
        return;
    }
    if (ComboBox1->ItemIndex == -1) {
        ShowMessage("Будь ласка, виберіть предмет.");
        ComboBox1->SetFocus();
        return;
    }

    int max_point = StrToInt(Edit2->Text);
    int min_r_point = StrToInt(Edit6->Text);
    int min_point = StrToInt(Edit4->Text);
    int status = RadioGroup1->ItemIndex;
    String formattedDate = FormatDateTime("yyyy-mm-dd", DatePicker1->Date);
    String subject_name = ComboBox1->Items->Strings[ComboBox1->ItemIndex];
    int subject_id = 0;
    TADOQuery *subjectQuery = new TADOQuery(this);
    subjectQuery->Connection = DataModule1->ADOConnection1;
    subjectQuery->SQL->Text = "SELECT Subject_id FROM subject WHERE Name = :Name";
    subjectQuery->Parameters->ParamByName("Name")->Value = subject_name;
    subjectQuery->Open();
    if (!subjectQuery->Eof) {
        subject_id = subjectQuery->FieldByName("Subject_id")->AsInteger;
    } else {
        ShowMessage("Обраний предмет не знайдено.");
        ComboBox1->SetFocus();
        subjectQuery->Close();
        delete subjectQuery;
        return;
    }
    subjectQuery->Close();
    delete subjectQuery;

    if (!(max_point > min_point && min_r_point < max_point && min_r_point > min_point)) {
        ShowMessage("Помилка: значення не відповідають умовам. Переконайтеся, що: \nMax_point > Min_point\nMin_r_point < Max_point\nMin_r_point > Min_point.");
        Edit2->SetFocus();
        return;
    }

    if (id == 0) {
        TADOQuery *query = new TADOQuery(this);
        query->Connection = DataModule1->ADOConnection1;
        query->SQL->Text = "INSERT INTO conditions (Max_point, Min_r_point, Min_point, Status, Date, Subject_id) VALUES (:Max_point, :Min_r_point, :Min_point, :Status, :Date, :Subject_id)";
        query->Parameters->ParamByName("Max_point")->Value = max_point;
        query->Parameters->ParamByName("Min_r_point")->Value = min_r_point;
        query->Parameters->ParamByName("Min_point")->Value = min_point;
        query->Parameters->ParamByName("Status")->Value = status;
        query->Parameters->ParamByName("Date")->Value = formattedDate;
        query->Parameters->ParamByName("Subject_id")->Value = subject_id;
        query->ExecSQL();
        delete query;
        ShowMessage("Новий запис успішно додано.");
    } else {
        TADOQuery *query = new TADOQuery(this);
        query->Connection = DataModule1->ADOConnection1;
        query->SQL->Text = "UPDATE conditions SET Max_point = :Max_point, Min_r_point = :Min_r_point, Min_point = :Min_point, Status = :Status, Date = :Date, Subject_id = :Subject_id WHERE Condition_id = :Condition_id";
        query->Parameters->ParamByName("Max_point")->Value = max_point;
        query->Parameters->ParamByName("Min_r_point")->Value = min_r_point;
        query->Parameters->ParamByName("Min_point")->Value = min_point;
        query->Parameters->ParamByName("Status")->Value = status;
        query->Parameters->ParamByName("Date")->Value = formattedDate;
        query->Parameters->ParamByName("Subject_id")->Value = subject_id;
        query->Parameters->ParamByName("Condition_id")->Value = id;
        query->ExecSQL();
        delete query;
        ShowMessage("Запис успішно відредаговано.");
    }
    DataModule1->DataSource3->DataSet->Close();
    DataModule1->DataSource3->DataSet->Open();
    Form5->Close();
}

//---------------------------------------------------------------------------

