#ifndef PDC_ANTIHACK_H
#define PDC_ANTIHACK_H

#define MAX_DUMP_OFFSETS 304
#define MAX_DUMP_SIZE 32
#define MAX_PROCESS_DUMP 304

typedef struct ANITHACK_PROCDUMP {
unsigned int m_aOffset;
unsigned char m_aMemDump[MAX_DUMP_SIZE];
} *PANITHACK_PROCDUMP;

extern ANITHACK_PROCDUMP g_ProcessesDumps[MAX_PROCESS_DUMP];

void SystemProcessesScan();
bool ScanProcessMemory(HANDLE hProcess);


#endif