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
      'es="DSN=coursach;SERVER=localhost;UID=root;DATABASE=nmt_results;' +
      'PORT=3306"'
    LoginPrompt = False
    Left = 96
    Top = 8
  end
  object MainQuery: TADOQuery
    Active = True
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
  object ADOTable1: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'student'
    Left = 248
    Top = 16
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 312
    Top = 16
  end
  object ADOTable2: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'subject'
    Left = 376
    Top = 16
  end
  object DataSource2: TDataSource
    DataSet = ADOTable2
    Left = 440
    Top = 24
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 72
    Top = 72
  end
  object DataSource3: TDataSource
    DataSet = ADOQuery2
    Left = 192
    Top = 96
  end
  object ADOQuery2: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      
        'SELECT c.Condition_id, s.Name AS Subject_Name, c.Max_point, c.Mi' +
        'n_r_point, c.Min_point, '
      '       CASE '
      '           WHEN c.Status = 1 THEN '#39#1086#1073#1086#1074'\'#39#1103#1079#1082#1086#1074#1086#39
      '           ELSE '#39#1085#1077' '#1086#1073#1086#1074'\'#39#1103#1079#1082#1086#1074#1086#39
      '       END AS Status,'
      '       c.Date'
      'FROM conditions c'
      'JOIN subject s ON c.Subject_id = s.Subject_id;')
    Left = 72
    Top = 136
  end
end
