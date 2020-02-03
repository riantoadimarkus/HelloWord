#ifndef _COM_IFFUNC_H_
#define _COM_IFFUNC_H_

typedef enum
{
	DRV_SUCCESS,							// (= 0)This function finishes successfully.
	DRV_ERR_INVALID_DRIVER_VERSION,			// (= 1)The version of the driver is invalid.
	DRV_ERR_INVALID_FIRMWARE_VERSION,		// (= 2)The version of the firmware is invalid.
	DRV_ERR_CONNECTION_ALREADY_OPENED,		// (= 3)The connection is opened already.
	DRV_ERR_PRINTER_OFFLINE,				// (= 4)The printer is offline state.
	DRV_ERR_CANNOT_SEND_DATA,				// (= 5)The printer driver cannot send  data to the printer.
	DRV_ERR_INVALID_RESPONSE,				// (= 6)The response of the printer is invalid.
	DRV_ERR_CONNECTION_TIMEOUT,				// (= 7)No response is returned from the printer within the specific time.
	DRV_ERR_CONNECTION_NOT_OPENED,			// (= 8)DBStatementOpen( ) was not executed
	DRV_ERR_INVALID_PARAMETER,				// (= 9)Input parameter is invalid
	DRV_ERR_NO_CALLBACK_FUNCTION,			// (= 10)There is no callback function registerd.
	DRV_ERR_PRINTING_ALREADY_IN_PROGRESS,	// (= 11)Print job is already sent to the printer by GDI
	DRV_ERR_NO_PAPER,						// (= 12)There is no paper to present, cut, eject and retract.
	DRV_ERR_FILE_NOT_FOUND,					// (= 13)Specified file is not found.
	DRV_ERR_INVALID_FILE_FORMAT,			// (= 14)The format of the file is invalid or the file has wrong CRC.
	DRV_ERR_NO_DATA_TO_PURGE,				// (= 15)There is no data to purge.
	DRV_ERR_INTERNAL,						// (= 16)There is an error between the DLL and the language monitor.
	DRV_ERR_PRINTING_NOT_START,				// (= 17)
	DRV_ERR_PRINTING_NOT_FINISH,			// (= 18)
	DRV_ERR_TRANSPORTING_NOT_START,			// (= 19)
	DRV_ERR_TRANSPORTING_NOT_FINISH,		// (= 20)
	DRV_ERR_CUT_NOT_START,					// (= 21)
	DRV_ERR_CUT_NOT_FINISH,					// (= 22)
	DRV_FAILURE,							// (= 23) Self test fail
	DRV_ERR_NOT_INSTALLED,					// (= 24) Option not installed
	DRV_ERR_SPOOL_SUSPEND,					// (= 25) Spool service suspended
	DRV_ERR_COVER_OPEN,						// (= 26) Cover open error
	DRV_ERR_UNDER_PAPER_FEEDING,			// (= 27) Under paper feeding
	DRV_ERR_PRINTING_STOPPED,				// (= 28) Printing stop
	DRV_ERR_UNDER_SELFTEST,					// (= 29) Self test doing
	DRV_ERR_PAPER_END,						// (= 30) Paper end
	DRV_ERR_CG_BROKEN,						// (= 31) CG broken
	DRV_ERR_CUTTER_ERROR,					// (= 32) Cutter error
	DRV_ERR_UNRECOVERABLE_ERROR,			// (= 33) Unrecoverable error
	DRV_ERR_PAPER_JAM_TRANSPORT,			// (= 34) Paper jam on transort jam sensor
	DRV_ERR_PAPER_JAM_TOF,					// (= 35) Paper jam on TOF sensor
	DRV_ERR_PAPER_JAM_EXIT,					// (= 36) paper jam on exit sensor
	DRV_ERR_RETRACT_BIN_FULL,				// (= 37) Retract bin full
	DRV_ERR_HARDWARE_ERROR,					// (= 38) Headware error
	DRV_ERR_THERMAL_HEAD_TEMPERATURE,		// (= 39) Thermal head temperature error
	DRV_ERR_PRINTER_CANNOT_OPEN,			// (= 40) Printer handle can not open.
	DRV_ERR_EMPTY_FW_TRACE,					// (= 41) Firmware tarce file not found.
	DRV_ERR_CANNOT_LOAD_DLL,				// (= 42) Dll can not load.
	DRV_ERR_FEEDER_NOT_INSTALLED,			// (= 43) Dual feeder not installed
	DRV_ERR_FEEDER_CANNOT_SELECT,			// (= 44) Active feeder can not selected.
	DRV_ERR_FEEDERCHANGE_NOT_START,			// (= 45) Time out for start of Feeder change
	DRV_ERR_FEEDERCHANGE_NOT_FINISH,		// (= 46) Time out for end of Feeder change
	DRV_ERR_PAPER_JAM_DUALFEEDER,			// (= 47) Paper jam on dual feeder
	DRV_ERR_UNABLE_LOAD_FEEDER1,			// (= 48) Unable to load at feeder #1
	DRV_ERR_UNABLE_LOAD_FEEDER2,			// (= 49) Unable to load at feeder #2
	DRV_ERR_FEEDER_ALREADY_SELECTED,		// (= 50) Target feeder already selected
} PRETURNS;

