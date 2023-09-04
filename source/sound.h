//---------------------------------------------------------------------------
#ifndef soundThreadH
#define soundThreadH

#define MAX_SOUND_FILE_COUNT 1
//---------------------------------------------------------------------------
class TSoundQueueItem
{
public:
  String File[MAX_SOUND_FILE_COUNT];   // �������� �����
  int Count;        // ������� ��� ������������� �����
  int Pause;        // ������� ������� ����� ����� �������������� (����.)
public:
  TSoundQueueItem(void);
  bool Add(String _File);
  bool HaveSound(void);
};
//---------------------------------------------------------------------------
// ������������ ������ ������� ������ �� ������������
#define TT_QUEUE_SIZE 20
// ��������� �����
class TSound : public TThread
{
// ������� ������ �� ������������  TSound
private:
  TSoundQueueItem Queue[TT_QUEUE_SIZE];
  int QueueSize;
  CRITICAL_SECTION busy;

protected:
  void __fastcall Execute();
  void __fastcall Wait(DWORD msec);

public:
  __fastcall TSound(bool CreateSuspended);
  __fastcall ~TSound(void);

public:
  bool AddToQueue(TSoundQueueItem * p);
  bool IsSilence(void);
  // ������� �� ������� ������������ 1 �������
  void DeleteFromQueue(void);

  void Stop(void);
  bool Play(AnsiString File, int Count=1);

private:
  bool __fastcall ReadBusy(void);
  bool __fastcall ReadAlmostFree(void);

__published:
  // ������������ ������ ?
  __property bool Busy = { read=ReadBusy };
  // ������������ �������� ��� ����� �������� (1 ���� 1 ������������) ?
  __property bool AlmostFree = { read=ReadAlmostFree };
};
//---------------------------------------------------------------------------
extern TSound * TalkingThread;
void MyPlaySound(AnsiString file);
//---------------------------------------------------------------------------
#endif

