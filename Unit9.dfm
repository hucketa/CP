object Form9: TForm9
  Left = 0
  Top = 0
  AutoSize = True
  BorderStyle = bsSingle
  Caption = 'Form9'
  ClientHeight = 273
  ClientWidth = 353
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
    Width = 353
    Height = 273
    Hint = #1055#1086#1083#1103' '#1076#1083#1103' '#1074#1074#1077#1076#1077#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111' '#1087#1088#1086' '#1089#1090#1091#1076#1077#1085#1090#1072
    Caption = #1055#1086#1083#1103' '#1076#1083#1103' '#1074#1074#1077#1076#1077#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111' '#1087#1088#1086' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1080
    TabOrder = 0
    object Label1: TLabel
      Left = 180
      Top = 167
      Width = 92
      Height = 15
      Caption = #1044#1072#1090#1072' '#1089#1082#1083#1072#1076#1072#1085#1085#1085#1103
    end
    object Label2: TLabel
      Left = 189
      Top = 66
      Width = 116
      Height = 15
      Caption = #1044#1072#1090#1072' '#1091#1082#1083#1072#1076#1072#1085#1085#1103' '#1091#1084#1086#1074
      OnClick = Label2Click
    end
    object Label3: TLabel
      Left = 25
      Top = 69
      Width = 126
      Height = 15
      Caption = #1053#1072#1074#1095#1072#1083#1100#1085#1072' '#1076#1080#1089#1094#1080#1087#1083#1110#1085#1072
    end
    object Label4: TLabel
      Left = 198
      Top = 22
      Width = 107
      Height = 15
      Caption = #1053#1072#1074#1095#1072#1083#1100#1085#1080#1081' '#1079#1072#1082#1083#1072#1076
    end
    object Label5: TLabel
      Left = 25
      Top = 159
      Width = 96
      Height = 15
      Caption = #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1080#1081': -'
    end
    object Label6: TLabel
      Left = 27
      Top = 201
      Width = 84
      Height = 15
      Caption = #1052#1110#1085#1110#1084#1072#1083#1100#1085#1080#1081': -'
    end
    object Label7: TLabel
      Left = 25
      Top = 180
      Width = 69
      Height = 15
      Caption = #1055#1088#1086#1093#1110#1076#1085#1080#1081': -'
    end
    object Button1: TButton
      Left = 25
      Top = 232
      Width = 301
      Height = 32
      Caption = #1044#1086#1076#1072#1090#1080
      TabOrder = 0
      OnClick = Button1Click
    end
    object LabeledEdit1: TLabeledEdit
      Left = 30
      Top = 40
      Width = 121
      Height = 23
      EditLabel.Width = 48
      EditLabel.Height = 15
      EditLabel.Caption = #1055#1030#1041' '#1091#1095#1085#1103
      EditLabel.OnClick = LabeledEdit1SubLabelClick
      TabOrder = 1
      Text = ''
      OnExit = LabeledEdit1Exit
    end
    object LabeledEdit4: TLabeledEdit
      Left = 27
      Top = 130
      Width = 121
      Height = 23
      EditLabel.Width = 96
      EditLabel.Height = 15
      EditLabel.Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090' '#1091' '#1073#1072#1083#1072#1093
      NumbersOnly = True
      TabOrder = 2
      Text = ''
      OnExit = LabeledEdit4Exit
    end
    object ComboBox1: TComboBox
      Left = 16
      Top = 87
      Width = 145
      Height = 23
      TabOrder = 3
      OnCloseUp = ComboBox1CloseUp
    end
    object DatePicker2: TDatePicker
      Left = 176
      Top = 87
      Date = 45563.000000000000000000
      DateFormat = 'dd/mm/yyyy'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      TabOrder = 4
      OnCloseUp = DatePicker2CloseUp
    end
    object RadioGroup1: TRadioGroup
      Left = 176
      Top = 125
      Width = 161
      Height = 41
      Caption = #1057#1090#1072#1090#1091#1089
      Columns = 2
      Items.Strings = (
        #1047#1076#1072#1085#1086
        #1053#1077' '#1079#1076#1072#1085#1086)
      TabOrder = 5
    end
    object DatePicker1: TDatePicker
      Left = 176
      Top = 187
      Date = 45563.000000000000000000
      DateFormat = 'dd/mm/yyyy'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      TabOrder = 6
      OnCloseUp = DatePicker1CloseUp
    end
    object ComboBox2: TComboBox
      Left = 176
      Top = 40
      Width = 145
      Height = 23
      TabOrder = 7
    end
  end
end
