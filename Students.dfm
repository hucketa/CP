object Form14: TForm14
  Left = 0
  Top = 0
  AutoSize = True
  BorderStyle = bsSingle
  Caption = #1056#1086#1073#1086#1090#1072' '#1079' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1108#1102' '#1087#1088#1086' '#1091#1095#1072#1089#1085#1080#1082#1110#1074' '#1053#1052#1058
  ClientHeight = 369
  ClientWidth = 897
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  Position = poDesktopCenter
  OnCreate = FormCreate
  TextHeight = 15
  object DBGrid1: TDBGrid
    Left = 0
    Top = 0
    Width = 897
    Height = 239
    DataSource = DataModule1.DataSource1
    PopupMenu = PopupMenu1
    ReadOnly = True
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    OnTitleClick = DBGrid1TitleClick
    Columns = <
      item
        Expanded = False
        FieldName = 'Student_id'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Passport_num'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Passport_type'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'PIB'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Birth_date'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Gender'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Email'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Phone_num'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'EduCerf_num'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'PN'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Additional'
        Visible = True
      end>
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 245
    Width = 894
    Height = 124
    Hint = #1055#1086#1083#1103' '#1076#1083#1103' '#1074#1074#1077#1076#1077#1085#1085#1103' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1111' '#1087#1088#1086' '#1089#1090#1091#1076#1077#1085#1090#1072
    Caption = #1060#1110#1083#1100#1090#1088#1072#1094#1110#1103
    TabOrder = 1
    object Label1: TLabel
      Left = 16
      Top = 184
      Width = 58
      Height = 15
      Caption = #1055#1086#1084#1110#1090#1082#1072'(*)'
    end
    object Label3: TLabel
      Left = 63
      Top = 17
      Width = 75
      Height = 15
      Caption = #1058#1080#1087' '#1087#1072#1089#1087#1086#1088#1090#1091
    end
    object Label7: TLabel
      Left = 568
      Top = 47
      Width = 34
      Height = 15
      Caption = 'E-mail'
    end
    object DatePicker1: TDatePicker
      Left = 400
      Top = 39
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
    object RadioGroup1: TRadioGroup
      Left = 208
      Top = 22
      Width = 161
      Height = 41
      Caption = #1057#1090#1072#1090#1100
      Columns = 2
      Items.Strings = (
        #1063#1086#1083#1086#1074#1110#1095#1072
        #1046#1110#1085#1086#1095#1072)
      TabOrder = 1
    end
    object Button1: TButton
      Left = 16
      Top = 210
      Width = 404
      Height = 25
      Caption = #1047#1072#1084#1110#1085#1080#1090#1080
      TabOrder = 2
    end
    object Edit5: TEdit
      Left = 608
      Top = 43
      Width = 132
      Height = 23
      TabOrder = 3
      OnExit = Edit5Exit
    end
    object Clear: TBitBtn
      Left = 125
      Top = 79
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
      TabOrder = 4
      OnClick = ClearClick
    end
    object Execute: TBitBtn
      Left = 16
      Top = 79
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
      TabOrder = 5
      OnClick = ExecuteClick
    end
    object ThisDate: TCheckBox
      Left = 375
      Top = 16
      Width = 218
      Height = 17
      Caption = #1060#1110#1083#1100#1090#1088#1091#1074#1072#1090#1080' '#1079#1072' '#1076#1072#1090#1086#1102' '#1085#1072#1088#1086#1076#1078#1077#1085#1085#1103
      TabOrder = 6
    end
    object ComboBox1: TComboBox
      Left = 40
      Top = 38
      Width = 145
      Height = 23
      TabOrder = 7
    end
    object DatePicker2: TDatePicker
      Left = 400
      Top = 77
      Date = 45563.000000000000000000
      DateFormat = 'dd/mm/yyyy'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      TabOrder = 8
      OnCloseUp = DatePicker2CloseUp
    end
  end
  object MainMenu1: TMainMenu
    Left = 408
    object N6: TMenuItem
      Caption = #1043#1086#1083#1086#1074#1085#1077' '#1084#1077#1085#1102
      OnClick = N6Click
    end
    object Lj1: TMenuItem
      Caption = #1055#1088#1086' '#1076#1086#1076#1072#1090#1086#1082
      OnClick = Lj1Click
    end
  end
  object PopupMenu1: TPopupMenu
    MenuAnimation = [maNone]
    Left = 456
    object N1: TMenuItem
      Caption = #1056#1077#1076#1072#1075#1091#1074#1072#1090#1080
      OnClick = N1Click
    end
    object N2: TMenuItem
      Caption = #1044#1086#1076#1072#1090#1080
      OnClick = N2Click
    end
  end
end
