#include<iostream>
#include<fstream>
#include<string>
#include "ComInterfaceX.h"
#pragma once

typedef HRESULT(*DLLGETCLASSOBJECTPROC)(long, long, void**);
typedef HRESULT(*DLLCANUNLOADNOWPROC)(void);

using namespace std;

HRESULT MyCoGetClassObject(long rclsid, long riid, void** ppv)
{
	/*
		Here the retrival of dll path from rclsid happens
	*/
	
	string line;
	ifstream f("MYREGISTERY.txt");

	getline(f, line);

	/*
	cout << line << endl;
	MessageBox(NULL, line.c_str(), TEXT("MSG"),MB_OK);

	f.close();
	*/
	string clsid = "";
	long index = 0;
	while (line[index] != '\"')
	{
		++index;
	}
	index++;
	while (line[index] != '\"')
	{
		clsid += line[index++];
	}
	long tempCLSID = atol(clsid.c_str());

	string path = "";
	index++;
	while (line[index] != '\"')
	{
		++index;
	}
	index++;
	while (line[index] != '\"')
	{
		path += line[index++];
	}
	if (tempCLSID == rclsid)
	{
		MessageBox(NULL, TEXT(path.c_str()), TEXT("MSG"), MB_OK);
	}

	//CoLoadLibrary("dll path");
	HINSTANCE hDll = LoadLibrary(path.c_str());
	
	DLLGETCLASSOBJECTPROC pDllGetClassObject = (DLLGETCLASSOBJECTPROC)GetProcAddress(hDll, TEXT("DllGetClassObject"));

	f.close();

	return (pDllGetClassObject(rclsid, riid, ppv));

}

HRESULT MyCoCreateInstance(long rclsid, IMyUnknown* pUnkOuter, long riid, void** ppv)
{
	 //code
	IMyClassFactory* pIClassFactory = NULL;
	MyCoGetClassObject(rclsid, IID_IMyClassFactory, (void**)&pIClassFactory);

	pIClassFactory->CreateInstance(pUnkOuter, riid, ppv);

	pIClassFactory->Release();

	return(S_OK);
}
