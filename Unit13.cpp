#include <System.RegularExpressions.hpp>
#include <Vcl.Dialogs.hpp>
#include <IniFiles.hpp>
#include <Data.Win.ADODB.hpp>
#include <System.RegularExpressions.hpp>
#include "Unit13.h"
#include "Main_Window.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm13 *Form13;

//---------------------------------------------------------------------------
__fastcall TForm13::TForm13(TComponent* Owner)
	: TForm(Owner)
{
	if (LoadTemplateFromIni()) {
		if (Form3 == NULL) {
			Application->CreateForm(__classid(TForm3), &Form3);
			this->Hide();
		}
	} else {
		this->Show();
	}
	fromCertificate = false;
}

bool __fastcall TForm13::LoadTemplateFromIni()
{
	TIniFile *IniFile = new TIniFile(ExtractFilePath(Application->ExeName) + "config.ini");
	bool success = false;
	try {
		if (IniFile->SectionExists("Certificate")) {
			template_name = IniFile->ReadString("Certificate", "TemplateName", "");
			if (!template_name.IsEmpty()) {
				success = true;
			}
		}
	}
	__finally {
		delete IniFile;
	}
	return success;
}

void __fastcall TForm13::Button1Click(TObject *Sender)
{
	if (!LabeledEdit1->Text.IsEmpty()) {
		template_name = LabeledEdit1->Text;
		SaveTemplateToIni();
		if (fromCertificate) {
			this->Close();
		} else {
			Form3->Show();
			fromCertificate = true;
			this->Hide();
		}
	} else {
		ShowMessage("Введіть шаблон для назви сертифікату");
	}
}


void __fastcall TForm13::SaveTemplateToIni()
{
	TIniFile *IniFile = new TIniFile(ExtractFilePath(Application->ExeName) + "config.ini");
	try {
		IniFile->WriteString("Certificate", "TemplateName", template_name);
	}
	__finally {
		delete IniFile;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm13::LabeledEdit1Exit(TObject *Sender)
{
	String text = LabeledEdit1->Text;
	if (!TRegEx::IsMatch(text, L"^[A-Za-z0-9]+$")) {
		ShowMessage(L"Дозволено тільки англійську мову та числа.");
		LabeledEdit1->SetFocus();
	}
}

void TForm13::setfromCertificate(bool k){
   fromCertificate = k;
}

