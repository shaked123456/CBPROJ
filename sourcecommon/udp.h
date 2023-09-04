#ifndef SaturnUDPSocketH
#define SaturnUDPSocketH
#include <winsock.h>

#define MYERROR_UNKNOWNPARAMS   50000
#define MYERROR_READCOUNT       50001
#define MYERROR_NOREQSIZE       50002

//---------------------------------------------------------------------------
class TUDP
{
private:
  SOCKET handle;        // ������������� ������
  bool Connected;       // ��������� ?
  bool Exceptions;      // �������� ��������� ��� ������� ?
  bool bBlockProtected; // ���� = true, �� ��� ������ � ����������� �������� ������
                        // ������������ ��������� ���������� ������ �� �������� ������

public:
  struct sockaddr_in destAddr, localAddr;
  int  InBytes;   // ����� ���� �������
  int  OutBytes;  // ����� ���� �������
  int  bytes;     // ���� ��������� � ��������� �������� ������ �� ������
  int  Error;     // if Error != 0 ������ ��������� �������� ����������� � �������
  int  WSAError;  // ��� ������ ������� WSAGetLastError()
  int  FlushSize; // ����� ������ �������, ������ �������� Flush()

public:
  TUDP(bool enableExceptions = false, bool _bBlockProtected = false);
  // ������ ����������� �������������� ���������� � ������ �������
  TUDP(char * dest, WORD port, bool enableExceptions = false,
       bool _bBlockProtected = false);
  ~TUDP();

public:
  // ������� ���������� UDP.
  // ���� local="" && lport=0 - ��� ����� ������� �������������.
  // ������: if( !udp.Open("", 0, "www.microsoft.com", 80) ) return false;
  // ����� ����� �������� � ������ local:lport
  // ����� ������������ ������� Write, Read, WriteTo, ReadFrom
  bool Open(char * local, WORD lport, char * dest, WORD dport);
  // ��-�� ��� � Open, �� �������� � ������ �� ��������������
  // ����� ������������ ������� ������ WriteTo, ReadFrom
  bool SimpleOpen(char * local, WORD lport, char * dest, WORD dport);

  bool BroadcastOpen(WORD port);
  
  //  ������� ����������
  bool Close(void);
  // ��������� ���������� ����������
  bool IsOpen(void) { return Connected; }
  // ��������� ����������������� ������
  bool __fastcall EnableBroadcast(BOOL enable);

  // ��� ������� ���������� ������ � ���������� ������
  // (�.�. �� ��� ������� ���������� � ��������� �������� �
  // ������ �� ����� ���� � ����� ���������)
  bool Write(void * data, int size);
  virtual bool Read(void * data, int size, bool bPeek=false);

  // ��� ������� ���������� ����� ������
  bool WriteTo(void * data, int size, struct sockaddr * p);
  // ��������� ������ ������ �� ��������� ������
  bool ReadFrom(void * data, int size, struct sockaddr * p, bool bPeek=false);
  // C�������� ������ ���� ������� � �������� ������
  virtual DWORD ReadLength(void);
  // ��������� ���������: ���� ������ ��� ����������,
  // ���� ����������� ������ ������, ���� �������, ����� ��������
  bool Poll(bool bread, bool bwrite, bool berror, long msec=0);
  // �������� �������� �����
  // ���������� - ������� ������� �������
  virtual int Flush(void);

  // �������� ��������� ����� � �������� �� ���������
  AnsiString GetLocalAddr(void);
  WORD GetLocalPort(void);
  AnsiString GetLocalAddrPort(void);

  // �������� ��������� �����, � ������� �� ���������
  AnsiString GetRemoteAddr(void);
  WORD GetRemotePort(void);
  AnsiString GetRemoteAddrPort(void);

  // �������� ��������� ��������� �����
  int    GetError(void)    { return Error; }
  int    GetWSAError(void) { return WSAError; }
  SOCKET GetHandle(void)   { return handle; }

  // �������� ��������� �� ������
  AnsiString GetErrorMessage(void);
  // �������� ��������� �� ������ �� �������
  AnsiString GetErrorMessageEng(void);

public:
  bool operator ! () { return GetError()!=0; }
  __property BOOL Broadcast = {write=EnableBroadcast};
};
//---------------------------------------------------------------------------
#endif
