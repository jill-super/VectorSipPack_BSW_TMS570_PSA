/* STARTSINGLE_OF_MULTIPLE */

/*******************************************************************************
|      Project Name: S T A T I O N - M A N A G E R   F O R   P S A 
|         File Name: Stat_Mgr.h
|
|       Description: Application-Interface of station manager for PSA
|                    Low Speed Fault Tolerant Bus 
|                    Declaration of functions, variables and constants
|
|-------------------------------------------------------------------------------
|               C O P Y R I G H T
|-------------------------------------------------------------------------------
| Copyright (c) 2001-2013 Vector Informatik GmbH           All rights reserved.
|
| This software is copyright protected and proprietary
| to Vector Informatik GmbH. Vector Informatik GmbH
| grants to you only those rights as set out in the
| license conditions. All other rights remain with
| Vector Informatik GmbH.
|
|-------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-------------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     ---------------------------------------
| Sf / vissf   Dieter Schaufelberger     Vector Informatik GmbH
| Et           Thomas Ebert              Vector Informatik GmbH
| vismas       Markus Schwarz            Vector Informatik GmbH
| vismdr       Markus Drescher           Vector Informatik GmbH
| vismpf       Marco Pfalzgraf           Vector Informatik GmbH
|-------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-------------------------------------------------------------------------------
| Date        Ver    Author  Description
| ---------   -----  ------  ---------------------------------------------------
| 2002-06-03  1.00   Sf      first implementation
| 2002-06-17  1.01   Sf      -ESCAN00003063: Removed CanInterruptDisabel() and 
|                            Restore from SmInitPowerOn()
|                            -NetworkTask(): Create new makro to enter given 
|                            Offline mode. Overworking of PartOffline modes.
|                            -Inserted correct version.
| 2002-07-23  1.10   Sf      Version Step due to Merge of Station Manager VDO 
|                            and Standard Module
|                            New specification PSA:
|                            ESCAN00002817: new Bus Off recovery sequence
|                            ESCAN00002818: Part Offline mode for diagnosis
|                            ESCAN00002819: new error counter handling
|                            ESCAN00002820: guaranteed state change in 10ms
| 2002-07-30  1.11   Et      ESCAN00003378: status callback functions
|                            ESCAN00003379: offline mask for diagnostics
|                            ESCAN00003381: initialisation of CANbedded SW components
|                            ESCAN00003382: interrupt disable/restore for power on initialisation
|                            ESCAN00003383: NM state task <=> NM timer task
|                            ESCAN00003384: PartOnline/PartOffline mask
|                            ESCAN00003385: startup network state "REVEIL"
|                            ESCAN00003386: prototypes "SmTx/RxTimeoutSupervision"
|                            ESCAN00003388: non-volatile counter for BusOff
|                            ESCAN00003389: non-volatile counter access
|                            ESCAN00003391: initialisation object of CAN driver
| 2002-08-15 1.12    Sf/Et   ESCAN00003459: move const variables to ROM
|                            ESCAN00003433: Enable transmission of all functional
|                                           messages in Mode Degrade
|                            ESCAN00003509: Organ Type 1 inserted
| 2002-09-20 1.13   Sf       ESCAN00003813: Array inmkIncNerr[] and inmkDecNerr[] 
|                                           accessed with wrong index 
|                            ESCAN00003814: After Bus Off not all given 
|                                           ECU states could be reached 
| 2002-10-01 1.14   Sf       ESCAN00003640: Minor -
|                            ESCAN00003641: Code -
|                            ESCAN00003643: and -
|                            ESCAN00003644: Syntax -
|                            ESCAN00003648: changes 
|                            ESCAN00003639: suffixes added
|                            ESCAN00003941: suffixes added
| 2002-10-01 1.15   Sf       ESCAN00003850: (Renault) Messages with a DLC too short, 
|                                           shall still  be taken into account
|                                           for the absent/present supervision. 
|                            ESCAN00003851: (Renault) Message independant bus off timer 
| 2002-10-24 1.16   Sf       Renault Sleep Management Slave Reduced and Slave Complete
|                            inserted  
| 2002-11-21 1.17   Sf       Removed ESCAN00003814 Not necessary according to PSA 
|                            ESCAN00004359: new define to use in can_inc
| 2002-12-07        Et       ESCAN00004393: Tx timeout supervision in state != NORMAL
| 2002-12-09 1.18   Sf       ESCAN00004304: For the supervised Tx message the IL
|                                           Timeout signals and functions are not available
|                            ESCAN00004305: Support of Organtype2 
|                            ESCAN00004332: Renault: Handling of 2 diagMuxOn signals
|                            ESCAN00004333: New switch to pass BusOff handling from 
|                                           the NM to the application
|                            ESCAN00004335: Improvement of the PSA Sleepmanagement
| 2002-12-18 1.19  Sf        ESCAN00004498: Compile error <<CanRxHandle undefined>>
| 2003-01-31 1.20  Sf        ESCAN00004747: loss of communication after receiving 
|                                           request to go to "veille"      
|                            ESCAN00004761: non-volatile counter PerteCOM and C_ABSENT 
|                                           (customer Siemens VDO) 
|                            ESCAN00004778: There are two different implemented 
|                                           algorithms to detect the network state "PerteCOM"
| 2003-02-19 1.21  Sf        ESCAN00004932: Treatment of bit INTERD_MEMO_DEF added
|                            ESCAN00004933: Confirmed Absent handling of Nerr fixed
|                            ESCAN00004851: Renault only: Access of wSmRxToCycCntr with wrong index
| 2003-02-22       Et        ESCAN00005001: Tx type of NM message
|                                           (customer Siemens VDO)
| 2003-02-27 1.22  Sf        ESCAN00004930: Renault: SmStop doesn't stop the timeoutsupervision 
|                                           of certain messages 
|                            ESCAN00005037: Support of PSA High Speed Nm
|                            ESCAN00005102: Call of SmStart may lead to inconsistent 
|                                           states between INM and SM
|                            ESCAN00005103: PSA: "CanPartOffline(C_SEND_GRP_NONE)" in state "Veille"
|                            ESCAN00005098: PSA: configuration to access information "INTERD_MEMO_DEF"
|                            ESCAN00005121: PSA: timeout detection for message "BSI_COMMANDES" in state "veille"
| 2003-03-27 1.23  Sf        ESCAN00005219: PSA: undefined network management states 0x06 and 0x07
|                            ESCAN00005220: PSA: Access macro for NerrState
|                            ESCAN00005233: ApplSmStatusIndication isn't called on SmStart() 
| 2003-04-04 1.24  Sf        ESCAN00005337: Support of Multiple ECUs added 
|                            ESCAN00005265: add offline mode check 
| 2003-05-28 1.25  Sf        ESCAN00005594: Sendtype Event for supervised sendmessage not supported by SM
|                            ESCAN00005602: PSA only: BusOff recovery failed for HighSpeed systems
|                            ESCAN00006127: recursive function call "ApplInmNmStatusIndicationRx"
|                            SLP2:
|                            ESCAN00006191: PSA: Unspecified value of phase_vie signal shall be taken as state"normal"
|                            ESCAN00006192: PSA: If the ECU wakes up the CAN bus, it has to ignore 
|                                           the phase_vie value "Mis_en_veille" for one second
|                            ESCAN00006193: PSA: Modification of the BusOff recovery sequence
|                            ESCAN00006194: PSA: Supervision of Mode Degrade Fonctionnel
| 2003-08-08 1.26 Sf         ESCAN00006362: PSA: Stationmanager must check the received 
|                                           DLC against Lmin in the Generic Precopy function
| 2003-09-11 1.27 Sf         ESCAN00006514: Minimum send delay may be neglected if no IL present
|                            ESCAN00006694: Compiler Error in specific configuration 
| 2003-10-10 1.27.01 Sf      ESCAN00006759: Compile Error if neither kCanNumberOfInitObjects 
|                                           nor kCanNumberOfInit is generated
| 2003-12-12 1.28.00 Sf      ESCAN00006525: PSA: If a message is rejected due to DLC < Lmin 
|                                           it must not be taken into account for the NM
|                            ESCAN00006963: Callback function ApplCanErrorPin() is called to late  
|                            ESCAN00007228: Provide Macro to set volatile BusOff counter
|                            ESCAN00007239: PSA only: If signal INTERD_MEMO_DEF is set,  
|                                           BusOff and PerteCom counters are stopped
|                            ESCAN00007241: PSA only: Callbackfunction ApplSmModeDegradeOn and Off 
|                                           should be only called if Mode degrade functionnel is requested
| 2004-02-05 1.29.00 Sf      ESCAN00007418: PSA only: Functional message may be sent once in state not allowed
|                            ESCAN00007445: PSA: No BusOff Recovery if CanInit() is called in CanResetBusOffEnd() 
|                            ESCAN00007467: Can Driver Multi channel API not supported by SM
| 2004-02-20 1.30.00 Sf      ESCAN00007652: Todo: Renault Only: Producer of Signal <DiagMux > must set
|                                           DiagMux state internally
| 2004-03-30 1.31.00 Sf      ESCAN00007873: SLP2 only: Unspecified ECU State (Phases_de_vie) 0x5 is not handled
|                                           as state "normal"
| 2004-04-02 1.32.00 Sf      ESCAN00008084: Renault only: Application specific fault management not supported
| 2004-05-04 1.33.00 Sf      ESCAN00008305: Remove Misra warnings
|                            ESCAN00008387: Multiple nodes: table SmIndirection is now multidimensional: changed access
| 2004-05-18 1.34.00 Sf      ESCAN00008427: Function CanSetVariableRxDataLen() is undefined in some configurations
| 2004-05-21 1.35.00 Sf      ESCAN00008451: PSA HighSpeed Nm corrections
| 2004-11-04 1.36.00 Sf      ESCAN00009247: PSA only: For ECUs of Organ type 2 BSI can't reach confirmed absent state
|                            ESCAN00009701: PSA only: for Organ type 2 insert supervision of Timeout Toff
| 2004-12-04 1.37.00 Sf      ESCAN00010242: PSA only: variable bSmState not initialized 
| 2005-02-08 1.38.00 Sf      ESCAN00010993: PSA only: PSA Only: Variables undeclared for Organtype 3
| 2005-03-16 1.39.00 Sf      ESCAN00011479: PSA only: Transmission of functional messages in a state 
|                                           where it is not allowed (non-conformance to specification)
|                            ESCAN00011487: PSA only: support transmission control for JDD message
|                            ESCAN00011546: Adding cast for ST7_beCAN to remove warnings
| 2005-06-17 1.40.00 Sf      ESCAN00012407: linker error due to missing cast
|                            ESCAN00012439: Network diagnosis does not restart after confirmed  PerteCom
|                            ESCAN00012522: No state transition into Sleep Mode 
| 2005-09-01 1.41.00 Sf      ESCAN00012182: Additional Wake up reason must be inserted to support CCL
|                            ESCAN00013696: Add new requirement from specification IND[D]
|                            ESCAN00013697: Move handling of Timeout indication for INM from Interrupt to Task context
| 2005-12-02 1.42.00 Sf      ESCAN00014729: Transmission of functional frames activated 
|                                           in state where transmission is not allowed
| 2006-01-10 1.43.00 Sf      ESCAN00014837: Incorrect WakeUp behavior in State PerteCom
| 2006-02-13 2.00.00 Sf      ESCAN00016971: Support of generic Osek_inm
| 2006-11-23 2.01.00 Sf      ESCAN00017932: No changes
|                            ESCAN00018441: No changes
|                            ESCAN00018488: No changes
|                            ESCAN00018489: No changes
| 2007-01-15 2.02.00 Sf      ESCAN00018899: No changes
| 2007-03-13 2.03.00 Sf      ESCAN00019905: No changes
| 2007-06-19 2.04.00 Sf      ESCAN00021034: No changes
|                            ESCAN00021113: Add support for dynamic tx supervision
| 2007-09_18 2.04.01 Sf      ESCAN00022377: No changes
|                            ESCAN00022378: No changes
| 2007-10_31 2.05.00 Sf      ESCAN00022994: Minimum send delay violated in case of a event message
|                            ESCAN00022997: BSI is reported <Confirmed Present> too fast
| 2007-12_12 3.00.00 Sf      --- Rework PSA SLP4
| 2008-03-11 3.00.01 Sf      ESCAN00024956: N_as counter incremented while active WakeUp
|                            ESCAN00025172: Compile error 
|                            ESCAN00025170: New API to reset the supervision on diagnostic request
|                            ESCAN00025407: ECU may reset   
| 2008-04-07 3.00.02 Vissf   ESCAN00025681: No changes
|                            ESCAN00025767: No changes
|                            ESCAN00025824: No changes
| 2008-05-15 3.00.03 Vissf   ESCAN00026898: Start-Delay time not as expected when tranmission of functional 
|                                           message is allowed
| 2008-07-10 3.01.00 Vissf   ESCAN00028169: No changes
|                            ESCAN00028168: No changes
|                            ESCAN00028358: Start Delay Time support 
| 2008-09-17 3.01.01 Vissf   ESCAN00030088: No changes
| 2008-11-11 3.02.00 Vissf   ESCAN00031077: No changes
| 2008-12-09 3.02.01 Vissf   ESCAN00032161: Support of internal NM state <Sleep_BSI_FRAME>
|                            ESCAN00032166: Support Supervision callback on every state change ( unfiltered callback )
| 2009-08-14 3.02.02 vismas  ESCAN00034544: No changes in this file
| 2011-07-27 3.03.00 vismpf  ESCAN00052368: No changes in this file
|                            ESCAN00052473: Removed declaration of SmStart()
|                            ESCAN00052549: Corrected/justified findings of static analysis tools
| 2013-11-05 3.03.01 vismdr  ESCAN00071596: No changes in this file
|******************************************************************************/

