---
title: "Technical Reference: Vector CAN Driver"
description: "Converted Vector delivery document — searchable text extraction; the original PDF/HTML remains authoritative."
---
<!-- markdownlint-disable MD009 MD012 MD030 MD046 -->

> **Source:** `/Doc/TechnicalReferences/TechnicalReference_CANDriver.pdf` — Vector-proprietary PDF, converted automatically to Markdown for browsing.  
> Text was extracted with `pypdf`; headings/lists/tables/images are **not** faithfully preserved. 
> The PDF itself remains the authoritative document.

## Document information

- **Group:** CAN module
- **Pages:** 149
- **PDF Title:** TechnicalReference
- **Author(s):** H. Honert, K. Emmert
- **Subject:** Vector CAN Driver
- **Version:** 3.01.01
- **Category:** Reference Implementation 1.5
- **Company:** Vector Informatik GmbH
- **Comments:** released

## PDF bookmarks (outline)

- 1 Document Information
-   1.1 History
-   1.2 Reference Documents
-   1.3 Contents1
- 2 About this Document
-   2.1 Documents this one refers to…
-   2.2 Naming Conventions
- 3 Reference Implementations
-   3.1 Version 1.0
-     3.1.1 What's new?
-     3.1.2 What's changed?
-   3.2 Version 1.1
-     3.2.1 What's new?
-       3.2.1.1 Mandatory (for all CAN Drivers)
-       3.2.1.2 Optional (for some specific CAN Drivers)
-     3.2.2 What's changed?
-   3.3 Version 1.2
-     3.3.1 What’s new?
-     3.3.2 What’s changed?
-   3.4 Version 1.3
-     3.4.1 What’s new?
-     3.4.2 What’s changed?
-   3.5 Version 1.4
-     3.5.1 What’s new?
-       3.5.1.1 Mandatory (for all CAN Drivers)
-         3.5.1.1.1 Common features
-         3.5.1.1.2 Transmission features
-       3.5.1.2 Optional (for some specific CAN Drivers)
-         3.5.1.2.1 Transmission features
-         3.5.1.2.2 Reception features

## Detected section headings (heuristic)

- 1 Document Information
- 1.1 History
- 2.22 Description of API extended
- 1.2 Reference Documents
- 1.3 Contents
- 5.2.4.2 Functional Interface (Confirmation Function for each message) ............... 34
- 5.2.4.3 Functional Interface (Common Confirmation Function for all messages) .. 34
- 5.2.9.2 Cancel a Transmission via CanCancelTransmit or
- 8.4.1 Conversion between Logical and Hardware Representation of CAN
- 2 About this Document
- 2.1 Documents this one refers to…
- 2.2 Naming Conventions
- 3 Reference Implementations
- 3.1 Version 1.0
- 3.1.1 What's new?
- 3.1.2 What's changed?
- 3.2 Version 1.1
- 3.2.1 What's new?
- 3.2.1.1 Mandatory (for all CAN Drivers)
- 3.2.1.2 Optional (for some specific CAN Drivers)
- 3.2.2 What's changed?
- 3.3 Version 1.2
- 3.3.1 What’s new?
- 3.3.2 What’s changed?
- 3.4 Version 1.3
- 3.4.1 What’s new?
- 3.4.2 What’s changed?
- 3.5 Version 1.4
- 3.5.1 What’s new?
- 3.5.1.1 Mandatory (for all CAN Drivers)

## Extracted text (beginning of document)

_Showing first 12000 of ~298030 extracted characters across 149 pages._

