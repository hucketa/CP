object Form8: TForm8
  Left = 0
  Top = 0
  AutoSize = True
  BorderStyle = bsSingle
  Caption = #1056#1086#1073#1086#1090#1072' '#1079' '#1085#1072#1074#1095#1072#1083#1100#1085#1080#1084#1080' '#1079#1072#1082#1083#1072#1076#1072#1084#1080
  ClientHeight = 86
  ClientWidth = 424
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesktopCenter
  OnShow = FormShow
  TextHeight = 15
  object Label1: TLabel
    Left = 327
    Top = 3
    Width = 21
    Height = 15
    Caption = #1058#1080#1087
  end
  object LabeledEdit1: TLabeledEdit
    Left = 0
    Top = 18
    Width = 121
    Height = 23
    EditLabel.Width = 32
    EditLabel.Height = 15
    EditLabel.Caption = #1052#1110#1089#1090#1086
    TabOrder = 0
    Text = ''
    OnExit = LabeledEdit1Exit
  end
  object LabeledEdit2: TLabeledEdit
    Left = 139
    Top = 18
    Width = 121
    Height = 23
    EditLabel.Width = 46
    EditLabel.Height = 15
    EditLabel.Caption = #1054#1073#1083#1072#1089#1090#1100
    TabOrder = 1
    Text = ''
    OnExit = LabeledEdit2Exit
  end
  object LabeledEdit4: TLabeledEdit
    Left = 1
    Top = 62
    Width = 121
    Height = 23
    EditLabel.Width = 34
    EditLabel.Height = 15
    EditLabel.Caption = 'E-mail'
    TabOrder = 2
    Text = ''
    OnExit = LabeledEdit4Exit
  end
  object LabeledEdit5: TLabeledEdit
    Left = 139
    Top = 62
    Width = 121
    Height = 23
    EditLabel.Width = 111
    EditLabel.Height = 15
    EditLabel.Caption = #1055#1030#1041' '#1074#1110#1076#1087#1086#1074#1110#1076#1072#1083#1100#1085#1086#1075#1086
    TabOrder = 3
    Text = ''
    OnExit = LabeledEdit5Exit
  end
  object Button1: TButton
    Left = 272
    Top = 53
    Width = 145
    Height = 31
    Caption = #1055#1110#1076#1090#1074#1077#1088#1076#1080#1090#1080
    TabOrder = 4
    OnClick = Button1Click
  end
  object ComboBox1: TComboBox
    Left = 275
    Top = 24
    Width = 145
    Height = 23
    TabOrder = 5
    Items.Strings = (
      #1042#1053#1047
      #1057#1047#1064
      #1043#1110#1084#1085#1072#1079#1110#1103
      #1051#1110#1094#1077#1081)
  end
end
