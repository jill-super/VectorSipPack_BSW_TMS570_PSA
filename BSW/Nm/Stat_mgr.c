
/* STARTSINGLE_OF_MULTIPLE */

/*******************************************************************************
|      Project Name: S T A T I O N - M A N A G E R   F O R   P S A  
|         File Name: Stat_Mgr.c
|
|       Description: Implementation of station manager for PSA
|                    Low Speed Fault Tolerant Bus 
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
| vissrk       Markus Schuster           Vector Informatik GmbH
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
|                            ESCAN00006191: PSA: Unspecified value of phase_vie signal shall be taken as state "normal"
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
| 2006-11-23 2.01.00 Sf      ESCAN00017932: No transmission of WakeUp message
|                            ESCAN00018441: optimize access to Non volatile memory 
|                            ESCAN00018488: Avoid calling of SmNetworkTask() in interrupt context
|                            ESCAN00018489: Keep DiagMuxOn state unchanged until BSI is declared confirmed absent
| 2007-01-15 2.02.00 Sf      ESCAN00018899: Compiler error if CCL is used and organtype is 3 
| 2007-03-13 2.03.00 Sf      ESCAN00019905: Journal de Defaut not blocked in ECU state ComOff
| 2007-06-19 2.04.00 Sf      ESCAN00021034: CAN driver assertion called after BusOff recovery
|                            ESCAN00021113: Add support for dynamic tx supervision
| 2007-09_18 2.04.01 Sf      ESCAN00022377: BusOff recovery algorithm not correct
|                            ESCAN00022378: No transmission of the Version message
| 2007-10_31 2.05.00 Sf      ESCAN00022994: Minimum send delay violated in case of a event message
|                            ESCAN00022997: BSI is reported <Confirmed Present> too fast
| 2007-12_12 3.00.00 Sf      --- Rework PSA SLP4
| 2008-03-11 3.00.01 Sf      ESCAN00024956: N_as counter incremented while active WakeUp
|                            ESCAN00025172: no changes 
|                            ESCAN00025170: New API to reset the supervision on diagnostic request
|                            ESCAN00025407: ECU may reset   
| 2008-04-07 3.00.02 Vissf   ESCAN00025681: Missing State transition to COM Off
|                            ESCAN00025767: N_as timeout detected too early
|                            ESCAN00025824: N_as counter don't increase value of 254
| 2008-05-15 3.00.03 Vissf   ESCAN00026898: Start-Delay time not as expected when tranmission of
|                                           functional message is allowed
| 2008-07-10 3.01.00 Vissf   ESCAN00028169: Restart Start-Delay timer only if transmission of frames
|                                           wasn't allowed before
|                            ESCAN00028168: Support state <Sleep_BSI_Frame> for organ type 3
|                            ESCAN00028358: Start Delay Time support 
| 2008-09-17 3.01.01 Vissf   ESCAN00030088: Change of DiagMuxOn information of BSI takes effect in 
|                                           task cycle after reception the new state
| 2008-11-11 3.02.00 Vissf   ESCAN00031077: Implicit handling of DiagMuxOn signal in state
|                                           "Mis_En_Veille" and "Com_Off" removed
| 2008-12-09 3.02.01 Vissf   ESCAN00032161: Support of internal NM state <Sleep_BSI_FRAME>
|                            ESCAN00032166: Support Supervision callback on every state change ( unfiltered callback )
| 2009-08-14 3.02.02 vismas  ESCAN00034544: Changed interrupt lock mechanism in task
| 2011-07-27 3.03.00 vismpf  ESCAN00052368: Support updated specification "phases de vie CAN" 96 649 896 99
|                                           by adding transition from state WakeUp to ComOff
|                            ESCAN00052473: No changes in this file
|                            ESCAN00052549: Corrected/justified findings of static analysis tools
| 2013-11-05 3.03.01 vismdr  ESCAN00071596: added channel indirection for SmWakeUpTask
|******************************************************************************/


/*******************************************************************************
* Include Files
*******************************************************************************/
#include "Stat_Mgr.h"
#if defined (SM_ENABLE_SOFTWARE_CHECK) 
/* lint -e661
  2008-01-25, vismas: 
  When assertions are active, PClint reports a variety of possible out-of-bounds.
  This warning is suppressed to focus on the relevant warnings. 
*/
#endif

/*******************************************************************************
* Version Check
*******************************************************************************/
#if ( NM_STMGRINDOSEK_LS_VERSION  != 0x0303)
 #error "STAT_MGR.C and STAT_MGR.H used in different versions, please check!"
#endif
#if( NM_STMGRINDOSEK_LS_RELEASE_VERSION != 0x01)
  #error "Different versions of Bugfix in Header and Source used!"
#endif

MEMORY_ROM vuint8 kStatMgrMainVersion   = (vuint8)( (NM_STMGRINDOSEK_LS_VERSION >> 8) );
MEMORY_ROM vuint8 kStatMgrSubVersion    = (vuint8)(  NM_STMGRINDOSEK_LS_VERSION &0xFF );
MEMORY_ROM vuint8 kStatMgrBugFixVersion = (vuint8)( NM_STMGRINDOSEK_LS_RELEASE_VERSION );

/******************************************************************************/
/* Common constants and defines                                               */
/******************************************************************************/
/* defines for restarting the delay time */
#define kSmSendNotAllowed 0
#define kSmSendAllowed 1

/*--- PSA specific setting of INM -------------------------------------------*/
#if defined (INM_ENABLE_INIT_ON_DIAG_ON)
#error "Please enable Init on Diag On in the INM configuration panel!"    
#else
#endif

#if defined (SM_ENABLE_NAS_SUPERVISION )
/* --- Check cycletime if N_as supervision is active ---*/
# if ( kSmTaskCycle > 5 )
#  error "Supervision of the N_as counter requires SM task cycle time less or equal 5ms!"
# endif
# if defined (SM_ENABLE_MULTIPLE_NODES)
#  error "Supervision of the N_as counter not possible for Multiple ECU configurations!" 
# endif
# if (SM_CHANNELS > 1 )
#  error "Supervision of the N_as counter only possible for single channel systems!"
# endif
#endif

#if defined (SM_ENABLE_ADDITIONAL_SUPERVISION)
# if defined ( ECU_TYPE_PSA_4 )
#else
#   error "Additional Supervision is only possible for Organ-Type4 Ecu!"
# endif
#endif

/* check if transmission shall not start on state change */
/* checks if part_offline is active */
#if defined( C_ENABLE_PART_OFFLINE )
#else
 #error "Part Offline functionality not enabled! Please enable in CAN Driver page"
#endif

/* checks for valid static configuration of station manager *******************/
#if defined( C_SEND_GRP_NONE )
#else
 #error "No send mask for message type 'NONE' is defined"
#endif

#if defined( C_SEND_GRP_WAKEUP )
#else
 #error "No send mask for message type 'WAKEUP' is defined"
#endif

#if defined( C_SEND_GRP_FUNCTIONAL )
#else
 #error "No send mask for message type 'FUNCTIONAL' is defined"
#endif

#if defined( C_SEND_GRP_DIAG )
#else
 #error "No send mask for message type 'DIAG' is defined"
#endif

#if defined( C_SEND_GRP_JDD )
#else
 #error "No send mask for message type 'JDD' is defined"
#endif
/* Defines ********************************************************************/


/******************************************************************************/
/* Specific constants and defines                                             */
/******************************************************************************/

/* checks for valid static configuration of station manager *******************/
#if defined( SM_NUMOFALLRXNODES )
 #if ( SM_NUMOFALLRXNODES == 0 )
  #error "no ECU Rx timeout supervision is activated"
 #endif
#else
 #error "define 'SM_NUMOFALLRXNODES' is not available"
#endif


/* check for valid ECU Type */
#if defined (ECU_TYPE_PSA_0 )
  #error "No sleep management ECU Type not supported!"   
#endif
#if defined ( ECU_TYPE_PSA_4 ) || defined ( ECU_TYPE_PSA_3 ) || defined ( ECU_TYPE_PSA_2 ) || defined ( ECU_TYPE_PSA_1 )
#else
  #error "No ECU Type configured! Please configure a ECU Type!" 
#endif

#define SM_FAST_BUS_OFF_REC_COUNT 3
#define SM_SLOW_REC_TIME (1000/kSmTaskCycle)
#define SM_RECOVERY_TIMER (1000/kSmTaskCycle)

#if defined (SM_ENABLE_NAS_SUPERVISION)

/* ESCAN00025767 (change) 
*  16ms is taken due to div operation 
*  16 / 5 = 3  Min: 3x5 = 15ms; max: 4x5 = 20ms 
*  16 / 4 = 4  Min: 4x4 = 16ms; max: 5x4 = 20ms
*  16 / 3 = 5  Min: 5x3 = 15ms; max: 6x3 = 18ms
*  16 / 2 = 8  Min: 8x2 = 16ms; max: 9x2 = 18ms
*/
#define SM_NAS_TIME ( (16 / kSmTaskCycle) + 1 )
#endif

/* Macros *********************************************************************/

#if defined (SM_ENABLE_MULTIPLE_NODES)
 #define SmGetECUindex(s) (SmIndirection[comMultipleECUCurrent][(s)])  /* PRQA S 3453 */ /* MD_StMgr_3453 */
#else
 #define SmGetECUindex(s) (SmIndirection[(s)])  /* PRQA S 3453 */ /* MD_StMgr_3453 */
#endif

#define  SmMasterIndex(ch)   ( SmGetECUindex( SmRxHdlNmCmdMsg[SmIdentity(ch)]))  /* PRQA S 3453 */ /* MD_StMgr_3453 */

/* get current internal state */
#define SmGetIntState(c)           (bSmIntState[(c)])  /* PRQA S 3453 */ /* MD_StMgr_3453 */
#define SmGetIntPhaseState(c)      (bSmIntState[(c)] & kSmPhases)  /* PRQA S 3453 */ /* MD_StMgr_3453 */

/* get requested external MASTER (phase) state */
#define SmGetExtState(c)           (bSmExtState[(c)] )  /* PRQA S 3453 */ /* MD_StMgr_3453 */
#define SmGetExtPhaseState(c)      (bSmExtState[(c)] & kSmPhases )  /* PRQA S 3453 */ /* MD_StMgr_3453 */


/* set current internal state */
#if defined(SM_ENABLE_TRANSITION_CB)
# if defined (SM_ENABLE_EXTENDED_STATES)
/* ESCAN00032161 */
#define SmSetIntECUState(c, s)      bSmIntState[(c)] = (vuint8)(bSmIntState[(c)] & ~kSmPhases); \
                                    bSmIntState[(c)] = (vuint8)(bSmIntState[(c)] | (s) ); \
                                    bSmIntStateExtended[(c)] = 0; \
                                    ApplSmStatusIndication( SM_CHANNEL_PARA_FIRST ((vuint8)((s) & kSmPhases)) )
# else
#define SmSetIntECUState(c, s)      bSmIntState[(c)] = (vuint8)(bSmIntState[(c)] & ~kSmPhases); \
                                    bSmIntState[(c)] = (vuint8)(bSmIntState[(c)] | (s) ); \
                                    ApplSmStatusIndication( SM_CHANNEL_PARA_FIRST ((vuint8)((s) & kSmPhases)) )
# endif 
#else  /* SM_ENABLE_TRANSITION_CB */
# if defined (SM_ENABLE_EXTENDED_STATES)
    /* ESCAN00032161 */
    #define SmSetIntECUState(c, s)  bSmIntState[(c)] = (vuint8)(bSmIntState[(c)] & ~kSmPhases); \
                                    bSmIntStateExtended[(c)] = 0; \
                                    bSmIntState[(c)] = (vuint8)(bSmIntState[(c)] | (s))
# else
    #define SmSetIntECUState(c, s)  bSmIntState[(c)] = (vuint8)(bSmIntState[(c)] & ~kSmPhases); \
                                    bSmIntState[(c)] = (vuint8)(bSmIntState[(c)] | (s))
# endif
#endif

#define SmSetIntState(c, s)        (bSmIntState[(c)] = (s))  /* PRQA S 3453 */ /* MD_StMgr_3453 */

/* set requested external MASTER (phase) state */
#define SmSetExtState(c, s)        (bSmExtState[(c)] = (s))  /* PRQA S 3453 */ /* MD_StMgr_3453 */
#define SmSetExtECUState(c, s)      bSmExtState[(c)] = (vuint8)(bSmExtState[(c)] & ~kSmPhases); \
                                    bSmExtState[(c)] = (vuint8)(bSmExtState[(c)] | (s) )


/* set requested external Diag state  */
#define SmSetExtDiagState(c, s)     bSmExtState[(c)] = (vuint8)(bSmExtState[(c)] & ~kSmDiagOn); \
                                    bSmExtState[(c)] = (vuint8)(bSmExtState[(c)] | (vuint8)((s)<<5) )


#if defined (SM_ENABLE_SOFTWARE_CHECK)
  /* debug mode for station manager is enabled */
  #define SmAssert(p, e)     if(!(p)){ApplSmFatalError(e);}
  #define SmAssertAlways(e)  ApplSmFatalError(e);
#else
  /* debug mode for station manager is disabled */
  #define SmAssert(a, b)
  #define SmAssertAlways(a)
#endif


#define C_SEND_GRP_STAT_MGR  ((vuint8) (C_SEND_GRP_WAKEUP|C_SEND_GRP_FUNCTIONAL|C_SEND_GRP_DIAG|C_SEND_GRP_JDD))


/* access Macro to DiagMux signal */
#define NmSmLsGetDiagMuxFromNmCmdMsg()  (rxStruct->pChipData[4] & kSmDiagMuxMask)
/* access Macro to Phase_de_vie signal */
#define NmSmLsGetModeFromNmCmdMsg()     (rxStruct->pChipData[4] & kSmModeMask)

#define kNmSmLsNmInitObj                0
/***************************************************************************/
/* external declarations                                                    */
/***************************************************************************/

#if defined SM_ENABLE_ADDITIONAL_SUPERVISION
extern V_MEMROM0 V_MEMROM1 CanReceiveHandle V_MEMROM2 SmAddRxHandle[SM_CHANNELS];
extern V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 SmAddRxTimeout[SM_CHANNELS];
#endif

/******************************************************************************/
/* Data Types / Structs / Unions                                              */
/******************************************************************************/

/******************************************************************************/
/* Intern and global data definitions                                         */
/******************************************************************************/

vuint8 MEMORY_NORMAL bSmCPerteCom[SM_CHANNELS];
/*
* Description        : volatile counter of PerteCom 
* Access rights      : r/w
* Val. range / Coding: Ring counter 
*/

vuint8 MEMORY_NORMAL bSmCBusOff[SM_CHANNELS];
/*
* Description        : volatile counter of  Bus off
* Access rights      : r/w
* Val. range / Coding: Ring counter 
*/