```text
©2010, Vector Informatik GmbH Version: 3.01.01 
based on template version 2.1 
1 / 149
 
 
 
 
 
 
 
 
 
 
 
Vector CAN Driver 
Technical Reference 
 
Reference Implementation 1.5 
 
 
Version 3.01.01 
 
 
 
 
 
 
 
 
 
 
Authors: H. Honert, K. Emmert 
Version: 3.01.01 
Status: released (in preparation/completed/inspected/released) 
 
 
 
 

TechnicalReference Vector CAN Driver 
©2010, Vector Informatik GmbH Version: 3.01.01 
based on template version 2.1 
 
 
2 / 149
1 Document Information 
1.1 History 
Author Date Version Remarks 
Hoffmann July, 30th 1997 1.00 Initial draft 
Baudermann, Ebner Aug, 9th 1999 2.00 Reorganization of the document
Hardware related 
documentation removed 
Ebner Nov, 2nd 1999 2.01 Spelling corrections 
Baudermann Nov, 6th 1999 2.02 Restrictions with reentrance 
capability for the following CAN 
Driver functions: CanInit, 
CanReset..., CanSleep, 
CanWakeUp and CAN 
interrupts 
Honert Dec, 14th 1999 2.03 DLC check added 
Ebner Feb, 8th 2000 2.04 Configuration by tool support 
(CANgen) added 
Baudermann, Rein, Honert, 
Brändle 
May, 23th 2000 2.10 Generally reworked 
According to reference 
implementation, version 1.1 
Honert Oct, 31th 2000 2.11 Description of indexed CAN 
Driver added 
Honert Feb, 28th 2001 2.12 Extensions according to 
reference implementation 
version 1.2 
Hardware related 
documentation of HC12 and 
C16x moved to a separate 
document 
Honert Aug, 10th 2001 2.13 Description of API extended 
 Single Receive Channel CAN 
Driver 
 CanCancelTransmit and 
CanCancelMsgTransmit added 
 Access to ErrorCounters added
Honert, 
 
Emmert 
Aug, 20th 2001 2.14 Prototype of UserPrecopy 
corrected 
Spelling corrections 
Modifications for pdf conversion
Emmert Okt, 9th 2001 2.15 Modifications of Figure 4 and 5. 
Honert Mai, 17th 2002 2.16 Function name corrected for 
indexed driver 
Extensions according to 

TechnicalReference Vector CAN Driver 
©2010, Vector Informatik GmbH Version: 3.01.01 
based on template version 2.1 
 
 
3 / 149
reference implementation 
version 1.3 
Ebner, Honert, Emmert Jun, 18th, 2003 2.20 Macro names corrected in 
figure 7. 
Extensions according to 
reference implementation 
version 1.4. 
Additional explanation for offline 
/ partial offline mode (ch. 5.2.6) 
Emmert, Honert Juli, 29th, 2003 2.21 New tables for API descriptions.
Corrections of some 
Parameters and API 
descriptions. 
Stephan Hoffmann, Klaus 
Emmert, Heike Honert, 
Patrick Markl 
May 17nd, 
2004 
2.22 Description of API extended 
 Direct Transmit Objects 
Cancel in Hardware 
Language corrections, New 
Layout, Technical revisions 
Klaus Emmert 
Matthias Fleischmann 
2005-12-30 2.23 GENy added as Generation 
Tool 
Added description for: 
 Multiple ECU 
 Common CAN 
 Signal Access Macros 
 Rx Queue 
 Conditional Message Received 
 Variable Datalen 
Heike Honert 2006-08-01 2.30 Extensions according to 
reference implementation 1.5. 
Heike Honert 2007-01-09 3.00 prepare links to hw specific 
Added description for: 
 CAN RAM check 
 Standard/HighEnd CAN Driver 
Heike Honert 2007-01-29 3.01 some corrections 
 improve Common CAN 
 service functions for conditional 
message reception added 
 Description for Partial Offline 
Mode for GENy modified 
 ESCAN00032527: Update 
description of 
ApplCanAddCanInterruptDisabl
e/Restore call-back function 
Heike Honert 2010-06-11 3.01.01 Reference to documentation of 
VstdLib changed 
Table 1-1 History of the Document 

TechnicalReference Vector CAN Driver 
©2010, Vector Informatik GmbH Version: 3.01.01 
based on template version 2.1 
 
 
4 / 149
1.2 Reference Documents 
Index and Document Name 
[1] TechnicalReference_<hardware>.pdf 
Table 1-2 Reference Documents 
 
 
 
 
 
 
Please note 
We have configured the programs in accordance with your specifications in the 
questionnaire. Whereas the programs do support other configurations than the one 
specified in your questionnaire, Vector´s release of the programs delivered to your 
company is expressly restricted to the configuration you have specified in the 
questionnaire. 

TechnicalReference Vector CAN Driver 
©2010, Vector Informatik GmbH Version: 3.01.01 
based on template version 2.1 
 
 
5 / 149
1.3 Contents 
1 Document Information ............................................................................................... 2 
1.1 History .......................................................................................................... 2 
1.2 Reference Documents ................................................................................. 4 
1.3 Contents....................................................................................................... 5 
2 About this Document ............................................................................................... 13 
2.1 Documents this one refers to….................................................................. 14 
2.2 Naming Conventions.................................................................................. 14 
3 Reference Implementations..................................................................................... 15 
3.1 Version 1.0 ................................................................................................. 15 
3.1.1 What's new?............................................................................................... 15 
3.1.2 What's changed?........................................................................................ 15 
3.2 Version 1.1 ................................................................................................. 16 
3.2.1 What's new?............................................................................................... 16 
3.2.1.1 Mandatory (for all CAN Drivers) ................................................................. 16 
3.2.1.2 Optional (for some specific CAN Drivers) .................................................. 16 
3.2.2 What's changed?........................................................................................ 16 
3.3 Version 1.2 ................................................................................................. 17 
3.3.1 What’s new?...............................................................................................17 
3.3.2 What’s changed? .......................................................................................17 
3.4 Version 1.3 ................................................................................................. 17 
3.4.1 What’s new?...............................................................................................17 
3.4.2 What’s changed? .......................................................................................17 
3.5 Version 1.4 ................................................................................................. 18 
3.5.1 What’s new?...............................................................................................18 
3.5.1.1 Mandatory (for all CAN Drivers) ................................................................. 18 
3.5.1.1.1 Common features....................................................................................... 18 
3.5.1.1.2 Transmission features................................................................................ 18 
3.5.1.2 Optional (for some specific CAN Drivers) .................................................. 18 
3.5.1.2.1 Transmission features................................................................................ 18 
3.5.1.2.2 Reception features ..................................................................................... 18 
3.5.2 What’s changed? .......................................................................................19 
3.5.2.1 Transmission features................................................................................ 19 
3.6 Version 1.5 ................................................................................................. 19 
3.6.1 What’s new?...............................................................................................19 
3.6.2 What’s changed? .......................................................................................20 

TechnicalReference Vector CAN Driver 
©2010, Vector Informatik GmbH Version: 3.01.01 
based on template version 2.1 
 
 
6 / 149
4 Overview ................................................................................................................... 21 
4.1 Short Summary of the Functional Scope ................................................... 22 
4.1.1 Initialization ................................................................................................ 22 
4.1.2 Transmission.............................................................................................. 22 
4.1.3 Reception................................................................................................... 23 
4.1.4 Bus-Off ....................................................................................................... 23 
4.1.5 Sleep Mode ................................................................................................ 23 
4.1.6 Special Features ........................................................................................ 23 
4.2 Data Structures for CAN Driver Customization .......................................... 24 
4.2.1 ROM Data .................................................................................................. 25 
4.2.1.1 Initialization Structures ............................................................................... 25 
4.2.1.2 Transmit Structures ....................................................................................26 
4.2.1.3 Receive Structures..................................................................................... 26 
4.2.2 RAM Data................................................................................................... 26 
5 Detailed Description of the Functional Scope (Standard) ....................................27 
5.1 Initialization ................................................................................................ 27 
5.1.1 Power-On Initialization of the CAN Driver .................................................. 27 
5.1.2 Re-Initialization of the CAN Controller ....................................................... 27 
5.2 Transmission.............................................................................................. 27 
5.2.1 Detailed Functional Description ................................................................. 27 
5.2.2 Transmit Queue.......................................................................................... 32 
5.2.3 Data Copy Mechanisms ............................................................................. 33 
5.2.3.1 Internal ....................................................................................................... 33 
5.2.3.2 User defined (“Pretransmit Function”)........................................................34 
5.2.4 Notification ................................................................................................. 34 
5.2.4.1 Data Interface (Confirmation Flag)............................................................. 34 
5.2.4.2 Functional Interface (Confirmation Function for each message) ............... 34 
5.2.4.3 Functional Interface (Common Confirmation Function for all messages) .. 34 
5.2.5 Offline Mode............................................................................................... 35 
5.2.6 Partial Offline Mode.................................................................................... 35 
5.2.6.1 Partial Offline Mode with GENy.................................................................. 36 
5.2.7 Passive State ............................................................................................. 39 
5.2.8 Tx Observe...................................

... [truncated — 286030 further characters not shown; see the original PDF] ...
```

## Original file

- Repository path: `/Doc/TechnicalReferences/TechnicalReference_CANDriver.pdf`

[Back to top](#_top)
