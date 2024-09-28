object Form15: TForm15
  Left = 0
  Top = 0
  Caption = #1057#1077#1088#1090#1080#1092#1110#1082#1072#1090#1080
  ClientHeight = 418
  ClientWidth = 898
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  Position = poDesigned
  TextHeight = 15
  object DBGrid1: TDBGrid
    Left = 8
    Top = 16
    Width = 441
    Height = 169
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 191
    Width = 441
    Height = 202
    Hint = #1055#1086#1083#1103' '#1076#1083#1103' '#1074#1074#1077#1076#1077#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111' '#1087#1088#1086' '#1089#1090#1091#1076#1077#1085#1090#1072
    Caption = #1055#1086#1083#1103' '#1076#1083#1103' '#1074#1074#1077#1076#1077#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111' '#1087#1088#1086' '#1089#1077#1088#1090#1080#1092#1110#1082#1090#1072#1090#1080
    TabOrder = 1
    object Label2: TLabel
      Left = 38
      Top = 135
      Width = 85
      Height = 15
      Caption = #1044#1072#1090#1072' '#1089#1090#1074#1086#1088#1077#1085#1085#1103
    end
    object Label3: TLabel
      Left = 38
      Top = 25
      Width = 81
      Height = 15
      Caption = 'ID '#1085#1072#1082#1072#1079#1091' '#1091#1084#1086#1074
    end
    object Label4: TLabel
      Left = 192
      Top = 25
      Width = 43
      Height = 15
      Caption = 'PIN-'#1082#1086#1076
      WordWrap = True
    end
    object Label5: TLabel
      Left = 191
      Top = 56
      Width = 54
      Height = 15
      Caption = #1058#1077#1088#1084#1110#1085' '#1076#1110#1111
      WordWrap = True
    end
    object Label1: TLabel
      Left = 46
      Top = 75
      Width = 61
      Height = 15
      Caption = 'ID '#1089#1090#1091#1076#1077#1085#1090#1072
    end
    object Edit1: TEdit
      Left = 16
      Top = 46
      Width = 121
      Height = 23
      NumbersOnly = True
      TabOrder = 0
      Text = '0'
    end
    object Edit2: TEdit
      Left = 279
      Top = 22
      Width = 132
      Height = 23
      NumbersOnly = True
      TabOrder = 1
    end
    object UpDown1: TUpDown
      Left = 137
      Top = 46
      Width = 16
      Height = 23
      Associate = Edit1
      TabOrder = 2
    end
    object DatePicker1: TDatePicker
      Left = 16
      Top = 156
      Date = 45563.000000000000000000
      DateFormat = 'dd/mm/yyyy'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      TabOrder = 3
    end
    object Edit4: TEdit
      Left = 279
      Top = 51
      Width = 132
      Height = 23
      NumbersOnly = True
      TabOrder = 4
    end
    object Button1: TButton
      Left = 191
      Top = 128
      Width = 230
      Height = 52
      Caption = #1044#1086#1076#1072#1090#1080
      TabOrder = 5
    end
    object RadioGroup1: TRadioGroup
      Left = 192
      Top = 75
      Width = 230
      Height = 38
      Columns = 2
      Items.Strings = (
        #1044#1110#1081#1089#1085#1080#1081
        #1053#1077' '#1076#1110#1081#1089#1085#1080#1081)
      TabOrder = 6
    end
  end
  object Edit3: TEdit
    Left = 24
    Top = 287
    Width = 121
    Height = 23
    NumbersOnly = True
    TabOrder = 2
    Text = '0'
  end
  object UpDown2: TUpDown
    Left = 145
    Top = 287
    Width = 16
    Height = 23
    Associate = Edit3
    TabOrder = 3
  end
  object DBGrid2: TDBGrid
    Left = 455
    Top = 16
    Width = 434
    Height = 265
    TabOrder = 4
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
  end
  object GroupBox2: TGroupBox
    Left = 455
    Top = 296
    Width = 441
    Height = 97
    Hint = #1055#1086#1083#1103' '#1076#1083#1103' '#1074#1074#1077#1076#1077#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111' '#1087#1088#1086' '#1089#1090#1091#1076#1077#1085#1090#1072
    Caption = #1057#1075#1077#1085#1077#1088#1091#1074#1072#1090#1080' '#1089#1077#1088#1090#1080#1092#1110#1082#1072#1090
    TabOrder = 5
    object Label10: TLabel
      Left = 46
      Top = 25
      Width = 61
      Height = 15
      Caption = 'ID '#1089#1090#1091#1076#1077#1085#1090#1072
    end
    object Button2: TButton
      Left = 175
      Top = 24
      Width = 230
      Height = 52
      Caption = #1047#1075#1077#1085#1077#1088#1091#1074#1072#1090#1080
      TabOrder = 0
    end
  end
  object Edit5: TEdit
    Left = 471
    Top = 342
    Width = 121
    Height = 23
    NumbersOnly = True
    TabOrder = 6
    Text = '0'
  end
  object UpDown3: TUpDown
    Left = 592
    Top = 342
    Width = 16
    Height = 23
    Associate = Edit5
    TabOrder = 7
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
