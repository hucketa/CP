#include <System.RegularExpressions.hpp>
#include <Vcl.Dialogs.hpp>
#include <IniFiles.hpp>
#include <Data.Win.ADODB.hpp>
#include "Unit13.h"
#include "Main_Window.h" // Подключаем модуль с MainForm
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm13 *Form13;
//---------------------------------------------------------------------------

__fastcall TForm13::TForm13(TComponent* Owner)
	: TForm(Owner)
{
	ComboBox1->Enabled = false;
	Button2->Enabled = false;
}

// Проверка и заполнение списка баз данных
void __fastcall TForm13::Button1Click(TObject *Sender) {
	TADOConnection *conn = new TADOConnection(NULL);
	try {
        // Используем DSN coursach для подключения
        conn->ConnectionString = "Provider=MSDASQL.1;Persist Security Info=False;DSN=coursach;";
        conn->LoginPrompt = false;
        conn->Connected = true;

        TADOQuery *query = new TADOQuery(NULL);
        query->Connection = conn;
        query->SQL->Text = "SHOW DATABASES";
        query->Open();

        ComboBox1->Items->Clear();
        while (!query->Eof) {
            ComboBox1->Items->Add(query->Fields->Fields[0]->AsString);
            query->Next();
        }
        delete query;

        ComboBox1->Enabled = true;
        Button2->Enabled = true;

    } catch (const Exception &e) {
        ShowMessage("Ошибка подключения к серверу: " + e.Message);
    }
    delete conn;
}

// Проверка базы данных на совместимость с проектом
void __fastcall TForm13::Button2Click(TObject *Sender) {
    TADOConnection *conn = new TADOConnection(NULL);
    try {
        // Используем DSN coursach для проверки базы данных
        conn->ConnectionString = "Provider=MSDASQL.1;Persist Security Info=False;DSN=coursach;";
        conn->LoginPrompt = false;
        conn->Connected = true;

        TADOQuery *query = new TADOQuery(NULL);
        query->Connection = conn;
        query->SQL->Text = "SELECT COUNT(*) FROM information_schema.tables WHERE table_name = 'необходимая_таблица'";
        query->Open();

        if (query->Fields->Fields[0]->AsInteger > 0) {
            ShowMessage("База данных совместима с проектом.");

            TIniFile *ini = new TIniFile(ChangeFileExt(Application->ExeName, ".ini"));
            ini->WriteString("Database", "IPAddress", Edit1->Text);
            ini->WriteString("Database", "Host", Edit2->Text);
            ini->WriteString("Database", "Username", Login->Text);
            ini->WriteString("Database", "Password", Password->Text);
            ini->WriteString("Database", "Database", ComboBox1->Text);
            delete ini;

            Close();  // Закрываем Form13
            Application->CreateForm(__classid(TForm3), &Form3);  // Открываем MainForm
            Form3->Show();
        } else {
            ShowMessage("Выбранная база данных несовместима с проектом.");
        }
        delete query;

    } catch (const Exception &e) {
        ShowMessage("Ошибка проверки базы данных: " + e.Message);
    }
    delete conn;
}

