/*
 � ���� ������ ������������ VCL ����� TSaveParams
 �� ������ ������� ��� ������� TSaveParamsINI � TSaveParamsXML

 ����� ������� �.

 ������ �������������:

   TSaveParamsINI * p = new TSaveParamsINI;
   // ��������� ���������� �������� ����� ��������� File �������������
   // ������ ����������� INI ����� 
   //p->CreateNewFile = true;
   // ��������� ���� ��� ������
   // ��� ���� ���������� ������ �����
   // ����� �������� �������� ��� ������� �����
   // ���� ���� �� ������ - ������������ "params.ini" � ����� ���������
   p->File = "c:\\myfile.ini";

   // ���������� �������� �� ��������
   p->CurrentSection = "setup"; // ��������� �������� ������ (������)
   p->Values["bool_value"] = true;
   p->Values["int_value"] = 123;
   p->Values["string_value"] = "������!";
   p->Values["double_value"] = 123.456;

   // ���������� �������� �� ������� (� ����)
   p->CurrentSection = "group";
   p->ValuesByIndex[0] = "������";

   // ���������� �������� � ��������� ����� TForm � ����� ������� TStringGrid
   // ���������� ������������ � ������ � ������ = ����� �����
   *p << Form1 << StringGrid1;

   // ���������� �������� ����� ����� TParamValue
   TParamValue par1("par1", 123); // ������� �������� � ������ par1 ��������� 123
   TParamValue par2("par2"); // ������� �������� � ������ par2 ��� ��������
   par2.value = 321;
   p->CurrentSection = "group";
   *p << par1 << par2;

   // ��������� �������� �� ��������
   p->CurrentSection = "setup";
   bool b = p->Values["bool_value"];
   int i = p->Values["int_value"];
   AnsiString s = p->Values["string_value"];
   // �������� �� ������� ��������� � ������ "double_value"
   double d;
   Variant v = p->Values["double_value"];
   if( ! v.IsEmpty() )
     d = v;

   // ��������� �������� �� �������
   p->CurrentSection = "group";
   AnsiString s1 = p->ValuesByIndex[0];

   // ��������� �������� � ��������� ����� TForm � ����� ������� TStringGrid
   *p >> Form1 >> StringGrid1;

   // ��������� �������� ����� ����� TParamValue
   p->CurrentSection = "group";
   *p >> par1 >> par2;

   p->Save(); // ����������� ������ �� ����

   delete p; // ���������� ����� ��� �� ����
*/
//---------------------------------------------------------------------------
#ifndef saveparH
#define saveparH

#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>

//---------------------------------------------------------------------------
// ����� ���������
class TParamValue
{
public:
  AnsiString name;
  Variant value;

public:
  TParamValue(AnsiString n, Variant v=Variant());
  TParamValue(void);
  bool Empty(void);
};
//---------------------------------------------------------------------------
// ������� ����� ��� ������ � ������ ����������
class TSaveParams : public TObject
{
protected:
  AnsiString fFile;
  bool fCreateNewFile;
  AnsiString fCurrentSection;
  int fMinimumColumnWidth;

private:
  // ��� ������� �������� � ����������� � ������� ������ CurrentSection
  void __fastcall SetByName(AnsiString name, Variant value);
  Variant __fastcall GetByName(AnsiString name);
  void __fastcall SetByIndex(int index, Variant value);
  Variant __fastcall GetByIndex(int index);

public:
  // inFile: ���� �� ����������
  // inCreateNewFile: true-�� ������ ���������� ����� inFile
  //                  false-������ ����������� ����� inFile
  TSaveParams(AnsiString inFile, bool inCreateNewFile=false);
  //TSaveParams(void);

  // ���������� �������� value ��������� name � ������ Section
  void virtual Set(AnsiString Section, AnsiString name, Variant value) = 0;
  // ��������� �������� ��������� name �� ������ Section
  // ���� ��������� �������� �� ������ ����� IsEmpty() � ������������� Variant ������ true
  Variant virtual Get(AnsiString Section, AnsiString name, Variant defval=Variant()) = 0;

  // �������� ������������� ������ Section
  bool virtual SectionExists(const AnsiString Section) = 0;
  // �������� ������������� �������� name � ������ Section
  bool virtual ValueExists(const AnsiString Section, const AnsiString name) = 0;

