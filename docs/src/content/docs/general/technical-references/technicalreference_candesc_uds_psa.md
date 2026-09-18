---
title: "Technical Reference: CANdesc UDS PSA"
description: "Converted Vector delivery document — searchable text extraction; the original PDF/HTML remains authoritative."
---
<!-- markdownlint-disable MD009 MD012 MD030 MD046 -->

> **Source:** `/Doc/TechnicalReferences/TechnicalReference_CANdesc_UDS_PSA.pdf` — Vector-proprietary PDF, converted automatically to Markdown for browsing.  
> Text was extracted with `pypdf`; headings/lists/tables/images are **not** faithfully preserved. 
> The PDF itself remains the authoritative document.

## Document information

- **Group:** CANdesc
- **Pages:** 18
- **PDF Title:** Technical Reference
- **Author(s):** Alexander Ditte
- **Subject:** CANdesc
- **Version:** 
- **Category:** 
- **Company:** 
- **Comments:** 

## PDF bookmarks (outline)

- History
- Contents
- Documents this one refers to ...
- CANdesc Support by Diagnostic Service
-   CANdesc
- How to…
-   …get the Id of the current active session
- CANdesc API categories
-   Single Context
-   Multiple Context
-   API Context Abstraction
-     Direct parameter usage
-       DESC_CONTEXT_PARAM_VALUE
-       DESC_CONTEXT_PARAM_ONLY
-       DESC_CONTEXT_PARAM_FIRST
-     Function declaration/definition usage
-       DESC_CONTEXT_FORMAL_PARAM_DEF_ONLY
-       DESC_CONTEXT_FORMAL_PARAM_DEF_FIRST
-     Universal context wrapper
-       DESC_CONTEXT_PARAM_WRAPPER_INDEX(contextConst)
-       DESC_CONTEXT_PARAM_WRAPPER_ONLY(contextConst)
-       DESC_CONTEXT_PARAM_WRAPPER_ONLY(contextConst)
-     Utility
-       DESC_CONTEXT_PARAM_DEF_LOCAL
-       DESC_CONTEXT_PARAM_DUMMY_USE
- Functions
-   Administrative Functions
-     DescInitPowerOn
-     DescInit
-   Help functions

## Detected section headings (heuristic)

- 1 History
- 2 Contents
- 6.3.2.1 DESC_CONTEXT_FORMAL_PARAM_DEF_ONLY.................................. 12
- 6.3.2.2 DESC_CONTEXT_FORMAL_PARAM_DEF_FIRST................................. 12
- 6.3.3.1 DESC_CONTEXT_PARAM_WRAPPER_INDEX(contextConst)............... 12
- 6.3.3.2 DESC_CONTEXT_PARAM_WRAPPER_ONLY(contextConst) ................ 12
- 6.3.3.3 DESC_CONTEXT_PARAM_WRAPPER_ONLY(contextConst) ................ 12
- 6.3.4.1 DESC_CONTEXT_PARAM_DEF_LOCAL................................................. 13
- 6.3.4.2 DESC_CONTEXT_PARAM_DUMMY_USE............................................... 13
- 3 Documents this one refers to…
- 4 CANdesc Support by Diagnostic Service
- 4.1 CANdesc
- 5 How to…
- 6 CANdesc API categories
- 6.1 Single Context
- 6.2 Multiple Context
- 6.3 API Context Abstraction
- 6.3.1 Direct parameter usage
- 6.3.1.1 DESC_CONTEXT_PARAM_VALUE
- 6.3.1.2 DESC_CONTEXT_PARAM_ONLY
- 6.3.1.3 DESC_CONTEXT_PARAM_FIRST
- 6.3.2 Function declarati on/definition usage
- 6.3.2.1 DESC_CONTEXT_FORMAL_PARAM_DEF_ONLY
- 6.3.2.2 DESC_CONTEXT_FORMAL_PARAM_DEF_FIRST
- 6.3.3 Universal context wrapper
- 6.3.3.1 DESC_CONTEXT_PARAM _WRAPPER_INDEX(contextConst)
- 6.3.3.2 DESC_CONTEXT_PARAM _WRAPPER_ONLY(contextConst)
- 6.3.3.3 DESC_CONTEXT_PARAM _WRAPPER_ONLY(contextConst)
- 6.3.4 Utility
- 6.3.4.1 DESC_CONTEXT_PARAM_DEF_LOCAL

## Extracted text (beginning of document)

_Showing first 12000 of ~18951 extracted characters across 18 pages._

