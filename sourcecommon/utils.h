/*
  � ���� ������ ������������ ��������� ������� ������ ����������
 */
//---------------------------------------------------------------------------
#ifndef LMutilsH
#define LMutilsH

#define MAX(a, b)  (((a) > (b)) ? (a) : (b))
#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#define ABS(n)     (((n) < 0) ? (-(n)) : (n))

#define MyOneDay  1.0
#define MyOneHour (1.0/24.0)
#define MyOneMin  (1.0/1440.0)
#define MyOneSec  (1.0/86400.0)
#define MyOneMSec (1.0/86400000.0)

#define ONE_KB 1024
#define ONE_MB (1024*1024)
#define ONE_GB (1024*1024*1024)

/* __BORLANDC__
 0x0550	- C++Builder 5.0 Enterprise
 0x0560	- C++Builder 6.0 Enterprise
 0x0593 - CodeGear 2007
 0x0643 - XE2
*/

#if __BORLANDC__ >= 0x0600
  // Unicode ������ �������
  #define __UTEXT(quote) L##quote      // r_winnt
#else
  #define __UTEXT(quote) quote         // r_winnt
#endif

// ��� Unicode ������ ������� �������� TEXT("")
// ��, ������ ���� char ������� ��� unicode
// __UTEXT �������� ������

//---------------------------------------------------------------------------
// ������� �� ������ s ���: ' ' && '\t' && ������� �� ������ del
// ������, ������� ' ' && '\t' ����������� ����� ������� ������� �� ���������
// ����� �����������: ;... (������ ������ ����������� �������� � comment)
void ProcessString(char * s, char comment=';', char * del="\"");
// ������� �� ������ s ��� �������, ��������� � ������ del
void DeleteCharactersFromString(char * s, char * del="\"");
// �������� � ������ s ��� �������, ������������ � ������ source �� ������ dest
void ReplaceCharactersFromString(char * s, char * source, char dest);
// �������� � ������ s ��� ������� from �� ������ to
void ReplaceCharacters(AnsiString & s, char from, char to);
// ����������: szName �������� ������ ����� c:\123 ��� URL \\comp\123 ?
bool IsFullPath(char * szName);
// ��� �������� ����� ? (�������� ������� ? ��� *)
bool IsFileMask(char * szName);
// ������� �� ����� ����� name ������������ �������
void DeleteBadCharsFromFileName(String & name);
// ��������� ����� ��� ����� ��������
// ���������� ����� ����������� �������� �� ������ �����
int strcmpfixedlen(char * str1, char * str2);
//int strcmpfixedlen(String str1, String str2);
// ������� ���-�� �������� ' ' || '\t' � ������ ������ buf
int SkipSpace(char * buf);

// � ������� Danfoss Contour ���� ������ ������ ���� �������
#if !defined(DANFOSS)
// �������������� ���������� ��������� �� ������ � ����� ��� �� �����
void ReportError(char *fmt, ...);
// �������������� ��������� ������ � ����� �� �� �����
void ReportMess(char *fmt, ...);
// �������������� ���������� ������� � ����� ��� �� ����� � �������� "��" "���"
// �������: true  - ���� ������ ������ "��"
//          false - ���� ������ ������ "���"
bool ReportYesNo(char *fmt, ...);
// ��������� telnet.exe � ���������� params
bool RunTelnet(AnsiString params);
#endif

// �������� � ����� szDir ������ '\\' ���� ��� ��� ��� ���
void TerminateDirectory(char * szDir);
// �������� �� ����� szDir ������ '\\' ���� ��� �� ����
void UnTerminateDirectory(char * szDir);
// �������������� ������ fmt � �������� � ����� ����� szLogFile
// savetime ���������� ����� �� �������� � ������ ������ ������� �����
void WriteToLogTime(char *fmt, bool savetime, ...);

// � Danfoss Contour ���� WriteToLog
#if !defined(DANFOSS)
void WriteToLog(char *fmt, ...);
#endif

