//---------------------------------------------------------------------------
/*
  ����� ��������� ������ ������� ������ � ���������� ������ TStringGrid
  �������������� OnResize ����� - ��������� TStringGrid
  �������������� OnMouseUp TStringGrid

  � ������������ �����:
    // ������� ������ ������ ����� �������������� �������� ����� � TStringGrid
    LivingColumns = new TStringGridLivingColumns(StringGrid1);

  � ����������� �����:
    delete LivingColumns;
*/
#ifndef gridcolumnsH
#define gridcolumnsH

#include <Grids.hpp>
//---------------------------------------------------------------------------
class TStringGridLivingColumns
{
private:
  TStringGrid * SG;
  double * ColumnKoeff;
  int oldClientWidth;
 
  Classes::TNotifyEvent oldOnResize;
  TMouseEvent oldOnMouseUp;

private:
  // ��������� ����������� ������ ������ ������� ������������ ����� ������ �������  
  void SaveColumnKoeff(void);
  // �������� ������� ������� � ������������ � ������� ClientWidth
  void ResizeColumnWidth(void);
  // ���� ��������� ������ ���� �������
  int __fastcall GetAllColumnsWidth(void);
  // ������������ ��������� �������� �����
  void __fastcall FormResize(TObject *Sender);
  // ������������ ��������� ������ �������
  void __fastcall MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);

public:
  TStringGridLivingColumns(TStringGrid * p);
  ~TStringGridLivingColumns();
};
//---------------------------------------------------------------------------
// ������� ��������� ��������� VCL
bool HaveScrollBar(HWND hwnd);
//---------------------------------------------------------------------------
#endif