/* common CAN header part *****************************************************/
#ifndef STAT_MGR_H
#define STAT_MGR_H

#include "can_inc.h"
#include "can_par.h"
#include "StMgrLs_cfg.h"
#include "StMgrLs_par.h"
#include "Inm_Osek.h"
#if defined( VGEN_ENABLE_IL_VECTOR )
#include "il_inc.h"
#endif

/******************************************************************************/
/* Version                  (abcd: Main version ab Sub Version cd )           */
/******************************************************************************/
extern vuint8 MEMORY_ROM kStatMgrMainVersion;
extern vuint8 MEMORY_ROM kStatMgrSubVersion;
extern vuint8 MEMORY_ROM kStatMgrBugFixVersion;

/* ##V_CFG_MANAGEMENT ##CQProject : Nm_StMgrIndOsek_Ls CQComponent : Implementation */ 
#define NM_STMGRINDOSEK_LS_VERSION          0x0303
#define NM_STMGRINDOSEK_LS_RELEASE_VERSION  0x01

/******************************************************************************/
/* Global definitions                                                         */
/******************************************************************************/
/*--- ECU-specific functionalities ------------------------------------------*/
#if defined ( ECU_TYPE_PSA_1 ) || defined ( ECU_TYPE_PSA_2 ) || defined ( ECU_TYPE_PSA_4 )
  /* The selected ECU type is capable to initiate a network activation */
