//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Certificate.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCertificates *Certificates;
//---------------------------------------------------------------------------
__fastcall TCertificates::TCertificates(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
