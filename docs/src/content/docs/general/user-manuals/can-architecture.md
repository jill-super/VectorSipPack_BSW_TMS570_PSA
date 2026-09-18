---
title: "CAN Architecture (CANbedded overview)"
description: "Converted Vector delivery document — searchable text extraction; the original PDF/HTML remains authoritative."
---
<!-- markdownlint-disable MD009 MD012 MD030 MD046 -->

> **Source:** `/Doc/UserManuals/CAN-Architecture.pdf` — Vector-proprietary PDF, converted automatically to Markdown for browsing.  
> Text was extracted with `pypdf`; headings/lists/tables/images are **not** faithfully preserved. 
> The PDF itself remains the authoritative document.

## Document information

- **Group:** User Manuals
- **Pages:** 28
- **PDF Title:** PowerPoint-Präsentation
- **Author(s):** Klaus Emmert
- **Subject:** 
- **Version:** 
- **Category:** CANcollege
- **Company:** Vector Informatik GmbH
- **Comments:** 

## PDF bookmarks (outline)

- CANbedded
- Introduction
- Introduction
- Introduction
- Introduction
- Tool Chain – Software Components
- Any ECU needs Communication Components
- Any ECU needs Communication Components
- Inside The ECU
- Inside The ECU
- CAN Driver
- CAN Driver - detailed
- Interaction Layer
- Interaction Layer - detailed
- Transport Protocol
- Transport Protocol - detailed
- Diagnostics Layer
- Diagnostics Layer - detailed
- Network Management
- Network Management - detailed
- Measurement and Calibration Protocol - XCP
- Universal Measurement and Calibration Protocol - detailed
- Communication Control Layer
- Communication Control Layer
- Generation Tool
- Generation Tool - detailed
- CANbedded Software Components and Standards
- Generation Process

## Extracted text (beginning of document)

_Showing first 11299 of ~11299 extracted characters._

