object Form13: TForm13
  Left = 0
  Top = 0
  Caption = #1040#1074#1090#1086#1088#1080#1079#1072#1094#1110#1103' '#1074' '#1041#1044
  ClientHeight = 273
  ClientWidth = 304
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 9
    Top = 65
    Width = 30
    Height = 15
    Caption = #1051#1086#1075#1110#1085
  end
  object Label2: TLabel
    Left = 9
    Top = 94
    Width = 42
    Height = 15
    Caption = #1055#1072#1088#1086#1083#1100
  end
  object Label3: TLabel
    Left = 8
    Top = 8
    Width = 214
    Height = 40
    Caption = #1040#1074#1090#1086#1088#1080#1079#1072#1094#1110#1103' '#1082#1086#1088#1080#1089#1090#1091#1074#1072#1095#1072' '#1076#1083#1103' '#1087#1110#1076#1082#1083#1102#1095#1077#1085#1085#1103' '#1076#1086' '#1041#1044
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = [fsItalic]
    ParentFont = False
    WordWrap = True
  end
  object Label4: TLabel
    Left = 8
    Top = 120
    Width = 97
    Height = 15
    Caption = 'IP '#1072#1076#1088#1077#1089#1072' '#1089#1077#1088#1074#1077#1088#1072
  end
  object Label5: TLabel
    Left = 8
    Top = 152
    Width = 25
    Height = 15
    Caption = #1061#1086#1089#1090
  end
  object Login: TEdit
    Left = 73
    Top = 62
    Width = 195
    Height = 23
    TabOrder = 0
  end
  object Password: TEdit
    Left = 73
    Top = 91
    Width = 195
    Height = 23
    TabOrder = 1
  end
  object Button1: TButton
    Left = 8
    Top = 178
    Width = 260
    Height = 26
    Caption = #1059#1074#1110#1081#1090#1080
    TabOrder = 2
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 111
    Top = 120
    Width = 157
    Height = 23
    TabOrder = 3
    Text = 'localhost'
  end
  object Edit2: TEdit
    Left = 73
    Top = 149
    Width = 195
    Height = 23
    NumbersOnly = True
    TabOrder = 4
  end
  object ComboBox1: TComboBox
    Left = 8
    Top = 210
    Width = 260
    Height = 23
    TabOrder = 5
    Text = 'ComboBox1'
  end
  object Button2: TButton
    Left = 8
    Top = 239
    Width = 260
    Height = 26
    Caption = #1054#1073#1088#1072#1090#1080' '#1073#1072#1079#1091
    TabOrder = 6
    OnClick = Button2Click
  end
end
