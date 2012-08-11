/*++

Copyright (C) 2012 The Little Beige Box, http://www.beige-box.com
Licensed under the GNU General Public License v3.

Module Name:

    info.c

Abstract:

    Info API for Windows SLC redpill patch.

Revision History:

--*/

#include "redpill.h"
#include <wchar.h>

HRESULT 
WINAPI
SLGetWindowsInformation(
    _In_                        PCWSTR                      pwszValueName,
    _Out_opt_                   SLDATATYPE*                 peDataType,
    _Out_                       UINT*                       pcbValue,
    _Outptr_result_bytebuffer_(*pcbValue) PBYTE*            ppbValue
    )
/*++
Routine Description:

    This function is used to for Windows components to get 
    component policy value.
    
Arguments:

    pwszValueName
        The name of the requested value.
        
    peDataType
        Data type. Following types are supported:
            SL_DATA_SZ     - UNICODE string
            SL_DATA_DWORD  - DWORD
            SL_DATA_BINARY - Binary blob
        
    pcbValue
        Size of the allocated buffer.
        
    ppbValue
        The value. If successful, the data is returned in the buffer 
        allocated by SLC.
        The caller has to call SLFreeMemory to free the memory. 
        
Return Error:
    E_INVALIDARG
    SL_E_VALUE_NOT_FOUND
    Other error codes.
    
--*/
{
    //
    // Check if this oid is supported by us.
    //

    if(wcsstr(pwszValueName, L"SLC-Component-RP")) {
           DWORD* yesValue = (DWORD*)LocalAlloc(LPTR, sizeof(DWORD));
           if(!yesValue) {
               RETURN_ERROR(ERROR_INVALID_HANDLE);
           }
           
           *yesValue = (0x00000001);    // windows wants it le, not be

           //
           // Return values
           //

           *peDataType = SL_DATA_DWORD;
           *pcbValue = sizeof(DWORD);
           ppbValue = (PBYTE*)yesValue;

           RETURN_ERROR(S_OK);

    } else {

        //
        // Not us.
        //

        PREPARE_LIBRARY(REAL_DLL_NAME, SLGETWINDOWSINFORMATION_ROUTINE, __FUNCTION__);
        tempResult = Procedure(pwszValueName, peDataType, pcbValue, ppbValue);
        DECONSTRUCT_LIBRARY();
        return tempResult;
    }
}

unsigned long __stdcall DbgPrint(char* fmt, ...);

HRESULT 
WINAPI
SLGetWindowsInformationDWORD(
    _In_ PCWSTR pwszValueName,
    _Out_ DWORD* pdwValue
    )
/*++
Routine Description:

    This function is used to for Windows components to get 
    component policy DWORD value.

Arguments:

    pwszValueName
        The name of the requested value.
        
    pdwValue
        The buffer to receive DWORD value
        
Return Error:
    E_INVALIDARG
    SL_E_VALUE_NOT_FOUND
    SL_E_DATATYPE_MISMATCHED
    Other error codes.
    
--*/
{
    //
    // Not us.
    //

    PREPARE_LIBRARY(REAL_DLL_NAME, SLGETWINDOWSINFORMATIONDWORD_ROUTINE, __FUNCTION__);
    tempResult = Procedure(pwszValueName, pdwValue);
    if(wcsstr(pwszValueName, L"RP") ||
       wcsstr(pwszValueName, L"SPP") ||
       wcsstr(pwszValueName, L"Enabled") ||
       wcsstr(pwszValueName, L"explorer") ||
       wcsstr(pwszValueName, L"twinui") ||
       wcsstr(pwszValueName, L"Microsoft-Windows")
    ) {
		
		//
		// Always genuine :)
		//

        *pdwValue = 0x1;
        tempResult = S_OK;
    }
    DECONSTRUCT_LIBRARY();
    return tempResult;

}