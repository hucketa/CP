object Form15: TForm15
  Left = 0
  Top = 0
  Caption = #1057#1077#1088#1090#1080#1092#1110#1082#1072#1090#1080
  ClientHeight = 438
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
      Left = 38
      Top = 76
      Width = 116
      Height = 15
      Caption = #1044#1072#1090#1072' '#1091#1082#1083#1072#1076#1072#1085#1085#1103' '#1091#1084#1086#1074
    end
    object Edit2: TEdit
      Left = 279
      Top = 22
      Width = 132
      Height = 23
      NumbersOnly = True
      TabOrder = 0
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
      TabOrder = 1
    end
    object Edit4: TEdit
      Left = 279
      Top = 51
      Width = 132
      Height = 23
      NumbersOnly = True
      TabOrder = 2
    end
    object Button1: TButton
      Left = 191
      Top = 128
      Width = 230
      Height = 52
      Caption = #1044#1086#1076#1072#1090#1080
      TabOrder = 3
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
      TabOrder = 4
    end
    object LabeledEdit1: TLabeledEdit
      Left = 33
      Top = 47
      Width = 121
      Height = 23
      EditLabel.Width = 121
      EditLabel.Height = 15
      EditLabel.Caption = #1053#1086#1084#1077#1088' '#1087#1072#1089#1087#1086#1088#1090#1091' '#1091#1095#1085#1103
      TabOrder = 5
      Text = ''
    end
    object DatePicker2: TDatePicker
      Left = 16
      Top = 97
      Date = 45568.000000000000000000
      DateFormat = 'dd/mm/yyyy'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      TabOrder = 6
    end
  end
  object DBGrid2: TDBGrid
    Left = 455
    Top = 16
    Width = 434
    Height = 377
    TabOrder = 2
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
  end
  object MainMenu1: TMainMenu
    Left = 360
    Top = 64
    object N1: TMenuItem
      Caption = #1057#1077#1088#1090#1080#1092#1110#1082#1072#1090#1080
      object N22: TMenuItem
        Caption = #1055#1086#1074#1077#1088#1085#1091#1090#1080#1089#1103' '#1074' '#1075#1086#1083#1086#1074#1085#1077' '#1084#1077#1085#1102
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
      object N21: TMenuItem
        Caption = #1055#1086#1074#1077#1088#1085#1091#1090#1080#1089#1103' '#1074' '#1075#1086#1083#1086#1074#1085#1077' '#1084#1077#1085#1102
      end
    end
    object Lj1: TMenuItem
      Caption = #1055#1088#1086' '#1076#1086#1076#1072#1090#1086#1082
    end
    object N2: TMenuItem
      Caption = #1059#1095#1085#1110
      object N6: TMenuItem
        Caption = #1044#1086#1076#1072#1074#1072#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111
      end
      object N7: TMenuItem
        Caption = #1056#1077#1076#1072#1075#1091#1074#1072#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1103
      end
      object N18: TMenuItem
        Caption = #1055#1086#1074#1077#1088#1085#1091#1090#1080#1089#1103' '#1091' '#1075#1086#1083#1086#1074#1085#1077' '#1084#1077#1085#1102
      end
    end
    object N3: TMenuItem
      Caption = #1059#1084#1086#1074#1080' '#1087#1088#1086#1093#1086#1076#1078#1077#1085#1085#1103
      object N8: TMenuItem
        Caption = #1044#1086#1076#1072#1074#1072#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111
      end
      object N9: TMenuItem
        Caption = #1056#1077#1076#1072#1075#1091#1074#1072#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111
      end
      object N10: TMenuItem
        Caption = #1055#1086#1074#1077#1088#1085#1091#1090#1080#1089#1103' '#1085#1072' '#1075#1086#1083#1086#1074#1085#1091
      end
    end
  end
end