---
title: "User Manual CANdesc"
description: "Converted Vector delivery document — searchable text extraction; the original PDF/HTML remains authoritative."
---
<!-- markdownlint-disable MD009 MD012 MD030 MD046 -->

> **Source:** `/Doc/UserManuals/UserManual_CANdesc.pdf` — Vector-proprietary PDF, converted automatically to Markdown for browsing.  
> Text was extracted with `pypdf`; headings/lists/tables/images are **not** faithfully preserved. 
> The PDF itself remains the authoritative document.

## Document information

- **Group:** User Manuals
- **Pages:** 72
- **PDF Title:** User Manual <User Manual Titlel>
- **Author(s):** Scheufele, Manuela
- **Subject:** <User Manual Subtitle>
- **Version:** 
- **Category:** 
- **Company:** Vector Informatik GmbH
- **Comments:** 

## PDF bookmarks (outline)

- 1 Manual Information
-   1.1 About this user manual
-     1.1.1 Certification
-     1.1.2 Warranty
-     1.1.3 Registered trademarks
-     Errata Sheet of manufacturers
- 2 Getting Started
-   2.1 How to use this Manual
- 3 Basic Information
-   An Overall View
-   3.2 What is Diagnostic
-   3.3 What happens during Diagnostics?
-   3.4 What is CANdesc?
-   3.5 Tools and Files
-     3.5.1 CANdela Studio, CDDT, CDD
-     3.5.2 Generation Tool, CDD, DBC
-     3.5.3 Generation Process with CANbedded Software Components
-   3.6 What CANdesc does
-   3.7 Diagnostics – a more detailed View
-     3.7.1 Basic Nomenclature from the Bottom Up
-     3.7.2 The same Nomenclature from the Top Down
-     3.7.3 Where to find this Nomenclature in CANdela Studio
-     3.7.4 Generic Handling of a Diagnostic Request in the CANdesc Component
-     3.7.5 User, None, OEM, Generated – what does this mean?
- 4 A Few STEPS to CANdesc
-   4.1 STEP What do you need before start?
-   Startup Code
-   Overview
-   4.4 STEP Installation
-   4.5 STEP Configuration with the Generation Tool

## Detected section headings (heuristic)

- 1 Manual Information 6
- 1.1 About this user manual 7
- 1.1.1 Certification 8
- 1.1.2 Warranty 8
- 1.1.3 Registered trademarks 8
- 1.1.4 Errata Sheet of manufacturers 8
- 2 Getting Started 9
- 2.1 How to use this Manual 10
- 3 Basic Information 11
- 3.1 An Overall View 12
- 3.2 What is Diagnostic 13
- 3.3 What happens during Diagnostics? 13
- 3.4 What is CANdesc? 14
- 3.5 Tools and Files 14
- 3.5.1 CANdela Studio, CDDT, CDD 14
- 3.5.2 Generation Tool, CDD, DBC 14
- 3.5.3 Generation Process with CANbedded Software Components 15
- 3.6 What CANdesc does 15
- 3.7 Diagnostics – a more detailed View 17
- 3.7.1 Basic Nomenclature from the Bottom Up 18
- 3.7.2 The same Nomenclature from the Top Down 19
- 3.7.3 Where to find this Nomenclature in CANdela Studio 19
- 3.7.4 Generic Handling of a Diagnostic Request in the CANdesc Component 21
- 3.7.5 User, None, OEM, Generated – what does this mean? 23
- 4 A Few STEPS to CANdesc 24
- 4.1 STEP What do you need before start? 25
- 4.2 Startup Code 25
- 4.3 Overview 25
- 4.4 STEP Installation 26
- 4.5 STEP Configuration with the Generation Tool 26

## Extracted text (beginning of document)

_Showing first 12000 of ~94450 extracted characters across 72 pages._

