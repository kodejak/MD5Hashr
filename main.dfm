object frmMain: TfrmMain
  Left = 526
  Top = 380
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'MD5 Hashr'
  ClientHeight = 610
  ClientWidth = 521
  Color = clAppWorkSpace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Tahoma'
  Font.Style = [fsBold]
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 19
  object Label1: TLabel
    Left = 8
    Top = 120
    Width = 50
    Height = 19
    Caption = 'Input:'
  end
  object Label2: TLabel
    Left = 8
    Top = 224
    Width = 62
    Height = 19
    Caption = 'Output:'
  end
  object Bevel1: TBevel
    Left = 8
    Top = 280
    Width = 505
    Height = 10
    Shape = bsBottomLine
  end
  object Label3: TLabel
    Left = 8
    Top = 312
    Width = 200
    Height = 19
    Caption = 'Comparison (MD5 hash):'
  end
  object Bevel2: TBevel
    Left = 8
    Top = 488
    Width = 505
    Height = 10
    Shape = bsBottomLine
  end
  object Label4: TLabel
    Left = 8
    Top = 8
    Width = 505
    Height = 49
    AutoSize = False
    Caption = 
      'Hint: You can  Drag && Drop  files to this EXE file in Explorer ' +
      'to generate *.md5 from desired files. You can use also MD5Hashr ' +
      'in a batch to generate *.md5 files with just simply  add a file ' +
      'name as a parameter.'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = True
    WordWrap = True
  end
  object Label5: TLabel
    Left = 8
    Top = 568
    Width = 505
    Height = 19
    Alignment = taCenter
    AutoSize = False
    Caption = 'Copyright (c) 2015 by kodejak - licensed under GPLv3+'
  end
  object EdInput: TEdit
    Left = 8
    Top = 144
    Width = 473
    Height = 27
    BorderStyle = bsNone
    TabOrder = 0
    OnChange = EdInputChange
  end
  object RGJob: TRadioGroup
    Left = 8
    Top = 56
    Width = 505
    Height = 57
    Caption = ' Job '
    Columns = 3
    ItemIndex = 0
    Items.Strings = (
      'Text to MD5'
      'File to MD5')
    TabOrder = 1
    OnClick = RGJobClick
  end
  object EdOutput: TEdit
    Left = 8
    Top = 248
    Width = 505
    Height = 27
    BorderStyle = bsNone
    TabOrder = 2
    OnChange = EdInputChange
  end
  object EdComp: TEdit
    Left = 8
    Top = 336
    Width = 473
    Height = 27
    BorderStyle = bsNone
    TabOrder = 3
    OnChange = EdInputChange
  end
  object BtnGen: TPanel
    Left = 8
    Top = 176
    Width = 225
    Height = 25
    Caption = 'Generate MD5 hash'
    Color = 5889348
    TabOrder = 4
    OnClick = BtnGenClick
    OnMouseDown = BtnFileMouseDown
    OnMouseUp = BtnFileMouseUp
  end
  object BtnFile: TPanel
    Left = 488
    Top = 144
    Width = 25
    Height = 25
    Hint = 'Open file to genarte md5 sum'
    Caption = '...'
    Color = 5889348
    ParentShowHint = False
    ShowHint = True
    TabOrder = 5
    Visible = False
    OnClick = BtnFileClick
    OnMouseDown = BtnFileMouseDown
    OnMouseUp = BtnFileMouseUp
  end
  object BtnClose: TPanel
    Left = 148
    Top = 512
    Width = 225
    Height = 25
    Caption = 'Close'
    Color = 5889348
    TabOrder = 6
    OnClick = BtnCloseClick
    OnMouseDown = BtnFileMouseDown
    OnMouseUp = BtnFileMouseUp
  end
  object BtnCompare: TPanel
    Left = 8
    Top = 368
    Width = 225
    Height = 25
    Caption = 'Compare'
    Color = 5889348
    TabOrder = 7
    OnClick = BtnCompareClick
    OnMouseDown = BtnFileMouseDown
    OnMouseUp = BtnFileMouseUp
  end
  object StatusBar: TStatusBar
    Left = 0
    Top = 591
    Width = 521
    Height = 19
    Panels = <>
    SimplePanel = True
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 408
    Width = 505
    Height = 81
    Caption = ' COMPARE RESULT '
    TabOrder = 9
    object LMatch: TLabel
      Left = 8
      Top = 24
      Width = 489
      Height = 49
      Alignment = taCenter
      AutoSize = False
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -37
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
      Transparent = True
    end
  end
  object BtnFileSum: TPanel
    Left = 488
    Top = 336
    Width = 25
    Height = 25
    Hint = 'Open md5sum file to compare'
    Caption = '...'
    Color = 5889348
    ParentShowHint = False
    ShowHint = True
    TabOrder = 10
    OnClick = BtnFileSumClick
    OnMouseDown = BtnFileMouseDown
    OnMouseUp = BtnFileMouseUp
  end
  object OpenDlg: TOpenDialog
    Filter = 'All files (*.*)|*.*'
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Left = 352
    Top = 72
  end
  object OpenSumDlg: TOpenDialog
    Filter = 'MD5 sum file (*.md5)|*.md5'
    Left = 384
    Top = 72
  end
end
