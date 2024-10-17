object Form7: TForm7
  Left = 0
  Top = 0
  AutoSize = True
  Caption = #1056#1086#1073#1086#1090#1072' '#1079' '#1110#1085#1092#1086#1088#1084#1072#1094#1110#1108#1102' '#1087#1088#1086' '#1087#1088#1077#1076#1084#1077#1090#1080
  ClientHeight = 169
  ClientWidth = 798
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  Position = poDefault
  OnClose = FormClose
  OnCreate = FormCreate
  TextHeight = 15
  object Image1: TImage
    Left = 635
    Top = 0
    Width = 159
    Height = 168
  end
  object DBGrid1: TDBGrid
    Left = 0
    Top = 0
    Width = 629
    Height = 168
    DataSource = DataModule1.DataSource2
    PopupMenu = PopupMenu1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    OnCellClick = DBGrid1CellClick
    OnTitleClick = DBGrid1TitleClick
    Columns = <
      item
        Expanded = False
        FieldName = 'Subject_id'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Name'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Description'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Image_name'
        Visible = True
      end>
  end
  object MainMenu1: TMainMenu
    Left = 584
    Top = 24
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
    Left = 520
    Top = 24
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