typedef struct {
	union{
		DWORDLONG	wVal;
		struct{
			//Printer Status
			BYTE Undefined1:2;				// 0-1 : OFF ON
			BYTE CashDrawer:1;				// 2   : One or both cash drawers open
			BYTE Offline:1;					// 3   : Offline state
			BYTE Undefined2:4;				// 4-7 : ON X X OFF
			
			//Offline Status
			BYTE Undefined3:2;				// 0-1 : OFF ON
			BYTE CoverOpen:1;				// 2   : Open cover
			BYTE ButtonFeed:1;				// 3   : Paper feeding due to Feed button
			BYTE Undefined4:1;				// 4   : ON
			BYTE PrintStop:1;				// 5   : Stop printing due to paper low
			BYTE Error:1;					// 6   : Error condition
			BYTE Undefined5:1;				// 7   : OFF
			
			//Error Status
			BYTE Undefined6:3;				// 0-2 : Undefined. Bit0: Fixed to off. Bit1: Fixed to on. Bit2: Fixed to off.
			BYTE CutterErr:1;				// 3   : Cutter error
			BYTE Undefined7:1;				// 4   : Not used. Fixed to on.
			BYTE UnrecoverableErr:1;		// 5   : Unrecoverable error occurred.
			BYTE AutoRecoverableErr:1;		// 6   : Automatically recoverable error occurred.
			BYTE Undefined8:1;				// 7   : Not used. Fixed to off.
			
			//Sensor Status
			BYTE Undefined9:2;				// 0-1 : Undefined. Bit0: Fixed to off. Bit1: Fixed to on.
			BYTE PaperLow1:1;				// 2   : Paper low condition
			BYTE PaperLow2:1;				// 3   : Paper low condition
			BYTE Undefined10:1;				// 4   : Not used. Fixed to on.
			BYTE PaperExhausted1:1;			// 5   : Paper exhausted or paper jam
			BYTE PaperExhausted2:1;			// 6   : Paper exhausted or paper jam
			BYTE Undefined11:1;				// 7   : Not used. Fixed to off.
			
			//Reserved
			BYTE Undefined12:8;				// 0-7 : Reserved byte 0000 0000
			
			//Other Error Status
			BYTE Undefined13:2;				// 0-1 : OFF ON
			BYTE ThermalHead:1;				// 2   : Thermal head failure dots exist
			BYTE Undefined614:5;			// 3-7 : OFF ON OFF OFF OFF OFF
		}Bit;
	}AllStatus;
}STS_INTERNAL,*PSTS_INTERNAL,*LPSTS_INTERNAL;

//typedef struct {
//	BYTE PrinterStatus;
//	BYTE OfflineStatus;
//	BYTE ErrorStatus;
//	BYTE SensorStatus;
//	BYTE OtherStatus;
//  BYTE WarnStatus;
//} STSDATA, *PSTSDATA, *LPSTSDATA;

typedef struct {
	DWORDLONG AllStatus;
} STSDATA, *PSTSDATA, *LPSTSDATA;

typedef struct {
	BYTE SensorStatus;
//	WORD DualFeederSensorStatus;
}SENSORDATA, *PSENSORDATA, *LPSENSORDATA;