#define SM_ECU_TYPE_ACTIVATION
#endif

#if defined ( ECU_TYPE_PSA_1 ) || defined ( ECU_TYPE_PSA_2 ) || defined ( ECU_TYPE_PSA_3 )
  /* The selected ECU type uses the CanPlus (+CAN) */
  #define SM_ECU_TYPE_CANPLUS
#endif

/* for network information "Phase vie reseau" */
#define kSmVeille        0x00u /* VEILLE / SLEEP */
#define kSmModeNormal    0x01u /* MODE NORMAL */
#define kSmMiseEnVeille  0x02u /* MISE EN VEILLE / GOTO SLEEP */
#define kSmReveil        0x03u /* REVEIL / WAKE UP */
#define kSmComOff        0x04u /* COM OFF */
#define kSmPerteCom      0x08u /* PerteCom / LIMP HOME */

#if defined( SM_ENABLE_EXTENDED_STATES )
/* if organtype 3 internal  status <SLEEP_BSI_FRAME> is maintained */
#define kSmExtSleepBSIFrame  0x09u /* extended Status Sleep_bsi_frame (organtyp 3 ) */
#endif

/* Mask for the Phases de vie */
#define kSmPhases        0x0fu
/* for diagnostic information "DEC" and "DIAG ON" */
#define kSmDiagOn        0x20u /* "DIAG ON" */

