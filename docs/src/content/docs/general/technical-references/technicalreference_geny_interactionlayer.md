---
title: "Technical Reference: Il_Vector Interaction Layer"
description: "Converted Vector delivery document — searchable text extraction; the original PDF/HTML remains authoritative."
---
<!-- markdownlint-disable MD009 MD012 MD030 MD046 -->

> **Source:** `/Doc/TechnicalReferences/TechnicalReference_GENy_InteractionLayer.pdf` — Vector-proprietary PDF, converted automatically to Markdown for browsing.  
> Text was extracted with `pypdf`; headings/lists/tables/images are **not** faithfully preserved. 
> The PDF itself remains the authoritative document.

## Document information

- **Group:** IL module
- **Pages:** 115
- **PDF Title:** YourTopic
- **Author(s):** Klaus Emmert, Gunnar Meiss, Heiko Hübler
- **Subject:** 
- **Version:** 
- **Category:** 
- **Company:** 
- **Comments:** 

## PDF bookmarks (outline)

- 1 Document Information
-   1.1 History
-   1.2 Reference Documents
- 2 Introduction
-   2.1 Architecture Overview
-   2.2 Data Access Concept
-   2.3 Adapt the Vector Interaction Layer
- 3 Functional Description
-   3.1 Features
-   3.2 Initialization
-   3.3 Interaction Layer State Machine
-     3.3.1 States
-       3.3.1.1 Uninit
-       3.3.1.2 Running
-  Receive Section  Reception of data is enabled as well as timeout monitoring and notification.
-  Transmit Section  Transmission of data is enabled. Signal Interface and Message Manager are workin
-   3.3.1.3 Waiting
-  Receive Section  Reception of data is enabled as well as the notification for indication. The time
-  Transmit Section  Transmission of data and the timeout monitoring will be disabled and the API wil
-   3.3.2 State Transitions
-     3.3.2.1 Init
-     3.3.2.2 Start
-     3.3.2.3 Stop
-     3.3.2.4 Wait
-     3.3.2.5 Release
-   3.4 Main Functions
-   3.5 Interaction Layer Communication Concept
-     3.5.1 Interface Concept
-     3.5.2 Notification Mechanisms
-   3.6 Data Access

## Detected section headings (heuristic)

- 1 Document Information
- 1.1 History
- 1.2 Reference Documents
- 3.6.5.2 AUTOSAR API ................................ ............................... 28
- 3.6.5.3 GENy configuration ................................ ........................ 29
- 3.7.2.1 Cyclic Transmission ................................ ....................... 34
- 3.7.2.2 OnEvent (OnWrite, OnChange) ................................ ..... 34
- 3.7.2.3 OnEvent with Repetition (OnWrite, OnChange) ............. 35
- 3.7.2.4 Transmit Fast if Signal is Active ................................ ..... 36
- 3.7.2.5 Transmit Fast if Signal is Active with Repetition ............. 38
- 3.7.3.1 Cyclic (Message) Transmission OR Cyclic (Signal)
- 3.7.3.2 Cyclic (Message) Transmission OR OnEvent [Write] ..... 39
- 3.7.3.3 Cyclic (Message) Transmission OR OnEvent [Write]
- 3.7.3.4 Cyclic (Message) Transmission OR OnEvent [Change] . 40
- 3.7.3.5 Cyclic (Message) Transmission OR OnEvent [Change]
- 3.7.3.6 Cyclic (Message) Transmission OR Transmit Fast If
- 3.7.3.7 Cyclic (Message) Transmission OR Transmit Fast If
- 3.7.3.8 Cyclic (Message) Transmission OR NoSigSendType ..... 42
- 3.11.1 Physical Multiple and Multiple Configuration ECU ............................ 50
- 6.1.2.15 IlSendOnInitMsg ................................ ............................ 89
- 6.1.2.17 IlTxRepetitionsAreActive ................................ ................ 90
- 6.1.2.18 IlTxSignalsAreActive ................................ ...................... 91
- 6.1.3 Generated Services provided by the Interaction Layer ..................... 92
- 6.1.3.1 Read and Write Signals and Signal Groups ................... 92
- 6.1.3.2 Read and Write Signals and SignalGroups in the RDS
- 6.1.3.3 Notification Flags of Signals, Signal Groups and
- 6.1.3.4 Dynamic Rx Timeout ................................ .................... 102
- 2 Introduction
- 2.1 Architecture Overview
- 2.2 Data Access Concept

