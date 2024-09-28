object Form2: TForm2
  Left = 0
  Top = 0
  Caption = #1056#1077#1076#1072#1075#1091#1074#1072#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111' '#1087#1088#1086' '#1091#1095#1085#1110#1074
  ClientHeight = 305
  ClientWidth = 904
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  OnCreate = FormCreate
  TextHeight = 15
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 441
    Height = 275
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
      Top = 122
      Width = 96
      Height = 15
      Caption = #1044#1072#1090#1072' '#1085#1072#1088#1086#1076#1078#1077#1085#1085#1103
    end
    object Label3: TLabel
      Left = 38
      Top = 25
      Width = 95
      Height = 15
      Caption = 'ID '#1091#1095#1085#1103'('#1089#1090#1091#1076#1077#1085#1090#1072')'
    end
    object Label4: TLabel
      Left = 192
      Top = 52
      Width = 92
      Height = 15
      Caption = #1053#1086#1084#1077#1088' '#1087#1072#1089#1087#1086#1088#1090#1091
    end
    object Label5: TLabel
      Left = 192
      Top = 83
      Width = 21
      Height = 15
      Caption = #1030#1055#1053
    end
    object Label6: TLabel
      Left = 192
      Top = 104
      Width = 95
      Height = 30
      Caption = #1053#1086#1084#1077#1088' '#1089#1074#1110#1076#1086#1089#1090#1074#1072' '#1087#1088#1086' '#1086#1089#1074#1110#1090#1091
      WordWrap = True
    end
    object Label7: TLabel
      Left = 192
      Top = 143
      Width = 34
      Height = 15
      Caption = 'E-mail'
    end
    object Label8: TLabel
      Left = 192
      Top = 164
      Width = 67
      Height = 30
      Caption = #1050#1086#1085#1090#1072#1082#1090#1085#1080#1081' '#1090#1077#1083#1077#1092#1086#1085
      WordWrap = True
    end
    object Edit2: TEdit
      Left = 290
      Top = 49
      Width = 132
      Height = 23
      NumbersOnly = True
      TabOrder = 0
    end
    object ComboBox1: TComboBox
      Left = 201
      Top = 20
      Width = 219
      Height = 23
      CanUndoSelText = True
      TabOrder = 1
      Items.Strings = (
        #1055#1072#1087#1077#1088#1086#1074#1080#1081
        'ID '#1082#1072#1088#1090#1072)
    end
    object DatePicker1: TDatePicker
      Left = 16
      Top = 142
      Date = 45563.000000000000000000
      DateFormat = 'dd/mm/yyyy'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      TabOrder = 2
    end
    object RadioGroup1: TRadioGroup
      Left = 16
      Top = 75
      Width = 161
      Height = 41
      Caption = #1057#1090#1072#1090#1100
      Columns = 2
      Items.Strings = (
        #1063#1086#1083#1086#1074#1110#1095#1072
        #1046#1110#1085#1086#1095#1072)
      TabOrder = 3
    end
    object Edit3: TEdit
      Left = 288
      Top = 165
      Width = 132
      Height = 23
      NumbersOnly = True
      TabOrder = 4
    end
    object Edit4: TEdit
      Left = 288
      Top = 78
      Width = 132
      Height = 23
      NumbersOnly = True
      TabOrder = 5
    end
    object Edit5: TEdit
      Left = 288
      Top = 136
      Width = 132
      Height = 23
      NumbersOnly = True
      TabOrder = 6
    end
    object Edit6: TEdit
      Left = 290
      Top = 107
      Width = 132
      Height = 23
      NumbersOnly = True
      TabOrder = 7
    end
    object Edit7: TEdit
      Left = 80
      Top = 205
      Width = 340
      Height = 23
      NumbersOnly = True
      TabOrder = 8
    end
    object Button1: TButton
      Left = 16
      Top = 234
      Width = 404
      Height = 25
      Caption = #1042#1085#1077#1089#1090#1080' '#1079#1084#1110#1085#1080
      TabOrder = 9
    end
    object ComboBox2: TComboBox
      Left = 16
      Top = 46
      Width = 161
      Height = 23
      TabOrder = 10
    end
  end
  object DBGrid1: TDBGrid
    Left = 455
    Top = 8
    Width = 447
    Height = 275
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
  end
  object MainMenu1: TMainMenu
    Left = 240
    Top = 80
    object N1: TMenuItem
      Caption = #1057#1077#1088#1090#1080#1092#1110#1082#1072#1090#1080
      object N22: TMenuItem
        Caption = #1055#1086#1074#1077#1088#1085#1091#1090#1080#1089#1103' '#1074' '#1075#1086#1083#1086#1074#1085#1077' '#1084#1077#1085#1102
      end
    end
    object N2: TMenuItem
      Caption = #1059#1095#1085#1110
      object N6: TMenuItem
        Caption = #1044#1086#1076#1072#1074#1072#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111
      end
      object N7: TMenuItem
        Caption = #1056#1077#1076#1072#1075#1091#1074#1072#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1103
      end
      object N8: TMenuItem
        Caption = #1042#1080#1076#1072#1083#1077#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111
      end
      object N18: TMenuItem
        Caption = #1055#1086#1074#1077#1088#1085#1091#1090#1080#1089#1103' '#1091' '#1075#1086#1083#1086#1074#1085#1077' '#1084#1077#1085#1102
      end
    end
    object N3: TMenuItem
      Caption = #1059#1084#1086#1074#1080' '#1087#1088#1086#1093#1086#1076#1078#1077#1085#1085#1103
      object N9: TMenuItem
        Caption = #1044#1086#1076#1072#1074#1072#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111
      end
      object N10: TMenuItem
        Caption = #1056#1077#1076#1072#1075#1091#1074#1072#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111
      end
      object N11: TMenuItem
        Caption = #1042#1080#1076#1072#1083#1077#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111
      end
      object N19: TMenuItem
        Caption = #1055#1086#1074#1077#1088#1085#1091#1090#1080#1089#1103' '#1091' '#1075#1086#1083#1086#1074#1085#1077' '#1084#1077#1085#1102
      end
    end
    object N4: TMenuItem
      Caption = #1055#1088#1077#1076#1084#1077#1090#1080
      object N12: TMenuItem
        Caption = #1044#1086#1076#1072#1074#1072#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111
      end
      object N13: TMenuItem
        Caption = #1056#1077#1076#1072#1075#1091#1074#1072#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111
      end
      object N14: TMenuItem
        Caption = #1042#1080#1076#1072#1083#1077#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111
      end
      object N20: TMenuItem
        Caption = #1055#1086#1074#1077#1088#1085#1091#1090#1080#1089#1103' '#1074' '#1075#1086#1083#1086#1074#1085#1077' '#1084#1077#1085#1102
      end
    end
    object N5: TMenuItem
      Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090#1080' '#1090#1077#1089#1090#1091#1074#1072#1085#1085#1103
      object N15: TMenuItem
        Caption = #1044#1086#1076#1072#1074#1072#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111
      end
      object N16: TMenuItem
        Caption = #1056#1077#1076#1072#1075#1091#1074#1072#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111
      end
      object N17: TMenuItem
        Caption = #1042#1080#1076#1072#1083#1077#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111
      end
      object N21: TMenuItem
        Caption = #1055#1086#1074#1077#1088#1085#1091#1090#1080#1089#1103' '#1074' '#1075#1086#1083#1086#1074#1085#1077' '#1084#1077#1085#1102
      end
    end
    object Lj1: TMenuItem
      Caption = #1055#1088#1086' '#1076#1086#1076#1072#1090#1086#1082
    end
  end
end
