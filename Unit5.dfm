object Form5: TForm5
  Left = 0
  Top = 0
  AutoSize = True
  BorderStyle = bsSingle
  Caption = #1056#1086#1073#1086#1090#1072' '#1079' '#1091#1084#1086#1074#1072#1084#1080' '#1087#1088#1086#1074#1077#1076#1077#1085#1085#1103
  ClientHeight = 178
  ClientWidth = 445
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
    Width = 441
    Height = 177
    Hint = #1055#1086#1083#1103' '#1076#1083#1103' '#1074#1074#1077#1076#1077#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111' '#1087#1088#1086' '#1089#1090#1091#1076#1077#1085#1090#1072
    TabOrder = 0
    object Label2: TLabel
      Left = 38
      Top = 64
      Width = 85
      Height = 15
      Caption = #1044#1072#1090#1072' '#1089#1090#1074#1086#1088#1077#1085#1085#1103
    end
    object Label4: TLabel
      Left = 191
      Top = 11
      Width = 108
      Height = 15
      Caption = #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1080#1081' '#1073#1072#1083
      WordWrap = True
    end
    object Label5: TLabel
      Left = 191
      Top = 44
      Width = 96
      Height = 15
      Caption = #1052#1110#1085#1110#1084#1072#1083#1100#1085#1080#1081' '#1073#1072#1083
      WordWrap = True
    end
    object Label6: TLabel
      Left = 191
      Top = 73
      Width = 81
      Height = 15
      Caption = #1055#1088#1086#1093#1110#1076#1085#1080#1081' '#1073#1072#1083
      WordWrap = True
    end
    object Label1: TLabel
      Left = 191
      Top = 101
      Width = 63
      Height = 30
      Caption = #1053#1072#1074#1095#1072#1083#1100#1085#1072' '#1076#1080#1089#1094#1080#1087#1083#1110#1085#1072
      WordWrap = True
    end
    object Edit2: TEdit
      Left = 304
      Top = 12
      Width = 132
      Height = 23
      NumbersOnly = True
      TabOrder = 0
    end
    object DatePicker1: TDatePicker
      Left = 19
      Top = 85
      Date = 45563.000000000000000000
      DateFormat = 'dd/mm/yyyy'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      TabOrder = 1
      OnCloseUp = DatePicker1CloseUp
    end
    object RadioGroup1: TRadioGroup
      Left = 13
      Top = 3
      Width = 161
      Height = 55
      Caption = #1057#1090#1072#1090#1091#1089
      Items.Strings = (
        #1054#1073#1086#1074'`'#1103#1079#1082#1086#1074#1086
        #1053#1077' '#1086#1073#1086#1074'`'#1103#1079#1082#1086#1074#1086)
      TabOrder = 2
    end
    object Edit4: TEdit
      Left = 304
      Top = 41
      Width = 132
      Height = 23
      NumbersOnly = True
      TabOrder = 3
    end
    object Edit6: TEdit
      Left = 303
      Top = 72
      Width = 132
      Height = 23
      NumbersOnly = True
      TabOrder = 4
    end
    object Button1: TButton
      Left = 19
      Top = 144
      Width = 406
      Height = 25
      Caption = #1044#1086#1076#1072#1090#1080
      TabOrder = 5
      OnClick = Button1Click
    end
    object ComboBox1: TComboBox
      Left = 280
      Top = 101
      Width = 155
      Height = 23
      TabOrder = 6
      TextHint = #1055#1088#1077#1076#1084#1077#1090' '#1087#1086#1074'`'#1103#1079#1072#1085#1080#1081' '#1079' '#1074#1080#1084#1086#1075#1086#1102
    end
  end
end
