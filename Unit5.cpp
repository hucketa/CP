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
//---------------------------------------------------------------------------
void __fastcall TForm5::DatePicker1CloseUp(TObject *Sender)
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