typedef struct {
	union{
		WORD wVal;
		struct {
			WORD notuse1:2;					// 0-1  : not use
			WORD PaperNearEnd_1:2;			// 2-3  : Paper near end #1
			WORD notuse2:1;					// 4    : not use
			WORD PaperEnd:2;				// 5-6  : Paper end
			WORD notuse3:1;					// 7    : not use
			WORD TransportJam:1;			// 8    : Transport jam
			WORD TOF:1;						// 9    : TOF 
			WORD notuse4:1;					// 10   : not use
			WORD Exit:1;					// 11   : Exit sensor
			WORD TOF_Mark:1;				// 12   : TOF mark sensor
			WORD notuse5:3;					// 13-15: not use
		}Bit;
	}EngineSensor;
	union{
		WORD wVal;
		struct{
			WORD PaperNearEnd_2:2;			// 0-1  : Paper near end #2
			WORD DF_1a:1;					// 2    : DF_1a
			WORD DF_2a:1;					// 3    : DF_2a
			WORD DF_1b:1;					// 4    : DF_1b
			WORD DF_2b:1;					// 5    : DF_2b
			WORD notuse:10;					// 6-15 : not use
		}Bit;
	}FeederSensor;
}SENSOR_DETAIL,*PSENSOR_DETAIL, *LPSENSOR_DETAIL;

#define PART_NUMBER_LEN				12
//#define MODULE_SERIAL_LEN			10
#define MODULE_SERIAL_LEN			8
#define HW_REVISION_LEN				4
#define MF_LOCATION_LEN				15
#define MF_DATE_LEN					10
#define PRT_POSITION_LEN			15
#define BOOT_VERSION_LEN			5
#define BOOT_CRC_LEN				2
#define BOOT_DATE_LEN				10
#define FW_VERSION_LEN				5
#define FW_CRC_LEN					2
#define FW_DATE_LEN					10
#define CG_VERSION_LEN				5
#define CG_CRC_LEN					2
#define CG_DATE_LEN					10

#define MFG_DATA_SIZE				(PART_NUMBER_LEN + MODULE_SERIAL_LEN + HW_REVISION_LEN + MF_LOCATION_LEN + \
									MF_DATE_LEN + PRT_POSITION_LEN + BOOT_VERSION_LEN + BOOT_CRC_LEN + BOOT_DATE_LEN + \
									FW_VERSION_LEN + FW_CRC_LEN + FW_DATE_LEN + CG_VERSION_LEN + CG_CRC_LEN + CG_DATE_LEN)

typedef struct {
	BYTE DieboldPartNumber[PART_NUMBER_LEN];	
	BYTE ModuleSerialNumber[MODULE_SERIAL_LEN];	
	BYTE HWRevisionLevel[HW_REVISION_LEN];
	BYTE ManufacturingLocation[MF_LOCATION_LEN];
	BYTE ManufacturingDate[MF_DATE_LEN];
	BYTE PrinterPosition[PRT_POSITION_LEN];
	BYTE BootLoaderRevision[BOOT_VERSION_LEN];
	BYTE BootLoaderCRC[BOOT_CRC_LEN];
	BYTE BootLoaderDate[BOOT_DATE_LEN];
	BYTE FWVersion[FW_VERSION_LEN];
	BYTE FWCRC[FW_CRC_LEN];
	BYTE FWDate[FW_DATE_LEN];
	BYTE CGVersion[CG_VERSION_LEN];
	BYTE CGCRC[CG_CRC_LEN];
	BYTE CGDate[CG_DATE_LEN];
} MFGDATA, *PMFGDATA, *LPMFGDATA;

typedef struct
{
	BYTE DieboldPartNumber[PART_NUMBER_LEN];
	BYTE HWRevisionLevel[HW_REVISION_LEN];
	BYTE PrinterPosition[PRT_POSITION_LEN];
} SETMFGDATA, *PSETMFGDATA, * LPSETMFGDATA;


typedef struct
{
	BYTE PrinterModel:1;			// Printer model (1ST/2ST)
	BYTE Transport:1;				// Transport option
	BYTE Feeder:1;					// Feeder option
	BYTE ResetSupport:1;			// SW/Quick reset support
	BYTE Reserved:1;
	BYTE PrinterID:3;				// Printer ID. 000:Snowhaven / 100:Entrylevel / 110:Viking
} PRTOPTION, *PPRTOPTION, *LPPRTOPTION;

