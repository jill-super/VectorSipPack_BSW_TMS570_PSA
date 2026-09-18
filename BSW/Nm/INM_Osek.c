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
  2.03.00   2005-01-24  vissf   ESCAN00010772 Bus Off supervision: Nm_IndOsek indicates confirmed BusOff state 
                                              to application MutliChannel support
  2.04.00   2005-06-06  vissf   ESCAN00012452 BusOff supervision algorithm never detects 
                                ESCAN00012518 confirmed BusOff state 
  2.05.00   2005-08-16  vissf   ESCAN00013233 Support of Multiple ECU
  2.06.00   2005-11-29  vissf   ESCAN00014371 Fault revovery algorithm added 
  2.07.00   2006-03-14  vissf   ESCAN00015293 Inconsistency between declaration and usage 
                                              of function ApplInmNmRxUserInit() and ApplInmNmTxUserInit()
  2.08.00   2006-04-03  vissf   ESCAN00016968 PSA HIGH SPEED/LOW SPEED support
  2.09.00   2006-08-30  vissf   ESCAN00017491 Wrong callback function called
  2.10.00   2006-09-11  vismas  ESCAN00017607 Added callback ApplInmNmBusOffInitCan()
  2.11.00   2006-10-09  vissf   ESCAN00017966 Missing extern declaration
  2.12.00   2007-05-09  vismas  ------------- Rework
  2.13.00   2007-11-08  vismas  ESCAN00023130 removed INM_ENABLE_CONF_PRESENT_CB
                                              changed implementation of InmEventTimeout, InmEventOk
  3.00.00   2007-10-30  vismas  ESCAN00023076 adapted to GENy
                                ESCAN00023077 adapted control flow in InmNmBusOff
                                ------------- adapted to new code template
**********************************************************************************************************************/

#define V_NM_INDOSEK_COMPONENT_SOURCE

#if defined ( INM_ENABLE_ASSERT )
/* lint -e661
  2007-12-13, vismas: 
  When assertions are active, PClint reports a variety of possible out-of-bounds.
  This warning is suppressed to focus on the relevant warnings. */
#endif

/**********************************************************************************************************************
  Includes
**********************************************************************************************************************/
#include "inm_osek.h"

/**********************************************************************************************************************
  Version check
**********************************************************************************************************************/
/*--- check version of static files ---------------------------------------------------------------------------------*/
#if ( NM_INDOSEK_VERSION != 0x0300u )
# error "Header and Source file are inconsistent (version)!"
#endif
#if ( NM_INDOSEK_RELEASE_VERSION != 0x00u )
# error "Header and Source file are inconsistent (release version)!"
#endif

/*--- check version of configuration tool / generated files ---------------------------------------------------------*/
#if defined ( VGEN_GENY )
#else
  #error "This code requires a configuration by tool GENy."
#endif

#if defined ( NM_INDOSEKDLL_VERSION )
  #if ( NM_INDOSEKDLL_VERSION < 0x0095u )
    #error  "This code requires a newer version of GENy DLL Nm_IndOsek.dll."
  #endif
#else
  #error "NM_INDOSEKDLL_VERSION is not defined."
#endif

/**********************************************************************************************************************
  ORGANI check
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local configuration
**********************************************************************************************************************/

/**********************************************************************************************************************
  Configuration check
**********************************************************************************************************************/
/*--- check channel assignment ----------------------------------------------*/
#if defined ( kInmNumberOfChannels )
# if ( kInmNumberOfChannels < 1 )
#  error "Nm_IndOsek: Invalid value of 'kInmNumberOfChannels'."
# endif
#else
# error "Nm_IndOsek: 'kInmNumberOfChannels' is not defined. Please check your configuration file."
#endif

/*--- check values -----------------------------------------------------------*/
#if defined ( kInmBusOffTimeout )
/*
 * Name:        kInmBusOffTimeout
 * Description: This value defines the time in [ms] that is used to detect a confirmed BusOff.
 */
# if ( kInmBusOffTimeout > 0 )
# else
#  error "Nm_IndOsek: 'kInmBusOffTimeout' has no valid value."
# endif
#else
# error "Nm_IndOsek: 'kInmBusOffTimeout' is not defined. Please check your configuration file."
#endif

#if defined ( kInmNumberOfRxMessages )
/*
 * Name:        kInmNumberOfRxMessages
 * Description: This value represents the sum of all RX messages that are used for supervision.
 *              These messages are defined in the DBC:
 *              All RX messages that have attribute "NmMessage_<currentNode>=yes" are used for
 *              RX supervision.
 */
# if ( kInmNumberOfRxMessages > 0 )
# else
#  error "Nm_IndOsek: 'kInmNumberOfRxMessages' has no valid value."
# endif
#else
# error "Nm_IndOsek: 'kInmNumberOfRxMessages' is not defined. Please check your configuration file."
#endif


/*--- check configured features ( Nm_IndOsek ) --------------------------------*/
#if defined ( INM_DISABLE_BUSOFF_SUPPORT )
/*
 * Name:        INM_<EN|DIS>ABLE_BUSOFF_SUPPORT
 * Description: If enabled, the sub-module for BusOff supervision is enabled, including all
 *              APIs and data.
 *              If disabled, the BusOff supervision is not possible.
 */
#else
# error "Nm_IndOsek: Define 'INM_<EN|DIS>ABLE_BUSOFF_SUPPORT' must be set."
#endif