```text
CANdesc 
Technical Reference 
 
PSA 
 
 
Version 1.00.00 
 
 
 
 
 
 
 
 
 
 
Authors: Alexander Ditte 
Version: 1.00.00 
Status: released (in preparation/completed/inspected/released) 
 
 
 
 

Technical Reference CANdesc UDS PSA 
2008, Vector Informatik GmbH Version: 1.00.00 
 
2/ 1 8
1 History 
Author Date Version Remarks 
Alexander Ditte 2007-12-05 1.0 Initial version 
 
 
 

Technical Reference CANdesc UDS PSA 
2008, Vector Informatik GmbH Version: 1.00.00 
 
3/ 1 8
2 Contents 
1 History .........................................................................................................................2 
2 Contents...................................................................................................................... 3 
3 Documents this one refers to… ................................................................................ 5 
4 CANdesc Support by Diagnostic Service ................................................................ 6 
4.1 CANdesc ...................................................................................................... 6 
5 How to…...................................................................................................................... 9 
5.1 …get the Id of the current active session..................................................... 9 
6 CANdesc API categories.......................................................................................... 10 
6.1 Single Context............................................................................................ 10 
6.2 Multiple Context ......................................................................................... 10 
6.3 API Context Abstraction ..............................................................................11 
6.3.1 Direct parameter usage...............................................................................11 
6.3.1.1 DESC_CONTEXT_PARAM_VALUE...........................................................11 
6.3.1.2 DESC_CONTEXT_PARAM_ONLY.............................................................11 
6.3.1.3 DESC_CONTEXT_PARAM_FIRST ............................................................11 
6.3.2 Function declaration/definition usage..........................................................11 
6.3.2.1 DESC_CONTEXT_FORMAL_PARAM_DEF_ONLY.................................. 12 
6.3.2.2 DESC_CONTEXT_FORMAL_PARAM_DEF_FIRST................................. 12 
6.3.3 Universal context wrapper.......................................................................... 12 
6.3.3.1 DESC_CONTEXT_PARAM_WRAPPER_INDEX(contextConst)............... 12 
6.3.3.2 DESC_CONTEXT_PARAM_WRAPPER_ONLY(contextConst) ................ 12 
6.3.3.3 DESC_CONTEXT_PARAM_WRAPPER_ONLY(contextConst) ................ 12 
6.3.4 Utility .......................................................................................................... 13 
6.3.4.1 DESC_CONTEXT_PARAM_DEF_LOCAL................................................. 13 
6.3.4.2 DESC_CONTEXT_PARAM_DUMMY_USE............................................... 13 
7 Functions .................................................................................................................. 14 
7.1 Administrative Functions ............................................................................ 14 
7.1.1 DescInitPowerOn ....................................................................................... 14 
7.1.2 DescInit ...................................................................................................... 15 
7.2 Help functions ............................................................................................ 16 

Technical Reference CANdesc UDS PSA 
2008, Vector Informatik GmbH Version: 1.00.00 
 
4/ 1 8
7.2.1 DescGetSessionIdOfSessionState............................................................. 16 
8 Glossary .................................................................................................................... 17 
9 Contact ...................................................................................................................... 18 

Technical Reference CANdesc UDS PSA 
2008, Vector Informatik GmbH Version: 1.00.00 
 
5/ 1 8
3 Documents this one refers to… 
 Technical Reference CANdesc and CANdesc (one for both) 
 User Manual CANdesc 
 
 
User Manual
Technical
Reference
General
Technical
Reference
OEM
You are here
 
Figure 3-1 Manuals and References for CANdesc 
All OEM specific topics with CANdesc are described within this technical reference and the 
common part (e.g. features, concepts) is in the generic technical reference. 
For faster integration, refer to the user manual CANdesc. 

Technical Reference CANdesc UDS PSA 
2008, Vector Informatik GmbH Version: 1.00.00 
 
6/ 1 8
4 CANdesc Support by Diagnostic Service 
There are three possible levels of support provided by CANdesc for any specific diagnostic 
request – complete, assisted and basic. The le vel of support provided by CANdesc varies 
according to CANdesc functionality and user se lection. All levels of support provide 
complete communication handling, including a ll transport protocol processing and error 
handling, diagnostic session and timer management and basic error checking. 
“Communication handling includes testing support of service, but also consistency of 
service, sub-function and/or identifier combination. Lengt h checking or request is 
performed. Validity of addressing is checked.” 
Error handling is a significant part of the EC U software. All errors appearing on this level 
are handled inside of CANdesc. 
 
4.1 CANdesc 
 
Complete 
Complete support means that CANdesc is ca pable of handling the diagnostic transaction 
without requesting support from (c alling) the ECU application. The ECU developer need 
not provide any code to help implement th e diagnostic feature an d CANdesc handles all 
processing. In case a service modifies stat es, the application will be notified using event-
callbacks – it does not have to concern about the protocol. 
Assisted 
Assisted support means that CANdesc is capa ble of fully parsing request messages and 
building response messages, but does not cont ain the logic necessary to execute the 
request or determine signal values. The ECU developer shall provide callbacks for 
CANdesc to invoke when needed to fill the logic gaps. 
Basic 
Basic support means that CANdesc is only ca pable of identifying that the ECU application 
shall process the request. The E CU application may have to pr ovide logic to validate the 
request message (length, sub-function/parameter evaluation) and build the response byte-
by-byte. 
 

Technical Reference CANdesc UDS PSA 
2008, Vector Informatik GmbH Version: 1.00.00 
 
7/ 1 8
 
10 – Diagnostic Session Control – Assisted 
The application shall provide only a functi on to check whether the session transition is 
allowed or not. All other tasks (e.g. re sponse assembling, state management) are 
performed by CANdesc. 
11 – Ecu Reset – Basic 
The application must provide a function that resets the ECU. 
14 – Clear Diagnostic Information – Basic 
The application must provide a function that clears fault memory. 
19 – Read DTC Information – Basic 
The application must pr ovide a function that implements the complete access to the fault 
memory. 
22 – Read Data By Identifier – Complete/Assisted 
CANdesc completely implements this service for IDs that map to global variables. 
Assisted support is provided for IDs that do not map to global variables (e.g. EEPROM / 
I/O Ports). 
The so called “multiple identifier in sing le request” support is handled by CANdesc 
completely. 
23 – Read Memory By Address – Basic 
The application must provide a function that implements the read access to the memory. 
27 – Security Access – Basic 
The application must provide a function which includes the complete seed/key algorithm. 
The state management can be designed to be handled by CANdesc. 
2E – Write Data By Identifier – Complete/Assisted 
CANdesc completely implements this service for IDs that map to global variables. 
Assisted support is provided for IDs that do not map to global variables. 
2F – Input Output Control By Identifier – Basic 
The application must provi de a function which implement s the complete I/O control 
operations. 
31 – Routine Control – Basic 
The application must provide a function which implements the complete routine control. 
34 – Request Download – Basic 
The application must provide a function which implements the complete service. Instead 
the Vector FlashBootLoader can be used. 

Technical Reference CANdesc UDS PSA 
2008, Vector Informatik GmbH Version: 1.00.00 
 
8/ 1 8
35 – RequestUpload – Basic 
The application must provide a function which implements the complete service. Instead 
the Vector FlashBootLoader can be used. 
36 – Transfer Data – Basic 
The application must provide a function which implements the complete service. Instead 
the Vector FlashBootLoader can be used. 
37 – Request Transfer Exit – Basic 
The application must provide a function which implements the complete service. Instead 
the Vector FlashBootLoader can be used. 
3D – Write Memory By Address – Basic 
The application must provide a function that implements the write access to the memory. 
3E – Tester Present – Complete 
CANdesc completely implements this service. 
85 – Control DTC Setting – Basic 
The application must provide a function that controls the fault memory storage. 
 
Diagnostic services not listed are not suppor ted in any way by CANdesc and must be 
implemented entirely by the ECU developer as a workaround. 
 
 

Technical Reference CANdesc UDS PSA 
2008, Vector Informatik GmbH Version: 1.00.00 
 
9/ 1 8
5 How to… 
There are some important use cases you have to consider in order to fulfill the PSA 
diagnostic requirements. CANdesc offers special APIs and mechanisms to help your 
application to realize these requirements and here you will find out how to do this. 
 
5.1 …get the Id of the current active session 
PSA defines no dedicated parameter identifier for reporting the current active diagnostic 
session in the ECU, but if required you can use CANdesc to help you: 
The CANdesc APIs for state access (i.e. De scGetStateSession()) returns the current 
session, but it is only an internal representation of the session not the session identifier. So 
you cannot use the return value of this API for that report. 
To get the session Id your application shall use the API DescGetSessionIdOfSessionState 
that converts a session state internal repr esentation into its corresponding session Id (e.g. 
for the default session the state is 0x01, t he session Id - 0x01, but for the extended 
session the state representation is 0x04, the session Id – 0x03). 
 

Technical Reference CANdesc UDS PSA 
2008, Vector Informatik GmbH Version: 1.00.00 
 
10 / 18
6 CANdesc API categories 
CANdesc can be instantiated in case the configuration r equires multiple diagnostic 
instances or/and parallel service processing. In order to offer maximum optimization for the 
single instance configurations there are two categories of CANdesc API. 
 
 
Info 
Currently Multiple Context is NOT relevant for PSA. 
 
6.1 Single Context 
In this configuration, the run-time and c ode overhead of an indexed operation mode is 
reduced to a minimum. 
6.2 Multiple Context 
In this configuration, the code is usi ng additional handles for exact addressing and 
recognition of the used API. 
 
For PSA there it depends on the configur ation if a multi- or single-instance 
diagnostics will be used. To lower the developm ent effort of your application and to 
be independent of the current configuration, please use the special API wrappers as 
described below. 
 
 

Technical Reference CANdesc UDS PSA 
2008, Vector Informatik GmbH Version: 1.00.00 
 
11 / 18
 
6.3 API Context Abstraction 
The following chapters describe the main use- cases w

... [truncated — 6951 further characters not shown; see the original PDF] ...
```

## Original file

- Repository path: `/Doc/TechnicalReferences/TechnicalReference_CANdesc_UDS_PSA.pdf`

[Back to top](#_top)
