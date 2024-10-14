object DataModule1: TDataModule1
  Height = 480
  Width = 640
  object MainFormSource: TDataSource
    DataSet = MainQuery
    Left = 168
    Top = 8
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=MSDASQL.1;Persist Security Info=False;Extended Properti' +
      'es="DSN=Course_project;DESCRIPTION=NMT_Results;SERVER=localhost;' +
      'UID=root;DATABASE=nmt_results;PORT=3306"'
    LoginPrompt = False
    Left = 96
    Top = 8
  end
  object MainQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    Prepared = True
    SQL.Strings = (
      'SELECT s.PIB,'
      '       r.Attemp_date,'
      '       CASE WHEN r.Status = 1 THEN '#39#1047#1076#1072#1085#1086#39' ELSE '#39#1053#1077' '#1079#1076#1072#1085#1086#39' END,'
      '       subj.Name,'
      '       r.Reached_score'
      'FROM Result r'
      'JOIN Student s ON r.Student_id = s.Student_id'
      'JOIN Subject subj ON r.Subj_id = subj.Subject_id'
      '')
    Left = 32
    Top = 8
  end
end
