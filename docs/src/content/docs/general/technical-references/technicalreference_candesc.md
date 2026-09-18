---
title: "Technical Reference: CANdesc"
description: "Converted Vector delivery document — searchable text extraction; the original PDF/HTML remains authoritative."
---
<!-- markdownlint-disable MD009 MD012 MD030 MD046 -->

> **Source:** `/Doc/TechnicalReferences/TechnicalReference_CANdesc.pdf` — Vector-proprietary PDF, converted automatically to Markdown for browsing.  
> Text was extracted with `pypdf`; headings/lists/tables/images are **not** faithfully preserved. 
> The PDF itself remains the authoritative document.

## Document information

- **Group:** CANdesc
- **Pages:** 117
- **PDF Title:** Technical Reference
- **Author(s):** Oliver Garnatz, Mishel Shishmanyan, Stefan Hübner, Matthias Heil
- **Subject:** CANdesc
- **Version:** 2.19.00
- **Category:** 
- **Company:** Vector Informatik GmbH
- **Comments:** released

## PDF bookmarks (outline)

- 1 History
- 2 Introduction
- 3 Documents this one refers to…
- 4 Architecture Overview
-   4.1 CANdesc – Internal processing
-     4.1.1 Diagnostic protocol
-     4.1.2 How does this flow actually work?
-   4.2 Application interface flow
-     4.2.1 Session- and CommunicationControl 
- 5 Advanced Configuration
-   5.1 Configure DBC attributes for diagnostics
-   5.2 Configure Handlers using CANdela attributes
-   5.3 ReadDataByIdentifier (SID $22)
-     5.3.1 Limitations of the service
-     5.3.2 Single PID mode
-       5.3.2.1 Sending a positive response using linear buffer access
-       5.3.2.2 Sending a positive response using ring buffer access
-       5.3.2.3 Sending a negative response
-     5.3.3 Multiple PID mode
-       5.3.3.1 Pure linear buffer configuration
-         5.3.3.1.1 Sending a positive response
-         5.3.3.1.2 Sending a negative response
-       5.3.3.2 Ring buffer active configuration
-         5.3.3.2.1 Sending a positive response
-         5.3.3.2.2 Sending a negative response
-         5.3.3.2.3 PostHandler execution rule
-   5.4 DynamicallyDefineDataIdentifier (SID $2C) (UDS)
-     5.4.1 Feature set
-     5.4.2 API Functions
-     5.4.3 Sequence Charts

## Detected section headings (heuristic)

- 1 History
- 5.2 Configure Handlers using
- 5.1 Configure DBC attributes for
- 6.6.8.2 DescRingBufferWrite()
- 4.2.1 Session- and CommunicationControl............................................ 16
- 5.2 Configure Handlers using CANdela attributes .............................. 17
- 5.3.2.1 Sending a positive response using linear buffer access ............... 25
- 5.3.2.2 Sending a positive response using ring buffer access .................. 26
- 5.4 DynamicallyDefineDataIdentifier (SID $2C) (UDS) ....................... 35
- 5.5 Read/Write Memory by Address (SID $23/$3D) (UDS) ................ 39
- 5.5.2 Task to be performed by the Application....................................... 39
- 6.6.5.1 ApplDescCheckSessionTransition().............................................. 61
- 6.6.7.2 DescStartMemByAddrRepeatedCall() .......................................... 70
- 6.6.10.3 ApplDescOnTransition«StateGroup»() ......................................... 80
- 6.6.11 Force “Response Correctly Received - Response Pending” transmission 81
- 6.6.12 DynamicallyDefineDataIdentifier ($2C) (UDS) functions.............. 84
- 6.6.12.2 ApplDescCheckDynDidMemoryArea().......................................... 86
- 6.6.13.1 ApplDescReadMemoryByAddress() ............................................. 95
- 6.6.13.2 ApplDescWriteMemoryByAddress().............................................. 96
- 2 Introduction
- 3 Documents this one refers to…
- 4 Architecture Overview
- 4.1 CANdesc – Internal processing
- 4.1.1 Diagnostic protocol
- 4.1.2 How does this flow actually work?
- 1 Not all services could be handled parallel.
- 4.2 Application interface flow
- 4.2.1 Session- and CommunicationControl
- 5 Advanced Configuration
- 5.1 Configure DBC attributes for diagnostics

## Extracted text (beginning of document)

_Showing first 12000 of ~159565 extracted characters across 117 pages._

