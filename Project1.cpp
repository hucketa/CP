//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", Form1);
USEFORM("Subjects.cpp", Form7);
USEFORM("Students.cpp", Form14);
USEFORM("School.cpp", Form6);
USEFORM("Unit10.cpp", Form10);
USEFORM("Unit9.cpp", Form9);
USEFORM("Unit8.cpp", Form8);
USEFORM("Unit5.cpp", Form5);
USEFORM("Unit2.cpp", Form2);
USEFORM("Data.cpp", DataModule1); /* TDataModule: File Type */
USEFORM("Conditions.cpp", Form4);
USEFORM("Certificate.cpp", Certificates);
USEFORM("Auth.cpp", Form12);
USEFORM("Help.cpp", Help_m);
USEFORM("Results.cpp", Form11);
USEFORM("Main_Window.cpp", Form3);
USEFORM("Unit13.cpp", Form13);
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
		Application->CreateForm(__classid(TForm6), &Form6);
		Application->CreateForm(__classid(TForm8), &Form8);
		Application->CreateForm(__classid(TForm9), &Form9);
		Application->CreateForm(__classid(TForm10), &Form10);
		Application->CreateForm(__classid(TForm12), &Form12);
		Application->CreateForm(__classid(TForm13), &Form13);
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