#define kSmBoffIndication  0x80u

#define kSmStateAppl    kSmModeNormal  

/* set PowerOn and Start states */
#define kSmPowerOn  kSmVeille
#define kSmStart    kSmReveil

/* Tveille 15s = 15000ms */
#define kSmTveille 15000u
/* Toff 1s = 1000ms */
#define kSmToff 1000u
/* WakeUp time 1s */
#define kSmTWakeUp 1000u

#define kSmRequestOk     0 
#define kSmRequestFailed 1
#define kSmPlusCanActive 1
#define kSmPlusCanDeactive 0

/* error codes for station manager assertions */
#define kWrongBsiAbsentInfo         0x01
#define kWrongEcuAbsentInfo         0x02
#define kRxToCntrOutOfRange         0x03
#define kTxHandleOutOfRange         0x04
#define kIllegalTxToState           0x05
#define kIllegalNetworkState        0x06
#define kInmMsgTimeOutOfRange       0x07
#define kBusOffRecTimeOutOfRange    0x08
#define kWakeUpMsgTimeOutOfRange    0x09
#define kWrongRxToIndex             0x0A
#define kWrongTxToMsgHnd            0x0B
#define kIllegalSetWakeUpReq        0x0C
#define kIllegalClearWakeUpReq      0x0D
#define kWrongStartIlChannel        0x0E
#define kWrongStopIlChannel         0x0F
#define kWrongIndRxIndex            0x10
#define kWrongIndTxChannel          0x11
#define kWrongIndBusOffChannel      0x12
#define kWrongGetNVMuteChannel      0x13
#define kWrongGetNVAbsentChannel    0x14
#define kWrongGetNVBusOffChannel    0x15
#define kWrongSetNVMuteChannel      0x16
#define kWrongSetNVAbsentChannel    0x17
#define kWrongSetNVBusOffChannel    0x18
#define kWrongInitBusOffChannel     0x19
#define kWrongGetAbsInfIndex        0x20
#define kWrongSetAbsInfIndex        0x21
#define kWrongInitVolCtrsChannel    0x22

