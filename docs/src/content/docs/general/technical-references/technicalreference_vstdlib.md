---
title: "Technical Reference: VStdLib"
description: "Converted Vector delivery document — searchable text extraction; the original PDF/HTML remains authoritative."
---
<!-- markdownlint-disable MD009 MD012 MD030 MD046 -->

> **Source:** `/Doc/TechnicalReferences/TechnicalReference_VStdLib.pdf` — Vector-proprietary PDF, converted automatically to Markdown for browsing.  
> Text was extracted with `pypdf`; headings/lists/tables/images are **not** faithfully preserved. 
> The PDF itself remains the authoritative document.

## Document information

- **Group:** VStdLib module
- **Pages:** 21
- **PDF Title:** VStdLib Technical Reference
- **Author(s):** Patrick Markl
- **Subject:** 
- **Version:** 
- **Category:** 
- **Company:** 
- **Comments:** 

## PDF bookmarks (outline)

- 1 Document Information
-   1.1 History
- 2 Introduction
- 3 Functional Description
- 4 Integration
-   4.1 CANbedded Particularities
-   4.2 MICROSAR Particularities
-   4.3 Mixing VStdLib Versions
- 5 Configuration
-   5.1 Usage with OSEK OS
-   5.2 Usage with QNX OS
- 6 API Description
-   6.1 Initialization
-   6.2  Interrupt Control
-   6.3 Memory Functions
-   6.4 Callback Functions
- 7 Assertions
- 8 Limitations
-   8.1 Interrupt control does not work correctly in user mode
- 9 Glossary and Abbreviations
-   9.1 Glossary
-   9.2 Abbreviations
- 10 Contact

## Detected section headings (heuristic)

- 1 Document Information
- 1.1 History
- 2 Introduction
- 3 Functional Description
- 4 Integration
- 4.1 CANbedded Particularities
- 4.2 MICROSAR Particularities
- 4.3 Mixing VStdLib Versions
- 5 Configuration
- 5.1 Usage with OSEK OS
- 5.2 Usage with QNX OS
- 6 API Description
- 6.1 Initialization
- 6.2 Interrupt Control
- 6.3 Memory Functions
- 6.4 Callback Functions
- 7 Assertions
- 8 Limitations
- 8.1 Interrupt control does not work correctly in user mode
- 9 Glossary and Abbreviations
- 9.1 Glossary
- 9.2 Abbreviations
- 10 Contact

## Extracted text (beginning of document)

_Showing first 12000 of ~25945 extracted characters across 21 pages._

