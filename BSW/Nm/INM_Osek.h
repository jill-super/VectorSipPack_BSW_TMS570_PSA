/* ORGANI: STARTSINGLE_OF_MULTIPLE */


/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  Copyright (c) 2007 by Vector Informatik GmbH.                                                  All rights reserved.
 
                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
         File:  inm_osek.h
      Project:  Nm_IndOsek
       Module:  -
    Generator:  -
  Description:  Header file for OSEK indirect network management
**********************************************************************************************************************/

/**********************************************************************************************************************
  AUTHOR IDENTITY
-----------------------------------------------------------------------------------------------------------------------
  Initials     Name                      Company
-----------------------------------------------------------------------------------------------------------------------
  vismas       Markus Schwarz            Vector Informatik GmbH
  vissf        Dieter Schaufelberger     Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
-----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Change Id     Description
-----------------------------------------------------------------------------------------------------------------------
  2.00.00   2004-10-18  vissf   ESCAN00009939 Support for Renault SLP2
  2.01.00   2004-10-22  Fmi     ESCAN00009981 Parameter definitions corrected
  2.02.00   2004-10-27  Fmi     ESCAN00010023 New naming conventions
                                ESCAN00010169 Incorrect initialization of variables
  2.03.00   2005-01-24  vissf   ESCAN00010772 Bus Off supervision: Nm_IndOsek indicates 
                                              confirmed BusOff state to application
  2.04.00   2005-06-06  vissf   ESCAN00012452 No changes
                                ESCAN00012518 No changes
  2.05.00   2005-08-16  vissf   ESCAN00013233 Support of Multiple ECU
  2.06.00   2005-11-29  vissf   ESCAN00014371 No changes 
  2.07.00   2006-03-14  vissf   ESCAN00015293 Inconsistency between declaration and usage 
                                              of function ApplInmNmRxUserInit() and ApplInmNmTxUserInit()
  2.08.00   2006-04-03  vissf   ESCAN00016968 PSA HIGH SPEED/LOW SPEED support
  2.09.00   2006-08-30  vissf   ESCAN00017491 No changes
  2.10.00   2006-09-11  vismas  ESCAN00017607 No changes
  2.11.00   2006-10-09  vissf   ESCAN00017966 Missing extern declaration
  2.12.00   2007-05-09  vismas  ------------- Rework
  2.13.00   2007-11-08  vismas  ESCAN00023130 extended status
  3.00.00   2007-10-30  vismas  ESCAN00023076 Adapted to GENy
                                ESCAN00023077 no changes in this files
                                ------------- adapted to new code template
**********************************************************************************************************************/

#if defined ( V_NM_INDOSEK_COMPONENT_HEADER )
#else
#define V_NM_INDOSEK_COMPONENT_HEADER

/**********************************************************************************************************************
  Includes
**********************************************************************************************************************/
/* system includes */
#include "v_cfg.h"
#include "v_def.h"

/* interface to the CAN driver (interrupt locking mechanism) */
#include "can_inc.h"

/* configuration of Nm_IndOsek */
#include "inm_cfg.h"

/**********************************************************************************************************************
  Version data
**********************************************************************************************************************/
/* ##V_CFG_MANAGEMENT ##CQProject : Nm_IndOsek CQComponent : Implementation */
#define NM_INDOSEK_VERSION            0x0300u
#define NM_INDOSEK_RELEASE_VERSION    0x00u

/**********************************************************************************************************************
  Global configuration
**********************************************************************************************************************/
#if ( kInmNumberOfChannels > 1 )
  #define INM_ENABLE_INDEXED_NM
#else
  #define INM_DISABLE_INDEXED_NM
#endif

/**********************************************************************************************************************
  Global typedefs
**********************************************************************************************************************/
typedef vuint16 inmNmChannelType;
typedef vuint8  inmNmCounterType;
typedef vuint8  inmNmIndexType;
typedef vuint8  inmNmStatusType;

typedef struct
{
  inmNmStatusType  status;
  inmNmCounterType counter;
} inmNmConditionType;

/**********************************************************************************************************************
  Global data defines
**********************************************************************************************************************/
/* state management */
#define INM_NM_OFF                    ((inmNmStatusType)0x00u)
#define INM_NM_ON                     ((inmNmStatusType)0x01u)

