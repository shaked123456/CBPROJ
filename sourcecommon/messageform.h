/*
  � ���� ������ ������������ ����� ��������� ���������.
  ����� ��������� �����������.
*/
//---------------------------------------------------------------------------
#ifndef messageformH
#define messageformH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TMessageForm : public TForm
{
__published:	// IDE-managed Components
        TSpeedButton *OkButton;
		TSpeedButton *CloseButton;
    TGroupBox *GroupBox;
    TImage *Image;
    TMemo *Memo;
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall CloseButtonClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TMessageForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMessageForm *MessageForm;
//---------------------------------------------------------------------------
/*
 ����� ���� � ���������� ���������
 ���������:
   OwnerForm - ��������� �� ������������ �����. ���� ������� NULL, �� ����
               ����� �������� � ������ �����
   Text - ����� ���������
   Caption - ��������� ����
   Modal - true ����� �������� ��������� ����
           false - ����������� (�� ���������)
   Error - true ����� ������� ������ "����" � ���� ������ "�������" (�� ���������)
           false ������ �� ����� � ���� ������ "��"
   Position - ������ ��������� ���� �� ������ (�� ��������� �� ������
           ������������ �����)
*/
void __fastcall ShowMessage2(TComponent * OwnerForm,
                             String Text,
                             String Caption="������",
                             bool Modal=false,
                             bool Error=true,
                             TPosition Position=poOwnerFormCenter);

// �������������� ���������� ��������� �� ������ � ����� ��� �� ����� � ��������� �����
void ReportError2(String fmt, ...);
// �������������� ��������� ������ � ����� �� �� ����� � ��������� �����
void ReportMess2(String fmt, ...);

// �������������� ���������� ��������� �� ������ � ����� ��� �� �����
// OwnerForm = Screen->ActiveForm | NULL
void ReportError3(bool bModal, TComponent * OwnerForm, String fmt, ...);
// �������������� ��������� ������ � ����� �� �� �����
void ReportMess3(bool bModal, TComponent * OwnerForm, String fmt, ...);
//---------------------------------------------------------------------------
#endif