#if defined ( INM_ENABLE_GENERIC_SUPPORT ) || \
    defined ( INM_DISABLE_GENERIC_SUPPORT )
/*
 * Name:        INM_<EN|DIS>ABLE_GENERIC_SUPPORT
 * Description: If enabled, the sub-module for user-specific supervision is enabled, including all
 *              APIs and data.
 *              If disabled, the user-specific supervision is not possible.
 */
#else
# error "Nm_IndOsek: Define 'INM_<EN|DIS>ABLE_GENERIC_SUPPORT' must be set."
#endif

#if defined ( INM_ENABLE_INIT_ON_DIAG_ON ) || \
    defined ( INM_DISABLE_INIT_ON_DIAG_ON )
/*
 * Name:        INM_<EN|DIS>ABLE_INIT_ON_DIAG_ON
 * Description: If enabled, each sub-modules get re-initialized when supervision is turned on.
 */
#else
# error "Nm_IndOsek: Define 'INM_<EN|DIS>ABLE_INIT_ON_DIAG_ON' must be set."
#endif

#if defined ( INM_ENABLE_INIT_ON_DIAG_OFF ) || \
    defined ( INM_DISABLE_INIT_ON_DIAG_OFF )
/*
 * Name:        INM_<EN|DIS>ABLE_INIT_ON_DIAG_OFF
 * Description: If enabled, each sub-modules get re-initialized when supervision is turned off.
 */
#else
# error "Nm_IndOsek: Define 'INM_<EN|DIS>ABLE_INIT_ON_DIAG_OFF' must be set."
#endif

#if defined ( INM_DISABLE_CLEAR_COUNTER )
/*
 * Name:        INM_<EN|DIS>ABLE_CLEAR_COUNTER
 * Description: If enabled, the error counter of the sub module (RX, TX, GenericUser) is reset when the 
 *              message/event is reported present the first time.
 *              If disabled, the error counter is decremented upon each reported presence.
 */
#else
# error "Nm_IndOsek: Define 'INM_<EN|DIS>ABLE_CLEAR_COUNTER' must be set."
#endif

#if defined ( INM_ENABLE_USER_INIT ) || \
    defined ( INM_DISABLE_USER_INIT )
/*
 * Name:        INM_<EN|DIS>ABLE_USER_INIT
 * Description: If enabled, the initialization and re-initialization of the sub modules 
 *              (RX, TX, GenericUser, BusOff) can be done by the application.
 *              The application is notified by callbacks about the need for the corresponding 
 *              (re-)initialization.
 *              If disabled, the Nm_IndOsek (re-)initializes the status itself to the 
 *              (internal) default values.
 */
#else
# error "Nm_IndOsek: Define 'INM_<EN|DIS>ABLE_USER_INIT' must be set."
#endif

#if defined ( INM_ENABLE_ASSERT ) || \
    defined ( INM_DISABLE_ASSERT )
/*
 * Name:        INM_<EN|DIS>ABLE_ASSERT
 * Description: If enabled, the Nm_IndOsek performs internal checks during runtime.
 * Note:        It is recommended to disable this feature for series production.
 */
#else
# error "Nm_IndOsek: Define 'INM_<EN|DIS>ABLE_ASSERT' must be set."
#endif

/**********************************************************************************************************************
  Local data defines
**********************************************************************************************************************/
/*
 * This define represents the upper limit of the counter.
 * The counter may not exceed this value. 
 * If the counter reaches this upper limit, the corresponding failure gets confirmed.
 */
#define kInmCounterMax            0xff

/* 
 * This define represents the number of TX messages that have to timeout 
 * before the counter is incremented.
 */
#define kInmTxMsgCounter          0x03

#define INM_NO_STATUS_CALLBACK    0x00
#define INM_STATUS_CALLBACK       0x01

/**********************************************************************************************************************
  Local macro defines
**********************************************************************************************************************/
/*--- interrupt locks -----------------------------------------------------------------------------------------------*/
#define InmEnterCriticalSection   CanInterruptDisable
#define InmLeaveCriticalSection   CanInterruptRestore

/*--- access for assertions -----------------------------------------------------------------------------------------*/
/* PRQA S 3453 ++ */ /* 2007-11-27, vismas: using macros allows more compact source code */
#if defined ( INM_ENABLE_ASSERT )
  #define InmAssert(cond, err)        if((cond)==0) { ApplInmFatalError(err); } /* PRQA S 3412 */ /* 2007-11-27, vismas: assertion function is configurable => this results in unknown code fragment */
  #define InmAssertAlways(err)        ApplInmFatalError(err)
#else
  #define InmAssert(cond, err)        
  #define InmAssertAlways(err)        
#endif
/* PRQA S 3453 -- */

/**********************************************************************************************************************
  Local data types and structures
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global data definitions (ROM)
**********************************************************************************************************************/

V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kInmMainVersion    = (vuint8)(( NM_INDOSEK_VERSION ) >> 8);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kInmSubVersion     = (vuint8)(  NM_INDOSEK_VERSION & 0x00FFu);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kInmReleaseVersion = (vuint8)(  NM_INDOSEK_RELEASE_VERSION );


