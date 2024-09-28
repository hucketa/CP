//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Condition_change.cpp", Form5);
USEFORM("Conditions_add.cpp", Form4);
USEFORM("Result_delete.cpp", Form13);
USEFORM("Result_change.cpp", Form12);
USEFORM("Subject_delete.cpp", Form9);
USEFORM("Subject_change.cpp", Form8);
USEFORM("Subject_add.cpp", Form7);
USEFORM("Condition_delete.cpp", Form6);
USEFORM("Main_Window.cpp", Form3);
USEFORM("Help.cpp", Form1);
USEFORM("Result_add.cpp", Form11);
USEFORM("Student_delete.cpp", Form10);
USEFORM("Student_change.cpp", Form2);
USEFORM("Student_add.cpp", Form14);
USEFORM("Certificate.cpp", Form15);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TForm3), &Form3);
		Application->CreateForm(__classid(TForm13), &Form13);
		Application->CreateForm(__classid(TForm12), &Form12);
		Application->CreateForm(__classid(TForm11), &Form11);
		Application->CreateForm(__classid(TForm8), &Form8);
		Application->CreateForm(__classid(TForm7), &Form7);
		Application->CreateForm(__classid(TForm6), &Form6);
		Application->CreateForm(__classid(TForm5), &Form5);
		Application->CreateForm(__classid(TForm4), &Form4);
		Application->CreateForm(__classid(TForm10), &Form10);
		Application->CreateForm(__classid(TForm2), &Form2);
		Application->CreateForm(__classid(TForm9), &Form9);
		Application->CreateForm(__classid(TForm14), &Form14);
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TForm15), &Form15);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
