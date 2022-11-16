#pragma once
#include"MyCom.h"

class ISum:public IMyUnknown
{
public: 
	virtual HRESULT __stdcall SumOfTwoIntigers(int, int, int *)=0; 
};

class ISubtract:public IMyUnknown
{
public:
	virtual HRESULT __stdcall SubOfTwoIntigers(int, int, int *)=0; 
};


const long CLSID_CSumSubtract = 3131;

const long IID_ISum = 3132;

const long IID_ISubtract = 3133;