```text
insert picture
8cm x 7cm
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
V2.04 2006-02-13
CANbedded
Embedded Software for Automotive Applications

2
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
Introduction
e.g. CAN Lowspeed:
Many ECUs participate in the 
CAN Lowspeed
Vehicle with different bus systems
(CAN Highspeed, CAN Lowspeed, LIN, FlexRay, MOST …)
For communication the ECUs need:
Physical connection >> bus system
Logical connection >> data base file >>

3
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
Introduction
The data base file is the basic element for ECU communication
ECUs, Signals, Messages
fixed
defined by the OEM
Attributes
flexible
defined by the OEM
and Vector
Assertions, 
Polling, Flags, 
Functions... 
Assertions, 
Polling, Flags, 
Functions... 
network wide
Assertions, 
Polling, Flags, 
Functions... 
ECU-specific
settings done by suppliers
with configuration tool
GENy/CANgen
ECU1 ECU2 ECU3
e.g. DBC, FIBEX, LDF

4
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
Introduction
Created by 
the OEM Data
base
CAN CANoe
Supplier 1
(Appl, GENy
CANbedded)
Data
base
Supplier 2
(Appl, GENy
CANbedded)
Supplier 3
(Appl, GENy
CANbedded)
Supplier 4
(Appl, GENy
CANbedded)
Data
base
Data
base
Dat
bas
a
e
this DBC is distributed to the suppliers
ECU1
basis 
for ECU 1
ECU2
basis 
for ECU 2
ECU3
basis
for ECU 3
ECU4
basis
for ECU 4
modification 
issues

5
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
Introduction
CAN CANoe
ECU1
ECU2
ECU3
ECU4
Almost the same communication / diagnostic tasks for all ECUs
T Save precious development time for your core application
T Avoid developing already existing solutions
>> use Standard Software Components
Software for Network 
Communication and 
Diagnostic
(Bus specific, same for all ECU
in one Bus system)
Application Software
(ECU-specific)

6
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
Tool Chain – Software Components
Diagnostics
Hardware control CAN / LIN communicationRe-Programming
Message handling
Application
Executable
Compiler
Linker

Flash
Code
CANfbl
OILGeneration
OIL Configuration
Operating System
osCAN
Customer specific
hardware
Physical busCAN LIN
Generation
Tool
Application
Communication Stack
CANbedded LIN CommunicationCANbedded
Flash Programming
CANfbl

CANoe
CANape
CANalyzer
CANdb++
Data
base
CANdela
Studio
CDD
ODX
CDDT
Your Task - Vector’s Solutions

7
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
Engine
Application
GearABS
Dashboard
Radio Navigation
CD-Changer Phone
Gateway
ClimaRoof
Powertrain
Multimedia
CANbedded Software 
Components
Body-CAN
ComputerSeat
Sensor 1 Sensor 2 Sensor 3
LIN
Door
Multimedia
Appl
CAN Bus
Any ECU needs Communication Components

8
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
Engine
Application
GearABS
Dashboard
Radio Navigation
CD
Changer Phone
Gateway
ClimaRoof
Powertrain
Body-CAN
Multimedia
CANbedded Software 
Components
ComputerSeat
Sensor 1 Sensor 2 Sensor 3
LIN
Door
Multimedia
Any ECU needs Communication Components

9
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
CAN Bus
Application
CANbedded Software Components
Application
CAN Controller
Transceiver
Inside The ECU

10
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
osCAN
CAN Controller
Transceiver
CAN Bus
Application
CANbedded Software Components
Inside The ECU

11
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
osCAN
CAN Controller
Transceiver
CAN Driver
CAN Bus
Application
CAN Driver

12
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
T Initialisation
T Transmission and Reception of Messages with Data-
and Functional Interface
T Data- and Functional Notification
T Indication (Rx)
T Confirmation (Tx)
T Overrun and Error Handling
T Wakeup Detection 
T Efficient Search Algorithms for Software 
Acceptance Filtering
Handling of Hardware Specific CAN Chip Characteristics and 
Provision of a Standardised Application Interface
CAN Driver - detailed

13
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
osCAN
CAN Driver
CAN Bus
Interaction 
Layer
Application
CAN Controller
Transceiver
Interaction Layer

14
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
Interaction Layer with Signal Interface
T Sending of Messages According to the Specified 
Transmission Types
T Checking of Minimum Distances Between Transmit 
Messages
T Monitoring of Receive Messages
T Setting of Default Values
T Ensuring of Data Consistency
T Signal Oriented Application Interface for Data 
Exchange and Notification
Interaction Layer - detailed

15
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
osCAN
CAN Driver
CAN Bus
Interaction 
Layer
Transport Protocol
Application
CAN Controller
Transceiver
Transport Protocol

16
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
T Segmentation of Data in Transmit Direction
T Collection of Data in Receive Direction 
T Exchange of Communication Parameters
T Control of Data Flow with Synchronisation of
Transmission and Reception
T Detection of Errors
T Message Loss
T Message Doubling
T Message Sequence
T Additional Addressing Information (Normal, 
Extended)
Transport Protocol for Data Exchange of Data Link 
Layer Independent Information
Transport Protocol - detailed

17
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
osCAN
Transport Protocol
CAN Driver
CAN Bus
Interaction 
Layer
Diagnostics
Layer
Application
CAN Controller
Transceiver
Diagnostics Layer

18
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
T Functional Interface for Diagnostic Services 
T Direct Processing of CAN Specific Diagnostic 
Requests (Enable/Disable Normal Message 
Transmission)
T Negative Responses (e.g. Service not Available)
T Exception Handling (e.g. Busy, Request Pending)
T Address Handling (Detection of Response Service 
Identification)
Diagnostics Layer According to ISO14229 / ISO14230 (Keyword 
Protocol 2000)
Diagnostics Layer - detailed

19
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
osCAN
Transport Protocol
CAN Driver
CAN Bus
Interaction 
Layer
Diagnostics
Layer
Network
Management
Application
CAN Controller
Transceiver
Network Management

20
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
T Synchronized Transition to Bus Sleep
T Determination of Net Configuration at Startup
T Monitoring of Net Configuration During Operation
T Error Recovery after Bus-Off
T Provision of Network Status Information
Network Management to Control the CAN Bus
Network Management - detailed

21
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
osCAN
Network
Management
Transport Protocol
CAN Driver
CAN Bus
Interaction 
Layer
Diagnostics
Layer Universal
Measure-
ment
And 
Calibration
Protocol
Application
CAN Controller
Transceiver
Measurement and Calibration Protocol - XCP

22
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
T Read and Write Access to Various Memory Locations
T Different Data Access Methods (Polling, Cyclic and 
Event-Triggered) 
T Flash Programming
T Simultaneous Handling of Several Controls
Universal Measurement and Calibration Protocol for 
Measurement and Calibration on various bus systems
Universal Measurement and Calibration Protocol - detailed

23
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
Communication
Control
Layer
osCAN
Network
Management
Transport Protocol
CAN Driver
CAN Bus
Interaction 
Layer
Diagnostics
Layer Universal
Measure-
ment
And 
Calibration
Protocol
Application
CAN Controller
Transceiver
Communication Control Layer

24
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
Integration of the Software Components
T CAN Driver, 
T Interaction Layer, 
T Network Management, 
T Transport Protocol
T Diagnostics
Abstraction for different
T Vehicle manufactureres
T Microcontrollers
T Compiler/linker
T CAN Controllers / Transceivers
T Configured via Generation Tool
T Global Debug Mechanism
Communication Control Layer
Communication Control Layer

25
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
osCAN
Network
Management
Transport Protocol
Communication
Control
Layer
Universal
Measure-
ment
And 
Calibration
Protocol
CAN Driver
CAN Bus
Interaction 
Layer
Diagnostics
Layer
Application
Generation 
Tool

CAN Controller
Transceiver
Generation Tool

26
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
T Used for the Complete Set of Vector’s CAN Software 
Components
T Driven by Communication Matrix ( Network 
Database)
T User Specific Settings for Each Node (Application 
Database)
T Part of Vector’s Tool Chain
Generation Tool for Parameters and Configuration
Generation Tool - detailed

27
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
osCAN
Network
Management
Transport Protocol
Communication
Control
Layer
Universal
Measure-
ment
And 
Calibration
Protocol
CAN Driver
Generation 
Tool
CAN Bus
Interaction 
Layer
Diagnostics
Layer
Application

/OSEKISO
ISO
/OSEKISO
HIS
ASAM
/OSEKISO
/OSEKISO
CAN Controller
Transceiver
CANbedded Software Components and Standards

28
© 2006. Vector Informatik GmbH. All rights reserved. Any distribution or copying is subject to prior written approval by Vector.
Slide: 
Generation Process
```

## Original file

- Repository path: `/Doc/UserManuals/CAN-Architecture.pdf`

[Back to top](#_top)