## Extracted text (beginning of document)

_Showing first 12000 of ~216294 extracted characters across 115 pages._

```text
Vector Interaction Layer 
Technical Reference 
 
Il_Vector 
Version 2.10.03 
 
 
 
 
 
 
 
 
 
 
 
Authors Klaus Emmert, Gunnar Meiss, Heiko Hübler 
Status Released 
 
 
 
 
 

Technical Reference Vector Interaction Layer 
2013, Vector Informatik GmbH Version: 2.10.03 
based on template version 3.7 
2 / 115 
1 Document Information 
1.1 History 
Author Date Version Remarks 
P . Jost 2000-05-05 1.0 creation 
P . Jost 2000-06-29 1.1 some corrections 
P . Jost 2000-07-13 1.2 changes in Figure 4 and some further corrections 
P . Jost 2000-08-06 1.3 correction of the First-Value Class 
P . Jost 2000-09-13 1.4 little corrections in the description of the TxTask and IlInit 
P . Jost 2001-03-01 1.5 message related transmission modes 
example for timeout monitoring 
multi channel support 
known problems 
integration example 
P . Jost 2001-06-22 1.6 some names of attributes changed 
DataChanged flag 
Tx timeout monitoring 
Rx and Tx default values 
new screen shots of the current Gentool 
changes in the state machine 
and further little corrections 
S. Hoffmann 2001-07-05 1.61 some corrections and branch for an OEM 
P . Jost 2001-07-13 1.62 adapted the corrections of version 1.61 for general IL 
P . Jost 2002-04-05 1.63 Signal groups 
Multiple physical and virtual ECU support 
Multiplex Signals 
Rx timeout monitoring: reload of timer and message 
related notification 
Notification in interrupt and task context (IL Polling) 
IL<Tx/Rx>StateTask 
Attributes for Rx timeout monitoring updated 
Configuration Tool pictures updated 
P . Jost 2002-08-16 1.7 Name of this document changed from User Manual to 
Technical Reference 
Multiple Indication Flags per Signal 
Macro to Get and Clear at once 
Chapter for Configuration Tool updated 
”New Style” API 
Data Type Prefix for Signal Access 
Further Callbacks for State Machine 
Initialization – IlInitPowerOn 
ECU Timeout 
H. Hörner 2003-06-16 1.8 Several wording and spelling issues corrected 
List of abbreviations and glossary removed, replaced by 
an own document 
Implementation details moved to an Annex 

Technical Reference Vector Interaction Layer 
2013, Vector Informatik GmbH Version: 2.10.03 
based on template version 3.7 
3 / 115 
K. Emmert 2003-09-02 1.9 Some design and link modifications. 
H. Hörner 2004-05-14 2.0 Add usage of VStdLib 
Documented return value of flag get macros 
Difference between GenMsgDelayTime and 
GenMsgStartDelayTime clarified 
Some clarifications about signal groups 
Wording enhanced for multiplexed signals 
Klaus Emmert 
Gunnar Meiss 
2005-06-10 2.01 Added support for GENy 
Added new feature dynamic timeout handling 
Added raw API for multiplex signals 
Reworked dbc attributes chapter 
Added matrix with transmission modes 
Gunnar Meiss 
 
2005-08-02 2.02 Adapted GenMsgFastOnStart 
Added GENy Multiplex Support 
Klaus Emmert 
Gunnar Meiss 
2005-11-04 2.03 Added AUTOSAR API for GENy, configuration and signal 
access. 
Added GenMsgFastOnStart for multiplex messages in 
GENy 
Added ESCAN00014120 CANGen 
Added ESCAN00008602 CANGen 
Added ESCAN00008604 CANGen 
Reworked ESCAN00010718 
Gunnar Meiss 2006-02-16 2.04 Added GENy Multiple ECU Reference 
Added ESCAN00013633 
DynRxTimeout API postfix and data types have changed. 
Klaus Emmert 2006-03-13 2.05 Signal Groups for GENy 
Gunnar Meiss 2006-04-06 2.06 Added Indexed API discontinuation for GENy. 
Corrected ApplIlFatalError Prototype 
Improved GenSigTimeoutMsg_<ECU> 
Corrected GenSigSendType description 
Removed GenSigTimeoutMsg_<ECU> for GENy 
Gunnar Meiss 2007-05-16 2.07 Opaque Data Types ESCAN00016935 GENy 
Improved documentation of call contexts of API functions 
ESCAN00017472, ESCAN00018014, ESCAN00014156, 
ESCAN00013962, ESCAN00013423, ESCAN00008047, 
ESCAN00008755 
Gunnar Meiss 2007-12-17 2.08 Added GenSigSuprvResp, GenSigSuprvRespSubValue 
and GenSigTimeoutMsg_<ECU> for GENy 
Updated API descriptions 
Updated GenMsgStartDelayTime 
Updated GenMsgIlSupport 
ESCAN00024092 
Gunnar Meiss 2008-04-21 2.08.01 ESCAN00024091 
Gunnar Meiss 2008-07-17 2.09.00 Reworked Document Structure 
ESCAN00024902 Added Node Mapped dbc Attributes 

Technical Reference Vector Interaction Layer 
2013, Vector Informatik GmbH Version: 2.10.03 
based on template version 3.7 
4 / 115 
Updated Abbreviations and Glossary with CIWI 
ESCAN00028781 Added IlTxRepetitionsAreActive and 
IlTxSignalsAreActive 
ESCAN00028787 Reset Timeout Flags On Release 
Added Geny attribute descriptions 
ESCAN00023799 Added Limitation 
ESCAN00025371 Updated Dynamic Timeout Monitoring 
ESCAN00029109 Added Documentation of Generated 
APIs 
Gunnar Meiss 2008-10-17 2.09.01 ESCAN00030172 The description of IlRxWait() 
is ‎incorrect 
Gunnar Meiss 2011-05-19 2.09.02 ESCAN00049272 OnChangeAndIfActive and 
OnChangeAndIfActiveWithRepetition is described 
incorrect in Table 3-6 "Send Type Matrix" 
ESCAN00049615 Incorrect Enumeration Values of the 
dbc attribute "ILUsed" 
ESCAN00048272 Incorrect Timing Diagram of the 
Transmit Fast if Signal Active Transmission Mode 
Heiko Hübler 2012-03-13 2.10.00 Added Signal status information (UpdateBits) 
Heiko Hübler 2012-05-14 2.10.00 Added description for the GENy GUI attribute “timeout 
time” 
Heiko Hübler 2012-09-13 2.10.01 Added description for PreConfig Switch “Enable 
UpdateBit Support” 
Changed “Send on Init” description 
Heiko Hübler 2012-11-07 2.10.02 ESCAN00041782: One 'e' too much in Technical 
Reference 
ESCAN00062898: Adapted description of Delimitation of 
the Bus Load 
Heiko Hübler 2013-05-13 2.10.03 ESCAN00052197: The OnChange Event is triggered if 
the value for IlPut changes out of the range 
Table 1-1 History of the Document 
 
 
 
 
 
 
 
 
 
 

Technical Reference Vector Interaction Layer 
2013, Vector Informatik GmbH Version: 2.10.03 
based on template version 3.7 
5 / 115 
1.2 Reference Documents 
No. Source Title Version 
[1] Vector Vector CAN driver. Technical Reference 
[2] Vector Vector Multiple ECUs. Technical Reference 1.00.00 
[3] Vector Vector Configuration Tool. Online Documentation. 
(no printed manual available) 
 
[4] OSEK OSEK/COM, Version 3.0.3 3.00.03 
[5] Z.120 (1996). Message Sequence Chart (MSC). 
ITU-T, Geneva 
April.1996 
[6] Vector Interaction Layer User Manual 
[7] AUTOSAR AUTOSAR Specification of Module COM 2.0.0 2.00.00 
[8] AUTOSAR AUTOSAR Specification of Module COM 3.1.0 3.1.0 
Table 1-2 Reference Documents 
 
Please note 
We have configured the programs in accordance with your specifications in the 
questionnaire. Whereas the programs do support other configurations than the one 
specified in your questionnaire, Vector´s release of the programs delivered to your 
company is expressly restricted to the configuration you have specified in the 
questionnaire. 

Technical Reference Vector Interaction Layer 
2013, Vector Informatik GmbH Version: 2.10.03 
based on template version 3.7 
6 / 115 
Contents 
1 Document Information ................................ ................................ ................................ . 2 
1.1 History ................................ ................................ ................................ ............... 2 
1.2 Reference Documents ................................ ................................ ....................... 5 
2 Introduction................................ ................................ ................................ ................. 11 
2.1 Architecture Overview ................................ ................................ ...................... 12 
2.2 Data Access Concept ................................ ................................ ....................... 13 
2.3 Adapt the Vector Interaction Layer ................................ ................................ ... 15 
3 Functional Description ................................ ................................ ............................... 17 
3.1 Features ................................ ................................ ................................ .......... 17 
3.2 Initialization ................................ ................................ ................................ ...... 17 
3.3 Interaction Layer State Machine ................................ ................................ ....... 18 
3.3.1 States ................................ ................................ .............................. 19 
3.3.1.1 Uninit ................................ ................................ ............. 19 
3.3.1.2 Running ................................ ................................ ......... 19 
3.3.1.3 Waiting ................................ ................................ ........... 19 
3.3.2 State Transitions ................................ ................................ .............. 19 
3.3.2.1 Init ................................ ................................ .................. 19 
3.3.2.2 Start ................................ ................................ ............... 19 
3.3.2.3 Stop ................................ ................................ ............... 20 
3.3.2.4 Wait ................................ ................................ ............... 20 
3.3.2.5 Release ................................ ................................ ......... 21 
3.4 Main Functions ................................ ................................ ................................ 21 
3.5 Interaction Layer Communication Concept................................ ....................... 23 
3.5.1 Interface Concept ................................ ................................ ............. 23 
3.5.2 Notification Mechanisms ................................ ................................ .. 23 
3.6 Data Access ................................ ................................ ................................ ..... 23 
3.6.1 Data Consistency ................................ ................................ ............. 23 
3.6.2 Signal Interface ................................ ................................ ................ 24 
3.6.3 AUTOSAR Signal Interface ................................ .............................. 25 
3.6.4 Example: Writing and reading a signal value ................................ .... 26 
3.6.5 Signal Groups ................................ ................................ .................. 27 
3.6.5.1 Il API ................................ ................................ .............. 27 
3.6.5.2 AUTOSAR API ................................ ............................... 28 
3.6.5.3 GENy configuration ................................ ........................ 29 
3.6.6 Default Values ................................ ................................ .................. 29 
3.7 Data Transmission ................................ ................................ ........................... 30 

Technical Reference Vector Interaction Layer 
2013, Vector Informatik GmbH Version: 2.10.03 
based on template version 3.7 
7 / 115 
3.7.1 Transmission Concept................................ ................................ ...... 30 
3.7.2 Signal Related Transmission Modes ................................ ................ 33 
3.7.2.1 Cyclic Transmission ................................ ....................... 34 
3.7.2.2 OnEvent (OnWrite, OnChange) ................................ ..... 34 
3.7.2.3 OnEvent with Repetition (OnWrite, OnChange) ............. 35 
3.7.2.4 Transmit Fast if Signal is Active ................................ ..... 36 
3.7.2.5 Transmit Fast if Signal is Active with Repetition ............. 38 
3.7.3 Mixed Transmission Mode................................ ................................ 39 
3.7.3.1 Cyclic (Message) Transmission OR Cyclic (Signal) 
Transmission ................................ ................................ . 39 
3.7.3.2 Cyclic (Message) Transmission OR OnEvent [Write] ..... 39 
3.7.3.3 Cyclic (Message) Transmission OR OnEvent [Write] 
with Repetition ................................ ............................... 3

... [truncated — 204294 further characters not shown; see the original PDF] ...
```

## Original file

- Repository path: `/Doc/TechnicalReferences/TechnicalReference_GENy_InteractionLayer.pdf`

[Back to top](#_top)