typedef struct
{
	BYTE DualRollMode:2;			// Dual roll mode
	BYTE AutoLoad:1;				// Autoloading after changing feeder
//	BYTE FeederChangeControl:1;		// Auto Feeder Change control for 1st receipt after time out
	BYTE Reserved1:1;				// Not use
	BYTE PaperType:1;				// Paper Type (Feeder #2)
	BYTE Reserved2:3;				// Not use
} DFOPTION, *PDFOPTION, *LPDFOPTION;

typedef struct
{
	BYTE Reserved:1;				// Not use
	BYTE MediaControl:2;			// Media control on init
	BYTE FeedButton:1;				// Feed Button
	BYTE PaperLowPosi:1;			// Paper low sensor position
	BYTE Color:1;					// Two color printing
	BYTE PaperType:1;				// Paper type
	BYTE Reserved2:1;				// Not use
}GENERIC, *PGENERIC, *LPGENERIC;

typedef struct
{
	BYTE ButtonFeed:1;				// Feed button control.(Not used for Entry)
	BYTE LoadingFeed:1;				// Auto loading control.(Not used for Entry) 
	BYTE ExitSensorCtl:1;			// Exit sensor control.(For Entry level)	// Now this menber is Not use. Always fixed to 0.
	BYTE PaperRollSize:1;			// Paper roll size.(For Entry level)
	BYTE Reserved:4;				// Not use
}FEEDCONTROL, *PFEEDCONTROL, *LPFEEDCONTROL;

typedef struct
{
	BYTE Generic;					// Generic control setting
	BYTE LPICPI;					// CPI and LPI
//	BYTE RetractBin;				// Retract bin capacity
	BYTE Reserved1;					// Not used
	BYTE Option;					// Printer configuration for Option (Read only)
	BYTE PrintHeadEnergyControl;	// Print head energy control level
	BYTE CodePage;					// Code page (858)
	BYTE PPOOffset[2];				// Last page offset value
	BYTE FeedControl;				// Feed button control (After present)
	BYTE TimeOutIdle;				// Time out to idle state
	BYTE DualRollOption;			// Dual roll option
//	BYTE DualRollOption_2;			// Dual roll option 2
	BYTE Reserved2:1;				// Not used
	BYTE PPOOffset_2[2];			// Last page offset value for Feeder #2
//	BYTE Reserved[4];				// Reserved
} PRNCONFIG, *PPRNCONFIG, *LPPRNCONFIG;

typedef struct
{
	BYTE Reserved:1;				// Not used
	BYTE PaperSize:2;				// Paper size 
	BYTE CPI:1;						// CPI
	BYTE LPI:4;						// LPI
} CPILPI, *PCPILPI, *LPCPILPI;

typedef struct
{

	BYTE TimeOutIdle:4;				// Timeout to idle state 
	BYTE Reserved:4;				// Not used

} TIMEOUTIDLE, *PTIMEOUTIDLE, *LPTIMEOUTIDLE;

typedef struct {
	DWORD dwPrintHeadLife;			// Print Head Life
	DWORD dwFeedLineCount;			// Feed Line Count
	DWORD dwCuttingCount;			// Cutting Count
	DWORD dwBlackDotMarkSensor;		// Black dot mark sensor out put level
	DWORD dwPresentPaperCount;		// Present Paper Count
	DWORD dwRetractPaperCount;		// Retract Paper Count
	DWORD dwPrintheadLife2nd;		// Print Head Life of 2nd head (back side)
	DWORD dwFeedLineCount2nd;		// Feed line count of 2nd feeder in Dual Roll
	DWORD dwReserved[15];			// Reserved
} ALLMETRICS, *PALLMETRICS, *LPALLMETRICS;

typedef struct {
	char			Version[8];		// Version of FW
	unsigned short	CRC;			// CRC for file
	char			Date[8];		// File date
	char			DeviceCode;		// Device code 'S'
	char			ProgramCode;	// type of file 'B','M','C'
	BYTE			SectorNum;		// num of sector
	BYTE			Reserved[3];	// not use
} FWHead;