static vuint8 MEMORY_NORMAL bSmExtState [SM_CHANNELS];
/*
* Description        : requested external MASTER state for organ type handling
* Access rights      : r/w
* Val. range / Coding: PSA                         
*                      kSmVeille (0x00),           
*                      kSmModeNormal (0x01),        
*                      kSmMiseEnVeille (0x02),     
*                      kSmReveil (0x03),           
*                      kSmComOff (0x04),           
*                      kSmDec (0x10),              
*                      kSmDiagOn (0x20)            
*/

static vuint8 MEMORY_NORMAL bSmIntState[SM_CHANNELS];
/*
* Description        : current internal SLAVE state for organ type handling
* Access rights      : r/w
* Val. range / Coding: PSA                         
*                      kSmVeille (0x00),           
*                      kSmModeNormal (0x01),        
*                      kSmMiseEnVeille (0x02),     
*                      kSmReveil (0x03),           
*                      kSmComOff (0x04),           
*                      kSmPerteCom (0x08),
*                      kSmDec (0x10),              
*                      kSmDiagOn (0x20)            
*/

#if defined (SM_ENABLE_EXTENDED_STATES )
/* ESCAN00032161 */
static vuint8 MEMORY_NORMAL bSmIntStateExtended[SM_CHANNELS];
/*
* Description        : internal SLAVE state for organ type 3 
* Access rights      : r/w
* Val. range / Coding:  0x0, 0x1
*/
#endif

static canuint8 MEMORY_NORMAL bSmNerrPinState[SM_CHANNELS];
/*
* Description        : state of the Nerr Pin of the transceiver
* Access rights      : r/w
* Val. range / Coding: 0 not set, 1 set
*/

static vuint8 MEMORY_NORMAL bSmConfPerteCom[SM_CHANNELS];
/*
* Description        : Flag if Confirmed Perte Com
* Access rights      : r/w
* Val. range / Coding: 0,1 
*/

static vuint8 baSmRxIndicationFlags[SM_NUMOFALLRXNODES];
/*
* Description        : array to store if message was received during last cycletime 
* Access rights      : r/w
* Val. range / Coding: 0: not received; 1: received        
*/


static vuint16 MEMORY_NORMAL wSmRxToCycCntr[SM_NUMOFALLRXNODES];
/*
* Description        : Rx timeout counter of each supervised Rx node
* Access rights      : r/w
* Val. range / Coding: 0 .. SmRxTimeoutValue [kEcuNr]
*/

static vuint16 MEMORY_NORMAL wSmTxToCycCntr[SM_CHANNELS];
/*
* Description        : Tx timeout counter of own supervised Tx node
* Access rights      : r/w
* Val. range / Coding: 0 .. 
*/



static vuint16 MEMORY_NORMAL wSmInmMsgCycCntr [SM_CHANNELS];
/*
* Description        : time distance between indirect OSEK network management messages
* Access rights      : r/w
* Val. range / Coding: 0 .. (kSmInmMsgTime /kSmTaskCyc )
*/


static vuint8 MEMORY_NORMAL bSmCmdBSIReceived[SM_CHANNELS];
/*
* Description        : Flag Commande_BSI was received after BusOff
* Access rights      : r/w
* Val. range / Coding: 0-> not received; 1-> received;
*/


static vuint16 MEMORY_NORMAL bSmBusOffCycCntr[SM_CHANNELS];
/*
* Description        : minimum time distance between repeated BusOff recoveries 
* Access rights      : r/w
* Val. range / Coding: kSmFastBusOffRecTime,
*                      kSmSlowBusOffRecTime
*/

static vuint16 MEMORY_NORMAL bSmBusOffOnlineCntr[SM_CHANNELS];
/*
* Description        : Timer to check if Bus Off recovery algorithm can be reset
*                      If after enabling the transmission for 1 second no BusOff occurs
*                      algorithm is reset    
* Access rights      : r/w
* Val. range / Coding: 1000ms /cycle time 
*/

static vuint8 MEMORY_NORMAL bSmBusOffRecCntr[SM_CHANNELS];
/*
* Description        : count of repeated BusOff recoveries (without successful Tx or Rx)
* Access rights      : r/w
* Val. range / Coding: kSmFastBusOffRecCnt,
*                      kSmMediumBusOffRecCnt,
*                      kSmSlowBusOffRecCnt
*/

#if defined SM_ENABLE_TRANSMISSION_HANDLING
static vuint16 MEMORY_NORMAL wSmTxDelayCntr[SM_CHANNELS];
/* ESCAN00022994: changed SmTransmitNmMessage from macro to function */
static vuint8 MEMORY_NORMAL bSmTxEventTrigger[SM_CHANNELS];
#else
#endif

#if defined ( SM_ECU_TYPE_ACTIVATION )

static vuint16 MEMORY_NORMAL wSmToffCntr[SM_CHANNELS];    
/*
* Description        : Toff timeout counter for PSA 
* Access rights      : r/w
* Val. range / Coding: 0 .. 0xff
*/

static vuint16 MEMORY_NORMAL wSmTveilleCntr[SM_CHANNELS];    
/*
* Description        : Tveille timeout counter for PSA Organ type 1,2 or 4
* Access rights      : r/w
* Val. range / Coding: 0 .. 0xff
*/
static vuint8 bSmCwakeUpCntr[SM_CHANNELS];
/*
* Description        : counter for max. value of active wake ups (3)
* Access rights      : r/w
* Val. range / Coding: 0 .. 0x3
*/

static vuint16 wSmTwakeUpCntr[SM_CHANNELS];
/*
* Description        : Timeout counter for WakeUp request by application
* Access rights      : r/w
* Val. range / Coding: 0..max
*/

static vuint8 MEMORY_NORMAL bSmNetRequest[SM_CHANNELS];
/*
* Description        : store the appl. request
* Access rights      : r/w
* Val. range / Coding: 0..1
*/
static vuint8 MEMORY_NORMAL bSmWakeUpRequest[SM_CHANNELS];
/*
* Description        : store the appl. request
* Access rights      : r/w
* Val. range / Coding: 0..1
*/
#if defined (SM_ENABLE_NAS_SUPERVISION )
static vuint8 MEMORY_NORMAL bSmActiveWakeUp[SM_CHANNELS];
/*
* Description        : flag if active WakeUp and therefore 
*                      N_as timeoutsupervison has to be skipped
* Access rights      : r/w
* Val. range / Coding: 0..1
*/
#endif
#endif

#if defined ( SM_ECU_TYPE_CANPLUS )
vuint8 bSmCanPlusState[SM_CHANNELS];
/*
* Description        : State of Plus CAN
* Access rights      : r/w
* Val. range / Coding: 0..1
*/
# if defined ( SM_ECU_TYPE_ACTIVATION )
static vuint8 bSmLocalCanPlusState[SM_CHANNELS];
/*
* Description        : local State of Plus CAN
* Access rights      : r/w
* Val. range / Coding: 0..1
*/
# endif
#endif 

#if defined ( SM_ENABLE_DYNAMIC_TX )
#else
static vuint8 bSmTxConfirmationFlag[SM_CHANNELS];
/*
* Description        : variable to store if message was transmitted during last cycletime 
* Access rights      : r/w
* Val. range / Coding: 0: not transmitted; 1: transmitted
*/
#endif

#if defined SM_ENABLE_ADDITIONAL_SUPERVISION
static vuint8 MEMORY_NORMAL bSmAddRxInidcationFlag[SM_CHANNELS];
/*
* Description        : indication flag for additional monitored message; Type4 only 
* Access rights      : r/w
* Val. range / Coding: 0: not received; 1: received
*/
static vuint8 MEMORY_NORMAL bSmAddRxState[SM_CHANNELS];
/*
* Description        : State of additional monitored message 
* Access rights      : r/w
* Val. range / Coding: 0: absent; 1: present
*/
static vuint16 MEMORY_NORMAL bSmAddRxTCntr[SM_CHANNELS];
/*
* Description        : Timeout counter of additional monitored message 
* Access rights      : r/w
* Val. range / Coding: 0..0xFFFF
*/
#endif


#if defined (SM_ENABLE_NAS_SUPERVISION)
static vuint8 bNasTimeout[kCanNumberOfUsedTxCANObjects];
/*
* Description        : Timeout counter for N_as supervision 
* Access rights      : r/w
* Val. range / Coding: 0..0xFF
*/
static CanTransmitHandle bActHandle[kCanNumberOfUsedTxCANObjects];
/*
* Description        : handle of Tx message which is currently transmitted 
* Access rights      : r/w
* Val. range / Coding: 0..0xFF
*/
static vuint8 bNasCounter;
/*
* Description        : counter of N_as events 
* Access rights      : r/w
* Val. range / Coding: 0 .. 0xFF
*/
#endif

static vuint8 MEMORY_NORMAL bSmCurrentSendState[SM_CHANNELS];
/*
* Description          current send state
* Access rights        r/w
* Val. range / Coding: kSmSendNotAllowed 0, kSmSendAllowed 1
*/

# if defined ( ECU_TYPE_PSA_2 ) || defined ( ECU_TYPE_PSA_4 )
/* ESCAN00025681 (modify) */
/* ESCAN00052368 added transition from kSmReveil -> kSmComOff */
static vuint8 MEMORY_ROM abSmChkTransAct[9] = { 0x0, 0x14, 0x1B, 0x16, 0x02, 0x14, 0x14, 0x14, 0x1F };
/*
* Description        : Array where the possible state transitions are configured
* Access rights      : r
* index, Value         kSmVeille        (0x00), 0x01
*                      kSmModeNormal    (0x01), 0x02
*                      kSmMiseEnVeille  (0x02), 0x04
*                      kSmReveil        (0x03), 0x08
*                      kSmComOff        (0x04), 0x10
*                      invalid state    (0x05), 0x0
*                      invalid state    (0x06), 0x0
*                      invalid state    (0x07), 0x0
*                      kSmPerteCom      (0x08), 0x20
* Val. range / Coding: 0..255
*/
# else
/* ESCAN00052368 added transition from kSmReveil -> kSmComOff */
static vuint8 MEMORY_ROM abSmChkTransAct[9] = { 0x0, 0x14, 0x0B, 0x16, 0x02, 0x14, 0x14, 0x14, 0x16 };
/*
* Description        : Array where the possible state transitions are configured
* Access rights      : r
* index, Value         kSmVeille        (0x00), 0x01
*                      kSmModeNormal    (0x01), 0x02
*                      kSmMiseEnVeille  (0x02), 0x04
*                      kSmReveil        (0x03), 0x08
*                      kSmComOff        (0x04), 0x10
*                      invalid state    (0x05), 0x0
*                      invalid state    (0x06), 0x0
*                      invalid state    (0x07), 0x0
*                      kSmPerteCom      (0x08), 0x20
* Val. range / Coding: 0..255
*/
# endif 


static vuint8 MEMORY_ROM abSmChkTransNew[9] = { 0x1, 0x2, 0x4, 0x8, 0x10, 0x02, 0x02, 0x02, 0x20 };
/*
* Description        : Array where the possible state transitions are configured
* Access rights      : r
* Val. range / Coding: 0..255
*/


/******************************************************************************/
/* Local functions declarations                                                           */
/******************************************************************************/

static void SmCanNerrAccess(SM_CHANNEL_TYPE_FIRST vuint8 );
static void SmRxTimeoutSupervision (SM_CHANNEL_TYPE_FIRST inmNmIndexType bEcuNr);
static void SmTxConfirmation(SM_CHANNEL_TYPE_ONLY);
static void SmBusOffInitCan(SM_CHANNEL_TYPE_ONLY);
#if defined (SM_ECU_TYPE_ACTIVATION)
static void SmWakeUpNetwork(SM_CHANNEL_TYPE_ONLY);
#endif
#if defined SM_ENABLE_NAS_SUPERVISION
static void ApplCancelTask(void);
#endif

static void SmDiagOn (SM_CHANNEL_TYPE_ONLY);
static void SmDiagOff (SM_CHANNEL_TYPE_ONLY);
static void SmNetworkTask (SM_CHANNEL_TYPE_ONLY);
static void SmTimeoutTask (SM_CHANNEL_TYPE_ONLY);
static void SmSupervisionTask(SM_CHANNEL_TYPE_ONLY);
static void SmDiagTask (SM_CHANNEL_TYPE_ONLY);
static void SmBusOffTask (SM_CHANNEL_TYPE_ONLY);
static void SmTxTask (SM_CHANNEL_TYPE_ONLY);

static vuint8 SmGetInterdMemoDef(SM_CHANNEL_TYPE_ONLY);
static void SmWakeUpTask(SM_CHANNEL_TYPE_ONLY);
static void SmSetECUSendState(SM_CHANNEL_TYPE_FIRST vuint8 bSendState );

/******************************************************************************/
/* Local functions definitions                                                           */
/******************************************************************************/


/******************************************************************************
* NAME:               SmSetECUSendState
* CALLED BY:          Stationmanager
* Preconditions:      initialization of station manager
* PARAMETER:          channel, new send state
* RETURN VALUE:       none
* Description:        set the required part offline mode 
*******************************************************************************/
static void SmSetECUSendState(SM_CHANNEL_TYPE_FIRST vuint8 bSendState )
{
#if (kCanNumberOfChannels >1 )
    CanChannelHandle channel = SmSmToCanChannel[sm_channel];
    CanPartOffline( channel, C_SEND_GRP_STAT_MGR);
    CanPartOnline( channel, bSendState);
#else
    CanPartOffline( C_SEND_GRP_STAT_MGR );
    CanPartOnline( bSendState );
#endif

    if(( bSendState & C_SEND_GRP_FUNCTIONAL) != 0) 
    {
        /* ESCAN00028169 */
        if( bSmCurrentSendState[sm_channel] == kSmSendNotAllowed )
        {
            bSmCurrentSendState[sm_channel] = kSmSendAllowed;
#if defined( VGEN_ENABLE_IL_VECTOR )
            /* only (re)activate if IL is already running */
            if( IlIsTxRun(IlGetStatus(IL_CHANNEL_ILPARA_ONLY))!= 0 )
            {
                /* aktivate IL */
                IlTxStop(IL_CHANNEL_ILPARA_ONLY);
                IlTxStart(IL_CHANNEL_ILPARA_ONLY);     
            }
# if defined ( SM_ENABLE_DYNAMIC_TX )
                /* set indirect OSEK network management time distance counter (initially) */
                wSmInmMsgCycCntr[sm_channel]  = bSmInmMsgTime[sm_channel];                
# else
                wSmInmMsgCycCntr[sm_channel]  = SmMsgTime[SmIdentity(sm_channel)];
# endif

#else       /* NO IL */
            /* ESCAN00028358 set Start delay time for INM message */            
#  if defined ( SM_ENABLE_DYNAMIC_TX )
            wSmInmMsgCycCntr[sm_channel] = 1 + bSmInmMsgDelayTime[sm_channel];
#  else
            /* set indirect OSEK network management time distance counter (initially) */
            wSmInmMsgCycCntr[sm_channel] = 1 + bSmInmMsgDelayTime[SmIdentity(sm_channel)];
#  endif
#endif
        }
    }
    else
    {
        /*ESCAN00028169 clear send allowance state */ 
        bSmCurrentSendState[sm_channel] = kSmSendNotAllowed;
    }
}