/**********************************************************************************************************************
  Global data definitions (RAM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local data definitions (ROM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local data definitions (RAM)
**********************************************************************************************************************/
/*--- state ---------------------------------------------------------------------------------------------------------*/
/*
 * Description : This variable stores the status of the NM.
 *               This status ist set to INM_NM_ON within InmNmStart() and 
 *               reset to INM_NM_OFF within InmNmStop().
 *               This status is used to determine if supervision may be 
 *               started.
 * Values      : - INM_NM_OFF
 *               - INM_NM_ON
 */
static inmNmStatusType inmNmState[kInmNumberOfChannels];

/*--- Rx ------------------------------------------------------------------------------------------------------------*/
/*
 * Description : This variable stores the status of each supervised RX message.
 *               The status information contains the supervision counter
 *               and the related supervision state.
 * Values      : N/A, because struct
 */
static inmNmConditionType inmRxCondition[kInmNumberOfRxMessages];

/*--- Tx ------------------------------------------------------------------------------------------------------------*/
/*
 * Description : This variable stores the status of each supervised TX message.
 *               The status information contains the supervision counter
 *               and the related supervision state.
 * Values      : N/A, because struct
 */
static inmNmConditionType inmTxCondition[kInmNumberOfChannels];

/*
 * Description : This variable is used to count the number of missing TX messages.
 *               The supervision counter and state is only updated when there
 *               have been three consecutive TX timeouts.
 * Values      : 0..kInmTxMsgCounter
 */
static inmNmCounterType inmCTxNOk[kInmNumberOfChannels];


#if defined ( INM_ENABLE_GENERIC_SUPPORT )
/*--- Generic -------------------------------------------------------------------------------------------------------*/
/*
 * Description : This variable stores the status of each supervised user-specific event.
 *               The status information contains the supervision counter
 *               and the related supervision state.
 * Values      : N/A, because struct
 */
static inmNmConditionType inmGenericCondition[kInmNumberOfChannels];
#endif


/**********************************************************************************************************************
  Local function prototypes
**********************************************************************************************************************/
static vuint8 InmEventOk( inmNmConditionType * const pEvent, vuint8 value );
static vuint8 InmEventTimeout( inmNmConditionType * const pEvent, vuint8 value );

/*--- Rx ------------------------------------------------------------------------------------------------------------*/
static void InmNmRxReInit( const inmNmIndexType index );

/*--- Tx ------------------------------------------------------------------------------------------------------------*/
static void InmNmTxReInit( INM_CHANNEL_TYPE_ONLY );

#if defined ( INM_ENABLE_GENERIC_SUPPORT )
/*--- Generic -------------------------------------------------------------------------------------------------------*/
static void InmNmGenericReInit( INM_CHANNEL_TYPE_ONLY );
#endif


/**********************************************************************************************************************
  Global function definitions
**********************************************************************************************************************/
/*--- state ---------------------------------------------------------------------------------------------------------*/
/**********************************************************************************************************************
  Name:         InmNmInit
  Parameter:    channel               handle of NM channel (only for multi-channel usage)
  Return value: 
  Description:  This function initializes the Nm_IndOsek.
                All internal states and variables are initialised. 
                This function has to be called once after a reset.
  Call context: during power-on initialization
**********************************************************************************************************************/
void InmNmInit( INM_CHANNEL_TYPE_ONLY )
{
  inmNmIndexType index;

  /*--- state management ---*/
  /* initialize local variables */
  inmNmState[INM_CHANNEL_IDX] = INM_NM_OFF;

  /*--- RX management ---*/
  /* initialize global variables */
  for( index=InmRxMsgStartIndex[INM_CHANNEL_IDX]; index<InmRxMsgStartIndex[INM_CHANNEL_IDX+1]; index++ )
  {
    #if defined ( INM_ENABLE_USER_INIT )
    ApplInmNmRxUserInit( index, &inmRxCondition[index] );
    #else
    inmRxCondition[index].status  = INM_FAILURE;
    inmRxCondition[index].counter = 0;
    #endif
  }

  /*--- TX management ---*/
  /* initialize global variables */
  #if defined ( INM_ENABLE_USER_INIT )
  ApplInmNmTxUserInit( INM_CHANNEL_PARA_FIRST &inmTxCondition[INM_CHANNEL_IDX] );
  #else
  inmTxCondition[INM_CHANNEL_IDX].status = INM_FAILURE;
  inmTxCondition[INM_CHANNEL_IDX].counter= 0;
  #endif

  #if defined ( INM_ENABLE_GENERIC_SUPPORT )
  /*--- Generic management ---*/
  /* initialize global variables */
    #if defined ( INM_ENABLE_USER_INIT )
  ApplInmNmGenericUserInit( INM_CHANNEL_PARA_FIRST &inmGenericCondition[INM_CHANNEL_IDX] );
    #else
  inmGenericCondition[INM_CHANNEL_IDX].status  = INM_FAILURE;
  inmGenericCondition[INM_CHANNEL_IDX].counter = 0;
    #endif
  #endif

}

