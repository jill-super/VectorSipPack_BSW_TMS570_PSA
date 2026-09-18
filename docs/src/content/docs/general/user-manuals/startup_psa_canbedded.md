---
title: "Startup with PSA — Step-by-Step Introduction"
description: "Converted Vector delivery document — searchable text extraction; the original PDF/HTML remains authoritative."
---
<!-- markdownlint-disable MD009 MD012 MD030 MD046 -->

> **Source:** `/Doc/UserManuals/Startup_PSA_CANbedded.pdf` — Vector-proprietary PDF, converted automatically to Markdown for browsing.  
> Text was extracted with `pypdf`; headings/lists/tables/images are **not** faithfully preserved. 
> The PDF itself remains the authoritative document.

## Document information

- **Group:** User Manuals
- **Pages:** 52
- **PDF Title:** User Manual <User Manual Titlel>
- **Author(s):** Scheufele, Manuela
- **Subject:** <User Manual Subtitle>
- **Version:** Version 3.2
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
-   2.2 Start immediately or need Basic Information?
- 3 A few STEPS to Basic ECU with PSA CANbedded
-   3.1 STEP What do you need before start?
-   3.2 STEP Installation
-     3.2.1 BSW folder
-   3.3 STEP Configuration Tool and DBC File
-     3.3.1 Start GENy with a Link or a Batch File
-     3.3.2 Preparations in GENy
-     3.3.3 Settings for the CANbedded Software Components
-   3.4 STEP Generate Files
-   3.5 STEP Add CANbedded  to Your Project 
-   3.6 STEP Adapt your Application Files
-     3.6.1 Including, Initialization and Cyclic Calls
-     3.6.2 Application Handling of User Requests and the Bus Communication
-     3.6.3 CANbedded Software Component Callback Functions
-   3.7 STEP Compile and Link your Project
-   3.8 STEP Test it via CANoe
-   3.9 STEP Test and Release Hints
- 4 Basic Information
-   4.1 Documentation Structure for CANbedded Components
-     4.1.1 Configuration Tools and Files
-   An Overall View

## Detected section headings (heuristic)

- 1 Manual Information 5
- 1.1 About this user manual 6
- 1.1.1 Certification 7
- 1.1.2 Warranty 7
- 1.1.3 Registered trademarks 7
- 1.1.4 Errata Sheet of manufacturers 7
- 2 Getting Started 8
- 2.1 How to use this Manual 9
- 2.2 Start immediately or need Basic Information? 9
- 3 A few STEPS to Basic ECU with PSA CANbedded 10
- 3.1 STEP What do you need before start? 11
- 3.2 STEP Installation 11
- 3.2.1 BSW folder 12
- 3.2.2 Installation GENy Framework 12
- 3.3 STEP Configuration Tool and DBC File 13
- 3.3.1 Start GENy with a Link or a Batch File 13
- 3.3.2 Preparations in GENy 14
- 3.3.3 Settings for the CANbedded Software Components 18
- 3.4 STEP Generate Files 23
- 3.5 STEP Add CANbedded to Your Project 24
- 3.6 STEP Adapt your Application Files 24
- 3.6.1 Including, Initialization and Cyclic Calls 25
- 3.6.2 Application Handling of User Requests and the Bus Communication 25
- 3.6.3 CANbedded Software Component Callback Functions 26
- 3.7 STEP Compile and Link your Project 27
- 3.8 STEP Test it via CANoe 27
- 3.9 STEP Test and Release Hints 28
- 4 Basic Information 29
- 4.1 Documentation Structure for CANbedded Components 30
- 4.1.1 Configuration Tools and Files 32

## Extracted text (beginning of document)

_Showing first 12000 of ~58327 extracted characters across 52 pages._

