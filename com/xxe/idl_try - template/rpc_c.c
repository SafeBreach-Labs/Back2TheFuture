

/* this ALWAYS GENERATED file contains the RPC client stubs */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 05:14:07 2038
 */
/* Compiler settings for rpc.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_)


#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#include <string.h>

#include "rpc_h.h"

#define TYPE_FORMAT_STRING_SIZE   6203                              
#define PROC_FORMAT_STRING_SIZE   6291                              
#define EXPR_FORMAT_STRING_SIZE   17                                
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _rpc_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } rpc_MIDL_TYPE_FORMAT_STRING;

typedef struct _rpc_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } rpc_MIDL_PROC_FORMAT_STRING;

typedef struct _rpc_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } rpc_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const rpc_MIDL_TYPE_FORMAT_STRING rpc__MIDL_TypeFormatString;
extern const rpc_MIDL_PROC_FORMAT_STRING rpc__MIDL_ProcFormatString;
extern const rpc_MIDL_EXPR_FORMAT_STRING rpc__MIDL_ExprFormatString;

#define GENERIC_BINDING_TABLE_SIZE   0            


/* Standard interface: DefaultIfName, ver. 1.0,
   GUID={0x12345778,0x1234,0xabcd,{0xef,0x00,0x01,0x23,0x45,0x67,0x89,0xab}} */



