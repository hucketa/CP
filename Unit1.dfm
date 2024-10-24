object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = #1042#1074#1077#1076#1077#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111
  ClientHeight = 295
  ClientWidth = 447
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesktopCenter
  OnShow = FormShow
  TextHeight = 15
  object GroupBox1: TGroupBox
    Left = -1
    Top = 8
    Width = 462
    Height = 289
    Hint = #1055#1086#1083#1103' '#1076#1083#1103' '#1074#1074#1077#1076#1077#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111' '#1087#1088#1086' '#1089#1090#1091#1076#1077#1085#1090#1072
    Caption = #1055#1086#1083#1103' '#1076#1083#1103' '#1074#1074#1077#1076#1077#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111' '#1087#1088#1086' '#1089#1090#1091#1076#1077#1085#1090#1072
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 208
      Width = 58
      Height = 15
      Caption = #1055#1086#1084#1110#1090#1082#1072'(*)'
    end
    object Label2: TLabel
      Left = 38
      Top = 98
      Width = 96
      Height = 15
      Caption = #1044#1072#1090#1072' '#1085#1072#1088#1086#1076#1078#1077#1085#1085#1103
    end
    object Label4: TLabel
      Left = 192
      Top = 28
      Width = 92
      Height = 15
      Caption = #1053#1086#1084#1077#1088' '#1087#1072#1089#1087#1086#1088#1090#1091
    end
    object Label5: TLabel
      Left = 192
      Top = 59
      Width = 21
      Height = 15
      Caption = #1030#1055#1053
    end
    object Label6: TLabel
      Left = 192
      Top = 80
      Width = 95
      Height = 30
      Caption = #1053#1086#1084#1077#1088' '#1089#1074#1110#1076#1086#1089#1090#1074#1072' '#1087#1088#1086' '#1086#1089#1074#1110#1090#1091
      WordWrap = True
    end
    object Label7: TLabel
      Left = 192
      Top = 119
      Width = 34
      Height = 15
      Caption = 'E-mail'
    end
    object Label8: TLabel
      Left = 192
      Top = 140
      Width = 67
      Height = 30
      Caption = #1050#1086#1085#1090#1072#1082#1090#1085#1080#1081' '#1090#1077#1083#1077#1092#1086#1085
      WordWrap = True
    end
    object Label3: TLabel
      Left = 23
      Top = 179
      Width = 19
      Height = 15
      Caption = #1055#1030#1041
      WordWrap = True
    end
    object Edit2: TEdit
      Left = 290
      Top = 25
      Width = 132
      Height = 23
      TabOrder = 0
      OnExit = Edit2Exit
    end
    object ComboBox1: TComboBox
      Left = 16
      Top = 22
      Width = 170
      Height = 23
      CanUndoSelText = True
      TabOrder = 1
      Text = #1055#1072#1087#1077#1088#1086#1074#1080#1081
      OnCloseUp = ComboBox1CloseUp
      Items.Strings = (
        #1055#1072#1087#1077#1088#1086#1074#1080#1081
        'ID-'#1082#1072#1088#1090#1072)
    end
    object DatePicker1: TDatePicker
      Left = 16
      Top = 118
      Date = 45563.000000000000000000
      DateFormat = 'dd/mm/yyyy'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      TabOrder = 2
      OnCloseUp = DatePicker1CloseUp
    end
    object RadioGroup1: TRadioGroup
      Left = 16
      Top = 51
      Width = 161
      Height = 41
      Caption = #1057#1090#1072#1090#1100
      Columns = 2
      Items.Strings = (
        #1063#1086#1083#1086#1074#1110#1095#1072
        #1046#1110#1085#1086#1095#1072)
      TabOrder = 3
      OnExit = RadioGroup1Exit
    end
    object Edit3: TEdit
      Left = 288
      Top = 141
      Width = 132
      Height = 23
      NumbersOnly = True
      TabOrder = 4
      OnExit = Edit3Exit
    end
    object Edit4: TEdit
      Left = 288
      Top = 54
      Width = 132
      Height = 23
      NumbersOnly = True
      TabOrder = 5
      OnExit = Edit4Exit
    end
    object Edit5: TEdit
      Left = 288
      Top = 112
      Width = 132
      Height = 23
      TabOrder = 6
      OnExit = Edit5Exit
    end
    object Edit6: TEdit
      Left = 290
      Top = 83
      Width = 132
      Height = 23
      TabOrder = 7
      OnExit = Edit6Exit
    end
    object Edit7: TEdit
      Left = 80
      Top = 205
      Width = 340
      Height = 23
      TabOrder = 8
    end
    object Button1: TButton
      Left = 16
      Top = 234
      Width = 404
      Height = 25
      Caption = #1047#1072#1084#1110#1085#1080#1090#1080
      TabOrder = 9
      OnClick = Button1Click
    end
    object Edit1: TEdit
      Left = 56
      Top = 176
      Width = 364
      Height = 23
      TabOrder = 10
      OnExit = Edit1Exit
    end
  end
end
