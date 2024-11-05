object Form15: TForm15
  Left = 0
  Top = 0
  AutoSize = True
  Caption = #1050#1086#1088#1080#1089#1090#1091#1074#1072#1095#1110
  ClientHeight = 146
  ClientWidth = 654
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnShow = FormShow
  TextHeight = 15
  object DBGrid1: TDBGrid
    Left = 0
    Top = 0
    Width = 650
    Height = 145
    DataSource = DataModule1.DataSource7
    PopupMenu = PopupMenu1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    OnTitleClick = DBGrid1TitleClick
  end
  object PopupMenu1: TPopupMenu
    Left = 264
    Top = 176
    object N1: TMenuItem
      Caption = #1044#1086#1076#1072#1090#1080
      OnClick = N1Click
    end
    object N2: TMenuItem
      Caption = #1056#1077#1076#1072#1075#1091#1074#1072#1090#1080
      OnClick = N2Click
    end
  end
end