static const RPC_CLIENT_INTERFACE DefaultIfName___RpcClientInterface =
    {
    sizeof(RPC_CLIENT_INTERFACE),
    {{0x12345778,0x1234,0xabcd,{0xef,0x00,0x01,0x23,0x45,0x67,0x89,0xab}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    0,
    0,
    0,
    0,
    0,
    0x00000000
    };
RPC_IF_HANDLE DefaultIfName_v1_0_c_ifspec = (RPC_IF_HANDLE)& DefaultIfName___RpcClientInterface;

extern const MIDL_STUB_DESC DefaultIfName_StubDesc;

static RPC_BINDING_HANDLE DefaultIfName__MIDL_AutoBindHandle;


long Proc0_LsarClose( 
    /* [context_handle][out][in] */ void **arg_0)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[0],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc1_CredrRename( 
    /* [context_handle][in] */ void *arg_0)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[42],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc2_LsarEnumeratePrivileges( 
    /* [context_handle][in] */ void *arg_0,
    /* [out][in] */ long *arg_1,
    /* [out] */ struct Struct_110_t *arg_2,
    /* [in] */ long arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[84],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc3_LsarQuerySecurityObject( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ long arg_1,
    /* [ref][out] */ struct Struct_160_t **arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[144],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc4_LsarSetSecurityObject( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ long arg_1,
    /* [in] */ struct Struct_160_t *arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[198],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc5_LsaITestCall( 
    /* [in] */ handle_t IDL_handle,
    /* [in] */ struct Struct_44_t *arg_0,
    /* [in] */ struct Struct_44_t *arg_1,
    /* [in] */ struct Struct_44_t *arg_2,
    /* [in] */ struct Struct_44_t *arg_3,
    /* [in] */ struct Struct_44_t *arg_4)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[252],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc6_LsarOpenPolicyRPC( 
    /* [unique][in] */ wchar_t *arg_0,
    /* [in] */ struct Struct_364_t *arg_1,
    /* [in] */ long arg_2,
    /* [context_handle][out] */ void **arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[316],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc7_LsarQueryInformationPolicy( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ short arg_1,
    /* [switch_is][ref][out] */ union union_428 **arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[370],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc8_LsarSetInformationPolicy( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ short arg_1,
    /* [switch_is][in] */ union union_428 *arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[424],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc9_LsaITestCall( 
    /* [context_handle][in] */ void *arg_0)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[478],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc10_LsarCreateAccount( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_280_t *arg_1,
    /* [in] */ long arg_2,
    /* [context_handle][out] */ void **arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[520],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc11_LsarEnumerateAccounts( 
    /* [context_handle][in] */ void *arg_0,
    /* [out][in] */ long *arg_1,
    /* [out] */ struct Struct_864_t *arg_2,
    /* [in] */ long arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[580],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc12_LsarCreateTrustedDomain( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_888_t *arg_1,
    /* [in] */ long arg_2,
    /* [context_handle][out] */ void **arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[640],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc13_LsarEnumerateTrustedDomains( 
    /* [context_handle][in] */ void *arg_0,
    /* [out][in] */ long *arg_1,
    /* [out] */ struct Struct_948_t *arg_2,
    /* [in] */ long arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[700],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc14_LsarLookupNames( 
    /* [context_handle][in] */ void *arg_0,
    /* [range][in] */ long arg_1,
    /* [size_is][in] */ struct Struct_44_t *arg_2,
    /* [ref][out] */ struct Struct_1034_t **arg_3,
    /* [out][in] */ struct Struct_1100_t *arg_4,
    /* [in] */ short arg_5,
    /* [out][in] */ long *arg_6)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[760],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc15_LsarLookupSids( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_1178_t *arg_1,
    /* [ref][out] */ struct Struct_1034_t **arg_2,
    /* [out][in] */ struct Struct_1260_t *arg_3,
    /* [in] */ short arg_4,
    /* [out][in] */ long *arg_5)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[838],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc16_LsarCreateSecret( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_44_t *arg_1,
    /* [in] */ long arg_2,
    /* [context_handle][out] */ void **arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[910],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc17_LsarOpenAccount( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_280_t *arg_1,
    /* [in] */ long arg_2,
    /* [context_handle][out] */ void **arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[970],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc18_LsarEnumeratePrivilegesAccount( 
    /* [context_handle][in] */ void *arg_0,
    /* [ref][out] */ struct Struct_1372_t **arg_1)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[1030],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc19_LsarAddPrivilegesToAccount( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_1372_t *arg_1)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[1078],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc20_LsarRemovePrivilegesFromAccount( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ unsigned char arg_1,
    /* [unique][in] */ struct Struct_1372_t *arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[1126],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc21_LsarGetQuotasForAccount( 
    /* [context_handle][in] */ void *arg_0,
    /* [out] */ struct Struct_670_t *arg_1)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[1180],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc22_LsaAllocateSharedMemory( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_670_t *arg_1)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[1228],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc23_LsarGetSystemAccessAccount( 
    /* [context_handle][in] */ void *arg_0,
    /* [out] */ long *arg_1)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[1276],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc24_LsarSetSystemAccessAccount( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ long arg_1)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[1324],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc25_LsarOpenTrustedDomain( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_280_t *arg_1,
    /* [in] */ long arg_2,
    /* [context_handle][out] */ void **arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[1372],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc26_LsarQueryInfoTrustedDomain( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ short arg_1,
    /* [switch_is][ref][out] */ union union_1468 **arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[1432],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc27_LsarSetInformationTrustedDomain( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ short arg_1,
    /* [switch_is][in] */ union union_1468 *arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[1486],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc28_LsarOpenSecret( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_44_t *arg_1,
    /* [in] */ long arg_2,
    /* [context_handle][out] */ void **arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[1540],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc29_LsarSetSecret( 
    /* [context_handle][in] */ void *arg_0,
    /* [unique][in] */ struct Struct_1662_t *arg_1,
    /* [unique][in] */ struct Struct_1662_t *arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[1600],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc30_LsarQuerySecret( 
    /* [context_handle][in] */ void *arg_0,
    /* [unique][out][in] */ struct Struct_1662_t **arg_1,
    /* [unique][out][in] */ struct Struct_518_t *arg_2,
    /* [unique][out][in] */ struct Struct_1662_t **arg_3,
    /* [unique][out][in] */ struct Struct_518_t *arg_4)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[1654],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc31_LsarLookupPrivilegeValue( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_44_t *arg_1,
    /* [out] */ struct Struct_62_t *arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[1720],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc32_LsarLookupPrivilegeName( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_62_t *arg_1,
    /* [ref][out] */ struct Struct_44_t **arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[1774],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc33_LsarLookupPrivilegeDisplayName( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_44_t *arg_1,
    /* [in] */ short arg_2,
    /* [in] */ short arg_3,
    /* [ref][out] */ struct Struct_44_t **arg_4,
    /* [out] */ short *arg_5)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[1828],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc34_LsarDeleteObject( 
    /* [context_handle][out][in] */ void **arg_0)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[1900],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc35_LsarEnumerateAccountsWithUserRight( 
    /* [context_handle][in] */ void *arg_0,
    /* [unique][in] */ struct Struct_44_t *arg_1,
    /* [out] */ struct Struct_864_t *arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[1942],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc36_LsarEnumerateAccountRights( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_280_t *arg_1,
    /* [out] */ struct Struct_2194_t *arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[1996],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc37_LsarAddAccountRights( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_280_t *arg_1,
    /* [in] */ struct Struct_2194_t *arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[2050],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc38_LsarRemoveAccountRights( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_280_t *arg_1,
    /* [in] */ unsigned char arg_2,
    /* [in] */ struct Struct_2194_t *arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[2104],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc39_LsarQueryTrustedDomainInfo( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_280_t *arg_1,
    /* [in] */ short arg_2,
    /* [switch_is][ref][out] */ union union_1468 **arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[2164],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc40_LsarSetTrustedDomainInfo( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_280_t *arg_1,
    /* [in] */ short arg_2,
    /* [switch_is][in] */ union union_1468 *arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[2224],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc41_LsarDeleteTrustedDomain( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_280_t *arg_1)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[2284],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc42_LsarStorePrivateData( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_44_t *arg_1,
    /* [unique][in] */ struct Struct_1662_t *arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[2332],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc43_LsarRetrievePrivateData( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_44_t *arg_1,
    /* [ref][out][in] */ struct Struct_1662_t **arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[2386],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc44_LsarOpenPolicy2( 
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [in] */ struct Struct_364_t *arg_1,
    /* [in] */ long arg_2,
    /* [context_handle][out] */ void **arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[2440],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc45_LsarGetUserName( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [ref][out][in] */ struct Struct_44_t **arg_1,
    /* [unique][out][in] */ struct Struct_44_t **arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[2494],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc46_LsarQueryInformationPolicy2( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ short arg_1,
    /* [switch_is][ref][out] */ union union_428 **arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[2546],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc47_LsarSetInformationPolicy2( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ short arg_1,
    /* [switch_is][in] */ union union_428 *arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[2600],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc48_LsarQueryTrustedDomainInfoByName( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_44_t *arg_1,
    /* [in] */ short arg_2,
    /* [switch_is][ref][out] */ union union_1468 **arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[2654],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc49_LsarSetTrustedDomainInfoByName( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_44_t *arg_1,
    /* [in] */ short arg_2,
    /* [switch_is][in] */ union union_1468 *arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[2714],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc50_LsarEnumerateTrustedDomainsEx( 
    /* [context_handle][in] */ void *arg_0,
    /* [out][in] */ long *arg_1,
    /* [out] */ struct Struct_2480_t *arg_2,
    /* [in] */ long arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[2774],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc51_LsarCreateTrustedDomainEx( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_1704_t *arg_1,
    /* [in] */ struct Struct_1796_t *arg_2,
    /* [in] */ long arg_3,
    /* [context_handle][out] */ void **arg_4)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[2834],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc52_LsaITestCall( 
    /* [context_handle][out][in] */ void **arg_0)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[2900],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc53_LsarQueryDomainInformationPolicy( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ short arg_1,
    /* [switch_is][ref][out] */ union union_2546 **arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[2942],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc54_LsarSetDomainInformationPolicy( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ short arg_1,
    /* [switch_is][unique][in] */ union union_2546 *arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[2996],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc55_LsarOpenTrustedDomainByName( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_44_t *arg_1,
    /* [in] */ long arg_2,
    /* [context_handle][out] */ void **arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[3050],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc56_LsaITestCall( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ short arg_1,
    /* [in] */ struct Struct_2740_t *arg_2,
    /* [ref][out] */ struct Struct_2740_t **arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[3110],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc57_LsarLookupSids2( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_1178_t *arg_1,
    /* [ref][out] */ struct Struct_1034_t **arg_2,
    /* [out][in] */ struct Struct_2838_t *arg_3,
    /* [in] */ short arg_4,
    /* [out][in] */ long *arg_5,
    /* [in] */ long arg_6,
    /* [in] */ long arg_7)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[3170],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc58_LsarLookupNames2( 
    /* [context_handle][in] */ void *arg_0,
    /* [range][in] */ long arg_1,
    /* [size_is][in] */ struct Struct_44_t *arg_2,
    /* [ref][out] */ struct Struct_1034_t **arg_3,
    /* [out][in] */ struct Struct_2960_t *arg_4,
    /* [in] */ short arg_5,
    /* [out][in] */ long *arg_6,
    /* [in] */ long arg_7,
    /* [in] */ long arg_8)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[3254],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc59_LsarCreateTrustedDomainEx2( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_1704_t *arg_1,
    /* [in] */ struct Struct_1900_t *arg_2,
    /* [in] */ long arg_3,
    /* [context_handle][out] */ void **arg_4)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[3344],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc60_CredrWrite( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [ref][in] */ struct Struct_3208_t *arg_1,
    /* [in] */ long arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[3410],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc61_CredrRead( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [size_is][string][in] */ wchar_t *arg_1,
    /* [in] */ long arg_2,
    /* [in] */ long arg_3,
    /* [ref][out] */ struct Struct_3208_t **arg_4)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[3462],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc62_CredrEnumerate( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [size_is][string][unique][in] */ wchar_t *arg_1,
    /* [in] */ long arg_2,
    /* [out] */ struct Struct_3290_t *arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[3526],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc63_CredrWriteDomainCredentials( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [ref][in] */ struct Struct_3392_t *arg_1,
    /* [ref][in] */ struct Struct_3208_t *arg_2,
    /* [in] */ long arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[3584],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc64_CredrReadDomainCredentials( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [ref][in] */ struct Struct_3392_t *arg_1,
    /* [in] */ long arg_2,
    /* [out] */ struct Struct_3290_t *arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[3642],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc65_CredrDelete( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [size_is][string][in] */ wchar_t *arg_1,
    /* [in] */ long arg_2,
    /* [in] */ long arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[3700],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc66_CredrGetTargetInfo( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [size_is][string][in] */ wchar_t *arg_1,
    /* [in] */ long arg_2,
    /* [ref][out] */ struct Struct_3392_t **arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[3758],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc67_CredrProfileLoaded( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[3816],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc68_LsarLookupNames3( 
    /* [context_handle][in] */ void *arg_0,
    /* [range][in] */ long arg_1,
    /* [size_is][in] */ struct Struct_44_t *arg_2,
    /* [ref][out] */ struct Struct_1034_t **arg_3,
    /* [out][in] */ struct Struct_3608_t *arg_4,
    /* [in] */ short arg_5,
    /* [out][in] */ long *arg_6,
    /* [in] */ long arg_7,
    /* [in] */ long arg_8)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[3856],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc69_CredrGetSessionTypes( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [range][in] */ long arg_1,
    /* [size_is][out] */ long *arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[3946],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc70_LsarRegisterAuditEvent( 
    /* [in] */ struct Struct_3696_t *arg_0,
    /* [context_handle][out] */ void **arg_1)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[3998],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc71_LsarGenAuditEvent( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ long arg_1,
    /* [in] */ struct Struct_3980_t *arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[4040],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc72_LsarUnregisterAuditEvent( 
    /* [context_handle][out][in] */ void **arg_0)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[4094],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc73_LsarQueryForestTrustInformation( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_4032_t *arg_1,
    /* [in] */ short arg_2,
    /* [ref][out] */ struct Struct_4208_t **arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[4136],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc74_LsarSetForestTrustInformation( 
    /* [context_handle][in] */ void *arg_0,
    /* [in] */ struct Struct_4032_t *arg_1,
    /* [in] */ short arg_2,
    /* [in] */ struct Struct_4208_t *arg_3,
    /* [in] */ unsigned char arg_4,
    /* [ref][out] */ struct Struct_4288_t **arg_5)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[4196],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc75_CredrRename( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [size_is][string][in] */ wchar_t *arg_1,
    /* [size_is][string][in] */ wchar_t *arg_2,
    /* [in] */ long arg_3,
    /* [in] */ long arg_4)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[4268],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc76_LsarLookupSids3( 
    /* [in] */ handle_t IDL_handle,
    /* [in] */ struct Struct_1178_t *arg_1,
    /* [ref][out] */ struct Struct_1034_t **arg_2,
    /* [out][in] */ struct Struct_2838_t *arg_3,
    /* [in] */ short arg_4,
    /* [out][in] */ long *arg_5,
    /* [in] */ long arg_6,
    /* [in] */ long arg_7)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[4332],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc77_LsarLookupNames4( 
    /* [in] */ handle_t IDL_handle,
    /* [range][in] */ long arg_1,
    /* [size_is][in] */ struct Struct_44_t *arg_2,
    /* [ref][out] */ struct Struct_1034_t **arg_3,
    /* [out][in] */ struct Struct_3608_t *arg_4,
    /* [in] */ short arg_5,
    /* [out][in] */ long *arg_6,
    /* [in] */ long arg_7,
    /* [in] */ long arg_8)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[4408],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc78_LsarOpenPolicySce( 
    /* [unique][in] */ wchar_t *arg_0,
    /* [in] */ struct Struct_364_t *arg_1,
    /* [in] */ long arg_2,
    /* [context_handle][out] */ void **arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[4490],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc79_LsarAdtRegisterSecurityEventSource( 
    /* [in] */ long arg_0,
    /* [string][unique][in] */ wchar_t *arg_1,
    /* [context_handle][out] */ void **arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[4544],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc80_LsarAdtUnregisterSecurityEventSource( 
    /* [in] */ long arg_0,
    /* [context_handle][out][in] */ void **arg_1)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[4592],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc81_LsarAdtReportSecurityEvent( 
    /* [in] */ long arg_0,
    /* [context_handle][in] */ void *arg_1,
    /* [in] */ long arg_2,
    /* [in] */ struct Struct_3820_t *arg_3,
    /* [in] */ struct Struct_3980_t *arg_4)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[4640],
                  ( unsigned char * )&arg_0);
    return ( long  )_RetVal.Simple;
    
}


long Proc82_CredrFindBestCredential( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [size_is][string][in] */ wchar_t *arg_1,
    /* [in] */ long arg_2,
    /* [in] */ long arg_3,
    /* [ref][out] */ struct Struct_3208_t **arg_4)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[4706],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc83_LsarSetAuditPolicy( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [unique][in] */ struct Struct_280_t *arg_1,
    /* [unique][in] */ struct Struct_736_t *arg_2,
    /* [range][in] */ long arg_3,
    /* [size_is][in] */ struct Struct_4502_t *arg_4)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[4770],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc84_LsarQueryAuditPolicy( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [unique][in] */ struct Struct_280_t *arg_1,
    /* [unique][in] */ struct Struct_736_t *arg_2,
    /* [range][in] */ long arg_3,
    /* [size_is][in] */ struct Struct_736_t *arg_4,
    /* [size_is][ref][out] */ struct Struct_4502_t **arg_5)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[4834],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc85_LsarEnumerateAuditPolicy( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [ref][out] */ struct Struct_4676_t **arg_1)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[4904],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc86_LsarEnumerateAuditCategories( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [ref][out] */ struct Struct_4726_t **arg_1)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[4950],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc87_LsarEnumerateAuditSubCategories( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [unique][in] */ struct Struct_736_t *arg_1,
    /* [in] */ unsigned char arg_2,
    /* [ref][out] */ struct Struct_4780_t **arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[4996],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc88_LsarLookupAuditCategoryName( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [in] */ struct Struct_736_t *arg_1,
    /* [ref][out] */ struct Struct_44_t **arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[5054],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc89_LsarLookupAuditSubCategoryName( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [in] */ struct Struct_736_t *arg_1,
    /* [ref][out] */ struct Struct_44_t **arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[5106],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc90_LsarSetAuditSecurity( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [in] */ long arg_1,
    /* [in] */ struct Struct_160_t *arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[5158],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc91_LsarQueryAuditSecurity( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [in] */ long arg_1,
    /* [ref][out] */ struct Struct_160_t **arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[5210],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc92_CredrReadByTokenHandle( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [in] */ unsigned __int3264 arg_1,
    /* [in] */ long arg_2,
    /* [size_is][string][in] */ wchar_t *arg_3,
    /* [in] */ long arg_4,
    /* [in] */ long arg_5,
    /* [ref][out] */ struct Struct_3208_t **arg_6)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[5262],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc93_CredrRestoreCredentials( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [size_is][string][unique][in] */ wchar_t *arg_1,
    /* [size_is][unique][in] */ unsigned char *arg_2,
    /* [range][in] */ long arg_3,
    /* [in] */ long arg_4)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[5338],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc94_CredrBackupCredentials( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [in] */ unsigned __int3264 arg_1,
    /* [in] */ long arg_2,
    /* [size_is][string][unique][in] */ wchar_t *arg_3,
    /* [size_is][unique][in] */ unsigned char *arg_4,
    /* [range][in] */ long arg_5,
    /* [in] */ long arg_6)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[5402],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc95_LsarManageSidNameMapping( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [in] */ short arg_1,
    /* [switch_is][in] */ union union_4974 *arg_2,
    /* [switch_is][ref][out] */ union union_5110 **arg_3)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[5478],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc96_CredrProfileUnloaded( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[5536],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc97_CredrRename( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [size_is][string][in] */ wchar_t *arg_1,
    /* [size_is][unique][in] */ unsigned char *arg_2,
    /* [in] */ long arg_3,
    /* [size_is][string][unique][in] */ wchar_t *arg_4,
    /* [size_is][string][unique][in] */ wchar_t *arg_5,
    /* [in] */ long arg_6)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[5576],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc98_CredrRename( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [size_is][string][in] */ wchar_t *arg_1,
    /* [in] */ long arg_2,
    /* [size_is][string][unique][in] */ wchar_t *arg_3,
    /* [size_is][string][unique][in] */ wchar_t *arg_4,
    /* [size_is][string][unique][in] */ wchar_t *arg_5,
    /* [size_is][string][unique][in] */ wchar_t *arg_6)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[5652],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc99_CredrRename( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [size_is][string][unique][in] */ wchar_t *arg_1,
    /* [size_is][string][in] */ wchar_t *arg_2,
    /* [in] */ long arg_3,
    /* [size_is][unique][in] */ unsigned char *arg_4,
    /* [in] */ long arg_5,
    /* [size_is][string][unique][in] */ wchar_t *arg_6,
    /* [in] */ long arg_7,
    /* [in] */ long arg_8)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[5728],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc100_CredrRename( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [size_is][string][in] */ wchar_t *arg_1,
    /* [in] */ long arg_2,
    /* [size_is][string][unique][in] */ wchar_t *arg_3,
    /* [size_is][string][unique][in] */ wchar_t *arg_4,
    /* [size_is][string][unique][in] */ wchar_t *arg_5)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[5816],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc101_CredrRename( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [size_is][string][in] */ wchar_t *arg_1,
    /* [out] */ long *arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[5886],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc102_LsarEfsGetSmartcardCredentials( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [in] */ struct Struct_62_t *arg_1,
    /* [size_is][size_is][ref][out] */ unsigned char **arg_2,
    /* [out] */ long *arg_3,
    /* [size_is][size_is][ref][out] */ unsigned char **arg_4,
    /* [out] */ long *arg_5)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[5938],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc103_LsarAuditSetGlobalSacl( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [in] */ struct Struct_4032_t *arg_1,
    /* [in] */ struct Struct_5486_t *arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[6008],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc104_LsarAuditQueryGlobalSacl( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [in] */ struct Struct_4032_t *arg_1,
    /* [out] */ struct Struct_5486_t *arg_2)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[6060],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc105_CredrProfileLoadedEx( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [in] */ long arg_1)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[6112],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc106_LsarInteractiveSessionIsLoggedOff( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [in] */ struct Struct_62_t *arg_1)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[6158],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc107_LsarConfigureAutoLogonCredentials( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[6204],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


long Proc108_LsarGetDeviceRegistrationInfo( 
    /* [in] */ handle_t IDL_handle,
    /* [string][unique][in] */ wchar_t *arg_0,
    /* [ref][out] */ struct Struct_5608_t **arg_1)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&DefaultIfName_StubDesc,
                  (PFORMAT_STRING) &rpc__MIDL_ProcFormatString.Format[6244],
                  ( unsigned char * )&IDL_handle);
    return ( long  )_RetVal.Simple;
    
}


#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif
#if !(TARGET_IS_NT60_OR_LATER)
#error You need Windows Vista or later to run this stub because it uses these features:
#error   forced complex structure or array, new range semantics, compiled for Windows Vista.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const rpc_MIDL_PROC_FORMAT_STRING rpc__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure Proc0_LsarClose */

			0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10 */	0x30,		/* FC_BIND_CONTEXT */
			0xe0,		/* Ctxt flags:  via ptr, in, out, */
/* 12 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 14 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 16 */	NdrFcShort( 0x38 ),	/* 56 */
/* 18 */	NdrFcShort( 0x40 ),	/* 64 */
/* 20 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 22 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */
/* 26 */	NdrFcShort( 0x0 ),	/* 0 */
/* 28 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 30 */	NdrFcShort( 0x118 ),	/* Flags:  in, out, simple ref, */
/* 32 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 34 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 36 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 38 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 40 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc1_CredrRename */

/* 42 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 44 */	NdrFcLong( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x1 ),	/* 1 */
/* 50 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 52 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 54 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 56 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 58 */	NdrFcShort( 0x24 ),	/* 36 */
/* 60 */	NdrFcShort( 0x8 ),	/* 8 */
/* 62 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 64 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 66 */	NdrFcShort( 0x0 ),	/* 0 */
/* 68 */	NdrFcShort( 0x0 ),	/* 0 */
/* 70 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 72 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 74 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 76 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Return value */

/* 78 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 80 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 82 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc2_LsarEnumeratePrivileges */

/* 84 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 86 */	NdrFcLong( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0x2 ),	/* 2 */
/* 92 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 94 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 96 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 98 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 100 */	NdrFcShort( 0x48 ),	/* 72 */
/* 102 */	NdrFcShort( 0x24 ),	/* 36 */
/* 104 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 106 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 108 */	NdrFcShort( 0x1 ),	/* 1 */
/* 110 */	NdrFcShort( 0x0 ),	/* 0 */
/* 112 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 114 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 116 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 118 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 120 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 122 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_2 */

/* 126 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 128 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 130 */	NdrFcShort( 0x8a ),	/* Type Offset=138 */

	/* Parameter arg_3 */

/* 132 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 134 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 140 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc3_LsarQuerySecurityObject */

/* 144 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0x3 ),	/* 3 */
/* 152 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 154 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 156 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 158 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 160 */	NdrFcShort( 0x2c ),	/* 44 */
/* 162 */	NdrFcShort( 0x8 ),	/* 8 */
/* 164 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 166 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 168 */	NdrFcShort( 0x1 ),	/* 1 */
/* 170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 172 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 174 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 176 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 178 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 180 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 182 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_2 */

/* 186 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 188 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 190 */	NdrFcShort( 0x9e ),	/* Type Offset=158 */

	/* Return value */

/* 192 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 194 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 196 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc4_LsarSetSecurityObject */

/* 198 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 200 */	NdrFcLong( 0x0 ),	/* 0 */
/* 204 */	NdrFcShort( 0x4 ),	/* 4 */
/* 206 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 208 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 210 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 212 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 214 */	NdrFcShort( 0x2c ),	/* 44 */
/* 216 */	NdrFcShort( 0x8 ),	/* 8 */
/* 218 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 220 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 224 */	NdrFcShort( 0x1 ),	/* 1 */
/* 226 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 228 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 230 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 232 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 234 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 236 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_2 */

/* 240 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 242 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 244 */	NdrFcShort( 0xbc ),	/* Type Offset=188 */

	/* Return value */

/* 246 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 248 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc5_LsaITestCall */

/* 252 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 258 */	NdrFcShort( 0x5 ),	/* 5 */
/* 260 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 262 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 264 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 268 */	NdrFcShort( 0x8 ),	/* 8 */
/* 270 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 272 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 276 */	NdrFcShort( 0x1 ),	/* 1 */
/* 278 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 280 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 282 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 284 */	NdrFcShort( 0xd8 ),	/* Type Offset=216 */

	/* Parameter arg_1 */

/* 286 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 288 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 290 */	NdrFcShort( 0xd8 ),	/* Type Offset=216 */

	/* Parameter arg_2 */

/* 292 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 294 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 296 */	NdrFcShort( 0xd8 ),	/* Type Offset=216 */

	/* Parameter arg_3 */

/* 298 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 300 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 302 */	NdrFcShort( 0xd8 ),	/* Type Offset=216 */

	/* Parameter arg_4 */

/* 304 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 306 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 308 */	NdrFcShort( 0xd8 ),	/* Type Offset=216 */

	/* Return value */

/* 310 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 312 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc6_LsarOpenPolicyRPC */

/* 316 */	0x33,		/* FC_AUTO_HANDLE */
			0x48,		/* Old Flags:  */
/* 318 */	NdrFcLong( 0x0 ),	/* 0 */
/* 322 */	NdrFcShort( 0x6 ),	/* 6 */
/* 324 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 326 */	NdrFcShort( 0x22 ),	/* 34 */
/* 328 */	NdrFcShort( 0x40 ),	/* 64 */
/* 330 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 332 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 336 */	NdrFcShort( 0x1 ),	/* 1 */
/* 338 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 340 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 342 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 344 */	NdrFcShort( 0xee ),	/* Type Offset=238 */

	/* Parameter arg_1 */

/* 346 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 348 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 350 */	NdrFcShort( 0x1c8 ),	/* Type Offset=456 */

	/* Parameter arg_2 */

/* 352 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 354 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 356 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 358 */	NdrFcShort( 0x110 ),	/* Flags:  out, simple ref, */
/* 360 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 362 */	NdrFcShort( 0x202 ),	/* Type Offset=514 */

	/* Return value */

/* 364 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 366 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 368 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc7_LsarQueryInformationPolicy */

/* 370 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 372 */	NdrFcLong( 0x0 ),	/* 0 */
/* 376 */	NdrFcShort( 0x7 ),	/* 7 */
/* 378 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 380 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 382 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 384 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 386 */	NdrFcShort( 0x2a ),	/* 42 */
/* 388 */	NdrFcShort( 0x8 ),	/* 8 */
/* 390 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 392 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 394 */	NdrFcShort( 0x1 ),	/* 1 */
/* 396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 398 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 400 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 402 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 404 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 406 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 408 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 410 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_2 */

/* 412 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 414 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 416 */	NdrFcShort( 0x206 ),	/* Type Offset=518 */

	/* Return value */

/* 418 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 420 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 422 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc8_LsarSetInformationPolicy */

/* 424 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 426 */	NdrFcLong( 0x0 ),	/* 0 */
/* 430 */	NdrFcShort( 0x8 ),	/* 8 */
/* 432 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 434 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 436 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 438 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 440 */	NdrFcShort( 0x2a ),	/* 42 */
/* 442 */	NdrFcShort( 0x8 ),	/* 8 */
/* 444 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 446 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 450 */	NdrFcShort( 0x1 ),	/* 1 */
/* 452 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 454 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 456 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 458 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 460 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 462 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 464 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_2 */

/* 466 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 468 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 470 */	NdrFcShort( 0x3e8 ),	/* Type Offset=1000 */

	/* Return value */

/* 472 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 474 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 476 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc9_LsaITestCall */

/* 478 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 480 */	NdrFcLong( 0x0 ),	/* 0 */
/* 484 */	NdrFcShort( 0x9 ),	/* 9 */
/* 486 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 488 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 490 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 492 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 494 */	NdrFcShort( 0x24 ),	/* 36 */
/* 496 */	NdrFcShort( 0x8 ),	/* 8 */
/* 498 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 500 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 506 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 508 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 510 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 512 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Return value */

/* 514 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 516 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 518 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc10_LsarCreateAccount */

/* 520 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 522 */	NdrFcLong( 0x0 ),	/* 0 */
/* 526 */	NdrFcShort( 0xa ),	/* 10 */
/* 528 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 530 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 532 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 534 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 536 */	NdrFcShort( 0x2c ),	/* 44 */
/* 538 */	NdrFcShort( 0x40 ),	/* 64 */
/* 540 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 542 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 546 */	NdrFcShort( 0x1 ),	/* 1 */
/* 548 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 550 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 552 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 554 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 556 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 558 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 560 */	NdrFcShort( 0x158 ),	/* Type Offset=344 */

	/* Parameter arg_2 */

/* 562 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 564 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 566 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 568 */	NdrFcShort( 0x110 ),	/* Flags:  out, simple ref, */
/* 570 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 572 */	NdrFcShort( 0x404 ),	/* Type Offset=1028 */

	/* Return value */

/* 574 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 576 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 578 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc11_LsarEnumerateAccounts */

/* 580 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 582 */	NdrFcLong( 0x0 ),	/* 0 */
/* 586 */	NdrFcShort( 0xb ),	/* 11 */
/* 588 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 590 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 592 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 594 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 596 */	NdrFcShort( 0x48 ),	/* 72 */
/* 598 */	NdrFcShort( 0x24 ),	/* 36 */
/* 600 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 602 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 604 */	NdrFcShort( 0x1 ),	/* 1 */
/* 606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 608 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 610 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 612 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 614 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 616 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 618 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 620 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_2 */

/* 622 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 624 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 626 */	NdrFcShort( 0x44c ),	/* Type Offset=1100 */

	/* Parameter arg_3 */

/* 628 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 630 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 632 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 634 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 636 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 638 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc12_LsarCreateTrustedDomain */

/* 640 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 642 */	NdrFcLong( 0x0 ),	/* 0 */
/* 646 */	NdrFcShort( 0xc ),	/* 12 */
/* 648 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 650 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 652 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 654 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 656 */	NdrFcShort( 0x2c ),	/* 44 */
/* 658 */	NdrFcShort( 0x40 ),	/* 64 */
/* 660 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 662 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 666 */	NdrFcShort( 0x1 ),	/* 1 */
/* 668 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 670 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 672 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 674 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 676 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 678 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 680 */	NdrFcShort( 0x2c2 ),	/* Type Offset=706 */

	/* Parameter arg_2 */

/* 682 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 684 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 686 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 688 */	NdrFcShort( 0x110 ),	/* Flags:  out, simple ref, */
/* 690 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 692 */	NdrFcShort( 0x404 ),	/* Type Offset=1028 */

	/* Return value */

/* 694 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 696 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 698 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc13_LsarEnumerateTrustedDomains */

/* 700 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 702 */	NdrFcLong( 0x0 ),	/* 0 */
/* 706 */	NdrFcShort( 0xd ),	/* 13 */
/* 708 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 710 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 712 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 714 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 716 */	NdrFcShort( 0x48 ),	/* 72 */
/* 718 */	NdrFcShort( 0x24 ),	/* 36 */
/* 720 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 722 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 724 */	NdrFcShort( 0x1 ),	/* 1 */
/* 726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 728 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 730 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 732 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 734 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 736 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 738 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 740 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_2 */

/* 742 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 744 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 746 */	NdrFcShort( 0x49c ),	/* Type Offset=1180 */

	/* Parameter arg_3 */

/* 748 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 750 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 752 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 754 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 756 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 758 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc14_LsarLookupNames */

/* 760 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 762 */	NdrFcLong( 0x0 ),	/* 0 */
/* 766 */	NdrFcShort( 0xe ),	/* 14 */
/* 768 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 770 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 772 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 774 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 776 */	NdrFcShort( 0x4e ),	/* 78 */
/* 778 */	NdrFcShort( 0x24 ),	/* 36 */
/* 780 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 782 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 784 */	NdrFcShort( 0x1 ),	/* 1 */
/* 786 */	NdrFcShort( 0x1 ),	/* 1 */
/* 788 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 790 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 792 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 794 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 796 */	NdrFcShort( 0x88 ),	/* Flags:  in, by val, */
/* 798 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 800 */	NdrFcShort( 0x4b0 ),	/* 1200 */

	/* Parameter arg_2 */

/* 802 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 804 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 806 */	NdrFcShort( 0x4be ),	/* Type Offset=1214 */

	/* Parameter arg_3 */

/* 808 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 810 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 812 */	NdrFcShort( 0x4ea ),	/* Type Offset=1258 */

	/* Parameter arg_4 */

/* 814 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 816 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 818 */	NdrFcShort( 0x544 ),	/* Type Offset=1348 */

	/* Parameter arg_5 */

/* 820 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 822 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 824 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_6 */

/* 826 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 828 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 830 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 832 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 834 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 836 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc15_LsarLookupSids */

/* 838 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 840 */	NdrFcLong( 0x0 ),	/* 0 */
/* 844 */	NdrFcShort( 0xf ),	/* 15 */
/* 846 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 848 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 850 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 852 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 854 */	NdrFcShort( 0x46 ),	/* 70 */
/* 856 */	NdrFcShort( 0x24 ),	/* 36 */
/* 858 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 860 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 862 */	NdrFcShort( 0x1 ),	/* 1 */
/* 864 */	NdrFcShort( 0x1 ),	/* 1 */
/* 866 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 868 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 870 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 872 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 874 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 876 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 878 */	NdrFcShort( 0x588 ),	/* Type Offset=1416 */

	/* Parameter arg_2 */

/* 880 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 882 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 884 */	NdrFcShort( 0x4ea ),	/* Type Offset=1258 */

	/* Parameter arg_3 */

/* 886 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 888 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 890 */	NdrFcShort( 0x5da ),	/* Type Offset=1498 */

	/* Parameter arg_4 */

/* 892 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 894 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 896 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_5 */

/* 898 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 900 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 902 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 904 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 906 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 908 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc16_LsarCreateSecret */

/* 910 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 912 */	NdrFcLong( 0x0 ),	/* 0 */
/* 916 */	NdrFcShort( 0x10 ),	/* 16 */
/* 918 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 920 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 922 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 924 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 926 */	NdrFcShort( 0x2c ),	/* 44 */
/* 928 */	NdrFcShort( 0x40 ),	/* 64 */
/* 930 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 932 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 936 */	NdrFcShort( 0x1 ),	/* 1 */
/* 938 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 940 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 942 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 944 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 946 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 948 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 950 */	NdrFcShort( 0xd8 ),	/* Type Offset=216 */

	/* Parameter arg_2 */

/* 952 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 954 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 956 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 958 */	NdrFcShort( 0x110 ),	/* Flags:  out, simple ref, */
/* 960 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 962 */	NdrFcShort( 0x404 ),	/* Type Offset=1028 */

	/* Return value */

/* 964 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 966 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 968 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc17_LsarOpenAccount */

/* 970 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 972 */	NdrFcLong( 0x0 ),	/* 0 */
/* 976 */	NdrFcShort( 0x11 ),	/* 17 */
/* 978 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 980 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 982 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 984 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 986 */	NdrFcShort( 0x2c ),	/* 44 */
/* 988 */	NdrFcShort( 0x40 ),	/* 64 */
/* 990 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 992 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 994 */	NdrFcShort( 0x0 ),	/* 0 */
/* 996 */	NdrFcShort( 0x1 ),	/* 1 */
/* 998 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 1000 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1002 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1004 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 1006 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1008 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1010 */	NdrFcShort( 0x158 ),	/* Type Offset=344 */

	/* Parameter arg_2 */

/* 1012 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1014 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1016 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 1018 */	NdrFcShort( 0x110 ),	/* Flags:  out, simple ref, */
/* 1020 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1022 */	NdrFcShort( 0x404 ),	/* Type Offset=1028 */

	/* Return value */

/* 1024 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1026 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1028 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc18_LsarEnumeratePrivilegesAccount */

/* 1030 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1032 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1036 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1038 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1040 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1042 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1044 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1046 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1048 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1050 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1052 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 1054 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1058 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 1060 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1062 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1064 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 1066 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1068 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1070 */	NdrFcShort( 0x5ee ),	/* Type Offset=1518 */

	/* Return value */

/* 1072 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1074 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1076 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc19_LsarAddPrivilegesToAccount */

/* 1078 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1080 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1084 */	NdrFcShort( 0x13 ),	/* 19 */
/* 1086 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1088 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1090 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1092 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1094 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1096 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1098 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1100 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 1102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1104 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1106 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 1108 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1110 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1112 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 1114 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1116 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1118 */	NdrFcShort( 0x61a ),	/* Type Offset=1562 */

	/* Return value */

/* 1120 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1122 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc20_LsarRemovePrivilegesFromAccount */

/* 1126 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1128 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1132 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1134 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1136 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1138 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1140 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1142 */	NdrFcShort( 0x29 ),	/* 41 */
/* 1144 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1146 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1148 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 1150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1152 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1154 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 1156 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1158 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1160 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 1162 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1164 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1166 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter arg_2 */

/* 1168 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1170 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1172 */	NdrFcShort( 0x5f2 ),	/* Type Offset=1522 */

	/* Return value */

/* 1174 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1176 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1178 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc21_LsarGetQuotasForAccount */

/* 1180 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1182 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1186 */	NdrFcShort( 0x15 ),	/* 21 */
/* 1188 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1190 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1192 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1194 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1196 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1198 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1200 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1202 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1208 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 1210 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1212 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1214 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 1216 */	NdrFcShort( 0x8113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=32 */
/* 1218 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1220 */	NdrFcShort( 0x330 ),	/* Type Offset=816 */

	/* Return value */

/* 1222 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1224 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc22_LsaAllocateSharedMemory */

/* 1228 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1230 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1234 */	NdrFcShort( 0x16 ),	/* 22 */
/* 1236 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1238 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1240 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1242 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1244 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1246 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1248 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1250 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1256 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 1258 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1260 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1262 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 1264 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1266 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1268 */	NdrFcShort( 0x330 ),	/* Type Offset=816 */

	/* Return value */

/* 1270 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1272 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1274 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc23_LsarGetSystemAccessAccount */

/* 1276 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1278 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1282 */	NdrFcShort( 0x17 ),	/* 23 */
/* 1284 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1286 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1288 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1290 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1292 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1294 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1296 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1298 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1304 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 1306 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1308 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1310 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 1312 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1314 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1316 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1318 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1320 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc24_LsarSetSystemAccessAccount */

/* 1324 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1326 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1330 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1332 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1334 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1336 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1338 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1340 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1342 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1344 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1346 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1352 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 1354 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1356 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1358 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 1360 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1362 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1366 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1368 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc25_LsarOpenTrustedDomain */

/* 1372 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1374 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1378 */	NdrFcShort( 0x19 ),	/* 25 */
/* 1380 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1382 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1384 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1386 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1388 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1390 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1392 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1394 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 1396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1398 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1400 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 1402 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1404 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1406 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 1408 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1410 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1412 */	NdrFcShort( 0x158 ),	/* Type Offset=344 */

	/* Parameter arg_2 */

/* 1414 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1416 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1418 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 1420 */	NdrFcShort( 0x110 ),	/* Flags:  out, simple ref, */
/* 1422 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1424 */	NdrFcShort( 0x404 ),	/* Type Offset=1028 */

	/* Return value */

/* 1426 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1428 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1430 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc26_LsarQueryInfoTrustedDomain */

/* 1432 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1434 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1438 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1440 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1442 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1444 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1446 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1448 */	NdrFcShort( 0x2a ),	/* 42 */
/* 1450 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1452 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 1454 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 1456 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1460 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 1462 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1464 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1466 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 1468 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1470 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1472 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_2 */

/* 1474 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1476 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1478 */	NdrFcShort( 0x634 ),	/* Type Offset=1588 */

	/* Return value */

/* 1480 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1482 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1484 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc27_LsarSetInformationTrustedDomain */

/* 1486 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1488 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1492 */	NdrFcShort( 0x1b ),	/* 27 */
/* 1494 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1496 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1498 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1500 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1502 */	NdrFcShort( 0x2a ),	/* 42 */
/* 1504 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1506 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1508 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 1510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1512 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1514 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 1516 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1518 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1520 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 1522 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1524 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1526 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_2 */

/* 1528 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1530 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1532 */	NdrFcShort( 0x8e4 ),	/* Type Offset=2276 */

	/* Return value */

/* 1534 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1536 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1538 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc28_LsarOpenSecret */

/* 1540 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1542 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1546 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1548 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1550 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1552 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1554 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1556 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1558 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1560 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1562 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 1564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1566 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1568 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 1570 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1572 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1574 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 1576 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1578 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1580 */	NdrFcShort( 0xd8 ),	/* Type Offset=216 */

	/* Parameter arg_2 */

/* 1582 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1584 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1586 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 1588 */	NdrFcShort( 0x110 ),	/* Flags:  out, simple ref, */
/* 1590 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1592 */	NdrFcShort( 0x404 ),	/* Type Offset=1028 */

	/* Return value */

/* 1594 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1596 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1598 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc29_LsarSetSecret */

/* 1600 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1602 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1606 */	NdrFcShort( 0x1d ),	/* 29 */
/* 1608 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1610 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1612 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1614 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1616 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1618 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1620 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1622 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 1624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1626 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1628 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 1630 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1632 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1634 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 1636 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1638 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1640 */	NdrFcShort( 0x8f8 ),	/* Type Offset=2296 */

	/* Parameter arg_2 */

/* 1642 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1644 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1646 */	NdrFcShort( 0x8f8 ),	/* Type Offset=2296 */

	/* Return value */

/* 1648 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1650 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1652 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc30_LsarQuerySecret */

/* 1654 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1656 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1660 */	NdrFcShort( 0x1e ),	/* 30 */
/* 1662 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1664 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1666 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1668 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1670 */	NdrFcShort( 0x7c ),	/* 124 */
/* 1672 */	NdrFcShort( 0x60 ),	/* 96 */
/* 1674 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1676 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 1678 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1680 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1682 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 1684 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1686 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1688 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 1690 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 1692 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1694 */	NdrFcShort( 0x8fc ),	/* Type Offset=2300 */

	/* Parameter arg_2 */

/* 1696 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 1698 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1700 */	NdrFcShort( 0x900 ),	/* Type Offset=2304 */

	/* Parameter arg_3 */

/* 1702 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 1704 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1706 */	NdrFcShort( 0x8fc ),	/* Type Offset=2300 */

	/* Parameter arg_4 */

/* 1708 */	NdrFcShort( 0x1a ),	/* Flags:  must free, in, out, */
/* 1710 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1712 */	NdrFcShort( 0x900 ),	/* Type Offset=2304 */

	/* Return value */

/* 1714 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1716 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1718 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc31_LsarLookupPrivilegeValue */

/* 1720 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1722 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1726 */	NdrFcShort( 0x1f ),	/* 31 */
/* 1728 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1730 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1732 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1734 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1736 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1738 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1740 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1742 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 1744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1746 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1748 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 1750 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1752 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1754 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 1756 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1758 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1760 */	NdrFcShort( 0xd8 ),	/* Type Offset=216 */

	/* Parameter arg_2 */

/* 1762 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1764 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1766 */	NdrFcShort( 0x16 ),	/* Type Offset=22 */

	/* Return value */

/* 1768 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1770 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1772 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc32_LsarLookupPrivilegeName */

/* 1774 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1776 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1780 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1782 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1784 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1786 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1788 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1790 */	NdrFcShort( 0x50 ),	/* 80 */
/* 1792 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1794 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 1796 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 1798 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1802 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 1804 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1806 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1808 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 1810 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1812 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1814 */	NdrFcShort( 0x16 ),	/* Type Offset=22 */

	/* Parameter arg_2 */

/* 1816 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1818 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1820 */	NdrFcShort( 0x90c ),	/* Type Offset=2316 */

	/* Return value */

/* 1822 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1824 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1826 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc33_LsarLookupPrivilegeDisplayName */

/* 1828 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1830 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1834 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1836 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1838 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1840 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1842 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1844 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1846 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1848 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 1850 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 1852 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1854 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1856 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 1858 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1860 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1862 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 1864 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1866 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1868 */	NdrFcShort( 0xd8 ),	/* Type Offset=216 */

	/* Parameter arg_2 */

/* 1870 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1872 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1874 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 1876 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1878 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1880 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_4 */

/* 1882 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1884 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1886 */	NdrFcShort( 0x90c ),	/* Type Offset=2316 */

	/* Parameter arg_5 */

/* 1888 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1890 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1892 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1894 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1896 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1898 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc34_LsarDeleteObject */

/* 1900 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1902 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1906 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1908 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1910 */	0x30,		/* FC_BIND_CONTEXT */
			0xe0,		/* Ctxt flags:  via ptr, in, out, */
/* 1912 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1914 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1916 */	NdrFcShort( 0x38 ),	/* 56 */
/* 1918 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1920 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1922 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1928 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 1930 */	NdrFcShort( 0x118 ),	/* Flags:  in, out, simple ref, */
/* 1932 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1934 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 1936 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1938 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1940 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc35_LsarEnumerateAccountsWithUserRight */

/* 1942 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1944 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1948 */	NdrFcShort( 0x23 ),	/* 35 */
/* 1950 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1952 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 1954 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1956 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1958 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1960 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1962 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1964 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 1966 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1968 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1970 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 1972 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 1974 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 1976 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 1978 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1980 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1982 */	NdrFcShort( 0x910 ),	/* Type Offset=2320 */

	/* Parameter arg_2 */

/* 1984 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1986 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1988 */	NdrFcShort( 0x44c ),	/* Type Offset=1100 */

	/* Return value */

/* 1990 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1992 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1994 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc36_LsarEnumerateAccountRights */

/* 1996 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1998 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2002 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2004 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2006 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 2008 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2010 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 2012 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2014 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2016 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2018 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 2020 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2022 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2024 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 2026 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 2028 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2030 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 2032 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2034 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2036 */	NdrFcShort( 0x158 ),	/* Type Offset=344 */

	/* Parameter arg_2 */

/* 2038 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2040 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2042 */	NdrFcShort( 0x948 ),	/* Type Offset=2376 */

	/* Return value */

/* 2044 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2046 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2048 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc37_LsarAddAccountRights */

/* 2050 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2052 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2056 */	NdrFcShort( 0x25 ),	/* 37 */
/* 2058 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2060 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 2062 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2064 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 2066 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2068 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2070 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2072 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 2074 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2076 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2078 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 2080 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 2082 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2084 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 2086 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2088 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2090 */	NdrFcShort( 0x158 ),	/* Type Offset=344 */

	/* Parameter arg_2 */

/* 2092 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2094 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2096 */	NdrFcShort( 0x948 ),	/* Type Offset=2376 */

	/* Return value */

/* 2098 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2100 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2102 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc38_LsarRemoveAccountRights */

/* 2104 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2106 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2110 */	NdrFcShort( 0x26 ),	/* 38 */
/* 2112 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2114 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 2116 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2118 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 2120 */	NdrFcShort( 0x29 ),	/* 41 */
/* 2122 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2124 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2126 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 2128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2130 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2132 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 2134 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 2136 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2138 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 2140 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2142 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2144 */	NdrFcShort( 0x158 ),	/* Type Offset=344 */

	/* Parameter arg_2 */

/* 2146 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2148 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2150 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 2152 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2154 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2156 */	NdrFcShort( 0x948 ),	/* Type Offset=2376 */

	/* Return value */

/* 2158 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2160 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2162 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc39_LsarQueryTrustedDomainInfo */

/* 2164 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2166 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2170 */	NdrFcShort( 0x27 ),	/* 39 */
/* 2172 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2174 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 2176 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2178 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 2180 */	NdrFcShort( 0x2a ),	/* 42 */
/* 2182 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2184 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2186 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 2188 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2190 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2192 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 2194 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 2196 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2198 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 2200 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2202 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2204 */	NdrFcShort( 0x158 ),	/* Type Offset=344 */

	/* Parameter arg_2 */

/* 2206 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2208 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2210 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 2212 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2214 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2216 */	NdrFcShort( 0x960 ),	/* Type Offset=2400 */

	/* Return value */

/* 2218 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2220 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2222 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc40_LsarSetTrustedDomainInfo */

/* 2224 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2226 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2230 */	NdrFcShort( 0x28 ),	/* 40 */
/* 2232 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2234 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 2236 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2238 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 2240 */	NdrFcShort( 0x2a ),	/* 42 */
/* 2242 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2244 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2246 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 2248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2250 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2252 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 2254 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 2256 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2258 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 2260 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2262 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2264 */	NdrFcShort( 0x158 ),	/* Type Offset=344 */

	/* Parameter arg_2 */

/* 2266 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2268 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2270 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 2272 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2274 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2276 */	NdrFcShort( 0x980 ),	/* Type Offset=2432 */

	/* Return value */

/* 2278 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2280 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc41_LsarDeleteTrustedDomain */

/* 2284 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2290 */	NdrFcShort( 0x29 ),	/* 41 */
/* 2292 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2294 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 2296 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2298 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 2300 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2302 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2304 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2306 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 2308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2310 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2312 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 2314 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 2316 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2318 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 2320 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2322 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2324 */	NdrFcShort( 0x158 ),	/* Type Offset=344 */

	/* Return value */

/* 2326 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2328 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2330 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc42_LsarStorePrivateData */

/* 2332 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2334 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2338 */	NdrFcShort( 0x2a ),	/* 42 */
/* 2340 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2342 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 2344 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2346 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 2348 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2350 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2352 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2354 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 2356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2358 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2360 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 2362 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 2364 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2366 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 2368 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2370 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2372 */	NdrFcShort( 0xd8 ),	/* Type Offset=216 */

	/* Parameter arg_2 */

/* 2374 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2376 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2378 */	NdrFcShort( 0x8f8 ),	/* Type Offset=2296 */

	/* Return value */

/* 2380 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2382 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc43_LsarRetrievePrivateData */

/* 2386 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2388 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2392 */	NdrFcShort( 0x2b ),	/* 43 */
/* 2394 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2396 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 2398 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2400 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 2402 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2404 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2406 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2408 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 2410 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2412 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2414 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 2416 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 2418 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2420 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 2422 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2424 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2426 */	NdrFcShort( 0xd8 ),	/* Type Offset=216 */

	/* Parameter arg_2 */

/* 2428 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2430 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2432 */	NdrFcShort( 0x994 ),	/* Type Offset=2452 */

	/* Return value */

/* 2434 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2436 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2438 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc44_LsarOpenPolicy2 */

/* 2440 */	0x33,		/* FC_AUTO_HANDLE */
			0x48,		/* Old Flags:  */
/* 2442 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2446 */	NdrFcShort( 0x2c ),	/* 44 */
/* 2448 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2450 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2452 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2454 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2456 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 2458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2460 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2462 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 2464 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2466 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2468 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 2470 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2472 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2474 */	NdrFcShort( 0x1c8 ),	/* Type Offset=456 */

	/* Parameter arg_2 */

/* 2476 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2478 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2480 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 2482 */	NdrFcShort( 0x110 ),	/* Flags:  out, simple ref, */
/* 2484 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2486 */	NdrFcShort( 0x202 ),	/* Type Offset=514 */

	/* Return value */

/* 2488 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2490 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2492 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc45_LsarGetUserName */

/* 2494 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2496 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2500 */	NdrFcShort( 0x2d ),	/* 45 */
/* 2502 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2504 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 2506 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2510 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2512 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2514 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 2516 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2518 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2520 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 2522 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2524 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2526 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 2528 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2530 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2532 */	NdrFcShort( 0x90c ),	/* Type Offset=2316 */

	/* Parameter arg_2 */

/* 2534 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2536 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2538 */	NdrFcShort( 0x99c ),	/* Type Offset=2460 */

	/* Return value */

/* 2540 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2542 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2544 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc46_LsarQueryInformationPolicy2 */

/* 2546 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2548 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2552 */	NdrFcShort( 0x2e ),	/* 46 */
/* 2554 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2556 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 2558 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2560 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 2562 */	NdrFcShort( 0x2a ),	/* 42 */
/* 2564 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2566 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 2568 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 2570 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2574 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 2576 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 2578 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2580 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 2582 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2584 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2586 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_2 */

/* 2588 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2590 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2592 */	NdrFcShort( 0x9a0 ),	/* Type Offset=2464 */

	/* Return value */

/* 2594 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2596 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2598 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc47_LsarSetInformationPolicy2 */

/* 2600 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2602 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2606 */	NdrFcShort( 0x2f ),	/* 47 */
/* 2608 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2610 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 2612 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2614 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 2616 */	NdrFcShort( 0x2a ),	/* 42 */
/* 2618 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2620 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2622 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 2624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2626 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2628 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 2630 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 2632 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2634 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 2636 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2638 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2640 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_2 */

/* 2642 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2644 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2646 */	NdrFcShort( 0x9c0 ),	/* Type Offset=2496 */

	/* Return value */

/* 2648 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2650 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2652 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc48_LsarQueryTrustedDomainInfoByName */

/* 2654 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2656 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2660 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2662 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2664 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 2666 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2668 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 2670 */	NdrFcShort( 0x2a ),	/* 42 */
/* 2672 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2674 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2676 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 2678 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2680 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2682 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 2684 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 2686 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2688 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 2690 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2692 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2694 */	NdrFcShort( 0xd8 ),	/* Type Offset=216 */

	/* Parameter arg_2 */

/* 2696 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2698 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2700 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 2702 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2704 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2706 */	NdrFcShort( 0x9d4 ),	/* Type Offset=2516 */

	/* Return value */

/* 2708 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2710 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2712 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc49_LsarSetTrustedDomainInfoByName */

/* 2714 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2716 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2720 */	NdrFcShort( 0x31 ),	/* 49 */
/* 2722 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2724 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 2726 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2728 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 2730 */	NdrFcShort( 0x2a ),	/* 42 */
/* 2732 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2734 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2736 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 2738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2740 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2742 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 2744 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 2746 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2748 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 2750 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2752 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2754 */	NdrFcShort( 0xd8 ),	/* Type Offset=216 */

	/* Parameter arg_2 */

/* 2756 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2758 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2760 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 2762 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2764 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2766 */	NdrFcShort( 0x9f4 ),	/* Type Offset=2548 */

	/* Return value */

/* 2768 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2770 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2772 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc50_LsarEnumerateTrustedDomainsEx */

/* 2774 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2776 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2780 */	NdrFcShort( 0x32 ),	/* 50 */
/* 2782 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2784 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 2786 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2788 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 2790 */	NdrFcShort( 0x48 ),	/* 72 */
/* 2792 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2794 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 2796 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 2798 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2802 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 2804 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 2806 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2808 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 2810 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 2812 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2814 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_2 */

/* 2816 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2818 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2820 */	NdrFcShort( 0xa48 ),	/* Type Offset=2632 */

	/* Parameter arg_3 */

/* 2822 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2824 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2826 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2828 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2830 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc51_LsarCreateTrustedDomainEx */

/* 2834 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2836 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2840 */	NdrFcShort( 0x33 ),	/* 51 */
/* 2842 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2844 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 2846 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2848 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 2850 */	NdrFcShort( 0x2c ),	/* 44 */
/* 2852 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2854 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2856 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 2858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2860 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2862 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 2864 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 2866 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2868 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 2870 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2872 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2874 */	NdrFcShort( 0x74c ),	/* Type Offset=1868 */

	/* Parameter arg_2 */

/* 2876 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2878 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2880 */	NdrFcShort( 0x7bc ),	/* Type Offset=1980 */

	/* Parameter arg_3 */

/* 2882 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2884 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2886 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_4 */

/* 2888 */	NdrFcShort( 0x110 ),	/* Flags:  out, simple ref, */
/* 2890 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2892 */	NdrFcShort( 0x404 ),	/* Type Offset=1028 */

	/* Return value */

/* 2894 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2896 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2898 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc52_LsaITestCall */

/* 2900 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2902 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2906 */	NdrFcShort( 0x34 ),	/* 52 */
/* 2908 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2910 */	0x30,		/* FC_BIND_CONTEXT */
			0xe0,		/* Ctxt flags:  via ptr, in, out, */
/* 2912 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2914 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 2916 */	NdrFcShort( 0x38 ),	/* 56 */
/* 2918 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2920 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2922 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 2924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2928 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 2930 */	NdrFcShort( 0x118 ),	/* Flags:  in, out, simple ref, */
/* 2932 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2934 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 2936 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2938 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2940 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc53_LsarQueryDomainInformationPolicy */

/* 2942 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2944 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2948 */	NdrFcShort( 0x35 ),	/* 53 */
/* 2950 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2952 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 2954 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2956 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 2958 */	NdrFcShort( 0x2a ),	/* 42 */
/* 2960 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2962 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 2964 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 2966 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2970 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 2972 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 2974 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 2976 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 2978 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2980 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2982 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_2 */

/* 2984 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2986 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2988 */	NdrFcShort( 0xa64 ),	/* Type Offset=2660 */

	/* Return value */

/* 2990 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2992 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2994 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc54_LsarSetDomainInformationPolicy */

/* 2996 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 2998 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3002 */	NdrFcShort( 0x36 ),	/* 54 */
/* 3004 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3006 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 3008 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3010 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 3012 */	NdrFcShort( 0x2a ),	/* 42 */
/* 3014 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3016 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3018 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 3020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3022 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3024 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 3026 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 3028 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3030 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 3032 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3034 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3036 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_2 */

/* 3038 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3040 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3042 */	NdrFcShort( 0xadc ),	/* Type Offset=2780 */

	/* Return value */

/* 3044 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3046 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3048 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc55_LsarOpenTrustedDomainByName */

/* 3050 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3052 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3056 */	NdrFcShort( 0x37 ),	/* 55 */
/* 3058 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3060 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 3062 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3064 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 3066 */	NdrFcShort( 0x2c ),	/* 44 */
/* 3068 */	NdrFcShort( 0x40 ),	/* 64 */
/* 3070 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3072 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 3074 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3076 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3078 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 3080 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 3082 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3084 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 3086 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3088 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3090 */	NdrFcShort( 0xd8 ),	/* Type Offset=216 */

	/* Parameter arg_2 */

/* 3092 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3094 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3096 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 3098 */	NdrFcShort( 0x110 ),	/* Flags:  out, simple ref, */
/* 3100 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3102 */	NdrFcShort( 0x404 ),	/* Type Offset=1028 */

	/* Return value */

/* 3104 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3106 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3108 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc56_LsaITestCall */

/* 3110 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3112 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3116 */	NdrFcShort( 0x38 ),	/* 56 */
/* 3118 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3120 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 3122 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3124 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 3126 */	NdrFcShort( 0x2a ),	/* 42 */
/* 3128 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3130 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3132 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 3134 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3136 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3138 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 3140 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 3142 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3144 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 3146 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3148 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3150 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_2 */

/* 3152 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3154 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3156 */	NdrFcShort( 0xb4e ),	/* Type Offset=2894 */

	/* Parameter arg_3 */

/* 3158 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3160 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3162 */	NdrFcShort( 0xb62 ),	/* Type Offset=2914 */

	/* Return value */

/* 3164 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3166 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3168 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc57_LsarLookupSids2 */

/* 3170 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3172 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3176 */	NdrFcShort( 0x39 ),	/* 57 */
/* 3178 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 3180 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 3182 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3184 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 3186 */	NdrFcShort( 0x56 ),	/* 86 */
/* 3188 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3190 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 3192 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 3194 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3196 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3198 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 3200 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 3202 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3204 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 3206 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3208 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3210 */	NdrFcShort( 0x588 ),	/* Type Offset=1416 */

	/* Parameter arg_2 */

/* 3212 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3214 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3216 */	NdrFcShort( 0x4ea ),	/* Type Offset=1258 */

	/* Parameter arg_3 */

/* 3218 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 3220 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3222 */	NdrFcShort( 0xbaa ),	/* Type Offset=2986 */

	/* Parameter arg_4 */

/* 3224 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3226 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3228 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_5 */

/* 3230 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3232 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3234 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_6 */

/* 3236 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3238 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3240 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_7 */

/* 3242 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3244 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3246 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3248 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3250 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3252 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc58_LsarLookupNames2 */

/* 3254 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3256 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3260 */	NdrFcShort( 0x3a ),	/* 58 */
/* 3262 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3264 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 3266 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3268 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 3270 */	NdrFcShort( 0x5e ),	/* 94 */
/* 3272 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3274 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0xa,		/* 10 */
/* 3276 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 3278 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3280 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3282 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 3284 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 3286 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3288 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 3290 */	NdrFcShort( 0x88 ),	/* Flags:  in, by val, */
/* 3292 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3294 */	NdrFcShort( 0xbbe ),	/* 3006 */

	/* Parameter arg_2 */

/* 3296 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3298 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3300 */	NdrFcShort( 0x4be ),	/* Type Offset=1214 */

	/* Parameter arg_3 */

/* 3302 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3304 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3306 */	NdrFcShort( 0x4ea ),	/* Type Offset=1258 */

	/* Parameter arg_4 */

/* 3308 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 3310 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3312 */	NdrFcShort( 0xc04 ),	/* Type Offset=3076 */

	/* Parameter arg_5 */

/* 3314 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3316 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3318 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_6 */

/* 3320 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3322 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3324 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_7 */

/* 3326 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3328 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3330 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_8 */

/* 3332 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3334 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3336 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3338 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3340 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 3342 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc59_LsarCreateTrustedDomainEx2 */

/* 3344 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3346 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3350 */	NdrFcShort( 0x3b ),	/* 59 */
/* 3352 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3354 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 3356 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3358 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 3360 */	NdrFcShort( 0x2c ),	/* 44 */
/* 3362 */	NdrFcShort( 0x40 ),	/* 64 */
/* 3364 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 3366 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 3368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3370 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3372 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 3374 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 3376 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3378 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 3380 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3382 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3384 */	NdrFcShort( 0x74c ),	/* Type Offset=1868 */

	/* Parameter arg_2 */

/* 3386 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3388 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3390 */	NdrFcShort( 0x80e ),	/* Type Offset=2062 */

	/* Parameter arg_3 */

/* 3392 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3394 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_4 */

/* 3398 */	NdrFcShort( 0x110 ),	/* Flags:  out, simple ref, */
/* 3400 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3402 */	NdrFcShort( 0x404 ),	/* Type Offset=1028 */

	/* Return value */

/* 3404 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3406 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3408 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc60_CredrWrite */

/* 3410 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3412 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3416 */	NdrFcShort( 0x3c ),	/* 60 */
/* 3418 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3420 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3422 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3424 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3426 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3428 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3430 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 3432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3434 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3436 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 3438 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3440 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3442 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 3444 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3446 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3448 */	NdrFcShort( 0xce8 ),	/* Type Offset=3304 */

	/* Parameter arg_2 */

/* 3450 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3452 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3454 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3456 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3458 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3460 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc61_CredrRead */

/* 3462 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3464 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3468 */	NdrFcShort( 0x3d ),	/* 61 */
/* 3470 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3472 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3474 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3476 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3478 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3480 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 3482 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 3484 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3486 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3488 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 3490 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3492 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3494 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 3496 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3498 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3500 */	NdrFcShort( 0xd40 ),	/* Type Offset=3392 */

	/* Parameter arg_2 */

/* 3502 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3504 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3506 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 3508 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3510 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3512 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_4 */

/* 3514 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3516 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3518 */	NdrFcShort( 0xd52 ),	/* Type Offset=3410 */

	/* Return value */

/* 3520 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3522 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3524 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc62_CredrEnumerate */

/* 3526 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3528 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3532 */	NdrFcShort( 0x3e ),	/* 62 */
/* 3534 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3536 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3538 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3540 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3542 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3544 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3546 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 3548 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3550 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3552 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 3554 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3556 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3558 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 3560 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3562 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3564 */	NdrFcShort( 0xd5a ),	/* Type Offset=3418 */

	/* Parameter arg_2 */

/* 3566 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3568 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3570 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 3572 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 3574 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3576 */	NdrFcShort( 0xd9e ),	/* Type Offset=3486 */

	/* Return value */

/* 3578 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3580 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3582 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc63_CredrWriteDomainCredentials */

/* 3584 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3586 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3590 */	NdrFcShort( 0x3f ),	/* 63 */
/* 3592 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3594 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3596 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3598 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3600 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3602 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3604 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 3606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3608 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3610 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 3612 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3614 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3616 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 3618 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3620 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3622 */	NdrFcShort( 0xe4a ),	/* Type Offset=3658 */

	/* Parameter arg_2 */

/* 3624 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3626 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3628 */	NdrFcShort( 0xce8 ),	/* Type Offset=3304 */

	/* Parameter arg_3 */

/* 3630 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3632 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3634 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3636 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3638 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3640 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc64_CredrReadDomainCredentials */

/* 3642 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3644 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3648 */	NdrFcShort( 0x40 ),	/* 64 */
/* 3650 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3652 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3654 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3656 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3658 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3660 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3662 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 3664 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3666 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3668 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 3670 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3672 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3674 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 3676 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3678 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3680 */	NdrFcShort( 0xe4a ),	/* Type Offset=3658 */

	/* Parameter arg_2 */

/* 3682 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3684 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3686 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 3688 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 3690 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3692 */	NdrFcShort( 0xd9e ),	/* Type Offset=3486 */

	/* Return value */

/* 3694 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3696 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3698 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc65_CredrDelete */

/* 3700 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3702 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3706 */	NdrFcShort( 0x41 ),	/* 65 */
/* 3708 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3710 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3712 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3714 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3716 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3718 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3720 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 3722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3724 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3726 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 3728 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3730 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3732 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 3734 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3736 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3738 */	NdrFcShort( 0xeb0 ),	/* Type Offset=3760 */

	/* Parameter arg_2 */

/* 3740 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3742 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3744 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 3746 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3748 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3750 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3752 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3754 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3756 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc66_CredrGetTargetInfo */

/* 3758 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3760 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3764 */	NdrFcShort( 0x42 ),	/* 66 */
/* 3766 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3768 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3770 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3772 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3774 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3776 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3778 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 3780 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3782 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3784 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 3786 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3788 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3790 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 3792 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3794 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3796 */	NdrFcShort( 0xec6 ),	/* Type Offset=3782 */

	/* Parameter arg_2 */

/* 3798 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3800 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3802 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 3804 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3806 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3808 */	NdrFcShort( 0xed8 ),	/* Type Offset=3800 */

	/* Return value */

/* 3810 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3812 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3814 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc67_CredrProfileLoaded */

/* 3816 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3818 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3822 */	NdrFcShort( 0x43 ),	/* 67 */
/* 3824 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3826 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3828 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3832 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3834 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3836 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 3838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3842 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 3844 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3846 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3848 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Return value */

/* 3850 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3852 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3854 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc68_LsarLookupNames3 */

/* 3856 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3858 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3862 */	NdrFcShort( 0x44 ),	/* 68 */
/* 3864 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3866 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 3868 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3870 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 3872 */	NdrFcShort( 0x5e ),	/* 94 */
/* 3874 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3876 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0xa,		/* 10 */
/* 3878 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 3880 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3882 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3884 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 3886 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 3888 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3890 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 3892 */	NdrFcShort( 0x88 ),	/* Flags:  in, by val, */
/* 3894 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3896 */	NdrFcShort( 0xee0 ),	/* 3808 */

	/* Parameter arg_2 */

/* 3898 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3900 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3902 */	NdrFcShort( 0x4be ),	/* Type Offset=1214 */

	/* Parameter arg_3 */

/* 3904 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3906 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3908 */	NdrFcShort( 0x4ea ),	/* Type Offset=1258 */

	/* Parameter arg_4 */

/* 3910 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 3912 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3914 */	NdrFcShort( 0xf2a ),	/* Type Offset=3882 */

	/* Parameter arg_5 */

/* 3916 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3918 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3920 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_6 */

/* 3922 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3924 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3926 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_7 */

/* 3928 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3930 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3932 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_8 */

/* 3934 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3936 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3938 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3940 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3942 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 3944 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc69_CredrGetSessionTypes */

/* 3946 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 3948 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3952 */	NdrFcShort( 0x45 ),	/* 69 */
/* 3954 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3956 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 3958 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 3960 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3962 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3964 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3966 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 3968 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3972 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 3974 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3976 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3978 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 3980 */	NdrFcShort( 0x88 ),	/* Flags:  in, by val, */
/* 3982 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3984 */	NdrFcShort( 0xf3e ),	/* 3902 */

	/* Parameter arg_2 */

/* 3986 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 3988 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3990 */	NdrFcShort( 0xf4c ),	/* Type Offset=3916 */

	/* Return value */

/* 3992 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3994 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3996 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc70_LsarRegisterAuditEvent */

/* 3998 */	0x33,		/* FC_AUTO_HANDLE */
			0x48,		/* Old Flags:  */
/* 4000 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4004 */	NdrFcShort( 0x46 ),	/* 70 */
/* 4006 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4010 */	NdrFcShort( 0x40 ),	/* 64 */
/* 4012 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4014 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 4016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4018 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4020 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 4022 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4024 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 4026 */	NdrFcShort( 0xf8e ),	/* Type Offset=3982 */

	/* Parameter arg_1 */

/* 4028 */	NdrFcShort( 0x110 ),	/* Flags:  out, simple ref, */
/* 4030 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4032 */	NdrFcShort( 0x202 ),	/* Type Offset=514 */

	/* Return value */

/* 4034 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4036 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4038 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc71_LsarGenAuditEvent */

/* 4040 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 4042 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4046 */	NdrFcShort( 0x47 ),	/* 71 */
/* 4048 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4050 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 4052 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 4054 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 4056 */	NdrFcShort( 0x2c ),	/* 44 */
/* 4058 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4060 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4062 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 4064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4066 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4068 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 4070 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 4072 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 4074 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 4076 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4078 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4080 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_2 */

/* 4082 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4084 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4086 */	NdrFcShort( 0x10ae ),	/* Type Offset=4270 */

	/* Return value */

/* 4088 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4090 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4092 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc72_LsarUnregisterAuditEvent */

/* 4094 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 4096 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4100 */	NdrFcShort( 0x48 ),	/* 72 */
/* 4102 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4104 */	0x30,		/* FC_BIND_CONTEXT */
			0xe0,		/* Ctxt flags:  via ptr, in, out, */
/* 4106 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 4108 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 4110 */	NdrFcShort( 0x38 ),	/* 56 */
/* 4112 */	NdrFcShort( 0x40 ),	/* 64 */
/* 4114 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4116 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 4118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4122 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 4124 */	NdrFcShort( 0x118 ),	/* Flags:  in, out, simple ref, */
/* 4126 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 4128 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 4130 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4132 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4134 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc73_LsarQueryForestTrustInformation */

/* 4136 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 4138 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4142 */	NdrFcShort( 0x49 ),	/* 73 */
/* 4144 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4146 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 4148 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 4150 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 4152 */	NdrFcShort( 0x2a ),	/* 42 */
/* 4154 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4156 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 4158 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 4160 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4162 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4164 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 4166 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 4168 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 4170 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 4172 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4174 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4176 */	NdrFcShort( 0x10ea ),	/* Type Offset=4330 */

	/* Parameter arg_2 */

/* 4178 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4180 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4182 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 4184 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 4186 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4188 */	NdrFcShort( 0x1100 ),	/* Type Offset=4352 */

	/* Return value */

/* 4190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4192 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc74_LsarSetForestTrustInformation */

/* 4196 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 4198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4202 */	NdrFcShort( 0x4a ),	/* 74 */
/* 4204 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4206 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 4208 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 4210 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 4212 */	NdrFcShort( 0x2f ),	/* 47 */
/* 4214 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4216 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 4218 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 4220 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4222 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4224 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 4226 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 4228 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 4230 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_1 */

/* 4232 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4234 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4236 */	NdrFcShort( 0x10ea ),	/* Type Offset=4330 */

	/* Parameter arg_2 */

/* 4238 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4240 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4242 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 4244 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4246 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4248 */	NdrFcShort( 0x1218 ),	/* Type Offset=4632 */

	/* Parameter arg_4 */

/* 4250 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4252 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4254 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter arg_5 */

/* 4256 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 4258 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4260 */	NdrFcShort( 0x1230 ),	/* Type Offset=4656 */

	/* Return value */

/* 4262 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4264 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4266 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc75_CredrRename */

/* 4268 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 4270 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4274 */	NdrFcShort( 0x4b ),	/* 75 */
/* 4276 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4278 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 4280 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 4282 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4284 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4286 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 4288 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 4290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4292 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4294 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 4296 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4298 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4300 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 4302 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4304 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4306 */	NdrFcShort( 0x128c ),	/* Type Offset=4748 */

	/* Parameter arg_2 */

/* 4308 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4310 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4312 */	NdrFcShort( 0x12a2 ),	/* Type Offset=4770 */

	/* Parameter arg_3 */

/* 4314 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4316 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4318 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_4 */

/* 4320 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4322 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4324 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4326 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4328 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4330 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc76_LsarLookupSids3 */

/* 4332 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 4334 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4338 */	NdrFcShort( 0x4c ),	/* 76 */
/* 4340 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 4342 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 4344 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 4346 */	NdrFcShort( 0x32 ),	/* 50 */
/* 4348 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4350 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 4352 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 4354 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4356 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4358 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_1 */

/* 4360 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4362 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4364 */	NdrFcShort( 0x588 ),	/* Type Offset=1416 */

	/* Parameter arg_2 */

/* 4366 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 4368 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4370 */	NdrFcShort( 0x4ea ),	/* Type Offset=1258 */

	/* Parameter arg_3 */

/* 4372 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 4374 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4376 */	NdrFcShort( 0xbaa ),	/* Type Offset=2986 */

	/* Parameter arg_4 */

/* 4378 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4380 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4382 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_5 */

/* 4384 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 4386 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4388 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_6 */

/* 4390 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4392 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_7 */

/* 4396 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4398 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4402 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4404 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4406 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc77_LsarLookupNames4 */

/* 4408 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 4410 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4414 */	NdrFcShort( 0x4d ),	/* 77 */
/* 4416 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 4418 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 4420 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 4422 */	NdrFcShort( 0x3a ),	/* 58 */
/* 4424 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4426 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 4428 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 4430 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4432 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4434 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_1 */

/* 4436 */	NdrFcShort( 0x88 ),	/* Flags:  in, by val, */
/* 4438 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4440 */	NdrFcShort( 0x12b4 ),	/* 4788 */

	/* Parameter arg_2 */

/* 4442 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4444 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4446 */	NdrFcShort( 0x4be ),	/* Type Offset=1214 */

	/* Parameter arg_3 */

/* 4448 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 4450 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4452 */	NdrFcShort( 0x4ea ),	/* Type Offset=1258 */

	/* Parameter arg_4 */

/* 4454 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 4456 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4458 */	NdrFcShort( 0xf2a ),	/* Type Offset=3882 */

	/* Parameter arg_5 */

/* 4460 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4462 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4464 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_6 */

/* 4466 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 4468 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4470 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_7 */

/* 4472 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4474 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4476 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_8 */

/* 4478 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4480 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4482 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4484 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4486 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 4488 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc78_LsarOpenPolicySce */

/* 4490 */	0x33,		/* FC_AUTO_HANDLE */
			0x48,		/* Old Flags:  */
/* 4492 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4496 */	NdrFcShort( 0x4e ),	/* 78 */
/* 4498 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4500 */	NdrFcShort( 0x22 ),	/* 34 */
/* 4502 */	NdrFcShort( 0x40 ),	/* 64 */
/* 4504 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 4506 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 4508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4510 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4512 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 4514 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 4516 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 4518 */	NdrFcShort( 0xee ),	/* Type Offset=238 */

	/* Parameter arg_1 */

/* 4520 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4522 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4524 */	NdrFcShort( 0x1c8 ),	/* Type Offset=456 */

	/* Parameter arg_2 */

/* 4526 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4528 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 4532 */	NdrFcShort( 0x110 ),	/* Flags:  out, simple ref, */
/* 4534 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4536 */	NdrFcShort( 0x202 ),	/* Type Offset=514 */

	/* Return value */

/* 4538 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4540 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4542 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc79_LsarAdtRegisterSecurityEventSource */

/* 4544 */	0x33,		/* FC_AUTO_HANDLE */
			0x48,		/* Old Flags:  */
/* 4546 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4550 */	NdrFcShort( 0x4f ),	/* 79 */
/* 4552 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4554 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4556 */	NdrFcShort( 0x40 ),	/* 64 */
/* 4558 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4560 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 4562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4566 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 4568 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4570 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 4572 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_1 */

/* 4574 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4576 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4578 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_2 */

/* 4580 */	NdrFcShort( 0x110 ),	/* Flags:  out, simple ref, */
/* 4582 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4584 */	NdrFcShort( 0x202 ),	/* Type Offset=514 */

	/* Return value */

/* 4586 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4588 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4590 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc80_LsarAdtUnregisterSecurityEventSource */

/* 4592 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 4594 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4598 */	NdrFcShort( 0x50 ),	/* 80 */
/* 4600 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4602 */	0x30,		/* FC_BIND_CONTEXT */
			0xe0,		/* Ctxt flags:  via ptr, in, out, */
/* 4604 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4606 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 4608 */	NdrFcShort( 0x40 ),	/* 64 */
/* 4610 */	NdrFcShort( 0x40 ),	/* 64 */
/* 4612 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 4614 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 4616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4620 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 4622 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4624 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 4626 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_1 */

/* 4628 */	NdrFcShort( 0x118 ),	/* Flags:  in, out, simple ref, */
/* 4630 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4632 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 4634 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4636 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4638 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc81_LsarAdtReportSecurityEvent */

/* 4640 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 4642 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4646 */	NdrFcShort( 0x51 ),	/* 81 */
/* 4648 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4650 */	0x30,		/* FC_BIND_CONTEXT */
			0x40,		/* Ctxt flags:  in, */
/* 4652 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4654 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 4656 */	NdrFcShort( 0x34 ),	/* 52 */
/* 4658 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4660 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 4662 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 4664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4666 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4668 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 4670 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4672 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 4674 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_1 */

/* 4676 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 4678 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4680 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter arg_2 */

/* 4682 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4684 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4686 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 4688 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4690 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4692 */	NdrFcShort( 0x158 ),	/* Type Offset=344 */

	/* Parameter arg_4 */

/* 4694 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4696 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4698 */	NdrFcShort( 0x10ae ),	/* Type Offset=4270 */

	/* Return value */

/* 4700 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4702 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4704 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc82_CredrFindBestCredential */

/* 4706 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 4708 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4712 */	NdrFcShort( 0x52 ),	/* 82 */
/* 4714 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4716 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 4718 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 4720 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4722 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4724 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 4726 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 4728 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4730 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4732 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 4734 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4736 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4738 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 4740 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4742 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4744 */	NdrFcShort( 0x12c2 ),	/* Type Offset=4802 */

	/* Parameter arg_2 */

/* 4746 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4748 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4750 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 4752 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4754 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4756 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_4 */

/* 4758 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 4760 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4762 */	NdrFcShort( 0xd52 ),	/* Type Offset=3410 */

	/* Return value */

/* 4764 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4766 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4768 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc83_LsarSetAuditPolicy */

/* 4770 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 4772 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4776 */	NdrFcShort( 0x53 ),	/* 83 */
/* 4778 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4780 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 4782 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 4784 */	NdrFcShort( 0x4c ),	/* 76 */
/* 4786 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4788 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 4790 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 4792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4794 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4796 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 4798 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4800 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4802 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 4804 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4806 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4808 */	NdrFcShort( 0xff2 ),	/* Type Offset=4082 */

	/* Parameter arg_2 */

/* 4810 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 4812 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4814 */	NdrFcShort( 0xff6 ),	/* Type Offset=4086 */

	/* Parameter arg_3 */

/* 4816 */	NdrFcShort( 0x88 ),	/* Flags:  in, by val, */
/* 4818 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4820 */	NdrFcShort( 0x12d4 ),	/* 4820 */

	/* Parameter arg_4 */

/* 4822 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4824 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4826 */	NdrFcShort( 0x12f0 ),	/* Type Offset=4848 */

	/* Return value */

/* 4828 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4830 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc84_LsarQueryAuditPolicy */

/* 4834 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 4836 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4840 */	NdrFcShort( 0x54 ),	/* 84 */
/* 4842 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4844 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 4846 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 4848 */	NdrFcShort( 0x4c ),	/* 76 */
/* 4850 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4852 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 4854 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 4856 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4858 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4860 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 4862 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4864 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4866 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 4868 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4870 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4872 */	NdrFcShort( 0xff2 ),	/* Type Offset=4082 */

	/* Parameter arg_2 */

/* 4874 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 4876 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4878 */	NdrFcShort( 0xff6 ),	/* Type Offset=4086 */

	/* Parameter arg_3 */

/* 4880 */	NdrFcShort( 0x88 ),	/* Flags:  in, by val, */
/* 4882 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4884 */	NdrFcShort( 0x130a ),	/* 4874 */

	/* Parameter arg_4 */

/* 4886 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4888 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4890 */	NdrFcShort( 0x1318 ),	/* Type Offset=4888 */

	/* Parameter arg_5 */

/* 4892 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 4894 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4896 */	NdrFcShort( 0x1336 ),	/* Type Offset=4918 */

	/* Return value */

/* 4898 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4900 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4902 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc85_LsarEnumerateAuditPolicy */

/* 4904 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 4906 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4910 */	NdrFcShort( 0x55 ),	/* 85 */
/* 4912 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4914 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 4916 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 4918 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4920 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4922 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4924 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 4926 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4930 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 4932 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4934 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4936 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 4938 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 4940 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4942 */	NdrFcShort( 0x1360 ),	/* Type Offset=4960 */

	/* Return value */

/* 4944 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4946 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4948 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc86_LsarEnumerateAuditCategories */

/* 4950 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 4952 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4956 */	NdrFcShort( 0x56 ),	/* 86 */
/* 4958 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4960 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 4962 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 4964 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4966 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4968 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4970 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 4972 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4974 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4976 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 4978 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4980 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4982 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 4984 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 4986 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4988 */	NdrFcShort( 0x13a6 ),	/* Type Offset=5030 */

	/* Return value */

/* 4990 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4992 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4994 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc87_LsarEnumerateAuditSubCategories */

/* 4996 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 4998 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5002 */	NdrFcShort( 0x57 ),	/* 87 */
/* 5004 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5006 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 5008 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 5010 */	NdrFcShort( 0x49 ),	/* 73 */
/* 5012 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5014 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 5016 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 5018 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5022 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 5024 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5026 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5028 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 5030 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 5032 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5034 */	NdrFcShort( 0xff6 ),	/* Type Offset=4086 */

	/* Parameter arg_2 */

/* 5036 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5038 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5040 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 5042 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 5044 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5046 */	NdrFcShort( 0x13a6 ),	/* Type Offset=5030 */

	/* Return value */

/* 5048 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5050 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5052 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc88_LsarLookupAuditCategoryName */

/* 5054 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 5056 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5060 */	NdrFcShort( 0x58 ),	/* 88 */
/* 5062 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5064 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 5066 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 5068 */	NdrFcShort( 0x44 ),	/* 68 */
/* 5070 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5072 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 5074 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 5076 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5078 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5080 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 5082 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5084 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5086 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 5088 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 5090 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5092 */	NdrFcShort( 0x374 ),	/* Type Offset=884 */

	/* Parameter arg_2 */

/* 5094 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 5096 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5098 */	NdrFcShort( 0x90c ),	/* Type Offset=2316 */

	/* Return value */

/* 5100 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5102 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc89_LsarLookupAuditSubCategoryName */

/* 5106 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 5108 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5112 */	NdrFcShort( 0x59 ),	/* 89 */
/* 5114 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5116 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 5118 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 5120 */	NdrFcShort( 0x44 ),	/* 68 */
/* 5122 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5124 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 5126 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 5128 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5132 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 5134 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5136 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5138 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 5140 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 5142 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5144 */	NdrFcShort( 0x374 ),	/* Type Offset=884 */

	/* Parameter arg_2 */

/* 5146 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 5148 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5150 */	NdrFcShort( 0x90c ),	/* Type Offset=2316 */

	/* Return value */

/* 5152 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5154 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc90_LsarSetAuditSecurity */

/* 5158 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 5160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5164 */	NdrFcShort( 0x5a ),	/* 90 */
/* 5166 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5168 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 5170 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 5172 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5174 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5176 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 5178 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 5180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5182 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5184 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 5186 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5188 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5190 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 5192 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5194 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5196 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_2 */

/* 5198 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5200 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5202 */	NdrFcShort( 0xbc ),	/* Type Offset=188 */

	/* Return value */

/* 5204 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5206 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5208 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc91_LsarQueryAuditSecurity */

/* 5210 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 5212 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5216 */	NdrFcShort( 0x5b ),	/* 91 */
/* 5218 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5220 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 5222 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 5224 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5226 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5228 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 5230 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 5232 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5236 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 5238 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5240 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5242 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 5244 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5246 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5248 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_2 */

/* 5250 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 5252 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5254 */	NdrFcShort( 0x9e ),	/* Type Offset=158 */

	/* Return value */

/* 5256 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5258 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5260 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc92_CredrReadByTokenHandle */

/* 5262 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 5264 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5268 */	NdrFcShort( 0x5c ),	/* 92 */
/* 5270 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 5272 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 5274 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 5276 */	NdrFcShort( 0x20 ),	/* 32 */
/* 5278 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5280 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 5282 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 5284 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5286 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5288 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 5290 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5292 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5294 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 5296 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5298 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5300 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_2 */

/* 5302 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5304 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5306 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 5308 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5310 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5312 */	NdrFcShort( 0x13e4 ),	/* Type Offset=5092 */

	/* Parameter arg_4 */

/* 5314 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5316 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5318 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_5 */

/* 5320 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5322 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5324 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_6 */

/* 5326 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 5328 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 5330 */	NdrFcShort( 0xd52 ),	/* Type Offset=3410 */

	/* Return value */

/* 5332 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5334 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 5336 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc93_CredrRestoreCredentials */

/* 5338 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 5340 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5344 */	NdrFcShort( 0x5d ),	/* 93 */
/* 5346 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 5348 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 5350 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 5352 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5354 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5356 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 5358 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 5360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5362 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5364 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 5366 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5368 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5370 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 5372 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5374 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5376 */	NdrFcShort( 0x13f6 ),	/* Type Offset=5110 */

	/* Parameter arg_2 */

/* 5378 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5380 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5382 */	NdrFcShort( 0x140c ),	/* Type Offset=5132 */

	/* Parameter arg_3 */

/* 5384 */	NdrFcShort( 0x88 ),	/* Flags:  in, by val, */
/* 5386 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5388 */	NdrFcShort( 0x1426 ),	/* 5158 */

	/* Parameter arg_4 */

/* 5390 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5392 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5396 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5398 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc94_CredrBackupCredentials */

/* 5402 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 5404 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5408 */	NdrFcShort( 0x5e ),	/* 94 */
/* 5410 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 5412 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 5414 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 5416 */	NdrFcShort( 0x20 ),	/* 32 */
/* 5418 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5420 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 5422 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 5424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5426 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5428 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 5430 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5432 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5434 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 5436 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5438 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5440 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_2 */

/* 5442 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5444 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5446 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 5448 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5450 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5452 */	NdrFcShort( 0x1430 ),	/* Type Offset=5168 */

	/* Parameter arg_4 */

/* 5454 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5456 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5458 */	NdrFcShort( 0x1446 ),	/* Type Offset=5190 */

	/* Parameter arg_5 */

/* 5460 */	NdrFcShort( 0x88 ),	/* Flags:  in, by val, */
/* 5462 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5464 */	NdrFcShort( 0x1460 ),	/* 5216 */

	/* Parameter arg_6 */

/* 5466 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5468 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 5470 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5472 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5474 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 5476 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc95_LsarManageSidNameMapping */

/* 5478 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 5480 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5484 */	NdrFcShort( 0x5f ),	/* 95 */
/* 5486 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5488 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 5490 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 5492 */	NdrFcShort( 0x6 ),	/* 6 */
/* 5494 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5496 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 5498 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 5500 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5502 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5504 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 5506 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5508 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5510 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 5512 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5514 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5516 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter arg_2 */

/* 5518 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5520 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5522 */	NdrFcShort( 0x146e ),	/* Type Offset=5230 */

	/* Parameter arg_3 */

/* 5524 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 5526 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5528 */	NdrFcShort( 0x1560 ),	/* Type Offset=5472 */

	/* Return value */

/* 5530 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5532 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5534 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc96_CredrProfileUnloaded */

/* 5536 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 5538 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5542 */	NdrFcShort( 0x60 ),	/* 96 */
/* 5544 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5546 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 5548 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 5550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5552 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5554 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 5556 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 5558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5562 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 5564 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5566 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5568 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Return value */

/* 5570 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5572 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5574 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc97_CredrRename */

/* 5576 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 5578 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5582 */	NdrFcShort( 0x61 ),	/* 97 */
/* 5584 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 5586 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 5588 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 5590 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5592 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5594 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 5596 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 5598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5600 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5602 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 5604 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5606 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5608 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 5610 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5612 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5614 */	NdrFcShort( 0x1598 ),	/* Type Offset=5528 */

	/* Parameter arg_2 */

/* 5616 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5618 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5620 */	NdrFcShort( 0x15aa ),	/* Type Offset=5546 */

	/* Parameter arg_3 */

/* 5622 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5624 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5626 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_4 */

/* 5628 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5630 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5632 */	NdrFcShort( 0x15c4 ),	/* Type Offset=5572 */

	/* Parameter arg_5 */

/* 5634 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5636 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5638 */	NdrFcShort( 0x15da ),	/* Type Offset=5594 */

	/* Parameter arg_6 */

/* 5640 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5642 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 5644 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5646 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5648 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 5650 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc98_CredrRename */

/* 5652 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 5654 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5658 */	NdrFcShort( 0x62 ),	/* 98 */
/* 5660 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 5662 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 5664 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 5666 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5668 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5670 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 5672 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 5674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5676 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5678 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 5680 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5682 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5684 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 5686 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5688 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5690 */	NdrFcShort( 0x15f4 ),	/* Type Offset=5620 */

	/* Parameter arg_2 */

/* 5692 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5694 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5696 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 5698 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5700 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5702 */	NdrFcShort( 0x1606 ),	/* Type Offset=5638 */

	/* Parameter arg_4 */

/* 5704 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5706 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5708 */	NdrFcShort( 0x161c ),	/* Type Offset=5660 */

	/* Parameter arg_5 */

/* 5710 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5712 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5714 */	NdrFcShort( 0x1632 ),	/* Type Offset=5682 */

	/* Parameter arg_6 */

/* 5716 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5718 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 5720 */	NdrFcShort( 0x1648 ),	/* Type Offset=5704 */

	/* Return value */

/* 5722 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5724 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 5726 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc99_CredrRename */

/* 5728 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 5730 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5734 */	NdrFcShort( 0x63 ),	/* 99 */
/* 5736 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 5738 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 5740 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 5742 */	NdrFcShort( 0x20 ),	/* 32 */
/* 5744 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5746 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0xa,		/* 10 */
/* 5748 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 5750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5752 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5754 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 5756 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5758 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5760 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 5762 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5764 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5766 */	NdrFcShort( 0x165e ),	/* Type Offset=5726 */

	/* Parameter arg_2 */

/* 5768 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5770 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5772 */	NdrFcShort( 0x1678 ),	/* Type Offset=5752 */

	/* Parameter arg_3 */

/* 5774 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5776 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5778 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_4 */

/* 5780 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5782 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5784 */	NdrFcShort( 0x168a ),	/* Type Offset=5770 */

	/* Parameter arg_5 */

/* 5786 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5788 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_6 */

/* 5792 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5794 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 5796 */	NdrFcShort( 0x16a4 ),	/* Type Offset=5796 */

	/* Parameter arg_7 */

/* 5798 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5800 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 5802 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_8 */

/* 5804 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5806 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 5808 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5810 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5812 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 5814 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc100_CredrRename */

/* 5816 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 5818 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5822 */	NdrFcShort( 0x64 ),	/* 100 */
/* 5824 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 5826 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 5828 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 5830 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5832 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5834 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 5836 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 5838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5840 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5842 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 5844 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5846 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5848 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 5850 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5852 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5854 */	NdrFcShort( 0x16be ),	/* Type Offset=5822 */

	/* Parameter arg_2 */

/* 5856 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5858 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5860 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_3 */

/* 5862 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5864 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5866 */	NdrFcShort( 0x16d0 ),	/* Type Offset=5840 */

	/* Parameter arg_4 */

/* 5868 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5870 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5872 */	NdrFcShort( 0x16e6 ),	/* Type Offset=5862 */

	/* Parameter arg_5 */

/* 5874 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5876 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5878 */	NdrFcShort( 0x16fc ),	/* Type Offset=5884 */

	/* Return value */

/* 5880 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5882 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 5884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc101_CredrRename */

/* 5886 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 5888 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5892 */	NdrFcShort( 0x65 ),	/* 101 */
/* 5894 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5896 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 5898 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 5900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5902 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5904 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 5906 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 5908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5910 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5912 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 5914 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5916 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5918 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 5920 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5922 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5924 */	NdrFcShort( 0x1716 ),	/* Type Offset=5910 */

	/* Parameter arg_2 */

/* 5926 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5928 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5930 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5932 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5934 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5936 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc102_LsarEfsGetSmartcardCredentials */

/* 5938 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 5940 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5944 */	NdrFcShort( 0x66 ),	/* 102 */
/* 5946 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 5948 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 5950 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 5952 */	NdrFcShort( 0x2c ),	/* 44 */
/* 5954 */	NdrFcShort( 0x40 ),	/* 64 */
/* 5956 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 5958 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 5960 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5964 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 5966 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5968 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5970 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 5972 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 5974 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5976 */	NdrFcShort( 0x16 ),	/* Type Offset=22 */

	/* Parameter arg_2 */

/* 5978 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 5980 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5982 */	NdrFcShort( 0x1728 ),	/* Type Offset=5928 */

	/* Parameter arg_3 */

/* 5984 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5986 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5988 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter arg_4 */

/* 5990 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 5992 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5994 */	NdrFcShort( 0x1746 ),	/* Type Offset=5958 */

	/* Parameter arg_5 */

/* 5996 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5998 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6000 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6002 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6004 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 6006 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc103_LsarAuditSetGlobalSacl */

/* 6008 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 6010 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6014 */	NdrFcShort( 0x67 ),	/* 103 */
/* 6016 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 6018 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 6020 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 6022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6024 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6026 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 6028 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 6030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6032 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6034 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 6036 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 6038 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6040 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 6042 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 6044 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6046 */	NdrFcShort( 0x10ea ),	/* Type Offset=4330 */

	/* Parameter arg_2 */

/* 6048 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 6050 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6052 */	NdrFcShort( 0xbc ),	/* Type Offset=188 */

	/* Return value */

/* 6054 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6056 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6058 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc104_LsarAuditQueryGlobalSacl */

/* 6060 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 6062 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6066 */	NdrFcShort( 0x68 ),	/* 104 */
/* 6068 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 6070 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 6072 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 6074 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6076 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6078 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 6080 */	0x8,		/* 8 */
			0x47,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, has range on conformance */
/* 6082 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6084 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6086 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 6088 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 6090 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6092 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 6094 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 6096 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6098 */	NdrFcShort( 0x10ea ),	/* Type Offset=4330 */

	/* Parameter arg_2 */

/* 6100 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 6102 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6104 */	NdrFcShort( 0xbc ),	/* Type Offset=188 */

	/* Return value */

/* 6106 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6108 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc105_CredrProfileLoadedEx */

/* 6112 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 6114 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6118 */	NdrFcShort( 0x69 ),	/* 105 */
/* 6120 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6122 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 6124 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 6126 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6128 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6130 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 6132 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 6134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6138 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 6140 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 6142 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6144 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 6146 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6148 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6152 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6154 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc106_LsarInteractiveSessionIsLoggedOff */

/* 6158 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 6160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6164 */	NdrFcShort( 0x6a ),	/* 106 */
/* 6166 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6168 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 6170 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 6172 */	NdrFcShort( 0x2c ),	/* 44 */
/* 6174 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6176 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 6178 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 6180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6184 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 6186 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 6188 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6190 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 6192 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 6194 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6196 */	NdrFcShort( 0x16 ),	/* Type Offset=22 */

	/* Return value */

/* 6198 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6200 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc107_LsarConfigureAutoLogonCredentials */

/* 6204 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 6206 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6210 */	NdrFcShort( 0x6b ),	/* 107 */
/* 6212 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6214 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 6216 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 6218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6220 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6222 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 6224 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 6226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6230 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 6232 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 6234 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6236 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Return value */

/* 6238 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6240 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6242 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Proc108_LsarGetDeviceRegistrationInfo */

/* 6244 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 6246 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6250 */	NdrFcShort( 0x6c ),	/* 108 */
/* 6252 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6254 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 6256 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 6258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6260 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6262 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 6264 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 6266 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6270 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg_0 */

/* 6272 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 6274 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6276 */	NdrFcShort( 0x998 ),	/* Type Offset=2456 */

	/* Parameter arg_1 */

/* 6278 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 6280 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6282 */	NdrFcShort( 0x1768 ),	/* Type Offset=5992 */

	/* Return value */

/* 6284 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6286 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6288 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const rpc_MIDL_TYPE_FORMAT_STRING rpc__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/*  4 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6) */
/*  6 */	0x30,		/* FC_BIND_CONTEXT */
			0xe1,		/* Ctxt flags:  via ptr, in, out, can't be null */
/*  8 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 10 */	0x30,		/* FC_BIND_CONTEXT */
			0x41,		/* Ctxt flags:  in, can't be null */
/* 12 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 14 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 16 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 18 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 20 */	NdrFcShort( 0x76 ),	/* Offset= 118 (138) */
/* 22 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 24 */	NdrFcShort( 0x8 ),	/* 8 */
/* 26 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 28 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 30 */	
			0x1c,		/* FC_CVARRAY */
			0x1,		/* 1 */
/* 32 */	NdrFcShort( 0x2 ),	/* 2 */
/* 34 */	0x16,		/* Corr desc:  field pointer, FC_SHORT */
			0x55,		/* FC_DIV_2 */
/* 36 */	NdrFcShort( 0x2 ),	/* 2 */
/* 38 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 40 */	0x0 , 
			0x0,		/* 0 */
/* 42 */	NdrFcLong( 0x0 ),	/* 0 */
/* 46 */	NdrFcLong( 0x0 ),	/* 0 */
/* 50 */	0x16,		/* Corr desc:  field pointer, FC_SHORT */
			0x55,		/* FC_DIV_2 */
/* 52 */	NdrFcShort( 0x0 ),	/* 0 */
/* 54 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 56 */	0x0 , 
			0x0,		/* 0 */
/* 58 */	NdrFcLong( 0x0 ),	/* 0 */
/* 62 */	NdrFcLong( 0x0 ),	/* 0 */
/* 66 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 68 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 70 */	NdrFcShort( 0x10 ),	/* 16 */
/* 72 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 74 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 76 */	NdrFcShort( 0x4 ),	/* 4 */
/* 78 */	NdrFcShort( 0x4 ),	/* 4 */
/* 80 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 82 */	NdrFcShort( 0xffcc ),	/* Offset= -52 (30) */
/* 84 */	
			0x5b,		/* FC_END */

			0x6,		/* FC_SHORT */
/* 86 */	0x6,		/* FC_SHORT */
			0x8,		/* FC_LONG */
/* 88 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 90 */	NdrFcShort( 0xffbc ),	/* Offset= -68 (22) */
/* 92 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 94 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 96 */	NdrFcShort( 0x10 ),	/* 16 */
/* 98 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 102 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 104 */	0x0 , 
			0x0,		/* 0 */
/* 106 */	NdrFcLong( 0x0 ),	/* 0 */
/* 110 */	NdrFcLong( 0x0 ),	/* 0 */
/* 114 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 116 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 118 */	NdrFcShort( 0x10 ),	/* 16 */
/* 120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 122 */	NdrFcShort( 0x1 ),	/* 1 */
/* 124 */	NdrFcShort( 0x4 ),	/* 4 */
/* 126 */	NdrFcShort( 0x4 ),	/* 4 */
/* 128 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 130 */	NdrFcShort( 0xff9c ),	/* Offset= -100 (30) */
/* 132 */	
			0x5b,		/* FC_END */

			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 134 */	0x0,		/* 0 */
			NdrFcShort( 0xffbd ),	/* Offset= -67 (68) */
			0x5b,		/* FC_END */
/* 138 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 140 */	NdrFcShort( 0x8 ),	/* 8 */
/* 142 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 144 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 146 */	NdrFcShort( 0x4 ),	/* 4 */
/* 148 */	NdrFcShort( 0x4 ),	/* 4 */
/* 150 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 152 */	NdrFcShort( 0xffc6 ),	/* Offset= -58 (94) */
/* 154 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 156 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 158 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 160 */	NdrFcShort( 0x2 ),	/* Offset= 2 (162) */
/* 162 */	
			0x12, 0x0,	/* FC_UP */
/* 164 */	NdrFcShort( 0x18 ),	/* Offset= 24 (188) */
/* 166 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 168 */	NdrFcShort( 0x1 ),	/* 1 */
/* 170 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 174 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 176 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 178 */	NdrFcLong( 0x0 ),	/* 0 */
/* 182 */	NdrFcLong( 0x40000 ),	/* 262144 */
/* 186 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 188 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 190 */	NdrFcShort( 0x8 ),	/* 8 */
/* 192 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 194 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 196 */	NdrFcShort( 0x4 ),	/* 4 */
/* 198 */	NdrFcShort( 0x4 ),	/* 4 */
/* 200 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 202 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (166) */
/* 204 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 206 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 208 */	
			0x11, 0x0,	/* FC_RP */
/* 210 */	NdrFcShort( 0xffea ),	/* Offset= -22 (188) */
/* 212 */	
			0x11, 0x0,	/* FC_RP */
/* 214 */	NdrFcShort( 0x2 ),	/* Offset= 2 (216) */
/* 216 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 218 */	NdrFcShort( 0x8 ),	/* 8 */
/* 220 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 222 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 224 */	NdrFcShort( 0x4 ),	/* 4 */
/* 226 */	NdrFcShort( 0x4 ),	/* 4 */
/* 228 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 230 */	NdrFcShort( 0xff38 ),	/* Offset= -200 (30) */
/* 232 */	
			0x5b,		/* FC_END */

			0x6,		/* FC_SHORT */
/* 234 */	0x6,		/* FC_SHORT */
			0x8,		/* FC_LONG */
/* 236 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 238 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 240 */	0x5,		/* FC_WCHAR */
			0x5c,		/* FC_PAD */
/* 242 */	
			0x11, 0x0,	/* FC_RP */
/* 244 */	NdrFcShort( 0xd4 ),	/* Offset= 212 (456) */
/* 246 */	
			0x1c,		/* FC_CVARRAY */
			0x0,		/* 0 */
/* 248 */	NdrFcShort( 0x1 ),	/* 1 */
/* 250 */	0x16,		/* Corr desc:  field pointer, FC_SHORT */
			0x0,		/*  */
/* 252 */	NdrFcShort( 0x2 ),	/* 2 */
/* 254 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 256 */	0x0 , 
			0x0,		/* 0 */
/* 258 */	NdrFcLong( 0x0 ),	/* 0 */
/* 262 */	NdrFcLong( 0x0 ),	/* 0 */
/* 266 */	0x16,		/* Corr desc:  field pointer, FC_SHORT */
			0x0,		/*  */
/* 268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 270 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 272 */	0x0 , 
			0x0,		/* 0 */
/* 274 */	NdrFcLong( 0x0 ),	/* 0 */
/* 278 */	NdrFcLong( 0x0 ),	/* 0 */
/* 282 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 284 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 286 */	NdrFcShort( 0x8 ),	/* 8 */
/* 288 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 290 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 292 */	NdrFcShort( 0x4 ),	/* 4 */
/* 294 */	NdrFcShort( 0x4 ),	/* 4 */
/* 296 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 298 */	NdrFcShort( 0xffcc ),	/* Offset= -52 (246) */
/* 300 */	
			0x5b,		/* FC_END */

			0x6,		/* FC_SHORT */
/* 302 */	0x6,		/* FC_SHORT */
			0x8,		/* FC_LONG */
/* 304 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 306 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 308 */	NdrFcShort( 0x6 ),	/* 6 */
/* 310 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 312 */	
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 314 */	NdrFcShort( 0x6 ),	/* 6 */
/* 316 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 318 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (306) */
/* 320 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 322 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 324 */	NdrFcShort( 0x4 ),	/* 4 */
/* 326 */	0x4,		/* Corr desc: FC_USMALL */
			0x0,		/*  */
/* 328 */	NdrFcShort( 0xfff9 ),	/* -7 */
/* 330 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 332 */	0x0 , 
			0x0,		/* 0 */
/* 334 */	NdrFcLong( 0x0 ),	/* 0 */
/* 338 */	NdrFcLong( 0x0 ),	/* 0 */
/* 342 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 344 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 346 */	NdrFcShort( 0x8 ),	/* 8 */
/* 348 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (322) */
/* 350 */	0x2,		/* FC_CHAR */
			0x2,		/* FC_CHAR */
/* 352 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 354 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (312) */
/* 356 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 358 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 360 */	NdrFcShort( 0x1 ),	/* 1 */
/* 362 */	0x0,		/* Corr desc:  field,  */
			0x5d,		/* FC_EXPR */
/* 364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 366 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 368 */	0x0 , 
			0x0,		/* 0 */
/* 370 */	NdrFcLong( 0x0 ),	/* 0 */
/* 374 */	NdrFcLong( 0x0 ),	/* 0 */
/* 378 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 380 */	
			0x17,		/* FC_CSTRUCT */
			0x1,		/* 1 */
/* 382 */	NdrFcShort( 0x4 ),	/* 4 */
/* 384 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (358) */
/* 386 */	0x2,		/* FC_CHAR */
			0x2,		/* FC_CHAR */
/* 388 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 390 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 392 */	NdrFcShort( 0x14 ),	/* 20 */
/* 394 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 396 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 398 */	NdrFcShort( 0x4 ),	/* 4 */
/* 400 */	NdrFcShort( 0x4 ),	/* 4 */
/* 402 */	0x12, 0x0,	/* FC_UP */
/* 404 */	NdrFcShort( 0xffc4 ),	/* Offset= -60 (344) */
/* 406 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 408 */	NdrFcShort( 0x8 ),	/* 8 */
/* 410 */	NdrFcShort( 0x8 ),	/* 8 */
/* 412 */	0x12, 0x0,	/* FC_UP */
/* 414 */	NdrFcShort( 0xffba ),	/* Offset= -70 (344) */
/* 416 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 418 */	NdrFcShort( 0xc ),	/* 12 */
/* 420 */	NdrFcShort( 0xc ),	/* 12 */
/* 422 */	0x12, 0x0,	/* FC_UP */
/* 424 */	NdrFcShort( 0xffd4 ),	/* Offset= -44 (380) */
/* 426 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 428 */	NdrFcShort( 0x10 ),	/* 16 */
/* 430 */	NdrFcShort( 0x10 ),	/* 16 */
/* 432 */	0x12, 0x0,	/* FC_UP */
/* 434 */	NdrFcShort( 0xffca ),	/* Offset= -54 (380) */
/* 436 */	
			0x5b,		/* FC_END */

			0x2,		/* FC_CHAR */
/* 438 */	0x2,		/* FC_CHAR */
			0x6,		/* FC_SHORT */
/* 440 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 442 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 444 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 446 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 448 */	NdrFcShort( 0x8 ),	/* 8 */
/* 450 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 452 */	0x2,		/* FC_CHAR */
			0x2,		/* FC_CHAR */
/* 454 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 456 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 458 */	NdrFcShort( 0x18 ),	/* 24 */
/* 460 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 462 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 464 */	NdrFcShort( 0x4 ),	/* 4 */
/* 466 */	NdrFcShort( 0x4 ),	/* 4 */
/* 468 */	0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 470 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 472 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 474 */	NdrFcShort( 0x8 ),	/* 8 */
/* 476 */	NdrFcShort( 0x8 ),	/* 8 */
/* 478 */	0x12, 0x0,	/* FC_UP */
/* 480 */	NdrFcShort( 0xff3c ),	/* Offset= -196 (284) */
/* 482 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 484 */	NdrFcShort( 0x10 ),	/* 16 */
/* 486 */	NdrFcShort( 0x10 ),	/* 16 */
/* 488 */	0x12, 0x0,	/* FC_UP */
/* 490 */	NdrFcShort( 0xff9c ),	/* Offset= -100 (390) */
/* 492 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 494 */	NdrFcShort( 0x14 ),	/* 20 */
/* 496 */	NdrFcShort( 0x14 ),	/* 20 */
/* 498 */	0x12, 0x0,	/* FC_UP */
/* 500 */	NdrFcShort( 0xffca ),	/* Offset= -54 (446) */
/* 502 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 504 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 506 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 508 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 510 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 512 */	NdrFcShort( 0x2 ),	/* Offset= 2 (514) */
/* 514 */	0x30,		/* FC_BIND_CONTEXT */
			0xa0,		/* Ctxt flags:  via ptr, out, */
/* 516 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 518 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 520 */	NdrFcShort( 0x2 ),	/* Offset= 2 (522) */
/* 522 */	
			0x12, 0x0,	/* FC_UP */
/* 524 */	NdrFcShort( 0x2 ),	/* Offset= 2 (526) */
/* 526 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x6,		/* FC_SHORT */
/* 528 */	0x26,		/* Corr desc:  parameter, FC_SHORT */
			0x0,		/*  */
/* 530 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 532 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 534 */	0x0 , 
			0x0,		/* 0 */
/* 536 */	NdrFcLong( 0x0 ),	/* 0 */
/* 540 */	NdrFcLong( 0x0 ),	/* 0 */
/* 544 */	NdrFcShort( 0x2 ),	/* Offset= 2 (546) */
/* 546 */	NdrFcShort( 0x30 ),	/* 48 */
/* 548 */	NdrFcShort( 0xe ),	/* 14 */
/* 550 */	NdrFcLong( 0x1 ),	/* 1 */
/* 554 */	NdrFcShort( 0x58 ),	/* Offset= 88 (642) */
/* 556 */	NdrFcLong( 0x2 ),	/* 2 */
/* 560 */	NdrFcShort( 0x80 ),	/* Offset= 128 (688) */
/* 562 */	NdrFcLong( 0x3 ),	/* 3 */
/* 566 */	NdrFcShort( 0x8c ),	/* Offset= 140 (706) */
/* 568 */	NdrFcLong( 0x5 ),	/* 5 */
/* 572 */	NdrFcShort( 0x86 ),	/* Offset= 134 (706) */
/* 574 */	NdrFcLong( 0x4 ),	/* 4 */
/* 578 */	NdrFcShort( 0xfe96 ),	/* Offset= -362 (216) */
/* 580 */	NdrFcLong( 0x6 ),	/* 6 */
/* 584 */	NdrFcShort( 0x9a ),	/* Offset= 154 (738) */
/* 586 */	NdrFcLong( 0x7 ),	/* 7 */
/* 590 */	NdrFcShort( 0xc0 ),	/* Offset= 192 (782) */
/* 592 */	NdrFcLong( 0x8 ),	/* 8 */
/* 596 */	NdrFcShort( 0xf0 ),	/* Offset= 240 (836) */
/* 598 */	NdrFcLong( 0x9 ),	/* 9 */
/* 602 */	NdrFcShort( 0xf8 ),	/* Offset= 248 (850) */
/* 604 */	NdrFcLong( 0xa ),	/* 10 */
/* 608 */	NdrFcShort( 0x100 ),	/* Offset= 256 (864) */
/* 610 */	NdrFcLong( 0xb ),	/* 11 */
/* 614 */	NdrFcShort( 0x100 ),	/* Offset= 256 (870) */
/* 616 */	NdrFcLong( 0xc ),	/* 12 */
/* 620 */	NdrFcShort( 0x13a ),	/* Offset= 314 (934) */
/* 622 */	NdrFcLong( 0xd ),	/* 13 */
/* 626 */	NdrFcShort( 0x134 ),	/* Offset= 308 (934) */
/* 628 */	NdrFcLong( 0xe ),	/* 14 */
/* 632 */	NdrFcShort( 0x4a ),	/* Offset= 74 (706) */
/* 634 */	NdrFcShort( 0xffff ),	/* Offset= -1 (633) */
/* 636 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 638 */	NdrFcShort( 0x8 ),	/* 8 */
/* 640 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 642 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 644 */	NdrFcShort( 0x28 ),	/* 40 */
/* 646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 648 */	NdrFcShort( 0x0 ),	/* Offset= 0 (648) */
/* 650 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 652 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 654 */	NdrFcShort( 0xffee ),	/* Offset= -18 (636) */
/* 656 */	0x2,		/* FC_CHAR */
			0x43,		/* FC_STRUCTPAD7 */
/* 658 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 660 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (636) */
/* 662 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 664 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 666 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 668 */	NdrFcShort( 0x4 ),	/* 4 */
/* 670 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 672 */	NdrFcShort( 0x8 ),	/* 8 */
/* 674 */	NdrFcShort( 0x10 ),	/* Corr flags:  */
/* 676 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 678 */	NdrFcLong( 0x0 ),	/* 0 */
/* 682 */	NdrFcLong( 0x3e8 ),	/* 1000 */
/* 686 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 688 */	0xb1,		/* FC_FORCED_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 690 */	NdrFcShort( 0xc ),	/* 12 */
/* 692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 694 */	NdrFcShort( 0x8 ),	/* Offset= 8 (702) */
/* 696 */	0x2,		/* FC_CHAR */
			0x3f,		/* FC_STRUCTPAD3 */
/* 698 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 700 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 702 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 704 */	NdrFcShort( 0xffda ),	/* Offset= -38 (666) */
/* 706 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 708 */	NdrFcShort( 0xc ),	/* 12 */
/* 710 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 712 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 714 */	NdrFcShort( 0x4 ),	/* 4 */
/* 716 */	NdrFcShort( 0x4 ),	/* 4 */
/* 718 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 720 */	NdrFcShort( 0xfd4e ),	/* Offset= -690 (30) */
/* 722 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 724 */	NdrFcShort( 0x8 ),	/* 8 */
/* 726 */	NdrFcShort( 0x8 ),	/* 8 */
/* 728 */	0x12, 0x0,	/* FC_UP */
/* 730 */	NdrFcShort( 0xfe7e ),	/* Offset= -386 (344) */
/* 732 */	
			0x5b,		/* FC_END */

			0x6,		/* FC_SHORT */
/* 734 */	0x6,		/* FC_SHORT */
			0x8,		/* FC_LONG */
/* 736 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 738 */	
			0x15,		/* FC_STRUCT */
			0x1,		/* 1 */
/* 740 */	NdrFcShort( 0x2 ),	/* 2 */
/* 742 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 744 */	
			0x1c,		/* FC_CVARRAY */
			0x1,		/* 1 */
/* 746 */	NdrFcShort( 0x2 ),	/* 2 */
/* 748 */	0x16,		/* Corr desc:  field pointer, FC_SHORT */
			0x55,		/* FC_DIV_2 */
/* 750 */	NdrFcShort( 0xa ),	/* 10 */
/* 752 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 754 */	0x0 , 
			0x0,		/* 0 */
/* 756 */	NdrFcLong( 0x0 ),	/* 0 */
/* 760 */	NdrFcLong( 0x0 ),	/* 0 */
/* 764 */	0x16,		/* Corr desc:  field pointer, FC_SHORT */
			0x55,		/* FC_DIV_2 */
/* 766 */	NdrFcShort( 0x8 ),	/* 8 */
/* 768 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 770 */	0x0 , 
			0x0,		/* 0 */
/* 772 */	NdrFcLong( 0x0 ),	/* 0 */
/* 776 */	NdrFcLong( 0x0 ),	/* 0 */
/* 780 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 782 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 784 */	NdrFcShort( 0x10 ),	/* 16 */
/* 786 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 788 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 790 */	NdrFcShort( 0x4 ),	/* 4 */
/* 792 */	NdrFcShort( 0x4 ),	/* 4 */
/* 794 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 796 */	NdrFcShort( 0xfd02 ),	/* Offset= -766 (30) */
/* 798 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 800 */	NdrFcShort( 0xc ),	/* 12 */
/* 802 */	NdrFcShort( 0xc ),	/* 12 */
/* 804 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 806 */	NdrFcShort( 0xffc2 ),	/* Offset= -62 (744) */
/* 808 */	
			0x5b,		/* FC_END */

			0x6,		/* FC_SHORT */
/* 810 */	0x6,		/* FC_SHORT */
			0x8,		/* FC_LONG */
/* 812 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 814 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 816 */	0xb1,		/* FC_FORCED_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 818 */	NdrFcShort( 0x20 ),	/* 32 */
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 822 */	NdrFcShort( 0x0 ),	/* Offset= 0 (822) */
/* 824 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 826 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 828 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 830 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 832 */	NdrFcShort( 0xff3c ),	/* Offset= -196 (636) */
/* 834 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 836 */	0xb1,		/* FC_FORCED_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 838 */	NdrFcShort( 0x20 ),	/* 32 */
/* 840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 842 */	NdrFcShort( 0x0 ),	/* Offset= 0 (842) */
/* 844 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 846 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (816) */
/* 848 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 850 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 852 */	NdrFcShort( 0x10 ),	/* 16 */
/* 854 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 856 */	NdrFcShort( 0xff24 ),	/* Offset= -220 (636) */
/* 858 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 860 */	NdrFcShort( 0xff20 ),	/* Offset= -224 (636) */
/* 862 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 864 */	
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 866 */	NdrFcShort( 0x1 ),	/* 1 */
/* 868 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 870 */	
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 872 */	NdrFcShort( 0x2 ),	/* 2 */
/* 874 */	0x2,		/* FC_CHAR */
			0x2,		/* FC_CHAR */
/* 876 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 878 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 880 */	NdrFcShort( 0x8 ),	/* 8 */
/* 882 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 884 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 886 */	NdrFcShort( 0x10 ),	/* 16 */
/* 888 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 890 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 892 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (878) */
			0x5b,		/* FC_END */
/* 896 */	
			0x1c,		/* FC_CVARRAY */
			0x1,		/* 1 */
/* 898 */	NdrFcShort( 0x2 ),	/* 2 */
/* 900 */	0x16,		/* Corr desc:  field pointer, FC_SHORT */
			0x55,		/* FC_DIV_2 */
/* 902 */	NdrFcShort( 0x12 ),	/* 18 */
/* 904 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 906 */	0x0 , 
			0x0,		/* 0 */
/* 908 */	NdrFcLong( 0x0 ),	/* 0 */
/* 912 */	NdrFcLong( 0x0 ),	/* 0 */
/* 916 */	0x16,		/* Corr desc:  field pointer, FC_SHORT */
			0x55,		/* FC_DIV_2 */
/* 918 */	NdrFcShort( 0x10 ),	/* 16 */
/* 920 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 922 */	0x0 , 
			0x0,		/* 0 */
/* 924 */	NdrFcLong( 0x0 ),	/* 0 */
/* 928 */	NdrFcLong( 0x0 ),	/* 0 */
/* 932 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 934 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 936 */	NdrFcShort( 0x2c ),	/* 44 */
/* 938 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 940 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 942 */	NdrFcShort( 0x4 ),	/* 4 */
/* 944 */	NdrFcShort( 0x4 ),	/* 4 */
/* 946 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 948 */	NdrFcShort( 0xfc6a ),	/* Offset= -918 (30) */
/* 950 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 952 */	NdrFcShort( 0xc ),	/* 12 */
/* 954 */	NdrFcShort( 0xc ),	/* 12 */
/* 956 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 958 */	NdrFcShort( 0xff2a ),	/* Offset= -214 (744) */
/* 960 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 962 */	NdrFcShort( 0x14 ),	/* 20 */
/* 964 */	NdrFcShort( 0x14 ),	/* 20 */
/* 966 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 968 */	NdrFcShort( 0xffb8 ),	/* Offset= -72 (896) */
/* 970 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 972 */	NdrFcShort( 0x28 ),	/* 40 */
/* 974 */	NdrFcShort( 0x28 ),	/* 40 */
/* 976 */	0x12, 0x0,	/* FC_UP */
/* 978 */	NdrFcShort( 0xfd86 ),	/* Offset= -634 (344) */
/* 980 */	
			0x5b,		/* FC_END */

			0x6,		/* FC_SHORT */
/* 982 */	0x6,		/* FC_SHORT */
			0x8,		/* FC_LONG */
/* 984 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 986 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 988 */	0x6,		/* FC_SHORT */
			0x8,		/* FC_LONG */
/* 990 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 992 */	NdrFcShort( 0xff94 ),	/* Offset= -108 (884) */
/* 994 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 996 */	
			0x11, 0x0,	/* FC_RP */
/* 998 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1000) */
/* 1000 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x6,		/* FC_SHORT */
/* 1002 */	0x26,		/* Corr desc:  parameter, FC_SHORT */
			0x0,		/*  */
/* 1004 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1006 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1008 */	0x0 , 
			0x0,		/* 0 */
/* 1010 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1014 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1018 */	NdrFcShort( 0xfe28 ),	/* Offset= -472 (546) */
/* 1020 */	
			0x11, 0x0,	/* FC_RP */
/* 1022 */	NdrFcShort( 0xfd5a ),	/* Offset= -678 (344) */
/* 1024 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1026 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1028) */
/* 1028 */	0x30,		/* FC_BIND_CONTEXT */
			0xa0,		/* Ctxt flags:  via ptr, out, */
/* 1030 */	0x0,		/* 0 */
			0x1,		/* 1 */
/* 1032 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1034 */	NdrFcShort( 0x42 ),	/* Offset= 66 (1100) */
/* 1036 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1038 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1040 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1042 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1048 */	0x12, 0x0,	/* FC_UP */
/* 1050 */	NdrFcShort( 0xfd3e ),	/* Offset= -706 (344) */
/* 1052 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1054 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1056 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1058 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1060 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 1062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1064 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1066 */	0x0 , 
			0x0,		/* 0 */
/* 1068 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1072 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1076 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1078 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 1080 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1084 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1090 */	0x12, 0x0,	/* FC_UP */
/* 1092 */	NdrFcShort( 0xfd14 ),	/* Offset= -748 (344) */
/* 1094 */	
			0x5b,		/* FC_END */

			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1096 */	0x0,		/* 0 */
			NdrFcShort( 0xffc3 ),	/* Offset= -61 (1036) */
			0x5b,		/* FC_END */
/* 1100 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1102 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1104 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1106 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1108 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1110 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1112 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1114 */	NdrFcShort( 0xffc6 ),	/* Offset= -58 (1056) */
/* 1116 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1118 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1120 */	
			0x11, 0x0,	/* FC_RP */
/* 1122 */	NdrFcShort( 0xfe60 ),	/* Offset= -416 (706) */
/* 1124 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1126 */	NdrFcShort( 0x36 ),	/* Offset= 54 (1180) */
/* 1128 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1130 */	NdrFcShort( 0xc ),	/* 12 */
/* 1132 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 1134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1136 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1138 */	0x0 , 
			0x0,		/* 0 */
/* 1140 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1144 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1148 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1150 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 1152 */	NdrFcShort( 0xc ),	/* 12 */
/* 1154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1156 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1158 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1160 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1162 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1164 */	NdrFcShort( 0xfb92 ),	/* Offset= -1134 (30) */
/* 1166 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1168 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1170 */	0x12, 0x0,	/* FC_UP */
/* 1172 */	NdrFcShort( 0xfcc4 ),	/* Offset= -828 (344) */
/* 1174 */	
			0x5b,		/* FC_END */

			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1176 */	0x0,		/* 0 */
			NdrFcShort( 0xfe29 ),	/* Offset= -471 (706) */
			0x5b,		/* FC_END */
/* 1180 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1182 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1184 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1186 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1188 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1190 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1192 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1194 */	NdrFcShort( 0xffbe ),	/* Offset= -66 (1128) */
/* 1196 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1198 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1200 */	0xb7,		/* FC_RANGE */
			0x8,		/* 8 */
/* 1202 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1206 */	NdrFcLong( 0x3e8 ),	/* 1000 */
/* 1210 */	
			0x11, 0x0,	/* FC_RP */
/* 1212 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1214) */
/* 1214 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1216 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1218 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 1220 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1222 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 1224 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 1226 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1230 */	NdrFcLong( 0x3e8 ),	/* 1000 */
/* 1234 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1236 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 1238 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1242 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1244 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1246 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1248 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1250 */	NdrFcShort( 0xfb3c ),	/* Offset= -1220 (30) */
/* 1252 */	
			0x5b,		/* FC_END */

			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1254 */	0x0,		/* 0 */
			NdrFcShort( 0xfbf1 ),	/* Offset= -1039 (216) */
			0x5b,		/* FC_END */
/* 1258 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1260 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1262) */
/* 1262 */	
			0x12, 0x0,	/* FC_UP */
/* 1264 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1266) */
/* 1266 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1268 */	NdrFcShort( 0xc ),	/* 12 */
/* 1270 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1272 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1274 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1276 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1278 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1280 */	NdrFcShort( 0xff68 ),	/* Offset= -152 (1128) */
/* 1282 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1284 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1286 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1288 */	
			0x11, 0x0,	/* FC_RP */
/* 1290 */	NdrFcShort( 0x3a ),	/* Offset= 58 (1348) */
/* 1292 */	0xb1,		/* FC_FORCED_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1294 */	NdrFcShort( 0xc ),	/* 12 */
/* 1296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1298 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1298) */
/* 1300 */	0x6,		/* FC_SHORT */
			0x3e,		/* FC_STRUCTPAD2 */
/* 1302 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1304 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1306 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1310 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 1312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1314 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 1316 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 1318 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1322 */	NdrFcLong( 0x3e8 ),	/* 1000 */
/* 1326 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1330 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1332 */	0x0 , 
			0x0,		/* 0 */
/* 1334 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1338 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1342 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1344 */	NdrFcShort( 0xffcc ),	/* Offset= -52 (1292) */
/* 1346 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1348 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1350 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1352 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1354 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1356 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1358 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1360 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1362 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (1306) */
/* 1364 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1366 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1368 */	
			0x11, 0x0,	/* FC_RP */
/* 1370 */	NdrFcShort( 0x2e ),	/* Offset= 46 (1416) */
/* 1372 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1374 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1376 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 1378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1380 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 1382 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 1384 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1388 */	NdrFcLong( 0x5000 ),	/* 20480 */
/* 1392 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1394 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 1396 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1400 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1406 */	0x12, 0x0,	/* FC_UP */
/* 1408 */	NdrFcShort( 0xfbd8 ),	/* Offset= -1064 (344) */
/* 1410 */	
			0x5b,		/* FC_END */

			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1412 */	0x0,		/* 0 */
			NdrFcShort( 0xfe87 ),	/* Offset= -377 (1036) */
			0x5b,		/* FC_END */
/* 1416 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1418 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1420 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1422 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1424 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1426 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1428 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1430 */	NdrFcShort( 0xffc6 ),	/* Offset= -58 (1372) */
/* 1432 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1434 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1436 */	
			0x11, 0x0,	/* FC_RP */
/* 1438 */	NdrFcShort( 0x3c ),	/* Offset= 60 (1498) */
/* 1440 */	0xb1,		/* FC_FORCED_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1442 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1446 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1446) */
/* 1448 */	0x6,		/* FC_SHORT */
			0x3e,		/* FC_STRUCTPAD2 */
/* 1450 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1452 */	NdrFcShort( 0xfb2c ),	/* Offset= -1236 (216) */
/* 1454 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1456 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1460 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 1462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1464 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 1466 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 1468 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1472 */	NdrFcLong( 0x5000 ),	/* 20480 */
/* 1476 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1480 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1482 */	0x0 , 
			0x0,		/* 0 */
/* 1484 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1488 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1492 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1494 */	NdrFcShort( 0xffca ),	/* Offset= -54 (1440) */
/* 1496 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1498 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1500 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1502 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1504 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1506 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1508 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1510 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1512 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (1456) */
/* 1514 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1516 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1518 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1520 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1522) */
/* 1522 */	
			0x12, 0x0,	/* FC_UP */
/* 1524 */	NdrFcShort( 0x26 ),	/* Offset= 38 (1562) */
/* 1526 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 1528 */	NdrFcShort( 0xc ),	/* 12 */
/* 1530 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1532 */	NdrFcShort( 0xfa1a ),	/* Offset= -1510 (22) */
/* 1534 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1536 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1538 */	NdrFcShort( 0xc ),	/* 12 */
/* 1540 */	0x8,		/* Corr desc: FC_LONG */
			0x0,		/*  */
/* 1542 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 1544 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 1546 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 1548 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1552 */	NdrFcLong( 0x3e8 ),	/* 1000 */
/* 1556 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1558 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (1526) */
/* 1560 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1562 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 1564 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1566 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (1536) */
/* 1568 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1570 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1572 */	
			0x11, 0x0,	/* FC_RP */
/* 1574 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1562) */
/* 1576 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1578 */	NdrFcShort( 0xfd06 ),	/* Offset= -762 (816) */
/* 1580 */	
			0x11, 0x0,	/* FC_RP */
/* 1582 */	NdrFcShort( 0xfd02 ),	/* Offset= -766 (816) */
/* 1584 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1586 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1588 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1590 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1592) */
/* 1592 */	
			0x12, 0x0,	/* FC_UP */
/* 1594 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1596) */
/* 1596 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x6,		/* FC_SHORT */
/* 1598 */	0x26,		/* Corr desc:  parameter, FC_SHORT */
			0x0,		/*  */
/* 1600 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1602 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1604 */	0x0 , 
			0x0,		/* 0 */
/* 1606 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1610 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1614 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1616) */
/* 1616 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1618 */	NdrFcShort( 0xd ),	/* 13 */
/* 1620 */	NdrFcLong( 0x1 ),	/* 1 */
/* 1624 */	NdrFcShort( 0xfa80 ),	/* Offset= -1408 (216) */
/* 1626 */	NdrFcLong( 0x2 ),	/* 2 */
/* 1630 */	NdrFcShort( 0x72 ),	/* Offset= 114 (1744) */
/* 1632 */	NdrFcLong( 0x3 ),	/* 3 */
/* 1636 */	NdrFcShort( 0x80 ),	/* Offset= 128 (1764) */
/* 1638 */	NdrFcLong( 0x4 ),	/* 4 */
/* 1642 */	NdrFcShort( 0xc4 ),	/* Offset= 196 (1838) */
/* 1644 */	NdrFcLong( 0x5 ),	/* 5 */
/* 1648 */	NdrFcShort( 0xfc52 ),	/* Offset= -942 (706) */
/* 1650 */	NdrFcLong( 0x6 ),	/* 6 */
/* 1654 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (1868) */
/* 1656 */	NdrFcLong( 0x7 ),	/* 7 */
/* 1660 */	NdrFcShort( 0x140 ),	/* Offset= 320 (1980) */
/* 1662 */	NdrFcLong( 0x8 ),	/* 8 */
/* 1666 */	NdrFcShort( 0x160 ),	/* Offset= 352 (2018) */
/* 1668 */	NdrFcLong( 0x9 ),	/* 9 */
/* 1672 */	NdrFcShort( 0x186 ),	/* Offset= 390 (2062) */
/* 1674 */	NdrFcLong( 0xa ),	/* 10 */
/* 1678 */	NdrFcShort( 0x1aa ),	/* Offset= 426 (2104) */
/* 1680 */	NdrFcLong( 0xb ),	/* 11 */
/* 1684 */	NdrFcShort( 0x1fa ),	/* Offset= 506 (2190) */
/* 1686 */	NdrFcLong( 0xc ),	/* 12 */
/* 1690 */	NdrFcShort( 0x230 ),	/* Offset= 560 (2250) */
/* 1692 */	NdrFcLong( 0xd ),	/* 13 */
/* 1696 */	NdrFcShort( 0x44 ),	/* Offset= 68 (1764) */
/* 1698 */	NdrFcShort( 0xffff ),	/* Offset= -1 (1697) */
/* 1700 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1702 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1704 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 1706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1708 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 1710 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 1712 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1716 */	NdrFcLong( 0x5 ),	/* 5 */
/* 1720 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1722 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 1724 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1728 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1730 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1732 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1734 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1736 */	NdrFcShort( 0xf956 ),	/* Offset= -1706 (30) */
/* 1738 */	
			0x5b,		/* FC_END */

			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1740 */	0x0,		/* 0 */
			NdrFcShort( 0xfa0b ),	/* Offset= -1525 (216) */
			0x5b,		/* FC_END */
/* 1744 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1746 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1748 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1750 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1752 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1754 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1756 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1758 */	NdrFcShort( 0xffc6 ),	/* Offset= -58 (1700) */
/* 1760 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1762 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1764 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 1766 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1768 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1770 */	0xb7,		/* FC_RANGE */
			0x8,		/* 8 */
/* 1772 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1776 */	NdrFcLong( 0x20010 ),	/* 131088 */
/* 1780 */	
			0x1c,		/* FC_CVARRAY */
			0x0,		/* 0 */
/* 1782 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1784 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 1786 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1788 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 1790 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 1792 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1796 */	NdrFcLong( 0x20010 ),	/* 131088 */
/* 1800 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 1802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1804 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1806 */	0x0 , 
			0x0,		/* 0 */
/* 1808 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1812 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1816 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 1818 */	0xb1,		/* FC_FORCED_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1820 */	NdrFcShort( 0xc ),	/* 12 */
/* 1822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1824 */	NdrFcShort( 0xa ),	/* Offset= 10 (1834) */
/* 1826 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1828 */	NdrFcShort( 0xffc6 ),	/* Offset= -58 (1770) */
/* 1830 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 1832 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1834 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1836 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (1780) */
/* 1838 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1840 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1842 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1844 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1850 */	0x12, 0x0,	/* FC_UP */
/* 1852 */	NdrFcShort( 0xffde ),	/* Offset= -34 (1818) */
/* 1854 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1856 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1858 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1860 */	0x12, 0x0,	/* FC_UP */
/* 1862 */	NdrFcShort( 0xffd4 ),	/* Offset= -44 (1818) */
/* 1864 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1866 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1868 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1870 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1872 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1874 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1876 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1878 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1880 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1882 */	NdrFcShort( 0xf8c4 ),	/* Offset= -1852 (30) */
/* 1884 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1886 */	NdrFcShort( 0xc ),	/* 12 */
/* 1888 */	NdrFcShort( 0xc ),	/* 12 */
/* 1890 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1892 */	NdrFcShort( 0xfb84 ),	/* Offset= -1148 (744) */
/* 1894 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1896 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1898 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1900 */	0x12, 0x0,	/* FC_UP */
/* 1902 */	NdrFcShort( 0xf9ea ),	/* Offset= -1558 (344) */
/* 1904 */	
			0x5b,		/* FC_END */

			0x6,		/* FC_SHORT */
/* 1906 */	0x6,		/* FC_SHORT */
			0x8,		/* FC_LONG */
/* 1908 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1910 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1912 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1914 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1916 */	0xb7,		/* FC_RANGE */
			0x8,		/* 8 */
/* 1918 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1922 */	NdrFcLong( 0x1 ),	/* 1 */
/* 1926 */	0xb7,		/* FC_RANGE */
			0x8,		/* 8 */
/* 1928 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1932 */	NdrFcLong( 0x1 ),	/* 1 */
/* 1936 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 1938 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1940 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 1942 */	NdrFcShort( 0xc ),	/* 12 */
/* 1944 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 1946 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 1948 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1952 */	NdrFcLong( 0x10000 ),	/* 65536 */
/* 1956 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 1958 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1960 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1964 */	NdrFcShort( 0xc ),	/* Offset= 12 (1976) */
/* 1966 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1968 */	NdrFcShort( 0xfacc ),	/* Offset= -1332 (636) */
/* 1970 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1972 */	0x36,		/* FC_POINTER */
			0x40,		/* FC_STRUCTPAD4 */
/* 1974 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1976 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1978 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (1936) */
/* 1980 */	0xb1,		/* FC_FORCED_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1982 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1986 */	NdrFcShort( 0x10 ),	/* Offset= 16 (2002) */
/* 1988 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1990 */	NdrFcShort( 0xffb6 ),	/* Offset= -74 (1916) */
/* 1992 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1994 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1996 */	NdrFcShort( 0xffba ),	/* Offset= -70 (1926) */
/* 1998 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 2000 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2002 */	
			0x12, 0x0,	/* FC_UP */
/* 2004 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (1958) */
/* 2006 */	
			0x12, 0x0,	/* FC_UP */
/* 2008 */	NdrFcShort( 0xffce ),	/* Offset= -50 (1958) */
/* 2010 */	
			0x12, 0x0,	/* FC_UP */
/* 2012 */	NdrFcShort( 0xffca ),	/* Offset= -54 (1958) */
/* 2014 */	
			0x12, 0x0,	/* FC_UP */
/* 2016 */	NdrFcShort( 0xffc6 ),	/* Offset= -58 (1958) */
/* 2018 */	0xb1,		/* FC_FORCED_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2020 */	NdrFcShort( 0x3c ),	/* 60 */
/* 2022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2024 */	NdrFcShort( 0x0 ),	/* Offset= 0 (2024) */
/* 2026 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2028 */	NdrFcShort( 0xff60 ),	/* Offset= -160 (1868) */
/* 2030 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2032 */	NdrFcShort( 0xfef4 ),	/* Offset= -268 (1764) */
/* 2034 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2036 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (1980) */
/* 2038 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2040 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 2042 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2044 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 2046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2048 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 2050 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 2052 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2056 */	NdrFcLong( 0x10000 ),	/* 65536 */
/* 2060 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 2062 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 2064 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2066 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 2068 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 2070 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2072 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2074 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2076 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (2040) */
/* 2078 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 2080 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 2082 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 2084 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2086 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 2088 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2090 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 2092 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 2094 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2098 */	NdrFcLong( 0x10000 ),	/* 65536 */
/* 2102 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 2104 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 2106 */	NdrFcShort( 0x2c ),	/* 44 */
/* 2108 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 2110 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 2112 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2114 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2116 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2118 */	NdrFcShort( 0xf7d8 ),	/* Offset= -2088 (30) */
/* 2120 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 2122 */	NdrFcShort( 0xc ),	/* 12 */
/* 2124 */	NdrFcShort( 0xc ),	/* 12 */
/* 2126 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2128 */	NdrFcShort( 0xfa98 ),	/* Offset= -1384 (744) */
/* 2130 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 2132 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2134 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2136 */	0x12, 0x0,	/* FC_UP */
/* 2138 */	NdrFcShort( 0xf8fe ),	/* Offset= -1794 (344) */
/* 2140 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 2142 */	NdrFcShort( 0x28 ),	/* 40 */
/* 2144 */	NdrFcShort( 0x28 ),	/* 40 */
/* 2146 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2148 */	NdrFcShort( 0xffbe ),	/* Offset= -66 (2082) */
/* 2150 */	
			0x5b,		/* FC_END */

			0x6,		/* FC_SHORT */
/* 2152 */	0x6,		/* FC_SHORT */
			0x8,		/* FC_LONG */
/* 2154 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 2156 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 2158 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 2160 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 2162 */	0x0,		/* 0 */
			NdrFcShort( 0xfe71 ),	/* Offset= -399 (1764) */
			0x8,		/* FC_LONG */
/* 2166 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 2168 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 2170 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2172 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 2174 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2176 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2178 */	0x0 , 
			0x0,		/* 0 */
/* 2180 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2184 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2188 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 2190 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 2192 */	NdrFcShort( 0x28 ),	/* 40 */
/* 2194 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 2196 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 2198 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2200 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2202 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2204 */	NdrFcShort( 0xf782 ),	/* Offset= -2174 (30) */
/* 2206 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 2208 */	NdrFcShort( 0xc ),	/* 12 */
/* 2210 */	NdrFcShort( 0xc ),	/* 12 */
/* 2212 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2214 */	NdrFcShort( 0xfa42 ),	/* Offset= -1470 (744) */
/* 2216 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 2218 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2220 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2222 */	0x12, 0x0,	/* FC_UP */
/* 2224 */	NdrFcShort( 0xf8a8 ),	/* Offset= -1880 (344) */
/* 2226 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 2228 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2230 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2232 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2234 */	NdrFcShort( 0xffbe ),	/* Offset= -66 (2168) */
/* 2236 */	
			0x5b,		/* FC_END */

			0x6,		/* FC_SHORT */
/* 2238 */	0x6,		/* FC_SHORT */
			0x8,		/* FC_LONG */
/* 2240 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 2242 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 2244 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 2246 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 2248 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 2250 */	0xb1,		/* FC_FORCED_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2252 */	NdrFcShort( 0x44 ),	/* 68 */
/* 2254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2256 */	NdrFcShort( 0x0 ),	/* Offset= 0 (2256) */
/* 2258 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2260 */	NdrFcShort( 0xffba ),	/* Offset= -70 (2190) */
/* 2262 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2264 */	NdrFcShort( 0xfe0c ),	/* Offset= -500 (1764) */
/* 2266 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2268 */	NdrFcShort( 0xfee0 ),	/* Offset= -288 (1980) */
/* 2270 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2272 */	
			0x11, 0x0,	/* FC_RP */
/* 2274 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2276) */
/* 2276 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x6,		/* FC_SHORT */
/* 2278 */	0x26,		/* Corr desc:  parameter, FC_SHORT */
			0x0,		/*  */
/* 2280 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2282 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2284 */	0x0 , 
			0x0,		/* 0 */
/* 2286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2294 */	NdrFcShort( 0xfd5a ),	/* Offset= -678 (1616) */
/* 2296 */	
			0x12, 0x0,	/* FC_UP */
/* 2298 */	NdrFcShort( 0xfe20 ),	/* Offset= -480 (1818) */
/* 2300 */	
			0x12, 0x14,	/* FC_UP [alloced_on_stack] [pointer_deref] */
/* 2302 */	NdrFcShort( 0xfffa ),	/* Offset= -6 (2296) */
/* 2304 */	
			0x12, 0x0,	/* FC_UP */
/* 2306 */	NdrFcShort( 0xf97a ),	/* Offset= -1670 (636) */
/* 2308 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 2310 */	NdrFcShort( 0xf710 ),	/* Offset= -2288 (22) */
/* 2312 */	
			0x11, 0x0,	/* FC_RP */
/* 2314 */	NdrFcShort( 0xf70c ),	/* Offset= -2292 (22) */
/* 2316 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 2318 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2320) */
/* 2320 */	
			0x12, 0x0,	/* FC_UP */
/* 2322 */	NdrFcShort( 0xf7c6 ),	/* Offset= -2106 (216) */
/* 2324 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 2326 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 2328 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 2330 */	NdrFcShort( 0x2e ),	/* Offset= 46 (2376) */
/* 2332 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 2334 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2336 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 2338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2340 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 2342 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 2344 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2348 */	NdrFcLong( 0x100 ),	/* 256 */
/* 2352 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 2354 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 2356 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2360 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2362 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2364 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2366 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2368 */	NdrFcShort( 0xf6de ),	/* Offset= -2338 (30) */
/* 2370 */	
			0x5b,		/* FC_END */

			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 2372 */	0x0,		/* 0 */
			NdrFcShort( 0xf793 ),	/* Offset= -2157 (216) */
			0x5b,		/* FC_END */
/* 2376 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 2378 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2380 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 2382 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 2384 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2386 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2388 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2390 */	NdrFcShort( 0xffc6 ),	/* Offset= -58 (2332) */
/* 2392 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 2394 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 2396 */	
			0x11, 0x0,	/* FC_RP */
/* 2398 */	NdrFcShort( 0xffea ),	/* Offset= -22 (2376) */
/* 2400 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 2402 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2404) */
/* 2404 */	
			0x12, 0x0,	/* FC_UP */
/* 2406 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2408) */
/* 2408 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x6,		/* FC_SHORT */
/* 2410 */	0x26,		/* Corr desc:  parameter, FC_SHORT */
			0x0,		/*  */
/* 2412 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2414 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2416 */	0x0 , 
			0x0,		/* 0 */
/* 2418 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2422 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2426 */	NdrFcShort( 0xfcd6 ),	/* Offset= -810 (1616) */
/* 2428 */	
			0x11, 0x0,	/* FC_RP */
/* 2430 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2432) */
/* 2432 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x6,		/* FC_SHORT */
/* 2434 */	0x26,		/* Corr desc:  parameter, FC_SHORT */
			0x0,		/*  */
/* 2436 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2438 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2440 */	0x0 , 
			0x0,		/* 0 */
/* 2442 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2446 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2450 */	NdrFcShort( 0xfcbe ),	/* Offset= -834 (1616) */
/* 2452 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 2454 */	NdrFcShort( 0xff62 ),	/* Offset= -158 (2296) */
/* 2456 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 2458 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 2460 */	
			0x12, 0x14,	/* FC_UP [alloced_on_stack] [pointer_deref] */
/* 2462 */	NdrFcShort( 0xff72 ),	/* Offset= -142 (2320) */
/* 2464 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 2466 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2468) */
/* 2468 */	
			0x12, 0x0,	/* FC_UP */
/* 2470 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2472) */
/* 2472 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x6,		/* FC_SHORT */
/* 2474 */	0x26,		/* Corr desc:  parameter, FC_SHORT */
			0x0,		/*  */
/* 2476 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2478 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2480 */	0x0 , 
			0x0,		/* 0 */
/* 2482 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2486 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2490 */	NdrFcShort( 0xf868 ),	/* Offset= -1944 (546) */
/* 2492 */	
			0x11, 0x0,	/* FC_RP */
/* 2494 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2496) */
/* 2496 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x6,		/* FC_SHORT */
/* 2498 */	0x26,		/* Corr desc:  parameter, FC_SHORT */
			0x0,		/*  */
/* 2500 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2502 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2504 */	0x0 , 
			0x0,		/* 0 */
/* 2506 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2510 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2514 */	NdrFcShort( 0xf850 ),	/* Offset= -1968 (546) */
/* 2516 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 2518 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2520) */
/* 2520 */	
			0x12, 0x0,	/* FC_UP */
/* 2522 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2524) */
/* 2524 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x6,		/* FC_SHORT */
/* 2526 */	0x26,		/* Corr desc:  parameter, FC_SHORT */
			0x0,		/*  */
/* 2528 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2530 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2532 */	0x0 , 
			0x0,		/* 0 */
/* 2534 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2538 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2542 */	NdrFcShort( 0xfc62 ),	/* Offset= -926 (1616) */
/* 2544 */	
			0x11, 0x0,	/* FC_RP */
/* 2546 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2548) */
/* 2548 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x6,		/* FC_SHORT */
/* 2550 */	0x26,		/* Corr desc:  parameter, FC_SHORT */
			0x0,		/*  */
/* 2552 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2554 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2556 */	0x0 , 
			0x0,		/* 0 */
/* 2558 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2562 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2566 */	NdrFcShort( 0xfc4a ),	/* Offset= -950 (1616) */
/* 2568 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 2570 */	NdrFcShort( 0x3e ),	/* Offset= 62 (2632) */
/* 2572 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 2574 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2576 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 2578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2580 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2582 */	0x0 , 
			0x0,		/* 0 */
/* 2584 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2588 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2592 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 2594 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 2596 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2600 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2602 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2604 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2606 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2608 */	NdrFcShort( 0xf5ee ),	/* Offset= -2578 (30) */
/* 2610 */	NdrFcShort( 0xc ),	/* 12 */
/* 2612 */	NdrFcShort( 0xc ),	/* 12 */
/* 2614 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2616 */	NdrFcShort( 0xf8b0 ),	/* Offset= -1872 (744) */
/* 2618 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2620 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2622 */	0x12, 0x0,	/* FC_UP */
/* 2624 */	NdrFcShort( 0xf718 ),	/* Offset= -2280 (344) */
/* 2626 */	
			0x5b,		/* FC_END */

			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 2628 */	0x0,		/* 0 */
			NdrFcShort( 0xfd07 ),	/* Offset= -761 (1868) */
			0x5b,		/* FC_END */
/* 2632 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 2634 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2636 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 2638 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 2640 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2642 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2644 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2646 */	NdrFcShort( 0xffb6 ),	/* Offset= -74 (2572) */
/* 2648 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 2650 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 2652 */	
			0x11, 0x0,	/* FC_RP */
/* 2654 */	NdrFcShort( 0xfcee ),	/* Offset= -786 (1868) */
/* 2656 */	
			0x11, 0x0,	/* FC_RP */
/* 2658 */	NdrFcShort( 0xfd5a ),	/* Offset= -678 (1980) */
/* 2660 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 2662 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2664) */
/* 2664 */	
			0x12, 0x0,	/* FC_UP */
/* 2666 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2668) */
/* 2668 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x6,		/* FC_SHORT */
/* 2670 */	0x26,		/* Corr desc:  parameter, FC_SHORT */
			0x0,		/*  */
/* 2672 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2674 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2676 */	0x0 , 
			0x0,		/* 0 */
/* 2678 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2682 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2686 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2688) */
/* 2688 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2690 */	NdrFcShort( 0x2 ),	/* 2 */
/* 2692 */	NdrFcLong( 0x2 ),	/* 2 */
/* 2696 */	NdrFcShort( 0x20 ),	/* Offset= 32 (2728) */
/* 2698 */	NdrFcLong( 0x3 ),	/* 3 */
/* 2702 */	NdrFcShort( 0x2e ),	/* Offset= 46 (2748) */
/* 2704 */	NdrFcShort( 0xffff ),	/* Offset= -1 (2703) */
/* 2706 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 2708 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2710 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 2712 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2714 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2716 */	0x0 , 
			0x0,		/* 0 */
/* 2718 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2722 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2726 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 2728 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 2730 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2732 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 2734 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 2736 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2738 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2740 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2742 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (2706) */
/* 2744 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 2746 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 2748 */	0xb1,		/* FC_FORCED_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 2750 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2754 */	NdrFcShort( 0x0 ),	/* Offset= 0 (2754) */
/* 2756 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 2758 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2760 */	NdrFcShort( 0xf7b4 ),	/* Offset= -2124 (636) */
/* 2762 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2764 */	NdrFcShort( 0xf7b0 ),	/* Offset= -2128 (636) */
/* 2766 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2768 */	NdrFcShort( 0xf7ac ),	/* Offset= -2132 (636) */
/* 2770 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2772 */	NdrFcShort( 0xf7a8 ),	/* Offset= -2136 (636) */
/* 2774 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2776 */	NdrFcShort( 0xf7a4 ),	/* Offset= -2140 (636) */
/* 2778 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2780 */	
			0x12, 0x0,	/* FC_UP */
/* 2782 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2784) */
/* 2784 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x6,		/* FC_SHORT */
/* 2786 */	0x26,		/* Corr desc:  parameter, FC_SHORT */
			0x0,		/*  */
/* 2788 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2790 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2792 */	0x0 , 
			0x0,		/* 0 */
/* 2794 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2798 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2802 */	NdrFcShort( 0xff8e ),	/* Offset= -114 (2688) */
/* 2804 */	
			0x11, 0x0,	/* FC_RP */
/* 2806 */	NdrFcShort( 0x58 ),	/* Offset= 88 (2894) */
/* 2808 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 2810 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2812 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 2814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2816 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 2818 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 2820 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2824 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2828 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 2830 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 2832 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2834 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 2836 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 2838 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2840 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2842 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2844 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (2808) */
/* 2846 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 2848 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 2850 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 2852 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2854 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 2856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2858 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 2860 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 2862 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2866 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2870 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 2872 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 2874 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2878 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2880 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2882 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2884 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2886 */	NdrFcShort( 0xffb2 ),	/* Offset= -78 (2808) */
/* 2888 */	
			0x5b,		/* FC_END */

			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 2890 */	0x0,		/* 0 */
			NdrFcShort( 0xffc3 ),	/* Offset= -61 (2830) */
			0x5b,		/* FC_END */
/* 2894 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 2896 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2898 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 2900 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 2902 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2904 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2906 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 2908 */	NdrFcShort( 0xffc6 ),	/* Offset= -58 (2850) */
/* 2910 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 2912 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 2914 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 2916 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2918) */
/* 2918 */	
			0x12, 0x0,	/* FC_UP */
/* 2920 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (2894) */
/* 2922 */	
			0x11, 0x0,	/* FC_RP */
/* 2924 */	NdrFcShort( 0x3e ),	/* Offset= 62 (2986) */
/* 2926 */	0xb1,		/* FC_FORCED_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2928 */	NdrFcShort( 0x14 ),	/* 20 */
/* 2930 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2932 */	NdrFcShort( 0x0 ),	/* Offset= 0 (2932) */
/* 2934 */	0x6,		/* FC_SHORT */
			0x3e,		/* FC_STRUCTPAD2 */
/* 2936 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2938 */	NdrFcShort( 0xf55e ),	/* Offset= -2722 (216) */
/* 2940 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 2942 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2944 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 2946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2948 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 2950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2952 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 2954 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 2956 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2960 */	NdrFcLong( 0x5000 ),	/* 20480 */
/* 2964 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2968 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2970 */	0x0 , 
			0x0,		/* 0 */
/* 2972 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2976 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2980 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2982 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (2926) */
/* 2984 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2986 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 2988 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2990 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 2992 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 2994 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2996 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2998 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3000 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (2944) */
/* 3002 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 3004 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 3006 */	0xb7,		/* FC_RANGE */
			0x8,		/* 8 */
/* 3008 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3012 */	NdrFcLong( 0x3e8 ),	/* 1000 */
/* 3016 */	
			0x11, 0x0,	/* FC_RP */
/* 3018 */	NdrFcShort( 0x3a ),	/* Offset= 58 (3076) */
/* 3020 */	0xb1,		/* FC_FORCED_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 3022 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3024 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3026 */	NdrFcShort( 0x0 ),	/* Offset= 0 (3026) */
/* 3028 */	0x6,		/* FC_SHORT */
			0x3e,		/* FC_STRUCTPAD2 */
/* 3030 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 3032 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 3034 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 3036 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3038 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 3040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3042 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 3044 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 3046 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3050 */	NdrFcLong( 0x3e8 ),	/* 1000 */
/* 3054 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 3058 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 3060 */	0x0 , 
			0x0,		/* 0 */
/* 3062 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3066 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3070 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 3072 */	NdrFcShort( 0xffcc ),	/* Offset= -52 (3020) */
/* 3074 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3076 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 3078 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3080 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 3082 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 3084 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3086 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3088 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3090 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (3034) */
/* 3092 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 3094 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 3096 */	
			0x11, 0x0,	/* FC_RP */
/* 3098 */	NdrFcShort( 0xfbf4 ),	/* Offset= -1036 (2062) */
/* 3100 */	
			0x11, 0x0,	/* FC_RP */
/* 3102 */	NdrFcShort( 0xca ),	/* Offset= 202 (3304) */
/* 3104 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 3106 */	0x40,		/* Corr desc:  constant, val=32767 */
			0x0,		/* 0 */
/* 3108 */	NdrFcShort( 0x7fff ),	/* 32767 */
/* 3110 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3112 */	0x0 , 
			0x0,		/* 0 */
/* 3114 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3118 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3122 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 3124 */	0x40,		/* Corr desc:  constant, val=256 */
			0x0,		/* 0 */
/* 3126 */	NdrFcShort( 0x100 ),	/* 256 */
/* 3128 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3130 */	0x0 , 
			0x0,		/* 0 */
/* 3132 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3136 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3140 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 3142 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3144 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 3146 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3148 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 3150 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 3152 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3156 */	NdrFcLong( 0xa00 ),	/* 2560 */
/* 3160 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 3162 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 3164 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3166 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 3168 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3170 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 3172 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 3174 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3178 */	NdrFcLong( 0x100 ),	/* 256 */
/* 3182 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 3184 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 3186 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3188 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 3190 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 3192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3196 */	0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3198 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3200 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 3202 */	NdrFcShort( 0xc ),	/* 12 */
/* 3204 */	NdrFcShort( 0xc ),	/* 12 */
/* 3206 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3208 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (3162) */
/* 3210 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 3212 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 3214 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 3216 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 3218 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3220 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 3222 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3224 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 3226 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 3228 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3232 */	NdrFcLong( 0x40 ),	/* 64 */
/* 3236 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 3238 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 3240 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3242 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3244 */	NdrFcShort( 0x2 ),	/* 2 */
/* 3246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3250 */	0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 3252 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 3254 */	NdrFcShort( 0xc ),	/* 12 */
/* 3256 */	NdrFcShort( 0xc ),	/* 12 */
/* 3258 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3260 */	NdrFcShort( 0xff9e ),	/* Offset= -98 (3162) */
/* 3262 */	
			0x5b,		/* FC_END */

			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 3264 */	0x0,		/* 0 */
			NdrFcShort( 0xffaf ),	/* Offset= -81 (3184) */
			0x5b,		/* FC_END */
/* 3268 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 3270 */	0x40,		/* Corr desc:  constant, val=256 */
			0x0,		/* 0 */
/* 3272 */	NdrFcShort( 0x100 ),	/* 256 */
/* 3274 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3276 */	0x0 , 
			0x0,		/* 0 */
/* 3278 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3282 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3286 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 3288 */	0x40,		/* Corr desc:  constant, val=513 */
			0x0,		/* 0 */
/* 3290 */	NdrFcShort( 0x201 ),	/* 513 */
/* 3292 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3294 */	0x0 , 
			0x0,		/* 0 */
/* 3296 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3300 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3304 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 3306 */	NdrFcShort( 0x38 ),	/* 56 */
/* 3308 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 3310 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 3312 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3314 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3316 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3318 */	NdrFcShort( 0xff2a ),	/* Offset= -214 (3104) */
/* 3320 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 3322 */	NdrFcShort( 0xc ),	/* 12 */
/* 3324 */	NdrFcShort( 0xc ),	/* 12 */
/* 3326 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3328 */	NdrFcShort( 0xff32 ),	/* Offset= -206 (3122) */
/* 3330 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 3332 */	NdrFcShort( 0x1c ),	/* 28 */
/* 3334 */	NdrFcShort( 0x1c ),	/* 28 */
/* 3336 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3338 */	NdrFcShort( 0xff3a ),	/* Offset= -198 (3140) */
/* 3340 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 3342 */	NdrFcShort( 0x28 ),	/* 40 */
/* 3344 */	NdrFcShort( 0x28 ),	/* 40 */
/* 3346 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3348 */	NdrFcShort( 0xff7c ),	/* Offset= -132 (3216) */
/* 3350 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 3352 */	NdrFcShort( 0x2c ),	/* 44 */
/* 3354 */	NdrFcShort( 0x2c ),	/* 44 */
/* 3356 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3358 */	NdrFcShort( 0xffa6 ),	/* Offset= -90 (3268) */
/* 3360 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 3362 */	NdrFcShort( 0x30 ),	/* 48 */
/* 3364 */	NdrFcShort( 0x30 ),	/* 48 */
/* 3366 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3368 */	NdrFcShort( 0xffae ),	/* Offset= -82 (3286) */
/* 3370 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 3372 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 3374 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 3376 */	0x0,		/* 0 */
			NdrFcShort( 0xf2e5 ),	/* Offset= -3355 (22) */
			0x8,		/* FC_LONG */
/* 3380 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 3382 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 3384 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 3386 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 3388 */	
			0x11, 0x0,	/* FC_RP */
/* 3390 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3392) */
/* 3392 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 3394 */	0x40,		/* Corr desc:  constant, val=32767 */
			0x0,		/* 0 */
/* 3396 */	NdrFcShort( 0x7fff ),	/* 32767 */
/* 3398 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3400 */	0x0 , 
			0x0,		/* 0 */
/* 3402 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3406 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3410 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 3412 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3414) */
/* 3414 */	
			0x12, 0x0,	/* FC_UP */
/* 3416 */	NdrFcShort( 0xff90 ),	/* Offset= -112 (3304) */
/* 3418 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3420 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3422) */
/* 3422 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 3424 */	0x40,		/* Corr desc:  constant, val=32767 */
			0x0,		/* 0 */
/* 3426 */	NdrFcShort( 0x7fff ),	/* 32767 */
/* 3428 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3430 */	0x0 , 
			0x0,		/* 0 */
/* 3432 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3436 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3440 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 3442 */	NdrFcShort( 0x2c ),	/* Offset= 44 (3486) */
/* 3444 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 3446 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3448 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 3450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3452 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3454 */	0x0 , 
			0x0,		/* 0 */
/* 3456 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3460 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3464 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 3466 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 3468 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3472 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3478 */	0x12, 0x0,	/* FC_UP */
/* 3480 */	NdrFcShort( 0xff50 ),	/* Offset= -176 (3304) */
/* 3482 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 3484 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3486 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 3488 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3490 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 3492 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 3494 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3496 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3498 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3500 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (3444) */
/* 3502 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 3504 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 3506 */	
			0x11, 0x0,	/* FC_RP */
/* 3508 */	NdrFcShort( 0x96 ),	/* Offset= 150 (3658) */
/* 3510 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 3512 */	0x40,		/* Corr desc:  constant, val=337 */
			0x0,		/* 0 */
/* 3514 */	NdrFcShort( 0x151 ),	/* 337 */
/* 3516 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3518 */	0x0 , 
			0x0,		/* 0 */
/* 3520 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3524 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3528 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 3530 */	0x40,		/* Corr desc:  constant, val=337 */
			0x0,		/* 0 */
/* 3532 */	NdrFcShort( 0x151 ),	/* 337 */
/* 3534 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3536 */	0x0 , 
			0x0,		/* 0 */
/* 3538 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3542 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3546 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 3548 */	0x40,		/* Corr desc:  constant, val=337 */
			0x0,		/* 0 */
/* 3550 */	NdrFcShort( 0x151 ),	/* 337 */
/* 3552 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3554 */	0x0 , 
			0x0,		/* 0 */
/* 3556 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3560 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3564 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 3566 */	0x40,		/* Corr desc:  constant, val=337 */
			0x0,		/* 0 */
/* 3568 */	NdrFcShort( 0x151 ),	/* 337 */
/* 3570 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3572 */	0x0 , 
			0x0,		/* 0 */
/* 3574 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3578 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3582 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 3584 */	0x40,		/* Corr desc:  constant, val=337 */
			0x0,		/* 0 */
/* 3586 */	NdrFcShort( 0x151 ),	/* 337 */
/* 3588 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3590 */	0x0 , 
			0x0,		/* 0 */
/* 3592 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3596 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3600 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 3602 */	0x40,		/* Corr desc:  constant, val=337 */
			0x0,		/* 0 */
/* 3604 */	NdrFcShort( 0x151 ),	/* 337 */
/* 3606 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3608 */	0x0 , 
			0x0,		/* 0 */
/* 3610 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3614 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3618 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 3620 */	0x40,		/* Corr desc:  constant, val=256 */
			0x0,		/* 0 */
/* 3622 */	NdrFcShort( 0x100 ),	/* 256 */
/* 3624 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3626 */	0x0 , 
			0x0,		/* 0 */
/* 3628 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3632 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3636 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 3638 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3640 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 3642 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3644 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 3646 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 3648 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3652 */	NdrFcLong( 0x3ef ),	/* 1007 */
/* 3656 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 3658 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 3660 */	NdrFcShort( 0x28 ),	/* 40 */
/* 3662 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 3664 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 3666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3670 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3672 */	NdrFcShort( 0xff5e ),	/* Offset= -162 (3510) */
/* 3674 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 3676 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3678 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3680 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3682 */	NdrFcShort( 0xff66 ),	/* Offset= -154 (3528) */
/* 3684 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 3686 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3688 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3690 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3692 */	NdrFcShort( 0xff6e ),	/* Offset= -146 (3546) */
/* 3694 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 3696 */	NdrFcShort( 0xc ),	/* 12 */
/* 3698 */	NdrFcShort( 0xc ),	/* 12 */
/* 3700 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3702 */	NdrFcShort( 0xff76 ),	/* Offset= -138 (3564) */
/* 3704 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 3706 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3708 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3710 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3712 */	NdrFcShort( 0xff7e ),	/* Offset= -130 (3582) */
/* 3714 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 3716 */	NdrFcShort( 0x14 ),	/* 20 */
/* 3718 */	NdrFcShort( 0x14 ),	/* 20 */
/* 3720 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3722 */	NdrFcShort( 0xff86 ),	/* Offset= -122 (3600) */
/* 3724 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 3726 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3728 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3730 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3732 */	NdrFcShort( 0xff8e ),	/* Offset= -114 (3618) */
/* 3734 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 3736 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3738 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3740 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3742 */	NdrFcShort( 0xff96 ),	/* Offset= -106 (3636) */
/* 3744 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 3746 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 3748 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 3750 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 3752 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 3754 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 3756 */	
			0x11, 0x0,	/* FC_RP */
/* 3758 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3760) */
/* 3760 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 3762 */	0x40,		/* Corr desc:  constant, val=32767 */
			0x0,		/* 0 */
/* 3764 */	NdrFcShort( 0x7fff ),	/* 32767 */
/* 3766 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3768 */	0x0 , 
			0x0,		/* 0 */
/* 3770 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3774 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3778 */	
			0x11, 0x0,	/* FC_RP */
/* 3780 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3782) */
/* 3782 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 3784 */	0x40,		/* Corr desc:  constant, val=337 */
			0x0,		/* 0 */
/* 3786 */	NdrFcShort( 0x151 ),	/* 337 */
/* 3788 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3790 */	0x0 , 
			0x0,		/* 0 */
/* 3792 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3796 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3800 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 3802 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3804) */
/* 3804 */	
			0x12, 0x0,	/* FC_UP */
/* 3806 */	NdrFcShort( 0xff6c ),	/* Offset= -148 (3658) */
/* 3808 */	0xb7,		/* FC_RANGE */
			0x8,		/* 8 */
/* 3810 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3814 */	NdrFcLong( 0x3e8 ),	/* 1000 */
/* 3818 */	
			0x11, 0x0,	/* FC_RP */
/* 3820 */	NdrFcShort( 0x3e ),	/* Offset= 62 (3882) */
/* 3822 */	0xb1,		/* FC_FORCED_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 3824 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3828 */	NdrFcShort( 0x8 ),	/* Offset= 8 (3836) */
/* 3830 */	0x6,		/* FC_SHORT */
			0x3e,		/* FC_STRUCTPAD2 */
/* 3832 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 3834 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 3836 */	
			0x12, 0x0,	/* FC_UP */
/* 3838 */	NdrFcShort( 0xf25a ),	/* Offset= -3494 (344) */
/* 3840 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 3842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3844 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 3846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3848 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 3850 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 3852 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3856 */	NdrFcLong( 0x3e8 ),	/* 1000 */
/* 3860 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 3864 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 3866 */	0x0 , 
			0x0,		/* 0 */
/* 3868 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3872 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3876 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 3878 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (3822) */
/* 3880 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 3882 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 3884 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3886 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 3888 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 3890 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3892 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3894 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 3896 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (3840) */
/* 3898 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 3900 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 3902 */	0xb7,		/* FC_RANGE */
			0x8,		/* 8 */
/* 3904 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3908 */	NdrFcLong( 0x3ed ),	/* 1005 */
/* 3912 */	
			0x11, 0x0,	/* FC_RP */
/* 3914 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3916) */
/* 3916 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 3918 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3920 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 3922 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3924 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 3926 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 3928 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3932 */	NdrFcLong( 0x3ed ),	/* 1005 */
/* 3936 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 3938 */	
			0x11, 0x0,	/* FC_RP */
/* 3940 */	NdrFcShort( 0x2a ),	/* Offset= 42 (3982) */
/* 3942 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x8,		/* FC_LONG */
/* 3944 */	0x8,		/* Corr desc: FC_LONG */
			0x0,		/*  */
/* 3946 */	NdrFcShort( 0xffe8 ),	/* -24 */
/* 3948 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 3950 */	0x0 , 
			0x0,		/* 0 */
/* 3952 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3956 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3960 */	NdrFcShort( 0x2 ),	/* Offset= 2 (3962) */
/* 3962 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3964 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3966 */	NdrFcLong( 0x1 ),	/* 1 */
/* 3970 */	NdrFcShort( 0x4 ),	/* Offset= 4 (3974) */
/* 3972 */	NdrFcShort( 0xffff ),	/* Offset= -1 (3971) */
/* 3974 */	
			0x15,		/* FC_STRUCT */
			0x1,		/* 1 */
/* 3976 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3978 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 3980 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 3982 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 3984 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3988 */	NdrFcShort( 0x0 ),	/* Offset= 0 (3988) */
/* 3990 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 3992 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 3994 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 3996 */	NdrFcShort( 0xf07a ),	/* Offset= -3974 (22) */
/* 3998 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 4000 */	NdrFcShort( 0xffc6 ),	/* Offset= -58 (3942) */
/* 4002 */	0x3e,		/* FC_STRUCTPAD2 */
			0x5b,		/* FC_END */
/* 4004 */	
			0x11, 0x0,	/* FC_RP */
/* 4006 */	NdrFcShort( 0x108 ),	/* Offset= 264 (4270) */
/* 4008 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x6,		/* FC_SHORT */
/* 4010 */	0x6,		/* Corr desc: FC_SHORT */
			0x0,		/*  */
/* 4012 */	NdrFcShort( 0xfff4 ),	/* -12 */
/* 4014 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4016 */	0x0 , 
			0x0,		/* 0 */
/* 4018 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4022 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4026 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4028) */
/* 4028 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4030 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4032 */	NdrFcLong( 0x2 ),	/* 2 */
/* 4036 */	NdrFcShort( 0xf9d4 ),	/* Offset= -1580 (2456) */
/* 4038 */	NdrFcLong( 0x3 ),	/* 3 */
/* 4042 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 4044 */	NdrFcLong( 0x4 ),	/* 4 */
/* 4048 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 4050 */	NdrFcLong( 0x5 ),	/* 5 */
/* 4054 */	NdrFcShort( 0x1c ),	/* Offset= 28 (4082) */
/* 4056 */	NdrFcLong( 0x9 ),	/* 9 */
/* 4060 */	NdrFcShort( 0x1a ),	/* Offset= 26 (4086) */
/* 4062 */	NdrFcLong( 0x6 ),	/* 6 */
/* 4066 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 4068 */	NdrFcLong( 0x7 ),	/* 7 */
/* 4072 */	NdrFcShort( 0x12 ),	/* Offset= 18 (4090) */
/* 4074 */	NdrFcLong( 0xc ),	/* 12 */
/* 4078 */	NdrFcShort( 0x4c ),	/* Offset= 76 (4154) */
/* 4080 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 4082 */	
			0x12, 0x0,	/* FC_UP */
/* 4084 */	NdrFcShort( 0xf164 ),	/* Offset= -3740 (344) */
/* 4086 */	
			0x12, 0x0,	/* FC_UP */
/* 4088 */	NdrFcShort( 0xf37c ),	/* Offset= -3204 (884) */
/* 4090 */	
			0x12, 0x0,	/* FC_UP */
/* 4092 */	NdrFcShort( 0x28 ),	/* Offset= 40 (4132) */
/* 4094 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 4096 */	NdrFcShort( 0x18 ),	/* 24 */
/* 4098 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 4100 */	NdrFcShort( 0xf370 ),	/* Offset= -3216 (884) */
/* 4102 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 4104 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 4106 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 4108 */	NdrFcShort( 0x18 ),	/* 24 */
/* 4110 */	0x16,		/* Corr desc:  field pointer, FC_SHORT */
			0x0,		/*  */
/* 4112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4114 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4116 */	0x0 , 
			0x0,		/* 0 */
/* 4118 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4122 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4126 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 4128 */	NdrFcShort( 0xffde ),	/* Offset= -34 (4094) */
/* 4130 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4132 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 4134 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4136 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 4138 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 4140 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4142 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4144 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 4146 */	NdrFcShort( 0xffd8 ),	/* Offset= -40 (4106) */
/* 4148 */	
			0x5b,		/* FC_END */

			0x6,		/* FC_SHORT */
/* 4150 */	0x6,		/* FC_SHORT */
			0x8,		/* FC_LONG */
/* 4152 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4154 */	
			0x12, 0x0,	/* FC_UP */
/* 4156 */	NdrFcShort( 0x8 ),	/* Offset= 8 (4164) */
/* 4158 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 4160 */	NdrFcShort( 0x80 ),	/* 128 */
/* 4162 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 4164 */	
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 4166 */	NdrFcShort( 0x80 ),	/* 128 */
/* 4168 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 4170 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (4158) */
/* 4172 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4174 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x6,		/* FC_SHORT */
/* 4176 */	0x6,		/* Corr desc: FC_SHORT */
			0x0,		/*  */
/* 4178 */	NdrFcShort( 0xfff0 ),	/* -16 */
/* 4180 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4182 */	0x0 , 
			0x0,		/* 0 */
/* 4184 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4188 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4192 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4194) */
/* 4194 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4196 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4198 */	NdrFcLong( 0x6 ),	/* 6 */
/* 4202 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 4204 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 4206 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4208 */	NdrFcShort( 0x14 ),	/* 20 */
/* 4210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4212 */	NdrFcShort( 0x0 ),	/* Offset= 0 (4212) */
/* 4214 */	0x6,		/* FC_SHORT */
			0x3e,		/* FC_STRUCTPAD2 */
/* 4216 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 4218 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 4220 */	NdrFcShort( 0xff2c ),	/* Offset= -212 (4008) */
/* 4222 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 4224 */	NdrFcShort( 0xffce ),	/* Offset= -50 (4174) */
/* 4226 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4228 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 4230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4232 */	0x16,		/* Corr desc:  field pointer, FC_SHORT */
			0x0,		/*  */
/* 4234 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4236 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4238 */	0x0 , 
			0x0,		/* 0 */
/* 4240 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4244 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4248 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 4252 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 4254 */	0x0 , 
			0x0,		/* 0 */
/* 4256 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4260 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4264 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 4266 */	NdrFcShort( 0xffc4 ),	/* Offset= -60 (4206) */
/* 4268 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4270 */	0xb1,		/* FC_FORCED_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4272 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4276 */	NdrFcShort( 0x8 ),	/* Offset= 8 (4284) */
/* 4278 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 4280 */	0x6,		/* FC_SHORT */
			0x3e,		/* FC_STRUCTPAD2 */
/* 4282 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 4284 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 4286 */	NdrFcShort( 0xffc6 ),	/* Offset= -58 (4228) */
/* 4288 */	
			0x11, 0x0,	/* FC_RP */
/* 4290 */	NdrFcShort( 0x28 ),	/* Offset= 40 (4330) */
/* 4292 */	
			0x1c,		/* FC_CVARRAY */
			0x1,		/* 1 */
/* 4294 */	NdrFcShort( 0x2 ),	/* 2 */
/* 4296 */	0x16,		/* Corr desc:  field pointer, FC_SHORT */
			0x55,		/* FC_DIV_2 */
/* 4298 */	NdrFcShort( 0x2 ),	/* 2 */
/* 4300 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4302 */	0x0 , 
			0x0,		/* 0 */
/* 4304 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4308 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4312 */	0x16,		/* Corr desc:  field pointer, FC_SHORT */
			0x55,		/* FC_DIV_2 */
/* 4314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4316 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4318 */	0x0 , 
			0x0,		/* 0 */
/* 4320 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4324 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4328 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 4330 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 4332 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4334 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 4336 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 4338 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4340 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4342 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 4344 */	NdrFcShort( 0xffcc ),	/* Offset= -52 (4292) */
/* 4346 */	
			0x5b,		/* FC_END */

			0x6,		/* FC_SHORT */
/* 4348 */	0x6,		/* FC_SHORT */
			0x8,		/* FC_LONG */
/* 4350 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4352 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 4354 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4356) */
/* 4356 */	
			0x12, 0x0,	/* FC_UP */
/* 4358 */	NdrFcShort( 0x112 ),	/* Offset= 274 (4632) */
/* 4360 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x6,		/* FC_SHORT */
/* 4362 */	0x6,		/* Corr desc: FC_SHORT */
			0x0,		/*  */
/* 4364 */	NdrFcShort( 0xfff4 ),	/* -12 */
/* 4366 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4368 */	0x0 , 
			0x0,		/* 0 */
/* 4370 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4374 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4378 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4380) */
/* 4380 */	NdrFcShort( 0x14 ),	/* 20 */
/* 4382 */	NdrFcShort( 0x3 ),	/* 3 */
/* 4384 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4388 */	NdrFcShort( 0xffc6 ),	/* Offset= -58 (4330) */
/* 4390 */	NdrFcLong( 0x1 ),	/* 1 */
/* 4394 */	NdrFcShort( 0xffc0 ),	/* Offset= -64 (4330) */
/* 4396 */	NdrFcLong( 0x2 ),	/* 2 */
/* 4400 */	NdrFcShort( 0x50 ),	/* Offset= 80 (4480) */
/* 4402 */	NdrFcShort( 0x92 ),	/* Offset= 146 (4548) */
/* 4404 */	
			0x1c,		/* FC_CVARRAY */
			0x1,		/* 1 */
/* 4406 */	NdrFcShort( 0x2 ),	/* 2 */
/* 4408 */	0x16,		/* Corr desc:  field pointer, FC_SHORT */
			0x55,		/* FC_DIV_2 */
/* 4410 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4412 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4414 */	0x0 , 
			0x0,		/* 0 */
/* 4416 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4420 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4424 */	0x16,		/* Corr desc:  field pointer, FC_SHORT */
			0x55,		/* FC_DIV_2 */
/* 4426 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4428 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4430 */	0x0 , 
			0x0,		/* 0 */
/* 4432 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4436 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4440 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 4442 */	
			0x1c,		/* FC_CVARRAY */
			0x1,		/* 1 */
/* 4444 */	NdrFcShort( 0x2 ),	/* 2 */
/* 4446 */	0x16,		/* Corr desc:  field pointer, FC_SHORT */
			0x55,		/* FC_DIV_2 */
/* 4448 */	NdrFcShort( 0xe ),	/* 14 */
/* 4450 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4452 */	0x0 , 
			0x0,		/* 0 */
/* 4454 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4458 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4462 */	0x16,		/* Corr desc:  field pointer, FC_SHORT */
			0x55,		/* FC_DIV_2 */
/* 4464 */	NdrFcShort( 0xc ),	/* 12 */
/* 4466 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4468 */	0x0 , 
			0x0,		/* 0 */
/* 4470 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4474 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4478 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 4480 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 4482 */	NdrFcShort( 0x14 ),	/* 20 */
/* 4484 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 4486 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 4488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4492 */	0x12, 0x0,	/* FC_UP */
/* 4494 */	NdrFcShort( 0xefca ),	/* Offset= -4150 (344) */
/* 4496 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 4498 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4500 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4502 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 4504 */	NdrFcShort( 0xff9c ),	/* Offset= -100 (4404) */
/* 4506 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 4508 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4510 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4512 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 4514 */	NdrFcShort( 0xffb8 ),	/* Offset= -72 (4442) */
/* 4516 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 4518 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 4520 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 4522 */	0x6,		/* FC_SHORT */
			0x8,		/* FC_LONG */
/* 4524 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4526 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 4528 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4530 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 4532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4534 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 4536 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 4538 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4542 */	NdrFcLong( 0x20000 ),	/* 131072 */
/* 4546 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 4548 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 4550 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4552 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 4554 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 4556 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4558 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4560 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 4562 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (4526) */
/* 4564 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 4566 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 4568 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 4570 */	NdrFcShort( 0x28 ),	/* 40 */
/* 4572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4574 */	NdrFcShort( 0x0 ),	/* Offset= 0 (4574) */
/* 4576 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 4578 */	0x3e,		/* FC_STRUCTPAD2 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 4580 */	0x0,		/* 0 */
			NdrFcShort( 0xf097 ),	/* Offset= -3945 (636) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 4584 */	0x0,		/* 0 */
			NdrFcShort( 0xff1f ),	/* Offset= -225 (4360) */
			0x40,		/* FC_STRUCTPAD4 */
/* 4588 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4590 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 4592 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4594 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 4596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4598 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 4600 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 4602 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4606 */	NdrFcLong( 0xfa0 ),	/* 4000 */
/* 4610 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 4612 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 4614 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4618 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4624 */	0x12, 0x0,	/* FC_UP */
/* 4626 */	NdrFcShort( 0xffc6 ),	/* Offset= -58 (4568) */
/* 4628 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 4630 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4632 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 4634 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4636 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 4638 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 4640 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4642 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4644 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 4646 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (4590) */
/* 4648 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 4650 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 4652 */	
			0x11, 0x0,	/* FC_RP */
/* 4654 */	NdrFcShort( 0xffea ),	/* Offset= -22 (4632) */
/* 4656 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 4658 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4660) */
/* 4660 */	
			0x12, 0x0,	/* FC_UP */
/* 4662 */	NdrFcShort( 0x3e ),	/* Offset= 62 (4724) */
/* 4664 */	0xb1,		/* FC_FORCED_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 4666 */	NdrFcShort( 0x14 ),	/* 20 */
/* 4668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4670 */	NdrFcShort( 0x0 ),	/* Offset= 0 (4670) */
/* 4672 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 4674 */	0x3e,		/* FC_STRUCTPAD2 */
			0x8,		/* FC_LONG */
/* 4676 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 4678 */	NdrFcShort( 0xfea4 ),	/* Offset= -348 (4330) */
/* 4680 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4682 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 4684 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4686 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 4688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4690 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4692 */	0x0 , 
			0x0,		/* 0 */
/* 4694 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4698 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4702 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 4704 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 4706 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4710 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4712 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4716 */	0x12, 0x0,	/* FC_UP */
/* 4718 */	NdrFcShort( 0xffca ),	/* Offset= -54 (4664) */
/* 4720 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 4722 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4724 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 4726 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4728 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 4730 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 4732 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4734 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4736 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 4738 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (4682) */
/* 4740 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 4742 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 4744 */	
			0x11, 0x0,	/* FC_RP */
/* 4746 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4748) */
/* 4748 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 4750 */	0x40,		/* Corr desc:  constant, val=32767 */
			0x0,		/* 0 */
/* 4752 */	NdrFcShort( 0x7fff ),	/* 32767 */
/* 4754 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4756 */	0x0 , 
			0x0,		/* 0 */
/* 4758 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4762 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4766 */	
			0x11, 0x0,	/* FC_RP */
/* 4768 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4770) */
/* 4770 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 4772 */	0x40,		/* Corr desc:  constant, val=32767 */
			0x0,		/* 0 */
/* 4774 */	NdrFcShort( 0x7fff ),	/* 32767 */
/* 4776 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4778 */	0x0 , 
			0x0,		/* 0 */
/* 4780 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4784 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4788 */	0xb7,		/* FC_RANGE */
			0x8,		/* 8 */
/* 4790 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4794 */	NdrFcLong( 0x3e8 ),	/* 1000 */
/* 4798 */	
			0x11, 0x0,	/* FC_RP */
/* 4800 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4802) */
/* 4802 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 4804 */	0x40,		/* Corr desc:  constant, val=32767 */
			0x0,		/* 0 */
/* 4806 */	NdrFcShort( 0x7fff ),	/* 32767 */
/* 4808 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4810 */	0x0 , 
			0x0,		/* 0 */
/* 4812 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4816 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4820 */	0xb7,		/* FC_RANGE */
			0x8,		/* 8 */
/* 4822 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4826 */	NdrFcLong( 0x100 ),	/* 256 */
/* 4830 */	
			0x11, 0x0,	/* FC_RP */
/* 4832 */	NdrFcShort( 0x10 ),	/* Offset= 16 (4848) */
/* 4834 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 4836 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4838 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 4840 */	NdrFcShort( 0xf08c ),	/* Offset= -3956 (884) */
/* 4842 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 4844 */	0x0,		/* 0 */
			NdrFcShort( 0xf087 ),	/* Offset= -3961 (884) */
			0x5b,		/* FC_END */
/* 4848 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 4850 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4852 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 4854 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4856 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 4858 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 4860 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4864 */	NdrFcLong( 0x100 ),	/* 256 */
/* 4868 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 4870 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (4834) */
/* 4872 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4874 */	0xb7,		/* FC_RANGE */
			0x8,		/* 8 */
/* 4876 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4880 */	NdrFcLong( 0x100 ),	/* 256 */
/* 4884 */	
			0x11, 0x0,	/* FC_RP */
/* 4886 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4888) */
/* 4888 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 4890 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4892 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 4894 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4896 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 4898 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 4900 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4904 */	NdrFcLong( 0x100 ),	/* 256 */
/* 4908 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 4910 */	NdrFcShort( 0xf046 ),	/* Offset= -4026 (884) */
/* 4912 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4914 */	
			0x11, 0x0,	/* FC_RP */
/* 4916 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4918) */
/* 4918 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 4920 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4922 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 4924 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4926 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 4928 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 4930 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4934 */	NdrFcLong( 0x100 ),	/* 256 */
/* 4938 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 4940 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 4942 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4946 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4948 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4952 */	0x12, 0x0,	/* FC_UP */
/* 4954 */	NdrFcShort( 0xff88 ),	/* Offset= -120 (4834) */
/* 4956 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 4958 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 4960 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 4962 */	NdrFcShort( 0x2 ),	/* Offset= 2 (4964) */
/* 4964 */	
			0x12, 0x0,	/* FC_UP */
/* 4966 */	NdrFcShort( 0x2c ),	/* Offset= 44 (5010) */
/* 4968 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 4970 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4972 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 4974 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4976 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 4978 */	0x0 , 
			0x0,		/* 0 */
/* 4980 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4984 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4988 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 4990 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 4992 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4994 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4996 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5002 */	0x12, 0x0,	/* FC_UP */
/* 5004 */	NdrFcShort( 0xedcc ),	/* Offset= -4660 (344) */
/* 5006 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 5008 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5010 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 5012 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5014 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 5016 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 5018 */	NdrFcShort( 0x4 ),	/* 4 */
/* 5020 */	NdrFcShort( 0x4 ),	/* 4 */
/* 5022 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5024 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (4968) */
/* 5026 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 5028 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 5030 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 5032 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5034) */
/* 5034 */	
			0x12, 0x0,	/* FC_UP */
/* 5036 */	NdrFcShort( 0x1c ),	/* Offset= 28 (5064) */
/* 5038 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 5040 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5042 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 5044 */	NdrFcShort( 0x4 ),	/* 4 */
/* 5046 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 5048 */	0x0 , 
			0x0,		/* 0 */
/* 5050 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5054 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5058 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 5060 */	NdrFcShort( 0xefb0 ),	/* Offset= -4176 (884) */
/* 5062 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 5064 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 5066 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5068 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 5070 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 5072 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5074 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5076 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5078 */	NdrFcShort( 0xffd8 ),	/* Offset= -40 (5038) */
/* 5080 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 5082 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 5084 */	
			0x11, 0x0,	/* FC_RP */
/* 5086 */	NdrFcShort( 0xef96 ),	/* Offset= -4202 (884) */
/* 5088 */	
			0x11, 0x0,	/* FC_RP */
/* 5090 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5092) */
/* 5092 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 5094 */	0x40,		/* Corr desc:  constant, val=32767 */
			0x0,		/* 0 */
/* 5096 */	NdrFcShort( 0x7fff ),	/* 32767 */
/* 5098 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5100 */	0x0 , 
			0x0,		/* 0 */
/* 5102 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5106 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5110 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5112 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5114) */
/* 5114 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 5116 */	0x40,		/* Corr desc:  constant, val=260 */
			0x0,		/* 0 */
/* 5118 */	NdrFcShort( 0x104 ),	/* 260 */
/* 5120 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5122 */	0x0 , 
			0x0,		/* 0 */
/* 5124 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5128 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5132 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5134 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5136) */
/* 5136 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 5138 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5140 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 5142 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5144 */	NdrFcShort( 0x10 ),	/* Corr flags:  */
/* 5146 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 5148 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5152 */	NdrFcLong( 0x400 ),	/* 1024 */
/* 5156 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 5158 */	0xb7,		/* FC_RANGE */
			0x8,		/* 8 */
/* 5160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5164 */	NdrFcLong( 0x400 ),	/* 1024 */
/* 5168 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5170 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5172) */
/* 5172 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 5174 */	0x40,		/* Corr desc:  constant, val=260 */
			0x0,		/* 0 */
/* 5176 */	NdrFcShort( 0x104 ),	/* 260 */
/* 5178 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5180 */	0x0 , 
			0x0,		/* 0 */
/* 5182 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5186 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5190 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5192 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5194) */
/* 5194 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 5196 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5198 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 5200 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5202 */	NdrFcShort( 0x10 ),	/* Corr flags:  */
/* 5204 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 5206 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5210 */	NdrFcLong( 0x400 ),	/* 1024 */
/* 5214 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 5216 */	0xb7,		/* FC_RANGE */
			0x8,		/* 8 */
/* 5218 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5222 */	NdrFcLong( 0x400 ),	/* 1024 */
/* 5226 */	
			0x11, 0x0,	/* FC_RP */
/* 5228 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5230) */
/* 5230 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x6,		/* FC_SHORT */
/* 5232 */	0x26,		/* Corr desc:  parameter, FC_SHORT */
			0x0,		/*  */
/* 5234 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5236 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5238 */	0x0 , 
			0x0,		/* 0 */
/* 5240 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5244 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5248 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5250) */
/* 5250 */	NdrFcShort( 0x18 ),	/* 24 */
/* 5252 */	NdrFcShort( 0x3 ),	/* 3 */
/* 5254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5258 */	NdrFcShort( 0x36 ),	/* Offset= 54 (5312) */
/* 5260 */	NdrFcLong( 0x1 ),	/* 1 */
/* 5264 */	NdrFcShort( 0x5e ),	/* Offset= 94 (5358) */
/* 5266 */	NdrFcLong( 0x2 ),	/* 2 */
/* 5270 */	NdrFcShort( 0xb6 ),	/* Offset= 182 (5452) */
/* 5272 */	NdrFcShort( 0xffff ),	/* Offset= -1 (5271) */
/* 5274 */	
			0x1c,		/* FC_CVARRAY */
			0x1,		/* 1 */
/* 5276 */	NdrFcShort( 0x2 ),	/* 2 */
/* 5278 */	0x16,		/* Corr desc:  field pointer, FC_SHORT */
			0x55,		/* FC_DIV_2 */
/* 5280 */	NdrFcShort( 0xa ),	/* 10 */
/* 5282 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5284 */	0x0 , 
			0x0,		/* 0 */
/* 5286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5294 */	0x16,		/* Corr desc:  field pointer, FC_SHORT */
			0x55,		/* FC_DIV_2 */
/* 5296 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5298 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5300 */	0x0 , 
			0x0,		/* 0 */
/* 5302 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5306 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5310 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 5312 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 5314 */	NdrFcShort( 0x18 ),	/* 24 */
/* 5316 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 5318 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 5320 */	NdrFcShort( 0x4 ),	/* 4 */
/* 5322 */	NdrFcShort( 0x4 ),	/* 4 */
/* 5324 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5326 */	NdrFcShort( 0xfbf6 ),	/* Offset= -1034 (4292) */
/* 5328 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 5330 */	NdrFcShort( 0xc ),	/* 12 */
/* 5332 */	NdrFcShort( 0xc ),	/* 12 */
/* 5334 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5336 */	NdrFcShort( 0xffc2 ),	/* Offset= -62 (5274) */
/* 5338 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 5340 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5342 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5344 */	0x11, 0x0,	/* FC_RP */
/* 5346 */	NdrFcShort( 0xec76 ),	/* Offset= -5002 (344) */
/* 5348 */	
			0x5b,		/* FC_END */

			0x6,		/* FC_SHORT */
/* 5350 */	0x6,		/* FC_SHORT */
			0x8,		/* FC_LONG */
/* 5352 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 5354 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 5356 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 5358 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 5360 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5362 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 5364 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 5366 */	NdrFcShort( 0x4 ),	/* 4 */
/* 5368 */	NdrFcShort( 0x4 ),	/* 4 */
/* 5370 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5372 */	NdrFcShort( 0xfbc8 ),	/* Offset= -1080 (4292) */
/* 5374 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 5376 */	NdrFcShort( 0xc ),	/* 12 */
/* 5378 */	NdrFcShort( 0xc ),	/* 12 */
/* 5380 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5382 */	NdrFcShort( 0xff94 ),	/* Offset= -108 (5274) */
/* 5384 */	
			0x5b,		/* FC_END */

			0x6,		/* FC_SHORT */
/* 5386 */	0x6,		/* FC_SHORT */
			0x8,		/* FC_LONG */
/* 5388 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 5390 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 5392 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 5394 */	NdrFcShort( 0x18 ),	/* 24 */
/* 5396 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 5398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5400 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 5402 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 5404 */	NdrFcLong( 0x1 ),	/* 1 */
/* 5408 */	NdrFcLong( 0x1000 ),	/* 4096 */
/* 5412 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 5414 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 5416 */	NdrFcShort( 0x18 ),	/* 24 */
/* 5418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5420 */	NdrFcShort( 0x3 ),	/* 3 */
/* 5422 */	NdrFcShort( 0x4 ),	/* 4 */
/* 5424 */	NdrFcShort( 0x4 ),	/* 4 */
/* 5426 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5428 */	NdrFcShort( 0xfb90 ),	/* Offset= -1136 (4292) */
/* 5430 */	NdrFcShort( 0xc ),	/* 12 */
/* 5432 */	NdrFcShort( 0xc ),	/* 12 */
/* 5434 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5436 */	NdrFcShort( 0xff5e ),	/* Offset= -162 (5274) */
/* 5438 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5440 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5442 */	0x11, 0x0,	/* FC_RP */
/* 5444 */	NdrFcShort( 0xec14 ),	/* Offset= -5100 (344) */
/* 5446 */	
			0x5b,		/* FC_END */

			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 5448 */	0x0,		/* 0 */
			NdrFcShort( 0xff77 ),	/* Offset= -137 (5312) */
			0x5b,		/* FC_END */
/* 5452 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 5454 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5456 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 5458 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 5460 */	NdrFcShort( 0x4 ),	/* 4 */
/* 5462 */	NdrFcShort( 0x4 ),	/* 4 */
/* 5464 */	0x11, 0x0,	/* FC_RP */
/* 5466 */	NdrFcShort( 0xffb6 ),	/* Offset= -74 (5392) */
/* 5468 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 5470 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 5472 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 5474 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5476) */
/* 5476 */	
			0x12, 0x0,	/* FC_UP */
/* 5478 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5480) */
/* 5480 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x6,		/* FC_SHORT */
/* 5482 */	0x26,		/* Corr desc:  parameter, FC_SHORT */
			0x0,		/*  */
/* 5484 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5486 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5488 */	0x0 , 
			0x0,		/* 0 */
/* 5490 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5494 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5498 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5500) */
/* 5500 */	NdrFcShort( 0x2 ),	/* 2 */
/* 5502 */	NdrFcShort( 0x3 ),	/* 3 */
/* 5504 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5508 */	NdrFcShort( 0xed5e ),	/* Offset= -4770 (738) */
/* 5510 */	NdrFcLong( 0x1 ),	/* 1 */
/* 5514 */	NdrFcShort( 0xed58 ),	/* Offset= -4776 (738) */
/* 5516 */	NdrFcLong( 0x2 ),	/* 2 */
/* 5520 */	NdrFcShort( 0xed52 ),	/* Offset= -4782 (738) */
/* 5522 */	NdrFcShort( 0xffff ),	/* Offset= -1 (5521) */
/* 5524 */	
			0x11, 0x0,	/* FC_RP */
/* 5526 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5528) */
/* 5528 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 5530 */	0x40,		/* Corr desc:  constant, val=1041 */
			0x0,		/* 0 */
/* 5532 */	NdrFcShort( 0x411 ),	/* 1041 */
/* 5534 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5536 */	0x0 , 
			0x0,		/* 0 */
/* 5538 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5542 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5546 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5548 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5550) */
/* 5550 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 5552 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5554 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 5556 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5558 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 5560 */	0x0 , 
			0x0,		/* 0 */
/* 5562 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5566 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5570 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 5572 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5574 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5576) */
/* 5576 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 5578 */	0x40,		/* Corr desc:  constant, val=1041 */
			0x0,		/* 0 */
/* 5580 */	NdrFcShort( 0x411 ),	/* 1041 */
/* 5582 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5584 */	0x0 , 
			0x0,		/* 0 */
/* 5586 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5590 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5594 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5596 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5598) */
/* 5598 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 5600 */	0x40,		/* Corr desc:  constant, val=1041 */
			0x0,		/* 0 */
/* 5602 */	NdrFcShort( 0x411 ),	/* 1041 */
/* 5604 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5606 */	0x0 , 
			0x0,		/* 0 */
/* 5608 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5612 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5616 */	
			0x11, 0x0,	/* FC_RP */
/* 5618 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5620) */
/* 5620 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 5622 */	0x40,		/* Corr desc:  constant, val=1041 */
			0x0,		/* 0 */
/* 5624 */	NdrFcShort( 0x411 ),	/* 1041 */
/* 5626 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5628 */	0x0 , 
			0x0,		/* 0 */
/* 5630 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5634 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5638 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5640 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5642) */
/* 5642 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 5644 */	0x40,		/* Corr desc:  constant, val=1041 */
			0x0,		/* 0 */
/* 5646 */	NdrFcShort( 0x411 ),	/* 1041 */
/* 5648 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5650 */	0x0 , 
			0x0,		/* 0 */
/* 5652 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5656 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5660 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5662 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5664) */
/* 5664 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 5666 */	0x40,		/* Corr desc:  constant, val=1041 */
			0x0,		/* 0 */
/* 5668 */	NdrFcShort( 0x411 ),	/* 1041 */
/* 5670 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5672 */	0x0 , 
			0x0,		/* 0 */
/* 5674 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5678 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5682 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5684 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5686) */
/* 5686 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 5688 */	0x40,		/* Corr desc:  constant, val=1041 */
			0x0,		/* 0 */
/* 5690 */	NdrFcShort( 0x411 ),	/* 1041 */
/* 5692 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5694 */	0x0 , 
			0x0,		/* 0 */
/* 5696 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5700 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5704 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5706 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5708) */
/* 5708 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 5710 */	0x40,		/* Corr desc:  constant, val=1041 */
			0x0,		/* 0 */
/* 5712 */	NdrFcShort( 0x411 ),	/* 1041 */
/* 5714 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5716 */	0x0 , 
			0x0,		/* 0 */
/* 5718 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5722 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5726 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5728 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5730) */
/* 5730 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 5732 */	0x40,		/* Corr desc:  constant, val=1041 */
			0x0,		/* 0 */
/* 5734 */	NdrFcShort( 0x411 ),	/* 1041 */
/* 5736 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5738 */	0x0 , 
			0x0,		/* 0 */
/* 5740 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5744 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5748 */	
			0x11, 0x0,	/* FC_RP */
/* 5750 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5752) */
/* 5752 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 5754 */	0x40,		/* Corr desc:  constant, val=1041 */
			0x0,		/* 0 */
/* 5756 */	NdrFcShort( 0x411 ),	/* 1041 */
/* 5758 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5760 */	0x0 , 
			0x0,		/* 0 */
/* 5762 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5766 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5770 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5772 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5774) */
/* 5774 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 5776 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5778 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 5780 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5782 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 5784 */	0x0 , 
			0x0,		/* 0 */
/* 5786 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5790 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5794 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 5796 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5798 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5800) */
/* 5800 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 5802 */	0x40,		/* Corr desc:  constant, val=1041 */
			0x0,		/* 0 */
/* 5804 */	NdrFcShort( 0x411 ),	/* 1041 */
/* 5806 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5808 */	0x0 , 
			0x0,		/* 0 */
/* 5810 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5814 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5818 */	
			0x11, 0x0,	/* FC_RP */
/* 5820 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5822) */
/* 5822 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 5824 */	0x40,		/* Corr desc:  constant, val=1041 */
			0x0,		/* 0 */
/* 5826 */	NdrFcShort( 0x411 ),	/* 1041 */
/* 5828 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5830 */	0x0 , 
			0x0,		/* 0 */
/* 5832 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5836 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5840 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5842 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5844) */
/* 5844 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 5846 */	0x40,		/* Corr desc:  constant, val=1041 */
			0x0,		/* 0 */
/* 5848 */	NdrFcShort( 0x411 ),	/* 1041 */
/* 5850 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5852 */	0x0 , 
			0x0,		/* 0 */
/* 5854 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5858 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5862 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5864 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5866) */
/* 5866 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 5868 */	0x40,		/* Corr desc:  constant, val=1041 */
			0x0,		/* 0 */
/* 5870 */	NdrFcShort( 0x411 ),	/* 1041 */
/* 5872 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5874 */	0x0 , 
			0x0,		/* 0 */
/* 5876 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5880 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5884 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5886 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5888) */
/* 5888 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 5890 */	0x40,		/* Corr desc:  constant, val=1041 */
			0x0,		/* 0 */
/* 5892 */	NdrFcShort( 0x411 ),	/* 1041 */
/* 5894 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5896 */	0x0 , 
			0x0,		/* 0 */
/* 5898 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5902 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5906 */	
			0x11, 0x0,	/* FC_RP */
/* 5908 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5910) */
/* 5910 */	
			0x25,		/* FC_C_WSTRING */
			0x44,		/* FC_STRING_SIZED */
/* 5912 */	0x40,		/* Corr desc:  constant, val=1041 */
			0x0,		/* 0 */
/* 5914 */	NdrFcShort( 0x411 ),	/* 1041 */
/* 5916 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 5918 */	0x0 , 
			0x0,		/* 0 */
/* 5920 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5924 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5928 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 5930 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5932) */
/* 5932 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5934 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5936) */
/* 5936 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 5938 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5940 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x54,		/* FC_DEREFERENCE */
/* 5942 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5944 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 5946 */	0x0 , 
			0x0,		/* 0 */
/* 5948 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5952 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5956 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 5958 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 5960 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5962) */
/* 5962 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 5964 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5966) */
/* 5966 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 5968 */	NdrFcShort( 0x1 ),	/* 1 */
/* 5970 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x54,		/* FC_DEREFERENCE */
/* 5972 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5974 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 5976 */	0x0 , 
			0x0,		/* 0 */
/* 5978 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5982 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5986 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 5988 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 5990 */	NdrFcShort( 0xe956 ),	/* Offset= -5802 (188) */
/* 5992 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 5994 */	NdrFcShort( 0x2 ),	/* Offset= 2 (5996) */
/* 5996 */	
			0x12, 0x0,	/* FC_UP */
/* 5998 */	NdrFcShort( 0xb8 ),	/* Offset= 184 (6182) */
/* 6000 */	
			0x1c,		/* FC_CVARRAY */
			0x1,		/* 1 */
/* 6002 */	NdrFcShort( 0x2 ),	/* 2 */
/* 6004 */	0x16,		/* Corr desc:  field pointer, FC_SHORT */
			0x55,		/* FC_DIV_2 */
/* 6006 */	NdrFcShort( 0x12 ),	/* 18 */
/* 6008 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 6010 */	0x0 , 
			0x0,		/* 0 */
/* 6012 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6016 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6020 */	0x16,		/* Corr desc:  field pointer, FC_SHORT */
			0x55,		/* FC_DIV_2 */
/* 6022 */	NdrFcShort( 0x10 ),	/* 16 */
/* 6024 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 6026 */	0x0 , 
			0x0,		/* 0 */
/* 6028 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6032 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6036 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 6038 */	
			0x1c,		/* FC_CVARRAY */
			0x1,		/* 1 */
/* 6040 */	NdrFcShort( 0x2 ),	/* 2 */
/* 6042 */	0x16,		/* Corr desc:  field pointer, FC_SHORT */
			0x55,		/* FC_DIV_2 */
/* 6044 */	NdrFcShort( 0x1a ),	/* 26 */
/* 6046 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 6048 */	0x0 , 
			0x0,		/* 0 */
/* 6050 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6054 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6058 */	0x16,		/* Corr desc:  field pointer, FC_SHORT */
			0x55,		/* FC_DIV_2 */
/* 6060 */	NdrFcShort( 0x18 ),	/* 24 */
/* 6062 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 6064 */	0x0 , 
			0x0,		/* 0 */
/* 6066 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6070 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6074 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 6076 */	
			0x16,		/* FC_PSTRUCT */
			0x7,		/* 7 */
/* 6078 */	NdrFcShort( 0x28 ),	/* 40 */
/* 6080 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 6082 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 6084 */	NdrFcShort( 0x4 ),	/* 4 */
/* 6086 */	NdrFcShort( 0x4 ),	/* 4 */
/* 6088 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 6090 */	NdrFcShort( 0xf8fa ),	/* Offset= -1798 (4292) */
/* 6092 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 6094 */	NdrFcShort( 0xc ),	/* 12 */
/* 6096 */	NdrFcShort( 0xc ),	/* 12 */
/* 6098 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 6100 */	NdrFcShort( 0xfcc6 ),	/* Offset= -826 (5274) */
/* 6102 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 6104 */	NdrFcShort( 0x14 ),	/* 20 */
/* 6106 */	NdrFcShort( 0x14 ),	/* 20 */
/* 6108 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 6110 */	NdrFcShort( 0xff92 ),	/* Offset= -110 (6000) */
/* 6112 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 6114 */	NdrFcShort( 0x1c ),	/* 28 */
/* 6116 */	NdrFcShort( 0x1c ),	/* 28 */
/* 6118 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 6120 */	NdrFcShort( 0xffae ),	/* Offset= -82 (6038) */
/* 6122 */	
			0x5b,		/* FC_END */

			0x6,		/* FC_SHORT */
/* 6124 */	0x6,		/* FC_SHORT */
			0x8,		/* FC_LONG */
/* 6126 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 6128 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 6130 */	0x6,		/* FC_SHORT */
			0x8,		/* FC_LONG */
/* 6132 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 6134 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 6136 */	0x0,		/* 0 */
			NdrFcShort( 0xea83 ),	/* Offset= -5501 (636) */
			0x5b,		/* FC_END */
/* 6140 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 6142 */	NdrFcShort( 0x4 ),	/* 4 */
/* 6144 */	0x18,		/* Corr desc:  field pointer, FC_LONG */
			0x0,		/*  */
/* 6146 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6148 */	NdrFcShort( 0x11 ),	/* Corr flags:  early, */
/* 6150 */	0x1 , /* correlation range */
			0x0,		/* 0 */
/* 6152 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6156 */	NdrFcLong( 0x3e8 ),	/* 1000 */
/* 6160 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 6162 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 6164 */	NdrFcShort( 0x4 ),	/* 4 */
/* 6166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6168 */	NdrFcShort( 0x1 ),	/* 1 */
/* 6170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6174 */	0x12, 0x0,	/* FC_UP */
/* 6176 */	NdrFcShort( 0xff9c ),	/* Offset= -100 (6076) */
/* 6178 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 6180 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 6182 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 6184 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6186 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 6188 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 6190 */	NdrFcShort( 0x4 ),	/* 4 */
/* 6192 */	NdrFcShort( 0x4 ),	/* 4 */
/* 6194 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 6196 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (6140) */
/* 6198 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 6200 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */

			0x0
        }
    };

static const rpc_MIDL_EXPR_FORMAT_STRING rpc__MIDL_ExprFormatString =
    {
        0,
        {
			0x4,		/* FC_EXPR_OPER */
			0xf,		/* OP_MINUS */
/*  2 */	0x0,		/*  */
			0x0,		/* 0 */
/*  4 */	0x3,		/* FC_EXPR_VAR */
			0x6,		/* FC_SHORT */
/*  6 */	NdrFcShort( 0xfffe ),	/* -2 */
/*  8 */	0x1,		/* FC_EXPR_CONST32 */
			0x8,		/* FC_LONG */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcLong( 0x4 ),	/* 4 */

			0x0
        }
    };

static const unsigned short rpc__MIDL_ExprFormatStringOffsetTable[] =
{
0,
};

static const NDR_EXPR_DESC  rpc_ExprDesc = 
 {
rpc__MIDL_ExprFormatStringOffsetTable,
rpc__MIDL_ExprFormatString.Format
};

static const unsigned short DefaultIfName_FormatStringOffsetTable[] =
    {
    0,
    42,
    84,
    144,
    198,
    252,
    316,
    370,
    424,
    478,
    520,
    580,
    640,
    700,
    760,
    838,
    910,
    970,
    1030,
    1078,
    1126,
    1180,
    1228,
    1276,
    1324,
    1372,
    1432,
    1486,
    1540,
    1600,
    1654,
    1720,
    1774,
    1828,
    1900,
    1942,
    1996,
    2050,
    2104,
    2164,
    2224,
    2284,
    2332,
    2386,
    2440,
    2494,
    2546,
    2600,
    2654,
    2714,
    2774,
    2834,
    2900,
    2942,
    2996,
    3050,
    3110,
    3170,
    3254,
    3344,
    3410,
    3462,
    3526,
    3584,
    3642,
    3700,
    3758,
    3816,
    3856,
    3946,
    3998,
    4040,
    4094,
    4136,
    4196,
    4268,
    4332,
    4408,
    4490,
    4544,
    4592,
    4640,
    4706,
    4770,
    4834,
    4904,
    4950,
    4996,
    5054,
    5106,
    5158,
    5210,
    5262,
    5338,
    5402,
    5478,
    5536,
    5576,
    5652,
    5728,
    5816,
    5886,
    5938,
    6008,
    6060,
    6112,
    6158,
    6204,
    6244
    };


static const MIDL_STUB_DESC DefaultIfName_StubDesc = 
    {
    (void *)& DefaultIfName___RpcClientInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    &DefaultIfName__MIDL_AutoBindHandle,
    0,
    0,
    0,
    0,
    rpc__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x60001, /* Ndr library version */
    0,
    0x801026e, /* MIDL Version 8.1.622 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    &rpc_ExprDesc
    };
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_) */

