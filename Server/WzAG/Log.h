#ifndef __LOG_H__
#define __LOG_H__

// Log System
class CLog
{
public:

	void Error(const char* format,...);
	void AddTime(const char* format,...);
	void Add(const char* format,...);
	void Attention(const char* format,...);

private:

	void Log();
	void LogTime();
	char out[2048];
	char tmp[2048];
	int LogColor;
};

extern CLog Log;

#endif