typedef struct {
	WORD wFWVersion;				//F/W Version
} PRINTERVERSION, *PPRINTERVERSION, *LPPRINTERVERSION;


typedef LONG (CALLBACK *StatusCallBack)(STSDATA *pStatus, LPVOID pCallbackContext);

enum{
	eIdle = 0,
	eHelthCheck
};

// action for Langage monitor
#define OPEN							L"Open"
#define GETSTATUS						L"StatusGet"
#define SETSTATUSCALLBACK				L"CallbackSet"
#define CANCELSTATUSCALLBACK			L"CallbackCancel"
#define TXRX							L"TxRx"
#define TXRX_NO_RESPONSE				L"TxRx_No_Response"
#define	TECRESET						L"Reset"
#define	TECRESET_EX						L"ResetEx"
#define GETMETRICS						L"GetMetrics"
#define GETALLMETRICS					L"GetAllMetrics"	
#define	SETMETRICS						L"SetMetrics"
#define GETMFG							L"GetMFGData"
#define SETMFG							L"SetMFGData"
#define SETMFGEX						L"SetMFGDataEx"
#define SETPRNCONFIG					L"SetConfiguration"
#define GETPRNCONFIG					L"GetConfiguration"
#define RECOVERERROR					L"Recover"
#define PRESENT							L"Present"
#define	PAPERREMOVED					L"PaperRemoved"
#define	STARTPAPERMONITOR				L"StartPaperMonitor"
#define	ENDPAPERMONITOR					L"EndPaperMonitor"
#define EJECT							L"Eject"
#define RETRACT							L"Retract"
#define CUT								L"Cut"
#define	PERFORMPAPERCHANGE				L"PaperChange"
#define ENTERSELFTEST					L"EnterSelfTest"
#define PERFORMSELFTEST					L"PerformSelfTest"
#define EXITSELFTEST					L"ExitSelfTest"
#define	PANELLEDCONTROL					L"Panel"
#define ENABLED							L"Enabled"
#define ADDEVENT						L"AddEvent"
#define PAPERLOWTRIGGER					L"PaperLowTrigger"

#define PURGEDATA						L"PurgeData"
#define	GETDLLVERSION					L"DllVersion"
#define GETTRANSPORTSTATUS				L"GetTransport"
#define GETSENSORSTATUS					L"GetSensor"
#define GETRETRACTEDCOUNT				L"GetRetractedCount"
#define	CLOSE							L"Close"
#define	TRANSPORT						L"Transport"		
#define DOWNLOAD						L"Download"
#define DL_STATUS						L"DownloadStatus"
#define DL_CANCEL						L"DownloadCancel"

#define DOWNLOAD_LOGO					L"DownloadLogo"
#define DOWNLOAD_PREDEFINE				L"DownloadPre_define"
#define ERASE_PREDEFINE					L"ErasePre_define"
#define GET_ACTIVEFEEDER				L"GetActiveFeeder"
#define SET_ACTIVEFEEDER				L"SetActiveFeeder"
#define GET_FW_TRACE					L"GetFirmwareTrace"
#define ERASE_FW_TRACE					L"EraseFirmwareTrace"
#define SAVE_FW_TRACE					L"SaveFirmwareTrace"
#define GET_TRACE_INFO					L"GetFirmwareTraceInfo"
#define GET_DF_STATUS					L"GetDualFeederStatus"

#define GET_MFG_FORMAT_TYEPE			L"GetMFGDataFormatType"

#define SWITCH_TO_IPLMODE				L"SwitchIPL"

#define	GETTHRESHOLD_LASTPAGE			L"GetThresholdForLastPage"
#define	GETFEEDINGVALUE					L"GetFeedingValue"
#define	GETPRINTERVERSION				L"GetPrinterVersion"
#define GETPRINTERSTATUS				L"GetPrinterStatus"
#define STARTPRINTING					L"StartPrinting"
#define ENDPRINTING						L"EndPrinting"

#define GET_FIRMWARE_LEVEL				L"GetFirmwareLevel"

