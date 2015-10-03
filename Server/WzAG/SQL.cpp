#include "Stdafx.h"


CSQLEx MySQL;

CSQLEx::CSQLEx()
{
}

CSQLEx::~CSQLEx()
{
    this->Disconnect();
}

void CSQLEx::Load()
{
	szDriver="{SQL Server}";
	GetPrivateProfileStringA("SQL","Host","127.0.0.1",szServer,sizeof(szServer),CUSTOM_PATH);
	GetPrivateProfileStringA("SQL","Host","127.0.0.1",szServer2,sizeof(szServer2),CUSTOM_PATH);
	GetPrivateProfileStringA("SQL","User","sa",szUser,sizeof(szUser),CUSTOM_PATH);
	GetPrivateProfileStringA("SQL","Password","12345",szPassword,sizeof(szPassword),CUSTOM_PATH);
	GetPrivateProfileStringA("SQL","Database","MuOnline",szDatabase,sizeof(szDatabase),CUSTOM_PATH);

	if(!this->Connect())
	{
		MessageBoxA(0,"Failed to connect - Check your Exillum.ini!","Error",MB_OK);
		::ExitProcess(0);
	} 
}

bool CSQLEx::Connect()
{
    if(this->m_bConnected == 1)
	{
        return false;
	}

    if(SQL_SUCCEEDED(SQLAllocHandle(SQL_HANDLE_ENV,SQL_NULL_HANDLE,&this->m_SQLEnvironment)) == 0)
    {
	    return false;
    }

    if(SQL_SUCCEEDED(SQLSetEnvAttr(this->m_SQLEnvironment,SQL_ATTR_ODBC_VERSION,(void *)SQL_OV_ODBC3,0)) == 0)
    {
        this->FreeHandle();	
        return false;
    }

    if(SQL_SUCCEEDED(SQLAllocHandle(SQL_HANDLE_DBC,this->m_SQLEnvironment,&this->m_SQLConnection)) == 0)
    {
        this->FreeHandle();	 
        return false;
    }

    SQLSetConnectOption(this->m_SQLConnection,SQL_LOGIN_TIMEOUT,5);	   
    SQLSetConnectOption(this->m_SQLConnection,SQL_CURSOR_TYPE,SQL_CURSOR_STATIC);

	SQLCHAR szConStrIn[1024],szConStrOut[1024];
    SQLSMALLINT iConOutSize = 0;

	sprintf((char*)szConStrIn,"DRIVER=%s; SERVER=%s; UID=%s; PWD=%s; DATABASE=%s;",szDriver,szServer2,szUser,szPassword,szDatabase);

    SQLRETURN Connect = SQLDriverConnect(this->m_SQLConnection,NULL,szConStrIn,SQL_NTS,szConStrOut,sizeof(szConStrOut),&iConOutSize,SQL_DRIVER_NOPROMPT);

    if(SQL_SUCCEEDED(Connect) == 0) 
    {
		this->FreeHandle();	 
        return false;
    }

    this->m_bConnected = 1;

    return true;
}

bool CSQLEx::ConnectExt()
{
    if(this->m_bConnected == 1)
		return false;

    if(SQL_SUCCEEDED(SQLAllocHandle(SQL_HANDLE_ENV,SQL_NULL_HANDLE,&this->m_SQLEnvironment)) == 0)
	    return false;

    if(SQL_SUCCEEDED(SQLSetEnvAttr(this->m_SQLEnvironment,SQL_ATTR_ODBC_VERSION,(void *)SQL_OV_ODBC3,0)) == 0)
    {
        this->FreeHandle();	 
        return false;
    }

    if(SQL_SUCCEEDED(SQLAllocHandle(SQL_HANDLE_DBC,this->m_SQLEnvironment,&this->m_SQLConnection)) == 0)
    {
        this->FreeHandle();	
        return false;
    }

    SQLSetConnectOption(this->m_SQLConnection,SQL_LOGIN_TIMEOUT,5);		   
    SQLSetConnectOption(this->m_SQLConnection,SQL_CURSOR_TYPE,SQL_CURSOR_STATIC);

	SQLCHAR szConStrIn[1024],szConStrOut[1024];
    SQLSMALLINT iConOutSize = 0;

	sprintf((char*)szConStrIn,"DRIVER=%s; SERVER=%s; UID=%s; PWD=%s; DATABASE=%s;",szDriver,szServer2,szUser,szPassword,szDatabase);

    SQLRETURN Connect = SQLDriverConnect(this->m_SQLConnection,NULL,szConStrIn,SQL_NTS,szConStrOut,sizeof(szConStrOut),&iConOutSize,SQL_DRIVER_NOPROMPT);

    if(SQL_SUCCEEDED(Connect) == 0) 
    {
		this->FreeHandle();	   
        return false;
    }

    this->m_bConnected = 1;

    return true;
}

