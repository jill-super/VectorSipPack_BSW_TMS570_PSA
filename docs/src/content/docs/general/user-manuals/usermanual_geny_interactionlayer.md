---
title: "User Manual Interaction Layer with GENy"
description: "Converted Vector delivery document — searchable text extraction; the original PDF/HTML remains authoritative."
---
<!-- markdownlint-disable MD009 MD012 MD030 MD046 -->

> **Source:** `/Doc/UserManuals/UserManual_GENy_InteractionLayer.pdf` — Vector-proprietary PDF, converted automatically to Markdown for browsing.  
> Text was extracted with `pypdf`; headings/lists/tables/images are **not** faithfully preserved. 
> The PDF itself remains the authoritative document.

## Document information

- **Group:** User Manuals
- **Pages:** 35
- **PDF Title:** Microsoft Word - UserManual_GENy_InteractionLayer.doc
- **Author(s):** visms
- **Subject:** 
- **Version:** 
- **Category:** 
- **Company:** 
- **Comments:** 

## Detected section headings (heuristic)

- 1.4 Additional Documents dealing with the Interaction Layer ................... 7
- 3.3.3 Generation Process with CANbedded Software Component ........... 12
- 4.1.2 Generated files that must not be changed, too................................. 15
- 5.2 STEP 2 Configuration Tool and DBC File ....................................... 20
- 5.2.1 Working with the Configuration Tool GENy...................................... 21
- 6.3 Where to get the generated names for the macros and
- 1 Welcome to the Interaction Layer User Manual
- 1.1 Beginners with the Interaction Layer start here ?
- 1.2 For Advanced Users
- 7 Steps for Interaction Layer integration.
- 1.3 Special topics
- 1.4 Additional Documents dealing with the Interacti on Layer
- 2 About This Document
- 2.1 How This Documentation Is Set-Up
- 2.2 Legend and Explanation of Symbols
- 3 Interaction Layer – An Overall View
- 3.1 Transmission problems
- 3.1.1 What is left to do for transmission
- 3.2 Reception problems
- 3.2.1 What is left to do for Reception
- 3.3 Tools And Files
- 3.3.1 The data base file (DBC file)
- 3.3.2 Configuration Tool
- 3.3.3 Generation Process with CANbedded Software Co mponent
- 3.4 What Is the Vector Interaction Layer
- 3.5 What The Interaction Layer Does
- 4 This Component – A More Detailed View
- 4.1 Files to form the Interaction Layer
- 4.1.1 Fix files that form the Interaction Layer
- 4.1.2 Generated files that must not be changed, too

## Extracted text (beginning of document)

_Showing first 12000 of ~41640 extracted characters across 35 pages._

