//---------------------------------------------------------------------------
#ifndef unilistH
#define unilistH

/*
  ������ TUniList: ������ ���������� �� �������
  ��������, �������� � ����������� �������� ���� T �� ����������� !
  �������� ��� ����������� ����� ��������: Add() / ExtractLast()
  ��� ������� ��������: Add() / Extract(0)

  ���� ����������� ��������� ����������� ���������� ��� ���� �������,
  ����� ItemsNB[], CountNB
  ��� ��������� ����������� ���������� ���� ������� EnableMultiTreading()
  ���� ��� ����� �������� �������.

  ������� �������������:
  1) ��� ����������:
    class c { int i; };
    TUniList<c> cl; // ������ ���������� �� c

    cl.Add( new c() );

    c * p = cl.ExtractLast();
    if( ! p )
      ; // ������ cl ����
    else
      // p - �������� ��������� �� ��������� ������ � ������,
      // ������ ���������� �� 1
      delete p;

    // ������� ��� ������� � ������
    for(int i=0, l=cl.Count; i<l; i++)
      delete (c *)cl.Items[i];
    cl.Clear(); // ������� ������

  2) ������������ ����������� ����������:
    class c { int i; };
    TUniList<c> cl; // ������ ���������� �� c
    cl.EnableMultiTreading();

    // Add() � Extract() ����� �������� �� ������ �������
    cl.Add( new c() );

    c * p = cl.Extract(0);
    if( ! p )
      ; // ������ cl ����
    else
      // p - �������� ��������� �� ������� 0, � ������ ���������� �� 1
      delete p;

    // ������ ������� �� ������ �������� � ����������� �����������
    // ������� ��� ������� � ������
    cl.SetBusy(true);
    try
    {
      for(int i=0, l=cl.CountNB; i<l; i++)
        delete (c *)cl.ItemsNB[i];
      cl.Clear(); // ������� ������
    }
    __finally
    { cl.SetBusy(false); }

  �����: ������� �.
  ������ 2

  ��������: unilist.cpp �������� � ������ ������ !
  #include "unilist.h" // � ���
*/

#include <vcl.h>

#include "critsection.h"

//---------------------------------------------------------------------------
template <class T>
class TUniList
{
private:
  TList * l;           // vcl TList
  TCritSection * pcs;  // Critical section for multi-thread access

public:
  TUniList(void);
  ~TUniList(void);

  // Start muti-thread syncronization in all methods except ItemsNB[], CountNB
  void EnableMultiTreading(void);

  // ������� ������
  // �������� �������� �� �����������
  void Clear(void);
  // ��������� ��������� p � ����� ������.
  // ����������� ������� �� ������������.
  // ���������� ������ ������ ��������� � ������ (� ����)
  int Add(T * p);
  // ��������� ��������� p � ������� i (� ����) ������.
  // ����������� ������� �� ������������.
  void Insert(int i, T * p);
  // ������� ��������� p �� ������
  void Delete(T * p);
  // ������� ��������� � �������� i �� ������
  // ���������� ��������� �� ��������� ������ ��� NULL
  T * Extract(int i);
  // ��-�� ��� ���������� �������� ������
  T * ExtractLast(void);
  // ��������� ������� ��������� p � ������
  bool Contains(T * p);
  // ������ � ��������� ������� �� ��� �������
  __property T * Items[int i] = {read=Get, write=Set};
  // ���������� �������� � ������
  __property int Count = {read=GetCount};

  // ��-��, ��� Items[], �� ��� ����������
  __property T * ItemsNB[int i] = {read=GetNB, write=SetNB};
  // ��-��, ��� Count, �� ��� ����������
  __property int CountNB = {read=GetCountNB};
  // ���������/���������� ����������
  bool SetBusy(bool b);

private:
  T * Get(int i);
  void Set(int i, T * p);
  int GetCount(void);

  T * GetNB(int i);
  void SetNB(int i, T * p);
  int GetCountNB(void);
};
//---------------------------------------------------------------------------

#include "unilist.cpp"

#endif