void CSQLEx::Disconnect()
{
    if(this->m_bConnected == 1)
    {
        SQLDisconnect(this->m_SQLConnection); 
		this->FreeHandle();
    }

    this->m_SQLConnection = NULL;
    this->m_SQLEnvironment = NULL;

    this->m_bConnected = 0;
}

void CSQLEx::FreeHandle()
{
    if(this->m_SQLConnection != NULL)
	    SQLFreeHandle(SQL_HANDLE_DBC,this->m_SQLConnection);
	
	if(this->m_SQLEnvironment != NULL)
	    SQLFreeHandle(SQL_HANDLE_ENV,this->m_SQLEnvironment);
}

bool CSQLEx::Execute(char* szQuery,...)
{
	if(this->m_bConnected == 0)
	{
        return false;
	}

    if(SQL_SUCCEEDED(SQLAllocHandle(SQL_HANDLE_STMT,this->m_SQLConnection,&this->m_STMT)) == 0)
    {
	    return false;
	}

	char szTemp[1024];

	va_list pArguments;

	va_start(pArguments,szQuery);
	vsprintf(szTemp,szQuery,pArguments);
	va_end(pArguments);

    if(SQL_SUCCEEDED(SQLPrepare(this->m_STMT,(unsigned char*)szTemp,strlen(szTemp))) == 0)
    {
	    return false;
	}
			
	SQLRETURN Execute = SQLExecute(this->m_STMT);

    if(Execute == SQL_SUCCESS || Execute == SQL_SUCCESS_WITH_INFO || Execute == SQL_NO_DATA)
    {
	    if(SQLRowCount(this->m_STMT,&this->m_RowCount) != SQL_SUCCESS)
		{
		    this->m_RowCount = 0;
		}

		if(SQLNumResultCols(this->m_STMT,(SQLSMALLINT*)&this->m_ColCount) != SQL_SUCCESS)
		{
		    this->m_ColCount = 0;
		}

		return true;
	}

	return false;
}


char* CSQLEx::GetLastError()
{
	char szError[1024];

    SQLCHAR     szState[20];
	SQLINTEGER  iNativeError;
	SQLSMALLINT iOutErrorSize;

	SQLError(this->m_SQLEnvironment,this->m_SQLConnection,this->m_STMT,szState,&iNativeError,(SQLCHAR*)szError,sizeof(szError),&iOutErrorSize);

    return &szError[0];
}

int CSQLEx::GetRow()
{
    return this->m_RowCount;
}

int CSQLEx::GetCol()
{
	return this->m_ColCount;
}

int CSQLEx::GetInt()
{
    long lSize,lResult=0;

    while(true)
	{
	    if(SQL_SUCCEEDED(SQLFetch(this->m_STMT)) == 0)
		    break;
		
		if(SQL_SUCCEEDED(SQLGetData(this->m_STMT,1,SQL_C_LONG,&lResult,sizeof(long),&lSize)) == 0)
		    break;
		
		return lResult;
	}

	return 0;
}

void CSQLEx::GetString(char *msg)
{
    long lSize;
	char lResult[1024];

	while(true)
	{
		if(SQL_SUCCEEDED(SQLFetch(this->m_STMT)) == 0)
			break;

		if(SQL_SUCCEEDED(SQLGetData(this->m_STMT, 1, SQL_C_CHAR, &lResult,sizeof(lResult),&lSize)) == 0)
		{
			break;
		}
		else
		{
			memcpy(msg,lResult,lSize);
			msg[lSize] = '\0';
		}
	}
}

bool CSQLEx::FetchRow(char* out,int len)
{
	long lSize;

    while(true)
	{
		if(SQL_SUCCEEDED(SQLFetch(this->m_STMT)) == 0)
			break;

		for(int n=0;n < this->m_ColCount;n++)
		    if(SQL_SUCCEEDED(SQLGetData(this->m_STMT,(n+1),SQL_C_CHAR,&out[n],len,&lSize)) == 0)
			    break;
		
		return 1;
	}

	return 0;
}