/**********************************************************************************************************************
  Name:         InmNmReInit
  Parameter:    channel               handle of NM channel (only for multi-channel usage)
  Return value: ---
  Description:  This function re-initializes the Nm_IndOsek.
                Only some internal states and variables are re-initialised.
**********************************************************************************************************************/
void InmNmReInit( INM_CHANNEL_TYPE_ONLY )
{
  inmNmIndexType index;

  InmEnterCriticalSection();

  /*--- state management ---*/
  /* no change => stay in same state after re-init */

  /*--- RX management ---*/
  for( index=InmRxMsgStartIndex[INM_CHANNEL_IDX]; index<InmRxMsgStartIndex[INM_CHANNEL_IDX+1]; index++ )
  {
    InmNmRxReInit(index);
  }

  /*--- TX management ---*/
  InmNmTxReInit( INM_CHANNEL_PARA_ONLY );

  #if defined ( INM_ENABLE_GENERIC_SUPPORT )
  /*--- Generic management ---*/
  InmNmGenericReInit( INM_CHANNEL_PARA_ONLY );
  #endif


  InmLeaveCriticalSection();
}

/**********************************************************************************************************************
  Name:         InmNmStart
  Parameter:    channel               handle of NM channel (only for multi-channel usage)
  Return value: ---
  Description:  This function starts the Nm_IndOsek.
**********************************************************************************************************************/
void InmNmStart( INM_CHANNEL_TYPE_ONLY )
{
  inmNmIndexType index;

  if (inmNmState[INM_CHANNEL_IDX] == INM_NM_OFF )
  {
    /*--- state management ---*/
    inmNmState[INM_CHANNEL_IDX] = INM_NM_ON;

    /*--- RX management ---*/
    /* inform application about current RX state */
    for( index=InmRxMsgStartIndex[INM_CHANNEL_IDX]; index<InmRxMsgStartIndex[INM_CHANNEL_IDX+1]; index++ )
    {
      ApplInmNmStatusIndicationRx( index, inmRxCondition[index].status );
    }

    /*--- TX management ---*/
    /* inform application about current TX state */
    ApplInmNmStatusIndicationTx( INM_CHANNEL_PARA_FIRST inmTxCondition[INM_CHANNEL_IDX].status );
    
  #if defined ( INM_ENABLE_GENERIC_SUPPORT )
    /*--- generic management ---*/
    /* inform application about current Generic state */
    ApplInmNmStatusIndicationGeneric( INM_CHANNEL_PARA_FIRST inmGenericCondition[INM_CHANNEL_IDX].status );
  #endif


    /* inform application about start of Nm_IndOsek */
    ApplInmNmStartCanIl( INM_CHANNEL_PARA_ONLY );
  }
  else
  {
    /* Nm_IndOsek is already started */
  }
}

/**********************************************************************************************************************
  Name:         InmNmStop
  Parameter:    channel               handle of NM channel (only for multi-channel usage)
  Return value: ---
  Description:  This function stops the Nm_IndOsek.
**********************************************************************************************************************/
void InmNmStop( INM_CHANNEL_TYPE_ONLY )
{
  if (inmNmState[INM_CHANNEL_IDX] == INM_NM_ON )
  {
    /* stop diagnostic mode (=> stop network supervision) */
    InmNmDiagOff( INM_CHANNEL_PARA_ONLY );

    /* enter state init - NM is off */
    inmNmState[INM_CHANNEL_IDX] = INM_NM_OFF;

    /* inform application about stop of Nm_IndOsek */
    ApplInmNmStopCanIl( INM_CHANNEL_PARA_ONLY );
  }
}

/**********************************************************************************************************************
  Name:         InmNmDiagOn
  Parameter:    channel               handle of NM channel (only for multi-channel usage)
  Return value: ---
  Description:  This function enables the network supervision for
                - RX
                - TX
                - generic (if enabled)
                - BusOff (if enabled)
  Call context: may be called on task and interrupt level
**********************************************************************************************************************/
void InmNmDiagOn( INM_CHANNEL_TYPE_ONLY )
{
  inmNmIndexType index;

  /* check if Nm_IndOsek in ON */
  if( inmNmState[INM_CHANNEL_IDX] == INM_NM_ON )
  {
    InmEnterCriticalSection();

    /*--- RX management: activate supervision for all nodes */
    for( index=InmRxMsgStartIndex[INM_CHANNEL_IDX]; index<InmRxMsgStartIndex[INM_CHANNEL_IDX+1]; index++ )
    {
      InmNmRxDiagOn( index );
    }

    /*--- TX management: activate supervision */
    InmNmTxDiagOn(INM_CHANNEL_PARA_ONLY);

  #if defined ( INM_ENABLE_GENERIC_SUPPORT )
    /*--- generic management: activate supervision */
    InmNmGenericDiagOn(INM_CHANNEL_PARA_ONLY);
  #endif


    InmLeaveCriticalSection();
  }
  else
  {
    /* Nm_IndOsek is not ON => supervision cannot be started */
  }
}

/**********************************************************************************************************************
  Name:         InmNmDiagOff
  Parameter:    channel               handle of NM channel (only for multi-channel usage)
  Return value: ---
  Description:  This function disables the network supervision for
                - RX
                - TX
                - generic (if enabled)
                - BusOff (if enabled)
  Call context: may be called on task and interrupt level
**********************************************************************************************************************/
void InmNmDiagOff( INM_CHANNEL_TYPE_ONLY )
{
  inmNmIndexType index;

  /* check if Nm_IndOsek in ON */
  if( inmNmState[INM_CHANNEL_IDX] == INM_NM_ON )
  {
    InmEnterCriticalSection();

    /*--- RX management: deactivate supervision for all nodes */
    for( index=InmRxMsgStartIndex[INM_CHANNEL_IDX]; index<InmRxMsgStartIndex[INM_CHANNEL_IDX+1]; index++ )
    {
      InmNmRxDiagOff( index );
    } 

    /*--- TX management: deactivate supervision */
    InmNmTxDiagOff( INM_CHANNEL_PARA_ONLY );

  #if defined (INM_ENABLE_GENERIC_SUPPORT)
    /*--- Generic management: deactivate supervision */
    InmNmGenericDiagOff( INM_CHANNEL_PARA_ONLY );
  #endif


    InmLeaveCriticalSection();
  }
  else
  {
    /* Nm_IndOsek is not OFF => supervision cannot be stopped */
  }
}

