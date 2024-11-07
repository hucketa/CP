object Form16: TForm16
  Left = 0
  Top = 0
  Caption = 'Form16'
  ClientHeight = 193
  ClientWidth = 291
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
    Left = 152
    Top = 59
    Width = 27
    Height = 15
    Caption = #1056#1086#1083#1100
  end
  object LabeledEdit1: TLabeledEdit
    Left = 8
    Top = 29
    Width = 121
    Height = 23
    EditLabel.Width = 30
    EditLabel.Height = 15
    EditLabel.Caption = #1051#1086#1075#1110#1085
    TabOrder = 0
    Text = ''
    OnExit = LabeledEdit1Exit
  end
  object LabeledEdit2: TLabeledEdit
    Left = 8
    Top = 80
    Width = 121
    Height = 23
    EditLabel.Width = 42
    EditLabel.Height = 15
    EditLabel.Caption = #1055#1072#1088#1086#1083#1100
    TabOrder = 1
    Text = ''
    OnExit = LabeledEdit2Exit
  end
  object LabeledEdit3: TLabeledEdit
    Left = 147
    Top = 30
    Width = 121
    Height = 23
    EditLabel.Width = 19
    EditLabel.Height = 15
    EditLabel.Caption = #1055#1030#1041
    TabOrder = 2
    Text = ''
    OnExit = LabeledEdit3Exit
  end
  object Button1: TButton
    Left = 8
    Top = 159
    Width = 267
    Height = 27
    Caption = #1055#1110#1076#1090#1074#1077#1088#1076#1080#1090#1080
    TabOrder = 3
    OnClick = Button1Click
  end
  object ComboBox1: TComboBox
    Left = 147
    Top = 80
    Width = 128
    Height = 23
    TabOrder = 4
    Items.Strings = (
      #1075#1086#1083#1086#1074#1085#1080#1081' '#1072#1076#1084#1110#1085#1110#1089#1090#1088#1072#1090#1086#1088
      #1072#1076#1084#1110#1085#1110#1089#1090#1088#1072#1090#1086#1088
      #1074#1110#1076#1087#1086#1074#1110#1076#1072#1083#1100#1085#1080#1081' '#1079#1072' '#1089#1077#1088#1090#1080#1092#1110#1082#1072#1090#1080)
  end
  object RadioGroup1: TRadioGroup
    Left = 8
    Top = 109
    Width = 267
    Height = 44
    Caption = #1057#1090#1072#1090#1091#1089
    Columns = 2
    Items.Strings = (
      #1040#1082#1090#1080#1074#1085#1080#1081
      #1053#1077' '#1072#1082#1090#1080#1074#1085#1080#1081)
    TabOrder = 5
  end
end
