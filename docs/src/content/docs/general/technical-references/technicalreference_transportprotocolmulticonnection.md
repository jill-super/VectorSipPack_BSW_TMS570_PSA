---
title: "Technical Reference: Transport Protocol ISO 15765-2"
description: "Converted Vector delivery document — searchable text extraction; the original PDF/HTML remains authoritative."
---
<!-- markdownlint-disable MD009 MD012 MD030 MD046 -->

> **Source:** `/Doc/TechnicalReferences/TechnicalReference_TransportProtocolMultiConnection.pdf` — Vector-proprietary PDF, converted automatically to Markdown for browsing.  
> Text was extracted with `pypdf`; headings/lists/tables/images are **not** faithfully preserved. 
> The PDF itself remains the authoritative document.

## Document information

- **Group:** TP module
- **Pages:** 177
- **PDF Title:** YourTopic
- **Author(s):** Oliver Garnatz, Andreas Pick, Peter Herrmann, Thomas Dedler
- **Subject:** 
- **Version:** 
- **Category:** 
- **Company:** 
- **Comments:** 

## PDF bookmarks (outline)

- 1 Introduction
-   1.1 Relation between general component and shipped version capability
-   1.2 Name Conventions
-   1.3 Abbreviations
-   1.4 Channel vs. Connection
-   1.5 TP classes
-     1.5.1 SingleTP classes
-     1.5.2 Static MultiTP classes
-     1.5.3 Dynamic MultiTP classes
-     1.5.4 Dispatched MultiTP classes
-   1.6 SingleConnection vs. MultipleConnection
-   1.7 Features
-     1.7.1 Feature List
- 2 Architecture Overview
-   2.1 Requirements
-     2.1.1 Protocol-Overview
-       2.1.1.1 Construction of unsegmented messages
-       2.1.1.2 Construction of segmented messages
-     2.1.2 Addressing modes
-       2.1.2.1 Normal Addressing
-       2.1.2.2 Mixed 11-bit ID Addressing
-       2.1.2.3 Normal Fixed Addressing
-       2.1.2.4 Extended Addressing
-       2.1.2.5 Mixed 29-bit ID Addressing
-       2.1.2.6 Structure of TPCI-Byte
-   2.2 Transmission
-   2.3 Reception
-   2.4 Working behaviors
-     2.4.1 Timings
-     2.4.2 Error detection

## Detected section headings (heuristic)

- 3.04.00 Added description for
- 3.13 ESCAN00051019: Added
- 2.5.3.1 Handling of unexpected FlowControl / ConsecutiveFrame frames .......... 37
- 4.2.2.1 TpRxSetConnectionNumber: Assign a Connection-Number to a
- 4.2.2.2 TpRxGetConnectionNumber: Get the Corresponding Connection-
- 4.2.2.3 TpRxGetAddressingFormat: Get the current addressing type ................ 73
- 4.2.2.4 TpRxGetAssignedDestination: Get the currently assigned destination .. 74
- 4.2.2.7 TpRxSetBS: Setting up BlockSize on Reception Side ............................ 77
- 4.2.2.9 TpRxSetSTMIN: Setting up STMin time on Reception Side .................... 78
- 4.2.2.10 TpRxGetSTMIN: Get STMin time on Reception Side.............................. 79
- 4.2.2.12 TpRxGetChannelExtID: Get Received Extended CAN-Id ....................... 81
- 4.2.2.14 TpRxGetSourceAddress: Get received Source Address ......................... 82
- 4.2.2.15 TpRxGetReceivedTargetAddress: Get received Target Address ............. 83
- 4.2.2.17 TpRxGetParameterGroupIdentification: Get Identification of PGN .......... 84
- 4.2.2.18 TpRxSetBufferOverrun: Enable partial acceptance............................... 85
- 4.2.2.20 TpRxSetTransmitExtID: Set transmission Extended CAN-Id................. 87
- 4.2.2.21 TpRxGetChannelIDType: Get the type of the received CAN-Id ............. 88
- 4.2.2.22 TpRxGetAddressExtension: Get address extension information ............ 88
- 4.2.2.24 TpRxSetWaitCorrectSN: Force to wait for a correct sequence
- 4.2.2.25 TpRxSetTimeoutConfirmation: Set CAN confirmation timeout ............... 91
- 4.2.2.26 TpRxSetTimeoutCF: Set Consecutive Frame confirmation timeout ....... 92
- 4.2.2.27 TpRxSetFCStatus: set up Flow Control on reception side ..................... 92
- 4.2.2.28 TpRxGetFCStatus: get the Flow Control setup on reception side .......... 93
- 4.2.2.29 TpRxSetClearToSend: proceed with the transmission after FC wait
- 4.2.2.30 TpRxWithoutFC: suppress FC frame usage at the Rx side .................... 95
- 4.2.2.32 TpRxSetPriorityBits: Set Priority, Data Page and Reserved bits ............. 97
- 4.2.3.1 TpTxGetFreeChannel: Assign Channel to Connection ........................... 98
- 4.2.3.2 TpTxGetConnectionNumber: Get the assigned Connection-Number ...... 99
- 4.2.3.3 TpTxGetConnectionStatus: Get the Connection Status .......................... 99
- 4.2.3.4 TpTxGetTargetAddress: Get the target address used for transmission 100

