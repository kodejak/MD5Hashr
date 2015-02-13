//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
    TEdit *EdInput;
    TLabel *Label1;
    TRadioGroup *RGJob;
    TOpenDialog *OpenDlg;
    TLabel *Label2;
    TEdit *EdOutput;
    TBevel *Bevel1;
    TLabel *Label3;
    TEdit *EdComp;
    TPanel *BtnGen;
    TPanel *BtnFile;
    TPanel *BtnClose;
    TPanel *BtnCompare;
    TStatusBar *StatusBar;
    TBevel *Bevel2;
    TLabel *Label4;
    TGroupBox *GroupBox1;
    TLabel *LMatch;
    TPanel *BtnFileSum;
    TOpenDialog *OpenSumDlg;
    TLabel *Label5;
    void __fastcall RGJobClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall BtnGenClick(TObject *Sender);
    void __fastcall BtnFileClick(TObject *Sender);
    void __fastcall BtnFileMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall BtnFileMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall BtnCompareClick(TObject *Sender);
    void __fastcall BtnCloseClick(TObject *Sender);
    void __fastcall EdInputChange(TObject *Sender);
    void __fastcall BtnFileSumClick(TObject *Sender);
private:	// Anwender-Deklarationen
    AnsiString getMd5FromFile(AnsiString fName);
    AnsiString getMd5FromText(AnsiString text);

    void resetMatch();
public:		// Anwender-Deklarationen
    __fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
