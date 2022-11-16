#pragma once
#include "ComInterfaceX.h"

class ISum:public IMyUnknown
{
public: 
	virtual HRESULT __stdcall SumOfTwoIntigers(int, int, int *)=0; // = 0 means tyaalaa code ach nahi ahe aani haa rajeshpradhaan ahe jyaalaa implement karnaara konhitari pahije ahe 
};

class ISubtract:public IMyUnknown
{
public:
	virtual HRESULT __stdcall SubOfTwoIntigers(int, int, int *)=0; // aani haa avinaash vidhaate ahe jyaalahi implement karnaara konhi tari pahije ahe for eg:patil or kulkarni wagaire
};


const long CLSID_CSumSubtract = 3131;

const long IID_ISum = 3132;

const long IID_ISubtract = 3133;