#define kSmDiagMuxMask              0x20
#define kSmDiagMuxEnable            0x20
#define kSmDiagMuxDisable           0x00

#define kSmModeMask                 (vuint8)0x07
/* Can driver API */
#if (SM_CHANNELS == 1 )
#  define SM_CHANNEL_TYPE_ONLY        void  /* PRQA S 3460 */ /* MD_CBD_19.4 */
#  define SM_CHANNEL_TYPE_FIRST
#  define SM_CHANNEL_PARA_ONLY
#  define SM_CHANNEL_PARA_FIRST
#  define sm_channel 0
# else
#  define SM_CHANNEL_TYPE_ONLY        inmNmChannelType  sm_channel
#  define SM_CHANNEL_TYPE_FIRST       inmNmChannelType  sm_channel,
#  define SM_CHANNEL_PARA_ONLY        sm_channel
#  define SM_CHANNEL_PARA_FIRST       sm_channel,
# endif


#if (SM_CHANNELS > 1)
#  define SM_ENABLE_INDEXED_NM
#else
#  define SM_DISABLE_INDEXED_NM
#endif

#if (kCanNumberOfChannels == 1)
#  define SM_CAN_CHANNEL_TYPE_ONLY          void  /* PRQA S 3460 */ /* MD_CBD_19.4 */
#  define SM_CAN_CHANNEL_TYPE_FIRST
#  define SM_CAN_CHANNEL_PARA_ONLY
#  define SM_CAN_CHANNEL_PARA_FIRST
#  define can_channel   0
# else
#  define SM_CAN_CHANNEL_TYPE_ONLY        CanChannelHandle can_channel
#  define SM_CAN_CHANNEL_TYPE_FIRST       CanChannelHandle can_channel,
#  define SM_CAN_CHANNEL_PARA_ONLY        can_channel
#  define SM_CAN_CHANNEL_PARA_FIRST       can_channel,
# endif



