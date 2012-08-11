/*++

Copyright (C) 2012 The Little Beige Box, http://www.beige-box.com
Licensed under the GNU General Public License v3.

Module Name:

    private.c

Abstract:

    Private API for Windows SLC redpill patch.

Revision History:

--*/

#include "redpill.h"

HRESULT
WINAPI
SLConsumeWindowsRight(
    __in HSLC hSLC
    )
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SL1ARGS_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLReArmWindows(
    VOID
    )
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SL0ARGS_ROUTINE, __FUNCTION__);
    tempResult = Procedure();
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLIsWindowsGenuineLocal(
    __in HSLC hSLC
    )
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SL1ARGS_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLRegisterWindowsEvent(
    __in PVOID pArg0,
    __in PVOID pArg1
    )
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SL2ARGS_ROUTINE, __FUNCTION__);
    tempResult = Procedure(pArg0, pArg1);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLUnregisterWindowsEvent(
    __in PVOID pArg0,
    __in PVOID pArg1
    )
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SL2ARGS_ROUTINE, __FUNCTION__);
    tempResult = Procedure(pArg0, pArg1);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLpCheckProductKey(
    __in HSLC hSLC,
    __in PVOID pArg1
    )
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SL2ARGS_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pArg1);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLpProcessOemProductKey(
    __in HSLC hSLC,
    __in PVOID pArg1
    )
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SL2ARGS_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pArg1);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLpUpdateComponentTokens(
    __in HSLC hSLC,
    __in PVOID pArg1
    )
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SL2ARGS_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pArg1);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLpGetGenuineLocal(
    __in PVOID pArg0,
    __in PVOID pArg1,
    __in PVOID pArg2
    )
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SL3ARGS_ROUTINE, __FUNCTION__);
    tempResult = Procedure(pArg0, pArg1, pArg2);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SlpGetWindowsKitchenSink(void) {
    return; /* We need to use the Solaris Super Tools Implementation Method. */
}