```text
CANdesc 
Technical Reference 
 
 
 
 
Version 2.19.00 
 
 
 
 
 
 
 
 
 
 
Authors: Oliver Garnatz, Mishel Shishmanyan, Stefan 
Hübner, Matthias Heil 
Version: 2.19.00 
Status: released (in preparation/completed/inspected/released) 
 
 
 
 

Technical Reference CANdesc 
1 History 
Author Date Version Remarks 
Oliver Garnatz 2003-11-12 2.00.00 Splitting into separate documents 
and general revision 
Oliver Garnatz 2004-01-13 2.00.01 Added chapter ‘Application interface 
flow’ 
Updated format template 
Mishel Shishmanyan 2004-03-09 2.01.00 New application callback convention 
(from CANdesc 2.09.00) 
Mishel Shishmanyan 2004-03-29 2.02.00 New APIs: 
- DescGetActivityState (from 
CANdesc 2.10.00) 
- DescSchedulerTask() (from 
CANdesc 2.09.00) 
Mishel Shishmanyan 2004-04-26 2.03.00 Added more information and 
limitations about the ring-buffer 
mechanism (6.6.8 “Ring Buffer 
Mechanism”) 
New feature: 
- Support for generic user 
service (from CANdesc 
2.11.00) 
- Force CANdesc to send 
RCR-RP response (from 
CANdesc 2.11.00) 
Stefan Hübner 2004-07-16 2.03.01 Editorial revision 
Oliver Garnatz 2004-08-12 2.04.00 Added chapter 4.2 
ReadDataByIdentifier (SID $22) 
within the Single- and the Multiple 
PID mode is described 
Oliver Garnatz 2004-10-08 2.05.00 ESCAN0000982: Description of 
MainHandler structure is not 
readable 
ROE transmission unit is described 
in detail 
Stefan Hübner 
Oliver Garnatz 
2004-10-15 2.06.00 Some additional information are 
provided 
Peter Herrmann 
Klaus Emmert 
2005-06-22 2.07.00 Added: Service $2C description. 
Added: Warning Text added 
Mishel Shishmanyan 
Oliver Garnatz 
2005-08.03 2.08.00 API added: 
- DescStateTask, 
- DescTimerTask, 
©2010, Vector Informatik GmbH Version: 2.19.00 
 
2 / 117

Technical Reference CANdesc 
- DescMayCallStateTaskAgai
n. 
- ApplDescFatalError 
API modified: 
- DescTask, 
- ApplDescCheckSessionTran
sition, 
- DescGetActivityState, 
- DescGetStateSession. 
API removed: 
- DescSchedulerTask 
Modified description for 
ReadDataByIdentifier with long data 
and negative response in main-
handler. 
Oliver Garnatz 2006-03-02 2.09.00 Added: ...prevent the ECU going to 
sleep while diagnostic is active 
Mishel Shishmanyan 2006-03-24 2.10.00 Added: document overview 
Mishel Shishmanyan 2006-04-27 2.11.00 Modified: 
-6.6.12 
DynamicallyDefineDataIdentifier 
($2C) (UDS) functions 
-6.6.12.1 
DescMayCallStateTaskAgain() 
 
Mishel Shishmanyan 2007-02-22 2.12.00 Added: 
 - 6.6.8.3 “DescRingBufferCancel()” 
 
Matthias Heil 2008-01-03 2.13.00 Added: 
Caution concerning user main 
handler on protocol level 
Matthias Heil 2008-02-29 2.14.00 Added: 
Handling of read/write memory by 
address: 
 - 5.5 “Read/Write Memory by 
Address” 
- 6.6.7.2 
“DescStartMemByAddrRepeatedCal
l()” 
- 6.6.13 ”Memory Access Callbacks”
Mishel Shishmanyan 2008-06-06 2.15.00 Removed: 
Chapter “ResponseOnEvent 
Transmission Unit” 
Added: 
©2010, Vector Informatik GmbH Version: 2.19.00 
 
3 / 117

Technical Reference CANdesc 
 - 6.6.12.3 “Non-volatile memory 
support” 
Mishel Shishmanyan 2008-11-09 2.16.00 Modified: 
- 6.6.8 and 6.6.8.1: Added limitation 
for UDS and SPRMIB with the ring 
buffer usage. 
- 7.6 …work with the ring-buffer 
mechanism 
Added: 
- 6.6.14 Flash Boot Loader Support 
- 7.8 …send a positive response 
without request after FBL flash job 
Mishel Shishmanyan 2009-05-18 2.17.00 Modified: 
6.6.5.1ApplDescCheckSessionTran
sition() 
Added: 
6.6.5.3DescIsSuppressPosResBitS
et () 
Mishel Shishmanyan 2009-08-11 2.18.00 Modified: 
Minor editorial changes 
5.2 Configure Handlers using 
CANdela attributes – added new 
data object attributes 
Added: 
7.9 …enforce CANdesc to use 
ANSI C instead of hardware 
optimized bit type 
5.1 Configure DBC attributes for 
diagnostics 
 
Mishel Shishmanyan 2010-12-21 2.19.00 Modified: 
6.6.8.2 DescRingBufferWrite() 
6.6.13.1 
ApplDescReadMemoryByAddress() 
6.6.13.2 
ApplDescWriteMemoryByAddress() 
 
 
©2010, Vector Informatik GmbH Version: 2.19.00 
 
4 / 117

Technical Reference CANdesc 
Contents 
1 History............................................................................................................ 2 
2 Introduction ................................................................................................. 10 
3 Documents this one refers to…................................................................. 11 
4 Architecture Overview ................................................................................ 12 
4.1 CANdesc – Internal processing..................................................... 12 
4.1.1 Diagnostic protocol........................................................................ 12 
4.1.2 How does this flow actually work? ................................................ 13 
4.2 Application interface flow .............................................................. 16 
4.2.1 Session- and CommunicationControl............................................ 16 
5 Advanced Configuration ............................................................................ 17 
5.1 Configure DBC attributes for diagnostics ...................................... 17 
5.2 Configure Handlers using CANdela attributes .............................. 17 
5.3 ReadDataByIdentifier (SID $22).................................................... 23 
5.3.1 Limitations of the service............................................................... 24 
5.3.2 Single PID mode ........................................................................... 25 
5.3.2.1 Sending a positive response using linear buffer access ............... 25 
5.3.2.2 Sending a positive response using ring buffer access .................. 26 
5.3.2.3 Sending a negative response........................................................ 27 
5.3.3 Multiple PID mode......................................................................... 27 
5.3.3.1 Pure linear buffer configuration ..................................................... 28 
5.3.3.1.1 Sending a positive response ......................................................... 28 
5.3.3.1.2 Sending a negative response........................................................ 29 
5.3.3.2 Ring buffer active configuration..................................................... 29 
5.3.3.2.1 Sending a positive response ......................................................... 32 
5.3.3.2.2 Sending a negative response........................................................ 33 
5.3.3.2.3 PostHandler execution rule ........................................................... 34 
5.4 DynamicallyDefineDataIdentifier (SID $2C) (UDS) ....................... 35 
5.4.1 Feature set.................................................................................... 35 
5.4.2 API Functions................................................................................ 35 
5.4.3 Sequence Charts .......................................................................... 36 
5.5 Read/Write Memory by Address (SID $23/$3D) (UDS) ................ 39 
5.5.1 Tasks performed by CANdesc ...................................................... 39 
5.5.2 Task to be performed by the Application....................................... 39 
5.5.3 Repeated service calls .................................................................. 39 
©2010, Vector Informatik GmbH Version: 2.19.00 
 
5 / 117

Technical Reference CANdesc 
6 CANdesc API ............................................................................................... 41 
6.1 API Categories .............................................................................. 41 
6.1.1 Single Context............................................................................... 41 
6.1.2 Multiple Context (only CANdesc) .................................................. 41 
6.2 Data Types.................................................................................... 41 
6.3 Global Variables............................................................................ 41 
6.4 Constants ...................................................................................... 41 
6.4.1 Component Version ...................................................................... 41 
6.5 Macros .......................................................................................... 42 
6.5.1 Data exchange .............................................................................. 42 
6.5.1.1 Splitting 16 bit data........................................................................ 42 
6.5.1.2 Splitting 32 bit data........................................................................ 42 
6.5.1.3 Assembling 16 bit data.................................................................. 43 
6.5.1.4 Assembling 32 bit data.................................................................. 43 
6.6 Functions....................................................................................... 44 
6.6.1 Administrative Functions ............................................................... 44 
6.6.1.1 DescInitPowerOn()........................................................................ 44 
6.6.1.2 DescInit()....................................................................................... 45 
6.6.1.3 DescTask().................................................................................... 46 
6.6.1.4 DescStateTask() ........................................................................... 47 
6.6.1.5 DescTimerTask()........................................................................... 48 
6.6.1.6 DescGetActivityState() .................................................................. 49 
6.6.2 Service Functions.......................................................................... 50 
6.6.2.1 DescSetNegResponse() ............................................................... 50 
6.6.2.2 DescProcessingDone() ................................................................. 51 
6.6.3 Service Call-Back functions .......................................................... 52 
6.6.3.1 Service PreHandler ....................................................................... 52 
6.6.3.2 Service MainHandler..................................................................... 53 
6.6.3.3 Service PostHandler ..................................................................... 55 
6.6.4 User (Unknown) Service Handling ................................................ 56 
6.6.4.1 How it works.................................................................................. 56 
6.6.4.2 ApplDescCheckUserService()....................................................... 57 
6.6.4.3 DescGetServiceId()....................................................................... 58 
6.6.4.4 Generic User Service MainHandler............................................... 59 
6.6.4.5 Generic User Service PostHandler ............................................... 60 
6.6.5 Session Handling .......................................................................... 61 
6.6.5.1 ApplDescCheckSessionTransition().............................................. 61 
6.6.5.2 DescSessionTransitionChecked()................................................. 62 
6.6.5.3 DescIsSuppressPosResBitSet () .................................................. 63 
6.6.5.4 ApplDescOnTransitionSession() ................................................... 64 
6.6.5.5 DescSetStateSession() ................................................................. 65 
©2010, Vector Informatik GmbH Version: 2.19.00 
 
6 / 117

Technical Reference CANdesc 
6.6.5.6 DescGetStateSession()................................................................. 66 
6.6.6 CommunicationControl Handling .................................................. 67 
6.6.6.1 ApplDescCheckCommCtrl() .......................................................... 67 
6.6.6.2 DescCommCtrlChecked() ............................................................. 6

... [truncated — 147565 further characters not shown; see the original PDF] ...
```

## Original file

- Repository path: `/Doc/TechnicalReferences/TechnicalReference_CANdesc.pdf`

[Back to top](#_top)
