#ifndef _SQL_H
#define _SQL_H

class CSQLEx
{
public:
    CSQLEx();
	virtual ~CSQLEx();

	void Load();
	bool ConnectExt();
	bool Connect();
	void Disconnect();
	bool Execute(char* szQuery,...);
	char* GetLastError();
	void FreeHandle();
	int GetRow();
	int GetCol();

	int GetInt();
	void GetString(char* msg);
	bool FetchRow(char* out,int len);
	char FetchArray[1024][50];
	char*szDriver;
	char szServer[50];
	char szServer2[50];
	char szUser[50];
	char szPassword[50];
	char szDatabase[50];
private:
	bool m_bConnected;
	HENV m_SQLEnvironment;
	HDBC m_SQLConnection;
	HSTMT m_STMT;
	long m_RowCount;
	long m_ColCount;
};

extern CSQLEx MySQL;

#endif