```text
VStdLib 
Technical Reference 
 
Vector Standard Library 
Version 1.6.2 
 
 
 
 
 
 
 
 
 
 
 
Authors Patrick Markl, Timo Vanoni 
Status Released 
 
 
 
 
 

Technical Reference VStdLib 
2013, Vector Informatik GmbH Version: 1.6.2 
based on template version 3.7 
2 / 21 
1 Document Information 
1.1 History 
Author Date Version Remarks 
Patrick Markl 2008-02-06 1.0 Creation, merge from Application Note 
Patrick Markl 2008-10-31 1.3 Fixed document version 
Patrick Markl 2008-11-07 1.4 Added information about mixed VStdLib versions 
Patrick Markl 2009-07-02 1.5 Updated assertion codes 
Added chapter about QNX OS 
Patrick Markl 2009-10-16 1.6 Described inclusion of OSEK OS header file 
Timo Vanoni 2013-05-10 1.6.2 ESCAN00067020: The interrupt lock functions 
do not work correctly for the user mode at 
specific controller 
Table 1-1 History of the Document 
 
 
 
 
 
 
Please note 
We have configured the programs in accordance with your specifications in the 
questionnaire. Whereas the programs do support other configurations than the one 
specified in your questionnaire, Vector’s release of the programs delivered to your 
company is expressly restricted to the configuration you have specified in the 
questionnaire. 

Technical Reference VStdLib 
2013, Vector Informatik GmbH Version: 1.6.2 
based on template version 3.7 
3 / 21 
Contents 
1 Document Information ................................ ................................ ................................ . 2 
1.1 History ................................ ................................ ................................ ............... 2 
2 Introduction................................ ................................ ................................ ................... 5 
3 Functional Description ................................ ................................ ................................ . 6 
4 Integration ................................ ................................ ................................ ..................... 8 
4.1 CANbedded Particularities ................................ ................................ ................. 8 
4.2 MICROSAR Particularities ................................ ................................ ................. 8 
4.3 Mixing VStdLib Versions ................................ ................................ .................... 8 
5 Configuration ................................ ................................ ................................ ................ 9 
5.1 Usage with OSEK OS ................................ ................................ ...................... 11 
5.2 Usage with QNX OS ................................ ................................ ........................ 11 
6 API Description ................................ ................................ ................................ ........... 13 
6.1 Initialization ................................ ................................ ................................ ...... 13 
6.2 Interrupt Control ................................ ................................ ............................... 14 
6.3 Memory Functions ................................ ................................ ........................... 15 
6.4 Callback Functions ................................ ................................ ........................... 17 
7 Assertions ................................ ................................ ................................ ................... 18 
8 Limitations ................................ ................................ ................................ .................. 19 
8.1 Interrupt control does not work correctly in user mode ................................ ..... 19 
9 Glossary and Abbreviations ................................ ................................ ...................... 20 
9.1 Glossary ................................ ................................ ................................ .......... 20 
9.2 Abbreviations ................................ ................................ ................................ ... 20 
10 Contact ................................ ................................ ................................ ........................ 21 
 

Technical Reference VStdLib 
2013, Vector Informatik GmbH Version: 1.6.2 
based on template version 3.7 
4 / 21 
Illustrations 
Figure 5-1 VStdLib configuration dialog in GENy ................................ ......................... 9 
Figure 5-2 VStdLib configuration dialog in CANGen ................................ .................... 9 
Figure 5-3 Locking configuration in case CAN events are handled in an interrupt 
thread ................................ ................................ ................................ ....... 11 
Figure 5-4 Configuration of the VStdLib in case of handling CAN events on interrupt 
level ................................ ................................ ................................ .......... 12 
 
Tables 
Table 1-1 History of the Document ................................ ................................ ............. 2 
 

Technical Reference VStdLib 
2013, Vector Informatik GmbH Version: 1.6.2 
based on template version 3.7 
5 / 21 
2 Introduction 
The basic idea of the VStdLib is to provide standard functionality to different Vector 
components. This includes memory copy and i nterrupt locking functions. The VStdLib is 
also a means to provide special memory copy functions , which are not available by 
compiler libraries to the communication components. 
The VStdLib is designed to be used by Vector communication components only. So the 
customer integrating the communication stack will probably not notice the VStdLib at all. 
The VStdLib is highly hardware specific. This means some functions are only available on 
certain platforms. This includes special copy functions for far, near or huge memory. A 
hardware specific VStdLib does not necessarily implement all possible copy function for 
the corresponding hardware platform , but only the functions required by the Vector 
software components. 
The VStdLib also provides interrupt lock functions. This feature depends on the 
CANbedded CAN driver’s Reference Implementation (RI). The RI defines a certain feature 
set to be supported by the CAN driver. CAN drivers which implement RI1.5 and higher do 
not provide an interrupt locking mechanism as previously implementations did 
(CanGlobalInterruptDisable/CanGlobalInterruptRestore). These driver require a VStdLi b to 
provide this functionality, although the API CanGlobalInterruptDisable and 
CanGlobalInterruptRestore remains for compatibility. Please refer to the CANbedded CAN 
driver technical reference for more information about your specific CAN driver. 
 
 
 

Technical Reference VStdLib 
2013, Vector Informatik GmbH Version: 1.6.2 
based on template version 3.7 
6 / 21 
3 Functional Description 
The VStdLib provides basically two main functionalities to Vector communication stack 
components. 
> Functions to copy memory 
> Functions to lock/unlock interrupts 
Interrupt locking functionality is required for CAN drivers with a reference implementation 
1.5 or higher or MICROSAR stacks. Functions to copy memory are always provided. The 
following table describes the API of the VStdLib which is used internally. 
 
API Function Description 
VStdMemSet Initializes default RAM memory to a certain 
character. 
VStdMemNearSet Initializes near RAM memory to a certain character. 
VStdMemFarSet Initializes far RAM memory to a certain character. 
VStdMemClr Clears default RAM to zero. 
VStdMemNearClr Clears near RAM to zero. 
VStdMemFarClr Clears far RAM to zero. 
VStdMemCpyRamToRam Copies default RAM to default RAM. 
VStdMemCpyRomToRam Copies default ROM to default RAM. 
VStdMemCpyRamToNearRam Copies default RAM to near RAM. 
VStdMemCpyRomToNearRam Copies default ROM to near RAM. 
VStdMemCpyRamToFarRam Copies default RAM to far RAM. 
VStdMemCpyRomToFarRam Copies default ROM to far RAM. 
VStdMemCpy16RamToRam Copies default RAM to default RAM. The copying is 
performed 16 bit wise. 
VStdMemCpy16RamToFarRam Copies default RAM to far RAM. The copying is 
performed 16 bit wise. 
VStdMemCpy16FarRamToRam Copies far RAM to default RAM. The copying is 
performed 16 bit wise. 
VStdMemCpy32RamToRam Copies default RAM to default RAM. The copying is 
performed 32 bit wise. 
VStdMemCpy32RamToFarRam Copies default RAM to far RAM. The copying is 
performed 32 bit wise. 
VStdMemCpy32FarRamToRam Copies far RAM to default RAM. The copying is 
performed 32 bit wise. 
 
 
 

Technical Reference VStdLib 
2013, Vector Informatik GmbH Version: 1.6.2 
based on template version 3.7 
7 / 21 
 
 
 
 
Info 
The API functions described in the following table contain “near” and “far” as parts of 
the API names. The meaning of near and far depends on the platform and the functions 
are not necessarily implemented to work on near or far memory. 
The wording “default RAM” or “default ROM” means RAM or ROM data which is not 
explicitly declared to be near or far. These data inherit the current compiler memory 
model settings. 
 
 
 
Caution 
One cannot be sure that a far to near copy routine (for instance) implements really a 
copying from far to near. This depends on the platform and the supported memory 
models of the communication stack! 

Technical Reference VStdLib 
2013, Vector Informatik GmbH Version: 1.6.2 
based on template version 3.7 
8 / 21 
4 Integration 
The integration of the VStdLib is straightforward. As the other Vector component s the 
VStdLib is to be configured by means of the configuration tool. The configuration is 
described in the next chapter. Chapter 6 describes some callback functio n which have to 
be implemented by the application depending on the configuration. 
In order to integrate the VStdLib s imply add the file vstdlib.c as the other Vector software 
components to the compile and link list. 
4.1 CANbedded Particularities 
If the VStdLib is integrated as part of a CANbedded stack the initialization of the VStdLib is 
performed by the CAN or LIN driver automatically. 
4.2 MICROSAR Particularities 
If a MICROSAR stack is integrated the VStdLib is not initialized by any of the software 
components. The application has to take care that the VStdLib’s initialization function is 
called before any other MICROSAR API function is called. The following code example 
shows how to initialize the VStdLib. 
 
void InitRoutine(void) 
{ 
 ... 
 
 /* Initialize the VstLib */ 
 VStdInitPowerOn(); 
 
 /* Perform initialization of the other software components */ 
 ... 
 
} 
 
4.3 Mixing VStdLib Versions 
If you receive different software component packages from Vector, it is possible that these 
packages con tain different VStdLib versions. A general rule is to use the VStdLib which 
was received with the CAN driver package. In case you encounter any incompatibilities or 
have questions, please contact the Vector support. 
 

Technical Reference VStdLib 
2013, Vector Informatik GmbH Version: 1.6.2 
based on template version 3.7 
9 / 21 
5 Configuration 
It depends on the used co mmunication software if the VStdLib has configurable options . 
The configuration tool provides options for the VStdLib if (as previously described) the 
used CAN driver has RI1.5 or higher or a MICROSAR stack is used. 
The VStdLib is configured by means of t he configuration tool. CANGen provides an own 
dialog named VStdLib to configure this component. In GENy these configuration options 
are found in the hardware options dialog. The following two pictures show the 
configuration dialogs in both tools. The first picture shows the dialog in GENy. 
 
 
Figure 5-1 VStdLib configuration dialog in GENy 
 
The next picture shows the configuration dialog of the VStdLib in the CANGen tool. 
 
 
Figure 5-2 VStdLib configuration dialog in CANGen 

Technical Reference VStdLib 
2013, Vector Informatik GmbH Version:

... [truncated — 13945 further characters not shown; see the original PDF] ...
```

## Original file

- Repository path: `/Doc/TechnicalReferences/TechnicalReference_VStdLib.pdf`

[Back to top](#_top)
