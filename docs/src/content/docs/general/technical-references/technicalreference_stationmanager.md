---
title: "Technical Reference: Station Manager (Nm_StMgrIndOsek_Ls)"
description: "Converted Vector delivery document — searchable text extraction; the original PDF/HTML remains authoritative."
---
<!-- markdownlint-disable MD009 MD012 MD030 MD046 -->

> **Source:** `/Doc/TechnicalReferences/TechnicalReference_Stationmanager.pdf` — Vector-proprietary PDF, converted automatically to Markdown for browsing.  
> Text was extracted with `pypdf`; headings/lists/tables/images are **not** faithfully preserved. 
> The PDF itself remains the authoritative document.

## Document information

- **Group:** NM module
- **Pages:** 35
- **PDF Title:** Nm_Stmgr_Ls
- **Author(s):** Marco Pfalzgraf
- **Subject:** Technical Reference
- **Version:** 
- **Category:** 
- **Company:** Vector Informatik GmbH
- **Comments:** 

## PDF bookmarks (outline)

- Nm_StMgrIndOsek_Ls
- 1 History
-   1.1 SM Version
- 2 Introduction
-   2.1 Reference Documents
-   2.2 Abbreviations
-   2.3 Tasks and Aims
- 3 Network management states
-   3.1 Organ Type 1 
-     3.1.1 Description of internal States for organ type 1:
-   3.2 Organ Type 2
-     3.2.1 Description of internal States for organ type 2 :
-   3.3 Organ Type 3
-     3.3.1 Description of internal States for organ type 3 :
-   3.4 Organ Type 4 
-     3.4.1 Description of internal States for organ type 4 :
- 4 Integration into the application
-   4.1  Delivery Items
-   4.2 Version Changes
-   4.3 Handling of the station-manager
-   4.4 Particularities if there is no Interaction Layer in the system
-     4.4.1 Event transmission of the supervised Tx message
-   4.5 Start delay time of Tx messages
-     4.5.1 Start delay time without Interaction Layer
-   4.6 Reading of Nerr state
-   4.7 Handling of the signal Interd_Memo_Def
-   4.8 Handling of Lmin
-     4.8.1 First value and Indication flags
-     4.8.2 Timeout flags and functions
-     4.8.3 Impact on the application

## Detected section headings (heuristic)

- 4.4.1 Event transmission of the supervised Tx message............................. 9
- 4.9.1 Configuration of the TP when using CanCanelTransmit()................. 14
- 6.2.1 SmInitPowerOn: Initialisation of the station-manager ....................... 20
- 6.2.3 SmGetStatus: Read the internal status of ECU ................................ 20
- 6.2.4 SmGetVolCNerr: Read the Value of the volatile Nerr Counter (Macro)
- 6.2.5 SmSetVolCNerr: Set the Value of the volatile Nerr Counter (Macro) 21
- 6.2.6 SmGetVolCPerteCom: R ead the Value of the volatile PerteCom
- 6.3 SmSetVolCPerteCom: Set the Value of the volatile PerteCom Counter
- 6.3.1 SmGetVolCBoff: Read the Value of the volatile BusOff Counter
- 6.3.2 SmSetVolCBoff: Set the Value of the volatile BusOff Counter (Macro)
- 6.3.3 SmSetWakeUpRequest: A CAN frame was received and woke up the
- 6.3.4 SmSetNetworkRequest: Release a Network Request to the network
- 6.3.5 SmReleaseNetworkRequest: Release a Network Request to the
- 6.3.7 SmTransmitNmMessage: Tranmsit the supervised Tx message on
- 6.4.1 ApplSmStatusIndicationTx: Status of transmission indication .......... 24
- 6.4.2 ApplSmStatusIndicationRx: Status of reception indication ............... 24
- 6.4.3 ApplSmStatusIndicationNerr: Status of Nerr Pin indication .............. 24
- 6.4.4 ApplSmStatusIndication: State of ECU has changed ....................... 25
- 6.4.5 ApplCanErrorPin: Get Status of Transceiver Error Pin ..................... 25
- 6.4.6 ApplSmGetInterdMemoDef: Get Status of filtered Interd_Memo_Def
- 6.4.7 ApplSmSetNVAbsentCount: Set the non volatile Rx counter ........... 25
- 6.4.8 ApplSmSetNVMuteCount: Set the non volatile Tx counter ............... 26
- 6.4.9 ApplSmSetNVNerrCount: Set the non volatile Nerr counter ............. 26
- 6.4.10 ApplSmGetNVAbsentCount: Get the non volatile Rx counter ....... 26
- 6.4.11 ApplSmGetNVMuteCount: Get the non volatile Tx counter........... 26
- 6.4.12 ApplSmGetNVNerrCount: Get the non volatile Nerr counter......... 27
- 6.4.13 ApplSmTrcvOn: Switch on the transceiver .................................... 27
- 6.4.14 ApplSmTrcvOff: Switch off the transceiver .................................... 27
- 6.4.16 ApplNwmBusOffEnd: Bus off recovery ended ............................... 28
- 6.4.17 ApplSmFatalError: Error in assertion occurred.............................. 28

