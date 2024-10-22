//---------------------------------------------------------------------------

#ifndef DataH
#define DataH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TDataModule1 : public TDataModule
{
__published:	// IDE-managed Components
	TDataSource *MainFormSource;
	TADOConnection *ADOConnection1;
	TADOQuery *MainQuery;
	TADOTable *ADOTable1;
	TDataSource *DataSource1;
	TADOTable *ADOTable2;
	TDataSource *DataSource2;
	TADOQuery *ADOQuery1;
	TDataSource *DataSource3;
	TADOQuery *ADOQuery2;
	TADOTable *ADOTable3;
	TDataSource *DataSource4;
	TADOQuery *ADOQuery3;
	TDataSource *DataSource5;
private:	// User declarations
public:		// User declarations
	__fastcall TDataModule1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
#endif