  // ������ �������� �� ����� File
  bool virtual Load(AnsiString File) = 0;
  // ������ �������� � ����, �� �������� �� ���������
  bool virtual Save(void) = 0;

public:
  // ���������� � �������������� ��������� � �������� �����
  void SetVcl(TForm * p);
  void GetVcl(TForm * p);

  // ���������� ��������� �����
  void SetVclPos(TForm * p);
  void GetVclPos(TForm * p);

  // ���������� � �������������� ����� ������� ��� ������ �����������
  void SetVcl(TStringGrid * p);
  void GetVcl(TStringGrid * p);
  void SetVcl(TDBGrid * p);
  void GetVcl(TDBGrid * p);
  void SetVcl(TListView * p);
  void GetVcl(TListView * p);
  // ������� VCL
  void SetVcl(TEdit * p);
  void GetVcl(TEdit * p);
  void SetVcl(TCheckBox * p);
  void GetVcl(TCheckBox * p);

// ���������� � �������������� ������� ��� ����� �����������,
// � ���� ���� �����. � �������� Section ���������� ��� �������������
// ����������, �������� p->Owner->Name, � � �������� Name - ��� ����������
// ��� ���� ����������� � ����������������� �����, �������� p->Name.
// � �������� Font - ��� ����� ����� ����������, �������� p->Font.
  void SetFont(AnsiString Section, AnsiString Name, TFont* Font);
  void GetFont(AnsiString Section, AnsiString Name, TFont* Font);

  // ���������� � �������������� ������ ��������� ��� ������� ����������
  void SetVcl(TParamValue * p);
  void GetVcl(TParamValue * p);
  void SetMany(TParamValue * p, int count);
  void GetMany(TParamValue * p, int count);

  // ��� ������� �������� �������� �� ������� ������ CurrentSection
  // � ��������� ��������� �������� �� ���������
  Variant GetByNameDef(AnsiString name, Variant defval);
  Variant GetByIndexDef(int index, Variant defval);

  // �������� ���������
public:
  TSaveParams & operator << (TForm * p);
  TSaveParams & operator >> (TForm * p);
  TSaveParams & operator < (TForm * p);
  TSaveParams & operator > (TForm * p);
  TSaveParams & operator << (TStringGrid * p);
  TSaveParams & operator >> (TStringGrid * p);
  TSaveParams & operator << (TDBGrid * p);
  TSaveParams & operator >> (TDBGrid * p);
  TSaveParams & operator << (TListView * p);
  TSaveParams & operator >> (TListView * p);
  TSaveParams & operator << (TEdit * p);
  TSaveParams & operator >> (TEdit * p);
  TSaveParams & operator << (TCheckBox * p);
  TSaveParams & operator >> (TCheckBox * p);
  TSaveParams & operator << (TParamValue & p);
  TSaveParams & operator >> (TParamValue & p);

  // ������� ��� ������� �������� � ������ TIniFile
public:
  int ReadInteger(const AnsiString Section, const AnsiString Ident, int Default);
  AnsiString ReadString(const AnsiString Section, const AnsiString Ident, const AnsiString Default);
  double ReadFloat(const AnsiString Section, const AnsiString Ident, double Default);
  bool ReadBool(const AnsiString Section, const AnsiString Ident, bool Default);

  void WriteInteger(const AnsiString Section, const AnsiString Ident, int Value);
  void WriteString(const AnsiString Section, const AnsiString Ident, const AnsiString Value);
  void WriteFloat(const AnsiString Section, const AnsiString Ident, double Value);
  void WriteBool(const AnsiString Section, const AnsiString Ident, bool Value);

  // ��������
__published:
  __property AnsiString File = {read=fFile, write=fFile};
  __property AnsiString CurrentSection = {read=fCurrentSection, write=fCurrentSection};
  __property bool CreateNewFile = {read=fCreateNewFile, write=fCreateNewFile};
  // ����������� ������ �������, ������� ��������������� ��� �������������� �� �������
  // �� ��������� 0, �.�. ����� ������������� ����� ������ �������
  // ������: ��������� MinimumColumnWidth � �������� 10 ����������, ��� ������ �������
  // �� ����� ����������� ����� 10
  __property int MinimumColumnWidth = {read=fMinimumColumnWidth, write=fMinimumColumnWidth};

  // ��� �������� �������� � ����������� � ������� ������ CurrentSection
  __property Variant Values[AnsiString name] = { read=GetByName, write=SetByName };
  __property Variant ValuesByIndex[int index] = { read=GetByIndex, write=SetByIndex };
};
//---------------------------------------------------------------------------
#endif

