object Form13: TForm13
  Left = 0
  Top = 0
  Caption = #1042#1080#1076#1072#1083#1077#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111' '#1087#1088#1086' '#1088#1077#1079#1091#1100#1090#1072#1090#1080
  ClientHeight = 437
  ClientWidth = 832
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  TextHeight = 15
  object DBGrid1: TDBGrid
    Left = 383
    Top = 8
    Width = 447
    Height = 406
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
  end
  object DBGrid2: TDBGrid
    Left = 16
    Top = 111
    Width = 361
    Height = 303
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
  end
  object GroupBox1: TGroupBox
    Left = 16
    Top = 8
    Width = 361
    Height = 97
    Hint = #1055#1086#1083#1103' '#1076#1083#1103' '#1074#1074#1077#1076#1077#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111' '#1087#1088#1086' '#1089#1090#1091#1076#1077#1085#1090#1072
    Caption = #1055#1086#1083#1103' '#1076#1083#1103' '#1074#1074#1077#1076#1077#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111' '#1087#1088#1086' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1080
    TabOrder = 2
    object Label3: TLabel
      Left = 38
      Top = 25
      Width = 73
      Height = 15
      Caption = 'ID '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1091
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
    object UpDown1: TUpDown
      Left = 137
      Top = 46
      Width = 16
      Height = 23
      Associate = Edit1
      TabOrder = 1
    end
    object Button1: TButton
      Left = 168
      Top = 42
      Width = 137
      Height = 32
      Caption = #1042#1080#1076#1072#1083#1080#1090#1080
      TabOrder = 2
    end
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
