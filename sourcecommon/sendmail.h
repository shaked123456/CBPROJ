#ifndef __SENDMAIL_H__
#define __SENDMAIL_H__

#include <IdSSLOpenSSL.hpp>
#include <IdExplicitTLSClientServerBase.hpp>
#include <IdSMTP.hpp>
#include <IdReplySMTP.hpp>

#include "unilist.h"
#include "letter.h"

/* TSendmailThread - ����� ������ ��� �������� E-Mail (������ TLetter)
   ������������ ���������� Indy.Sockets (VCL) version 10
   (http://www.indyproject.org/Sockets/index.EN.aspx)
   �����: ������� �.

   ��� �������� E-Mail ����� ������� �������� ������� TLetter (��. letter.h)
   � ��������� ��� �������� �����:

     server - ����� ������� � ������ ������������ �� SMTP
     port   - ���� �������
     username - ��� ������������, ��� ��������������
     password - ������, ��� ��������������
     ssl - SMTP_SSL_OFF ��� (������������ �����������),
           SMTP_SSL_ON  ������������ SSL ����� (������ 465 ����),
           SMTP_SSL_TLS ������������ TLS ����� ���� ��� ������ �������� (������ 587 ����)

     sender - e-mail ����� �����������
     sender_name - ��� �����������
     recipient - e-mail ����� ����������
     subject - ���� ������
     message - ���������

     callback - �������, ������� ����� ������� �� �������� ������ ��� ������.
                ���������:
                  self - ������ TLetter; � ��� ���� error
                         ����� ����� � ��������� ������ ���� result == false
     closure - �� �� ����� ��� � callback, �� � ����������� ��������� �� ������.
               ��������� �������� �������, ���������� �������� �������.

   ���������� ��������� �� �����:
   TSendmailThread * SendmailThread = NULL;

   ����� ����� ����� ������� ����������� �������
   TSendmailThread::Send(&SendmailThread, TLetter *)
   ��� ������� ����� �������� �����, �������� ������ � ������� �� �������� �
   ������ ���������� ���������.
   �������� ������ �������� ����� ����������� ������ ��� �������� ������� ������.
   � ���������� �������� ������ ����� ������ � ������� callback / closure
   ��� ���������� ���������� ����� ������� ����������� �������
   TSendmailThread::Exit(&SendmailThread)
   ��� ���������� ������ ������ �������� �����.
*/

//---------------------------------------------------------------------------
class TSendmailThread : public TThread
{
private:
  TIdSMTP * smtp;             // ��������� SMTP (���������� indy)
  TIdSSLIOHandlerSocketOpenSSL * SSLIOHandler; // ��������� SSL
  TUniList<TLetter> letters;  // ������� ����� �� ��������
  TLetter * SyncLetter;       // ��������� ��� ������� sync()

private:
  // ��������� ���������� �������� ������
  // ��� ���������� ����� ����
  bool SendInternal(TLetter * p);
  // ����� TLetter::callback and/or TLetter::closure � ��������� ��������� ������
  void __fastcall sync(void);
  // ������� ������������� ��������� ����� UTF8
  // ���������� ��� TIdMessage::OnInitializeISO
  void __fastcall iiso(char &VHeaderEncoding, AnsiString &VCharSet);

protected:
  // �������� ������� ������
  void __fastcall Execute();

public:
  __fastcall TSendmailThread(void);
  __fastcall ~TSendmailThread();
  // ������� ����� (���� �� ��� �� ������), �������� ��������� �� ���� �
  // *SendmailThread � ���������� ������ TLetter
  static void __fastcall Send(TSendmailThread ** SendmailThread, TLetter * p);
  // ������� ����� �� ��������� *SendmailThread
  static void __fastcall Exit(TSendmailThread ** SendmailThread);
};
//---------------------------------------------------------------------------
#endif