```text
User Manual 
CANdesc 
A Step by Step Introduction
Version 1.7 
English 
 
 

 
 
 
Impressum 
 
Vector Informatik GmbH 
Ingersheimer Straße 24 
D-70499 Stuttgart 
 
 
The information and data given in this user manual can be changed without prior notice. No part of this manual may be reproduced in 
any form or by any means without the written permission of the publisher, regardless of which method or which instruments, electronic 
or mechanical, are used. All technical information, drafts, etc. are liable to law of copyright protection. 
 © Copyright 2009, Vector Informatik GmbH 
All rights reserved. 
 

User Manual CANdesc Manual Information 
Manual History 
Author Date Version Details 
Klaus Emmert 2004-05-10 1.1 Vector symbols included, template 
version 1.8 used (this history 
included), AppDesc… changed to 
ApplDesc due to software 
modifications, description of GENy 
as generation tool added, testing of 
diagnostics layer described with 
CANoe demo configuration, further 
Information about diagnostic buffer 
(linear and ring buffer mechanism) 
and the repeated service call 
feature 
Klaus Emmert 2004-10-15 1.2 Modifications after Review. 
Klaus Emmert 2005-08-12 1.3 Two new functions: 
DescTimerTask(), 
DescStateTask(). 
These two functions can be used 
instead of DescTask to handle the 
timers and the application 
separately. 
Klaus Emmert 2006-03-24 1.4 Issues in example code fixed 
Document overview added 
Oliver Garnatz 2007-01-12 1.5 Added description of 
CANdesc_ConnectorCAN GENy 
component 
Klaus Emmert 2008-01-28 1.6 References fixed 
Manuela Scheufele 2009-07-27 1.7 (see section Version 1.7 on page 
66) 
 
 
Reference Documents 
No. Source Title 
[1] Vector Informatik Technical Reference CANdesc 
[2] Vector Informatik Technical Reference CANdescBasic 
 
 
© Vector Informatik GmbH Version 1.7 - 3 - 

Manual Information User Manual CANdesc 
Inhaltsverzeichnis 
1 Manual Information 6 
1.1 About this user manual 7 
1.1.1 Certification 8 
1.1.2 Warranty 8 
1.1.3 Registered trademarks 8 
1.1.4 Errata Sheet of manufacturers 8 
2 Getting Started 9 
2.1 How to use this Manual 10 
3 Basic Information 11 
3.1 An Overall View 12 
3.2 What is Diagnostic 13 
3.3 What happens during Diagnostics? 13 
3.4 What is CANdesc? 14 
3.5 Tools and Files 14 
3.5.1 CANdela Studio, CDDT, CDD 14 
3.5.2 Generation Tool, CDD, DBC 14 
3.5.3 Generation Process with CANbedded Software Components 15 
3.6 What CANdesc does 15 
3.7 Diagnostics – a more detailed View 17 
3.7.1 Basic Nomenclature from the Bottom Up 18 
3.7.2 The same Nomenclature from the Top Down 19 
3.7.3 Where to find this Nomenclature in CANdela Studio 19 
3.7.4 Generic Handling of a Diagnostic Request in the CANdesc Component 21 
3.7.5 User, None, OEM, Generated – what does this mean? 23 
4 A Few STEPS to CANdesc 24 
4.1 STEP What do you need before start? 25 
4.2 Startup Code 25 
4.3 Overview 25 
4.4 STEP Installation 26 
4.5 STEP Configuration with the Generation Tool 26 
4.5.1 Using the Generation Tool CANgen 26 
4.5.2 Using the Generation Tool GENy 27 
4.6 STEP Generating Files 29 
4.6.1 Using Generation Tool CANgen 29 
4.6.2 Using the Generation Tool GENy 32 
4.7 STEP Add CANbedded to your Project 32 
4.8 STEP Adapt Your Application Files 33 
4.8.1 Including, Initializing and Cyclic Calling 33 
4.9 STEP Functional Connection between your Application and CANdesc/CANdela Studio 35 
4.9.1 How to handle User-Defined Handlers 35 
4.9.2 How to Handle Predefined Handlers (for MainHandler only) 38 
4.9.3 Handling OEM-Specific Settings 40 
- 4 - Version 1.7 © Vector Informatik GmbH 

User Manual CANdesc Manual Information 
4.10 STEP Compile and link your Project 41 
4.11 STEP Test it via CANoe 41 
4.11.1 Start CANoe.CAN OSEK TP enlarged 41 
4.11.2 Test of CANdesc 42 
5 Further Information 44 
5.1 Diagnostic State Handling using CANdela Studio 45 
5.2 Typical Examples of State Groups and States in an Automotive Environment 45 
5.3 Creating and editing State Groups, States and Transitions 45 
5.4 Connection between the states and your application 47 
5.5 Diagnostic Buffer 48 
5.5.1 Linear Diagnostic Buffer 48 
5.5.2 Ring Buffer Mechanism 49 
5.5.2.1 Activation of the Ring Buffer 51 
5.5.2.2 Main Control Functions for the Ring Buffer Mechanism 51 
5.5.2.3 Examples for Ring Buffer Mechanism 52 
5.6 Repeated Service Call Feature 55 
5.6.1 Activation of the Repeated Service Call 55 
5.6.2 Repeated Service Call and Ring Buffer 1 – “Write and Check” 56 
5.6.3 Repeated Service Call and Ring Buffer 2 – “Check and Write” 57 
6 Additional Information 58 
6.1 Persistors 59 
6.1.1 Update Persistors – Install current Version 60 
7 FAQs 63 
7.1 Introduction 64 
7.2 Frequently Asked Questions 64 
8 What’s new, what’s changed 65 
8.1 Version 1.7 66 
8.1.1 What’s new 66 
8.1.2 What’s changed 66 
9 Address table 67 
10 Glossar 69 
11 Index 70 
 
© Vector Informatik GmbH Version 1.7 - 5 - 

Manual Information User Manual CANdesc 
1 Manual Information 
In this chapter you find the following information: 
1.1 About this user manual page 7
 Certification 
 Warranty 
 Registered trademarks 
 Errata Sheet of manufacturers 
 
 
- 6 - Version 1.7 © Vector Informatik GmbH 

User Manual CANdesc Manual Information 
1.1 About this user manual 
The user manual provides the following access help: Finding information 
quickly ¼ At the beginning of each chapter you will find a summary of the contents, 
¼ In the header you can see in which chapter and paragraph you are, 
¼ In the footer you can see to which version the user manual replies, 
¼ At the end of the user manual you will find an index, with whose help you will 
quickly find information, 
¼ Also at the end of the user manual you will find a glossary in which you can look 
up an explanation of used technical terms 
 
Conventions In the two following charts you will find the conventions used in the user manual 
regarding utilized spellings and symbols. 
 
 Style Utilization 
 bold Blocks, surface elements, window- and dialog names of the 
software. Accentuation of warnings and advices. 
[OK] Push buttons in brackets 
File|Save Notation for menus and menu entries 
 MICROSAR Legally protected proper names and side notes. 
 Source Code File name and source code. 
 Hyperlink Hyperlinks and references. 
 <CTRL>+<S> Notation for shortcuts. 
 
 Symbol Utilization 
 
 
Here you can obtain supplemental information. 
 
 
This symbol calls your attention to warnings. 
 
 
Here you can find additional information. 
 
 
Here is an example that has been prepared for you. 
 
 
Step-by-step instructions provide assistance at these points. 
 
 
Instructions on editing files are found at these points. 
 
 
 
This symbol warns you not to edit the specified file. 
 
© Vector Informatik GmbH Version 1.7 - 7 - 

Manual Information User Manual CANdesc 
1.1.1 Certification 
Certified Quality 
Management System 
Vector Informatik GmbH has ISO 9001:2000 certification. The ISO standard is a 
globally recognized standard. 
 
Spice Level 3 The Embedded Software Components business area at Vector Informatik GmbH 
achieved process maturity level 3 during a HIS-conformant assessment. 
 
1.1.2 Warranty 
Restriction of 
warranty 
 
We reserve the right to change the contents of the documentation and the software 
without notice. Vector Informatik GmbH assumes no liability for correct contents or 
damages which are resulted from the usage of the documentation. We are grateful for 
references to mistakes or for suggestions for improvement to be able to offer you 
even more efficient products in the future. 
 
1.1.3 Registered trademarks 
Registered 
trademarks 
 
All trademarks mentioned in this documentation and if necessary third party 
registered are absolutely subject to the conditions of each valid label right and the 
rights of particular registered proprietor. All trademarks, trade names or company 
names are or can be trademarks or registered trademarks of their particular 
proprietors. All rights which are not expressly allowed are reserved. If an explicit label 
of trademarks, which are used in this documentation, fails, should not mean that a 
name is free of third party rights. 
 ¼ Outlook , Windows, Windows XP, Windows 2000, Windows NT, Visual Studio are 
trademarks of the Microsoft Corporation. 
 
1.1.4 Errata Sheet of manufacturers 
 
Caution: Vector only delivers software! 
Your hardware manufacturer will provide you with the necessary errata sheets 
concerning your used hardware. In case of errata dealing with CAN please provide us 
the relevant erratas and we will figure out whether this hardware problem is already 
known to us or whether to get a possible workaround. 
 
 
Info: Because of many NDAs with different hardware manufacturers or because we 
are not informed about, we are not able to provide you with information concerning 
hardware errata of the hardware manufacturers. 
 
 
- 8 - Version 1.7 © Vector Informatik GmbH 

User Manual CANdesc Getting Started 
2 Getting Sta
In this chapter you find the following information: 
rted 
2.1 How to use this Manual page 10
 
 
© Vector Informatik GmbH Version 1.7 - 9 - 

Getting Started User Manual CANdesc 
2.1 How to use this Manual 
by step. 
 nswers to special questions without reading the whole document us
 Just follow the description step 
 
FAQ To find a e the 
FAQ list (see section FAQs on page 63). 
 
- 10 - Version 1.7 © Vector Informatik GmbH 

User Manual CANdesc Basic Information 
3 Basic Information 
In this chapter you find the following information: 
3.2 What is Diagnos 13tic page
3.3 What happens during Diagnostics? page 13
3.4 What is CANdesc? page 14
3.5 Tools and Files page 14
 CANdela Studio, CDDT, CDD 
 Generation Tool, CDD, DBC 
 Generation Process with CANbedded Software Components 
3.6 What CANdesc does page 15
3.7 Diagnostics – a more detailed View page 17
 Basic Nomenclature from the Bottom Up 
 The same Nomenclature from the Top Down 
 Where to find this Nomenclature in CANdela Studio 
 Generic Handling of a Diagnostic Request in the CANdesc Component 
 User, None, OEM, Generated – what does this mean? 
 
© Vector Informatik GmbH Version 1.7 - 11 - 

Basic Information User Manual CANdesc 
3.1 An Overall View 
ECU in the focus What we are now talking about 
shown in the figure below. Almost every 
is an ECU, a module to be built-in a vehicle like 
ECU participates in a certain bus system like 
xRay or LIN. e.g. CAN, Fle
 
 
Vehicle with different bus systems
 CAN Highspeed
 CAN Lowspeed
 LIN
 FlexRay
 MOST
 So any ECU within one bus system has to provide an identical interface to this bus 
system because all ECUs have to share information via this bus system as you see in 
the figure below. 
 
CAN Lowspeed as 
an example bus 
system 
 
 
 
 For that reason all ECUs are built-up in the same way. There is a software part to 
realize the main job (application) of this ECU e.g. to control the engine or a door. The 
other part is the software part to be able to communicate with the other ECUs via the 
bus system that is the communication software. 
 
- 12 - Version 1.7 © Vector Informatik GmbH 

User Manual CANdesc Basic Information 
Application Software 
Software for Network 
Communication and Diagnostics
 
 
 
3.2 What is Diagnostic 
Dia'gno stics - 
Detection, 
Examination of a 
machine; 
[greek. diagnoskein 
„analyze deeply, 
differentiate] 
In contrast to Dia’gno 
 sis – Examination 
(med.) 
Diagnostics in a technical context is the examination of a machine. But diagnostics in 
this context goes way beyond this definition. 
Diagnostics comprises function monitoring, error detection, fault memory, activation, 
data acquisition etc. and is used for variant coding, end-of-line programming, 
reprogramming, identification etc. 
3.3 What hap
In most cases an Off-Board tester (Client) sends a diagnostic request to the ECU (via 
CAN) and the ECU (Server) sends back a diagnostic response. This can be a positive 
or a negative response. The following fi

... [truncated — 82450 further characters not shown; see the original PDF] ...
```

## Original file

- Repository path: `/Doc/UserManuals/UserManual_CANdesc.pdf`

[Back to top](#_top)