/**********************************************************************************************************************
  Name:         InmNmGetStatus
  Parameter:    channel               handle of NM channel (only for multi-channel usage)
  Return value: - INM_NM_ON :         NM is running
                - INM_NM_OFF:         NM is not running
  Description:  This function returns the status of the NM.
**********************************************************************************************************************/
inmNmStatusType InmNmGetStatus( INM_CHANNEL_TYPE_ONLY )
{
  return( inmNmState[INM_CHANNEL_IDX] );
}

/*--- Rx ------------------------------------------------------------------------------------------------------------*/
/**********************************************************************************************************************
  Name:         InmNmRxDiagOn
  Parameter:    index                 index of the Rx message
  Return value: ---
  Description:  This function enables the supervision for a certain RX message.
                This RX message is identified by <index>
**********************************************************************************************************************/
void InmNmRxDiagOn( const inmNmIndexType index )
{
  #if ( kInmNumberOfChannels > 1 )
  inmNmChannelType channel;
  #endif

  #if ( kInmNumberOfChannels > 1 )
  channel = InmIndexToChannel[index];
  #endif

  /* check if Nm_IndOsek in ON */ 
  if( inmNmState[INM_CHANNEL_IDX] == INM_NM_ON )
  {
    /* enable supervision */
    inmRxCondition[index].status |= INM_SPV_ACTIVE;

  #if defined ( INM_ENABLE_INIT_ON_DIAG_ON )
    InmNmRxReInit( index );
  #endif
  }
}

/**********************************************************************************************************************
  Name:         InmNmRxDiagOff
  Parameter:    index                 index of the Rx message
  Return value: 
  Description:  This function disables the supervision for a certain RX message.
                This RX message is identified by <index>.
**********************************************************************************************************************/
void InmNmRxDiagOff( const inmNmIndexType index )
{
  #if ( kInmNumberOfChannels > 1 )
  inmNmChannelType channel;
  #endif

  #if ( kInmNumberOfChannels > 1 )
  channel = InmIndexToChannel[index];
  #endif

  /* check if Nm_IndOsek in ON */ 
  if( inmNmState[INM_CHANNEL_IDX] == INM_NM_ON )
  {
    /* disable supervision */
    inmRxCondition[index].status &= (inmNmStatusType)(~(vuintx)(INM_SPV_ACTIVE));

  #if defined ( INM_ENABLE_INIT_ON_DIAG_OFF )
    InmNmRxReInit( index );
  #endif
  }
}

/**********************************************************************************************************************
  Name:         InmNmRxOk
  Parameter:    index                 index of the Rx message
  Return value: ---
  Description:  This function informs the Nm_IndOsek that the reception of a supervised RX message was successful.
                This can be done e.g. by the IL.
**********************************************************************************************************************/
void InmNmRxOk( const inmNmIndexType index )
{
  #if ( kInmNumberOfChannels > 1 )
  inmNmChannelType channel;
  #endif

  InmEnterCriticalSection();

  #if ( kInmNumberOfChannels > 1 )
  channel = InmIndexToChannel[index];
  #endif

  /* check if Nm_IndOsek in ON */
  if( inmNmState[INM_CHANNEL_IDX] == INM_NM_ON )
  {

    if( InmEventOk( &inmRxCondition[index], InmRxDecrement[index] ) == INM_STATUS_CALLBACK )
    {
      ApplInmNmStatusIndicationRx( index, inmRxCondition[index].status );
    }
  }

  InmLeaveCriticalSection();
}

/**********************************************************************************************************************
  Name:         InmNmRxTimeOut
  Parameter:    index                 index of the Rx message
  Return value: ---
  Description:  This function informs the Nm_IndOsek that the reception of a supervised RX message was not successful.
                This can be done e.g. by the IL.
**********************************************************************************************************************/
void InmNmRxTimeOut( const inmNmIndexType index )
{
  /* check if supervision is active */
  if( (inmRxCondition[index].status & INM_SPV_ACTIVE) != 0 )
  {
    InmEnterCriticalSection();
   
    /* process event status */
    if( InmEventTimeout( &inmRxCondition[index], InmRxIncrement[index] ) == INM_STATUS_CALLBACK )
    {
      ApplInmNmStatusIndicationRx( index, inmRxCondition[index].status );
    }

    InmLeaveCriticalSection();
  }
}

/**********************************************************************************************************************
  Name:         InmNmGetRxCondition
  Parameter:    index                 index of the Rx message
  Return value: pStatus               pointer to status of generic supervision
  Description:  This function returns a pointer to the current status of the RX supervision of a certain 
                Rx message (given by <index>).
**********************************************************************************************************************/
inmNmConditionType* InmNmGetRxCondition( const inmNmIndexType index )
{
  inmNmConditionType *rval;

  if( index < kInmNumberOfRxMessages )
  {
    rval = &inmRxCondition[index];
  }
  else
  {
    rval = 0;
    InmAssertAlways( kInmInvalidRxIndex );
  }

  return( rval );
}