//---------------------------------------------------------------------------
// ������� ���������� � ��� ������������� �� ����� ������� !
bool DeleteDirectory(char * szPath, bool bDelTopDir=true);
// �������� ����� �� ����� szFrom �� ����� szMask � ����� szTo �� ����� ���������������
// ���� szFrom � szTo ������ ����������� �������� '\\'
bool CopyDirectory(char * szFrom, char * szMask, char * szTo);
//---------------------------------------------------------------------------
// ��� ������������� ������� ���������� ���������� � ������� ���� shlobj.h
// lpszPathObj - ���� � ������� (���������), ��� �������� ����� ����������� �����
// lpszWorkDir - ������� ������� ������� (���������)
// lpszPathLink - ������ ��� ����� ������
// lpszDesc - �����������
// lpszArgument - ��������� ��������� ������ ����������� ���������
HRESULT CreateLink(LPCSTR lpszPathObj, LPCSTR lpszWorkDir,
                   LPSTR lpszPathLink, LPSTR lpszDesc,
                   LPSTR lpszArgument="");
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class TMYIniFile;
// ������������ �� BYTE ������� ��� ������������� � �������� ���� LanMon 1
#pragma pack(push,1)
class TMyFont
{
public:
  TColor Color;
  int Height;
  char Name[32];
  TFontPitch Pitch;
  int PixelsPerInch;
  int Size;
  BYTE Style; // ���� 1 2 4 8 {fsBold,fsItalic,fsUnderline,fsStrikeOut};

public:
  void Get(TFont *);
  void Set(TFont *);
  bool Load(TMYIniFile * f, char * Section);
  bool Save(TMYIniFile * f, char * Section);
};
#pragma pack(pop)
//-----------------------------------------------------------------
// �������� ������ ���� �� "�������� ����". ������: TWaitCursor wait;
// ���������� ������ ������ ��� ������ ������� �� ������� ���������
class TWaitCursor
{
public:
	TWaitCursor() : oldc((TCursor)Screen->Cursor)
	{ Screen->Cursor = (TCursor)crHourGlass; }
    ~TWaitCursor()  { Screen->Cursor = (TCursor)oldc; }

private:
    TCursor oldc;
};
//---------------------------------------------------------------------------
// ������������� ����������������� ����� hex � ��������
BYTE HexVal(char hex);
// c - ��� ����������������� ����� ?
bool IsHexDigit(char c);
// ������������� �������� num �� 0 �� 15 � ������ ����������������� ����� �� '0' �� 'F'
char DigitToChar(BYTE num);
// ������������� ��� ������� ����������������� ���� �� '0' �� 'F' � ��������
BYTE CharToDigit(char ch, char cl);
// ������������� ������ ���� data[size] � ����������������� ������
AnsiString ToHexMas(void * data, int size);
// ������������� ����������������� ������ s � ������ ���� data[size]
// �������: false ���� ������� ������� size ������������ ���
//          � ������ ���������� �������� ������
//          true ���� �������������� ������ �������
bool FromHexMas(AnsiString s, void * data, int size);
//---------------------------------------------------------------------------
// ������������� �������� ������� interval � ������ ��� ������ �� �����
String GetTimeString(TDateTime interval);
// �������: "����" or "���" or "����" � ���-�� �� ���-�� ���� days
String GetDaysName(DWORD days);
// �������: "���" or "����" or "�����" � ���-�� �� ���-�� ����� hours
String GetHoursName(DWORD hours);

// ������������� ���-�� ���� � ������ ��� ������ �� �����
AnsiString GetBytesString(DWORD count);
String GetBytesStringEng(ULONGLONG count);
// ������������� �������� ������� interval � ������ ��� ������ �� �����
// � �������: "� ��:��:��"
AnsiString TimeIntervalToString(TDateTime interval);
//---------------------------------------------------------------------------
// �������� ��������� �������� ���� �� ������������ ��
// ��������� � �������� ������������ �������� �����
// ���� ���������� �������� - ������������ �� �����������
bool CorrectFormRect(int & l, int & t, int & w, int & h);

// ������������ ��������� ����� f �� ������� ����� �� ����� p
void LoadFormPosition(TMYIniFile * p, TForm * f);
// ��������� ��������� ����� f �� ������� ����� � ����� p
void SaveFormPosition(TMYIniFile * p, TForm * f);

