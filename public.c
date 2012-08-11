/*++

Copyright (C) 2012 The Little Beige Box, http://www.beige-box.com
Licensed under the GNU General Public License v3.

Module Name:

    public.c

Abstract:

    Public API for Windows SLC redpill patch.

Revision History:

--*/

#include "redpill.h"

HRESULT
WINAPI
SLOpen(
    _Out_                       HSLC*                       phSLC
    )
/*++
Routine Description:
    Initializes the Software Licensing Client (SLC)
    and connect SLC to Software Licensing Service (SLS).
    If succeeds, a context handle is returned for subsequent calls.

Arguments:
    phSLC
        Pointer to context handle returned from service.

Return Error:
    E_INVALIDARG
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLOPEN_ROUTINE, __FUNCTION__);
    tempResult = Procedure(phSLC);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLClose(
    _In_                        HSLC                        hSLC
    )
/*++
Routine Description:

    Close SLC context handle. When this function is called,
    the associated context on SL service is released.

Arguments:

    hSLC
        Handle to current SLC context.

Return Error:

    E_INVALIDARG
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLCLOSE_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}


HRESULT
WINAPI
SLInstallProofOfPurchase(
    _In_                    HSLC                            hSLC,
    _In_                    PCWSTR                          pwszPKeyAlgorithm,
    _In_                    PCWSTR                          pwszPKeyString,
    _In_                    UINT                            cbPKeySpecificData,
    _In_reads_bytes_opt_(cbPKeySpecificData) PBYTE          pbPKeySpecificData,
    _Out_                   SLID*                           pPkeyId
    )
/*+
Routine Description:

    Register the product key with SL.

Arguments:

    hSLC
        Handle to current SLC context.

    pwszPKeyAlgorithm
        Product Key algorithm.

    pwszPKeyString
        Product key string (e.g. 5x5 string).

    cbPKeySpecificData
        Size of product key specific data. If no PKey specific data, set to 0.

    pbPKeySpecificData
        Product key specific data. If no PKey specific data, set to NULL.

    pPkeyId
        An Identifier of the registered Product key, so caller
        can reference PKey information later.

Return Error:

    E_INVALIDARG
    E_ACCESSDENIED
    SL_E_LUA_ACCESSDENIED
    SL_E_INVALID_PKEY
    SL_E_PRODUCT_SKU_NOT_INSTALLED
    SL_E_UNSUPPORTED
    SL_E_PKEY_INVALID_UPGRADE
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLINSTALLPROOFOFPURCHASE_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pwszPKeyAlgorithm, pwszPKeyString, cbPKeySpecificData,
                           pbPKeySpecificData, pPkeyId);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLInstallProofOfPurchaseEx(
    _In_                    HSLC                            hSLC,
    _In_                    CONST SLID*                     pApplicationId,
    _In_opt_                CONST SLID*                     pProductSkuId,
    _In_                    PCWSTR                          pwszPKeyAlgorithm,
    _In_                    PCWSTR                          pwszPKeyString,
    _In_                    UINT                            cbPKeySpecificData,
    _In_reads_bytes_opt_(cbPKeySpecificData) PBYTE          pbPKeySpecificData,
    _Out_                   SLID*                           pPkeyId
    )
/*+
Routine Description:

    Register the product key with SL.

Arguments:

    hSLC
        Handle to current SLC context.

    pApplicationId
        Application Id

    pProductSkuId
        Product Sku Id

    pwszPKeyAlgorithm
        Product Key algorithm.

    pwszPKeyString
        Product key string (e.g. 5x5 string).

    cbPKeySpecificData
        Size of product key specific data. If no PKey specific data, set to 0.

    pbPKeySpecificData
        Product key specific data. If no PKey specific data, set to NULL.

    pPkeyId
        An Identifier of the registered Product key, so caller
        can reference PKey information later.

Return Error:

    E_INVALIDARG
    E_ACCESSDENIED
    SL_E_LUA_ACCESSDENIED
    SL_E_INVALID_PKEY
    SL_E_PRODUCT_SKU_NOT_INSTALLED
    SL_E_UNSUPPORTED
    SL_E_PKEY_INVALID_UPGRADE
    SL_E_MISMATCHED_PRODUCT_SKU
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLINSTALLPROOFOFPURCHASEEX_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pApplicationId, pProductSkuId,
                           pwszPKeyAlgorithm, pwszPKeyString, cbPKeySpecificData,
                           pbPKeySpecificData, pPkeyId);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}


HRESULT
WINAPI
SLUninstallProofOfPurchase(
    _In_                        HSLC                        hSLC,
    _In_                        CONST SLID*                 pPKeyId
    )
/*++
Routine Description:

    Unregister the product key information.

Arguments:

    hSLC
        Handle to current SLC context.

    pPkeyId
        Identifier of the registered Product key.

Return Error:

    E_INVALIDARG
    E_ACCESSDENIED
    SL_E_LUA_ACCESSDENIED
    SL_E_PKEY_NOT_INSTALLED
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLUNINSTALLPROOFOFPURCHASE_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pPKeyId);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLInstallLicense(
    _In_                        HSLC                        hSLC,
    _In_                        UINT                        cbLicenseBlob,
    _In_reads_bytes_(cbLicenseBlob)  CONST BYTE*            pbLicenseBlob,
    _Out_                       SLID*                       pLicenseFileId
    )
/*++
Routine Description:

    Callers pass in license blob (in bytes) and size of blob.
    SL stores the license and returned a license file Id.

Arguments:

    hSLC
        Handle to current SLC context.

    cbLicenseBlob
        Size of license blob

    pbLicenseBlob
        licenses in blob. The caller can open/read license file or
        receives the blob from

    pLicenseFileId
        License File Id

Return Error:

    E_INVALIDARG
    E_ACCESSDENIED
    SL_E_LUA_ACCESSDENIED
    SL_E_INVALID_LICENSE
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLINSTALLLICENSE_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, cbLicenseBlob, pbLicenseBlob, pLicenseFileId);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}


HRESULT
WINAPI
SLUninstallLicense(
    _In_                        HSLC                        hSLC,
    _In_                        CONST SLID*                 pLicenseFileId
    )
/*++
Routine Description:

    Uninstall a license file according to license file Id and target
    user option.

Arguments:

    hSLC
        Handle to current SLC context.

    pLicenseFileId
        License file Id.

Return Error:

    E_INVALIDARG
    E_ACCESSDENIED
    SL_E_LUA_ACCESSDENIED
    SL_E_LICENSE_FILE_NOT_INSTALLED
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLUNINSTALLLICENSE_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pLicenseFileId);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}


HRESULT
WINAPI
SLConsumeRight(
    _In_                        HSLC                        hSLC,
    _In_                        CONST SLID*                 pAppId,
    _In_opt_                    CONST SLID*                 pProductSkuId,
    _In_opt_                    PCWSTR                      pwszRightName,
    _Reserved_                  PVOID                       pvReserved
    )
/*++
Routine Description:

    Let an application to exercise rights on a locally-stored licenses.
    Calling this function binds a license to the right. If this right
    cannot be exercised, then the application gets failed result.

Arguments:

    hSLC
        Handle to current SLC context.

    pAppId
        The identifier of the application who's right is going to be
        consumed.

    pProductSkuId
        The identifier of Product SKU. If NULL, all Product  SKU's
        licenses will be consumed.

    pwszRightName
        The name of right to be consumed.

    pvReserved
        Reserved.

Return Error:

    E_INVALIDARG
    SL_E_RIGHT_NOT_GRANTED
    SL_E_PRODUCT_SKU_NOT_INSTALLED
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLCONSUMERIGHT_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pAppId, pProductSkuId, pwszRightName, pvReserved);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}


HRESULT
WINAPI
SLGetProductSkuInformation(
    _In_                        HSLC                        hSLC,
    _In_                        CONST SLID*                 pProductSkuId,
    _In_                        PCWSTR                      pwszValueName,
    _Out_opt_                   SLDATATYPE*                 peDataType,
    _Out_                       UINT*                       pcbValue,
    _Outptr_result_bytebuffer_(*pcbValue) PBYTE*            ppbValue
    )
/*++
Routine Description:

    Get information about specified product Sku.

Arguments:
    hSLC
        Handle to current SLC context.

    pwszValueName
        SL_INFO_KEY_NAME
            Return Type = SL_DATA_SZ
            Return Data = The product name
        SL_INFO_KEY_DESCRIPTION
            Return Type = SL_DATA_SZ
            Return Data = Description of the product
        SL_INFO_KEY_AUTHOR
            Return Type = SL_DATA_SZ
            Return Data = Author of the product

        The caller can also query the value specified in public OOB
        otherInfo. (use same key name defined there)

    peDataType
        Data type. Following types are supported:
            SL_DATA_SZ     - UNICODE string
            SL_DATA_DWORD  - DWORD
            SL_DATA_BINARY - Binary blob

    pcbValue
        Size of the allocated buffer.

    ppbValue
        If successful, the data is returned in the buffer allocated by SLC.
        The caller has to call LocalFree to free the memory.

Return Error:
    E_INVALIDARG
    SL_E_VALUE_NOT_FOUND
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLGETPRODUCTSKUINFORMATION_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pProductSkuId, pwszValueName, peDataType, pcbValue,
                           ppbValue);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLGetPKeyInformation(
    _In_                        HSLC                        hSLC,
    _In_                        CONST SLID*                 pPKeyId,
    _In_                        PCWSTR                      pwszValueName,
    _Out_opt_                   SLDATATYPE*                 peDataType,
    _Out_                       UINT*                       pcbValue,
    _Outptr_result_bytebuffer_(*pcbValue) PBYTE*            ppbValue
    )
/*++
Routine Description:

    Get information of specified product key

Arguments:
    hSLC
        Handle to current SLC context.

    pwszValueName
        SL_INFO_KEY_DIGITAL_PID
            Return Type = SL_DATA_SZ
            Return Data = Formatted PID structure for a PID4
        SL_INFO_KEY_DIGITAL_PID2
            Return Type = SL_DATA_SZ
            Return Data = Formatted PID structure for a PID2
        SL_INFO_KEY_PARTIAL_PRODUCT_KEY
            Return Type = SL_DATA_SZ
            Return Data = First 5 characters of Product Key
        SL_INFO_KEY_PRODUCT_SKU_ID
            Return Type = SL_DATA_BINARY (SLID)
            Return Data = Sku SLID
        SL_INFO_KEY_CHANNEL
            Return Type SL_DATA_SZ
            Return Data = Channel Id

    peDataType
        Data type. Following types are supported:
            SL_DATA_SZ     - UNICODE string
            SL_DATA_DWORD  - DWORD
            SL_DATA_BINARY - Binary blob

    pcbValue
        Size of the allocated buffer.

    ppbValue
        If successful, the data is returned in the buffer allocated by SLC.
        The caller has to call LocalFree to free the memory.

Return Error:
    E_INVALIDARG
    SL_E_PKEY_NOT_INSTALLED
    SL_E_NOT_SUPPORTED
    
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLGETPKEYINFORMATION_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pPKeyId, pwszValueName,
                           peDataType, pcbValue, ppbValue);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}


HRESULT
WINAPI
SLGetLicenseInformation(
    _In_                        HSLC                        hSLC,
    _In_                        CONST SLID*                 pSLLicenseId,
    _In_                        PCWSTR                      pwszValueName,
    _Out_opt_                   SLDATATYPE*                 peDataType,
    _Out_                       UINT*                       pcbValue,
    _Outptr_result_bytebuffer_(*pcbValue) PBYTE*            ppbValue
    )
/*++
Routine Description:
    Get information of specified license

Arguments:
    hSLC
        Handle to current SLC context.

    pwszValueName
        SL_INFO_KEY_DESCRIPTION
            Return Type = SL_DATA_SZ
            Return Data = Description of the license
        SL_INFO_KEY_LICENSE_TYPE
            Return Type = SL_DATA_SZ
            Return Data = The type of the license
        SL_INFO_KEY_VERSION
            Return Type = SL_DATA_SZ
            Return Data = The version of the license

        The caller can also query the value specified in license's
        otherInfo. (use same key name defined there)

    peDataType
        Data type. Following types are supported:
            SL_DATA_SZ     - UNICODE string
            SL_DATA_DWORD  - DWORD
            SL_DATA_BINARY - Binary blob

    pcbValue
        Size of the allocated buffer.

    ppbValue
        If successful, the data is returned in the buffer allocated by SLC.
        The caller has to call LocalFree to free the memory.

Return Error:
    E_INVALIDARG
    SL_E_VALUE_NOT_FOUND

--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLGETLICENSEINFORMATION_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pSLLicenseId, pwszValueName, peDataType, pcbValue, ppbValue);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}


HRESULT
WINAPI
SLGetLicensingStatusInformation(
    _In_                        HSLC                        hSLC,
    _In_opt_                    CONST SLID*                 pAppID,
    _In_opt_                    CONST SLID*                 pProductSkuId,
    _In_opt_                    PCWSTR                      pwszRightName,
    _Out_                       UINT*                       pnStatusCount,
    _Outptr_result_buffer_(*pnStatusCount) SL_LICENSING_STATUS** ppLicensingStatus
    )
/*++
Routine Description:

    Get information of licensing status of specified application/Sku

Arguments:
    hSLC
        Handle to current SLC context.

    pAppID, pProductSkuId
        Optional.
            pAppID=NULL, pProductSkuId=NULL
                Get previous right consumption result.
            pAppID=NULL, pProductSkuId=not NULL
                Get licensing status of this Sku
            pAppID=not NULL, pProductSkuId=NULL
                Get licensing status of this Application
            pAppID=not NULL, pProductSkuId=not NULL
                Get licensing status of this Application/Sku

    pwszRightName
        NULL

    pnStatusCount
        Number of Sku's status

    ppLicensingStatus
        Sku's status

Return Error:
    E_INVALIDARG
    SL_E_RIGHT_NOT_CONSUMED

--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLGETLICENSINGSTATUSINFORMATION_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pAppID, pProductSkuId, pwszRightName, pnStatusCount,
                           ppLicensingStatus);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}


HRESULT
WINAPI
SLGetPolicyInformation(
    _In_                        HSLC                        hSLC,
    _In_                        PCWSTR                      pwszValueName,
    _Out_opt_                   SLDATATYPE*                 peDataType,
    _Out_                       UINT*                       pcbValue,
    _Outptr_result_bytebuffer_(*pcbValue) PBYTE*            ppbValue
    )
/*++
Routine Description:

    Get information of poliy after right has been consumed successfully

Arguments:
    hSLC
        Handle to current SLC context.

    pwszValueName
        The name of the policy name

    peDataType
        Data type. Following types are supported:
            SL_DATA_SZ     - UNICODE string
            SL_DATA_DWORD  - DWORD
            SL_DATA_BINARY - Binary blob

    pcbValue
        Size of the allocated buffer.

    ppbValue
        If successful, the data is returned in the buffer allocated by SLC.
        The caller has to call LocalFree to free the memory.

Return Error:
    E_INVALIDARG
    SL_E_VALUE_NOT_FOUND
    SL_E_RIGHT_NOT_GRANTED

--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLGETPOLICYINFORMATION_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pwszValueName, peDataType, pcbValue, ppbValue);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLGetPolicyInformationDWORD(
    _In_                        HSLC                        hSLC,
    _In_                        PCWSTR                      pwszValueName,
    _Out_                       DWORD*                      pdwValue
    )
/*++
Routine Description:

    Sililar to SLGetPolicyInformation.
    Callers pass in a dword buffer.

Arguments:
    hSLC
        Handle to current SLC context.

    pwszValueName
        The name of the policy name

    pdwValue
        Return value

Return Error:
    E_INVALIDARG
    SL_E_VALUE_NOT_FOUND
    SL_E_RIGHT_NOT_GRANTED
    SL_E_DATATYPE_MISMATCHED

--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLGETPOLICYINFORMATIONDWORD_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pwszValueName, pdwValue);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLGetServiceInformation(
    _In_                        HSLC                        hSLC,
    _In_                        PCWSTR                      pwszValueName,
    _Out_opt_                   SLDATATYPE*                 peDataType,
    _Out_                       UINT*                       pcbValue,
    _Outptr_result_bytebuffer_(*pcbValue) PBYTE*            ppbValue
    )
/*++
Routine Description:

    Get information of global data, like service version,
    tamper status ... etc.

Arguments:
    hSLC
        Handle to current SLC context.

    pwszValueName
        The name of the key for query.

        SL_INFO_KEY_VERSION
            version of SL service. e.g. "1.2.3.4"
            Return Type = SL_DATA_SZ

        SL_INFO_KEY_SYSTEM_STATE
            System state
                SL_SYSTEM_STATE_TAMPERED
                SL_SYSTEM_STATE_REBOOT_POLICY_FOUND
            Return Type = SL_DATA_DWORD
            
        SL_INFO_KEY_ACTIVE_PLUGINS
            Return Type = SL_DATA_MULTI_SZ
            Return Data = Fully-qualified DLL paths for all active plugins
                          (NULL-delimited and double-NULL terminated)

        SL_INFO_KEY_SECURE_STORE_ID
            Return Type = SL_DATA_SZ
            Return Data = Secure store ID (GUID)

        SL_INFO_KEY_SESSION_MACHINE_ID
            Return Type = SL_DATA_BINARY
            Return Data = Session machine ID (Binary Blob)
            
    peDataType
        Data type. Following types are supported:
            SL_DATA_SZ       - UNICODE string
            SL_DATA_DWORD    - DWORD
            SL_DATA_BINARY   - Binary blob
            SL_DATA_MULTI_SZ - Double-NULL terminated UNICODE string array

    pcbValue
        Size of the allocated buffer.

    ppbValue
        If successful, the data is returned in the buffer allocated by SLC.
        The caller has to call LocalFree to free the memory.

Return Error:
    E_INVALIDARG
    SL_E_VALUE_NOT_FOUND

--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLGETSERVICEINFOMATION_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pwszValueName, peDataType, pcbValue, ppbValue);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLGetApplicationInformation(
    _In_                        HSLC                        hSLC,
    _In_                        const SLID*                 pApplicationId,
    _In_                        PCWSTR                      pwszValueName,
    _Out_opt_                   SLDATATYPE*                 peDataType,
    _Out_                       UINT*                       pcbValue,
    _Outptr_result_bytebuffer_(*pcbValue) PBYTE*            ppbValue
    )
/*++
Routine Description:

    Get information about specified application.

Arguments:
    hSLC
        Handle to current SLC context.

    pwszValueName
        SL_INFO_KEY_IS_KMS
            Return Type = SL_DATA_DWORD
            Return Data = Indicates whether the machine has a key management service enabled
        SL_INFO_KEY_KMS_CURRENT_COUNT
            Return Type = SL_DATA_DWORD
            Return Data = Count of currently active volume clients on KMS host
        SL_INFO_KEY_KMS_REQUIRED_CLIENT_COUNT
            Return Type = SL_DATA_DWORD
            Return Data = Min number of VL clients required to connect to a KMS host for enabling activation
        SL_INFO_KEY_KMS_UNLICENSED_REQUESTS
            Return Type = SL_DATA_DWORD
            Return Data = Count of KMS requests from VL clients with License Status=Unlicensed
        SL_INFO_KEY_KMS_LICENSED_REQUESTS
            Return Type = SL_DATA_DWORD
            Return Data = Count of KMS requests from VL clients with License Status=Licensed
        SL_INFO_KEY_KMS_OOB_GRACE_REQUESTS
            Return Type = SL_DATA_DWORD
            Return Data = Count of KMS requests from VL clients with License Status=OOB Grace
        SL_INFO_KEY_KMS_OOT_GRACE_REQUESTS
            Return Type = SL_DATA_DWORD
            Return Data = Count of KMS requests from VL clients with License Status=OOT Grace
        SL_INFO_KEY_KMS_NON_GENUINE_GRACE_REQUESTS
            Return Type = SL_DATA_DWORD
            Return Data = Count of KMS requests from VL clients with License Status=Non-Genuine Grace
        SL_INFO_KEY_KMS_NOTIFICATION_REQUESTS
            Return Type = SL_DATA_DWORD
            Return Data = Count of KMS requests from VL clients with License Status=Notification
        SL_INFO_KEY_KMS_TOTAL_REQUESTS
            Return Type = SL_DATA_DWORD
            Return Data = Total count of valid KMS requests
        SL_INFO_KEY_KMS_FAILED_REQUESTS
            Return Type = SL_DATA_DWORD
            Return Data = Total count of failed KMS requests

    peDataType
        Data type. Following types are supported:
            SL_DATA_SZ     - UNICODE string
            SL_DATA_DWORD  - DWORD
            SL_DATA_BINARY - Binary blob

    pcbValue
        Size of the allocated buffer.

    ppbValue
        If successful, the data is returned in the buffer allocated by SLC.
        The caller has to call LocalFree to free the memory.

Return Error:
    E_INVALIDARG
    SL_E_VALUE_NOT_FOUND

--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLGETAPPLICATIONINFORMATION_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pApplicationId, pwszValueName, peDataType,
                           pcbValue, ppbValue);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLActivateProduct(
    _In_                        HSLC                        hSLC,
    _In_                        CONST SLID*                 pProductSkuId,
    _In_opt_                    UINT                        cbAppSpecificData,
    _In_opt_                    CONST PVOID                 pvAppSpecificData,
    _In_opt_                    CONST SL_ACTIVATION_INFO_HEADER* pActivationInfo,
    _In_opt_                    PCWSTR                      pwszProxyServer,
    _In_opt_                    WORD                        wProxyPort
    )
/*++

Routine Description:

    Acquire use licenses (q.g. retail-online or Volume ... etc,).

Arguments:

    hSLC
        Handle to current SLC context.

    pProductSkuId
        Porduct Id.

    cbAppSpecificData
        Size of application specific data.

    pbAppSpecificData
        Application specific data. License server can use this
        information to embed application specific run-time information.

    pActivationInfo
        Additional information; depends on the type of activation (see remark).

    pwszProxyServer
        Proxy server name (optional). NULL for automatic proxy discovery

    wProxyPort
        Proxy server port. 0 for default port.

Remark:

    This function can be used for Retail and Active Directory phone activation. 
    Depending on the activation type, the pActivationInfo should be filled
    as follows:

    Retail activation:

        pActivationInfo must be set to NULL.

    Active Directory activation:
    
        SL_AD_ACTIVATION_INFO AdaOnlineInfo;

        memset(&AdaOnlineInfo, 0, sizeof(AdaOnlineInfo);
            
        AdaOnlineInfo->header.cbSize  = sizeof(AdaOnlineInfo);
        AdaOnlineInfo->header.type    = SL_ACTIVATION_TYPE_ACTIVE_DIRECTORY;
        AdaOnlineInfo->pwszProductKey = L"<5x5 Product Key>";
        AdaOnlineInfo->pwszActivationObjectName = L"<string>";  // or NULL

        The product key will not be installed.

Return Error:

    E_INVALIDARG
    SL_E_PUBLISHING_LICENSE_NOT_INSTALLED
    SL_E_PKEY_NOT_INSTALLED
    SL_E_PRODUCT_SKU_NOT_INSTALLED
    Network errors
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLACTIVATEPRODUCT_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pProductSkuId, cbAppSpecificData, pvAppSpecificData,
                           pActivationInfo, pwszProxyServer, wProxyPort);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLGetServerStatus(
    _In_                        PCWSTR                      pwszServerURL,
    _In_                        PCWSTR                      pwszAcquisitionType,
    _In_opt_                    PCWSTR                      pwszProxyServer,
    _In_opt_                    WORD                        wProxyPort,
    _Out_                       HRESULT*                    phrStatus
    )
/*++
Routine Description:

    This function checks the server status according to the specified
    URL and RequestType.

    Callers can either pass in URL kept by themselves or get SKU
    specific URL by calling GetProductSkuInformation and query each
    URL.

Arguments:

    pwszServerURL
        Server's URL .

    pwszAcquisitionType
        see slapi.h. There are 5 acquisition types.
        SL_INFO_KEY_SECURE_PROCESSOR_ACTIVATION_URL
        SL_INFO_KEY_RIGHT_ACCOUNT_ACTIVATION_URL
        SL_INFO_KEY_PRODUCT_KEY_ACTIVATION_URL
        SL_INFO_KEY_USE_LICENSE_ACTIVATION_URL
        SL_INFO_KEY_PRODUCT_ACTIVATION_URL

    pwszProxyServer
        Proxy server name (optional). NULL for automatic proxy discovery

    wProxyPort
        Proxy server port. 0 for default port.

    phrStatus
        Server status.
            S_OK
            Network errors

Return Error:
    E_INVALIDARG

--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLGETSERVERSTATUS_ROUTINE, __FUNCTION__);
    tempResult = Procedure(pwszServerURL, pwszAcquisitionType, pwszProxyServer,
                           wProxyPort, phrStatus);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLReArm(
    _In_                        HSLC                        hSLC,
    _In_                        CONST SLID*                 pApplicationId,
    _In_opt_                    CONST SLID*                 pProductSkuId,
    _In_                        DWORD                       dwFlags
    )
/*++
Routine Description:

    This function is rearm application activation.

Arguments: none

    hSLC
        Handle to current SLC session.

    pApplicationId,
        Applicaiton Id.
        
    pProductSkuId
        Product SKU Id.

    dwFlags
        Flags for ReArm behavior.  Valid values are 0 or 
        SL_REARM_REBOOT_REQUIRED.  Passing SL_REARM_REBOOT_REQUIRED will 
        require a reboot before an API using the security processor can
        succeed.        
        
Return Error:

--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLREARM_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pApplicationId, pProductSkuId, dwFlags);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLGenerateOfflineInstallationId(
    _In_                        HSLC                        hSLC,
    _In_                        CONST SLID*                 pProductSkuId,
    _Outptr_                    PWSTR*                      ppwszInstallationId
    )
/*++
Routine Description:

    Generate Installation Id (IID).
    Users can send the IID to CSR to get the Confirmation Id (CID).

Arguments:

    hSLC
        Handle to current SLC context.

    pProductSkuId
        Product Id.

    ppwszInstallationId
        The Installation Id string. The caller calls LocalFree to
        free memory.

Return Error:

    E_INVALIDARG
    SL_E_PKEY_NOT_INSTALLED
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLGENERATEOFFLINEINSTALLATIONID_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pProductSkuId, ppwszInstallationId);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLGenerateOfflineInstallationIdEx(
    _In_                        HSLC                        hSLC,
    _In_opt_                    CONST SLID*                 pProductSkuId,
    _In_opt_                    CONST SL_ACTIVATION_INFO_HEADER* pActivationInfo,
    _Outptr_                    PWSTR*                      ppwszInstallationId
    )
/*++
Routine Description:

    Generate Installation Id (IID).
    Users can send the IID to CSR to get the Confirmation Id (CID).

Arguments:

    hSLC
        Handle to current SLC context.

    pProductSkuId
        Product Id.

    pActivationInfo
        Additional information; depends on the type of activation (see remark).

    ppwszInstallationId
        The Installation Id string. The caller calls LocalFree to
        free memory.

Remark:

    This function can be used for Retail and Active Directory phone activation. 
    Depending on the activation type, the pActivationInfo should be filled
    as follows:

    Retail activation:

        pActivationInfo must be set to NULL. In this case the function 
        works the same way as SLDepositOfflineConfirmationId.

    Active Directory activation:
    
        SL_AD_ACTIVATION_INFO AdaRequestInfo;

        memset(&AdaRequestInfo, 0, sizeof(AdaRequestInfo);            

        AdaRequestInfo->header.cbSize            = sizeof(AdaRequestInfo);
        AdaRequestInfo->header.type              = SL_ACTIVATION_TYPE_ACTIVE_DIRECTORY;
        AdaRequestInfo->pwszProductKey           = L"<5x5 Product Key>";
        AdaRequestInfo->pwszActivationObjectName = NULL;

        The product key will not be installed.

Return Error:

    E_INVALIDARG
    SL_E_PKEY_NOT_INSTALLED
    TODO: (ADA) more error codes here.
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLGENERATEOFFLINEINSTALLATIONIDEX_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pProductSkuId, pActivationInfo, ppwszInstallationId);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLDepositOfflineConfirmationId(
    _In_                        HSLC                        hSLC,
    _In_                        CONST SLID*                 pProductSkuId,
    _In_                        PCWSTR                      pwszInstallationId,
    _In_                        PCWSTR                      pwszConfirmationId
    )
/*++
Routine Description:

    Deposit Installation Id (IID) and Confirmation Id (CID) for off-line activation.

Arguments:

    hSLC
        Handle to current SLC context.

    pProductSkuId
        Product Id.

    pwszInstallationId
        The Installation Id generated by SLGenerateOfflineInstallationId(Ex).

    pwszConfirmationId
        The confirmation Id CSR generated for users.

Return Error:

    E_INVALIDARG
    SL_E_CIDIID_INVALID_CHECK_DIGITS
    SL_E_PRODUCT_SKU_NOT_INSTALLED
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLDEPOSITOFFLINECONFORMATIONID_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pProductSkuId, pwszInstallationId, pwszConfirmationId);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLDepositOfflineConfirmationIdEx(
    _In_                        HSLC                        hSLC,
    _In_opt_                    CONST SLID*                 pProductSkuId,
    _In_opt_                    CONST SL_ACTIVATION_INFO_HEADER* pActivationInfo,
    _In_                        PCWSTR                      pwszInstallationId,
    _In_                        PCWSTR                      pwszConfirmationId
    )
/*++
Routine Description:

    Deposit Installation Id (IID) and Confirmation Id (CID) for off-line activation.

Arguments:

    hSLC
        Handle to current SLC context.

    pProductSkuId
        Product Id.

    pwszInstallationId
        The Installation Id generated by SLGenerateOfflineInstallationId(Ex).

    pwszConfirmationId
        The confirmation Id CSR generated for users.

Return Error:

    E_INVALIDARG
    SL_E_CIDIID_INVALID_CHECK_DIGITS
    SL_E_PRODUCT_SKU_NOT_INSTALLED
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLDEPOSITOFFLINECONFIRMATIONIDEX_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pProductSkuId, pActivationInfo, pwszInstallationId, pwszConfirmationId);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLGetPKeyId(
    _In_                        HSLC                        hSLC,
    _In_                        PCWSTR                      pwszPKeyAlgorithm,
    _In_                        PCWSTR                      pwszPKeyString,
    _In_                        UINT                        cbPKeySpecificData,
    _In_reads_bytes_opt_(cbPKeySpecificData) CONST BYTE*    pbPKeySpecificData,
    _Out_                       SLID*                       pPKeyId
    )
/*++
Routine Description:

    Get the registered Product Key Id associated with the Product.

Arguments:

    hSLC
        Handle to current SLC context.

    pwszPKeyAlgorithm
        Product Key algorithm.

    pwszPKeyString
        Product key string (e.g. 5x5 string).

    cbPKeySpecificData
        Size of product key specific data. If no PKey specific data, set to 0.

    pbPKeySpecificData
        Product key specific data. If no PKey specific data, set to NULL.

    pPKeyId
        The Product Key Id associated with the Product.

Return Error:

    E_INVALIDARG
    SL_E_PKEY_NOT_INSTALLED
    
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLGETPKEYID_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pwszPKeyAlgorithm, pwszPKeyString, cbPKeySpecificData, pbPKeySpecificData,
                           pPKeyId);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLGetInstalledProductKeyIds(
    _In_                        HSLC                        hSLC,
    _In_                        CONST SLID*                 pProductSkuId,
    _Out_                       UINT*                       pnProductKeyIds,
    _Outptr_result_buffer_(*pnProductKeyIds) SLID**         ppProductKeyIds
    )
/*++
Routine Description:

    This function returns a list of product key Ids associated
    with the specified Product SKU Id.

Arguments:

    hSLC
        Handle to current SLC session.

    pProductSkuId
        Product SKU Id.

    pnProductKeyIds
        Number of Product Key Ids returned.

    hEvent
        Returned Product Key Ids.


Return Error:

    SL_E_VALUE_NOT_FOUND
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLGETINSTALLEDPRODUCTKEYIDS, __FUNCTION__);
    tempResult = Procedure(hSLC, pProductSkuId, pnProductKeyIds, ppProductKeyIds);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLSetCurrentProductKey(
    _In_ HSLC hSLC,
    _In_ CONST SLID* pProductSkuId,
    _In_ CONST SLID* pProductKeyId
    )
/*++
Routine Description:

    This function let the caller set current
    product key to previously installed product key.

Arguments:

    hSLC
        Handle to current SLC session.

    pProductSkuId
        Product SKU Id.

    pProductKeyId
        Product Key Id.

Return Error:

    SL_E_MISMATCHED_PRODUCT_SKU
    SL_E_PKEY_NOT_INSTALLED
    SL_E_OPERATION_NOT_ALLOWED
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLSETCURRENTPRODUCTKEY_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pProductSkuId, pProductKeyId);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLGetSLIDList(
    _In_                        HSLC                        hSLC,
    _In_                        SLIDTYPE                    eQueryIdType,
    _In_opt_                    CONST SLID*                 pQueryId,
    _In_                        SLIDTYPE                    eReturnIdType,
    _Out_                       UINT*                       pnReturnIds,
    _Outptr_result_buffer_(*pnReturnIds) SLID**             ppReturnIds
    )
/*++

Description:

    Get a list of SLIDs according to input query Id type and Id value.

    For example, input Id is SkuId, and return Id is AppId, which means
    the caller wants to get a list of AppId associated with this SkuId.

    If no information is found, then *pnReturnIds is 0.

Parameters:

    eQueryIdType
        The type of input Id

    rQueryId
        The input Id

    eReturnIdType
        The type of returned Ids.

    pnReturnIds
        Number of returned Ids.

    ppReturnIds
        Returned Ids.

Remark:
    Support following queries.

        SL_ID_APPLICATION, SLID_ALL, SL_ID_APPLICATION
            Get All Installed Application Ids.

        SL_ID_PRODUCT_SKU, SLID_ALL, SL_ID_PRODUCT_SKU
            Get All Installed Product Sku Ids.

        SL_ID_APPLICATION, appId , SL_ID_PRODUCT_SKU
            Get Sku Ids according to the input App Id.

        SL_ID_PRODUCT_SKU, skuId , SL_ID_APPLICATION
            Get App Ids according to the input Sku Id

        SL_ID_PRODUCT_SKU, skuId , SL_ID_PKEY
            Get License PKey Ids according to the input Sku Id

        SL_ID_PRODUCT_SKU, skuId , SL_ID_LICENSE_FILE
            Get License file Ids according to the input Sku Id

        SL_ID_LICENSE_FILE, fileId , SL_ID_LICENSE
            Get License Ids according to the input License File Id

        SL_ID_LICENSE, LicenseId, SL_ID_LICENSE_FILE
            Get License File Id according to the input License Id

        SL_ID_LICENSE, LicenseId, SL_ID_APPLICATION
        SL_ID_LICENSE, LicenseId, SL_ID_PRODUCT_SKU
            Get union of all App Ids or Sku Ids from all grants of
            a token activation license. Returns SL_E_NOT_SUPPORTED
            if the LicenseId is valid but doesn't refer to a token
            activation license.

    If callers give the combinations not listed above, then the
    API will return SL_E_NOT_SUPPORTED.

Return Error:

    E_INVALIDARG
    SL_E_VALUE_NOT_FOUND
    SL_E_NOT_SUPPORT
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLGETSLIDLIST_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, eQueryIdType, pQueryId,
                           eReturnIdType, pnReturnIds, ppReturnIds);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLGetLicenseFileId(
    _In_                        HSLC                        hSLC,
    _In_                        UINT                        cbLicenseBlob,
    _In_reads_bytes_(cbLicenseBlob)  CONST BYTE*                 pbLicenseBlob,
    _Out_                       SLID*                       pLicenseFileId
    )
/*++
Routine Description:

    This function takes the license blob and find if it has been
    installed already. If not, return SL_E_FILE_NOT_INSTALLED, otherwisw,
    return an LicenseFileId.

Arguments:

    hSLC
        Handle to current SLC context.

    cbLicenseBlob
        Size of license blob

    pbLicenseBlob
        licenses in blob. The caller can open/read license file or
        receives the blob from

    pLicenseFileId
        License File Id

Return Error:

    E_INVALIDARG
    SL_E_INVALID_LICENSE
    SL_E_LICENSE_FILE_NOT_INSTALLED
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLGETLICENSEFILEID_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, cbLicenseBlob, pbLicenseBlob,
                           pLicenseFileId);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLGetLicense(
    _In_                        HSLC                        hSLC,
    _In_                        CONST SLID*                 pLicenseFileId,
    _Out_                       UINT*                       pcbLicenseFile,
    _Outptr_result_bytebuffer_(*pcbLicenseFile) PBYTE*      ppbLicenseFile
    )
/*++
Routine Description:

    This function returns the license file blob.

Arguments:

    hSLC
        Handle to current SLC context.

    pLicenseFileId
        License file Id

    pcbLicenseFile
        Size of license file blob

    ppbLicenseFile
        License file blob

Return Error:

    E_INVALIDARG
    SL_E_LICENSE_FILE_NOT_INSTALLED
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLGETLICENSE_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pLicenseFileId, pcbLicenseFile,
                           ppbLicenseFile);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}


HRESULT
WINAPI
SLFireEvent(
    _In_                        HSLC                        hSLC,
    _In_                        PCWSTR                      pwszEventId,
    _In_                        CONST SLID*                 pApplicationId
    )
/*++
Routine Description:
    This function sends specified event to registered listener
    (whoever registered the event with the spcified AppId).

    The caller has to have administrator privilege to call this function.

Arguments:

    hSLC
        Handle to current SLC session.

    pwszEventId
        Event to be fired.

    pApplicationId
        Application Id.

Return Error:

    E_ACCESSDENIED
    SL_E_INVALID_EVENT_ID
    SL_E_EVENT_NOT_REGISTERED
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLFIREEVENT_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pwszEventId, pApplicationId);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLRegisterEvent(
    _In_opt_                    HSLC                        hSLC,
    _In_                        PCWSTR                      pwszEventId,
    _In_                        CONST SLID*                 pApplicationId,
    _In_                        HANDLE                      hEvent
    )
/*++
Routine Description:

    This function registers an event in SL service.

    The caller can receive notifications when the registered event is fired.

Arguments:

    hSLC
        Handle to current SLC session (optional).
        - hSLC == NULL, service is running:
            SLOpen will be called internally before the RPC call.
        - hSLC != NULL, service is running:
            Use the provided handle to do the RPC call.
        - Service is not running (hSLC is not used in that case):
            Service won't be started, event will be correctly registered on service start.
        
    pwszEventId
        Predefined SL event identifier.

    pApplicationId
        Register the event to this Application Id.

    hEvent
        Caller provides the event handle used for notification.

Return Error:

    SL_E_INVALID_EVENT_ID
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLREGISTEREVENT_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pwszEventId, pApplicationId, hEvent);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLUnregisterEvent(
    _In_opt_                    HSLC                        hSLC,
    _In_                        PCWSTR                      pwszEventId,
    _In_                        CONST SLID*                 pApplicationId,
    _In_                        HANDLE                      hEvent
    )
/*++
Routine Description:

    This function unregisters an registered event in SL service.

    After unregisteration, SL stopps notifying this event.

Arguments:

    hSLC
        Handle to current SLC session (optional).
        - hSLC == NULL, service is running:
            SLOpen will be called internally before the RPC call.
        - hSLC != NULL, service is running:
            Use the provided handle to do the RPC call.
        - Service is not running (hSLC is not used in that case):
            Service won't be started, event will be correctly un-registered.

    pwszEventId
        Predefined SL event identifier.

    pApplicationId
        Unegister the event from this Application Id.

    hEvent
        The registered event handle.


Return Error:

    SL_E_INVALID_EVENT_ID
    SL_E_EVENT_NOT_REGISTERED
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLUNREGISTEREVENT_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pwszEventId, pApplicationId, hEvent);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLIsGenuineLocal(
    _In_                        CONST SLID*                 pAppId,
    _Out_                       SL_GENUINE_STATE*           pGenuineState, 
    _Inout_opt_                 SL_NONGENUINE_UI_OPTIONS*   pUIOptions
    )
/*++
Routine Description:

    Determines if an installation is a Genuine installation.
    It interrogates the license for pAppId and inspects the "Tampered"
    flag.  If either the license for pAppId is invalid or the "Tampered"
    flag is set, the installation is assumed to be invalid.

    pGenuineState is ONLY modified if the result is S_OK.  Otherwise, it is
    left in the state in which it was found on function entry.

Arguments:

    pAppId
        Application identifier. 

    pbGenuineState
        Output state value - one of the SL_GENUINE_STATE values

    pUIOptions
        Non genuine UI options. If NULL, no UI is displayed if 
        state is non-genuine. 

Return Error:

    S_OK
        Operation completed successfully.

    E_INVALIDARG
        pGenuineState is NULL.

--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLISGENUINELOCAL_ROUTINE, __FUNCTION__);
    tempResult = Procedure(pAppId, pGenuineState, pUIOptions);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLIsGenuineLocalEx(
    _In_                        CONST SLID*                 pAppId,
    _In_opt_                    CONST SLID*                 pSkuId,
    _Out_                       SL_GENUINE_STATE*           pGenuineState
    )
/*++
Routine Description:

    Determines if an installation is a Genuine installation.
    If the SkuId is provided, it is used for the primary check.  If the Sku license
    contains a ProductUniquenessGroupId value, that is also used.  Finally, the AppId is used.
    If the AppId, ProductUniquenessGroupId, or SkuId contains a "Tampered" flag or if the license
    state is invalid or "Tampered", the installation is assumed to be invalid.
    

    pGenuineState is ONLY modified if the result is S_OK.  Otherwise, it is
    left in the state in which it was found on function entry.

Arguments:

    pAppId
        Application identifier.
    
    pSkuId
        Sku identifier, optional.  If specified and the Sku license contains a
        ProductUniquenessGroupId then that is also checked.

    pbGenuineState
        Output state value - one of the SL_GENUINE_STATE values

Return Error:

    S_OK
        Operation completed successfully.

    E_INVALIDARG
        pGenuineState is NULL.

--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLISGENUINELOCALEX_ROUTINE, __FUNCTION__);
    tempResult = Procedure(pAppId, pSkuId, pGenuineState);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}


HRESULT
WINAPI
SLAcquireGenuineTicket(
    _Outptr_result_bytebuffer_(*pcbTicketBlob) VOID**       ppTicketBlob,  
    _Out_                       UINT*                       pcbTicketBlob,
    _In_                        PCWSTR                      pwszTemplateId, 
    _In_                        PCWSTR                      pwszServerUrl, 
    _In_opt_                    PCWSTR                      pwszClientToken 
    )
/*++
Routine Description:

    Returns genuine ticket acquired from Software Licensing Server based
    on SLWGA template blob. 
    
    The client is responsible for freeing the buffer returned in ppGenuineBlob.
    SLWGAFreeMemory should be used to free the memory.

    The output parameters are only set if the function returns S_OK.  Otherwise,
    they are left as they were when the function was entered.

Arguments:

    ppTicketBlob
        Pointer to output pointer to be returned (XrML genuine ticket).

    pcbTicketBlob
        An output pointer that will contain the size, in bytes, of the region
        returned in ppTicketBlob.

    pwszTemplateId
        Id of genuine blob template kept on the server side. 

    pwszServerUrl
        Ticket acquisition server url. 

    pwszClientToken
        Client custom token. 

Return Error:

    S_OK
        Operation completed successfully.

--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLACQUIREGENUINETICKET_ROUTINE, __FUNCTION__);
    tempResult = Procedure(ppTicketBlob, pcbTicketBlob, pwszTemplateId, pwszServerUrl, pwszClientToken);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLSetGenuineInformation(
    _In_                        CONST SLID*                 pQueryId,
    _In_                        PCWSTR                      pwszValueName,
    _In_                        SLDATATYPE                  eDataType,
    _In_opt_                    UINT                        cbValue,
    _In_reads_bytes_opt_(cbValue)    CONST BYTE*            pbValue
    )
/*++
Routine Description:

    This function sets genuine related information.

Arguments:

    pQueryId
        pQueryId can be one of the following.  

        ApplicationId in case of querying following property values.
            SL_PROP_BRT_DATA
            SL_PROP_BRT_COMMIT

        SKUId in case of querying following property values.
            SL_PROP_LAST_ACT_ATTEMPT_HRESULT
            SL_PROP_LAST_ACT_ATTEMPT_TIME
            SL_PROP_LAST_ACT_ATTEMPT_SERVER_FLAGS
            SL_PROP_ACTIVATION_VALIDATION_IN_PROGRESS

    pwszValueName
        pwszValueName can be one of the following property names.
            SL_PROP_BRT_DATA
            SL_PROP_BRT_COMMIT
            SL_PROP_LAST_ACT_ATTEMPT_HRESULT
            SL_PROP_LAST_ACT_ATTEMPT_TIME
            SL_PROP_LAST_ACT_ATTEMPT_SERVER_FLAGS
            SL_PROP_ACTIVATION_VALIDATION_IN_PROGRESS

    eType
        See SLDATATYPE

    cbValue
        Size of value

    pbValue
        Value.
            Some properties allows NULL pointer, which can be used to delete
            the property but some properties can't.

Return Value:

    HRESULT_FROM_WIN32(ERROR_BUFFER_OVERFLOW)
        The size of value is over expected size

    E_ACCESSDENIED
        Admin privilege required
    E_INVALIDARG
        Some property does not allow NULL value
    SL_E_NOT_SUPPORTED
        The name of value is not supported
    SL_E_DEPENDENT_PROPERTY_NOT_SET
        If entry has been set
    SL_E_DATATYPE_MISMATCHED
        The type of data is mismatched with the expected type
        of specified value name
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLSETGENUINEINFORMATION_ROUTINE, __FUNCTION__);
    tempResult = Procedure(pQueryId, pwszValueName, eDataType, cbValue, pbValue);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLGetReferralInformation(
    _In_                        HSLC                        hSLC,
    _In_                        SLREFERRALTYPE              eReferralType,
    _In_                        CONST SLID*                 pSkuOrAppId,
    _In_                        PCWSTR                      pwszValueName,
    _Outptr_                    PWSTR*                      ppwszValue 
    )
/*++
SLGetReferralInformation

Routine Description:

      Associates information with the specified product

Arguments:

      hSLC
          Handle retrieved by previous call to SLOpen

      eReferralType
          Do we want to obtain application or SKU specific referral information

      pSkuOrAppId
          Application or SKU from which to obtain referral information

      pwszValueName
          The value name for the associated data.
          Allowable value pairs:
                SL_PARTNERID
                    Partner Id for the license reseller
                SL_REFERRALID
                    Referral ID for the license reseller
                SL_MERCHANTCOMMERCEURL
                    The merchant URL to purchase additional licenses
                SL_MERCHANTUPGRADEURL
                    The merchant URL to purchase additional licenses
                SL_DOWNLOADURL
                    A forward link to download the associated application
                SL_INSTALLATIONPARAMETERS
                    Any parameters that are used when running the associated application's installer
                SL_MERCHANTSUPPORTPHONENUMBER
                    The merchant support phone number(s)
                SL_MERCHANTSUPPORTEMAIL
                    The merchant support email address
                SL_MERCHANTSUPPORTURL
                    The merchant support URL
                SL_SERIALIZEDDATA
                    A generic data blob

      pwszValue
          The value to store
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLGETREFERRALINFORMATION_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, eReferralType, pSkuOrAppId, pwszValueName, ppwszValue);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLPersistRTSPayloadOverride(
    _In_                        HSLC                        hSLC,
    _In_                        CONST SLID*                 pApplicationId,
    _In_opt_                    CONST SLID*                 pProductSkuId,
    _In_reads_bytes_(cbData)    BYTE*                       pbData,
    _In_                        DWORD                       cbData
    )
/*++
SLPersistRTSPayloadOverride

Routine Description:

      Associates information with the specified product for online and phone activation

Arguments:
 
      hSLC
          Handle retrieved by previous call to SLOpen
          
      pApplicationId
          Application Id to associate the payload data with

      pProductSkuId
          Optional Sku Id to associate the payload data with

      pbData
          The byte data that will be sent up during activation.
          This API assumes the data is composed of a 20-bit value stored in the first three bytes:
          Byte[0] is the LSB of the HIWORD, Byte[1] is the HSB of the LOWORD, and Byte[2] is the LSB of the LOWORD.
          Any value composed of these three bytes that exceeds 20 bits will be rejected with E_INVALIDARG
          
      cbData
          The number of bytes that will be stored.  This must be equal to 3.
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLPERSISTRTSPAYLOADOVERRIDE_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pApplicationId, pProductSkuId, pbData, cbData);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLPersistApplicationPolicies(
    _In_                        CONST SLID*                 pApplicationId,
    _In_opt_                    CONST SLID*                 pProductSkuId,
    _In_                        DWORD                       dwFlags
    )
/*++
Routine Description:

    Stores the current consumed policies to the disk for fast policy access.
    If the internal consumption fails then any current cache data is deleted
    such that subsequent calls to SLLoadApplicationPolicies() will return
    SL_E_APPLICATION_POLICIES_MISSING.
    SLPersistApplicationPolicies returns success if the policy update succeeds,
    regardless of internal consumption results.

Arguments:

    pApplicationId
        Identifier of the AppId to be used for the fast policy queries.

    pProductSkuId
        optional - Identifier of the ACID to be used for the fast policy queries.

    dwFlags
        additional flags if any

Return Error:

    E_INVALIDARG
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLPERSISTAPPLICATIONPOLICIES_ROUTINE, __FUNCTION__);
    tempResult = Procedure(pApplicationId, pProductSkuId, dwFlags);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLGetApplicationPolicy(
    _In_                        HSLP                        hPolicyContext,
    _In_                        PCWSTR                      pwszValueName,
    _Out_opt_                   SLDATATYPE*                 peDataType,
    _Out_                       UINT*                       pcbValue,
    _Outptr_result_bytebuffer_(*pcbValue) PBYTE*            ppbValue
    )
/*++
Routine Description:

    Queries a policy from the set loaded set stored with SLPersistApplicationPolicies 
    and loaded using SLLoadApplicationPolicies

Arguments:

    hPolicyContext
        Context handle returned by SLLoadApplicationPolicies

    pwszValueName
        the name of the policy to query, or '*' for all policies

    peDataType
        optional - returns the type of the data if data was available

    pcbValue
        returns the size of the data if data was available

    ppbValue
        returns the data if data was available

Return Error:

    E_INVALIDARG
    SL_E_APPLICATION_POLICIES_NOT_LOADED     if the policy context was not found
    SL_E_VALUE_NOT_FOUND                     if the policy is not found
    SL_E_RIGHT_NOT_GRANTED                   if the policy list is empty
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLGETAPPLICATIONPOLICY_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hPolicyContext, pwszValueName, peDataType, pcbValue, ppbValue);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLLoadApplicationPolicies(
    _In_                        CONST SLID*                 pApplicationId,
    _In_opt_                    CONST SLID*                 pProductSkuId,
    _In_                        DWORD                       dwFlags,
    _Out_                       HSLP*                       phPolicyContext
    )
/*++
Routine Description:

    Loads the application policies set with SLPersistApplicationPolicies 
    for use by the query function SLGetApplicationPolicy

Arguments:

    pApplicationId
        Identifier of the AppId to be used for the fast policy queries.

    pProductSkuId
        optional - Identifier of the ACID to be used for the fast policy queries.

    dwFlags
        additional flags if any
        
    pPolicyContext
        pointer to a policy context for use in SLGetApplicationPolicy and 
        SLUnloadApplicationPolicies

Return Error:

    E_INVALIDARG
    SL_E_APPLICATION_POLICIES_MISSING   if the policy list doesn't exist
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLLOADAPPLICATIONPOLICIES_ROUTINE, __FUNCTION__);
    tempResult = Procedure(pApplicationId, pProductSkuId, dwFlags, phPolicyContext);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLUnloadApplicationPolicies(
    _In_                        HSLP                        hPolicyContext,
    _In_                        DWORD                       dwFlags
    )
/*++
Routine Description:

    Releases the policy context handle returned by SLLoadApplicationPolicies

Arguments:

    hPolicyContext
        Context handle returned by SLLoadApplicationPolicies

    dwFlags
        additional flags, if any

Return Error:

    E_INVALIDARG
    SL_E_APPLICATION_POLICIES_NOT_LOADED     if the policy context was not found
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLUNLOADAPPLICATIONPOLICIES_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hPolicyContext, dwFlags);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}


HRESULT
WINAPI
SLGetAuthenticationResult(
    _In_                          HSLC                      hSLC,
    _Out_                         UINT*                     pcbValue,
    _Outptr_result_bytebuffer_(*pcbValue) PBYTE*            ppbValue
    )
/*++
Routine Description:

    This function gets the authentication results set by some SLAPI call.
    Caller can use this result to verify the integrity of return data 
    of some SLAPI 

Arguments:

    hSLC
        Handle to current SLC context.
        
    cbValue
        Size of authentication result
        
    pbValue
        Authentication result

Return Value:
    
    SL_E_AUTHN_MISMATCHED_KEY
        The key used in SLSetAuthenticationData call is incorrect
    
    SL_E_AUTHN_CANT_VERIFY
        The authentication cannot be done. For example, right consumption is not done or failed. Or 
        this feature is not enabled in licenses.
        
    SL_E_AUTHN_CHALLENGE_NOT_SET
        The authentication data (challenge) is not set
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLGETAUTHENTICATIONRESULT_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, pcbValue, ppbValue);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLSetAuthenticationData(
    _In_                          HSLC                      hSLC,
    _In_opt_                      UINT                      cbValue,
    _In_reads_bytes_opt_(cbValue) CONST BYTE*               pbValue
    )
/*++
Routine Description:

    This function lets caller set authentication data, so the caller 
    can authenticate the result from some SLAPI call.

Arguments:

    hSLC
        Handle to current SLC context.
        
    cbValue
        Size of authentication data
        
    pbValue
        Authentication data

Return Value:

    HRESULT_FROM_WIN32(ERROR_INVALID_DATA)
        The format of authentication data is invalid
        
    SL_E_AUTHN_WRONG_VERSION
        The security version is wrong

    SL_E_NOT_SUPPORTED
        The authentication data format is not supported

--*/             
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLSETAUTHENTICATIONDATA_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hSLC, cbValue, pbValue);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLGetGenuineInformation(
    _In_                        CONST SLID*                 pQueryId,
    _In_                        PCWSTR                      pwszValueName,
    _Out_opt_                   SLDATATYPE*                 peDataType,
    _Out_                       UINT*                       pcbValue,
    _Outptr_result_bytebuffer_(*pcbValue) BYTE**            ppbValue
    )
