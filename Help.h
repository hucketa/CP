//---------------------------------------------------------------------------

#ifndef HelpH
#define HelpH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class THelp_m : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TImage *Image1;
private:	// User declarations
public:		// User declarations
	__fastcall THelp_m(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE THelp_m *Help_m;
//---------------------------------------------------------------------------
#endif
