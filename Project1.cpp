//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Subjects.cpp", Form7);
USEFORM("Students.cpp", Form14);
USEFORM("Results.cpp", Form11);
USEFORM("Unit5.cpp", Form5);
USEFORM("Unit2.cpp", Form2);
USEFORM("Unit1.cpp", Form1);
USEFORM("Data.cpp", DataModule1);
USEFORM("Conditions.cpp", Form4);
USEFORM("Certificate.cpp", Certificates);
USEFORM("Main_Window.cpp", Form3);
USEFORM("Help.cpp", Help_m);
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
		Application->CreateForm(__classid(THelp_m), &Help_m);
		Application->CreateForm(__classid(TCertificates), &Certificates);
		Application->CreateForm(__classid(TDataModule1), &DataModule1);
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TForm2), &Form2);
		Application->CreateForm(__classid(TForm5), &Form5);
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