/*++
Routine Description:

    This function gets genuine related information.

Arguments:

    pQueryId
        pQueryId can be one of the following.  

        GenuineId in case of querying following property values.
            SL_PROP_GENUINE_RESULT  
            SL_PROP_GET_GENUINE_AUTHZ

        ApplicationId in case of querying following property values.
            SL_PROP_BRT_DATA
            SL_PROP_BRT_COMMIT 
            SL_PROP_NONGENUINE_GRACE_FLAG

        SKUId in case of querying following property values.
            SL_PROP_LAST_ACT_ATTEMPT_HRESULT
            SL_PROP_LAST_ACT_ATTEMPT_TIME
            SL_PROP_LAST_ACT_ATTEMPT_SERVER_FLAGS
            SL_PROP_ACTIVATION_VALIDATION_IN_PROGRESS


    pwszValueName
        pwszValueName can be one of the following property names.
            SL_PROP_GENUINE_RESULT
            SL_PROP_GET_GENUINE_AUTHZ:<sessiondId>
            SL_PROP_BRT_DATA
            SL_PROP_BRT_COMMIT
            SL_PROP_NONGENUINE_GRACE_FLAG
            SL_PROP_LAST_ACT_ATTEMPT_HRESULT
            SL_PROP_LAST_ACT_ATTEMPT_TIME
            SL_PROP_LAST_ACT_ATTEMPT_SERVER_FLAGS
            SL_PROP_ACTIVATION_VALIDATION_IN_PROGRESS

    eType
        See SLDATATYPE

    cbValue
        Size of value

    pbValue
        Value

Return Value:

    SL_E_NOT_SUPPORTED
        The name of value is not supported

    SL_E_VALUE_NOT_FOUND
        The specified value can not be found

--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLGETGENUINEINFORMATION_ROUTINE, __FUNCTION__);
    tempResult = Procedure(pQueryId, pwszValueName, peDataType, pcbValue, ppbValue);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}

HRESULT
WINAPI
SLGetGenuineInformationEx(
    _In_                        CONST SLID*                 pAppId,
    _In_                        PCWSTR                      pwszValueName,
    _Out_opt_                   SLDATATYPE*                 peDataType,
    _Out_                       UINT*                       pcbValue,
    _Outptr_result_bytebuffer_(*pcbValue) BYTE**            ppbValue
    )
/*++
Routine Description:

    This function gets genuine information.

Arguments:

    pAppId
        Application ID. E.g. Windows AppId

    pwszValueName
        Name of the property

    eType
        See SLDATATYPE

    cbValue
        Size of value

    pbValue
        Value

Return Value:

    SL_E_NOT_SUPPORTED
        The name of value is not supported

    SL_E_VALUE_NOT_FOUND
        The specified value can not be found
    
    SL_E_NOT_GENUINE
        The Application licensing state is non-genuine
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLGETGENUINEINFORMATIONEX_ROUTINE, __FUNCTION__);
    tempResult = Procedure(pAppId, pwszValueName, peDataType, pcbValue, ppbValue);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}


HRESULT
WINAPI
SLGatherMigrationBlob(
    _In_                            BOOL                    bMigratableOnly,
    _In_opt_                        LPCWSTR                 pwszEncryptorUri,
    _In_                            HANDLE                  hFile
    )
/*+
Routine Description:

    Gathers licensing information into provided file handle. This licensing information
    can later be applied/deposited using SLDepositMigrationBlob.

Arguments:

    bMigratableOnly
        Specifies if only migratable data should be gathered

    pwszEncryptorUri
        URI of key to use for encrypting session key used to encrypt
        any sensitive data in the output blob.

        Only valid values are NULL and SL_DEFAULT_MIGRATION_ENCRYPTOR_URI,
        which both refer to the same key.

    hFile
        File handle to where licensing state blob should be written.

Return Error:

    S_OK
        Operation completed successfully

    E_INVALIDARG
        One or more arguments are invalid

    E_ACCESSDENIED
        Access denied (API requires admin privileges)
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLGATHERMIGRATIONBLOB_ROUTINE, __FUNCTION__);
    tempResult = Procedure(bMigratableOnly, pwszEncryptorUri, hFile);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}


HRESULT
WINAPI
SLDepositMigrationBlob(
    _In_                            HANDLE                  hFile
    )
/*+
Routine Description:

    Deposits licensing information previously collected/gathered using SLGatherMigrationBlob.

Arguments:


    hFile
        File handle from which licensing state blob should be read.

Return Error:

    S_OK
        Operation completed successfully

    E_INVALIDARG
        One or more arguments are invalid

    E_ACCESSDENIED
        Access denied (API requires admin privileges)
--*/
{
    PREPARE_LIBRARY(REAL_DLL_NAME, SLDEPOSITMIGRATIONBLOB_ROUTINE, __FUNCTION__);
    tempResult = Procedure(hFile);
    DECONSTRUCT_LIBRARY();
    return tempResult;
}