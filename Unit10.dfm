object Form10: TForm10
  Left = 0
  Top = 0
  AutoSize = True
  BorderStyle = bsSingle
  Caption = 'Form10'
  ClientHeight = 185
  ClientWidth = 401
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesktopCenter
  OnCreate = FormCreate
  TextHeight = 15
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 401
    Height = 185
    Hint = #1055#1086#1083#1103' '#1076#1083#1103' '#1074#1074#1077#1076#1077#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111' '#1087#1088#1086' '#1089#1090#1091#1076#1077#1085#1090#1072
    Caption = #1055#1086#1083#1103' '#1076#1083#1103' '#1074#1074#1077#1076#1077#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111' '#1087#1088#1086' '#1089#1077#1088#1090#1080#1092#1110#1082#1090#1072#1090#1080
    TabOrder = 0
    object Label2: TLabel
      Left = 46
      Top = 66
      Width = 85
      Height = 15
      Caption = #1044#1072#1090#1072' '#1089#1090#1074#1086#1088#1077#1085#1085#1103
    end
    object Label1: TLabel
      Left = 46
      Top = 125
      Width = 73
      Height = 15
      Caption = #1044#1072#1090#1072' '#1072#1085#1091#1083#1103#1094#1110#1111
    end
    object DatePicker1: TDatePicker
      Left = 16
      Top = 87
      Date = 45563.000000000000000000
      DateFormat = 'dd/mm/yyyy'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      TabOrder = 0
      OnCloseUp = DatePicker1CloseUp
    end
    object Button1: TButton
      Left = 192
      Top = 125
      Width = 193
      Height = 53
      Caption = #1055#1110#1076#1090#1074#1077#1088#1076#1080#1090#1080
      TabOrder = 1
      OnClick = Button1Click
    end
    object RadioGroup1: TRadioGroup
      Left = 192
      Top = 66
      Width = 193
      Height = 47
      Caption = #1057#1090#1072#1090#1091#1089
      Columns = 2
      Items.Strings = (
        #1044#1110#1081#1089#1085#1080#1081
        #1053#1077' '#1076#1110#1081#1089#1085#1080#1081)
      TabOrder = 2
    end
    object LabeledEdit1: TLabeledEdit
      Left = 192
      Top = 37
      Width = 193
      Height = 23
      EditLabel.Width = 48
      EditLabel.Height = 15
      EditLabel.Caption = #1055#1030#1041' '#1091#1095#1085#1103
      EditLabel.OnClick = LabeledEdit1SubLabelClick
      TabOrder = 3
      Text = ''
      OnExit = LabeledEdit1Exit
    end
    object LabeledEdit2: TLabeledEdit
      Left = 37
      Top = 37
      Width = 121
      Height = 23
      EditLabel.Width = 45
      EditLabel.Height = 15
      EditLabel.Caption = #1055#1030#1053'-'#1082#1086#1076
      MaxLength = 15
      NumbersOnly = True
      TabOrder = 4
      Text = ''
      OnExit = LabeledEdit2Exit
    end
    object DatePicker2: TDatePicker
      Left = 16
      Top = 146
      Date = 45563.000000000000000000
      DateFormat = 'dd/mm/yyyy'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      TabOrder = 5
      OnCloseUp = DatePicker2CloseUp
    end
  end
end
