#ifndef MyServerTcpH
#define MyServerTcpH

#include <winsock.h>

//---------------------------------------------------------------------------
class MSocket
{
public:
  SOCKET handle;    //
  bool Connected;   // ��������� ?
  int  Error;       // ��������� �������� ����������� � ������� ?
  bool Exceptions;  // �������� ��������� ��� ������� ?
  bool bNoDestroy;

public:
  struct sockaddr_in destAddr, localAddr;
  int InBytes, OutBytes; // �������� ����
  int bytes;   // ���� ������� ��� �������� � ��������� ��������
  int errcode; // ==WSAGetLastError() ��������� ��������

public:
  MSocket(SOCKET h=NULL, bool enableExceptions = false);
  ~MSocket();

  void Initialize(MSocket * p);//SOCKET h, struct sockaddr_in * DestinationAddress);

public:
  // ������� ����������
  bool Close(void);
  // ��������� ���������� ����������
  bool IsOpen(void) { return Connected; }
  //
  // ��� ������� ���������� ������ � ���������� ������
  // (�.�. �� ��� ������� ���������� � ��������� �������� �
  // ������ �� ����� ���� � ����� ���������)
  bool Write(void * data, int size);
  bool Read(void * data, int size);
  // ��� ������� ���������� ����� ������
  //bool WriteTo(void * data, int size, struct sockaddr * p);
  //bool ReadFrom(void * data, int size, struct sockaddr * p);
  // ����� ����� ������ ��� ������ � ����� ��� �������� ?
  DWORD ReadLength(void);
  // ��������� ���������: ���� ������ ��� ����������,
  // ���� ����������� ������ ������, ���� ������, ����� ��������
  bool Poll(bool bread, bool bwrite, bool berror, long msec=0);

  // �������� ��������� ��������� �����
  int    GetError(void)  { return Error; }
  SOCKET GetHandle(void) { return handle; }

public:
  bool operator ! () { return GetError()!=0; }

public:
  MSocket & operator << (char * string)
  {
    if( string )
    {
      int l = lstrlen(string);
      if( l > 0 )
        Write(string, l+1);
    }
    return *this;
  }
  MSocket & operator << (char c) { Write((BYTE *)&c, sizeof(c)); return *this; }
  MSocket & operator << (int i)  { Write((BYTE *)&i, sizeof(i)); return *this; }
  MSocket & operator >> (char & c) { Read((BYTE *)&c, sizeof(c)); return *this; }

public:
  // �������� ��������� ����� � �������� �� ���������
  AnsiString GetLocalAddr(void);
  WORD GetLocalPort(void);
  AnsiString GetLocalAddrPort(void);

  // �������� ��������� �����, � ������� �� ���������
  AnsiString GetRemoteAddr(void);
  WORD GetRemotePort(void);
  AnsiString GetRemoteAddrPort(void);

  // �������� ��������� �� ������
  AnsiString GetErrorMessage(void);
  // �������� ��������� �� ������ �� �������
  AnsiString GetErrorMessageEng(void);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class MTCPServer : public MSocket
{
public:
  MTCPServer(bool enableExceptions = false);
  ~MTCPServer();

public:
  // ����� ���������� TCP
  bool Open(char * local="", WORD lport=0);

  MSocket * GetClient(long timetowait=100); // in msec
  //  ������� ����������
  bool Close(void);
  // ��������� ���������� ����������
  bool IsOpen(void) { return Connected; }
};
//---------------------------------------------------------------------------
#endif