## Extracted text (beginning of document)

_Showing first 12000 of ~267038 extracted characters across 177 pages._

```text
Technical Reference Transport Protocol ISO15765-2 
2013, Vector Informatik GmbH Version: 3.14.00 
based on template version 5.1.0 
1 / 177 
 
 
 
 
 
 
 
 
 
 
 
Transport Protocol ISO15765-2 
Technical Reference 
 
Single/Multiple Connection 
Version 3.14.00 
 
 
 
 
 
 
 
 
 
 
Authors Oliver Garnatz, Andreas Pick, Peter Herrmann, 
Thomas Dedler 
Status Released 
 
 
 
 
 

Technical Reference Transport Protocol ISO15765-2 
2013, Vector Informatik GmbH Version: 3.14.00 
based on template version 5.1.0 
2 / 177 
Document Information 
History 
Author Date Version Remarks 
Rein 1999-06-22 1.0 File created 
Baeuerle 1999-11-02 1.42 Description of connection 
specific timing parameters 
added 
Ebner 2000-07-17 1.51 Single connection version 
removed; documents only 
contains multiple connection 
extensions 
Garnatz 2000-09-19 2.03 Adaptation to new 
MultiConnection TP 
Garnatz 2001-02-09 2.07 Added new functionality 
Garnatz 2001-05-11 2.10 Update new Generation Tool 
versions 
Garnatz 2001-09-14 2.17 General improvement; 
Update to version 2.17 of 
tpmc.c module 
Garnatz 2002-01.24 2.27 SingleConnection version is 
added; Protocol-Overview is 
added 
Garnatz 2002-06-18 2.33 Added restrictions for data 
consistency 
Pick / Garnatz 2002-10-16 2.36 Update: CAN Driver in polling 
mode 
Added: Fast transmission of 
ConsecutiveFrames 
Update: Usage of TransmitCF 
parameter 
Garnatz 2002-11-29 2.37 General rework 
Garnatz 2003-01-16 2.39 Update: 
TpTransmit/CopyToCan/Appl
TpCheckTA 
Garnatz 2004-01-13 2.44 Update: ApplTpCopyToCAN 
Pick 2004-03-01 2.52 Update: Mixed 29-bit ID 
addressing 
TpRxGetCanBuffer 
TpRxSetBufferOverrun 
TpRxGetAddressExtension 
TpTxSetAddressExtension 
Pick 2004-05-14 2.60 Multiple ECUs example 
Restriction on 
TpTxStateTask/TpRxStateTas
k 
Tx/Rx message buffer 

Technical Reference Transport Protocol ISO15765-2 
2013, Vector Informatik GmbH Version: 3.14.00 
based on template version 5.1.0 
3 / 177 
consistency clarification 
Return value of 
ApplTpPreCopyCheck 
Mixed 11-bit ID addressing 
TpTransmit() return values 
Added TpCanChannelInit() 
Added TpRxSetTransmitID() 
Changed 
TpRxSetBufferOverrun 
Changed 
ApplTpTxCopyToCAN 
Changes in chapter ‘How to 
serve Different 
 Connections (only 
dynamic channels)’. 
Pick 2004-12-01 2.68 Added description for GENy 
configuration tool 
(ESCAN00008734). 
Update of API description 
(ESCAN00008314). 
Feature list added 
(ESCAN00008315). 
Prototype parameter 
corrected (ESCAN00009965) 
 
Pick 2005-04-07 2.72.00 Added description for multiple 
addressing systems. 
C++ access to TPMC. 
Pick 2005-07-14 2.73.00 Added description for GENy 
configuration 
Herrmann 2005-07-19 2.73.00 Added new API functions: 
TpRxSetWaitCorrectSN, 
TpTxSetStrictFlowControlChe
ck 
Herrmann 2005-08-11 2.73.00 Added new API functions: 
TpRxSetTimeoutConfirmation
, 
TpTxSetTimeoutConfirmation, 
TpRxSetTimeoutCF, 
TpTxSetTimeoutCF 
Garnatz 2006-01-13 2.80.00 Added deviation to ISO 
15765-2 
Herrmann 2006-02-08 2.82.00 ISO 15765-2 deviations 
elaborated 
Herrmann 2006-03-03 2.86.00 Cleanup (ESCAN15514) 
Herrmann 2006-03-23 2.86.00 ISO 15765-2 deviations 
elaborated 
Herrmann 2006-04-11 2.87.00 General rework after review 
Herrmann 2006-07-03 2.89.00 Added WaitFrame handling. 

Technical Reference Transport Protocol ISO15765-2 
2013, Vector Informatik GmbH Version: 3.14.00 
based on template version 5.1.0 
4 / 177 
Herrmann 2007-02-01 2.90.00 Added OEM feature 
TP_ENABLE_STRICT_DL_C
HECK 
Herrmann 2007-02-23 2.91.00 Added feature 
TP_DISABLE_MF_RECEPTI
ON 
Herrmann 2007-03-14 2.92.00 Added ApplFuncTpPrecopy 
callback description and 
reduced TpRxResetChannel 
API usage to indication point 
in time or after. 
Herrmann 2007-09-20 2.93.00 Completed Multiple ECU 
description (see chapter 
7.3.1). Added TpRxGet-
AddressingFormat / 
AssignedDestination 
description. 
 VERSION 3.xx 
Herrmann 2007-10-15 3.00.00 Added description for new 
TpClass 
“Dispatched<AddressingType>” 
Herrmann 2007-11-20 3.01.00 Cosmetics / Syntax 
Herrmann 2008-01-14 3.02.00 New API: 
TpTxGetTargetAddress 
Herrmann 2008-02-12 3.03.00 Minor corrections within API 
descriptions 
(ApplTpTxErrorIndication, 
TpRxGetCanBuffer) 
Herrmann 2008-04-17, 
 
2008-07-17 
3.04.00 Added description for 
TP_ENBLE_DYN_CHANNEL_TIM
ING. 
Added description for the usage 
of extended identifiers for 
normal addressing as well at 
configuration time as also 
dynamically at runtime 
(TP_USE_EXT_IDS_FOR_NO
RMAL). 
Herrmann 2008-12-10 3.05.00 Added description for 
GenMsgDelay attribute in 
chapter 3.4.1 
Herrmann 2009-01-25 3.07.00 Adapted version number to 
ALM package number (3.06.00 
skipped) 
Herrmann 2009-11-25 3.08.00 Added description for reception 
and transmission without flow 
control frames for dyn. 
(TpRxWithoutFC, 
TpTxWithoutFC) and static 

Technical Reference Transport Protocol ISO15765-2 
2013, Vector Informatik GmbH Version: 3.14.00 
based on template version 5.1.0 
5 / 177 
(TpTxFlowControl, 
TpRxFlowControl 
) Tp classes. 
Herrmann 2010-01-12 3.09.00 Enhanced description for DLC 
checks on the Rx side (see 
2.4.2.5). 
Added API functions for 29-Bit 
ext. Id dynamic handling. 
Heil 2010-11-08 3.10.00 Added more flexibility for DLC 
checks on the Rx side (see 
2.4.2.5) 
Herrmann 2011-01-19 3.11.00 Moved 
TP_MEMORY_MODEL_DATA 
from user config file to GENy 
Herrmann 2011-04-05 3.12 ESCAN00051019: Added new 
(customer specific) pre-compile 
switches: 
TP_ENABLE_IGNORE_FC_RE
S_STMIN, 
TP_ENABLE_IGNORE_FC_OV
FL (see 3.2.3). 
Herrmann 
 
Dedler 
2011-07-11 
 
2011-09-21 
3.13 ESCAN00051019: Added 
support for the dynamic setting 
of 29-bit CAN-IDs (see 
4.2.2.31, 4.2.2.32, 4.2.3.29, 
4.2.3.30). 
Added new pre-compile switch: 
TP_USE_UNEXPECTED_FC_
CANCELATION (see 3.2.3). 
Dedler 2012-04-10 3.13.01 Description of 
TpRxGetCanBuffer modified 
according to ESCAN00057225 
Dedler 2013-04-30 3.14.00 Description for non-standard 
flow control handling updated 
(3.2.3) 
 
Reference Documents 
No. Title 
[1] /ISO/TF2/: ISO FDIS 15765-2; Road vehicles — Diagnostics on CAN — Part 2: Network 
layer services; 
Date 2004-07-16 
[2] /OSEK-COM/: OSEK/VDX Communication Version 2.1, revision 1 17th June 1998 
[3] /CANDrv/: Manual for CAN Driver in used version 
[4] ISO15765-2: ISO TC 22/SC 3; ISO 15765-2:2003(E); Road vehicles — Diagnostics on 
controller area network (CAN) — Part 2: Part 2: Network layer services 
 

Technical Reference Transport Protocol ISO15765-2 
2013, Vector Informatik GmbH Version: 3.14.00 
based on template version 5.1.0 
6 / 177 
 
 
Caution 
We have configured the programs in accordance with your specifications in the 
questionnaire. Whereas the programs do support other configurations than the one 
specified in your questionnaire, Vector´s release of the programs delivered to your 
company is expressly restricted to the configuration you have specified in the 
questionnaire. 
 
 

Technical Reference Transport Protocol ISO15765-2 
2013, Vector Informatik GmbH Version: 3.14.00 
based on template version 5.1.0 
7 / 177 
Contents 
1 Introduction ................................ ................................ ................................ .................. 15 
1.1 Relation between general component and shipped version capability .................... 15 
1.2 Name Conventions ................................ ................................ ................................ . 16 
1.3 Abbreviations ................................ ................................ ................................ ......... 17 
1.4 Channel vs. Connection ................................ ................................ ......................... 17 
1.5 TP classes................................ ................................ ................................ .............. 18 
1.5.1 SingleTP classes ................................ ................................ ........................... 18 
1.5.2 Static MultiTP classes ................................ ................................ ................... 18 
1.5.3 Dynamic MultiTP classes ................................ ................................ .............. 18 
1.5.4 Dispatched MultiTP classes ................................ ................................ .......... 18 
1.6 SingleConnection vs. MultipleConnection ................................ ............................... 19 
1.7 Features ................................ ................................ ................................ ................. 19 
1.7.1 Feature List ................................ ................................ ................................ ... 19 
2 Architecture Overview ................................ ................................ ................................ . 23 
2.1 Requirements ................................ ................................ ................................ ......... 23 
2.1.1 Protocol-Overview ................................ ................................ ......................... 23 
2.1.1.1 Construction of unsegmented messages ................................ ................ 23 
2.1.1.2 Construction of segmented messages ................................ .................... 23 
2.1.2 Addressing modes ................................ ................................ ........................ 24 
2.1.2.1 Normal Addressing ................................ ................................ ................. 25 
2.1.2.2 Mixed 11-bit ID Addressing ................................ ................................ ..... 25 
2.1.2.3 Normal Fixed Addressing ................................ ................................ ....... 25 
2.1.2.4 Extended Addressing................................ ................................ .............. 25 
2.1.2.5 Mixed 29-bit ID Addressing ................................ ................................ ..... 26 
2.1.2.6 Structure of TPCI-Byte ................................ ................................ ........... 26 
2.2 Transmission ................................ ................................ ................................ .......... 28 
2.3 Reception ................................ ................................ ................................ ............... 29 
2.4 Working behaviors ................................ ................................ ................................ .. 30 
2.4.1 Timings ................................ ................................ ................................ ......... 30 
2.4.2 Error detection................................ ................................ ............................... 31 
2.4.2.1 Reception of a SingleFrame ................................ ................................ ... 31 
2.4.2.2 Reception of a FirstFrame ................................ ................................ ...... 31 
2.4.2.3 Reception of a FlowControl ................................ ................................ .... 31 
2.4.2.4 Reception of a ConsecutiveFrame................................ .......................... 32 
2.4.2.5 Observing CAN frame DLC (Data Length Code) ................................ .... 32 
2.4.3 Buffer consistency ................................ ................................ ......................... 33 
2.4.4 Function re-entrancy ................................ ................................ ..................... 33 
2.5 Restriction ................................ ................................ ................................ .............. 34 

Technical Reference Transport Protocol ISO15765-2 
2013, Vector Informatik GmbH Version: 3.14.00 
based on template version 5.1.0 
8 / 177 
2.5.1 Restrictions to ISO/TF2 specification ................................ ............................. 34 
2.5.2 Limitations of Transport Protocol Implementation ................................ .......... 34 
2.5.3 Deviations to ISO/TF2 specification ................................ ......................

... [truncated — 255038 further characters not shown; see the original PDF] ...
```

## Original file

- Repository path: `/Doc/TechnicalReferences/TechnicalReference_TransportProtocolMultiConnection.pdf`

[Back to top](#_top)
