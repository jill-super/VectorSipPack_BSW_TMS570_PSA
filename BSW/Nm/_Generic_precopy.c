/*******************************************************************************
|      Project Name: GenericPrecopy   F O R   P S A 
|         File Name: Generic_precopy.c
|
|       Description: Dispatcher for PSA
|                    Low Speed Fault Tolerant Bus 
|
|-------------------------------------------------------------------------------
|               C O P Y R I G H T
|-------------------------------------------------------------------------------
| Copyright (c) 2001-2008 Vector Informatik GmbH           All rights reserved.
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
| Sf           Dieter Schaufelberger     Vector Informatik GmbH
|-------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-------------------------------------------------------------------------------
| Date        Ver    Author  Description
| ---------   -----  ------  ---------------------------------------------------
| 2008-01-23   2.00   Sf      Implementation for PSA SLP4
| 2008-02-12   2.01   Sf      Removed inmkIncGeneric and inmkDecGeneric
| 2008-03-18   2.02   Sf      added RI 1.5 switch for dlcReceived
*******************************************************************************/
#include "can_inc.h"
# if defined( C_SINGLE_RECEIVE_BUFFER )
extern vuint8 IlCanGenericPrecopy( CanReceiveHandle rcvObject )
#  define ilCanGenericPrecopyRcvObject  (rcvObject);
# endif

# if defined( C_MULTIPLE_RECEIVE_BUFFER )
extern vuint8 IlCanGenericPrecopy( CanReceiveHandle rcvObject, pChipDataPtr dptr );
#  define ilCanGenericPrecopyRcvObject  (rcvObject)
# endif

# if defined(C_SINGLE_RECEIVE_CHANNEL) || defined(C_MULTIPLE_RECEIVE_CHANNEL)
extern vuint8 IlCanGenericPrecopy( CanRxInfoStructPtr rxStruct );
#  define ilCanGenericPrecopyRcvObject  (rxStruct->Handle)
# endif

#if defined ( VGEN_ENABLE_NM_OSEK_I_HS )
#include "NmStMgrHs.h"
#endif

#if defined ( VGEN_ENABLE_NM_OSEK_I )
#include "Stat_Mgr.h"
#endif

#if defined ( VGEN_ENABLE_NM_OSEK_I_HS )
extern V_MEMROM0 vuint8 MEMORY_ROM HsSmInmCanRxMinMsgLen[kCanNumberOfRxObjects];
#elif defined ( VGEN_ENABLE_NM_OSEK_I )
#if (C_VERSION_REF_IMPLEMENTATION < 0x150u)
extern V_MEMROM0 vuint8 MEMORY_ROM SmCanRxMinMsgLen[kCanNumberOfRxObjects];
#endif
#else
 #error "Invalid configuration! Neither Nm_StMgrIndOsek_Ls or _Hs active!"
#endif

/******************************************************************************
* NAME:               SmCanGenericPrecopy
* CALLED BY:          CAN driver (specific precopy function)
* Preconditions:      enabled CAN (Rx) interrupts
* PARAMETER:          none
* RETURN VALUE:       kCan
* Description:        
*******************************************************************************/
# if defined( C_SINGLE_RECEIVE_BUFFER )
C_CALLBACK_1 canuint8 C_CALLBACK_2 SmCanGenericPrecopy( CanReceiveHandle rcvObject )
# define CANRXACTUALDLC CanRxActualDLC
# endif
# if defined( C_MULTIPLE_RECEIVE_BUFFER )
C_CALLBACK_1 canuint8 C_CALLBACK_2 SmCanGenericPrecopy( CanReceiveHandle rcvObject, pChipDataPtr dptr )
# define CANRXACTUALDLC CanRxActualDLC
# endif
# if defined(C_SINGLE_RECEIVE_CHANNEL) || defined(C_MULTIPLE_RECEIVE_CHANNEL)
C_CALLBACK_1 canuint8 C_CALLBACK_2 SmCanGenericPrecopy( CanRxInfoStructPtr cris )
#  define rcvObject  (cris->Handle)
#  define CANRXACTUALDLC CanRxActualDLC(cris)
# endif
{ 
#if (C_VERSION_REF_IMPLEMENTATION < 0x150u)
  vuint8 dlcReceived;
#endif
  vuint8 rval = kCanNoCopyData;

#if ( kCanNumberOfChannels >1 )
    CanChannelHandle can_channel;
    can_channel = cris->Channel;
#endif

#if (C_VERSION_REF_IMPLEMENTATION < 0x150u)
    /* check for DLC */
    dlcReceived = CANRXACTUALDLC;
#if defined ( VGEN_ENABLE_NM_OSEK_I_HS )
    if ( dlcReceived >= HsSmInmCanRxMinMsgLen[rcvObject] )
#else
    if ( dlcReceived >= SmCanRxMinMsgLen[rcvObject] )
#endif
    {
#if defined(C_ENABLE_VARIABLE_RX_DATALEN)
      CanSetVariableRxDatalen (rcvObject, dlcReceived );
#endif
#endif /* REF < 150 */
      
  #if ( kCanNumberOfChannels > 1 )
    /* multi channel system */
    #error "Please check and adapt the channel assignment for multichannel systems."
    #error "Remove this error code afterwards" 

    /* *** ADAPT THIS SECTION ACCORDING TO YOUR SYSTEM SETUP *** */
    if ( can_channel == 0 )
    {
      SmPrecopy( cris );
    }
    else
    {
      HsSmPrecopy( cris );
    }
  #else
    /* single channel system */
    #if defined ( VGEN_ENABLE_NM_OSEK_I_HS ) && \
        defined ( VGEN_ENABLE_NM_OSEK_I )
      #error "Invalid configuration: There can be no Nm_StMgrIndOsek_Ls and _Hs on a single CAN channel"
    #endif

    #if defined ( VGEN_ENABLE_NM_OSEK_I_HS )
    HsSmPrecopy( cris );
    #endif

    #if defined ( VGEN_ENABLE_NM_OSEK_I )
    SmPrecopy( cris );
    #endif

  #endif
    rval = kCanCopyData;
#if ( C_VERSION_REF_IMPLEMENTATION < 0x150u)
  } 
  else
  { 
    /* DLC is too short */
  } 
#endif
  return ( rval );
}
#if defined (VGEN_ENABLE_IL_VECTOR )
# if defined(C_SINGLE_RECEIVE_BUFFER)
canuint8 GenCanGenericPrecopy(CanReceiveHandle rxObject) {
   if(SmCanGenericPrecopy(rxObject) == kCanCopyData)
   {
      return IlCanGenericPrecopy(rxObject);
   }
   return kCanNoCopyData;
}
# endif

# if defined( C_MULTIPLE_RECEIVE_BUFFER )
canuint8 GenCanGenericPrecopy(CanReceiveHandle rxObject, CanChipDataPtr rxDataPtr) {
   if(SmCanGenericPrecopy(rxObject, rxDataPtr) == kCanCopyData)
   {
      return IlCanGenericPrecopy(rxObject, rxDataPtr);
   }
   return kCanNoCopyData;
}
# endif
# if defined(C_SINGLE_RECEIVE_CHANNEL) || defined(C_MULTIPLE_RECEIVE_CHANNEL)
canuint8 GenCanGenericPrecopy(CanRxInfoStructPtr cris) {
   if(SmCanGenericPrecopy(cris) == kCanCopyData)
   {
      return IlCanGenericPrecopy(cris);
   }
   return kCanNoCopyData;
}
# endif
#endif
/************   Organi, Version 3.6.2 Vector-Informatik GmbH  ************/
