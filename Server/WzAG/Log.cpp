#include "StdAfx.h"

// Log System
CLog Log;

void CLog::Error(const char* format,...)
{
	va_list argv;
	va_start(argv,format);
	vsprintf(this->tmp,format,argv);
	va_end(argv);
	sprintf(this->out,"%s",tmp);
	LogColor = 2;
	this->LogTime();
}

void CLog::AddTime(const char* format,...)
{
	va_list argv;
	tm * today;
	time_t ltime;
	char tmpbuf[512];
	time(&ltime);
	today=localtime(&ltime);
	wsprintf(tmpbuf,"%.8s",asctime(today)+11);
	va_start(argv,format);
	vsprintf(this->tmp,format,argv);
	memcpy(this->out,tmp,strlen(tmp));
	va_end(argv);
	strcat(tmpbuf,this->tmp);
	LogColor = 1;
	this->LogTime();
}

void CLog::Add(const char* format,...)
{
	va_list argv;
	va_start(argv,format);
	vsprintf(this->tmp,format,argv);
	memcpy(this->out,tmp,strlen(tmp));
	va_end(argv);
	LogColor = 5;
	this->Log();
}

void CLog::Attention(const char* format,...)
{
	va_list argv;
	va_start(argv,format);
	vsprintf(this->tmp,format,argv);
	va_end(argv);
	sprintf(this->out,"%s",tmp);
	LogColor = 5;
	this->LogTime();
}

void CLog::Log()
{
	char tofile[2048] = {0};
	sprintf(tofile,"%s",this->out);
	LogAddFuncColor(this->LogColor,tofile);
	ZeroMemory(&tofile,sizeof(tofile));
	ZeroMemory(&tmp,sizeof(tmp));
	ZeroMemory(&out,sizeof(out));
}

void CLog::LogTime()
{
	SYSTEMTIME t;
	GetLocalTime(&t);
	char currdate[11] = {0};
	sprintf(currdate,"%02d:%02d:%02d",t.wHour,t.wMinute,t.wSecond);
	char tofile[2048] = {0};
	sprintf(tofile,"%s %s",currdate,this->out);
	LogAddFuncColor(this->LogColor,tofile);
	ZeroMemory(&tofile,sizeof(tofile));
	ZeroMemory(&tmp,sizeof(tmp));
	ZeroMemory(&out,sizeof(out));
}