#if defined ( SM_ENABLE_TRANSMISSION_HANDLING )
/* ESCAN00022994: changed SmTransmitNmMessage from macro to function */
/******************************************************************************
* NAME:               SmTransmitNmMessage
* CALLED BY:          application
* Preconditions:      initialization of station manager
* PARAMETER:          channel
* RETURN VALUE:       none
* Description:        trigger event transmission of Nm message
*******************************************************************************/
void SmTransmitNmMessage(SM_CHANNEL_TYPE_ONLY)
{
    /* check if already called */
    if ( bSmTxEventTrigger[sm_channel] == 0 )
    {
        bSmTxEventTrigger[sm_channel] = 1;

        if ( wSmTxDelayCntr[sm_channel] >= wSmInmMsgCycCntr[sm_channel] )
        {
            /* send with next task */
            wSmInmMsgCycCntr[sm_channel] = 1; 
        }
        else
        {
            wSmInmMsgCycCntr[sm_channel] -= wSmTxDelayCntr[sm_channel];
        }
    }
    else
    {
        /* multiple call */
    }
}
#endif

/******************************************************************************
* NAME:               SmGetInterdMemoDef
* CALLED BY:          station manager
* Preconditions:      initialization of station manager
* PARAMETER:          none
* RETURN VALUE:       state of the bit InterdMemoDef ( 0 not set, >0 set )
* Description:        In state application and ComOff the state of the bit 
*                     InterdMemoDef has to be taken into account for the volatile
*                     coutner handling.
*******************************************************************************/
static vuint8 SmGetInterdMemoDef(SM_CHANNEL_TYPE_ONLY)
{
#if defined  ( SM_ENABLE_INTERD_MEMO_DEF_HANDLING )
    vuint8 rval;
# if defined (SM_ENABLE_INTERD_MEMO_DEF_APPL_SPECIFIC)
    /* Always get signal from application */
    rval = ApplSmGetInterdMemoDef(SM_CHANNEL_PARA_ONLY);
# else
    /* The status of the flag "InterdMemoDef" is only relevant if the NM operates 
     * in NM mode "Normal" or "ComOff" */
    if ( (SmGetIntPhaseState(sm_channel) == kSmStateAppl) || (SmGetIntPhaseState(sm_channel) == kSmComOff) )
    {
        rval = ApplSmGetInterdMemoDef(SM_CHANNEL_PARA_ONLY);
    }
    else
    {
        rval = 0;
    }
# endif
    return (rval);
#else
    return 0;
#endif
}


