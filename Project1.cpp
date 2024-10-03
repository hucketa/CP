//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Students.cpp", Form14);
USEFORM("Subjects.cpp", Form7);
USEFORM("Results.cpp", Form11);
USEFORM("Conditions.cpp", Form4);
USEFORM("Certificate.cpp", Form15);
USEFORM("Main_Window.cpp", Form3);
USEFORM("Help.cpp", Form1);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TForm3), &Form3);
		Application->CreateForm(__classid(TForm11), &Form11);
		Application->CreateForm(__classid(TForm7), &Form7);
		Application->CreateForm(__classid(TForm4), &Form4);
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
