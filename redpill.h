/*++

Copyright (C) 2012 The Little Beige Box, http://www.beige-box.com
Licensed under the GNU General Public License v3.

Module Name:

    redpill.h

Abstract:

    Main header for Windows redpill patch.

Revision History:

--*/

#ifndef _REDPILL_H_
#define _REDPILL_H_

#include <Windows.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "api.h"

#ifdef __cplusplus
}
#endif

#include "sal.h"
#include "slpublic.h"

#include <WinSock2.h>

#define REAL_DLL_NAME        "slcrp.dll"
#define SPPC_DLL_NAME        "sppc.dll"


#define DebugPrint(x, ...)

#pragma warning(disable:4090)

#define PREPARE_LIBRARY(x,y,z)                      \
        HINSTANCE hModule;                          \
        HRESULT tempResult;                         \
        y Procedure;                                \
                                                    \
        hModule = LoadLibrary(TEXT(x));             \
        if(!hModule) {                              \
            DebugPrint("Module failed to load.");   \
            SetLastError(ERROR_INVALID_HANDLE);     \
            return HRESULT_FROM_WIN32(ERROR_INVALID_HANDLE); \
        }                                           \
                                                    \
        Procedure = (y)GetProcAddress(hModule, z);  \
        if(!Procedure) {                            \
            DebugPrint("Failed to get procedure."); \
            SetLastError(ERROR_INVALID_HANDLE);     \
            return HRESULT_FROM_WIN32(ERROR_INVALID_HANDLE); \
        }                                           

#define DECONSTRUCT_LIBRARY()                       \
        FreeLibrary(hModule);                       \
        Procedure = NULL;                           \
        SetLastError(tempResult);

#define RETURN_ERROR(x)                             \
        SetLastError(x);                            \
        return HRESULT_FROM_WIN32(x);

#ifndef WINAPI
#define WINAPI __stdcall
#endif

#endif