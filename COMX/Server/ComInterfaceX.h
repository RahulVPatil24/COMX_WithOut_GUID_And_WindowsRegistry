#pragma once
class IMyUnknown
{
public:
	virtual HRESULT __stdcall QueryInterface(long riid, void** ppv) = 0;
	virtual ULONG __stdcall AddRef(void) = 0;
	virtual ULONG __stdcall Release(void) = 0;
};

class IMyClassFactory : public IMyUnknown
{
public:
	virtual HRESULT __stdcall CreateInstance(IMyUnknown*, long, void**) = 0;
	virtual HRESULT __stdcall LockServer(BOOL) = 0;
};

const long IID_IMyUnknown = 1000;
const long IID_IMyClassFactory = 2000;
