object DataModule1: TDataModule1
  Height = 480
  Width = 640
  object ADOTable1: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'school'
    Left = 224
    Top = 8
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
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
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT '
      '    s.PIB AS "'#1055#1030#1041' '#1089#1090#1091#1076#1077#1085#1090#1072'",'
      '    r.Attemp_date AS "'#1044#1072#1090#1072' '#1089#1082#1083#1072#1076#1072#1085#1085#1103'",'
      '    r.Status AS "'#1057#1090#1072#1090#1091#1089'",'
      '    subj.Name AS "'#1053#1072#1079#1074#1072' '#1087#1088#1077#1076#1084#1077#1090#1072'"'
      'FROM '
      '    Result r'
      'JOIN '
      '    Student s ON r.Student_id = s.Student_id'
      'JOIN '
      '    Subject subj ON r.Subj_id = subj.Subject_id;')
    Left = 32
    Top = 8
  end
end