/* general status management (RX, TX, Generic, BusOff) */
/*ESCAN00023130*/
#define INM_OK                        ((inmNmStatusType)0x00u)
#define INM_FAILURE                   ((inmNmStatusType)0x01u)
#define INM_CONFIRMED                 ((inmNmStatusType)0x02u)
#define INM_CONFIRMED_OK              ((inmNmStatusType)0x02u)
#define INM_CONFIRMED_FAILURE         ((inmNmStatusType)0x03u)
#define INM_STAT_FAILURE              ((inmNmStatusType)0x04u)
#define INM_STAT_CHANGE               ((inmNmStatusType)0x08u)
#define INM_SPV_ACTIVE                ((inmNmStatusType)0x10u)

#if defined ( INM_ENABLE_ASSERT )
/* assertion codes */
#define kInmInvalidChannel            0x01
#define kInmInvalidRxIndex            0x02
#endif

/**********************************************************************************************************************
  Global macro defines
**********************************************************************************************************************/
/*--- configuration access macros -----------------------------------------------------------------------------------*/
#if defined ( INM_ENABLE_INDEXED_NM )
  #define InmCfg_TaskCycle(ch)        InmCycleTime_Field[ch]
#else
  #define InmCfg_TaskCycle(ch)        kInmCycleTime
#endif

/*--- channel access macros -----------------------------------------------------------------------------------------*/
#if ( kInmNumberOfChannels == 1 )
#define INM_CHANNEL_PARA_ONLY         
#define INM_CHANNEL_PARA_FIRST        
#define INM_CHANNEL_TYPE_ONLY         void
#define INM_CHANNEL_TYPE_FIRST        
#define INM_CHANNEL_IDX               0
#else
#define INM_CHANNEL_PARA_ONLY         channel
#define INM_CHANNEL_PARA_FIRST        channel,
#define INM_CHANNEL_TYPE_ONLY         inmNmChannelType channel
#define INM_CHANNEL_TYPE_FIRST        inmNmChannelType channel,
#define INM_CHANNEL_IDX               channel
#endif 

/**********************************************************************************************************************
  Global data prototypes (exported, RAM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global data prototypes (exported, ROM)
**********************************************************************************************************************/

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kInmMainVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kInmSubVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kInmReleaseVersion;


/**********************************************************************************************************************
  Global data prototypes (imported, RAM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global data prototypes (imported, ROM)
**********************************************************************************************************************/
/*--- system --------------------------------------------------------------------------------------------------------*/
#if defined ( INM_ENABLE_INDEXED_NM )
V_MEMROM0 extern V_MEMROM1 inmNmChannelType V_MEMROM2 InmIndexToChannel[kInmNumberOfRxMessages];
#endif

/*--- Rx ------------------------------------------------------------------------------------------------------------*/
V_MEMROM0 extern V_MEMROM1 inmNmCounterType V_MEMROM2 InmRxIncrement[kInmNumberOfRxMessages];
V_MEMROM0 extern V_MEMROM1 inmNmCounterType V_MEMROM2 InmRxDecrement[kInmNumberOfRxMessages];
V_MEMROM0 extern V_MEMROM1 inmNmIndexType   V_MEMROM2 InmRxMsgStartIndex[kInmNumberOfChannels+1];

/*--- Tx ------------------------------------------------------------------------------------------------------------*/
V_MEMROM0 extern V_MEMROM1 inmNmCounterType V_MEMROM2 InmTxIncrement[kInmNumberOfChannels];
V_MEMROM0 extern V_MEMROM1 inmNmCounterType V_MEMROM2 InmTxDecrement[kInmNumberOfChannels];

#if defined ( INM_ENABLE_GENERIC_SUPPORT ) 
/*--- Generic -------------------------------------------------------------------------------------------------------*/
V_MEMROM0 extern V_MEMROM1 inmNmCounterType V_MEMROM2 InmGenericIncrement[kInmNumberOfChannels];
V_MEMROM0 extern V_MEMROM1 inmNmCounterType V_MEMROM2 InmGenericDecrement[kInmNumberOfChannels];
#endif