```text
User Manual 
Startup with PSA
A Step by Step Introduction
Version 1.0.0 
English 
 

 
 
 
 
Manual History 
Author Date Version Details 
Klaus Emmert 
Manuela Scheufele 
2009-07-24 0.1 Creation 
Klaus Emmert 
Manuela Scheufele 
2009-10-01 1.0.0 Released 
 
 
Reference Documents 
No. Source Title Version 
 
 
 
Impressum 
 
Vector Informatik GmbH 
Ingersheimer Straße 24 
D-70499 Stuttgart 
 
 
The information and data given in this user manual can be changed without prior notice. No part of this manual may be reproduced in 
any form or by any means without the written permission of the publisher, regardless of which method or which instruments, electronic 
or mechanical, are used. All technical information, drafts, etc. are liable to law of copyright protection. 
 © Copyright 2009, Vector Informatik GmbH 
All rights reserved. 

User Manual Startup with PSA Manual Information 
© Vector Informatik GmbH Version 1.0.0 - 3 - 
Inhaltsverzeichnis 
1 Manual Information 5 
1.1 About this user manual 6 
1.1.1 Certification 7 
1.1.2 Warranty 7 
1.1.3 Registered trademarks 7 
1.1.4 Errata Sheet of manufacturers 7 
2 Getting Started 8 
2.1 How to use this Manual 9 
2.2 Start immediately or need Basic Information? 9 
3 A few STEPS to Basic ECU with PSA CANbedded 10 
3.1 STEP What do you need before start? 11 
3.2 STEP Installation 11 
3.2.1 BSW folder 12 
3.2.2 Installation GENy Framework 12 
3.3 STEP Configuration Tool and DBC File 13 
3.3.1 Start GENy with a Link or a Batch File 13 
3.3.2 Preparations in GENy 14 
3.3.3 Settings for the CANbedded Software Components 18 
3.4 STEP Generate Files 23 
3.5 STEP Add CANbedded to Your Project 24 
3.6 STEP Adapt your Application Files 24 
3.6.1 Including, Initialization and Cyclic Calls 25 
3.6.2 Application Handling of User Requests and the Bus Communication 25 
3.6.3 CANbedded Software Component Callback Functions 26 
3.7 STEP Compile and Link your Project 27 
3.8 STEP Test it via CANoe 27 
3.9 STEP Test and Release Hints 28 
4 Basic Information 29 
4.1 Documentation Structure for CANbedded Components 30 
4.1.1 Configuration Tools and Files 32 
4.2 An Overall View 34 
4.3 An ECU – a More Detailed View 35 
4.3.1 Generic Usage of CANbedded Software Components 35 
4.3.2 Independent Software Components in an ECU 36 
4.3.3 Requesting and Releasing Bus Communication 36 
4.3.4 Multiple Channel ECU 36 
4.3.5 Availability and Usage of XCP within the CANbedded Stack 37 
4.3.6 Start-up Time of the CANbedded Stack 37 
4.3.7 Resources of the CANbedded Stack 37 
5 Further Offers 38 
5.1 Hotline 39 
5.2 Training Classes 39 

Manual Information User Manual Startup with PSA 
- 4 - Version 1.0.0 © Vector Informatik GmbH 
5.3 Integration Support 39 
5.4 Integration Review 39 
6 Additional Information 40 
6.1 Persistors 41 
6.1.1 Update Persistors – Install current Version 42 
7 FAQs 45 
7.1 Introduction 46 
7.2 Frequently Asked Questions 46 
8 Address table 47 
9 Glossar y 49 
10 Index 50 
 

User Manual Startup with PSA Manual Information 
© Vector Informatik GmbH Version 1.0.0 - 5 - 
1 Manual Information 
In this chapter you find the following information: 
1.1 About this user manual page 6
 Certification 
 Warranty 
 Registered trademarks 
 Errata Sheet of manufacturers 
 

Manual Information User Manual Startup with PSA 
- 6 - Version 1.0.0 © Vector Informatik GmbH 
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
 

User Manual Startup with PSA Manual Information 
© Vector Informatik GmbH Version 1.0.0 - 7 - 
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
 
 
 
 

Getting Started User Manual Startup with PSA 
- 8 - Version 1.0.0 © Vector Informatik GmbH 
2 Getting Started 
In this chapter you find the following information: 
2.1 How to use this Manual page 9
2.2 Start immediately or need Basic Information? page 9
 

User Manual Startup with PSA Getting Started 
© Vector Informatik GmbH Version 1.0.0 - 9 - 
2.1 How to use this Manual 
Step by Step Just follow the description step by step. 
 
Basic Information To find basic information about CANbedded (see section Basic Information on page 
29). 
 
FAQ To find answers to 
special questions without reading the whole document use the 
FAQ list (see section FAQs on page 45). 
 
2.2 Start immediately or need Basic Information? 
You are Novice or 
Expert? 
This User Manual is designed to fit the needs and expectations of the developers of 
the ECUs. Of course there are differences in planning the software architecture. But 
the core is almost the same for all types of ECUs. 
Your aim is to implement the CANbedded software components as fast as possible. 
Perhaps you already know the basic concepts of CANbedded? 
Then let’s start with the step-by-step introduction in how to startup with PSA 
CANbedded software components regardless of the ECU type. You will find remarks 
if the handling differs for a specific ECU type. 
For more basic information about CANbedded refer to (see section Basic Information 
on pag
e 29). 
 
 

A few STEPS to Basic ECU with PSA CANbedded User Manual Startup with PSA 
- 10 - Version 1.0.0 © Vector Informatik GmbH 
3 A few STEPS to Basic ECU with PSA CANbedded 
In this chapter you find the following information: 
3.1 STEP What do you need before start? page 11
3.2 STEP Installation page 11
 BSW folder 
 Installation GENy Framework 
3.3 STEP Configuration Tool and DBC File page 13
 Start GENy with a Link or a Batch File 
 Preparations in GENy 
 Settings for the CANbedded Software Components 
3.4 STEP Generate Files page 23
3.5 STEP Add CANbedded to Your Project page 24
3.6 STEP Adapt your Application Files page 24
 Including, Initialization and Cyclic Calls 
 Application Handling of User Re quests and the Bus Communication 
 CANbedded Software Component Callback Functions 
3.7 STEP Compile and Link your Project page 27
3.8 STEP Test it via CANoe page 27
3.9 STEP Test and Release Hints page 28
 
 

User Manual Startup with PSA A few STEPS to Basic ECU with PSA CANbedded 
© Vector Informatik GmbH Version 1.0.0 - 11 - 
3.1 STEP W hat do you need before start? 
CANbedded Did you get the CANbedded delivery? 
 
3.2 STEP Installation 
 
The following list shows the tools and software (C Code or Library) that are included 
in the CANbedded delivery and what has to be installed further on. 
 ¼ Vector CANbedded SIP CBDxxxxxxx Rxx <name>_Setup.exe 
BSW modules, exact content depends on your delivery, the details are outlined in 
the following illustration. 
¼ GENyFramework_<version>-PGP-sda.exe 
downloaded from the FTP server. The framework of the configuration tool GENy. 
 
Your Delivery from 
Vector 
Unpack the Delivery 
Start the Setup.exe and follow the installation dialogs. 
 
 
Situation after 
installation 
Use the Start|Programme|Vector CANbedded …| to find the installation. 
 
Try to keep a proper 
file structure to keep 
the overall view 
throughout the 
complete 
development process 
 
 
 
Example File 
Structure after 
Installation 
You will find the software components in the following file structure or in a similar one.
 
 

A few STEPS to Basic ECU with PSA CANbedded User Manual Startup with PSA 
- 12 - Version 1.0.0 © Vector Informatik GmbH 
 
Info: It is up to you to use a different file structure. This is merely a recommendation 
and the result of the installation process. 
3.2.1 BSW folder 
 You will find the following files in the BSW folder: 
 
CAN Driver CAN - CAN Driver 
can_drv.c – can_def.h – can_inc.h – cancel_in_hw_user_cfg.cfg 
(delete underscore for usage) 
 
 
Info: Dependent on the CAN Driver there could be additional files. 
 
Network 
Management 
NM – Network Management 
Generic_precopy.c – INM_Osek.c – INM_Osek.h – Stat_Mgr.c – Stat_Mgr.h 
 
Interaction Layer IL - Interaction Layer 
il.c – il_def.h – il_inc.h 
 
Transport Protocol TP – ISO Transport Protocol 
tpmc.c – tpmc.h 
 
Diagnostics Layer Diag - Diagnostics Layer CANdesc 
The files will be generated completely 
 
Communication 
Control Layer 
 
CCL - Communication Control Layer 
ccl.c – ccl.h – ccl_inc.h 
 
_Common v_def.h – v_ver.h – sip_vers.c – sip_vers.h – vstdlib.c – vstdlib.h 
 
 
Info: The SIP check ensures that all used CANbedded components fit together. If not, 
a pre-processor error will occur. Please make sure that the SIP check file is complied 
with your application. 
 
Universal 
Measurement and 
Calibration Protocol 
XCP - Universal Measurement and Calibration Protocol 
_xcp_appl.c - _xcp_appl.c - xcp_can.h - XcpProf.c - XcpProf.h 
 
3.2.2 Installation GENy Framework 
Ins

... [truncated — 46327 further characters not shown; see the original PDF] ...
```

## Original file

- Repository path: `/Doc/UserManuals/Startup_PSA_CANbedded.pdf`

[Back to top](#_top)
