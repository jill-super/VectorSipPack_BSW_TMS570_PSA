---
title: "Technical Reference: Nm_IndOsek"
description: "Converted Vector delivery document — searchable text extraction; the original PDF/HTML remains authoritative."
---
<!-- markdownlint-disable MD009 MD012 MD030 MD046 -->

> **Source:** `/Doc/TechnicalReferences/TechnicalReference_Nm_IndOsek.pdf` — Vector-proprietary PDF, converted automatically to Markdown for browsing.  
> Text was extracted with `pypdf`; headings/lists/tables/images are **not** faithfully preserved. 
> The PDF itself remains the authoritative document.

## Document information

- **Group:** NM module
- **Pages:** 55
- **PDF Title:** TechnicalReference
- **Author(s):** Markus Schwarz
- **Subject:** Nm_IndOsek
- **Version:** 1.12
- **Category:** Indirect Network Management
- **Company:** Vector Informatik GmbH
- **Comments:** released

## PDF bookmarks (outline)

- 1 Document Information
-   1.1 History
-   1.2 Reference Documents
-   1.3  Abbreviations & Acronyms
-   1.4 Naming Convention
- 2 Overview
-   2.1 Delivery Package
-   2.2  Concept
- 3 Features
-   3.1 General
-     3.1.1 Overview
-     3.1.2 Control
-     3.1.3 Event Notification
-     3.1.4 Event Processing
-     3.1.5 Status Information
-   3.2  RX Supervision
-     3.2.1 Overview
-     3.2.2 Control
-     3.2.3 Event Notification
-     3.2.4 Status Information
-   3.3  TX Supervision
-     3.3.1 Overview
-     3.3.2 Control
-     3.3.3 Event Notification
-     3.3.4 Status Information
-   3.4  BusOff Supervision
-     3.4.1 Overview
-     3.4.2 Control
-     3.4.3 Event Notification
-     3.4.4 Status Information

## Detected section headings (heuristic)

- 1 Document Information
- 1.1 History
- 1.2 Reference Documents
- 1.3 Abbreviations & Acronyms
- 1.4 Naming Convention
- 2 Overview
- 2.1 Delivery Package
- 2.2 Concept
- 3 Features
- 3.1 General
- 3.1.1 Overview
- 3.1.2 Control
- 3.1.3 Event Notification
- 3.1.4 Event Processing
- 3.1.5 Status Information
- 3.2 RX Supervision
- 3.2.1 Overview
- 3.2.2 Control
- 3.2.3 Event Notification
- 3.2.4 Status Information
- 3.3 TX Supervision
- 3.3.1 Overview
- 3.3.2 Control
- 3.3.3 Event Notification
- 3.3.4 Status Information
- 3.4 BusOff Supervision
- 3.4.1 Overview
- 3.4.2 Control
- 3.4.3 Event Notification
- 3.4.4 Status Information

## Extracted text (beginning of document)

_Showing first 12000 of ~76611 extracted characters across 55 pages._