/******************************************************************************
* NAME:               SmDiagOn 
* CALLED BY:          station manager (function 'SmNetworkTask ') 
* Preconditions:      initialization of station manager
* PARAMETER:          sm_channel
* RETURN VALUE:       none
* Description:        Start the timeout supervision of Rx and Tx messages. 
*                     C_BSI supervision is handled separatly 
*******************************************************************************/
static void SmDiagOn (SM_CHANNEL_TYPE_ONLY)
{
#if defined (SM_ENABLE_MULTIPLE_NODES )
  vuint8 bMsgNr; 
#endif
  vuint8 bEcuNr;

  if( (SmGetIntState(sm_channel) & kSmDiagOn) == 0 )
  {

  /* SET current internal SLAVE diagnostic state */
  SmSetIntState( sm_channel, (vuint8)(SmGetIntState(sm_channel) | kSmDiagOn) );

  /* set ECU Rx timeout slave ECU counter */
#if defined (SM_ENABLE_MULTIPLE_NODES )
  for(bMsgNr=0; bMsgNr<kCanNumberOfRxObjects; bMsgNr++)
  {
      /* only relevant ECUs */ 
      if( (bEcuNr = SmGetECUindex(bMsgNr)) != 0xff)
#else
  {
      for(bEcuNr=0; bEcuNr<SM_NUMOFALLRXNODES; bEcuNr++)
#endif
      {
# if defined ( SM_ENABLE_MULTIPLE_NODES )
            if( (inmRxCondition[bEcuNr].status & SM_ECU_VALID ) != 0)
#endif
            {
               /* check if timer not startet */
               if( wSmRxToCycCntr [bEcuNr] == 0 )
               {
                wSmRxToCycCntr [bEcuNr] = SmRxTimeoutValue [bEcuNr];
               }
        }
      }
   }
    /* start diagnostic session ("DIAG OFF" => "DIAG ON") */
   /* supervision of RX, TX, started */
   InmNmDiagOn(SM_CHANNEL_PARA_ONLY);
  }
  else
  {}
}
/******************************************************************************
* NAME:               SmDiagOff 
* CALLED BY:          station manager (function 'SmNetworkTask ')
* Preconditions:      initialization of station manager
* PARAMETER:          none
* RETURN VALUE:       none
* Description:        Stop the timeout supervision of Rx and Tx messages
*                     C_BSI supervision is handled separatly
*******************************************************************************/
static void SmDiagOff (SM_CHANNEL_TYPE_ONLY)
{
#if defined (SM_ENABLE_MULTIPLE_NODES )
  vuint8 bMsgNr;
#endif
  vuint8 bEcuNr;

  /* SET current internal SLAVE diagnostic state */
  SmSetIntState(sm_channel, (vuint8)(SmGetIntState(sm_channel) & ~kSmDiagOn));

 /* clear ECU Rx timeout slave ECU counter */
#if defined (SM_ENABLE_MULTIPLE_NODES )
  for(bMsgNr=0; bMsgNr<kCanNumberOfRxObjects; bMsgNr++)
  {
      /* only relevant ECUs */ 
      if( (bEcuNr = SmGetECUindex(bMsgNr)) != 0xff)
#else
  {
      for(bEcuNr=0; bEcuNr<SM_NUMOFALLRXNODES; bEcuNr++)
#endif
      {
        if( bEcuNr != SmMasterIndex(sm_channel) )
        {
# if defined ( SM_ENABLE_MULTIPLE_NODES )
            if( (inmRxCondition[bEcuNr].status & SM_ECU_VALID ) != 0)
#endif
            {
                wSmRxToCycCntr [bEcuNr] = 0;
            }
         }
      }
   }
   /* stop Rx, Tx supervision */
   InmNmDiagOff(SM_CHANNEL_PARA_ONLY);
}

#if defined ( SM_ECU_TYPE_CANPLUS )
/******************************************************************************
* NAME:               SmSetPlusCanState 
* CALLED BY:          Application
* Preconditions:      initialization of station manager
* PARAMETER:          none
* RETURN VALUE:       none
* Description:        Set state of +CAN signal(HW-signal)
*******************************************************************************/
void SmSetPlusCanState(SM_CHANNEL_TYPE_FIRST vuint8 state )
{
    bSmCanPlusState[sm_channel] = state;
#if defined (ECU_TYPE_PSA_3)
    if( state == 0 )
    {
        /* put ECU into sleep mode */
        SmInitPowerOn();
    }
#endif
}
#endif


#if defined ( SM_ECU_TYPE_ACTIVATION )
/******************************************************************************
* NAME:               SmNetworkRequestAllowed 
* CALLED BY:          Application 
* Preconditions:      initialization of station manager
* PARAMETER:          channel
* RETURN VALUE:       retval:  kSmRequestOk:  Request allowed; 
*                              kSmRequestFailed:  Request not allowed 
*                             (max. value of active wake up exceeded) 
* Description:        check if netrequest is possible
*******************************************************************************/
vuint8 SmNetworkRequestAllowed(SM_CHANNEL_TYPE_ONLY)
{
    vuint8 retval;

    if ( bSmCwakeUpCntr[sm_channel]< 3) 
    {
        retval = kSmRequestOk;
    }
    else

    {
        retval = kSmRequestFailed;
    }
    return retval;
}


/******************************************************************************
* NAME:               SmSetNetworkRequest 
* CALLED BY:          Application 
* Preconditions:      initialization of station manager
* PARAMETER:          channel
* RETURN VALUE:       state:  kSmRequestOk:  Request accepted; 
*                             kSmRequestFailed:  Request not accepted 
*                             (max. value of active wake up exceeded) 
* Description:        Set an external Wake Up request (  application need communication ) 
*******************************************************************************/
vuint8 SmSetNetworkRequest(SM_CHANNEL_TYPE_ONLY)
{ 
    
  vuint8 state = kSmRequestOk;

  if( bSmCwakeUpCntr[sm_channel] <3 )
  {
      bSmNetRequest[sm_channel]= 1;
#if defined (SM_ENABLE_NAS_SUPERVISION )
      if( SmGetIntPhaseState(sm_channel)== kSmVeille )
      {
        /* active WakeUp in state Veille-> don't check N_as timeout */
        bSmActiveWakeUp[sm_channel] = 1;
      }
#endif
  }
  else
  {
      state = kSmRequestFailed;
  }
  return state;
}

/******************************************************************************
* NAME:               SmReleaseNetworkRequest 
* CALLED BY:          Application 
* Preconditions:      initialization of station manager
* PARAMETER:          channel
* RETURN VALUE:       none
* Description:        Release an external Wake Up request ( application don't need communication ) 
*******************************************************************************/
void SmReleaseNetworkRequest(SM_CHANNEL_TYPE_ONLY)
{ 
  bSmNetRequest[sm_channel]= 0;
}

/******************************************************************************
* NAME:               SmSetWakeUpRequest 
* CALLED BY:          Application 
* Preconditions:      initialization of station manager
* PARAMETER:          channel
* RETURN VALUE:       none
* Description:        Set CAN Wake Up request ( CAN frame received ) 
*******************************************************************************/
void SmSetWakeUpRequest(SM_CHANNEL_TYPE_ONLY)
{
    /* only set if in state Veille */
    if( SmGetIntPhaseState(sm_channel)== kSmVeille )
    {
        bSmWakeUpRequest[sm_channel] = 1;
    }
}

/******************************************************************************
* NAME:               SmWakeUpNetwork 
* CALLED BY:          station manager 
* Preconditions:      active station manager
* PARAMETER:          none
* RETURN VALUE:       none
* Description:        The application needs an active indirect OSEK network
*                     management. Therefore a wakeup request is set. 
*                     A specific wakeup message is sent periodically to force
*                     the master ECU to change the state of all slave ECUs
*                     to "MODE NORMAL".
*******************************************************************************/
static void SmWakeUpNetwork (SM_CHANNEL_TYPE_ONLY)
{        
    if ( bSmCwakeUpCntr[sm_channel] < 3 )
    {
       if ( wSmTwakeUpCntr[sm_channel] == 0 )
       {
        #if (kCanNumberOfChannels >1 )
            CanChannelHandle can_channel = SmSmToCanChannel[sm_channel];
        #endif
            /* disable all CAN interrupts */
            CanCanInterruptDisable(SM_CAN_CHANNEL_PARA_ONLY);
            /* Reset Tveille counter */
            wSmTveilleCntr[sm_channel] = 0;
            if ( wSmToffCntr[sm_channel] != 0 )
            {
                /* Reset Toff counter */
                wSmToffCntr[sm_channel] = 0;          
                /* restart surveillance of Commande_BSI */
                wSmRxToCycCntr[SmMasterIndex(sm_channel)] = SmRxTimeoutValue[SmMasterIndex(sm_channel)];
        #if defined SM_ENABLE_ADDITIONAL_SUPERVISION
                bSmAddRxTCntr[sm_channel] = SmAddRxTimeout[sm_channel];
        #endif
            }
        /* set Status to Reveil */
        SmSetIntECUState( sm_channel, kSmReveil );
        /* enable sending of wakeup message */
        SmSetECUSendState ( SM_CHANNEL_PARA_FIRST C_SEND_GRP_WAKEUP);           
    
        /* set wakeUp counter */
        wSmTwakeUpCntr[sm_channel]= kSmTWakeUp/kSmTaskCycle;
        bSmCwakeUpCntr[sm_channel]++;
        /* enable all CAN interrupts */
        CanCanInterruptRestore(SM_CAN_CHANNEL_PARA_ONLY);
       }
    }
    else
    {
    /* implizit Release of Netrequest */
       bSmNetRequest[sm_channel] = 0;   
    /* CAllback to Upper Layer */
       ApplSmNetRequestRelease(SM_CHANNEL_PARA_ONLY); 
    }
}
#endif

/********************************************/

/******************************************************************************
* NAME:               SmWakeUpTask 
* CALLED BY:          StMgr
* Preconditions:      initialization of station manager
* PARAMETER:          channel
* RETURN VALUE:       none
* Description:        Check if there are any WakeUp reasons  
*******************************************************************************/
static void SmWakeUpTask(SM_CHANNEL_TYPE_ONLY)
{
#if (kCanNumberOfChannels > 1u )
    CanChannelHandle can_channel = SmSmToCanChannel[sm_channel]; /* ESCAN00071596 */
#endif

    if( SmGetIntPhaseState(sm_channel)== kSmVeille )
    {
        #if defined ( SM_ECU_TYPE_CANPLUS )&& defined ( SM_ECU_TYPE_ACTIVATION )
        /* network requested? */
        if( (bSmNetRequest[sm_channel] != 0) || 
            (bSmWakeUpRequest[sm_channel] != 0) || 
            (bSmCanPlusState[sm_channel] != 0) )
        {
          bSmWakeUpRequest[sm_channel] = 0;
       #elif defined ( SM_ECU_TYPE_ACTIVATION ) 
        if( bSmNetRequest[sm_channel] != 0 || 
            bSmWakeUpRequest[sm_channel] != 0 )
        {
           bSmWakeUpRequest[sm_channel] = 0;
        #elif defined ( SM_ECU_TYPE_CANPLUS )
        if( bSmCanPlusState[sm_channel] != 0 )
        {
        #endif
           /* clear PerteCom volatile counter */
           bSmCPerteCom[sm_channel] = 0;
           bSmCBusOff[sm_channel] = 0;
#if defined (SM_ENABLE_NAS_SUPERVISION)
           bNasCounter = 0;
#endif
           InmNmStart(SM_CHANNEL_PARA_ONLY);


           SmSetExtState(sm_channel, kSmReveil);
           SmSetIntECUState(sm_channel, kSmReveil);
           /* start surveillance of Commande_BSI */
           wSmRxToCycCntr[SmMasterIndex(sm_channel)] = SmRxTimeoutValue[SmMasterIndex(sm_channel)];
#if defined SM_ENABLE_ADDITIONAL_SUPERVISION
           bSmAddRxTCntr[sm_channel] = SmAddRxTimeout[sm_channel];
#endif
           /* Put CAN driver ONline */
           CanOnline(SM_CAN_CHANNEL_PARA_ONLY);
        }
#if defined ( SM_ECU_TYPE_ACTIVATION )
        /* net request by application: send WakeUp message */
        if( bSmNetRequest[sm_channel] != 0 ) 
        {
            SmWakeUpNetwork(SM_CHANNEL_PARA_ONLY);
        }
#endif
    }

/*---------------------------------------------*/
#if defined ( SM_ECU_TYPE_ACTIVATION )
    if( SmGetIntPhaseState(sm_channel) == kSmPerteCom )
    {
        /* clear CAN Wake Up request */
        bSmWakeUpRequest[sm_channel] = 0;

        if( bSmNetRequest[sm_channel] != 0 )
        {
#  if defined (ECU_TYPE_PSA_1)
            /* +CAN absent? only then we are allowed to wake Up */
            if( bSmCanPlusState[sm_channel] == 0 )
#  endif
            {
                SmWakeUpNetwork(SM_CHANNEL_PARA_ONLY);
            }
        }
    }
  
/*----------------------------------*/
    
    if( (SmGetIntPhaseState(sm_channel) == kSmMiseEnVeille) || (SmGetIntPhaseState(sm_channel) == kSmReveil))
        /* WakeUp during MisEnVeille or Reveil */
    {
        /* clear CAN Wake Up request */
        bSmWakeUpRequest[sm_channel] = 0;
        if( bSmNetRequest[sm_channel] != 0 )
        {
            SmWakeUpNetwork(SM_CHANNEL_PARA_ONLY);
        }
    }
#endif

#if defined SM_ENABLE_ADDITIONAL_SUPERVISION   
    if( SmGetIntPhaseState(sm_channel)== kSmPerteCom )
    {
        /* check if add supervised msg. is received */
        if ( bSmAddRxState[sm_channel] == 1 )
        {
            SmSetExtECUState(sm_channel, kSmModeNormal);
        }
    }
#endif
}



/******************************************************************************
* NAME:               SmNetworkTask 
* CALLED BY:          station manager (function 'SmTask')
* Preconditions:      initialization of station manager
* PARAMETER:          none
* RETURN VALUE:       none
* Description:        The network task handles the state transition according to
*                     the definition of organ type 1,2 or 3 which depends on the requested
*                     state (including timeout) by the message "COMMANDE_BSI" of
*                     the master ECU.
*                     Additionaly the network management message of the own slave
*                     ECU is sent.
*******************************************************************************/
static void SmNetworkTask( SM_CHANNEL_TYPE_ONLY )
{
    vuint8 bSmTransmitVersionMessage = 0;

#if (kCanNumberOfChannels >1 )
    CanChannelHandle can_channel = SmSmToCanChannel[sm_channel];
#endif
    /* disable all CAN interrupts */
    CanCanInterruptDisable(SM_CAN_CHANNEL_PARA_ONLY);

    /***********************************/
    /* Check if Transition is possible */
    /***********************************/
    if(( abSmChkTransAct[SmGetIntPhaseState(sm_channel)] & abSmChkTransNew[SmGetExtPhaseState(sm_channel)]) != 0 )
    {
        /* switch requested state and call function */
        if( SmGetExtPhaseState(sm_channel) == kSmVeille )
        { 
            /* implicit check if function was already executed */
            if( wSmRxToCycCntr [SmMasterIndex(sm_channel)] != 0 )
            {
                /* ( Stop surveillance of Commande_BSI ) */
                wSmRxToCycCntr [SmMasterIndex(sm_channel)] = 0;
#if defined SM_ENABLE_ADDITIONAL_SUPERVISION
                bSmAddRxTCntr[sm_channel] = 0;
#endif
                /* ESCAN00031077 */
                /* Stop Diagnosis */
                SmDiagOff(SM_CHANNEL_PARA_ONLY);
                SmSetExtState(sm_channel, (vuint8)(SmGetExtState(sm_channel) & ~kSmDiagOn));
#if defined (ECU_TYPE_PSA_3)
#else
                /* start T_off timer */ 
                if ( wSmToffCntr[sm_channel] == 0)
                {
                    wSmToffCntr[sm_channel] = kSmToff/kSmTaskCycle;
                }
#endif
# if defined (SM_ENABLE_EXTENDED_STATES )
                /* ESCAN00032161 */
                bSmIntStateExtended[sm_channel] = 1;
# endif
                /* set part online: NONE */
                SmSetECUSendState ( SM_CHANNEL_PARA_FIRST C_SEND_GRP_NONE);
            }
        }
        else if( SmGetExtPhaseState(sm_channel) == kSmReveil )
        {
            SmSetIntECUState(sm_channel, kSmReveil );
           
            /* ( Start surveillance of Commande_BSI ) */
            wSmRxToCycCntr[SmMasterIndex(sm_channel)] = SmRxTimeoutValue[SmMasterIndex(sm_channel)];
#if defined SM_ENABLE_ADDITIONAL_SUPERVISION

            bSmAddRxTCntr[sm_channel] = SmAddRxTimeout[sm_channel];
#endif      
            /* ESCAN00031077 */
            /* Stop Diagnosis */
            SmDiagOff(SM_CHANNEL_PARA_ONLY);

            /* set part online: None */
            SmSetECUSendState ( SM_CHANNEL_PARA_FIRST C_SEND_GRP_NONE);
        }
        else if( SmGetExtPhaseState(sm_channel) == kSmMiseEnVeille )
        {

# if defined ( SM_ECU_TYPE_ACTIVATION )
            /* check if we want to wake up the bus       */
            /* If: wait 1 second until switching to MEV  */
            if ( wSmTwakeUpCntr[sm_channel] == 0 )
#endif
            {
                SmSetIntECUState(sm_channel, kSmMiseEnVeille );

                /* ESCAN00031077 code removed */

                /* set part online: JDD */
                SmSetECUSendState ( SM_CHANNEL_PARA_FIRST C_SEND_GRP_JDD);
            }
        }
        else if( SmGetExtPhaseState(sm_channel) == kSmComOff )
        {
            SmSetIntECUState(sm_channel, kSmComOff );

            /* Set partonline: Only diag */
            SmSetECUSendState( SM_CHANNEL_PARA_FIRST C_SEND_GRP_DIAG);

            /* Reset of external event counter (bSmCwakeUpCntr) is performed at transition to state normal */

            /* ESCAN00031077 code removed */
        }
        /* all other states are assumed as state normal */
        else
        {
#if defined ( SM_ECU_TYPE_ACTIVATION )
            bSmCwakeUpCntr[sm_channel] = 0;
#endif
            /* send version message if coming from Stat reveil */
            if( SmGetIntPhaseState(sm_channel) == kSmReveil )
            {
              bSmTransmitVersionMessage = 1;
            }
            /* SET current internal SLAVE phase state to mode normal */
            SmSetIntECUState(sm_channel, kSmModeNormal);
            if( wSmRxToCycCntr[SmMasterIndex(sm_channel)] == 0 ) 
            {
              /* ( Start supervision of Commande_BSI ) */
              wSmRxToCycCntr[SmMasterIndex(sm_channel)] = SmRxTimeoutValue[SmMasterIndex(sm_channel)];
#if defined SM_ENABLE_ADDITIONAL_SUPERVISION
              bSmAddRxTCntr[sm_channel] = SmAddRxTimeout[sm_channel];
#endif
            }

# if defined (SM_ECU_TYPE_ACTIVATION )
            /* Stop WakeUp timer (only relevant to avoid direct transition Reveil -> MeVeille: */
            /* can be stopped in mode normal) */
            wSmTwakeUpCntr[sm_channel] = 0;
# endif

            SmDiagOn(SM_CHANNEL_PARA_ONLY);
            /* set part online: FUNCTIONAL and DIAG and JDD */
            SmSetECUSendState ( SM_CHANNEL_PARA_FIRST C_SEND_GRP_FUNCTIONAL|C_SEND_GRP_DIAG|C_SEND_GRP_JDD);
            if( bSmTransmitVersionMessage == 1 )
            {
              SmAssert ( (SmTxHdlVersionMsg[SmIdentity(sm_channel)] < kCanNumberOfTxObjects), kTxHandleOutOfRange );
              /* ESCAN00025407 */
              if( SmTxHdlVersionMsg[SmIdentity(sm_channel)] < kCanNumberOfTxObjects )
              {
                (void)CanTransmit( SmTxHdlVersionMsg[SmIdentity(sm_channel)] );
              }
            }
        }
    }
/* Check if ECU received Cmd BSI and switch online again  */
/* Flag is set int SmCanNerrAccess()                      */
    if (bSmCmdBSIReceived[sm_channel]== 1)
    {
      bSmCmdBSIReceived[sm_channel] = 0;

      /* if BusOff, no frame has to be transmitted 
      after reception of c_BSI if state != normal. 
      Req. 966-0213.01B  */
      if ( SmGetIntPhaseState(sm_channel) == kSmPerteCom )
      {
        SmSetECUSendState ( SM_CHANNEL_PARA_FIRST C_SEND_GRP_NONE);
      }

      /* switch on CAN driver completely */
      CanOnline(SM_CAN_CHANNEL_PARA_ONLY);

      /* clear flag */
      bSmBusOffRecCntr[sm_channel] &= (vuint8)(~((vuintx)kSmBoffIndication));
      /* start 1000ms timer to reset recovery algorithm */
      bSmBusOffOnlineCntr[sm_channel] = SM_RECOVERY_TIMER;
    }
  /* enable all CAN interrupts */
  CanCanInterruptRestore(SM_CAN_CHANNEL_PARA_ONLY);
}


/******************************************************************************
* NAME:               SmTimeoutTask 
* CALLED BY:          station manager (function 'SmTask ')
* Preconditions:      initialization of station manager
* PARAMETER:          none
* RETURN VALUE:       none
* Description:        Check for +CAN, T_off and T_veille
*******************************************************************************/
static void SmTimeoutTask( SM_CHANNEL_TYPE_ONLY )
{
#if (kCanNumberOfChannels >1 )
    CanChannelHandle can_channel = SmSmToCanChannel[sm_channel];
#endif
    /* disable all */
    CanInterruptDisable();

#if defined (SM_ECU_TYPE_ACTIVATION )

#if defined ( SM_ECU_TYPE_CANPLUS)
    /***********************************/
    /* Check if +CAN state has changed */
    /***********************************/
    if( bSmLocalCanPlusState[sm_channel] != bSmCanPlusState[sm_channel] )
    {
        bSmLocalCanPlusState[sm_channel] = bSmCanPlusState[sm_channel];

        if ( bSmCanPlusState[sm_channel] == 0)
        {       
            if( SmGetIntPhaseState(sm_channel) == kSmPerteCom )
            {
                /* set Tveille counter (add 1 cause it is decremented immediatelly below) */
                wSmTveilleCntr[sm_channel] = (kSmTveille/kSmTaskCycle) + 1;

# if defined ( ECU_TYPE_PSA_1 )
                /* Stop emission of messages if +CAN missing */
                SmSetECUSendState ( SM_CHANNEL_PARA_FIRST C_SEND_GRP_NONE);           
                SmDiagOff(SM_CHANNEL_PARA_ONLY);
# endif
            }
        }
        else
        {
            /* stop Tveille counter */
            wSmTveilleCntr[sm_channel] = 0;
# if defined ( ECU_TYPE_PSA_1 )                         
            if( SmGetIntPhaseState(sm_channel) == kSmPerteCom )
            {
                /* set part online: FUNCTIONAL to restart transmission */
                SmSetECUSendState ( SM_CHANNEL_PARA_FIRST C_SEND_GRP_FUNCTIONAL | C_SEND_GRP_DIAG);           
            }
# endif
        }
    }
#endif

    /**********************************/
    /* WAKE UP TIMER                  */
    /* (ignore Mis_en_Veille for one  */
    /* sec. if ECU wakes up the bus ) */
    /**********************************/
    if ( wSmTwakeUpCntr[sm_channel] != 0 )
    {
        wSmTwakeUpCntr[sm_channel]--;
    }

    /*******************/
    /* T_veille TIMER  */
    /*******************/
    if ( wSmTveilleCntr[sm_channel] != 0 )
    {
        wSmTveilleCntr[sm_channel]--;   
        if ( wSmTveilleCntr[sm_channel] == 0 ) /* Timeout 15s since perte com -> goto veille */
        {
            /* SET current external SLAVE phase state to "Veille" */  
            SmSetExtECUState(sm_channel, kSmVeille);
            /* Goto sleep immediately: Set T_off counter to 1 to stop in check of T_off */
            wSmToffCntr[sm_channel] = 1;
        }
    }

    /****************/
    /* T_off TIMER  */
    /****************/
    if ( wSmToffCntr[sm_channel] != 0 )
    {
        wSmToffCntr[sm_channel]--;
        if ( wSmToffCntr[sm_channel] == 0 )
        {
            /* ( Stop surveillance of Commande_BSI ) */
            wSmRxToCycCntr [SmMasterIndex(sm_channel)] = 0;  

            SmSetIntECUState(sm_channel, kSmVeille );
            /* stop indirect OSEK network management */
            InmNmStop(SM_CHANNEL_PARA_ONLY);  
        }
    }
/* ESCAN00028168 */
#endif /* (ECU_TYPE_PSA_1) || defined (ECU_TYPE_PSA_2) || defined ( ECU_TYPE_PSA_4 )*/
    /* enable all interrupts */
    CanInterruptRestore();
}




/******************************************************************************
* NAME:               SmSupervisionTask 
* CALLED BY:          station manager (function 'SmTask ')
* Preconditions:      initialization of station manager
* PARAMETER:          none
* RETURN VALUE:       none
* Description:        The indirect OSEK network management observes both the 
*                     message transmission of the owm slave ECU and the message
*                     reception from the master ECU and all other slave ECUs.
*                     If a timeout occurs, either the volatile or non-volatile
*                     counter for "MUTE" (Tx) / "ABSENT" (Rx) is incremented.
*******************************************************************************/
static void SmSupervisionTask(SM_CHANNEL_TYPE_ONLY)
{
  vuint8 bEcuNr;
  #if (kCanNumberOfChannels >1 )
    CanChannelHandle can_channel = SmSmToCanChannel[sm_channel];
#endif
/* check possible timeout of each supervised Rx node if state != veille ****/
  if (SmGetIntPhaseState(sm_channel) != kSmVeille )
  {
    /* disable all CAN interrupts */
    CanCanInterruptDisable(SM_CAN_CHANNEL_PARA_ONLY);

    /********************/
    /**** RX SECTION ****/
    /********************/

#if defined SM_ENABLE_ADDITIONAL_SUPERVISION
    if (bSmAddRxInidcationFlag[sm_channel] != 0 )
    {
        bSmAddRxInidcationFlag[sm_channel] = 0;
        bSmAddRxState[sm_channel] = 1;
        /* Restart Timer */
        if( bSmAddRxTCntr[sm_channel] != 0)
        {
            bSmAddRxTCntr[sm_channel] = SmAddRxTimeout[sm_channel];
        }        
    }
    else
    {
        if( bSmAddRxTCntr[sm_channel] != 0)
        {
            bSmAddRxTCntr[sm_channel]--;
            if( bSmAddRxTCntr[sm_channel] == 0)
            {
                bSmAddRxState[sm_channel] = 0;
                bSmAddRxTCntr[sm_channel] = SmAddRxTimeout[sm_channel];
            }
         }
    }
#endif

    for(bEcuNr=0; bEcuNr<SM_NUMOFALLRXNODES; bEcuNr++)
    {
      if ( baSmRxIndicationFlags[bEcuNr] == 1 )
      {
        SmRxTimeoutSupervision(SM_CHANNEL_PARA_FIRST bEcuNr);
        baSmRxIndicationFlags[bEcuNr] = 0;
      }

      /* ECU Rx timeout counter is activated? */
      else if( wSmRxToCycCntr [bEcuNr] != 0)
      {
        /* decrement ECU Rx timeout counter */
        wSmRxToCycCntr[bEcuNr]--;

        /* check underflow of ECU Rx timeout counter */
        SmAssert ( (wSmRxToCycCntr [bEcuNr]<SmRxTimeoutValue [bEcuNr]), kRxToCntrOutOfRange);

        /* ECU Rx timeout counter is expired? */
        if( wSmRxToCycCntr [bEcuNr] == 0)
        {
            if ( SmGetInterdMemoDef(SM_CHANNEL_PARA_ONLY) == 0 )
            {
                /* notify indirect OSEK network management of Rx message timeout */ 
                (void)InmNmRxTimeOut(bEcuNr);
            }
            /* set ECU Rx timeout counter (once again) */
            wSmRxToCycCntr [bEcuNr] = SmRxTimeoutValue [bEcuNr];
            /*************************************/
            /*              PERTE COM            */
            /* InmNmMaster expired? Set PerteCom */
            /*************************************/

#if defined SM_ENABLE_ADDITIONAL_SUPERVISION
            if ( bEcuNr == SmMasterIndex(sm_channel) &&  bSmAddRxState[sm_channel] == 0 )
            {
#else
            if ( bEcuNr == SmMasterIndex(sm_channel))
            {
#endif
              if( SmGetIntPhaseState(sm_channel) != kSmPerteCom  )
              {
                /* increment volatile perteCom counter and let it overflow at 256 */
                bSmCPerteCom[sm_channel]++;

                /* SET current internal SLAVE phase state to "PERTE COM" */
                SmSetIntECUState(sm_channel, kSmPerteCom);
                /* SET current external SLAVE phase state to "PERTE COM" */
                SmSetExtECUState(sm_channel, kSmPerteCom);

    # if defined (ECU_TYPE_PSA_3)
                /* set part online: FUNCTIONAL */
                SmSetECUSendState ( SM_CHANNEL_PARA_FIRST C_SEND_GRP_FUNCTIONAL | C_SEND_GRP_DIAG);
    # endif

    # if defined ( SM_ECU_TYPE_ACTIVATION )
                /* Stop WakeUp timer (only relevant for direct transition Reveil -> MeVeille) */
                wSmTwakeUpCntr[sm_channel] = 0;
    # endif

    # if defined ( ECU_TYPE_PSA_1 )
                /* +CAN already absent? */
                if( bSmCanPlusState[sm_channel] == 0 )
                {
                    /* Stop emission of messages if +CAN is missing */
                    SmSetECUSendState ( SM_CHANNEL_PARA_FIRST C_SEND_GRP_NONE);
                    
                    /* start Tveille Counter */
                    wSmTveilleCntr[sm_channel] = (kSmTveille/kSmTaskCycle);
                }
                else /* +CAN present */
                {
                    /* set part online: FUNCTIONAL */
                    SmSetECUSendState ( SM_CHANNEL_PARA_FIRST C_SEND_GRP_FUNCTIONAL| C_SEND_GRP_DIAG);
                }
    #  endif /* ECU_TYPE_PSA_1 */

    #  if defined ( ECU_TYPE_PSA_2 ) || defined ( ECU_TYPE_PSA_4 )
                SmSetECUSendState ( SM_CHANNEL_PARA_FIRST C_SEND_GRP_NONE);
                
#  if defined ( ECU_TYPE_PSA_2 )
                /* +CAN already absent? */
                if( bSmCanPlusState[sm_channel] == 0 )
#endif
                {
                    /* start Tveille Counter */
                    wSmTveilleCntr[sm_channel] = (kSmTveille/kSmTaskCycle);
                }
    #  endif /* ECU_TYPE_PSA_2 || defined ( ECU_TYPE_PSA_4 ) */
              } /* state != perteCom? */
            } /* Master ECU? */
        }/* timer elapsed ? */
      } /* timer active ? */
      else
      {
        /* nothing to be done */
      }
    } /* for */

/********************/
/**** TX SECTION ****/
/********************/
  /* handle Tx Confirmation */
 #if defined ( SM_ENABLE_DYNAMIC_TX )
  if ((CanConfirmationFlags._c[CanGetConfirmationOffset(bSmInmMsgHandle[sm_channel])] \
    & CanGetConfirmationMask(bSmInmMsgHandle[sm_channel])) != 0 )
  {
    /* clear Repeated Boff Bit and counter */
    bSmBusOffRecCntr[sm_channel] = 0;

    SmTxConfirmation(SM_CHANNEL_PARA_ONLY); 
    CanConfirmationFlags._c[CanGetConfirmationOffset(bSmInmMsgHandle[sm_channel])] \
      &=(canuint8)(~CanGetConfirmationMask(bSmInmMsgHandle[sm_channel]));
  }
 #else
  if ( bSmTxConfirmationFlag[sm_channel] == 1 )  
  {
     SmTxConfirmation(SM_CHANNEL_PARA_ONLY); 
     bSmTxConfirmationFlag[sm_channel] = 0;
  }    
 #endif
/* check possible timeout of own supervised Tx node ***************************/
  /* ECU Tx timeout counter is activated? */
  else if( wSmTxToCycCntr[sm_channel] != 0 )
  {
    /* decrement ECU Tx timeout counter */
    wSmTxToCycCntr[sm_channel] --;


    /* ECU Tx timeout counter is expired? */
    if( wSmTxToCycCntr[sm_channel] == 0  )
    {
         if (SmGetInterdMemoDef(SM_CHANNEL_PARA_ONLY) == 0 )
         {
            /* notify indirect OSEK network management of Tx message timeout */ 
            InmNmTxTimeOut( SM_CHANNEL_PARA_ONLY);
         }
    }
  }
  else
  {
    /* nothing to be done */
  }
  /* enable all CAN interrupts */
  CanCanInterruptRestore(SM_CAN_CHANNEL_PARA_ONLY);
  }
}



/******************************************************************************
* NAME:               SmDiagTask 
* CALLED BY:          station manager (function 'SmTask ')
* Preconditions:      initialization of station manager
* PARAMETER:          none
* RETURN VALUE:       none
* Description:        The volatile counters for Tx timeout (MUTE), Rx timeout
*                     (ABSENT) and BusOff (BUSOFF) are handled in active
*                     diagnostic mode [DIAG_ON = 1], whereas the non-volatile
*                     counters are permitted to increment more than once within
*                     a so-called "warm up cycle". So the inhibition is only
*                     possible by a CAN+ ECU reset.
*******************************************************************************/
static void SmDiagTask (SM_CHANNEL_TYPE_ONLY)
{

#if (kCanNumberOfChannels >1 )
    CanChannelHandle can_channel = SmSmToCanChannel[sm_channel];
#endif
    /* disable all CAN interrupts */
    CanCanInterruptDisable(SM_CAN_CHANNEL_PARA_ONLY);
    
    /* No Bus Off pending? We don't read the new Diag state when B.off algorithm is activ */
    if ((!bSmBusOffCycCntr[sm_channel] ) && ((SmGetIntPhaseState(sm_channel) == kSmStateAppl ) || \
       ( SmGetIntPhaseState(sm_channel) == kSmMiseEnVeille )||(SmGetIntPhaseState(sm_channel) == kSmComOff )))
    {
    /* diagnostic handling "DIAG ON" */
    /* GET current internal SLAVE diagnostic state */
        if( (SmGetIntState(sm_channel) & kSmDiagOn) != 0 )
        { 
            /* GET requested external MASTER diagnostic state */
            if( (SmGetExtState(sm_channel) & kSmDiagOn) == 0 )
            {           
                /* stop diagnostic session ("DIAG ON" => "DIAG OFF") */
                SmDiagOff(SM_CHANNEL_PARA_ONLY);
            }
        }
        else
        {
            /* GET requested external MASTER diagnostic state */
            if( (SmGetExtState(sm_channel) & kSmDiagOn ) != 0 )
            {
                
                /* start diagnostic session ("DIAG OFF" => "DIAG ON") */
                SmDiagOn(SM_CHANNEL_PARA_ONLY);
            }
        }
     }
        /* to avoid a recursive call of ApplInmNmStatusIndicationRx
    this flag is set and InmDiagOff() called here */
    if ( bSmConfPerteCom[sm_channel] == 1 )
    {
        /* CLEAR current internal SLAVE diagnostic state */
        SmSetIntState(sm_channel, (vuint8)(SmGetIntState(sm_channel) & ~kSmDiagOn));
        SmSetExtState(sm_channel, (vuint8)(SmGetExtState(sm_channel) & ~kSmDiagOn));
        SmDiagOff(SM_CHANNEL_PARA_ONLY);
        bSmConfPerteCom[sm_channel] = 0;
    }

    /* enable all CAN interrupts */
    CanCanInterruptRestore(SM_CAN_CHANNEL_PARA_ONLY);
}

/******************************************************************************
* NAME:               SmBusOffTask 
* CALLED BY:          station manager (function 'SmTask ')
* Preconditions:      initialization of station manager
* PARAMETER:          none
* RETURN VALUE:       none
* Description:        After a specified amount of repeated BusOff (without any
*                     successful transmission and reception of messages) a 
*                     (medium or slow) delay for the following recovery must
*                     takes place to minimize the bus load for a possible
*                     permanent mal function.
*******************************************************************************/
static void SmBusOffTask (SM_CHANNEL_TYPE_ONLY)
{
#if (kCanNumberOfChannels >1 )
    CanChannelHandle can_channel = SmSmToCanChannel[sm_channel];
#endif
  /* BusOff time distance counter is activated? */
  if( bSmBusOffCycCntr[sm_channel] != 0 )
  {
    /* decrement BusOff time distance counter */    
    bSmBusOffCycCntr[sm_channel] --;

    /* BusOff time distance counter is expired? */
    if ( bSmBusOffCycCntr[sm_channel] == 0 )
    {
# if (kCanNumberOfChannels >1 )
      (void) CanStart( can_channel );
# else 
      (void) CanStart();
# endif

# if defined(SM_ENABLE_BUSOFF_END_FCT )
      /* notify on end of BusOff recovery algorithm */
      ApplNwmBusoffEnd(SM_CHANNEL_PARA_ONLY);
# endif

      /* set bus Off Indication Bit. This Bit indicates if the CAN Cell */
      /* can be set Online on reception of the message Command_BSI (s. SmCanNerrAccess() ) */
      bSmBusOffRecCntr[sm_channel] |= kSmBoffIndication;
    }
  }

  /* can the BusOff recovery algorithm be reset? */
  if( bSmBusOffOnlineCntr[sm_channel] != 0 )
  {
    bSmBusOffOnlineCntr[sm_channel]--;
    if( bSmBusOffOnlineCntr[sm_channel] == 0 )
    {
        /* clear Repeated Boff Bit and counter */
        bSmBusOffRecCntr[sm_channel] = 0;
    }
  }
}


/******************************************************************************/
/* Global functions                                                           */
/******************************************************************************/

/* service functions **********************************************************/

/******************************************************************************
* NAME:               SmGetStatus 
* CALLED BY:          application
* Preconditions:      initialization of station manager
* PARAMETER:          network state (s. variable "bSmIntState ")
* RETURN VALUE:       none
* Description:        The current internal SLAVE phase state is provided for
*                     application access (e.g. to suppress the timeout
*                     observation).
*******************************************************************************/
vuint8 SmGetStatus (SM_CHANNEL_TYPE_ONLY)
{
  /* get current internal SLAVE phase state */
  return ((vuint8)(SmGetIntState(sm_channel) & (kSmPhases | kSmDiagOn)));
}

#if defined( SM_ENABLE_EXTENDED_STATES )
/* ESCAN00032161 */
/******************************************************************************
* NAME:               SmGetExtendedStatus 
* CALLED BY:          application
* Preconditions:      initialization of station manager
* PARAMETER:          internal state (s. variable "bSmIntStateExtended ")
* RETURN VALUE:       none
* Description:        The current internal SLAVE phase state is provided for
*                     application access
*******************************************************************************/
vuint8 SmGetExtendedStatus(SM_CHANNEL_TYPE_ONLY)
{
    vuint8 state;
    if( bSmIntStateExtended[sm_channel] == 1 )
    {
        state = kSmExtSleepBSIFrame;
    }
    else
    {
        state = SmGetIntState(sm_channel)& (kSmPhases | kSmDiagOn);
    }
    return ( state );
}
#endif


/******************************************************************************
* NAME:               SmInitPowerOn 
* CALLED BY:          application
* Preconditions:      disabled CAN interrupts (Tx, Rx and Error)
* PARAMETER:          none
* RETURN VALUE:       none
* Description:        Both the indirect OSEK network management and the
*                     station manager of organ type 3 is initialized. All
*                     variables are set to default values:
*                     - internal/external state: "VEILLE"
*                     - stop Tx and Rx timeout observation
*                     - set master ECU and all slave ECUs to "PRESENT"
*                     - reset BusOff recovery algorithm
*******************************************************************************/
void SmInitPowerOn (void)
{
#if defined (SM_ENABLE_MULTIPLE_NODES )
  vuint8 bMsgNr; 
#endif

#if( SM_CHANNELS >1 )
  vuint8 sm_channel;
#endif  

#if defined (SM_ENABLE_NAS_SUPERVISION)
  vuint8 i;
#endif 
  vuint8 bEcuNr;


#if defined (SM_ENABLE_NAS_SUPERVISION)
    /* N_as supervision only supported for single channel */
    for(i=0; i<kCanNumberOfUsedTxCANObjects;i++)
    {
        bNasTimeout[i] = 0;
        bActHandle[i] = 0xff;        
    }
    bNasCounter = 0;
#endif  

#if( SM_CHANNELS >1 )
  /* init all channels */
  for ( sm_channel = 0; sm_channel<SM_CHANNELS; sm_channel++ )
#endif
  {

#if defined SM_ENABLE_ADDITIONAL_SUPERVISION
    bSmAddRxInidcationFlag[sm_channel] = 0;
    bSmAddRxState[sm_channel] = 0;
    bSmAddRxTCntr[sm_channel] = 0;
#endif

#if defined (SM_ENABLE_TRANSMISSION_HANDLING)
    bSmTxEventTrigger[sm_channel] = 0;
# if defined ( SM_ENABLE_DYNAMIC_TX )
    wSmTxDelayCntr[sm_channel] = ( (bSmInmMsgTime[sm_channel] - (30/kSmTaskCycle )));
# else
    wSmTxDelayCntr[sm_channel] = ( (SmMsgTime[SmIdentity(sm_channel)] - (30/kSmTaskCycle )));
# endif 
#endif

#if defined ( SM_ECU_TYPE_ACTIVATION )
    /* init Toff and Tveille counter */
    wSmTveilleCntr[sm_channel] = 0; 
    bSmNetRequest[sm_channel] = 0;
    bSmWakeUpRequest[sm_channel] = 0;
    bSmCwakeUpCntr[sm_channel] = 0;
    wSmTwakeUpCntr[sm_channel] = 0;
    wSmToffCntr[sm_channel] = 0;
 #if defined (SM_ENABLE_NAS_SUPERVISION )
    bSmActiveWakeUp[sm_channel] = 0;
 #endif
#endif 

#if defined ( SM_ECU_TYPE_CANPLUS )
    bSmCanPlusState[sm_channel] = 0;
# if defined ( SM_ECU_TYPE_ACTIVATION )
    bSmLocalCanPlusState[sm_channel] = 0;
# endif
#endif
#if defined ( SM_ENABLE_DYNAMIC_TX )
#else
    bSmTxConfirmationFlag[sm_channel] = 0;
#endif
    bSmCmdBSIReceived[sm_channel] = 0;
    bSmNerrPinState[sm_channel] = 0;
    /* clear BusOff recovery counter */
    bSmBusOffRecCntr[sm_channel]  = 0;
    /* clear BusOff time distance counter */
    bSmBusOffCycCntr[sm_channel]  = 0;  
    bSmBusOffOnlineCntr[sm_channel] = 0;
    bSmConfPerteCom[sm_channel] = 0; 
    bSmCPerteCom[sm_channel] = 0;
    bSmCBusOff[sm_channel] = 0;
    bSmCurrentSendState[sm_channel] = kSmSendNotAllowed;

    wSmInmMsgCycCntr[sm_channel] = 0;
    /* clear ECU Tx timeout counter */
    wSmTxToCycCntr[sm_channel]  = 0;

 #if defined (SM_ENABLE_EXTENDED_STATES )
    /* ESCAN00032161 */
    bSmIntStateExtended[sm_channel] = 0;
 #endif

    SmSetECUSendState ( SM_CHANNEL_PARA_FIRST C_SEND_GRP_NONE);
    /* SET current internal SLAVE phase state to "sleep" */
    SmSetIntState (sm_channel, kSmPowerOn);
    /* SET requested external MASTER phase state to "sleep" */
    SmSetExtState (sm_channel, kSmPowerOn);
    /* initialize indirect OSEK network management */
    InmNmInit(SM_CHANNEL_PARA_ONLY);
    /* Put ECU into Sleep mode */
    ApplInmNmStopCanIl(SM_CHANNEL_PARA_ONLY);
  }

#if defined (SM_ENABLE_MULTIPLE_NODES )
  for(bMsgNr=0; bMsgNr<kCanNumberOfRxObjects; bMsgNr++)
  {
    /* only relevant ECUs */ 
    bEcuNr = SmGetECUindex(bMsgNr);
    if( bEcuNr != 0xff )
    {
      inmRxCondition[bEcuNr].status |= SM_ECU_VALID;
#else
  {      
    /* Rx supervision array is linear and not organized by channels! */
    for(bEcuNr=0; bEcuNr<SM_NUMOFALLRXNODES; bEcuNr++)
    {        
#endif
      /* clear ECU Rx timeout master/slave ECU counter */
      wSmRxToCycCntr [bEcuNr] = 0;
      baSmRxIndicationFlags [bEcuNr] = 0;
    }
  }  
}

/******************************************************************************
* NAME:               SmTxTask 
* Preconditions:      initialization of station manager
* PARAMETER:          none
* RETURN VALUE:       none
* Description:        Timeout and transmit control
*******************************************************************************/
static void SmTxTask (SM_CHANNEL_TYPE_ONLY)
{
  /* Send INM Message */   
  /* indirect OSEK network management time distance counter is activated? */
  if( wSmInmMsgCycCntr[sm_channel] != 0  )
  {
      /* decrement indirect OSEK network management time distance counter */
      wSmInmMsgCycCntr[sm_channel] --;
          
      /* indirect OSEK network management time distance counter is expired? */
      if( wSmInmMsgCycCntr[sm_channel] == 0 )
      {
 #if defined (SM_ENABLE_TRANSMISSION_HANDLING)
 # if defined ( SM_ENABLE_DYNAMIC_TX )
         SmAssert ( (bSmInmMsgHandle[sm_channel] < kCanNumberOfTxObjects), kTxHandleOutOfRange );
         CanTransmit (bSmInmMsgHandle[sm_channel]);
 # else
         SmAssert ( (SmMsgHandle[SmIdentity(sm_channel)] < kCanNumberOfTxObjects), kTxHandleOutOfRange );
         /* send indirect OSEK network management messages immediately */
         (void)CanTransmit (SmMsgHandle[SmIdentity(sm_channel)]);
 # endif 
         /* ESCAN00022994: clear eventTriggerIndication (valid for normal or dynamic TX */
         bSmTxEventTrigger[sm_channel] = 0;
 #endif

 #if defined ( SM_ENABLE_DYNAMIC_TX )
          wSmInmMsgCycCntr[sm_channel]  = bSmInmMsgTime[sm_channel];
 #else
          /* set indirect OSEK network management time distance counter (initially) */
          wSmInmMsgCycCntr[sm_channel]  = SmMsgTime[SmIdentity(sm_channel)];
 #endif
 
          if(wSmTxToCycCntr[sm_channel] == 0 )
          {
            /* set ECU Tx timeout counter (once again) */
              wSmTxToCycCntr[sm_channel]  = SmMsgTimeoutTime[SmIdentity(sm_channel)];
          }
      }
  }
}



/******************************************************************************
* NAME:               SmTask 
* Preconditions:      initialization of station manager
* PARAMETER:          none
* RETURN VALUE:       none
* Description:        The complete polling handling is done by the main task
*                     of the station manager:
*                     a) network state transitions by slave/master ECU
*                     b) diagnostic handling for (non-)volatile counters
*                     c) Tx and Rx timeout observation
*                     d) different BusOff recovery algorithms (MEDIUM, SLOW)
*                     e) wakeup request to force state "MODE NORMAL"
*******************************************************************************/
void SmTask(SM_CHANNEL_TYPE_ONLY)
{
  SmWakeUpTask(SM_CHANNEL_PARA_ONLY);
#if defined ( SM_ENABLE_POLLING_MODE ) 
  /* transition between different network states (PHASES VIE RESEAU) */
  SmNetworkTask(SM_CHANNEL_PARA_ONLY);
#endif

  /* ESCAN00030088 */
  SmDiagTask(SM_CHANNEL_PARA_ONLY);

  SmSupervisionTask(SM_CHANNEL_PARA_ONLY);
  /* handling of (non-)volatile error counters (ABSENT, MUTE and BUSOFF) */

  SmTimeoutTask(SM_CHANNEL_PARA_ONLY);

  SmBusOffTask(SM_CHANNEL_PARA_ONLY);

  SmTxTask(SM_CHANNEL_PARA_ONLY);

#if defined (SM_ENABLE_NAS_SUPERVISION)
  ApplCancelTask();
#endif
}


/******************************************************************************
* NAME:               SmCanNerrAccess 
* CALLED BY:          Generic Precopy
* Preconditions:      enabled CAN (Rx) interrupts
* PARAMETER:          new ECU state
* RETURN VALUE:       none
* Description:        Checks State of Nerr Pin on reception of 
*                     Commande_bsi. (ONLY PSA!)
*******************************************************************************/
static void SmCanNerrAccess( SM_CHANNEL_TYPE_FIRST vuint8 newState ) 
{
#if ( kCanNumberOfChannels >1 )
  CanChannelHandle can_channel = SmSmToCanChannel[sm_channel];
#endif

# if ( defined V_ENABLE_USE_DUMMY_STATEMENT )
  newState = newState;
# endif

  /* No Bus Off pending or timer expired? */
  if( !bSmBusOffCycCntr[sm_channel] )
  {

    /* Clear confirmed PerteCom flag */
    bSmConfPerteCom[sm_channel] = 0;

    SmSetExtECUState( sm_channel, newState );


    /* BusOff Pending? Set Flag to call CanOnline() in Networktask */
    if( (bSmBusOffRecCntr[sm_channel] & kSmBoffIndication) != 0 )
    {
      bSmCmdBSIReceived[sm_channel] = 1;
    }

#  if defined (SM_ECU_TYPE_ACTIVATION )
    /* communication is back */
    /* clear Tveille counter */
    wSmTveilleCntr[sm_channel] = 0;
    if( wSmToffCntr[sm_channel] != 0 )
    {
      /* Commande_BSI received, Cancel Toff Timer */
      wSmToffCntr[sm_channel] = 0;
      /* restart surveillance of Commande_BSI */
      wSmRxToCycCntr[SmMasterIndex(sm_channel)] = SmRxTimeoutValue[SmMasterIndex(sm_channel)];
#if defined SM_ENABLE_ADDITIONAL_SUPERVISION
      bSmAddRxTCntr[sm_channel] = SmAddRxTimeout[sm_channel];
#endif
    }
# endif
      
# if defined ( SM_ENABLE_POLLING_MODE )
#else
    /* Call Networktask */
    SmNetworkTask(SM_CHANNEL_PARA_ONLY);
# endif
  }
}

/******************************************************************************
* NAME:               SmRxTimeoutSupervision 
* CALLED BY:          Sm
* Preconditions:      enabled CAN (Rx) interrupts
* PARAMETER:          (channel),index of supervised ECU
* RETURN VALUE:       none
* Description:        A Rx message of each other slave ECU has to received within
*                     a defined timeout time. Otherwise the (non-volatile) error
*                     counters (for "ABSENT") have to be increased.
*******************************************************************************/
static void SmRxTimeoutSupervision(SM_CHANNEL_TYPE_FIRST inmNmIndexType bEcuNr)
{
    /* check ECU number (array index) for Rx supervision */
    SmAssert( (bEcuNr < SM_NUMOFALLRXNODES), kWrongRxToIndex);

    if ( SmGetInterdMemoDef(SM_CHANNEL_PARA_ONLY) == 0 )
    {
        /* notify indirect OSEK network management of successful Rx message reception */
       InmNmRxOk(bEcuNr);
    }

    /* reload timer only if it is not stopped */
    if( wSmRxToCycCntr[bEcuNr] != 0 )
    {
        /* set ECU Rx timeout counter (once again) */
        wSmRxToCycCntr[bEcuNr] = SmRxTimeoutValue [bEcuNr];
    }

    if(bEcuNr == SmMasterIndex(sm_channel) )
    {
        /* Commmande_BSI received */
        /* Nerr Pin validation */
        if( SmGetInterdMemoDef(SM_CHANNEL_PARA_ONLY) == 0 )
        {
            /* status of NERR pin (transceiver TJA1053/TJA1054) */
            if( bSmNerrPinState[sm_channel] != 0 )
            {
               InmNmGenericTimeOut(SM_CHANNEL_PARA_ONLY);
            }
            else
            {
               InmNmGenericOk(SM_CHANNEL_PARA_ONLY);
            }
        }
    }
}


/******************************************************************************
* NAME:               SmTxTimeoutSupervision 
* CALLED BY:          CAN driver (specific confirmation function)
* Preconditions:      enabled CAN (Tx) interrupts
* PARAMETER:          none
* RETURN VALUE:       none
* Description:        A Tx message of the own slave ECU has to received within
*                     a defined timeout time. Otherwise the (non-volatile) error
*                     counter (for "MUTE") has to be increased.
*******************************************************************************/
void SmTxTimeoutSupervision(CanTransmitHandle txObject)
{
#if defined ( SM_ENABLE_DYNAMIC_TX )
#else
#if ( SM_CHANNELS>1)
    CanChannelHandle sm_channel;
    sm_channel = CanGetChannelOfTxObj(txObject);
#endif
#if defined V_ENABLE_USE_DUMMY_STATEMENT
    (void)txObject;  /* PRQA S 3112 */ /* MD_NmStMgrLs_3112 */
#endif
    /* set confirmation flag */
    bSmTxConfirmationFlag[sm_channel] = 1;
#endif
}


/******************************************************************************
* NAME:               SmTxConfirmation 
* CALLED BY:          SmSupervisionTask
* Preconditions:      Sm started
* PARAMETER:          none
* RETURN VALUE:       none
* Description:        A Tx message of the own slave ECU has to received within
*                     a defined timeout time. Otherwise the (non-volatile) error
*                     counter (for "MUTE") has to be increased.
*******************************************************************************/
static void SmTxConfirmation(SM_CHANNEL_TYPE_ONLY)
{
  if (SmGetInterdMemoDef(SM_CHANNEL_PARA_ONLY) == 0 )
  {
      /* notify indirect OSEK network management of successful Tx message transmission */ 
      InmNmTxOk(SM_CHANNEL_PARA_ONLY);
  }

  /* clear ECU Tx timeout counter (once again) */
  wSmTxToCycCntr[sm_channel]  = 0;
}

/******************************************************************************
* NAME:               SmPrecopy
* CALLED BY:          CAN driver (specific precopy function)
* Preconditions:      enabled CAN (Rx) interrupts
* PARAMETER:          none
* RETURN VALUE:       kCan
* Description:        
*******************************************************************************/
#if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) || defined ( C_SINGLE_RECEIVE_CHANNEL )
void SmPrecopy( CanRxInfoStructPtr rxStruct  )  /* PRQA S 3673 */ /* MD_StMgr_3673 */
{
#else
  #error "StatMgrIndOsek: Only C_MULTIPLE_RECEIVE_CHANNEL and C_SINGLE_RECEIVE_CHANNEL are supported."
#endif

#if ( SM_CHANNELS > 1 )
  CanChannelHandle sm_channel = SmCanToSmChannel[rxStruct->Channel];
#endif
    
  if( (rxStruct->Handle) == SmRxHdlNmCmdMsg[SmIdentity(sm_channel)])
  {                
    bSmNerrPinState[sm_channel] = ApplCanErrorPin(SM_CHANNEL_PARA_ONLY);

    /* DiagMuxFlag */
    if ( NmSmLsGetDiagMuxFromNmCmdMsg() == kSmDiagMuxEnable )
    {
      /* Set external Diagnosis State */
      SmSetExtDiagState( sm_channel, 1);
    }
    else
    {
      SmSetExtDiagState( sm_channel, 0);
    }

    /* Phases_de_vie signal */
    SmCanNerrAccess(SM_CHANNEL_PARA_FIRST NmSmLsGetModeFromNmCmdMsg());

  } /* MasterCmdMsg */

  if( SmGetECUindex(rxStruct->Handle) != 0xff )
  {
    baSmRxIndicationFlags[SmGetECUindex(rxStruct->Handle)] = 1;
  }
#if defined SM_ENABLE_ADDITIONAL_SUPERVISION
  if( (rxStruct->Handle) == SmAddRxHandle[sm_channel] )
  {
    bSmAddRxInidcationFlag[sm_channel]=1;
  }
#endif
}


/******************************************************************************
* NAME:               NmCanError 
* CALLED BY:          CAN driver (BusOff interrupt) 
* Preconditions:      enabled CAN (Error) interrupts
* PARAMETER:          none
* RETURN VALUE:       none
* Description:        A transition from "ERROR ACTIVE/ERROR PASSIVE" to "BUSOFF"
*                     is detected by the CAN controller. The code duplicated
*                     function "NmCanError " is adapted to the code indexed
*                     function "InmNmBusOff ".
*******************************************************************************/
void NmCanError (SM_CAN_CHANNEL_TYPE_ONLY)
{
#if ( kCanNumberOfChannels > 1)
#  if (SM_CHANNELS > 1 )
  inmNmChannelType sm_channel = SmCanToSmChannel[can_channel];
#  endif
#endif
    
  bSmCBusOff[sm_channel]++;
  /* stop 1000ms timer to reset recovery algorithm */
  bSmBusOffOnlineCntr[sm_channel] = 0;

  SmBusOffInitCan(SM_CHANNEL_PARA_ONLY);
}
/******************************************************************************
* NAME:               SmBusOffInitCan
* CALLED BY:          Station manager
* Preconditions:      none
* PARAMETER:          channel 
* RETURN VALUE:       none
* Description:        Depending on the amount of repeated BusOffs (without any
*                     successful transmission or reception of messages) different
*                     recovery algorithms (FAST,  SLOW). Send messages
*                     are suppressed by the online/offline mechanism of the
*                     CAN driver whereas receive messages are handled furthermore.
*                     The application is notified on begin ("ApplNwmBusOff ")
*                     and end ("ApplNwmBusOffEnd ").
*******************************************************************************/
static void SmBusOffInitCan(SM_CHANNEL_TYPE_ONLY)
{ 
# if (kCanNumberOfChannels >1 )
  CanChannelHandle can_channel = SmSmToCanChannel[sm_channel];
# endif
  /* switch off CAN driver completely */
  CanOffline(SM_CAN_CHANNEL_PARA_ONLY);

  /* in case of BusOff, no Timeoutsupervision */ 
  SmDiagOff(SM_CHANNEL_PARA_ONLY);

   /* start of busoff handling */
# if (kCanNumberOfChannels >1 )
    CanResetBusOffStart( can_channel, kNmSmLsNmInitObj);
# else
    CanResetBusOffStart(kNmSmLsNmInitObj );
# endif
    
# if defined(SM_ENABLE_BUSOFF_FCT )
    /* notify on begin of BusOff recovery algorithm */
      ApplNwmBusoff(SM_CHANNEL_PARA_ONLY);
# endif
    /* end of busoff handling */
# if (kCanNumberOfChannels >1 )
    CanResetBusOffEnd( can_channel, kNmSmLsNmInitObj);
# else
    CanResetBusOffEnd( kNmSmLsNmInitObj );
# endif
  /* fast recovery algorithm for repeated BusOff */
  /* mask Indication and r.Boff bit */
  if( (bSmBusOffRecCntr[sm_channel] & 0x3f) < SM_FAST_BUS_OFF_REC_COUNT  )
  {
    /* increment BusOff recovery counter */
    bSmBusOffRecCntr[sm_channel] ++;
    /* set bus Off Indication Bit */
    bSmBusOffRecCntr[sm_channel] |= kSmBoffIndication;
# if defined(SM_ENABLE_BUSOFF_END_FCT )
    /* notify on end of BusOff recovery algorithm */
    ApplNwmBusoffEnd(SM_CHANNEL_PARA_ONLY);
# endif
  }
  /* slow recovery algorithm for repeated BusOff */
  else
  {
# if defined ( C_ENABLE_STOP )
    /* Stop Candriver */
#  if (kCanNumberOfChannels >1 )
    (void) CanStop( can_channel );
#  else
    (void) CanStop();
#  endif
# endif
    /* set BusOff time distance counter */    
    bSmBusOffCycCntr[sm_channel]  = (vuint8)SM_SLOW_REC_TIME;
  }
}

/******************************************************************************
* NAME:               SmResetSupervision
* CALLED BY:          Application
* Preconditions:      initialization of station manager
* PARAMETER:          (channel),  
* RETURN VALUE:       none
* Description:        On request of the diagnostic tool supervision is reset
*                     Counters and states are reset and supervision is activated
*******************************************************************************/

void SmResetSupervision(SM_CHANNEL_TYPE_ONLY)
{
    vuint8 bDiagMuxState;
    inmNmConditionType *pXXCondition;
    inmNmIndexType index;
    bDiagMuxState = 0;

    /* check if ECU was confirmed PerteCom */
    pXXCondition = InmNmGetRxCondition( SmMasterIndex(sm_channel));
    if( (pXXCondition->status &( INM_FAILURE |INM_STAT_FAILURE)) == (INM_FAILURE | INM_STAT_FAILURE))
    {
        bDiagMuxState = 1;
    }

    for( index=InmRxMsgStartIndex[sm_channel]; index<InmRxMsgStartIndex[sm_channel+1]; index++ )
    {
        pXXCondition = InmNmGetRxCondition(index);  
        pXXCondition->counter = 0;
        pXXCondition->status  |=  INM_CONFIRMED;
        pXXCondition->status  &= (vuint8)~(vuintx)(INM_FAILURE|INM_STAT_CHANGE|INM_STAT_FAILURE);
#if defined( SM_ENABLE_STATUS_CB )
        ApplSmStatusIndicationRx (index, INM_CONFIRMED_OK );
#endif
#if defined( SM_ENABLE_FAULTSTOR) 
         /* set NV counter to 0 */
        ApplSmSetNVAbsentCount(index, 0);
#endif
    }

    /* TX */
    pXXCondition = InmNmGetTxCondition(SM_CHANNEL_PARA_ONLY);
    pXXCondition->counter = 0;
    pXXCondition->status  |=  INM_CONFIRMED;
    pXXCondition->status  &= (vuint8)~(vuintx)(INM_FAILURE|INM_STAT_CHANGE|INM_STAT_FAILURE);

    /* Nerr */
    pXXCondition = InmNmGetGenericCondition(SM_CHANNEL_PARA_ONLY);
    pXXCondition->counter = 0;
    pXXCondition->status  |=  INM_CONFIRMED;
    pXXCondition->status  &= (vuint8)~(vuintx)(INM_FAILURE|INM_STAT_CHANGE|INM_STAT_FAILURE);

#if defined( SM_ENABLE_STATUS_CB )
    ApplSmStatusIndicationTx (SM_CHANNEL_PARA_FIRST INM_CONFIRMED_OK);
    ApplSmStatusIndicationNerr (SM_CHANNEL_PARA_FIRST INM_CONFIRMED_OK);
#endif
#if defined( SM_ENABLE_FAULTSTOR) 
     /* set NV counter to 0 */
     ApplSmSetNVMuteCount(SM_CHANNEL_PARA_FIRST 0);
     ApplSmSetNVNerrCount(SM_CHANNEL_PARA_FIRST 0);
#endif

    if ( bDiagMuxState == 1 ) 
    {
        SmDiagOn(SM_CHANNEL_PARA_ONLY);
    }

}


/* callback functions *********************************************************/


/******************************************************************************
* NAME:               ApplInmNmRxUserInit
* CALLED BY:          indirect OSEK network management
* Preconditions:      none (=> callback function)
* PARAMETER:          index, poointer to condition-struct 
* RETURN VALUE:       none
* Description:        Intitialize the volatile counter depending on the 
*                     non volatile state
*******************************************************************************/
void ApplInmNmRxUserInit( inmNmIndexType index, inmNmConditionType * pRxCondition )
{
#if defined( SM_ENABLE_FAULTSTOR)
    if( ApplSmGetNVAbsentCount(index) != 0 )
    {
        pRxCondition->counter = 255;
        pRxCondition->status = (INM_CONFIRMED_FAILURE|INM_STAT_FAILURE);
    }
    else
#endif
    {
        pRxCondition->counter = 0;
        pRxCondition->status = INM_CONFIRMED_OK;
    }
  #if defined( SM_ENABLE_FAULTSTOR)
  #else
    #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
    (void)index; /* PRQA S 3112 */ /* MD_NmStMgrLs_3112 */
    #endif
  #endif
}
/******************************************************************************
* NAME:               ApplInmNmRxUserReInit
* CALLED BY:          indirect OSEK network management
* Preconditions:      none (=> callback function)
* PARAMETER:          index, poointer to condition-struct 
* RETURN VALUE:       none
* Description:        Intitialize the volatile counter depending on the 
*                     non volatile state
*******************************************************************************/
void ApplInmNmRxUserReInit( inmNmIndexType index, inmNmConditionType * pRxCondition)
{
#if defined( SM_ENABLE_FAULTSTOR)
    if( ApplSmGetNVAbsentCount(index) != 0 )
    {
        pRxCondition->counter = 255;
        pRxCondition->status  |= (INM_CONFIRMED_FAILURE|INM_STAT_FAILURE);
        pRxCondition->status  &= (inmNmStatusType)(~((vuintx)(INM_STAT_CHANGE)));
    }
#else
    if( (pRxCondition->status & INM_STAT_FAILURE) != 0 )
    {
        pRxCondition->counter = 255;
        pRxCondition->status  |= (INM_CONFIRMED_FAILURE|INM_STAT_FAILURE);
        pRxCondition->status  &= (vuint8)~(vuintx)(INM_STAT_CHANGE);

    }
#endif
    else
    {
        pRxCondition->counter = 0;
        pRxCondition->status  |=  INM_CONFIRMED;
        pRxCondition->status  &= (vuint8)~(vuintx)(INM_FAILURE|INM_STAT_CHANGE);
    }
  #if defined( SM_ENABLE_FAULTSTOR)
  #else
    #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
    (void)index;  /* PRQA S 3112 */ /* MD_NmStMgrLs_3112 */
    #endif
  #endif
}
/******************************************************************************
* NAME:               ApplInmNmTxUserInit
* CALLED BY:          indirect OSEK network management
* Preconditions:      none (=> callback function)
* PARAMETER:          index, poointer to condition-struct 
* RETURN VALUE:       none
* Description:        Intitialize the volatile counter depending on the 
*                     non volatile state
*******************************************************************************/
void ApplInmNmTxUserInit( SM_CHANNEL_TYPE_FIRST inmNmConditionType * pTxCondition)
{
#if defined( SM_ENABLE_FAULTSTOR)
    if( ApplSmGetNVMuteCount(SM_CHANNEL_PARA_ONLY) != 0 )
    {
        pTxCondition->counter = 255;
        pTxCondition->status  = (INM_CONFIRMED_FAILURE|INM_STAT_FAILURE);
    }
    else
#endif
    {
        pTxCondition->counter = 0;
        pTxCondition->status = INM_CONFIRMED_OK;
    }
}
/******************************************************************************
* NAME:               ApplInmNmTxUserReInit
* CALLED BY:          indirect OSEK network management
* Preconditions:      none (=> callback function)
* PARAMETER:          channel, pointer to condition-struct 
* RETURN VALUE:       none
* Description:        Intitialize the volatile counter depending on the 
*                     non volatile state
*******************************************************************************/
void ApplInmNmTxUserReInit(SM_CHANNEL_TYPE_FIRST  inmNmConditionType * pTxCondition)
{
  #if defined( SM_ENABLE_FAULTSTOR)
    if( ApplSmGetNVMuteCount(SM_CHANNEL_PARA_ONLY) != 0 )
    {
        pTxCondition->counter = 255;
        pTxCondition->status  |= (INM_CONFIRMED_FAILURE|INM_STAT_FAILURE);
        pTxCondition->status  &= (inmNmStatusType)(~((vuintx)(INM_STAT_CHANGE)));
    }
  #else
    if( (pTxCondition->status & INM_STAT_FAILURE) != 0 )
    {
        pTxCondition->counter = 255;
        pTxCondition->status  |= (INM_CONFIRMED_FAILURE|INM_STAT_FAILURE);
        pTxCondition->status  &= (vuint8)~(vuintx)(INM_STAT_CHANGE);
     }
#endif
    else
    {
        pTxCondition->counter = 0;
        pTxCondition->status  |=  INM_CONFIRMED;
        pTxCondition->status  &= (vuint8)~(vuintx)(INM_FAILURE|INM_STAT_CHANGE);
    }
}


/******************************************************************************
* NAME:               ApplInmNmGenericUserInit
* CALLED BY:          indirect OSEK network management
* Preconditions:      none (=> callback function)
* PARAMETER:          channel, pointer to condition-struct 
* RETURN VALUE:       none
* Description:        Intitialize the volatile counter depending on the 
*                     non volatile state
*******************************************************************************/
void ApplInmNmGenericUserInit(INM_CHANNEL_TYPE_FIRST inmNmConditionType * pNerrCondition)
{
#if defined( SM_ENABLE_FAULTSTOR)
    if( ApplSmGetNVNerrCount(SM_CHANNEL_PARA_ONLY) != 0 )
    {
        pNerrCondition->counter = 255;
        pNerrCondition->status = (INM_CONFIRMED_FAILURE|INM_STAT_FAILURE);
    }
    else
#endif
    {
        pNerrCondition->counter = 0;
        pNerrCondition->status = INM_CONFIRMED_OK;
    }
}


/******************************************************************************
* NAME:               ApplInmNmGenericUserReInit
* CALLED BY:          indirect OSEK network management
* Preconditions:      none (=> callback function)
* PARAMETER:          channel, pointer to condition-struct 
* RETURN VALUE:       none
* Description:        Intitialize the volatile counter depending on the 
*                     non volatile state
*******************************************************************************/
void ApplInmNmGenericUserReInit(INM_CHANNEL_TYPE_FIRST inmNmConditionType * pNerrCondition)
{
#if defined( SM_ENABLE_FAULTSTOR)
    if( ApplSmGetNVNerrCount(SM_CHANNEL_PARA_ONLY) != 0 )
    {
        pNerrCondition->counter = 255;
        pNerrCondition->status |= (INM_CONFIRMED_FAILURE|INM_STAT_FAILURE);
        pNerrCondition->status  &= (inmNmStatusType)(~((vuintx)(INM_STAT_CHANGE)));
    }
#else
    if( (pNerrCondition->status & INM_STAT_FAILURE ) != 0 )
    {
        pNerrCondition->counter = 255;
        pNerrCondition->status |= (INM_CONFIRMED_FAILURE|INM_STAT_FAILURE);
        pNerrCondition->status  &= (vuint8)~(vuintx)(INM_STAT_CHANGE);
    }
#endif
    else
    {
        pNerrCondition->counter = 0;
        pNerrCondition->status |=  INM_CONFIRMED;
        pNerrCondition->status &= (vuint8)~(vuintx)(INM_FAILURE|INM_STAT_CHANGE);
    }
}


/******************************************************************************
* NAME:               ApplInmNmStartCanIl
* CALLED BY:          indirect OSEK network management
* Preconditions:      none (=> callback function)
* PARAMETER:          channel 
* RETURN VALUE:       none
* Description:        If the indirect OSEK network management and the station
*                     manager is started by the service function
*                     "SmSetWakeUpRequest", the CAN transceiver is set to
*                     NORMAL mode before CAN driver and CAN message handler
*                     are activated.
*******************************************************************************/
void ApplInmNmStartCanIl(SM_CHANNEL_TYPE_ONLY)
{
  /*
  The Tx path of CAN message handler is started seperately 
  by the station manager, whereas the Rx path is started within the
  following transceiver handling by the CAN I/O subsystem itself.
  The Tx path of CAN driver is also set to online.
  */
  /* switch on CAN transceiver TJA1053/TJA1054 */
  ApplSmTrcvOn(SM_CHANNEL_PARA_ONLY);
}

/******************************************************************************
* NAME:               ApplInmNmStopCanIl
* CALLED BY:          indirect OSEK network management
* Preconditions:      none (=> callback function)
* PARAMETER:          channel 
* RETURN VALUE:       none
* Description:        If the indirect OSEK network management and the station
*                     manager is stopped the CAN transceiver is set to SLEEP mode after
*                     CAN message handler and CAN driver are deactivated.
*******************************************************************************/
void ApplInmNmStopCanIl(SM_CHANNEL_TYPE_ONLY)
{
#if (kCanNumberOfChannels >1 )
    CanChannelHandle can_channel = SmSmToCanChannel[sm_channel];
#endif

  /* switch physical layer offline */
  CanOffline( SM_CAN_CHANNEL_PARA_ONLY ); 

  #if (kCanNumberOfChannels >1 )
  CanResetBusSleep( can_channel, kNmSmLsNmInitObj);
  #else
  CanResetBusSleep( kNmSmLsNmInitObj );
  #endif

  /* switch off CAN transceiver TJA1053/TJA1054 */
  ApplSmTrcvOff(SM_CHANNEL_PARA_ONLY);
}



/******************************************************************************
* NAME:               ApplInmNmStatusIndicationRx
* CALLED BY:          indirect OSEK network management
* Preconditions:      none (=> callback function)
* PARAMETER:          - index (ECU handle)
*                     - status (OK, FAILURE or CONFIRMED FAILURE)
* RETURN VALUE:       none
* Description:        The application is notified on a status change of
*                     the Rx information (OK, FAILURE or CONFIRMED FAILURE) of
*                     observed master ECU and other slave ECUs (receive
*                     messages) by function "ApplSmStatusIndicationRx ".
*******************************************************************************/
void ApplInmNmStatusIndicationRx( inmNmIndexType index, inmNmStatusType status)
{
#if (SM_CHANNELS > 1 )
  inmNmChannelType sm_channel;
  sm_channel = InmIndexToChannel[index];
#endif 

  /* check index to access ECU information */
  SmAssert ( (index<SM_NUMOFALLRXNODES), kWrongIndRxIndex);

#if defined( SM_ENABLE_FAULTSTOR) 
   if( (status & INM_STAT_CHANGE) != 0 )
    {
      /* => store information in non-volatile memory */
      if( (status & INM_STAT_FAILURE) != 0 )
      {
        /* set NV counter to Max */
        ApplSmSetNVAbsentCount(index, 1); 
      }
      else
      {
        /* confirmed present */
        /* set NV counter to 0 */
        ApplSmSetNVAbsentCount(index, 0);
      }
    }
#endif

  
  if( (status & ( INM_FAILURE |INM_STAT_FAILURE)) == (INM_FAILURE | INM_STAT_FAILURE) )
  {
    if(index == SmMasterIndex(sm_channel))
    {  
         /* Stop Diagnosis if confirmed failure of BSI */ 
         bSmConfPerteCom[sm_channel] = 1;
    }
  }

#if defined( SM_ENABLE_STATUS_CB )
  /* status indication of Rx timeout (information ABSENT) */
 # if defined ( SM_ENABLE_MULTIPLE_NODES )
  if((inmRxCondition[index].status & SM_ECU_VALID ) != 0 )
 #endif
  {
 
 #if defined ( SM_ENABLE_UNCONDITIONAL_STATUS_CB )
 /* ESCAN00032166 */
 #else
    if ( (status & (INM_FAILURE|INM_CONFIRMED)) != 0 )
 #endif
    {
        ApplSmStatusIndicationRx (index, (status & (INM_FAILURE|INM_CONFIRMED_FAILURE)) );
    }
  }
#endif
}

/******************************************************************************
* NAME:               ApplInmNmStatusIndicationTx
* CALLED BY:          indirect OSEK network management
* Preconditions:      none (=> callback function)
* PARAMETER:          - channel 
*                     - status (OK, FAILURE or CONFIRMED FAILURE)
* RETURN VALUE:       none
* Description:        The application is notified on a status change of
*                     the Tx information (OK, FAILURE or CONFIRMED FAILURE) of
*                     observed own slave ECU (send message) by function
*                     "ApplSmStatusIndicationTx ".
*******************************************************************************/
void ApplInmNmStatusIndicationTx(SM_CHANNEL_TYPE_FIRST inmNmStatusType status)
{

#if defined( SM_ENABLE_FAULTSTOR) 
    if( (status & INM_STAT_CHANGE) != 0 )
    {
      /* => store information in non-volatile memory */
      if( (status & INM_STAT_FAILURE) != 0 )
      {
        /* set NV counter to Max */
        ApplSmSetNVMuteCount(SM_CHANNEL_PARA_FIRST 1); 
      }
      else
      {
        /* confirmed present */
        /* set NV counter to 0 */
        ApplSmSetNVMuteCount(SM_CHANNEL_PARA_FIRST 0);
      }
    }
#endif

#if defined ( SM_ENABLE_STATUS_CB)
 #if defined ( SM_ENABLE_UNCONDITIONAL_STATUS_CB )
    /* ESCAN00032166 */
 #else
    if ( (status & (INM_FAILURE|INM_CONFIRMED)) != 0 )
 #endif
    {
      /* status indication of Tx timeout (information MUTE) */
      ApplSmStatusIndicationTx(SM_CHANNEL_PARA_FIRST (status & INM_CONFIRMED_FAILURE));
    }
#else
 #if (SM_CHANNELS > 1 )
   #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
    (void)sm_channel;  /* PRQA S 3112 */ /* MD_NmStMgrLs_3112 */
   #endif
 #endif
 #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
    (void)status;  /* PRQA S 3112 */ /* MD_NmStMgrLs_3112 */
 #endif
#endif /* #if defined( SM_ENABLE_STATUS_CB  ) */
}


/******************************************************************************
* NAME:               ApplInmNmStatusIndicationGeneric
* CALLED BY:          indirect OSEK network management
* Preconditions:      none (=> callback function)
* PARAMETER:          - channel 
*                     - status (OK, FAILURE or CONFIRMED FAILURE)
* RETURN VALUE:       none
* Description:        The application is notified on a status change of
*                     the Nerr information (OK, FAILURE or CONFIRMED FAILURE)
*******************************************************************************/
void ApplInmNmStatusIndicationGeneric(INM_CHANNEL_TYPE_FIRST inmNmStatusType status)
{

 #if defined( SM_ENABLE_FAULTSTOR) 
   if( (status & INM_STAT_CHANGE) != 0 )
    {
      /* => store information in non-volatile memory */
      if( (status & INM_STAT_FAILURE) != 0 )
      {
        /* set NV counter to Max */
        ApplSmSetNVNerrCount(INM_CHANNEL_PARA_FIRST 1); 
      }
      else
      {
        /* confirmed present */
        /* set NV counter to 0 */
        ApplSmSetNVNerrCount(INM_CHANNEL_PARA_FIRST 0);
      }
    }
#endif

#if defined( SM_ENABLE_STATUS_CB)
 #if defined ( SM_ENABLE_UNCONDITIONAL_STATUS_CB )
 /* ESCAN00032166 */
 #else
  if ( (status & (INM_FAILURE|INM_CONFIRMED)) != 0 )
 #endif
  {
    /* status indication of Tx timeout (information MUTE) */
    ApplSmStatusIndicationNerr(INM_CHANNEL_PARA_FIRST (status & INM_CONFIRMED_FAILURE));
  }
#else
 #if (SM_CHANNELS > 1 )
  (void)channel;  /* PRQA S 3112 */ /* MD_NmStMgrLs_3112 */
 #endif 
  (void)status;  /* PRQA S 3112 */ /* MD_NmStMgrLs_3112 */
#endif /* #if defined( SM_ENABLE_STATUS_CB  ) */
}

#if defined (SM_ENABLE_NAS_SUPERVISION )
/* TxObserve */
  #if defined C_ENABLE_TX_OBSERVE

/******************************************************************************
* NAME:               ApplCanTxObjStart
* CALLED BY:          CAN driver
* Preconditions:      none (=> callback function)
* PARAMETER:          - channel 
*                     - Tx Object
* RETURN VALUE:       none
* Description:        Notification about Transmission start
*******************************************************************************/
void ApplCanTxObjStart( CAN_CHANNEL_CANTYPE_FIRST CanObjectHandle txHwObject )
{
#if defined ( SM_ECU_TYPE_ACTIVATION )
    /* check if in active WakeUp-> no supervision */
    if( bSmActiveWakeUp[SmCanToSmChannel[can_channel]] == 0 ) 
#endif
    {
        bNasTimeout[txHwObject] = SM_NAS_TIME;
        bActHandle[txHwObject] = CanTxGetActHandle(txHwObject);
        bNasCounter ++;
    }
}
/******************************************************************************
* NAME:               ApplCanTxObjConfirmed
* CALLED BY:          CAN driver
* Preconditions:      none (=> callback function)
* PARAMETER:          - channel 
*                     - Tx Object
* RETURN VALUE:       none
* Description:        Notification about successful transmission
*******************************************************************************/
void ApplCanTxObjConfirmed(CAN_CHANNEL_CANTYPE_FIRST CanObjectHandle txHwObject )
{
#if defined ( SM_ECU_TYPE_ACTIVATION )
    if( bSmActiveWakeUp[SmCanToSmChannel[can_channel]] == 0 ) 
#endif
    {
        bNasTimeout[txHwObject] = 0;
        /* ESCAN00025824 (check removed) */
        bNasCounter--;   
    }
#if defined ( SM_ECU_TYPE_ACTIVATION )
    else
    {
        /* clear flag on first confirmation */
        bSmActiveWakeUp[SmCanToSmChannel[can_channel]] = 0;
    }
#endif
}
/******************************************************************************
* NAME:               ApplCanInit
* CALLED BY:          CAN driver
* Preconditions:      none (=> callback function)
* PARAMETER:          - channel 
*                     - Tx Object
* RETURN VALUE:       none
* Description:        Notification about reinit of CAN driver
*******************************************************************************/
void ApplCanInit( CAN_CHANNEL_CANTYPE_FIRST CanObjectHandle txHwObjectFirstUsed, CanObjectHandle txHwObjectFirstUnused)
{
    vuint16 i;
    for(i=txHwObjectFirstUsed; i<txHwObjectFirstUnused;i++)
    {
        bNasTimeout[i] = 0;
    }
#if defined ( SM_ECU_TYPE_ACTIVATION )
    /* clear flag on first confirmation */
    bSmActiveWakeUp[SmCanToSmChannel[can_channel]] = 0;
#endif
}
/*******************************************************************************
* NAME          : ApplCancelTask
* CALLED BY     : Stationmanager
* PRECONDITIONS : none
* PARAMETERS    : none
* RETURN VALUE  : none
********************************************************************************/
static void ApplCancelTask(void)
{
    vuint8 i;
    for (i=0;i<kCanNumberOfUsedTxCANObjects;i++)
    {
        if( bNasTimeout[i] != 0 )
        {
            bNasTimeout[i]--;
            if( bNasTimeout[i] == 0)
            {
                CanCancelTransmit( bActHandle[i] );
            }
        }
    }
}

/******************************************************************************
* NAME:               SmTxPreTransmitNas
* CALLED BY:          CAN driver
* Preconditions:      none ( Pretransmit function )
* PARAMETER:          - CanTxInfoStruct /  CanChipDataPtr
* RETURN VALUE:       kCanCopyData
* Description:        write the value of the bNasCounter to signal N_as counter
*******************************************************************************/
#if defined(C_MULTIPLE_RECEIVE_CHANNEL) || defined(C_SINGLE_RECEIVE_CHANNEL)
vuint8 SmTxPreTransmitNas(CanTxInfoStruct ctis)
{
  #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
    (void)ctis; /* PRQA S 3112 */ /* MD_NmStMgrLs_3112 */
  #endif
#else
vuint8 SmTxPreTransmitNas(CanChipDataPtr txObject);
{
  #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
    (void)txObject; /* PRQA S 3112 */ /* MD_NmStMgrLs_3112 */
  #endif
#endif
    /* write N_as value */
    SmNasCounter(bNasCounter);
    return kCanCopyData;
}

  #else  /* #if defined C_ENABLE_TX_OBSERVE */
   #error Enable Tx observe in CAN driver configuration
  #endif
#endif  /* #if defined (SM_ENABLE_NAS_SUPERVISION ) */


/* module specific MISRA deviations:
   MD_NmStMgrLs_0883:
     Reason:     The filter comment is encapsulated by preprocessor defines outside the multiple include protection.
     Risk:       There is no risk as this warning occurs only if singlesource files are used.
     Prevention: Do not use singlesource files for delivery.
   MD_NmStMgrLs_3112:
     Reason: Dummy statement to avoid compiler warnings
     Risk: There is no risk as such statements have no effect on the code.
     Prevention: Cover by code review
   MD_NmStMgrLs_3453:
     Reason:     A function-like macro is used instead of function. The macros cover no code statements but only value calculation.
     Risk:       Content of macro is hidden.
     Prevention: Covered by code review.
   MD_NmStMgrLs_3673:
     Reason:     This rule affects a callback function from another module.
     Risk:       Parameter is not defined as const and could be modified within this function.
     Prevention: The parameter is not modified. Covered by code review.
*/

/**********************************************************************************************************************
  EOF
**********************************************************************************************************************/