/* SM state */
#define SM_IS_STOPPED 0x0u
#define SM_IS_STARTED 0x1u


/******************************************************************************/
/* Global    data                                                      */
/******************************************************************************/

extern vuint8 MEMORY_NORMAL bSmCBusOff[SM_CHANNELS];
/*
* Description        : Volatile BusOff Counter
* Access rights      : rw
* Val. range / Coding: 0..255                            
*/

extern vuint8 MEMORY_NORMAL bSmCPerteCom[SM_CHANNELS];
/*
* Description        : Volatile PerteCom Counter
* Access rights      : rw
* Val. range / Coding: 0..255                            
*/

#if defined ( SM_ECU_TYPE_CANPLUS )
extern vuint8 MEMORY_NORMAL bSmCanPlusState[SM_CHANNELS];
/*
* Description        : State of Plus CAN pin
* Access rights      : rw
* Val. range / Coding: 0..1                            
*/
#endif





/******************************************************************************/
/* Generated data                                                      */
/******************************************************************************/
#if defined (SM_ENABLE_MULTIPLE_NODES)
extern V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 SmIndirection[kSmNumberOfNodes][kCanNumberOfRxObjects];
#else
extern V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 SmIndirection[kCanNumberOfRxObjects];
#endif
#if (C_VERSION_REF_IMPLEMENTATION < 0x150u)
extern V_MEMROM0 vuint8 MEMORY_ROM SmCanRxMinMsgLen[kCanNumberOfRxObjects];
#endif

/* station manager */
extern V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 SmRxTimeoutValue[SM_NUMOFALLRXNODES];
extern V_MEMROM0 V_MEMROM1 CanChannelHandle V_MEMROM2 SmSmToCanChannel[SM_CHANNELS];
extern V_MEMROM0 V_MEMROM1 CanChannelHandle V_MEMROM2 SmCanToSmChannel[kCanNumberOfChannels];

#if defined ( SM_ENABLE_DYNAMIC_TX )
extern vuint16 MEMORY_NORMAL bSmInmMsgTime[SM_CHANNELS];
#else
extern V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 SmMsgTime[SM_CHANNELS * kVNumberOfIdentities];
/*
* Description        : Array to store cycl. time of transmit message
* Access rights      : r/w
* Val. range / Coding: 0..0xFFFF
*/
#endif

extern V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 SmMsgTimeoutTime[SM_CHANNELS];
extern V_MEMROM0 V_MEMROM1 inmNmChannelType V_MEMROM2 InmIndexToChannel[kInmNumberOfRxMessages];
extern V_MEMROM0 V_MEMROM1 CanTransmitHandle V_MEMROM2 SmTxHdlVersionMsg[SM_CHANNELS * kVNumberOfIdentities];
extern V_MEMROM0 V_MEMROM1 CanTransmitHandle V_MEMROM2 SmRxHdlNmCmdMsg[SM_CHANNELS * kVNumberOfIdentities];
/*
* Description        : Mapping table ECUindex -> channel
* Access rights      : r
* Val. range / Coding: 0..255                            
*/

# if defined (SM_ENABLE_TRANSMISSION_HANDLING)
/* ESCAN00028358 Start Delay Time support */
extern V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 bSmInmMsgDelayTime[SM_CHANNELS];

