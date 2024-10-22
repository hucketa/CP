object Form2: TForm2
  Left = 0
  Top = 0
  AutoSize = True
  BorderStyle = bsSingle
  Caption = #1056#1086#1073#1086#1090#1072' '#1079' '#1085#1072#1074#1095#1072#1083#1100#1085#1080#1084#1080' '#1076#1080#1089#1094#1080#1087#1083#1110#1085#1072#1084#1080
  ClientHeight = 138
  ClientWidth = 453
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnShow = FormShow
  TextHeight = 15
  object Label1: TLabel
    Left = 24
    Top = 55
    Width = 84
    Height = 15
    Caption = #1054#1087#1080#1089' '#1087#1088#1077#1076#1084#1077#1090#1091
    WordWrap = True
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 449
    Height = 137
    Hint = #1055#1086#1083#1103' '#1076#1083#1103' '#1074#1074#1077#1076#1077#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111' '#1087#1088#1086' '#1089#1090#1091#1076#1077#1085#1090#1072
    Caption = #1055#1086#1083#1103' '#1076#1083#1103' '#1074#1074#1077#1076#1077#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111' '#1087#1088#1086' '#1085#1072#1074#1095#1072#1083#1100#1085#1091' '#1076#1080#1089#1094#1080#1087#1083#1110#1085#1091
    TabOrder = 0
    object Label4: TLabel
      Left = 16
      Top = 25
      Width = 87
      Height = 15
      Caption = #1053#1072#1079#1074#1072' '#1087#1088#1077#1076#1084#1077#1090#1091
    end
    object Label6: TLabel
      Left = 19
      Top = 89
      Width = 81
      Height = 30
      Caption = #1055#1086#1089#1080#1083#1072#1085#1085#1103' '#1076#1086' '#1079#1086#1073#1088#1072#1078#1077#1085#1085#1103
      WordWrap = True
    end
    object Edit2: TEdit
      Left = 114
      Top = 23
      Width = 132
      Height = 23
      TabOrder = 0
      OnExit = Edit2Exit
    end
    object Edit4: TEdit
      Left = 114
      Top = 54
      Width = 132
      Height = 23
      TabOrder = 1
      OnExit = Edit4Exit
    end
    object Button1: TButton
      Left = 252
      Top = 25
      Width = 186
      Height = 40
      Caption = #1044#1086#1076#1072#1090#1080
      TabOrder = 2
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 252
      Top = 71
      Width = 186
      Height = 44
      Caption = #1047#1072#1074#1072#1085#1090#1072#1078#1080#1090#1080' '#1088#1080#1089#1091#1085#1086#1082
      TabOrder = 3
      OnClick = Button2Click
    end
  end
  object Edit1: TEdit
    Left = 114
    Top = 92
    Width = 132
    Height = 23
    TabOrder = 1
    OnExit = Edit1Exit
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 392
    Top = 8
  end
end