```text
Nm_IndOsek 
Technical Reference 
 
Indirect Network Management 
 
 
Version 1.12 
 
 
 
 
 
 
 
Authors: Markus Schwarz 
Version: 1.12 
Status: released (in preparation/completed/inspected/released) 
 
 
 

TechnicalReference Nm_IndOsek 
1 Document Information 
1.1 History 
Author Date Version Remarks 
Ralf Fritz 21.06.2001 1.00 Creation of this document 
Ralf Fritz 01.10.2001 1.01 User value support added, 
Multiple ECU added 
Dieter Schaufelberger 2002-02-28 1.02 ApplInmNmInitVolatileCounters( 
) and Macros added 
Dieter Schaufelberger 2002-08-15 1.03 Adoptions to new system 
structure 
Dieter Schaufelberger 2002-09-11 1.04 Description of the database 
attributes revised 
Dieter Schaufelberger 2002-10-22 1.05 Revision 
Inserted new chapter: 
Particularities of RENAULT Bus 
Off supervision 
Dieter Schaufelberger 2002-11-28 1.06 Revision 
New configuration features 
Dieter Schaufelberger 2003-07-31 1.07 Correction in the attribute part 
Dieter Schaufelberger 2004-04-05 1.08 Inserted Support of LEVEL 3 
Dieter Schaufelberger 2004-10-20 1.09 New OSEK_INM Version 2.0 
Markus Schwarz 2006-09-12 1.10 Changed chapter 1.1, new 
layout 
Markus Schwarz 2006-12-19 1.11 Revision and rework 
Markus Schwarz 2008-01-21 1.12 added chapter on configuration 
with GENy 
Table 1-1 History of the Document 
1.2 Reference Documents 
Index Document 
[UR_01] OSEK/VDX Network Management 2.53 
[UR_02] Specification of the generic communication layers for CAN embedded networks 
at RENAULT & PSA 
Version 2.1 dated 04/01/98 
referenced RENAULT: DIV/D3E/60601/98/032gb 
Table 1-2 References Documents 
©2008, Vector Informatik GmbH Version: 1.12 
based on template version 1.9 
2/ 5 5

TechnicalReference Nm_IndOsek 
1.3 Abbreviations & Acronyms 
Abbreviation Complete expression 
CAN Controller Area Network 
ECU Electronic Control Unit 
IL Interaction Layer 
NM Network Management 
Note: Within this document, NM refers to Nm_IndOsek 
OEM Original Equipment Manufacturer 
Table 1-3 Abbreviations & acronyms 
1.4 Naming Convention 
Naming Description 
Nm_IndOsek Refers to the Vector CANbedded software component that handles the 
indirect network management. 
Table 1-4 Naming convention 
 
 
 
 
 
 
 
 
 
 
 
 
Please note 
We have configured the programs in accordance with your specifications in the 
questionnaire. Whereas the programs do support other configurations than the one 
specified in your questionnaire, Vector’s release of the programs delivered to your 
company is expressly restricted to the configuration you have specified in the 
questionnaire.
©2008, Vector Informatik GmbH Version: 1.12 
based on template version 1.9 
3/ 5 5

TechnicalReference Nm_IndOsek 
Contents 
1 Document Information ............................................................................................... 2 
1.1 History .......................................................................................................... 2 
1.2 Reference Documents ................................................................................. 2 
1.3 Abbreviations & Acronyms ........................................................................... 3 
1.4 Naming Convention...................................................................................... 3 
2 Overview ..................................................................................................................... 9 
2.1 Delivery Package ......................................................................................... 9 
2.2 Concept...................................................................................................... 10 
3 Features .................................................................................................................... 11 
3.1 General .......................................................................................................11 
3.1.1 Overview .....................................................................................................11 
3.1.2 Control.........................................................................................................11 
3.1.3 Event Notification ........................................................................................11 
3.1.4 Event Processing ........................................................................................11 
3.1.5 Status Information ...................................................................................... 12 
3.2 RX Supervision .......................................................................................... 13 
3.2.1 Overview .................................................................................................... 13 
3.2.2 Control........................................................................................................ 13 
3.2.3 Event Notification ....................................................................................... 13 
3.2.4 Status Information ...................................................................................... 13 
3.3 TX Supervision........................................................................................... 14 
3.3.1 Overview .................................................................................................... 14 
3.3.2 Control........................................................................................................ 14 
3.3.3 Event Notification ....................................................................................... 14 
3.3.4 Status Information ...................................................................................... 14 
3.4 BusOff Supervision .................................................................................... 15 
3.4.1 Overview .................................................................................................... 15 
3.4.2 Control........................................................................................................ 15 
3.4.3 Event Notification ....................................................................................... 15 
3.4.4 Status Information ...................................................................................... 15 
3.4.5 Others ........................................................................................................ 15 
3.5 Generic Supervision................................................................................... 16 
3.5.1 Overview .................................................................................................... 16 
3.5.2 Control........................................................................................................ 16 
3.5.3 Event Notification ....................................................................................... 16 
3.5.4 Status Information ...................................................................................... 16 
©2008, Vector Informatik GmbH Version: 1.12 
based on template version 1.9 
4/ 5 5

TechnicalReference Nm_IndOsek 
3.5.5 Others ........................................................................................................ 16 
4 Integration................................................................................................................. 17 
4.1 Involved Files ............................................................................................. 17 
4.2 Include Structure ........................................................................................ 17 
4.3 Necessary Steps to Integrate the NM in Your Project................................ 18 
4.4 Necessary Steps to Run the NM................................................................ 18 
5 Configuration............................................................................................................ 19 
6 Integration Hints....................................................................................................... 22 
6.1 CANbedded stack ...................................................................................... 22 
6.1.1 Vector Station Manager.............................................................................. 22 
6.2 Special use-cases ...................................................................................... 22 
6.2.1 Multiple ECUs ............................................................................................ 22 
7 Related Files ............................................................................................................. 23 
7.1 Static Files.................................................................................................. 23 
7.2 Dynamic Files............................................................................................. 23 
8 API Description......................................................................................................... 24 
8.1 General ...................................................................................................... 24 
8.1.1 Multi channel usage ................................................................................... 24 
8.2 API ............................................................................................................. 25 
8.2.1 NM Handler ................................................................................................ 26 
8.2.2 RX Supervision .......................................................................................... 30 
8.2.3 TX Supervision........................................................................................... 33 
8.2.4 BusOff Supervision .................................................................................... 36 
8.2.5 User-specific Supervision........................................................................... 39 
8.3 Callbacks.................................................................................................... 42 
8.3.1 NM Handler ................................................................................................ 43 
8.3.2 RX Supervision .......................................................................................... 44 
8.3.3 TX Supervision........................................................................................... 46 
8.3.4 BusOff Supervision .................................................................................... 48 
8.3.5 Generic Supervision................................................................................... 50 
8.4 Other Interfaces ......................................................................................... 52 
8.4.1 Version Information .................................................................................... 52 
9 Working with the Code............................................................................................. 53 
9.1 Version Information .................................................................................... 53 
9.2 Application Interface................................................................................... 53 
©2008, Vector Informatik GmbH Version: 1.12 
based on template version 1.9 
5/ 5 5

TechnicalReference Nm_IndOsek 
10 CANdb Attributes ..................................................................................................... 54 
 
©2008, Vector Informatik GmbH Version: 1.12 
based on template version 1.9 
6/ 5 5

TechnicalReference Nm_IndOsek 
Illustrations 
Figure 2-1 Concept of NM within the CANbedded stack.................................................. 10 
Figure 4-1 Include structure ............................................................................................. 17 
Figure 5-1 System-specific configuration ......................................................................... 19 
Figure 5-2 Channel-specific configuration........................................................................ 21 
 
Tables 
Table 1-1 His

... [truncated — 64611 further characters not shown; see the original PDF] ...
```

## Original file

- Repository path: `/Doc/TechnicalReferences/TechnicalReference_Nm_IndOsek.pdf`

[Back to top](#_top)
