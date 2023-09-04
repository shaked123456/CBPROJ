//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "messageform.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TMessageForm * MessageForm = NULL;
//---------------------------------------------------------------------------
__fastcall TMessageForm::TMessageForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMessageForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if( Key==VK_RETURN || Key==VK_ESCAPE )
    CloseButtonClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TMessageForm::CloseButtonClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
// ����������� ����������� ���������� ���-�� ������������ ����� ��� ���������
int MemoMaxLinesVisible(TMemo * Memo)
{
  HGDIOBJ OldFont;
  HDC Hand;
  TEXTMETRIC TM;
  TRect Rect;
  int tempint;

  Hand = GetDC(Memo->Handle);
  try
  {
    OldFont = SelectObject(Hand, Memo->Font->Handle);
    try
    {
      GetTextMetrics(Hand, &TM);
      Memo->Perform(EM_GETRECT, 0, (Longint)&Rect);
      tempint = (Rect.Bottom - Rect.Top) / (TM.tmHeight + TM.tmExternalLeading);
    }
    __finally
    {
      SelectObject(Hand, OldFont);
    }
  }
  __finally
  {
    ReleaseDC(Memo->Handle, Hand);
  }
  return tempint;
}
//---------------------------------------------------------------------------
#define MaxFontSize 16

void __fastcall ShowMessage2(TComponent * OwnerForm,
                             String Text,
                             String Caption,
                             bool Modal,
                             bool Error,
                             TPosition Position)
{
  // ���������������� ��������� �� ������������ ��������
  // � ����, ��� ���������� TMessageForm �� ����� ��������� �
  // ��������� ���������� � OwnerForm == MessageForm
  // ��� �������� � Access violation !
  if( OwnerForm && OwnerForm == MessageForm )
    OwnerForm = NULL;

  // ����� ���� ��������� ������ ������ �� 2 ��������:
  // - ����� ��������� ��������� OwnerForm
  // - ����� ������� ���������� �����
  if( MessageForm )
    delete MessageForm;

  MessageForm = new TMessageForm(OwnerForm);

  MessageForm->Position = Position;
  MessageForm->Memo->Lines->Text = Text;
  MessageForm->Caption = Caption;
  if( Error )
  {
    MessageForm->OkButton->Visible = false;
    MessageForm->CloseButton->Visible = true;
    MessageForm->Image->Visible = true;
    MessageForm->Memo->Left = 64;
    MessageForm->Memo->Width = MessageForm->GroupBox->Width - 72;
  }
  else
  {
    MessageForm->OkButton->Visible = true;
    MessageForm->CloseButton->Visible = false;
    MessageForm->Image->Visible = false;
    MessageForm->Memo->Left = 8;
    MessageForm->Memo->Width = MessageForm->GroupBox->Width - 16;
  }

  // ����� ������� - �������� �����
  if( MessageForm->Memo->Lines->Count < MemoMaxLinesVisible(MessageForm->Memo) )
  {
    do
    {
      MessageForm->Memo->Font->Size = MessageForm->Memo->Font->Size + 1;
      // ����� MaxFontSize ������� �� �����������
      if( MessageForm->Memo->Font->Size == MaxFontSize ) break;
    }
    while( MessageForm->Memo->Lines->Count < MemoMaxLinesVisible(MessageForm->Memo) );

    // ���� ����� �������� ������� - �������� �����
    if( MessageForm->Memo->Lines->Count > MemoMaxLinesVisible(MessageForm->Memo) )
      MessageForm->Memo->Font->Size = MessageForm->Memo->Font->Size - 1;
  }
  // ����� �� ������� - �������� ������ ����
  else
  {
    for(int i=0; i<10 && MessageForm->Memo->Lines->Count > MemoMaxLinesVisible(MessageForm->Memo); i++)
    {
      MessageForm->Width = MessageForm->Width + 15;
      MessageForm->Height = MessageForm->Height + 20;
    }
  }

  // ������� � ������ ����� ���� ��� ��������� (����� ����� �� ����������)
  if( ! OwnerForm )
    SetWindowLong(MessageForm->Handle, GWL_EXSTYLE, GetWindowLong(MessageForm->Handle, GWL_EXSTYLE) | WS_EX_APPWINDOW);

  if( Modal )
    MessageForm->ShowModal();
  else
    MessageForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TMessageForm::FormClose(TObject *Sender, TCloseAction &Action)
{
  // ������� ����� ��� ��������
  Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TMessageForm::FormDestroy(TObject *Sender)
{
  // ���� � ShowMessage2 ����� �������� OwnerForm, �� ��� �������� ����� - ���������
  // TMessageForm ��������� �������������. � ���� ������ - ������� ���������
  MessageForm = NULL;
}
//---------------------------------------------------------------------------
void ReportError2(String fmt, ...)
{
#ifndef SYSTEMSERVICE
  va_list argptr;
  va_start(argptr, fmt);
  String s;
  s.vprintf(fmt.c_str(), argptr);
  ShowMessage2(Screen->ActiveForm,
			   s,
			   Application->Title, //L"������",
			   true,  // Modal
			   true); //Error
  va_end(argptr);
#endif
}
//---------------------------------------------------------------------------
void ReportMess2(String fmt, ...)
{
#ifndef SYSTEMSERVICE
  va_list argptr;
  va_start(argptr, fmt);
  String s;
  s.vprintf(fmt.c_str(), argptr);
  ShowMessage2(Screen->ActiveForm,
			   s,
			   Application->Title,
			   true,  // Modal
			   false); //Error
  va_end(argptr);
#endif
}
//---------------------------------------------------------------------------
void ReportError3(bool bModal, TComponent * OwnerForm, String fmt, ...)
{
#ifndef SYSTEMSERVICE
  va_list argptr;
  va_start(argptr, fmt);
  String s;
  s.vprintf(fmt.c_str(), argptr);
  ShowMessage2(OwnerForm,
			   s,
			   Application->Title, //L"������",
			   bModal,  // Modal
			   true); //Error
  va_end(argptr);
#endif
}
//---------------------------------------------------------------------------
void ReportMess3(bool bModal, TComponent * OwnerForm, String fmt, ...)
{
#ifndef SYSTEMSERVICE
  va_list argptr;
  va_start(argptr, fmt);
  String s;
  s.vprintf(fmt.c_str(), argptr);
  ShowMessage2(OwnerForm,
			   s,
			   Application->Title,
			   bModal,  // Modal
			   false); //Error
  va_end(argptr);
#endif
}
//---------------------------------------------------------------------------