/*--- Tx ------------------------------------------------------------------------------------------------------------*/
/**********************************************************************************************************************
  Name:         InmNmTxDiagOn
  Parameter:    channel               handle of NM channel (only for multi-channel usage)
  Return value: ---
  Description:  This function enables the supervision for the TX message.
                There is one supervised TX message for each channel.
**********************************************************************************************************************/
void InmNmTxDiagOn( INM_CHANNEL_TYPE_ONLY )
{
  /* check if Nm_IndOsek in ON */ 
  if( inmNmState[INM_CHANNEL_IDX] == INM_NM_ON )
  {
    /* enable supervision */
    inmTxCondition[INM_CHANNEL_IDX].status |= INM_SPV_ACTIVE;

  #if defined ( INM_ENABLE_INIT_ON_DIAG_ON )
    InmNmTxReInit( INM_CHANNEL_PARA_ONLY );
  #endif
  }
}

/**********************************************************************************************************************
  Name:         InmNmTxDiagOff
  Parameter:    channel               handle of NM channel (only for multi-channel usage)
  Return value: ---
  Description:  This function disables the supervision for the TX message.
                There is one supervised TX message for each channel.
**********************************************************************************************************************/
void InmNmTxDiagOff( INM_CHANNEL_TYPE_ONLY )
{
  /* check if Nm_IndOsek in ON */ 
  if( inmNmState[INM_CHANNEL_IDX] == INM_NM_ON )
  {
    /* disable supervision */
    inmTxCondition[INM_CHANNEL_IDX].status &= (inmNmStatusType)(~(vuintx)INM_SPV_ACTIVE);

  #if defined ( INM_ENABLE_INIT_ON_DIAG_OFF )
    InmNmTxReInit( INM_CHANNEL_PARA_ONLY );
  #endif
  }
}

/**********************************************************************************************************************
  Name:         InmNmTxOk
  Parameter:    channel               handle of NM channel (only for multi-channel usage)
  Return value: ---
  Description:  This function informs the Nm_IndOsek that the transmission of the supervised TX message was successful.
                This can be done e.g. by the IL.
**********************************************************************************************************************/
void InmNmTxOk( INM_CHANNEL_TYPE_ONLY )
{
  InmEnterCriticalSection();

  /* check if Nm_IndOsek in ON */
  if( inmNmState[INM_CHANNEL_IDX] == INM_NM_ON )
  {

    /* reset counter for TX errors */
    inmCTxNOk[INM_CHANNEL_IDX] = 0;

    if( InmEventOk( &inmTxCondition[INM_CHANNEL_IDX], InmTxDecrement[INM_CHANNEL_IDX] ) == INM_STATUS_CALLBACK )
    {
      ApplInmNmStatusIndicationTx( INM_CHANNEL_PARA_FIRST inmTxCondition[INM_CHANNEL_IDX].status );
    }
  }

  InmLeaveCriticalSection();
}

/**********************************************************************************************************************
  Name:         InmNmTxTimeOut
  Parameter:    channel               handle of NM channel (only for multi-channel usage)
  Return value: ---
  Description:  This function informs the Nm_IndOsek that the transmission of the supervised TX message was not 
                successful.This can be done e.g. by the IL.
**********************************************************************************************************************/
void InmNmTxTimeOut( INM_CHANNEL_TYPE_ONLY )
{
  /* check if supervision is active */
  if( (inmTxCondition[INM_CHANNEL_IDX].status & INM_SPV_ACTIVE) != 0 )
  {
    InmEnterCriticalSection();
    
    /* increment counter for TX errors */
    inmCTxNOk[INM_CHANNEL_IDX]++;

    /* check if this counter reaches maximum */
    if( inmCTxNOk[INM_CHANNEL_IDX] >= kInmTxMsgCounter )
    {
      /* reset TX error counter */
      inmCTxNOk[INM_CHANNEL_IDX] = 0;

      /* process event status */
      if( InmEventTimeout( &inmTxCondition[INM_CHANNEL_IDX], InmTxIncrement[INM_CHANNEL_IDX] ) == INM_STATUS_CALLBACK )
      {
        ApplInmNmStatusIndicationTx( INM_CHANNEL_PARA_FIRST inmTxCondition[INM_CHANNEL_IDX].status );
      }
    }
    InmLeaveCriticalSection();
  }
}

/**********************************************************************************************************************
  Name:         InmNmGetTxCondition
  Parameter:    channel               handle of NM channel (only for multi-channel usage)
  Return value: pStatus               pointer to status of TX supervision
  Description:  This function returns a pointer to the current status of the TX supervision.
**********************************************************************************************************************/
inmNmConditionType *InmNmGetTxCondition( INM_CHANNEL_TYPE_ONLY )
{
  inmNmConditionType *rval;

  rval = &inmTxCondition[INM_CHANNEL_IDX];

  return( rval );
}