#  if defined ( SM_ENABLE_DYNAMIC_TX )
extern CanTransmitHandle MEMORY_NORMAL bSmInmMsgHandle[SM_CHANNELS];
#  else 
extern V_MEMROM0 V_MEMROM1 CanTransmitHandle V_MEMROM2 SmMsgHandle[SM_CHANNELS * kVNumberOfIdentities];
/*
* Description        : Array to store transmit handle of supervised tx message
* Access rights      : r/w
* Val. range / Coding: 0..255
*/
#  endif
# endif /* SM_ENABLE_TRANSMISSION_HANDLING */

/******************************************************************************/
/* macros                                                                     */
/******************************************************************************/

/* Get and set volatile counters */

#if ( SM_CHANNELS > 1 )
# define SmGetVolCBoff(c)       (bSmCBusOff[(c)])
# define SmSetVolCBoff(c, s)    (bSmCBusOff[(c)] = (s))  /* PRQA S 3453 */ /* MD_StMgr_3453 */
# define SmGetVolCPerteCom(c)   (bSmCPerteCom[(c)]) 
# define SmSetVolCPerteCom(c, s)(bSmCPerteCom[(c)] = (s))  /* PRQA S 3453 */ /* MD_StMgr_3453 */
# define SmGetVolCNerr(c)       (InmNmGetGenericCondition(c)->counter)
# define SmSetVolCNerr(c, s)    (InmNmGetGenericCondition(c)->counter = (s))  /* PRQA S 3453 */ /* MD_StMgr_3453 */
# define SmGetVolCMute(c)       (InmNmGetTxCondition(c)->counter)
# define SmSetVolCMute(c, s)    (InmNmGetTxCondition(c)->counter = (s))  /* PRQA S 3453 */ /* MD_StMgr_3453 */
#else
# define SmGetVolCBoff()        (bSmCBusOff[0])
# define SmSetVolCBoff(s)       (bSmCBusOff[0] = (s))  /* PRQA S 3453 */ /* MD_StMgr_3453 */
# define SmGetVolCPerteCom()    (bSmCPerteCom[0])
# define SmSetVolCPerteCom(s)   (bSmCPerteCom[0] = (s))  /* PRQA S 3453 */ /* MD_StMgr_3453 */
# define SmGetVolCNerr()        (InmNmGetGenericCondition()->counter)
# define SmSetVolCNerr(s)       (InmNmGetGenericCondition()->counter = (s))  /* PRQA S 3453 */ /* MD_StMgr_3453 */
# define SmGetVolCMute()        (InmNmGetTxCondition()->counter)
# define SmSetVolCMute(s)       (InmNmGetTxCondition()->counter = (s))  /* PRQA S 3453 */ /* MD_StMgr_3453 */
#endif

# define SmGetVolCRx(c)         (InmNmGetRxCondition(c)->counter)  /* PRQA S 3453 */ /* MD_StMgr_3453 */
# define SmSetVolCRx(c,s)       (InmNmGetRxCondition(c)->counter = (s))  /* PRQA S 3453 */ /* MD_StMgr_3453 */

#if defined (SM_ENABLE_MULTIPLE_NODES)
   #define SmIdentity(ch) ((vActiveIdentityLog * SM_CHANNELS) + (ch))  /* PRQA S 3453 */ /* MD_StMgr_3453 */
#else
   #define SmIdentity(ch) (ch)  /* PRQA S 3453 */ /* MD_StMgr_3453 */
#endif

/******************************************************************************/
/* Function prototypes                                                        */
/******************************************************************************/

/* service functions **********************************************************/

#if defined ( SM_ECU_TYPE_CANPLUS )
extern void SmSetPlusCanState(SM_CHANNEL_TYPE_FIRST vuint8 state );
#endif

#if defined ( SM_ECU_TYPE_ACTIVATION )
vuint8 SmNetworkRequestAllowed(SM_CHANNEL_TYPE_ONLY);
vuint8 SmSetNetworkRequest(SM_CHANNEL_TYPE_ONLY);
void SmReleaseNetworkRequest(SM_CHANNEL_TYPE_ONLY);
void SmSetWakeUpRequest(SM_CHANNEL_TYPE_ONLY);
#endif