## Extracted text (beginning of document)

_Showing first 12000 of ~64793 extracted characters across 35 pages._

```text
Nm_StMgrIndOsek_Ls 
Technical Reference 
Station Manager (Low Speed) 
 
 
 
 
 
 
 
Version 3.05 
Date 2011-07-29 
File TechnicalReference_Stationmanager.doc 
Number of Pages 35 
 

 Station manager for PSA Technical Reference 1 
1 History ............................................................................................................ 5 
1.1 SM Version................................................................................................ 5 
2 Introduction.................................................................................................... 5 
2.1 Reference Documents............................................................................... 5 
2.2 Abbreviations ............................................................................................ 5 
2.3 Tasks and Aims......................................................................................... 6 
3 Network management states ........................................................................ 6 
3.1 Organ Type 1 ............................................................................................ 6 
3.1.1 Description of internal States for organ type 1:................................... 6 
3.2 Organ Type 2 ............................................................................................ 7 
3.2.1 Description of internal States for organ type 2 :.................................. 7 
3.3 Organ Type 3 ............................................................................................ 7 
3.3.1 Description of internal States for organ type 3 :.................................. 7 
3.4 Organ Type 4 ............................................................................................ 8 
3.4.1 Description of internal States for organ type 4 :.................................. 8 
4 Integration into the application .................................................................... 8 
4.1 Delivery Items ........................................................................................... 8 
4.2 Version Changes....................................................................................... 9 
4.3 Handling of the station-manager ............................................................... 9 
4.4 Particularities if there is no Interaction Layer in the system....................... 9 
4.4.1 Event transmission of the supervised Tx message............................. 9 
4.5 Start delay time of Tx messages ............................................................... 9 
4.5.1 Start delay time without Interaction Layer........................................... 9 
4.6 Reading of Nerr state .............................................................................. 10 
4.7 Handling of the signal Interd_Memo_Def ................................................ 10 
4.8 Handling of Lmin ..................................................................................... 10 
4.8.1 First value and Indication flags ......................................................... 11 
4.8.2 Timeout flags and functions.............................................................. 11 
4.8.3 Impact on the application.................................................................. 11 
4.8.4 Access to the actual DLC ................................................................. 12 
4.9 Cancel of pending transmit messages .................................................... 12 
©2011, Vector Informatik GmbH TechnicalR eference_Stationmanager.doc Version 3.05 

 Station manager for PSA Technical Reference 2 
4.9.1 Configuration of the TP when using CanCanelTransmit()................. 14 
4.9.2 Example Code .................................................................................. 14 
4.10 Handling of the version message......................................................... 14 
4.11 Configuring the Part Offline mode....................................................... 14 
4.12 Supervision Reset on Request of the Diagnosis.................................. 15 
5 Sleep and Wake Up sequence PSA............................................................ 15 
5.1 Transition from Sleep ( Veille ) to WakeUp ( Reveil ) .............................. 15 
5.1.1 External event ( Organ type 1, 2 and 4 ):.......................................... 16 
5.1.2 Bus event ( Organ type 1, 2 and 4 )................................................. 16 
5.1.3 +CAN activation Organ type 1 and 2 ................................................ 17 
5.1.4 +CAN activation Organ type 3 .......................................................... 17 
5.2 Transition to Veille................................................................................... 18 
5.2.1 Organ type 1,2 and 4........................................................................ 18 
5.2.2 Organ type 3..................................................................................... 18 
5.3 Setting and Releasing a Request for the network ................................... 19 
5.4 Indication of the +CAN signal to the Station manager............................. 19 
6 API of the station-manager ......................................................................... 19 
6.1 Version of the source code...................................................................... 19 
6.2 station-manager services called by the application ................................. 20 
6.2.1 SmInitPowerOn: Initialisation of the station-manager ....................... 20 
6.2.2 SmTask: cyclic Task......................................................................... 20 
6.2.3 SmGetStatus: Read the internal status of ECU ................................ 20 
6.2.4 SmGetVolCNerr: Read the Value of the volatile Nerr Counter (Macro)
 20 
6.2.5 SmSetVolCNerr: Set the Value of the volatile Nerr Counter (Macro) 21 
6.2.6 SmGetVolCPerteCom: R ead the Value of the volatile PerteCom 
Counter (Macro)............................................................................................. 21 
6.3 SmSetVolCPerteCom: Set the Value of the volatile PerteCom Counter 
(Macro).............................................................................................................. 21 
6.3.1 SmGetVolCBoff: Read the Value of the volatile BusOff Counter 
(Macro) 21 
6.3.2 SmSetVolCBoff: Set the Value of the volatile BusOff Counter (Macro)
 22 
©2011, Vector Informatik GmbH TechnicalR eference_Stationmanager.doc Version 3.05 

 Station manager for PSA Technical Reference 3 
6.3.3 SmSetWakeUpRequest: A CAN frame was received and woke up the 
ECU 22 
6.3.4 SmSetNetworkRequest: Release a Network Request to the network 
management.................................................................................................. 22 
6.3.5 SmReleaseNetworkRequest: Release a Network Request to the 
network management .................................................................................... 22 
6.3.6 SmSetPlusCanState(state)............................................................... 23 
6.3.7 SmTransmitNmMessage: Tranmsit the supervised Tx message on 
next call of SmTask() ..................................................................................... 23 
6.4 Application functions required by the station-manager............................ 24 
6.4.1 ApplSmStatusIndicationTx: Status of transmission indication .......... 24 
6.4.2 ApplSmStatusIndicationRx: Status of reception indication ............... 24 
6.4.3 ApplSmStatusIndicationNerr: Status of Nerr Pin indication .............. 24 
6.4.4 ApplSmStatusIndication: State of ECU has changed ....................... 25 
6.4.5 ApplCanErrorPin: Get Status of Transceiver Error Pin ..................... 25 
6.4.6 ApplSmGetInterdMemoDef: Get Status of filtered Interd_Memo_Def 
Bit 25 
6.4.7 ApplSmSetNVAbsentCount: Set the non volatile Rx counter ........... 25 
6.4.8 ApplSmSetNVMuteCount: Set the non volatile Tx counter ............... 26 
6.4.9 ApplSmSetNVNerrCount: Set the non volatile Nerr counter ............. 26 
6.4.10 ApplSmGetNVAbsentCount: Get the non volatile Rx counter ....... 26 
6.4.11 ApplSmGetNVMuteCount: Get the non volatile Tx counter........... 26 
6.4.12 ApplSmGetNVNerrCount: Get the non volatile Nerr counter......... 27 
6.4.13 ApplSmTrcvOn: Switch on the transceiver .................................... 27 
6.4.14 ApplSmTrcvOff: Switch off the transceiver .................................... 27 
6.4.15 ApplNwmBusOff: Bus off indication............................................... 27 
6.4.16 ApplNwmBusOffEnd: Bus off recovery ended ............................... 28 
6.4.17 ApplSmFatalError: Error in assertion occurred.............................. 28 
7 Configuration of the station-manager........................................................ 29 
7.1 General Configuration ............................................................................. 29 
7.2 Status Callback functions........................................................................ 29 
7.2.1 ECU StateChange Callback: ............................................................ 29 
7.2.2 Fault State Support:.......................................................................... 29 
©2011, Vector Informatik GmbH TechnicalR eference_Stationmanager.doc Version 3.05 

 Station manager for PSA Technical Reference 4 
7.2.3 Fault Storage Support:...................................................................... 30 
7.2.4 Bus Off Callback Support : ............................................................... 30 
7.2.5 Bus Off End Callback Support: ......................................................... 30 
7.2.6 Use Flag InterdMemoDef.................................................................. 30 
7.2.7 ECU State Change in Task Context ................................................. 30 
7.2.8 N_as Timeout Handling .................................................................... 30 
7.2.9 Sleep Management........................................................................... 30 
7.2.10 Task cycle ..................................................................................... 30 
7.2.11 Debug Support .............................................................................. 31 
8 Database attributes ..................................................................................... 32 
8.1 Receive Message Attribute ..................................................................... 32 
8.2 Signal Attribute........................................................................................ 33 
9 Precautions .................................................................................................. 34 
9.1 Calling CanSleep(…); wit hin status callback ........................................... 34 
 
©2011, Vector Informatik GmbH TechnicalR eference_Stationmanager.doc Version 3.05 

 Station manager for PSA Technical Reference 5 
1 History 
 
Author Date Version Remarks 
Dieter Schaufelberger 2008-01-29 3.00 creation of this document 
Dieter Schaufelberger 2008-02-12 3.01 Firest corrections 
Dieter Schaufelberger 2008-03-14 3.02 Added new API, modify Sleep/WakeUp 
Dieter Schaufelberger 2008-06-25 3.03 Minor corrections 
Dieter Schaufelberger 2008-07-11 3.04 Added support of start delay time 
Marco Pfalzgraf 2011-07-28 3.05 Update of user specification [INM PSA] 
1.1 SM Version 
This document refers to version 3.03.00 of the station-manager for the PSA Low Speed 
Fault Tolerant bus. 
2 Introduction 
The aim of this document is to describe the handling of the station-manager for PSA. 
This document contains 
 a short description of the station-manager 
 the condition for using the station-manager 
 the interfaces of the user program for the station-manager 
This chapter gives a brief overview of the tasks and aims of the station-manager. 
Please refer also to the specification of the Indirect Network Management [INM PSA]. 
2.1 R

... [truncated — 52793 further characters not shown; see the original PDF] ...
```

## Original file

- Repository path: `/Doc/TechnicalReferences/TechnicalReference_Stationmanager.pdf`

[Back to top](#_top)