// ������������ ��������� ����� f �� ������� ����� � ������ param[count] �� ����� szPositionFile
void LoadPosition(TForm * f, int * param=NULL, int count=NULL);
// ��������� ��������� ����� f �� ������� ����� � ������ param[count] � ����� szPositionFile
void SavePosition(TForm * f, int * param=NULL, int count=NULL);
// --//--
void LoadPosition(TForm * f, double * param, int count);
// --//--
void SavePosition(TForm * f, double * param, int count);
// --//--
void LoadPosition(TForm * f, AnsiString * param, int count);
// --//--
void SavePosition(TForm * f, AnsiString * param, int count);
//---------------------------------------------------------------------------
//void ASSERT(bool b);
// ������� ������ ������ size - ����� s � ������� ��������� �� ���
// ���� size=0, �� ����� ������ ����� �������������� ����� ������ s
// ����� ������������� ������������ ������� ����� ������� !
char * MyNewStr(char * s, int size=0);
// ������ �� ���������� ��������� � ����������� CmdLine
//   wShowWindow - ������� ��������� ���� ��� ��������� ���������
//   bWait = false �� ������� ���������� ��������� ���������
//   bWait = true ����� ���������� ��������� ���������
//   pExitCode - ��� �������� ��������� ��������� (������ ��� bWait = true)
//   szCurDir - ������������ ������� ������� ���������� ��� ������� ���������
//   pdwProcessId - ������������� �������� ��������� ��������� (������ ��� bWait = false)
bool RunProg(char * CmdLine, WORD wShowWindow=SW_NORMAL, bool bWait=false,
			 DWORD * pExitCode=NULL, char * szCurDir=NULL, DWORD * pdwProcessId=NULL);
// ������ ��������� Windows Paint ��� ����� file
bool RunPaint(String file, String * error=NULL);
//---------------------------------------------------------------------------
#define MAX_LAST_OPEN_DOCS 10
// �������� � ���� �������� szIniFile ��� ����� ��������� szDocFile
void AddToLastOpenDocs(char * szIniFile, char * szDocFile);
// �������� � ���� ������ ������� ���� mi[i] ����������� ������ �� ����� szIniFile
void AddLastOpenDocsToMenu(char * szIniFile, TMenuItem ** mi);
// ����������� ���������� �������� ��� ������ v � �������� ����� buf �������� size
// ���������� �������� ������ ��������������� ������
// ������������ ��� ���������� ���������� �������� � �������������� ������
int VarToBinary(Variant v, BYTE * buf, int size);
// ������ ����������� ����� ������� ������ N �� ������ P
BYTE Summa(void * P, WORD N);
// ������������� �� BCD val � ��������
BYTE FromBCD(BYTE val);
// ������������� � BCD �� �������� val
BYTE ToBCD(BYTE val);
// ������������� ���� val � �������� �������������
AnsiString ByteToBinary(BYTE val);
// ������� �� ������ s ����� � WordNumber (� 1)
// ������������ ���� � ������ ������ ���� �� �������� ������ delim
AnsiString ExtractSubString(AnsiString s, int WordNumber, AnsiString delim=" \t\n\r");
//---------------------------------------------------------------------------
// ������������� ������ ������� ���� source � ������ ��������� dest �� �������� ��������������
void Transliterate(char * source, char * dest);
// ���������� ��� � bit (� ����) � ������� data � �������� set
void SetBit(BYTE * data, int bit, bool set);
// �������� �������� ���� � bit (� ����) � ������� data
bool GetBit(BYTE * data, int bit);
// �������� ���-�� �������� � v (��� ��� v ����� ���� ��������)
int VariantGetValuesCount(Variant v);
// �������� ��� ��������� ������ GetLastError � ��������� ��� � error
// �������� ��� error ��������� �������� ������ � ����������
AnsiString FormatLastError(DWORD & error);
// �������� ��� error ��������� �������� ������ � ����������
// error - ��� ������������ GetLastError
AnsiString FormatLastError2(DWORD error);
// ���� s = "param=value" ���������� "value"
AnsiString __fastcall GetValueFromString(AnsiString s);
// �������� ������ ����������� ����� File �� ��� ������� ������ � ���������� Major, Minor, Release, Build
// ���������� false ��� ������ � true ��� ������
bool GetFileVersion(AnsiString File, WORD & Major, WORD & Minor, WORD & Release, WORD & Build);
// ��������������� IP �����, �������������� � DWORD, � ������
AnsiString IPAddrToString(DWORD ip);
// ��������������� TDateTime t � __int64 FileTime
ULONGLONG TDateTimeToFileTime(double t);
// ��������������� __int64 FileTime t � TDateTime
double TFileTimeToDateTime(ULONGLONG t);
// ���������� TRUE, ���� 'c' ������������ ����� ���� �� �������� ������ "+-*^/=;(),&|<>% \t\r"
int iscodedelim(char c);
// ������������ ������ � ������������ � ��������� PostgreSQL
AnsiString __fastcall MakePostgresString(AnsiString source, int maxlen=0);
// ��������� ��������� ����� � ������� ��������� ������� ������ szServiceName
// � ������� �������� to (� �������������)
bool __fastcall WaitService(char * szServiceName, DWORD dwCurrentState, DWORD to=15000);
// ����� ��� ����� � ���������� dir �� ����� mask � ��������� �� �������� ����� � p
void __fastcall FindFiles(TStrings * p, String dir, String mask);
//---------------------------------------------------------------------------
// �������������� ������ � �������� double result
// ����������� ����������� '.' ��� ','
// ���� � str - �������� ����� ��� ������ ������ ���������� false
// ���������� �� ���������
bool MyStrToFloat(String str, double & result);
// ��-�� � ���������� ����������
void MyStrToFloatException(String str, double & result);
double MyStrToFloatException(String str);
// ���������� �� ���������
double MyStrToFloatDef(String str, double def);
// �������������� ����� v � ������, ����� ����� digit ����
String MyFloatToStr(double v, int digit);

