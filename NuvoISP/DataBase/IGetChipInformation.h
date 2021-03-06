#pragma once

#define GETCHIPINFO_LIBRARY_NAME	_T("GetChipInformation.dll")
#define CREATE_CHIP_MANAGER_NAME	_T("CreateChipInfoManager")
#define CHIP_NAME_LEN				100
#define GROUP_NAME_LEN				100
#define CHIP_UCID_MAX_LEN			4
#define CHIP_CFG_MAX_LEN			4

enum eAllChipSeries : DWORD {
    ISD_94000_SERIES			= 0x100001,
    ISD_91200_SERIES			= 0x100002,
    ISD_9160_SERIES				= 0x100003,
    ISD_91300_SERIES			= 0x100004,
    ISD_91000_SERIES			= 0x100005,
    NUVOICE_N572F064_SERIES		= 0x200001,
    NUVOICE_N572F072_SERIES		= 0x200002,
    NUVOICE_N571_SERIES			= 0x300001,
    NUVOICE_N569_SERIES			= 0x400001,
    NUVOICE_N570_SERIES			= 0x500001,
    NUVOICE_N575_SERIES			= 0x600001,
    NUVOICE_N576_SERIES			= 0x700001,
    NUVOICE_JNK561_SERIES		= 0x800001,
};

typedef struct sChipInfo {
    DWORD	dwChipID;
    DWORD	dwChipIDMask;
    DWORD	dwChipUCID[CHIP_UCID_MAX_LEN];
    char	sChipName[CHIP_NAME_LEN];
    DWORD	dwSeriesEnum;
    DWORD	dwAPROMSize;
    DWORD	dwLDROMSize;
    DWORD	dwEmbeedSPIFlashSize;
    DWORD	dwSRAMSize;
    DWORD	dwErasePageSize;
    DWORD	dwDataFlashAddress;
    DWORD	dwDataFlashSize;
} sChipInfo;

enum eChipInfoError {
    ECE_NO_ERROR,
    ECE_NO_CHIP_CFG_DATA,
    ECE_NO_MATCH_CHIP,
    ECE_NO_MATCH_SERIES,
    ECE_EXPORT_FAILED,
    ECE_CFG_NO_CFG,
    ECE_CFG_DATAFLASH_ADDRESS_ERROR,
};

class I_ChipInfoManager
{
public:
    virtual void ReleaseDLL() = 0;
    virtual eChipInfoError GetChipInfo(DWORD dwChipID, sChipInfo &GetChipInfo, DWORD *dwCfg = NULL) = 0;
};

typedef BOOL (FAR WINAPI *CREATE_CHIPINFO_MANAGER)(I_ChipInfoManager **pIGetChipInfoManager);
