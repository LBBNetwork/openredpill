/*++

Copyright (C) 2012 The Little Beige Box, http://www.beige-box.com
Licensed under the GNU General Public License v3.

Module Name:

    api.h

Abstract:

    Stub API type definitions for Windows redpill patch.

Revision History:

--*/

#ifndef _STUB_API_H_
#define _STUB_API_H_

//
// Core Definitions
//

typedef PVOID HSLC, HSLP; // Abstract type?!?
typedef GUID SLID;  // why microsoft why are you
                    // fascinated with GUIDs.

//
// Type of SL Id
//
typedef enum _tagSLIDTYPE
{
    SL_ID_APPLICATION = 0,
    SL_ID_PRODUCT_SKU,
    SL_ID_LICENSE_FILE,
    SL_ID_LICENSE,
    SL_ID_PKEY,
    SL_ID_ALL_LICENSES,
    SL_ID_ALL_LICENSE_FILES,
    SL_ID_LAST
} SLIDTYPE;

//
// Product activation structures
//
typedef enum _tagSL_ACTIVATION_TYPE
{
    SL_ACTIVATION_TYPE_DEFAULT          = 0,
    SL_ACTIVATION_TYPE_ACTIVE_DIRECTORY = 1,
} SL_ACTIVATION_TYPE;

typedef struct _tagSL_ACTIVATION_INFO_HEADER
{
    DWORD                       cbSize;
    SL_ACTIVATION_TYPE          type;
} SL_ACTIVATION_INFO_HEADER;

typedef enum _tagSLDATATYPE
{
    SL_DATA_NONE        = REG_NONE,
    SL_DATA_SZ          = REG_SZ,
    SL_DATA_DWORD       = REG_DWORD,
    SL_DATA_BINARY      = REG_BINARY,
    SL_DATA_MULTI_SZ    = REG_MULTI_SZ,
    SL_DATA_SUM         = 100,
} SLDATATYPE;


//
// Active directory activation )(header.type == SL_ACTIVATION_TYPE_ACTIVE_DIRECTORY)
//
typedef struct _tagSL_AD_ACTIVATION_INFO
{
    SL_ACTIVATION_INFO_HEADER   header;
    PCWSTR                      pwszProductKey;
    PCWSTR                      pwszActivationObjectName;
} SL_AD_ACTIVATION_INFO;

//
// Types of information that can be queried with SLGetReferralInformation
//
typedef enum
{
    SL_REFERRALTYPE_SKUID = 0,
    SL_REFERRALTYPE_APPID,
    SL_REFERRALTYPE_OVERRIDE_SKUID,
    SL_REFERRALTYPE_OVERRIDE_APPID,
    SL_REFERRALTYPE_BEST_MATCH,
} SLREFERRALTYPE;

//
// Licensing status
//
typedef enum _tagSLLICENSINGSTATUS
{
    SL_LICENSING_STATUS_UNLICENSED,
    SL_LICENSING_STATUS_LICENSED,
    SL_LICENSING_STATUS_IN_GRACE_PERIOD,
    SL_LICENSING_STATUS_NOTIFICATION,
    SL_LICENSING_STATUS_LAST
} SLLICENSINGSTATUS;


//
// Licensing status
//
typedef struct _tagSL_LICENSING_STATUS
{
    SLID SkuId;                          // SKU id
    SLLICENSINGSTATUS eStatus;           // licensing status, see SLLICENSINGSTATUS
    DWORD dwGraceTime;                   // grace time in minute
    DWORD dwTotalGraceDays;              // pre-defined grace days in license
    HRESULT hrReason;                    // the error of unlicensed status
    UINT64 qwValidityExpiration;         // Validity expiration day
} SL_LICENSING_STATUS;

typedef enum _SL_GENUINE_STATE
{
    SL_GEN_STATE_IS_GENUINE         = 0,
    SL_GEN_STATE_INVALID_LICENSE,
    SL_GEN_STATE_TAMPERED,
    SL_GEN_STATE_LAST, 
} SL_GENUINE_STATE;

typedef struct _tagSL_NONGENUINE_UI_OPTIONS
{
    DWORD                       cbSize;
    CONST SLID*                 pComponentId;
    HRESULT                     hResultUI;

} SL_NONGENUINE_UI_OPTIONS;

//
// Specstrings
//

#ifndef __in
#define __in
#endif

#ifndef __out
#define __out
#endif

#ifndef __inopt
#define __inopt
#endif