```text
Vector Informatik GmbH, Ingerheimer Str. 24, 70499 Stuttgart 
Tel. 0711/80670-0, Fax 0711/80670-399, Email [email redacted] 
Internet http:\\www.vector-informatik.de 
 
 
 
 
 
 
 
 
 
 
 
Interaction Layer 
with GENy 
User Manual 
(Your First Steps) 
 
 
Version 1.03.01 
 
 
 
 
 
 
 

User Manual Interaction Layer 
 2007, Vector Informatik GmbH Version: 1.03.01 
 based on template version 1.8 
1 / 35 
 
 
 
 
 
 
 
Authors: Klaus Emmert 
Version: 1.03.01 
Status: released (in preparation/completed/inspected/released) 
 
 

User Manual Interaction Layer 
 2007, Vector Informatik GmbH Version: 1.03.01 
 based on template version 1.8 
2 / 35 
History 
Author Date Version Remarks 
Klaus Emmert 2004-04-29 1.00 Converted from Version 0.8 to 
new User Manual Layout. 
Klaus Emmert 2004-05-17 1.1 Usage of vstdlib added (started with 
IL version 1.83) 
Klaus Emmert 2005-06-24 1.02 GENy added as new 
Configuration Tool. 
Gunnar Meiss 2007-05-16 1.03 ESCAN00020395 
Gunnar Meiss 2007-07-12 1.03.01 ESCAN00021408 Update 
Contents 
 

User Manual Interaction Layer 
 2007, Vector Informatik GmbH Version: 1.03.01 
 based on template version 1.8 
3 / 35 
Motivation For This Work 
What is a signal? 
A Signal is an abstract container for information. It can hold physical values, states 
or commandos. Signals can concern the complete vehi cle or only some control 
units. 
Using the Interaction Layer you do not have to take care about the transmission or 
reception of signal or the data consistency. If you need the content of a signal, just 
read it, if a value changed, just write it. All the rest is done by the Interaction Layer. 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
WARNING 
All application code in any of the Vector User Manu als is for training 
purposes only. They are slightly tested and designed to understand the basic 
idea of using a certain component or a set of components. 
 

User Manual Interaction Layer 
 2007, Vector Informatik GmbH Version: 1.03.01 
 based on template version 1.8 
4 / 35 
Contents 
1 Welcome to the Interaction Layer User Manual............................................. 7 
1.1 Beginners with the Interaction Layer start here?................................ 7 
1.2 For Advanced Users................................. ......................................... 7 
1.3 Special topics .................................................................................... 7 
1.4 Additional Documents dealing with the Interaction Layer ................... 7 
2 About This Document ................................................................................... .. 8 
2.1 How This Documentation Is Set-Up ................................................... 8 
2.2 Legend and Explanation of Symbols.................................................. 9 
3 Interaction Layer – An Overall View ............................................................. 10 
3.1 Transmission problems.............................. ...................................... 10 
3.1.1 What is left to do for transmission................ .................................... 10 
3.2 Reception problems................................. ........................................ 11 
3.2.1 What is left to do for Reception................... ..................................... 11 
3.3 Tools And Files.................................... ............................................ 11 
3.3.1 The data base file (DBC file)...................... ...................................... 11 
3.3.2 Configuration Tool ........................................................................... 12 
3.3.3 Generation Process with CANbedded Software Component ........... 12 
3.4 What Is the Vector Interaction Layer................................................ 14 
3.5 What The Interaction Layer Does .................................................... 14 
4 This Component – A More Detailed View..................................................... 15 
4.1 Files to form the Interaction Layer.................................................... 15 
4.1.1 Fix files that form the Interaction Layer ............................................ 15 
4.1.2 Generated files that must not be changed, too................................. 15 
4.1.2.1 Configuration Tool GENy............................ ..................................... 15 
4.1.3 Configurable files................................. ............................................ 15 
4.1.4 il.c............................................... ................................................... .. 15 
4.1.5 il_def. h.......................................... .................................................. 15 
4.1.6 Il_par.c........................................... .................................................. 15 
4.1.7 il_par.h........................................... .................................................. 15 
4.1.8 il_cfg.h........................................... .................................................. 16 
4.1.9 il_inc.h ............................................................................................. 16 
4.1.9.1 Vstdlib.c / vstdlib.h.............................. ............................................. 16 
4.1.10 Includes when using GENy........................... ................................... 16 
4.2 Handling of the Interaction Layer ..................................................... 16 
5 A Basically Running Interaction Layer In 7 Steps....................................... 18 

User Manual Interaction Layer 
 2007, Vector Informatik GmbH Version: 1.03.01 
 based on template version 1.8 
5 / 35 
5.1 STEP 1 Unpack the delivery ........................................................... 19 
5.2 STEP 2 Configuration Tool and DBC File ....................................... 20 
5.2.1 Working with the Configuration Tool GENy...................................... 21 
5.2.1.1 Project Setup in GENy.............................. ....................................... 21 
5.2.1.2 Interaction Layer Settings in GENy................. ................................. 21 
5.3 STEP 3 Generate Files............................. ...................................... 23 
5.4 STEP 4 Add Files to Your Application............................................. 24 
5.4.1 Using GENy......................................... ............................................ 24 
5.5 STEP 5 Adaptations For Your Application ....................................... 25 
5.6 STEP 6 Compile And Link ............................................................... 28 
5.7 STEP 7 Test the Software Component ............................................ 28 
5.7.1 Built-up of the test environment ....................................................... 28 
5.7.2 Test of Interaction Layer .................................................................. 29 
6 Further Information ................................................................................... .... 31 
6.1 States of the Interaction Layer ......................................................... 31 
6.2 Debugging of Interaction Layer..................... ................................... 31 
6.3 Where to get the generated names for the macros and 
functions.......................................... ................................................ 32 
6.4 Usage of flags and functions............................................................ 32 
6.5 Data Consistency ............................................................................ 33 
7 Index.............................................. ................................................... ................ 1 
 

User Manual Interaction Layer 
 2007, Vector Informatik GmbH Version: 1.03.01 
 based on template version 1.8 
6 / 35 
Illustrations 
Figure 3-1 Transmission Problems ............................................................................ 10 
Figure 3-2 Reception Problems ................................................................................. 11 
Figure 3-3 Generation Process For Vector CANbedded Software Components ........ 13 
Figure 3-4 Overview CAN Driver, Interaction Layer and Application .......................... 14 
Figure 4-1 Including Vector Interaction Layer ............................................................ 16 
Figure 5-1 Generation Information............................. ................................................ 23 
Figure 5-2 The test environment............................... ................................................. 28 
Figure 5-3 How to get an data base into CANoe........................................................ 29 
Figure 5-4 Configure menu and Real adjustment....................................................... 29 
Figure 5-5 A trace of the example application with timeout occurring......................... 29 
Figure 5-6 Insert a generator block to send the message 201 all 10ms ..................... 30 
Figure 5-7 A trace without timeout ............................................................................. 30 
Figure 6-1 The State machine of the Interaction Layer .............................................. 31 
Figure 6-2 Debug options for Interaction Layer.......................................................... 31 
 

User Manual Interaction Layer 
 2007, Vector Informatik GmbH Version: 1.03.01 
 based on template version 1.8 
7 / 35 
Cha pter 2 
Chapter 3.4 
Chapter 4 
Chapter 5 
Chapter 6.1 
Chapter 6.3 
Chapter 0 
1 Welcome to the Interaction Layer User Manual 
1.1 Beginners with the Interaction Layer start here ? 
You need some information about this document? 
What is the Interaction Layer ? 
 
 
 
1.2 For Advanced Users 
Start reading here . 
7 Steps for Interaction Layer integration. 
 
 
 
1.3 Special topics 
States of the Interaction Layer 
Generated Names for macros and functions ? 
Flags and Functions 
 
 
 
1.4 Additional Documents dealing with the Interacti on Layer 
TechnicalReference_InteractionLayer 
OEM-specific Documentation 

User Manual Interaction Layer 
 2007, Vector Informatik GmbH Version: 1.03.01 
 based on template version 1.8 
8 / 35 
2 About This Document 
This document gives you an understanding of the Int eraction Layer. You will 
receive general information, a step-by-step tutoria l to get the Interaction Layer 
running and to use its functionalities. 
2.1 How This Documentation Is Set-Up 
Chapter Content 
Chapter 1 The welcome page is to navigate in the document. Th e main parts of the document 
can be accessed from here via hyperlinks. 
Chapter 2 It contains some formal information about this docu ment, an explanation of legends 
and symbols. 
Chapter 3 In this chapter you get a brief introduction in this Interaction Layer and its tasks. 
Chapter 4 Here you find some more insight in the Interaction Layer. 
Chapter 5 Here are the 7 Steps for you to integrate the Inter action Layer, how to do the 
necessary settings in the Configuration Tool and ho w to connect the Interaction Layer 
with your application. 
Chapter 6 This chapter provides you with some further information. 
Chapter 7 In this last chapter there is a list of experiences with the Interaction Layer. 
 

User Manual Interaction Layer 
 2007, Vector Informatik GmbH Version: 1.03.01 
 based on template version 1.8 
9 / 35 
These areas 
to the right of 
the text 
contain brief 
items of 
information 
that will 
facilitate your 
search for 
specific 
topics. 
2.2 Legend and Explanation of Symbols 
You find these symbols at the right side of the doc ument. They indicate special 
areas in the text. Here is a list of their meaning. 
Symbol Meaning 
 
The building bricks mark examples. 
 You will find key words and information in short sentences in the margin. This will 
greatly simplify your search for topics. 
 
The footprints will lead you through the steps until you can use the described 
Interaction Layer. 
 
There is something you should 

... [truncated — 29640 further characters not shown; see the original PDF] ...
```

## Original file

- Repository path: `/Doc/UserManuals/UserManual_GENy_InteractionLayer.pdf`

[Back to top](#_top)
