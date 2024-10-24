object Form12: TForm12
  Left = 0
  Top = 0
  AutoSize = True
  Caption = #1047#1084#1110#1085#1072' '#1088#1086#1083#1110
  ClientHeight = 42
  ClientWidth = 405
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnShow = FormShow
  TextHeight = 15
  object LabeledEdit1: TLabeledEdit
    Left = 0
    Top = 18
    Width = 121
    Height = 23
    Hint = 
      'koristuvach1 - '#1084#1077#1085#1077#1076#1078#1077#1088' '#1087#1088#1077#1076#1084#1077#1090#1110#1074'; koristuvach2 -'#1084#1077#1085#1077#1076#1078#1077#1088' '#1088#1077#1079#1091#1083#1100 +
      #1090#1072#1090#1110#1074'; koristuvach3 - '#1084#1077#1085#1077#1076#1078#1077#1088' '#1091#1095#1085#1110#1074
    EditLabel.Width = 30
    EditLabel.Height = 15
    EditLabel.Hint = 
      'koristuvach1 - '#1084#1077#1085#1077#1076#1078#1077#1088' '#1087#1088#1077#1076#1084#1077#1090#1110#1074'; koristuvach2 -'#1084#1077#1085#1077#1076#1078#1077#1088' '#1088#1077#1079#1091#1083#1100 +
      #1090#1072#1090#1110#1074'; koristuvach3 - '#1084#1077#1085#1077#1076#1078#1077#1088' '#1091#1095#1085#1110#1074
    EditLabel.Caption = #1051#1086#1075#1110#1085
    EditLabel.ParentShowHint = False
    EditLabel.ShowHint = True
    TabOrder = 0
    Text = ''
  end
  object LabeledEdit2: TLabeledEdit
    Left = 144
    Top = 18
    Width = 121
    Height = 23
    EditLabel.Width = 42
    EditLabel.Height = 15
    EditLabel.Hint = 'user1pass; user2pass; user3pass'
    EditLabel.Caption = #1055#1072#1088#1086#1083#1100
    EditLabel.ParentShowHint = False
    EditLabel.ShowHint = True
    TabOrder = 1
    Text = ''
  end
  object Button1: TButton
    Left = 280
    Top = 8
    Width = 121
    Height = 33
    Caption = #1055#1110#1076#1090#1074#1077#1088#1076#1080#1090#1080
    TabOrder = 2
    OnClick = Button1Click
  end
end
