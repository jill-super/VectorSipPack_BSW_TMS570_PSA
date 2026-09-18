---
title: "AN-ISC-8-1067 GenMsgMinAcceptLength with Il_Vector"
description: "Converted Vector delivery document — searchable text extraction; the original PDF/HTML remains authoritative."
---
<!-- markdownlint-disable MD009 MD012 MD030 MD046 -->

> **Source:** `/Doc/ApplicationNotes/AN-ISC-8-1067_GenMsgMinAcceptLength.pdf` — Vector-proprietary PDF, converted automatically to Markdown for browsing.  
> Text was extracted with `pypdf`; headings/lists/tables/images are **not** faithfully preserved. 
> The PDF itself remains the authoritative document.

## Document information

- **Group:** Application Notes
- **Pages:** 5
- **PDF Title:** GenMsgMinAcceptLength with Il_Vector in Geny
- **Author(s):** Meiss, Gunnar
- **Subject:** Application Note  AN-ISC-8-1067
- **Version:** 1.1
- **Category:** Application Note
- **Company:** Vector Informatik GmbH
- **Comments:** This Application Note describes the reception of messages with a DLC smaller or equal than the described DLC in the database with the Il_Vector and the database attribute GenMsgMinAcceptLength.

## Detected section headings (heuristic)

- 1.0 Overview
- 1.1 Database Attributes
- 1.2 Particularities and Limitations
- 1.2.1 Indication Notification
- 1.2.2 Example Without DLC Change
- 1.2.3 Example With DLC Change
- 1.2.4 Data Changed Flags
- 1.2.5 Timeout Flags and Functions
- 1.2.6 Multiplexed Signals
- 2.0 Additional Resources
- 3.0 Contacts
- 70499 Stuttgart
- 39500 Orchard Hill Pl., Ste 550
- 41755 Göteborg
- 168 Boulevard Camélinat
- 92240 Malakoff

## Extracted text (beginning of document)

_Showing first 9069 of ~9069 extracted characters._

