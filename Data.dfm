object DataModule1: TDataModule1
  Height = 480
  Width = 640
  object MainFormSource: TDataSource
    DataSet = MainQuery
    Left = 504
    Top = 288
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=MSDASQL.1;Persist Security Info=False;Extended Properti' +
      'es="DSN=coursach;SERVER=localhost;UID=root;DATABASE=nmt_results;' +
      'PORT=3306"'
    LoginPrompt = False
    Left = 280
    Top = 24
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
      '       CASE WHEN r.Status = 1 THEN '#39#1047#1076#1072#1085#1086#39' ELSE '#39#1053#1077#1079#1076#1072#1085#1086#39' END,'
      '       subj.Name,'
      '       r.Reached_score'
      'FROM Result r'
      'JOIN Student s ON r.Student_id = s.Student_id'
      'JOIN Subject subj ON r.Subj_id = subj.Subject_id')
    Left = 376
    Top = 136
  end
  object ADOTable1: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'student'
    Left = 64
    Top = 208
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 408
    Top = 288
  end
  object ADOTable2: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'subject'
    Left = 136
    Top = 208
  end
  object DataSource2: TDataSource
    DataSet = ADOTable2
    Left = 248
    Top = 288
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 536
    Top = 136
  end
  object DataSource3: TDataSource
    DataSet = ADOQuery2
    Left = 328
    Top = 288
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
    Left = 456
    Top = 136
  end
  object ADOTable3: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'school'
    Left = 208
    Top = 208
  end
  object DataSource4: TDataSource
    DataSet = ADOTable3
    Left = 168
    Top = 288
  end
  object ADOQuery3: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      '    r.Res_id,'
      '    st.PIB,'
      '    sub.Name,'
      '    r.Reached_score,'
      '    c.Max_point,'
      '    c.Min_r_point,'
      
        '    CASE WHEN r.Status = 1 THEN '#39#1047#1072#1088#1072#1093#1086#1074#1072#1085#1086#39' ELSE '#39#1053#1077' '#1079#1072#1088#1072#1093#1086#1074#1072#1085#1086 +
        #39' END AS Status,'
      '    r.Attemp_date,'
      '    c.Date,'
      '    school.Email'
      'FROM'
      '    result r'
      'JOIN'
      '    student st ON r.Student_id = st.Student_id'
      'JOIN'
      '    subject sub ON r.Subj_id = sub.Subject_id'
      'JOIN'
      '    conditions c ON r.Condition_id = c.Condition_id'
      'JOIN'
      '    school ON r.School_id = school.School_id;'
      '')
    Left = 304
    Top = 136
  end
  object DataSource5: TDataSource
    DataSet = ADOQuery3
    Left = 88
    Top = 288
  end
  object DataSource6: TDataSource
    DataSet = ADOQuery4
    Left = 88
    Top = 352
  end
  object ADOQuery4: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT certificate.Cerf_num, '
      '       student.PIB AS Student_PIB, '
      '       certificate.PIN, '
      '       certificate.Creation_date, '
      '       certificate.Effect_time, '
      '       CASE'
      '           WHEN certificate.Status = 1 THEN '#39#1044#1110#1081#1089#1085#1080#1081#39
      '           ELSE '#39#1053#1077' '#1076#1110#1081#1089#1085#1080#1081#39
      '       END AS Status,'
      '       users.PIB AS Issuer_PIB'
      'FROM certificate'
      'JOIN student ON certificate.Student_id = student.Student_id'
      'LEFT JOIN users ON certificate.Login = users.Login;')
    Left = 232
    Top = 136
  end
  object ADOQuery5: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT '
      '    Login,'
      '    Password,'
      '    Role,'
      '    PIB,'
      '    CASE '
      '        WHEN Status = 1 THEN '#39#1072#1082#1090#1080#1074#1085#1080#1081#39
      '        WHEN  Status = 0 THEN '#39#1085#1077' '#1072#1082#1090#1080#1074#1085#1080#1081#39
      '        ELSE '#39#1085#1077#1074#1110#1076#1086#1084#1080#1081' '#1089#1090#1072#1090#1091#1089#39
      '    END AS `'#1057#1090#1072#1090#1091#1089'`'
      'FROM users;')
    Left = 416
    Top = 224
  end
  object DataSource7: TDataSource
    DataSet = ADOQuery5
    Left = 528
    Top = 200
  end
end