#ifndef __outopt
#define __outopt
#endif

#ifndef __reserved
#define __reserved
#endif

#ifndef __optional
#define __optional
#endif

#define STUBAPI

#undef WINAPI
#define WINAPI


typedef
HRESULT
STUBAPI
WINAPI
(*SLOPEN_ROUTINE)(
    __out HSLC phSLC
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLCLOSE_ROUTINE)(
    __in HSLC phSLC
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLINSTALLPROOFOFPURCHASE_ROUTINE)(
    __in HSLC phSLC,
    __in PCWSTR pwszPKeyAlgorithm,
    __in PCWSTR pwszPKeyString,
    __in UINT cbPKeySpecificData,
    __in PBYTE pbPKeySpecificData,
    __out SLID* pPkeyId
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLINSTALLPROOFOFPURCHASEEX_ROUTINE)(
    __in HSLC hSLC,
    __in CONST SLID* pApplicationId,
    __inopt CONST SLID* pProductSkuId,
    __in PCWSTR pwszPKeyAlgorithm,
    __in PCWSTR pwszPKeyString,
    __in UINT cbPKeySpecificData,
    __in PBYTE pbPKeySpecificData,
    __out SLID* pPkeyId
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLUNINSTALLPROOFOFPURCHASE_ROUTINE)(
    __in HSLC hSLC,
    __in CONST SLID* pPKeyId
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLINSTALLLICENSE_ROUTINE)(
    __in HSLC hSLC,
    __in UINT cbLicenseBlob,
    __in CONST BYTE* pbLicenseBlob,
    __out SLID* pLicenseFileId
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLUNINSTALLLICENSE_ROUTINE)(
    __in HSLC hSLC,
    __in CONST SLID* pLicenseFileId
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLCONSUMERIGHT_ROUTINE)(
    __in HSLC hSLC,
    __in CONST SLID* pAppId,
    __inopt CONST SLID* pProductSkuId,
    __inopt PCWSTR pwszRightName,
    __reserved PVOID pvReserved
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLGETPRODUCTSKUINFORMATION_ROUTINE)(
    __in HSLC hSLC,
    __in CONST SLID* pProductSkuId,
    __in PCWSTR pwszValueName,
    __outopt SLDATATYPE* peDataType,
    __out UINT* pcbValue,
    __out PBYTE* ppbValue
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLGETPKEYINFORMATION_ROUTINE)(
    __in HSLC hSLC,
    __in CONST SLID* pPKeyId,
    __in PCWSTR pwszValueName,
    __outopt SLDATATYPE* peDataType,
    __out UINT* pcbValue,
    __out PBYTE* ppbValue
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLGETLICENSEINFORMATION_ROUTINE)(
    __in HSLC hSLC,
    __in CONST SLID* pPKeyId,
    __in PCWSTR pwszValueName,
    __outopt SLDATATYPE* peDataType,
    __out UINT* pcbValue,
    __out PBYTE* ppbValue
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLGETLICENSINGSTATUSINFORMATION_ROUTINE)(
    __in HSLC hSLC,
    __inopt CONST SLID* pAppID,
    __inopt CONST SLID* pProductSkuId,
    __inopt PCWSTR pwszRightName,
    __out UINT* pnStatusCount,
    __out SL_LICENSING_STATUS** ppLicensingStatus
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLGETPOLICYINFORMATION_ROUTINE)(
    __in HSLC hSLC,
    __in PCWSTR pwszValueName,
    __outopt SLDATATYPE* peDataType,
    __out UINT* pcbValue,
    __out PBYTE* ppbValue
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLGETPOLICYINFORMATIONDWORD_ROUTINE)(
    __in HSLC hSLC,
    __in PCWSTR pwszValueName,
    __out DWORD* pdwValue
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLGETSERVICEINFOMATION_ROUTINE)(
    __in HSLC hSLC,
    __in PCWSTR pwszValueName,
    __outopt SLDATATYPE* peDataType,
    __out UINT* pcbValue,
    __out PBYTE* ppbValue
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLGETAPPLICATIONINFORMATION_ROUTINE)(
    __in HSLC hSLC,
    __in CONST SLID* pApplicationId,
    __in PCWSTR pwszValueName,
    __outopt SLDATATYPE* peDataType,
    __out UINT* pcbValue,
    __out PBYTE* ppbValue
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLACTIVATEPRODUCT_ROUTINE)(
    __in HSLC hSLC,
    __in CONST SLID* pProductSkuId,
    __inopt UINT cbAppSpecificData,
    __inopt CONST PVOID pvAppSpecificData,
    __inopt CONST SL_ACTIVATION_INFO_HEADER* pActivationInfo,
    __inopt PCWSTR pwszProxyServer,
    __inopt WORD wProxyPort
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLGETSERVERSTATUS_ROUTINE)(
    __in PCWSTR pwszServerURL,
    __in PCWSTR pwszAcquisitionType,
    __inopt PCWSTR pwszProxyServer,
    __inopt WORD wProxyPort,
    __out HRESULT* phrStatus
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLREARM_ROUTINE)( 
    __in HSLC hSLC,
    __in CONST SLID* pApplicationId,
    __inopt CONST SLID* pProductSkuId,
    __in DWORD dwFlags
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLGENERATEOFFLINEINSTALLATIONID_ROUTINE)(
    __in HSLC hSLC,
    __in CONST SLID* pProductSkuId,
    __out PWSTR* ppwszInstallationId
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLGENERATEOFFLINEINSTALLATIONIDEX_ROUTINE)(
    __in HSLC hSLC,
    __inopt SLID* pProductSkuId,
    __inopt SL_ACTIVATION_INFO_HEADER* pActivationInfo,
    __out PWSTR* ppwszInstallationId
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLDEPOSITOFFLINECONFORMATIONID_ROUTINE)(
    __in HSLC hSLC,
    __in CONST SLID* pProductSkuId,
    __in PCWSTR pwszInstallationId,
    __in PCWSTR pwszConfirmationId
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLDEPOSITOFFLINECONFIRMATIONIDEX_ROUTINE)(
    __in HSLC hSLC,
    __inopt CONST SLID* pProductSkuId,
    __inopt CONST SL_ACTIVATION_INFO_HEADER* pActivationInfo,
    __in PCWSTR pwszInstallationId,
    __in PCWSTR pwszConfirmationId
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLGETPKEYID_ROUTINE)(
    __in HSLC hSLC,
    __in PCWSTR pwszPKeyAlgorithm,
    __in PCWSTR pwszPKeyString,
    __in UINT cbPKeySpecificData,
    __in CONST BYTE* pbPKeySpecificData,
    __out SLID* pPKeyId
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLGETINSTALLEDPRODUCTKEYIDS)(
    __in HSLC hSLC,
    __in CONST SLID* pProductSkuId,
    __out UINT* pnProductKeyIds,
    __out SLID** ppProductKeyIds
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLSETCURRENTPRODUCTKEY_ROUTINE)(
    __in HSLC hSLC,
    __in CONST SLID* pProductSkuId,
    __in CONST SLID* pProductKeyId
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLGETSLIDLIST_ROUTINE)(
    __in HSLC hSLC,
    __in SLIDTYPE eQueryIdType,
    __inopt CONST SLID* pQueryId,
    __in SLIDTYPE eReturnIdType,
    __out UINT* pnReturnIds,
    __out SLID** ppReturnIds
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLGETLICENSEFILEID_ROUTINE)(
    __in HSLC hSLC,
    __in UINT cbLicenseBlob,
    __in CONST BYTE* pbLicenseBlob,
    __out SLID* pLicenseFileId
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLGETLICENSE_ROUTINE)(
    __in HSLC hSLC,
    __in CONST SLID* pLicenseFileId,
    __out UINT* pcbLicenseFile,
    __out PBYTE* ppbLicenseFile
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLFIREEVENT_ROUTINE)(
    __in HSLC hSLC,
    __in PCWSTR pwszEventId,
    __in CONST SLID* pApplicationId
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLREGISTEREVENT_ROUTINE)(
    __inopt HSLC hSLC,
    __in PCWSTR pwszEventId,
    __in CONST SLID* pApplicationId,
    __in HANDLE hEvent
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLUNREGISTEREVENT_ROUTINE)(
    __inopt HSLC hSLC,
    __in PCWSTR pwszEventId,
    __in CONST SLID* pApplicationId,
    __in HANDLE hEvent
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLGETWINDOWSINFORMATION_ROUTINE)(
    __in HSLC hSLC,
    __out SLDATATYPE* peDataType,
    __out UINT* pcbValue,
    __out PBYTE* ppbValue
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLGETWINDOWSINFORMATIONDWORD_ROUTINE)(
    __in PCWSTR pwszValueName,
    __out DWORD* pdwValue
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLISGENUINELOCAL_ROUTINE)(
    __in CONST SLID* pAppId,
    __out SL_GENUINE_STATE* pGenuineState,
    __inopt SL_NONGENUINE_UI_OPTIONS* pUIOptions
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLISGENUINELOCALEX_ROUTINE)(
    __in CONST SLID* pAppId,
    __inopt CONST SLID* pSkuId,
    __out SL_GENUINE_STATE* pGenuineState
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLACQUIREGENUINETICKET_ROUTINE)(
    __out VOID** ppTicketBlob,
    __out UINT* pcbTicketBlob,
    __in PCWSTR pwszTemplateId,
    __in PCWSTR pwszServerUrl,
    __inopt PCWSTR pwszClientToken
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLSETGENUINEINFORMATION_ROUTINE)(
    __in CONST SLID* pQueryId,
    __in PCWSTR pwszValueName,
    __in SLDATATYPE eDataType,
    __inopt UINT cbValue,
    __inopt CONST BYTE* pbValue
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLGETREFERRALINFORMATION_ROUTINE)(
    __in HSLC hSLC,
    __in SLREFERRALTYPE eReferralType,
    __in CONST SLID* pSkuOrAppId,
    __in PCWSTR pwszValueName,
    __out PWSTR* ppwszValue
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLPERSISTRTSPAYLOADOVERRIDE_ROUTINE)(
    __in HSLC hSLC,
    __in CONST SLID* pApplicationId,
    __inopt CONST SLID* pProductSkuId,
    __in BYTE* pbData,
    __in DWORD cbData
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLPERSISTAPPLICATIONPOLICIES_ROUTINE)(
    __in CONST SLID* pApplicationId,
    __in CONST SLID* pProductSkuId,
    __in DWORD dwFlags
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLGETAPPLICATIONPOLICY_ROUTINE)(
    __in HSLP hPolicyContext,
    __in PCWSTR pwszValueName,
    __outopt SLDATATYPE* peDataType,
    __out UINT* pcbValue,
    __out PBYTE* ppbValue
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLLOADAPPLICATIONPOLICIES_ROUTINE)(
    __in CONST SLID* pApplicationId,
    __in CONST SLID* pProductSkuId,
    __in DWORD dwFlags,
    __out HSLP* phPolicyContext
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLUNLOADAPPLICATIONPOLICIES_ROUTINE)(
    __in HSLP hPolicyContext,
    __in DWORD dwFlags
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLGETAUTHENTICATIONRESULT_ROUTINE)(
    __in HSLC hSLC,
    __out UINT* pcbValue,
    __out PBYTE* ppbValue
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLSETAUTHENTICATIONRESULT_ROUTINE)(
    __in HSLC hSLC,
    __inopt UINT cbValue,
    __inopt CONST BYTE* pbValue
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLSETAUTHENTICATIONDATA_ROUTINE)(
    __in HSLC hSLC,
    __inopt UINT cbValue,
    __inopt CONST BYTE* pbValue
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLGETGENUINEINFORMATION_ROUTINE)(
    __in CONST SLID* pQueryId,
    __in PCWSTR pwszValueName,
    __outopt SLDATATYPE* peDataType,
    __out UINT* pcbValue,
    __out BYTE** ppbValue
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLGETGENUINEINFORMATIONEX_ROUTINE)(
    __in CONST SLID* pAppId,
    __in PCWSTR pwszValueName,
    __outopt SLDATATYPE* peDataType,
    __out UINT* pcbValue,
    __out BYTE** ppbValue
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLGATHERMIGRATIONBLOB_ROUTINE)(
    __in BOOL bMigratableOnly,
    __inopt LPCWSTR pwszEncryptorUri,
    __in HANDLE hFile
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SLDEPOSITMIGRATIONBLOB_ROUTINE)(
    __in HANDLE hFile
    );

//
// Private Guessed API
//

typedef
HRESULT
STUBAPI
WINAPI
(*SL0ARGS_ROUTINE)(
    void
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SL1ARGS_ROUTINE)(
    __in PVOID pArg0
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SL2ARGS_ROUTINE)(
    __in PVOID pArg0,
    __in PVOID pArg1
    );

typedef
HRESULT
STUBAPI
WINAPI
(*SL3ARGS_ROUTINE)(
    __in PVOID pArg0,
    __in PVOID pArg1,
    __in PVOID pArg2
    );


#endif