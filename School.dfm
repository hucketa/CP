object Form6: TForm6
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = #1056#1086#1073#1086#1090#1072' '#1079' '#1085#1072#1074#1095#1072#1083#1100#1085#1080#1084#1080' '#1079#1072#1082#1083#1072#1076#1072#1084#1080
  ClientHeight = 178
  ClientWidth = 666
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  Position = poDesktopCenter
  OnShow = FormShow
  TextHeight = 15
  object DBGrid1: TDBGrid
    Left = 8
    Top = 8
    Width = 657
    Height = 169
    DataSource = DataModule1.DataSource4
    PopupMenu = PopupMenu1
    ReadOnly = True
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    OnTitleClick = DBGrid1TitleClick
  end
  object MainMenu1: TMainMenu
    Left = 360
    Top = 128
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
    Left = 440
    Top = 128
    object N1: TMenuItem
      Caption = #1044#1086#1076#1072#1090#1080
      OnClick = N1Click
    end
    object N2: TMenuItem
      Caption = #1056#1077#1076#1072#1075#1091#1074#1072#1090#1080
      OnClick = N2Click
    end
    object N3: TMenuItem
      Caption = #1042#1080#1076#1072#1083#1080#1090#1080
      OnClick = N3Click
    end
  end
end