/**********************************************************************************************************************
  Global function prototypes
**********************************************************************************************************************/
/*---------------------------------------------------------------------------------------------------------------------
  service functions
---------------------------------------------------------------------------------------------------------------------*/
/*--- state ---------------------------------------------------------------------------------------------------------*/
extern void InmNmInit(INM_CHANNEL_TYPE_ONLY);
extern void InmNmReInit(INM_CHANNEL_TYPE_ONLY);
extern void InmNmStart(INM_CHANNEL_TYPE_ONLY);
extern void InmNmStop(INM_CHANNEL_TYPE_ONLY);
extern void InmNmDiagOn(INM_CHANNEL_TYPE_ONLY);
extern void InmNmDiagOff(INM_CHANNEL_TYPE_ONLY);
extern inmNmStatusType InmNmGetStatus(INM_CHANNEL_TYPE_ONLY);

/*--- Rx ------------------------------------------------------------------------------------------------------------*/
extern void InmNmRxDiagOn(const inmNmIndexType index);
extern void InmNmRxDiagOff(const inmNmIndexType index);
extern void InmNmRxOk(const inmNmIndexType index);
extern void InmNmRxTimeOut(const inmNmIndexType index);
extern inmNmConditionType *InmNmGetRxCondition(const inmNmIndexType index);

/*--- Tx ------------------------------------------------------------------------------------------------------------*/
extern void InmNmTxDiagOn(INM_CHANNEL_TYPE_ONLY);
extern void InmNmTxDiagOff(INM_CHANNEL_TYPE_ONLY);
extern void InmNmTxOk(INM_CHANNEL_TYPE_ONLY);
extern void InmNmTxTimeOut(INM_CHANNEL_TYPE_ONLY);
extern inmNmConditionType *InmNmGetTxCondition(INM_CHANNEL_TYPE_ONLY);

#if defined (INM_ENABLE_GENERIC_SUPPORT)
/*--- Generic -------------------------------------------------------------------------------------------------------*/
extern void InmNmGenericDiagOn(INM_CHANNEL_TYPE_ONLY);
extern void InmNmGenericDiagOff(INM_CHANNEL_TYPE_ONLY);
extern void InmNmGenericOk(INM_CHANNEL_TYPE_ONLY);
extern void InmNmGenericTimeOut(INM_CHANNEL_TYPE_ONLY);
extern inmNmConditionType *InmNmGetGenericCondition(INM_CHANNEL_TYPE_ONLY);
#endif


/*---------------------------------------------------------------------------------------------------------------------
  callback functions
---------------------------------------------------------------------------------------------------------------------*/
/*--- state ---------------------------------------------------------------------------------------------------------*/
extern void ApplInmNmStartCanIl( INM_CHANNEL_TYPE_ONLY );
extern void ApplInmNmStopCanIl( INM_CHANNEL_TYPE_ONLY );

/*--- Rx ------------------------------------------------------------------------------------------------------------*/
extern void ApplInmNmStatusIndicationRx( inmNmIndexType index, inmNmStatusType status );
#if defined ( INM_ENABLE_USER_INIT )
extern void ApplInmNmRxUserInit( inmNmIndexType index, inmNmConditionType *pStatus );
extern void ApplInmNmRxUserReInit( inmNmIndexType index, inmNmConditionType *pStatus );
#endif

/*--- Tx ------------------------------------------------------------------------------------------------------------*/
extern void ApplInmNmStatusIndicationTx( INM_CHANNEL_TYPE_FIRST inmNmStatusType status );
#if defined ( INM_ENABLE_USER_INIT )
extern void ApplInmNmTxUserInit( INM_CHANNEL_TYPE_FIRST inmNmConditionType *pStatus );
extern void ApplInmNmTxUserReInit( INM_CHANNEL_TYPE_FIRST  inmNmConditionType *pStatus );
#endif

#if defined ( INM_ENABLE_GENERIC_SUPPORT )
/*--- Generic --------------------------------------------------------------------------------------------------------*/
extern void ApplInmNmStatusIndicationGeneric( INM_CHANNEL_TYPE_FIRST inmNmStatusType status );
  #if defined ( INM_ENABLE_USER_INIT )
extern void ApplInmNmGenericUserInit( INM_CHANNEL_TYPE_FIRST inmNmConditionType *pStatus );
extern void ApplInmNmGenericUserReInit( INM_CHANNEL_TYPE_FIRST inmNmConditionType *pStatus );
  #endif
#endif


#if defined ( INM_ENABLE_ASSERT )
extern void ApplInmFatalError( vuint8 error );
#endif

#endif /* V_NM_INDOSEK_COMPONENT_HEADER */

/**********************************************************************************************************************
  EOF
**********************************************************************************************************************/
/* ORGANI: STOPSINGLE_OF_MULTIPLE */