#if defined ( INM_ENABLE_GENERIC_SUPPORT )
/*--- Generic -------------------------------------------------------------------------------------------------------*/
/**********************************************************************************************************************
  Name:         InmNmGenericDiagOn
  Parameter:    channel               handle of NM channel (only for multi-channel usage)
  Return value: ---
  Description:  This function enables the generic supervision for the given channel.
**********************************************************************************************************************/
void InmNmGenericDiagOn( INM_CHANNEL_TYPE_ONLY )
{
  /* check if Nm_IndOsek in ON */ 
  if( inmNmState[INM_CHANNEL_IDX] == INM_NM_ON )
  {
    InmEnterCriticalSection();

    /* enable supervision */
    inmGenericCondition[INM_CHANNEL_IDX].status |= INM_SPV_ACTIVE;

    #if defined ( INM_ENABLE_INIT_ON_DIAG_ON )
    InmNmGenericReInit( INM_CHANNEL_PARA_ONLY );
    #endif

    InmLeaveCriticalSection();
  }
}
#endif

#if defined ( INM_ENABLE_GENERIC_SUPPORT )
/**********************************************************************************************************************
  Name:         InmNmGenericDiagOff
  Parameter:    channel               handle of NM channel (only for multi-channel usage)
  Return value: ---
  Description:  This function disables the generic supervision for the given channel.
**********************************************************************************************************************/
void InmNmGenericDiagOff( INM_CHANNEL_TYPE_ONLY )
{
  /* check if Nm_IndOsek in ON */ 
  if( inmNmState[INM_CHANNEL_IDX] == INM_NM_ON )
  {
    InmEnterCriticalSection();

    /* disable supervision */
    inmGenericCondition[INM_CHANNEL_IDX].status &= (inmNmStatusType)(~(vuintx)INM_SPV_ACTIVE);

    #if defined ( INM_ENABLE_INIT_ON_DIAG_OFF )
    InmNmGenericReInit( INM_CHANNEL_PARA_ONLY );
    #endif

    InmLeaveCriticalSection();
  }
}
#endif

#if defined ( INM_ENABLE_GENERIC_SUPPORT )
/**********************************************************************************************************************
  Name:         InmNmGenericOk
  Parameter:    channel               handle of NM channel (only for multi-channel usage)
  Return value: ---
  Description:  This function informs the Nm_IndOsek that an event occured that is monitored by generic supervision.
**********************************************************************************************************************/
void InmNmGenericOk( INM_CHANNEL_TYPE_ONLY )
{
  /* check if supervision is active */
  if( (inmGenericCondition[INM_CHANNEL_IDX].status & INM_SPV_ACTIVE) != 0 )
  {
    InmEnterCriticalSection();

    if( InmEventOk( &inmGenericCondition[INM_CHANNEL_IDX], InmGenericDecrement[INM_CHANNEL_IDX] ) == INM_STATUS_CALLBACK )
    {
      ApplInmNmStatusIndicationGeneric( INM_CHANNEL_PARA_FIRST inmGenericCondition[INM_CHANNEL_IDX].status );
    }

    InmLeaveCriticalSection();
  }
}
#endif

#if defined ( INM_ENABLE_GENERIC_SUPPORT )
/**********************************************************************************************************************
  Name:         InmNmGenericTimeOut
  Parameter:    channel               handle of NM channel (only for multi-channel usage)
  Return value: ---
  Description:  This function informs the Nm_IndOsek that a timeout occured for the generic supervision.
**********************************************************************************************************************/
void InmNmGenericTimeOut( INM_CHANNEL_TYPE_ONLY )
{
  /* check if supervision is active */
  if( (inmGenericCondition[INM_CHANNEL_IDX].status & INM_SPV_ACTIVE) != 0 )
  {
    InmEnterCriticalSection();

    if( InmEventTimeout( &inmGenericCondition[INM_CHANNEL_IDX], InmGenericIncrement[INM_CHANNEL_IDX] ) == INM_STATUS_CALLBACK )
    {
      ApplInmNmStatusIndicationGeneric( INM_CHANNEL_PARA_FIRST inmGenericCondition[INM_CHANNEL_IDX].status );
    }

    InmLeaveCriticalSection();
  }
}
#endif

#if defined ( INM_ENABLE_GENERIC_SUPPORT )
/**********************************************************************************************************************
  Name:         InmNmGetGenericCondition
  Parameter:    channel               handle of NM channel (only for multi-channel usage)
  Return value: pStatus               pointer to status of generic supervision
  Description:  This function returns a pointer to the current status of the generic supervision.
**********************************************************************************************************************/
inmNmConditionType *InmNmGetGenericCondition( INM_CHANNEL_TYPE_ONLY )
{
  inmNmConditionType *rval;

  rval = &inmGenericCondition[INM_CHANNEL_IDX];

  return( rval );
}
#endif








/**********************************************************************************************************************
  Local function definitions
**********************************************************************************************************************/
/**********************************************************************************************************************
  Name:         InmEventTimeout
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
static vuint8 InmEventTimeout( inmNmConditionType * const pEvent, vuint8 value )
{
  vuint8 rval = INM_NO_STATUS_CALLBACK;

  pEvent->status &= (inmNmStatusType)(~(vuintx)INM_STAT_CHANGE);

  /* update supervision counter */
  if( pEvent->counter < (kInmCounterMax - value) )
  {
    pEvent->counter += value;
  }
  else
  {
    pEvent->counter = kInmCounterMax;
  }

  /* update dynamic failure */
  if( (pEvent->status & INM_FAILURE) == 0 )
  {
    pEvent->status |= INM_FAILURE;
    pEvent->status &= (inmNmStatusType)(~(vuintx)(INM_CONFIRMED));
    rval = INM_STATUS_CALLBACK;
  }

  if( pEvent->counter == kInmCounterMax )
  {
    /* update static failure */
    if( (pEvent->status & INM_STAT_FAILURE) == 0 )
    {
      pEvent->status |= ( INM_STAT_FAILURE | INM_STAT_CHANGE );
    }

    /* update confirmed information */
    if( (pEvent->status & INM_CONFIRMED) == 0 )
    {
      pEvent->status |= INM_CONFIRMED;
      rval = INM_STATUS_CALLBACK;
    }
  }

  return( rval );
}