extern void SmTask(SM_CHANNEL_TYPE_ONLY);
extern void SmInitPowerOn(void);

extern vuint8 SmGetStatus(SM_CHANNEL_TYPE_ONLY);

/* ESCAN00022994: changed SmTransmitNmMessage from macro to function */
#if defined ( SM_ENABLE_TRANSMISSION_HANDLING )
extern void SmTransmitNmMessage(SM_CHANNEL_TYPE_ONLY);
# endif /* SM_ENABLE_TRANSMISSION_HANDLING */

extern void SmResetSupervision(SM_CHANNEL_TYPE_ONLY);

#if defined( SM_ENABLE_EXTENDED_STATES )
extern vuint8 SmGetExtendedStatus(SM_CHANNEL_TYPE_ONLY);
#endif

/* API that is called by the CAN driver ***************************************/
#if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) || defined ( C_SINGLE_RECEIVE_CHANNEL )
extern void SmPrecopy( CanRxInfoStructPtr rxStruct );
#endif

/* callback functions *********************************************************/
extern void ApplSmTrcvOn(SM_CHANNEL_TYPE_ONLY);
extern void ApplSmTrcvOff(SM_CHANNEL_TYPE_ONLY);

#if defined (SM_ENABLE_MULTIPLE_NODES )
extern vuint8 ApplSmGetDiagState0(vuint8 rcvObject);
extern vuint8 ApplSmGetDiagState1(vuint8 rcvObject);
extern vuint8 ApplSmGetMasterIndex(void);
#endif
#if defined ( SM_ECU_TYPE_ACTIVATION )
extern void ApplSmNetRequestRelease(SM_CHANNEL_TYPE_ONLY);
#endif 

extern vuint8 ApplSmGetInterdMemoDef(SM_CHANNEL_TYPE_ONLY );

#if defined( SM_ENABLE_SOFTWARE_CHECK )
 extern void ApplSmFatalError (SM_CHANNEL_TYPE_FIRST vuint8);
#endif

#if defined( SM_ENABLE_TRANSITION_CB )
 extern void ApplSmStatusIndication (SM_CHANNEL_TYPE_FIRST vuint8 state);
#endif
 
#if defined(SM_ENABLE_BUSOFF_FCT )
 extern void ApplNwmBusoff (SM_CHANNEL_TYPE_ONLY );
#endif
#if defined(SM_ENABLE_BUSOFF_END_FCT )
 extern void ApplNwmBusoffEnd (SM_CHANNEL_TYPE_ONLY);
#endif


 extern vuint8 ApplCanErrorPin (SM_CHANNEL_TYPE_ONLY);


# if defined( SM_ENABLE_STATUS_CB )
 extern void ApplSmStatusIndicationRx (inmNmIndexType index,inmNmStatusType status);
 extern void ApplSmStatusIndicationTx (SM_CHANNEL_TYPE_FIRST inmNmStatusType status);
 extern void ApplSmStatusIndicationNerr (SM_CHANNEL_TYPE_FIRST inmNmStatusType status);
# endif /* #if defined( SM_ENABLE_STATUS_CB ) */


# if defined( SM_ENABLE_FAULTSTOR )
 extern inmNmCounterType ApplSmGetNVAbsentCount(inmNmIndexType index);
 extern inmNmCounterType ApplSmGetNVMuteCount(SM_CHANNEL_TYPE_ONLY);
 extern inmNmCounterType ApplSmGetNVNerrCount(SM_CHANNEL_TYPE_ONLY);

 extern void ApplSmSetNVAbsentCount(inmNmIndexType index,inmNmCounterType value);
 extern void ApplSmSetNVMuteCount(SM_CHANNEL_TYPE_FIRST inmNmCounterType value);
 extern void ApplSmSetNVNerrCount(SM_CHANNEL_TYPE_FIRST inmNmCounterType value);
# endif 

#endif /* #ifndef STAT_MGR_H */
