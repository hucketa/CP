object Form3: TForm3
  Left = 0
  Top = 0
  Caption = #1054#1073#1083#1110#1082' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1110#1074' '#1085#1084#1090
  ClientHeight = 353
  ClientWidth = 754
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  OnCreate = FormCreate
  TextHeight = 15
  object DBGrid1: TDBGrid
    Left = 0
    Top = 53
    Width = 513
    Height = 281
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
  end
  object RadioGroup1: TRadioGroup
    Left = 0
    Top = 0
    Width = 513
    Height = 49
    Hint = #1054#1073#1077#1088#1110#1090#1100' '#1087#1091#1085#1082#1090' '#1079#1072' '#1103#1082#1080#1084' '#1087#1086#1090#1088#1110#1073#1085#1086' '#1074#1110#1076#1089#1086#1088#1090#1091#1074#1072#1090#1080' '#1079#1072#1087#1080#1089#1080
    Caption = #1057#1086#1088#1090#1091#1074#1072#1085#1085#1103' '#1091' '#1087#1086#1088#1103#1076#1082#1091' '#1079#1088#1086#1089#1090#1072#1085#1085#1103' '#1079#1072':'
    Columns = 3
    Items.Strings = (
      #1057#1090#1072#1090#1091#1089' '#1079#1076#1072#1095#1110
      #1044#1072#1090#1072' '#1079#1076#1072#1095#1110
      #1055#1088#1110#1079#1074#1080#1097#1077' '#1091#1095#1085#1103)
    TabOrder = 1
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 334
    Width = 754
    Height = 19
    Panels = <
      item
        Alignment = taCenter
        Text = #1043#1091#1085#1077#1085#1082#1086' '#1071#1088#1086#1089#1083#1072#1074' '#1052#1072#1082#1089#1080#1084#1086#1074#1080#1095
        Width = 200
      end
      item
        Alignment = taCenter
        BiDiMode = bdLeftToRight
        ParentBiDiMode = False
        Width = 200
      end
      item
        Alignment = taCenter
        Text = #1051#1086#1075#1110#1085' '#1091#1095#1072#1089#1085#1080#1082#1072
        Width = 200
      end>
    ExplicitTop = 333
    ExplicitWidth = 750
  end
  object GroupBox1: TGroupBox
    Left = 519
    Top = 0
    Width = 227
    Height = 328
    Caption = #1060#1110#1083#1100#1090#1088#1072#1094#1110#1103
    TabOrder = 3
    object DatePicker1: TDatePicker
      Left = 32
      Top = 23
      Date = 45563.000000000000000000
      DateFormat = 'dd/mm/yyyy'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      TabOrder = 0
    end
    object CheckBox1: TCheckBox
      Left = 20
      Top = 63
      Width = 97
      Height = 17
      Caption = #1056#1072#1085#1110#1096#1077' '#1079#1072
      TabOrder = 1
    end
    object CheckBox2: TCheckBox
      Left = 20
      Top = 86
      Width = 97
      Height = 17
      Caption = #1062#1103' '#1076#1072#1090#1072
      TabOrder = 2
    end
    object CheckBox3: TCheckBox
      Left = 113
      Top = 63
      Width = 97
      Height = 17
      Caption = #1055#1110#1079#1085#1110#1096#1077
      TabOrder = 3
    end
    object GroupBox2: TGroupBox
      Left = 16
      Top = 109
      Width = 185
      Height = 84
      Caption = #1057#1090#1072#1090#1091#1089' '#1079#1076#1072#1095#1110
      TabOrder = 4
      object RadioGroup2: TRadioGroup
        Left = 8
        Top = 14
        Width = 134
        Height = 55
        Margins.Top = 0
        Margins.Bottom = 0
        Items.Strings = (
          #1047#1076#1072#1085#1086
          #1053#1077' '#1079#1076#1072#1085#1086)
        TabOrder = 0
      end
    end
    object GroupBox3: TGroupBox
      Left = 16
      Top = 207
      Width = 185
      Height = 66
      Caption = #1055#1088#1110#1079#1074#1080#1097#1077' '#1091#1095#1085#1103
      TabOrder = 5
      object Edit1: TEdit
        Left = 11
        Top = 24
        Width = 166
        Height = 23
        TabOrder = 0
      end
    end
    object Button1: TButton
      Left = 16
      Top = 279
      Width = 185
      Height = 34
      Caption = #1047#1072#1089#1090#1086#1089#1091#1074#1072#1090#1080
      TabOrder = 6
    end
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
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 424
    Top = 64
  end
end