```text
GenMsgMinAcceptLength with Il_Vector in Geny 
Version 1.1 
2008-09-09 
Application Note AN-ISC-8-1067 
 
 
 
Author(s) Meiss, Gunnar 
Restrictions Customer confidential - PSA, Renault and Nissan only 
Abstract This Application Note describes the reception of messages with a DLC smaller or equal 
than the described DLC in the database with the Il_Vector and the database attribute 
GenMsgMinAcceptLength. 
 
Table of Contents 
 
 1 
Copyright © 2008 - Vector Informatik GmbH 
Contact Information: www.vector-informatik.com or ++49-711-80 670-0 
1.0 Overview ..........................................................................................................................................................1 
1.1 Database Attributes.......................................................................................................................................1 
1.2 Particularities and Limitations .......................................................................................................................2 
1.2.1 Indication Notification..................................................................................................................................2 
1.2.2 Example Without DLC Change...................................................................................................................2 
1.2.3 Example With DLC Change........................................................................................................................3 
1.2.4 Data Changed Flags...................................................................................................................................4 
1.2.5 Timeout Flags and Functions .....................................................................................................................4 
1.2.6 Multiplexed Signals.....................................................................................................................................4 
2.0 Additional Resources.......................................................................................................................................4 
3.0 Contacts...........................................................................................................................................................5 
 
 
1.0 Overview 
The Specification of PSA defines, that a CAN message has to be accepted by the ECU with different lengths. The 
minimum length can be equal to the DLC of a message defined in the database for an ECU or smaller. 
If a message is received, where the DLC is smaller than defined in the database, the application has to be 
implemented with care according to the rules described in this document. All messages received with a DLC 
smaller than the configured GenMsgMinAcceptLength, the messages are discarded by the ECU, because received 
length is smaller than the minimum expected one. 
1.1 Database Attributes 
The following table describes the properties of the database attribute GenMsgMinAcceptLength. 
Name GenMsgMinAcceptLength 
Description This value defines the minimum acce ptance length in bytes of a CAN message. If no 
value is specified, set the value to the DLC. 
Type Of Object Message 
Value Type Integer 
Default 8 
Minimum 0 
Maximum 8 
Table 1 – Properties of database attribute 

 GenMsgMinAcceptLength with Il_Vector in Geny 
 
 
 
 2 
Application Note AN-ISC-8-1067 
 
1.2 Particularities and Limitations 
1.2.1 Indication Notification 
If the received DLC of a message is greater or equal to the GenMsgMinAcceptLength configured in the database, 
the indication notification (first value flags and indication flags are set and indication functions are called) is 
performed for all signals or signal groups which are entirely contained in the received DLC of the message. If a 
grouped signal is entirely within the received DLC, but the signal group is not within the received DLC, the 
indication notification is not performed. 
Note: The application must check the indication flag or function before the signal value can be read by 
the IlGet<SignalName>() signal access function or macro. If the indication flag is not set or the 
indication function is not called, the application has to use the default value of the signal. 
1.2.2 Example Without DLC Change 
The following code is an example if a message is received with a DLC smaller as defined in the database but the 
DLC does not change during runtime ( GenMsgMinAcceptLength < DLC < DatabaseDLC ). 
The example function is the application task which reads the signals “Speed” and “Rpm” of the message 
“EngineInfo”. 
/* Declare variables for the signal values. */ 
vuint8 ApplicationSpeedVariable; 
vuint8 ApplicationRpmVariable; 
 
void ApplicationTask(void) 
{ 
 if(IlGetSpeedIndication()) 
 { 
 /* Read the received signal value. */ 
 ApplicationSpeedVariable = IlGetRxSpeed(); 
 /* Reset the indication flag. */ 
 IlClrSpeedIndication(); 
 } 
 else 
 { 
 /* 
 The signal has not been received yet. 
 Set the default value, if the default value is not configured. 
 */ 
 ApplicationSpeedVariable = 5; 
 } 
 /* 
 Read the received signal value or the default value, 
 which is configured in the generation tool. 
 */ 
 ApplicationRpmVariable = IlGetRxRpm(); 
} 
 

 GenMsgMinAcceptLength with Il_Vector in Geny 
 
 
 
 3 
Application Note AN-ISC-8-1067 
 
1.2.3 Example With DLC Change 
The following code is an example if a network is used where the DLC of a received messages changes during 
runtime. The example function is the application task which reads the signals “Speed” and “Rpm” of the message 
“EngineInfo”. 
Note: The application has to implement a message based CAN Driver PreCopy function which has to 
clear all signal indication flags of the message and the polling feature of the Il_Vector must be 
activated for this message. The following figure shows the configured attributes in GENy. 
 
 
Figure 1 – Rx Messages of GENy 
 
/* Declare variables for the signal values. */ 
vuint8 ApplicationSpeedVariable; 
vuint8 ApplicationRpmVariable; 
 
void ApplicationTask(void) 
{ 
 if(IlGetSpeedIndication()) 
 { 
 /* Read the received signal value. */ 
 ApplicationSpeedVariable = IlGetRxSpeed(); 
 /* Reset the indication flag. */ 
 IlClrSpeedIndication(); 
 } 
 else 
 { 
 /* 
 The signal has not been received yet. 
 Set the default value, if the default value is not configured. 
 */ 
 ApplicationSpeedVariable = 5; 
 } 
 /* 
 Read the received signal value or the default value, 
 which is configured in the generation tool. 
 */ 
 ApplicationRpmVariable = IlGetRxRpm(); 
} 
 
 
 
 

 GenMsgMinAcceptLength with Il_Vector in Geny 
 
 
 
 4 
Application Note AN-ISC-8-1067 
 
 
vuint8 EngineInfoPreCopy(CanRxInfoStructPtr rxStruct) 
{ 
 rxStruct = rxStruct; 
 /* 
 Clear all signal indication Flags of the message to guarantee, 
 that only received signals are processed by the application. 
 */ 
 IlClrSpeedIndication(); 
 IlClrRpmIndication(); 
 return kCanCopyData; 
} 
 
1.2.4 Data Changed Flags 
The “Data Changed Flag” of a rx signal is only valid, if the indication flag is set or the signal indication function is 
called previously. 
Note: Indication Flags have to be cleared by the applic ation, or use the IlGetClr macros to get and clear 
the indication flags. 
1.2.5 Timeout Flags and Functions 
Message is never received after IlRxStart 
Timeout flags are set and timeout functions are called for all signals in the message if the timeout is elapsed. 
Message is received minimum once after IlRxStart 
Timeout flags are set and timeout functions are called for all signals in the message, which are received with a 
DLC greater than GenMsgMinAcceptLength, but smaller than the Size of the receive buffer. 
1.2.6 Multiplexed Signals 
The database attribute GenMsgMinAcceptLength must not be used with messages containing multiplexed signals. 
2.0 Additional Resources 
See additional in the Technical Reference of the Il_Vector. 

 GenMsgMinAcceptLength with Il_Vector in Geny 
 
 
 
 5 
Application Note AN-ISC-8-1067 
 
3.0 Contacts 
 
Vector Informatik GmbH 
Ingersheimer Straße 24 
70499 Stuttgart 
Germany 
Tel.: +49 711-80670-0 
Fax: +49 711-80670-111 
Email: [email redacted] 
 
 
Vector CANtech, Inc. 
39500 Orchard Hill Pl., Ste 550 
Novi, MI 48375 
USA 
Tel: +1-248-449-9290 
Fax: +1-248-449-9704 
Email: [email redacted] 
 
VecScan AB 
Theres Svenssons Gata 9 
41755 Göteborg 
Sweden 
Tel: +46 (0)31 764 76 00 
Fax: +46 (0)31 764 76 19 
Email: [email redacted] 
Vector France SAS 
168 Boulevard Camélinat 
92240 Malakoff 
France 
Tel: +33 (0)1 42 31 40 00 
Fax: +33 (0)1 42 31 40 09 
Email: [email redacted] 
 
Vector Japan Co. Ltd. 
Seafort Square Center Bld. 18F 
2-3-12, Higashi-shinagawa, 
Shinagawa-ku 
Tokyo 140-0002 
Japan 
Tel.: +81 3 5769 7800 
Fax: +81 3 5769 6975 
Email: [email redacted] 
Vector Korea IT Inc. 
Daerung Post Tower III, 508 
182-4 Guro-dong, Guro-gu 
Seoul, 152-790 
Republic of Korea 
Tel.: +82-2-2028-0600 
Fax: +82-2-2028-0604 
Email: [email redacted]
```

## Original file

- Repository path: `/Doc/ApplicationNotes/AN-ISC-8-1067_GenMsgMinAcceptLength.pdf`

[Back to top](#_top)