// �������������� ����� ��� ������ dow � ��������� ������������ ��� ������
// dow ��� � DayOfWeek():
// 1 = ����������� 7 = ������� (not ISO 8601 compliant)
// (8 = ���� ����������� ��� �������������)
String GetDayOfWeekNameLong(int dow);

// �������������� ������ ������ 1-12 � ��������� ������������ ������
String GetMonthNameLong(int month);

// �������������� ���� ������� dt � ��������� ������ ��� ������ �� �����
// ������ ������� �������� ���������� _TimeFormat (������ "hh:mm:ss.zzz")
// ������������ ��������:
//   ���� dt ������� �� ������������ ������ ����� �� ����� _TimeFormat
//   ���� dt � ������� ���� �� ������������ ����� �������� ������ � ����� �� ����� _TimeFormat
//   �� ���� ��������� ������� ������������ ����� �������� ������ ��� � ����� �� ����� _TimeFormat
#if __BORLANDC__ >= 0x0630
String DateTimeIntellektFormat(TDateTime dt, String _TimeFormat=FormatSettings.LongTimeFormat);
#else
String DateTimeIntellektFormat(TDateTime dt, String _TimeFormat=LongTimeFormat);
#endif
//---------------------------------------------------------------------------
// ���������� ����������� ������������ ������ � ����� ������ Windows
// ���������� � ������� �� Clipboard()->SetTextBuf()
bool setClipboard(AnsiString & lines);
String __fastcall GetRecommendedPath(bool common, String folder, String def);
// ������ SameText, ������������ �� ��������� � Builder 2007
bool __fastcall MySameText(String s1, String s2);
// ����������� source � ������ ��� ������ � ���������� ����������
// ����������� ������������� ������������
String FormatRegExpString(String source);
//---------------------------------------------------------------------------
struct colstring
{
  int val;
  char * string;
};
String GetColorNameRus(TColor c);
//---------------------------------------------------------------------------
void MySetLocalTime(TDateTime t);
// �������� ������� ������� ���� (Windows Vista and up)
// ���������� enum TOKEN_ELEVATION_TYPE:
//    -1 - ������ GetTokenInformation (�������� Windows version < Vista)
//    0  - ������ WinAPI
//    1 (TokenElevationTypeDefault) - UAC ��������
//    2 (TokenElevationTypeFull)    - Run As Administrator
//    3 (TokenElevationTypeLimited) - UAC �������
int GetCurrentElevationType(void);
// �������� ������ ���� � ������������ ����� ���������
// �������� ������ ����� ���������� � ���� ".\\" ��� Windows Vista and up
String GetApplicationExeName(void);
//---------------------------------------------------------------------------
// ���� ����� �/�� �������� ISO 8601: "yyyy[mm[dd[Thh[nn[ss[.zzzz]]]]]]"
String DateTimeToISO8601(TDateTime v);
TDateTime DateTimeFromISO8601(String s);
// ������ Str ���������� � StartStr ?
bool StringStartWith(String Str, String StartStr);
String GetTemporaryFileName(void);
//---------------------------------------------------------------------------
AnsiString SecurePassword(AnsiString password);
AnsiString UnsecurePassword(AnsiString secure_password);
//---------------------------------------------------------------------------
#endif
