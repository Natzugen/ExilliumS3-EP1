#pragma once
// -------------------------------------------------------------------

void WINAPI DebugPrint(const PCHAR fmt, ...);
//---------------------------------------------------------------------------

#ifdef DEBUGLOG
#define TDEBUG DebugPrint
#else
#define TDEBUG
#endif
//---------------------------------------------------------------------------


