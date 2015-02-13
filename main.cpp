/**
 *   MD5 Hashr generate MD5 check sums and compare it to other check sums.
 *   Copyright (C) 2015  Christian Handorf - kodejak at gmail dot com
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>
 */
 
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "md5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#pragma resource "res.res"
#pragma resource "XPStyle.res"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
void LoadResourceFont( AnsiString ResourceName)
{
   TResourceStream *ResStream;
   unsigned long FontsCount;

   ResStream =  new TResourceStream((unsigned int)HInstance, ResourceName, "ANY_FONT" /*RT_RCDATA*/);
   AddFontMemResourceEx(ResStream->Memory, ResStream->Size, NULL, &FontsCount);
   delete ResStream;
}
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
    : TForm(Owner)
{
    try
    {
        LoadResourceFont("RES_FONT");
        Font->Name = "Raleway";
    }
    catch (...)
    {
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::RGJobClick(TObject *Sender)
{
    BtnFile->Visible = (RGJob->ItemIndex == 1);

    LMatch->Caption = "";
    EdInput->Text = "";
    EdOutput->Text = "";
    StatusBar->SimpleText = "";
}
//---------------------------------------------------------------------------
AnsiString TfrmMain::getMd5FromFile(AnsiString fName)
{
    MD5 md5;
    AnsiString out;

    out = AnsiString(md5.digestFile(fName.c_str()));

    return out;
}
//---------------------------------------------------------------------------
AnsiString TfrmMain::getMd5FromText(AnsiString text)
{
    MD5 md5;
    AnsiString out;

    out = AnsiString(md5.digestString(text.c_str()));
    return out;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormCreate(TObject *Sender)
{
    AnsiString md5, newFile;
    TStringList *sl;

    if (ParamCount() > 0)
    {
        if (FileExists(ParamStr(1)))
        {
            md5 = getMd5FromFile(ParamStr(1));
            sl = new TStringList();
            newFile = ParamStr(1) + ".md5";
            sl->Add(md5 + "  " + ExtractFileName(ParamStr(1)));
            try
            {
                sl->SaveToFile(newFile);
            }
            catch (...)
            {
            }

            delete sl;

            PostMessage(Handle, WM_CLOSE, 0, 0);
        }
    }
    else
    {

    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::BtnGenClick(TObject *Sender)
{
    MD5 md5;
    AnsiString out;

    switch (RGJob->ItemIndex)
    {
        case 0:
            out = getMd5FromText(EdInput->Text);
            break;

        case 1:
            if (FileExists(EdInput->Text) == false)
            {
                StatusBar->SimpleText = "File doesn't exists";
                return;
            }

            out = getMd5FromFile(EdInput->Text);
            break;
    };

    EdOutput->Text = out;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::BtnFileClick(TObject *Sender)
{
    if (OpenDlg->Execute())
    {
        EdInput->Text = OpenDlg->FileName;
    }    
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::BtnFileMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    TPanel *thisPanel;

    if (Sender->ClassNameIs("TPanel") == false)
        return;

    thisPanel = dynamic_cast<TPanel*> (Sender);

    if (thisPanel == NULL)
        return;

    thisPanel->BevelOuter = bvLowered;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::BtnFileMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    TPanel *thisPanel;

    if (Sender->ClassNameIs("TPanel") == false)
        return;

    thisPanel = dynamic_cast<TPanel*> (Sender);

    if (thisPanel == NULL)
        return;

    thisPanel->BevelOuter = bvRaised;

}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::BtnCompareClick(TObject *Sender)
{
    if (EdOutput->Text.Length() < 1)
    {
        StatusBar->SimpleText = "First MD5 field is empty";
        return;
    }
    if (EdComp->Text.Length() < 1)
    {
        StatusBar->SimpleText = "Second MD5 field is empty";
        return;
    }

    if (EdOutput->Text.Trim() != EdComp->Text.Trim())
    {
        LMatch->Caption = "No match!";
        LMatch->Font->Color = clRed;
    }
    else
    {
        LMatch->Caption = "Match!";
        LMatch->Font->Color = clLime;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::BtnCloseClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::EdInputChange(TObject *Sender)
{
    resetMatch();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::BtnFileSumClick(TObject *Sender)
{
    TStringList *sl;
    AnsiString md5sum;
    int pos;

    if (OpenSumDlg->Execute())
    {
        sl = new TStringList();
        sl->LoadFromFile(OpenSumDlg->FileName);

        if (sl->Count < 1)
        {
            goto badend;
        }

        pos = sl->Strings[0].AnsiPos(" ");
        if (pos == 0)
        {
            md5sum = sl->Strings[0];
        }
        else
        {
            md5sum = sl->Strings[0].SubString(1, pos-1);
        }

        EdComp->Text = md5sum;

badend:
        delete sl;
    }

}
//---------------------------------------------------------------------------
void TfrmMain::resetMatch()
{
    StatusBar->SimpleText = "";
    LMatch->Caption = "";
}
