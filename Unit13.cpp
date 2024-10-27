#include <System.RegularExpressions.hpp>
#include <Vcl.Dialogs.hpp>
#include "Unit13.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm13 *Form13;
//---------------------------------------------------------------------------

__fastcall TForm13::TForm13(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm13::LoginExit(TObject *Sender)
{
	String login = Login->Text;
	if (!TRegEx::IsMatch(login, "^[A-Za-z0-9_]{4,16}$")) {
		ShowMessage("Логін повинен містити тільки букви, цифри та підкреслення, і бути довжиною від 4 до 16 символів.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm13::PasswordExit(TObject *Sender)
{
	String password = Password->Text;
	if (!TRegEx::IsMatch(password, "^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[A-Za-z\\d]{6,20}$")) {
		ShowMessage("Пароль повинен містити принаймні одну заглавну букву, одну строчну букву і одну цифру, і бути довжиною від 6 до 20 символів.");
	}
}
//---------------------------------------------------------------------------