/**********************************************************************************************************************
  Name:         InmEventOk
  Parameter:    
  Return value: 
  Description:  
**********************************************************************************************************************/
static vuint8 InmEventOk( inmNmConditionType * const pEvent, vuint8 value )
{
  vuint8 rval = INM_NO_STATUS_CALLBACK;

  pEvent->status &= (inmNmStatusType)(~(vuintx)INM_STAT_CHANGE);

  /* update failure */
  if( (pEvent->status & INM_FAILURE) != 0 )
  {
    pEvent->status &= (inmNmStatusType)(~(vuintx)(INM_FAILURE|INM_CONFIRMED));
    rval = INM_STATUS_CALLBACK;
  }

  /* check if supervision is active */
  if( (pEvent->status & INM_SPV_ACTIVE) != 0 )
  {
    /* update supervision counter */
    if( pEvent->counter > value )
    {
      pEvent->counter -= value;
    }
    else
    {
      pEvent->counter = 0;
    }

    if( pEvent->counter == 0 )
    {
      /* update static failure */
      if( (pEvent->status & INM_STAT_FAILURE) != 0 )
      {
        pEvent->status &= (inmNmStatusType)(~(vuintx)INM_STAT_FAILURE);
        pEvent->status |= INM_STAT_CHANGE;
      }

      /* update confirmed information */
      if( (pEvent->status & INM_CONFIRMED) == 0 )
      {
        pEvent->status |= INM_CONFIRMED;
        rval = INM_STATUS_CALLBACK;
      }
    }
  }

  return( rval );
}

/*--- Tx ------------------------------------------------------------------------------------------------------------*/
/**********************************************************************************************************************
  Name:         InmNmRxReInit
  Parameter:    index
  Return value: ---
  Description:  
**********************************************************************************************************************/
static void InmNmRxReInit( const inmNmIndexType index )
{
  /* re-initialize global variables */
  #if defined ( INM_ENABLE_USER_INIT )
  ApplInmNmRxUserReInit( index, &inmRxCondition[index] );
  #else
  inmRxCondition[index].status  &= (inmNmStatusType)(~(vuintx)INM_CONFIRMED_FAILURE);
  inmRxCondition[index].counter  = 0;
  #endif

  /* inform application about new status */
  ApplInmNmStatusIndicationRx( index, inmRxCondition[index].status );
}

/*--- Tx ------------------------------------------------------------------------------------------------------------*/
/**********************************************************************************************************************
  Name:         InmNmTxReInit
  Parameter:    channel               handle of NM channel (only for multi-channel usage)
  Return value: 
  Description:  
**********************************************************************************************************************/
static void InmNmTxReInit( INM_CHANNEL_TYPE_ONLY )
{
  /* re-initialize global variables */
  #if defined ( INM_ENABLE_USER_INIT )
  ApplInmNmTxUserReInit( INM_CHANNEL_PARA_FIRST &inmTxCondition[INM_CHANNEL_IDX] );
  #else
  inmTxCondition[INM_CHANNEL_IDX].status  &= (inmNmStatusType)(~(vuintx)INM_CONFIRMED_FAILURE);
  inmTxCondition[INM_CHANNEL_IDX].counter  = 0;
  #endif

  /* re-initialize local variables */
  inmCTxNOk[INM_CHANNEL_IDX]  = 0;

  /* inform application about new status */
  ApplInmNmStatusIndicationTx( INM_CHANNEL_PARA_FIRST inmTxCondition[INM_CHANNEL_IDX].status );
}

#if defined (INM_ENABLE_GENERIC_SUPPORT)
/*--- Generic --------------------------------------------------------------------------------------------------------*/
/**********************************************************************************************************************
  Name:         InmNmGenericReInit
  Parameter:    channel               handle of NM channel (only for multi-channel usage)
  Return value: 
  Description:  
**********************************************************************************************************************/
static void InmNmGenericReInit( INM_CHANNEL_TYPE_ONLY )
{
  /* re-initialize global variables */
  #if defined ( INM_ENABLE_USER_INIT )
  ApplInmNmGenericUserReInit( INM_CHANNEL_PARA_FIRST &inmGenericCondition[INM_CHANNEL_IDX] );
  #else
  inmGenericCondition[INM_CHANNEL_IDX].status  &= (inmNmStatusType)(~INM_CONFIRMED_FAILURE);
  inmGenericCondition[INM_CHANNEL_IDX].counter  = 0;
  #endif

  /* inform application about new status */
  ApplInmNmStatusIndicationGeneric( INM_CHANNEL_PARA_FIRST inmGenericCondition[INM_CHANNEL_IDX].status );
}
#endif



/**********************************************************************************************************************
  EOF
**********************************************************************************************************************/
/* ORGANI: STOPSINGLE_OF_MULTIPLE */