//Data for langage monitor
#define	ENABLED_IN						L"Enabled_input"
#define	EVENT_ONOFF						L"SetEventLog"
#define PAPERLOW_OPT					L"SetPaperLow"
#define TXRX_TYPE						L"TxRx_Type"
#define TXRX_IN_TX_NAME					L"TxRx_Input_Tx_Name"
#define TXRX_IN_TX_SIZE					L"TxRx_Input_Tx_Size"
#define TXRX_IN_RX_SIZE					L"TxRx_Input_Rx_Size"
#define TXRX_IN_TIMEOUT					L"TxRx_Input_TimeOut"
#define SETMETRICS_IN					L"SetMetrics_Input"
#define METRICS_IN_ID					L"MetricID"
#define SETMFG_IN						L"SetMFGData_Input"
#define SETMFGEX_IN						L"SetMFGDataEx_Input"
#define SETPRNCONFIG_IN					L"SetPrnterConfig_Input"
#define DOWNLOAD_IN_NAME				L"Download_Input_Name"
#define DOWNLOAD_IN_TYPE				L"Download_Input_Type"
#define DOWNLOAD_IN_SIZE				L"Download_Input_Size"
#define DOWNLOAD_IN_TIMEOUT				L"Download_Input_TimeOut"
#define SELFTEST_IN_NAME				L"SelfTest_Input_Name"
#define SELFTEST_IN_SIZE				L"SelfTest_Input_Size"
#define SELFTEST_IN_ID					L"SelfTest_Input_ID"
#define SELFTEST_IN_PRINTMODE			L"SelfTest_Input_PrintMode"
#define PANELLEDCONTROL_IN				L"PanelLedControl_Input"
#define	TRANSPORT_IN					L"Transport_input"		
#define LOGO_IN_NAME					L"Logo_Input_Name"
#define LOGO_IN_NO						L"Logo_Input_No"
#define LOGO_IN_SIZE					L"Logo_Input_Size"
#define PREDEFINE_IN_NAME				L"Predefine_Input_Name"
#define PREDEFINE_IN_SIZE				L"Predefine_Input_Size"
#define FEEDER_NO						L"FeederNo"

#define	RETURNVALUE						L"ReturnValue"
#define	TIMEINTERVAL					L"TimeInterval"
#define	OUTPUTTOFILE_CHECK				L"OutputToFile_Check"
#define OUTPUTTOFILE_PATH				L"OutputToFile_Path"
#define TOTALFEEDINGVALUE				L"TotalFeedingValue"
#define TOTALFEEDINGVALUE_DF1			L"TotalFeedingValueLower"
#define TOTALFEEDINGVALUE_DF2			L"TotalFeedingValueUpper"

#define SIMULATE_MODE					L"SimulationMode"
#define SIMULATE_STATUS					L"Simulate_Status"

#define HEALTH_MODE						L"HealthMode"
#define SPOOLER_HEALTH					L"HealthCounter"

#define CUSTOM_PAPER					L"CustomPaper"
#define LOG_SETTING_CHANGE				L"DriverSettingChangeLog"
#define LOG_SETTING_CONDITION			L"LogSettingCondition"

#define FIRMWARE_TRACE_TARGET			L"FirmwareTraceTarget"
#define PAPERREMOVE_MONITOR				L"PaperRemoveMonitor"

#define RESET_TYPE						L"ResetType"				// type of printer reset

#define STSDATA_PRINTINGFILE_READY		0x0001			// Printing data is ready(OtherStatus)
#define STSDATA_RETRACTBINFULL			0x0002			// Retract bin is full(OtherStatus)
#define STSDATA_LASTPAGE				0x0004			// LastPage(OtherStatus)
#define STSDATA_PAPERREMOVED			0x0040			// Paper remove(OtherStatus)
#define STSDATA_NOTCONNECTED			0x0080			// Disconnect (OtherStatus)

//#define TECRESET_HW					0x00			// HW reset execute
#define TECRESET_SW						0x01			// SW reset execute
#define TECRESET_QUICK					0x02			// Quick reset execute

#define PRINT_MODE_SINGLE				0x00			// Print mode single
#define PRINT_MODE_DUAL					0x02			// Print mode dual with dual
#define PRINT_MODE_PREDEFINED			0x03			// Print mode dual with pre-defined

