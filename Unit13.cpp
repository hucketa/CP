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
		ShowMessage("���� ������� ������ ����� �����, ����� �� �����������, � ���� �������� �� 4 �� 16 �������.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm13::PasswordExit(TObject *Sender)
{
	String password = Password->Text;
	if (!TRegEx::IsMatch(password, "^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[A-Za-z\\d]{6,20}$")) {
		ShowMessage("������ ������� ������ �������� ���� �������� �����, ���� ������� ����� � ���� �����, � ���� �������� �� 6 �� 20 �������.");
	}
}
//---------------------------------------------------------------------------

