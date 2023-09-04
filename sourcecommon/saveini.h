/*
 � ���� ������ ������������ VCL ����� TSaveParamsINI
 �� ������ ��� ���������� � �������������� �������� � INI ����
 ��������� ������ TSaveParamsINI ����� ������� ������ ����������� (new)
 ����� ������� �.
*/
//---------------------------------------------------------------------------
#ifndef saveiniH
#define saveiniH

#include "savepar.h"
#include "inif.h"

//---------------------------------------------------------------------------
class TSaveParamsINI : public TSaveParams
{
private:
  TMYIniFile * f;
  void __fastcall SetFile(AnsiString inFile);

public:
  TSaveParamsINI(AnsiString inFile, bool inCreateNewFile=false);
  virtual __fastcall ~TSaveParamsINI();

  void virtual Set(AnsiString Section, AnsiString name, Variant value);
  Variant virtual Get(AnsiString Section, AnsiString name, Variant defval=Variant());

  bool SectionExists(const AnsiString Section);
  bool ValueExists(const AnsiString Section, const AnsiString name);

  bool virtual Load(AnsiString inFile);
  bool virtual Save(void);

__published:
  __property AnsiString File = {read=fFile, write=SetFile};
};
//---------------------------------------------------------------------------
#endif