//#define SELFTEST_ALL					0x00			// Perform all tests except item 2
//#define SELFTEST_CONFIGURATION		0x01			// Printer configuration printout
//#define SELFTEST_EEPROM				0x02			// EEPROM reset
//#define SELFTEST_ALL_CHARA			0x03			// All characters print test
//#define SELFTEST_ASCII				0x04			// Rolling ascii
//#define SELFTEST_BLACKMARK			0x05			// Black mark test
//#define SELFTEST_RETRACTING			0x06			// Retracting test
//#define SELFTEST_DOTCHECK				0x07			// Dot check pattern print
//#define SELFTEST_CUTTING				0x08			// Cutting test
//#define SELFTEST_PRESENTING			0x09			// Presenting test
//#define SELFTEST_APPLICATION			0x0A			// Print Application buffer
//#define SELFTEST_MEMORY				0x0B			// Memory test
//#define SELFTEST_MAX_COUNT			0x0C

#define SELFTEST_CONFIGURATION			0x01			// Printer configuration printout
#define SELFTEST_DOTCHECK				0x02			// Dot check pattern print
#define SELFTEST_MEMORY					0x03			// Memory test

#define LOG_ALL_DISABLE					0x00			// Log setting disable
#define LOG_FATAL						0x01			// Log setting fatal
#define LOG_ERROR						0x02			// Log setting error
#define LOG_WARNING						0x04			// Log setting warning
#define LOG_INFORMATION					0x08			// Log setting information
#define LOG_TRACE						0x10			// Log setting trace
#define LOG_PRINT_DATA					0x20			// Log setting print data

#define LOG_LEVEL_ERROR					(LOG_FATAL | LOG_ERROR)
#define LOG_LEVEL_WARNING				(LOG_FATAL | LOG_ERROR | LOG_WARNING)
#define LOG_LEVEL_DEBUG					(LOG_FATAL | LOG_ERROR | LOG_WARNING | LOG_TRACE | LOG_PRINT_DATA)

#define LOG_SETTING_CHANGE_BY_API		0x10
#define LOG_SETTING_CHANGE_BY_UI		0x01

#define	TXRX_BULK						0				// Bulk transfer (default)
#define TXRX_CONTROL					1				// Control transfer

#define TIMEINTERVAL_DEFAULT			100				// Status thread interval
#define TIMEOUT_DEFAULT					(1000 * 3)
#define TIMEOUT_TXRX_START				(1000 * 60)
#define TIMEOUT_TXRX_FINISH				(1000 * 30)
#define TIMEOUT_RESET					(1000 * 30)
#define TIMEOUT_PRESENT_START			(1000 * 5)
#define TIMEOUT_PRESENT_FINISH			(1000 * 20)
#define TIMEOUT_EJECT_START				(1000 * 5)
#define TIMEOUT_EJECT_FINISH			(1000 * 20)
#define TIMEOUT_RETRACT_START			(1000 * 5)
#define TIMEOUT_RETRACT_FINISH			(1000 * 120)	// Changed to 120sec from 40sec @20140711 H.Inaba
//#define TIMEOUT_RETRACT_FINISH			(1000 * 40)
#define TIMEOUT_CUT_START				(1000 * 3)
#define TIMEOUT_CUT_FINISH				(1000 * 15)
#define TIMEOUT_PAPERCHANGE_START		(1000 * 3)
#define TIMEOUT_PAPERCHANGE_FINISH		(1000 * 20)
#define TIMEOUT_PAPERREMOVED			(1000 * 30)
#define TIMEOUT_DOWNLOAD_ENTER			(1000 * 15)
#define TIMEOUT_DOWNLOAD_SENDDATA		(1000 * 10)
#define TIMEOUT_DOWNLOAD_WRITEFLASHROM	(1000 * 60)
#define TIMEOUT_DOWNLOAD_RESETFW		(1000 * 15)
#define TIMEOUT_SELFTEST_BLACKMARK		(1000 * 60)
#define TIMEOUT_SELFTEST_EEPROM_RESET	(1000 * 30)
#define TIMEOUT_SELFTEST_MEMORY_TEST	(1000 * 30)
#define TIMEOUT_AUTO_CUTTER_OFF			(1000 * 3)
#define TIMEOUT_PAGEMODE_OFF			(1000 * 5)
#define TIMEOUT_TRANSPORT_START			(1000 * 3)

#define TIMEOUT_RECEIVE_RESP			(1000 * 2)
#define TIMEOUT_RECEIVE_FW_TRACE		(1000 * 3)

