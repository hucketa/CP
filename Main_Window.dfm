object Form3: TForm3
  Left = 0
  Top = 0
  AutoSize = True
  BorderStyle = bsSingle
  Caption = #1054#1073#1083#1110#1082' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1110#1074' '#1085#1084#1090
  ClientHeight = 354
  ClientWidth = 813
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  Position = poDesktopCenter
  OnCreate = FormCreate
  OnShow = FormShow
  TextHeight = 15
  object StatusBar1: TStatusBar
    Left = 0
    Top = 335
    Width = 813
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
    ExplicitTop = 334
    ExplicitWidth = 809
  end
  object GroupBox1: TGroupBox
    Left = 566
    Top = 0
    Width = 227
    Height = 328
    Caption = #1060#1110#1083#1100#1090#1088#1072#1094#1110#1103
    TabOrder = 1
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
      OnCloseUp = DatePicker1CloseUp
    end
    object Earlier: TCheckBox
      Left = 20
      Top = 63
      Width = 97
      Height = 17
      Caption = #1056#1072#1085#1110#1096#1077' '#1079#1072
      TabOrder = 1
    end
    object ThisDate: TCheckBox
      Left = 20
      Top = 86
      Width = 97
      Height = 17
      Caption = #1062#1103' '#1076#1072#1090#1072
      TabOrder = 2
    end
    object Later: TCheckBox
      Left = 113
      Top = 63
      Width = 97
      Height = 17
      Caption = #1055#1110#1079#1085#1110#1096#1077
      TabOrder = 3
    end
    object Status: TGroupBox
      Left = 16
      Top = 109
      Width = 185
      Height = 84
      Caption = #1057#1090#1072#1090#1091#1089' '#1079#1076#1072#1095#1110
      TabOrder = 4
      object Status_check: TRadioGroup
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
    object Surname_student: TGroupBox
      Left = 16
      Top = 207
      Width = 185
      Height = 66
      Caption = #1055#1030#1041' '#1091#1095#1085#1103
      TabOrder = 5
      object Edit1: TEdit
        Left = 16
        Top = 24
        Width = 166
        Height = 23
        TabOrder = 0
        OnExit = Edit1Exit
      end
    end
  end
  object Clear: TBitBtn
    Left = 691
    Top = 279
    Width = 90
    Height = 34
    Caption = #1054#1095#1080#1089#1090#1080#1090#1080
    Glyph.Data = {
      36040000424D3604000000000000360000002800000010000000100000000100
      20000000000000040000C40E0000C40E00000000000000000000FEFEFEFFFEFE
      FEFFFCFCFCFF363636FF050505FF141414FF000000FF141414FF030303FF0707
      07FF121212FF060606FFC6C6C6FFFFFFFF00FDFDFDFFFFFFFF00FEFEFEFFFFFF
      FF00F0F0F0FF0A0A0AFF2D2D2DFF696969FF000000FF787878FF131313FF2424
      24FF6F6F6FFF000000FFA4A4A4FFFFFFFF00FCFCFCFFFFFFFF00FDFDFDFFFFFF
      FF00E2E2E2FF010101FF3C3C3CFF676767FF000000FF7E7E7EFF161616FF1E1E
      1EFF7A7A7AFF000000FF8F8F8FFFFFFFFF00FBFBFBFFFFFFFF00FDFDFDFFFFFF
      FF00CFCFCFFF000000FF464646FF5E5E5EFF000000FF7C7C7CFF171717FF1717
      17FF7E7E7EFF000000FF757575FFFFFFFF00FCFCFCFFFFFFFF00FCFCFCFFFFFF
      FF00BBBBBBFF000000FF515151FF575757FF000000FF7C7C7CFF191919FF1111
      11FF828282FF000000FF5E5E5EFFFFFFFF00FCFCFCFFFFFFFF00FBFBFBFFFFFF
      FF00A6A6A6FF000000FF5A5A5AFF4F4F4FFF000000FF7C7C7CFF1A1A1AFF0A0A
      0AFF848484FF000000FF474747FFFFFFFF00FDFDFDFFFFFFFF00FBFBFBFFFFFF
      FF008D8D8DFF000000FF626262FF474747FF000000FF7B7B7BFF1C1C1CFF0303
      03FF848484FF000000FF313131FFFEFEFEFFFFFFFF00FEFEFEFFFBFBFBFFFFFF
      FF00757575FF000000FF676767FF3E3E3EFF000000FF7A7A7AFF1D1D1DFF0000
      00FF828282FF000000FF1E1E1EFFF5F5F5FFFFFFFF00FEFEFEFFFCFCFCFFFFFF
      FF00636363FF040404FF777777FF3C3C3CFF040404FF848484FF232323FF0404
      04FF8C8C8CFF0D0D0DFF121212FFE9E9E9FFFFFFFF00FEFEFEFFFDFDFDFFFFFF
      FF003B3B3BFF000000FF454545FF121212FF000000FF4A4A4AFF070707FF0000
      00FF4C4C4CFF000000FF000000FFD2D2D2FFFFFFFF00FDFDFDFFFFFFFF00FFFF
      FF007C7C7CFF585858FF595959FF585858FF585858FF535353FF575757FF5C5C
      5CFF606060FF6B6B6BFF696969FFE2E2E2FFFFFFFF00FDFDFDFFFFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00E7E7E7FFB6B6B6FF737373FF4A4A4AFFF2F2F2FFFFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00EEEEEEFFC6C6C6FF919191FF515151FF1616
      16FF000000FF000000FF000000FF393939FFF5F5F5FFFFFFFF00FFFFFF00FBFB
      FBFFB6B6B6FF7D7D7DFF3E3E3EFF101010FF000000FF000000FF050505FF4242
      42FF393939FFA1A1A1FFDEDEDEFFFFFFFF00FFFFFF00FFFFFF00FEFEFEFFF9F9
      F9FF232323FF000000FF1E1E1EFF272727FF666666FFCCCCCCFFDEDEDEFFCECE
      CEFF7A7A7AFFFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FEFEFEFFFFFF
      FF00D9D9D9FFC9C9C9FFFAFAFAFFE5E5E5FF737373FF828282FF797979FF8282
      82FFD4D4D4FFFDFDFDFFFCFCFCFFFEFEFEFFFFFFFF00FFFFFF00}
    TabOrder = 2
    OnClick = ClearClick
  end
  object Execute: TBitBtn
    Left = 582
    Top = 279
    Width = 103
    Height = 34
    Caption = #1047#1072#1089#1090#1086#1089#1091#1074#1072#1090#1080
    DisabledImageName = 'Execute'
    Glyph.Data = {
      42040000424D4204000000000000420000002800000010000000100000000100
      20000300000000040000000000000000000000000000000000000000FF0000FF
      0000FF0000004C7047004C7047004C7047004C7047004C7047004C7047004C70
      47004C7047004C7047004C7047004C7047004C7047004C7047004C7047004C70
      47004C7047004C7047004C7047004C7047004C7047004C704700000000024C70
      47004C7047004C7047004C7047004C7047004C7047004C7047004C7047004C70
      47004C7047004C7047004C7047004C7047004C7047000000000C000000860000
      00604C7047004C7047004C7047004C7047004C7047004C7047004C7047004C70
      47004C7047004C7047004C7047004C7047000000000B00000092000000FF0000
      00EF000000604C7047004C7047004C7047004C7047004C7047004C7047004C70
      47004C7047004C7047004C7047000000000B00000092000000FD000000FF0000
      00FF000000EE000000604C7047004C7047004C7047004C7047004C7047004C70
      47004C7047004C7047000000000B00000092000000FD000000FF000000BD0000
      00D5000000FF000000EE000000604C7047004C7047004C7047004C7047004C70
      47004C7047000000000D00000090000000FD000000FF000000AC000000160000
      0036000000D5000000FF000000EE000000604C7047004C7047004C7047004C70
      47004C704700000000A2000000FC000000FF000000AC000000174C7047004C70
      470000000038000000D5000000FF000000EE000000604C7047004C7047004C70
      47004C7047000000009E000000FB000000AD000000174C7047004C7047004C70
      47004C70470000000038000000D5000000FF000000EE000000604C7047004C70
      47004C7047000000000F0000005C0000001A4C7047004C7047004C7047004C70
      47004C7047004C70470000000038000000D5000000FF000000EE000000604C70
      47004C7047004C7047004C7047004C7047004C7047004C7047004C7047004C70
      47004C7047004C7047004C70470000000038000000D5000000FF000000EE0000
      005F4C7047004C7047004C7047004C7047004C7047004C7047004C7047004C70
      47004C7047004C7047004C7047004C70470000000038000000D5000000FF0000
      00ED0000006F4C7047004C7047004C7047004C7047004C7047004C7047004C70
      47004C7047004C7047004C7047004C7047004C70470000000038000000D50000
      00FF000000C34C7047004C7047004C7047004C7047004C7047004C7047004C70
      47004C7047004C7047004C7047004C7047004C7047004C7047000000003A0000
      0098000000294C7047004C7047004C7047004C7047004C7047004C7047004C70
      47004C7047004C7047004C7047004C7047004C7047004C7047004C7047000000
      00034C7047004C7047004C7047004C7047004C7047004C7047004C7047004C70
      47004C7047004C7047004C7047004C7047004C7047004C7047004C7047004C70
      47004C704700}
    TabOrder = 3
    OnClick = ExecuteClick
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 8
    Width = 552
    Height = 319
    DataSource = DataModule1.MainFormSource
    TabOrder = 4
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    OnTitleClick = DBGrid1TitleClick
  end
  object MainMenu1: TMainMenu
    Left = 264
    Top = 256
    object N2: TMenuItem
      Caption = #1059#1095#1085#1110
      OnClick = N2Click
    end
    object N6: TMenuItem
      Caption = '|'
      Enabled = False
    end
    object N4: TMenuItem
      Caption = #1053#1072#1074#1095#1072#1083#1100#1085#1110' '#1076#1080#1089#1094#1080#1087#1083#1110#1085#1080
      OnClick = N4Click
    end
    object N3: TMenuItem
      Caption = #1059#1084#1086#1074#1080' '#1087#1088#1086#1093#1086#1076#1078#1077#1085#1085#1103
      OnClick = N3Click
    end
    object N9: TMenuItem
      Caption = #1053#1072#1074#1095#1072#1083#1100#1085#1110' '#1079#1072#1082#1083#1072#1076#1080
      OnClick = N9Click
    end
    object N7: TMenuItem
      Caption = '|'
      Enabled = False
    end
    object N5: TMenuItem
      Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090#1080' '#1090#1077#1089#1090#1091#1074#1072#1085#1085#1103
      OnClick = N5Click
    end
    object N1: TMenuItem
      Caption = #1057#1077#1088#1090#1080#1092#1110#1082#1072#1090#1080
      OnClick = N1Click
    end
    object N8: TMenuItem
      Caption = '|'
      Enabled = False
    end
    object Lj1: TMenuItem
      Caption = #1055#1088#1086' '#1076#1086#1076#1072#1090#1086#1082
      OnClick = Lj1Click
    end
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 328
    Top = 256
  end
end