#define TIMEOUT_PRINT_START				(1000 * 10)	

#define TIMEOUT_FEEDERCHANGE_START		(1000 * 5)
#define TIMEOUT_FEEDERCHANGE_FINISH		(1000 * 40)

#define	TIMEOUT_CONNECTION				20

// Paper near end position
#define PAPER_NEAREND_POSITION_A		1500			// Paper near end position A (1500cm)
#define PAPER_NEAREND_POSITION_B		5200			// Paper near end position B (5200cm)
#define PAPER_NEAREND_2ND_FEEDER		300				// Paper near end 2nd feeder (300cm)

#define PRINT_HEAD_LIFE_TH				150000			// Print head life threshold.(150km) 01/Aug/2011


#define WAIT_DEFAULT					500
#define WAIT_PAPERMONITOR				20			// Wait value for paper monitor
#define WAIT_PAPERMONITOR_TRANSPORT		(WAIT_PAPERMONITOR * 10)			// Wait value for paper monitor(during transport operation)
//#define WAIT_PAPERMONITOR_TRANSPORT		(WAIT_PAPERMONITOR * 4)			// Wait value for paper monitor(during transport operation)
#define WAIT_CUTMONITOR					(WAIT_PAPERMONITOR * 4)				// Wait value for cut monitor(during cut operation)
#define WAIT_MEMORY_TEST				5000		// wait value for memory test.(Printer self test)
#define WAIT_EEPROM_RESET				5000		// wait value for EEPROM reset.(Printer self test)
#define WAIT_COOLDOWN					(1000 * 35)	// wait value for cooling down of Thermal Head		@20140708 R.Kato
#define WAIT_FEEDER_CHG					(1000 * 35)	// wait value for auto feeder changing. (30+margin)	@20140915 R.Kato
#define WAIT_REMOVEBITON				(1000 * 3)	// wait value for paper remove bit set to ON after Cut for Viking/IRT.	@20141205 R.Kato

// Printer level 
#define LEVEL_UNKNOWN					0x00	// Phase unknown
#define LEVEL_PHASE_ONE					0x01	// Phase-1
#define LEVEL_PHASE_TWO					0x02	// Phase-2


#define STATUS_THREAD_INTERVAL			3000


#define SELECT_PAPER_82_5X297			0	// 82.5 x 297 mm
#define SELECT_PAPER_82_5X257			1	// 82.5 x 257 mm
#define SELECT_PAPER_80X297				2	// 80 x 297 mm
#define SELECT_PAPER_80X257				3	// 80 x 257 mm
#define SELECT_PAPER_60X297				4	// 60 x 297 mm
#define SELECT_PAPER_60X257				5	// 60 x 257 mm
#define SELECT_PAPER_58X297				6	// 58 x 297 mm
#define SELECT_PAPER_58X257				7	// 58 x 257 mm
#define SELECT_PAPER_3_24X6				8	// 3.24 x 6 in
#define SELECT_PAPER_3_24X10_5			9	// 3.24 x 10.5 in
#define SELECT_PAPER_3_24X11			10	// 3.24 x 11 in
#define SELECT_PAPER_3_14X6				11	// 3.14 x 6 in
#define SELECT_PAPER_3_14X10_5			12	// 3.14 x 10.5 in
#define SELECT_PAPER_3_14X11			13	// 3.14 x 11 in
#define SELECT_PAPER_2_36X6				14	// 2.36 x 6 in
#define SELECT_PAPER_2_36X10_5			15	// 2.36 x 10.5 in
#define SELECT_PAPER_2_36X11			16	// 2.36 x 11 in
#define SELECT_PAPER_2_28X6				17	// 2.28 x 6 in
#define SELECT_PAPER_2_28X10_5			18	// 2.28 x 10.5 in
#define SELECT_PAPER_2_28X11			19	// 2.28 x 11 in
#define SELECT_PAPER_82_5X3276			20	// 82.5 x 3276 mm
#define SELECT_PAPER_80X3276			21	// 80 x 3276 mm
#define SELECT_PAPER_60X3276			22	// 80 x 3276 mm
#define SELECT_PAPER_58X3276			23	// 80 x 3276 mm
#define SELECT_PAPER_80X508				24	// 80 x 508 mm



#endif