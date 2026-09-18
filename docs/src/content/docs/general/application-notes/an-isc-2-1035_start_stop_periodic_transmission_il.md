---
title: "AN-ISC-2-1035 Start/Stop Periodic Transmission (IL)"
description: "Converted Vector delivery document — searchable text extraction; the original PDF/HTML remains authoritative."
---
<!-- markdownlint-disable MD009 MD012 MD030 MD046 -->

> **Source:** `/Doc/ApplicationNotes/AN-ISC-2-1035_Start_Stop_Periodic_Transmission_IL.pdf` — Vector-proprietary PDF, converted automatically to Markdown for browsing.  
> Text was extracted with `pypdf`; headings/lists/tables/images are **not** faithfully preserved. 
> The PDF itself remains the authoritative document.

## Document information

- **Group:** Application Notes
- **Pages:** 5
- **PDF Title:** Start Stop Periodic Transmission with IL
- **Author(s):** Gunnar Meiss
- **Subject:** Application Note AN-ISC-2-1035
- **Version:** 1.3
- **Category:** Application Note
- **Company:** Vector Informatik GmbH
- **Comments:** Start and stop a periodical transmission of the Interaction Layer.


## Detected section headings (heuristic)

- 1.0 How to start and stop periodic transmission
- 1.1 Manufacturer, Hardware platform, derivative
- 1.2 Problem Description
- 1.3 Problem Solution
- 1.3.1 Additional Configuration of the Interaction Layer in CANgen
- 1.3.2 Configuration of the Interaction Layer in GENy
- 1.3.3 Additional Functions Provided by the Interaction Layer Kernel
- 2.0 Contacts
- 70499 Stuttgart
- 39500 Orchard Hill Pl., Ste 550
- 168 Boulevard Camélinat
- 92240 Malakoff

## Extracted text (beginning of document)

_Showing first 6798 of ~6798 extracted characters._

```text
Start Stop Periodic Transmission with IL 
Version 1.3 
2007-08-14 
 
Application Note AN-ISC-2-1035 
 
 
 
Author(s) Gunnar Meiss 
Restrictions Restricted membership 
Abstract Start and stop a periodical transmission of the Interaction Layer. 
 
 
Table of Contents 
 
 
 1 
Copyright © 2007 - Vector Informatik GmbH 
Contact Information: www.vector-informatik.com or ++49-711-80 670-0 
 
1.0 How to start and stop periodic transmission....................................................................................................1 
1.1 Manufacturer, Hardware platform, derivative................................................................................................1 
1.2 Problem Description......................................................................................................................................1 
1.3 Problem Solution ...........................................................................................................................................1 
1.3.1 Additional Configuration of the Interaction Layer in CANgen .....................................................................2 
1.3.2 Configuration of the Interaction Layer in GENy ..........................................................................................3 
1.3.3 Additional Functions Provided by the Interaction Layer Kernel..................................................................3 
2.0 Contacts...........................................................................................................................................................5 
 
 
1.0 How to start and stop periodic transmission 
1.1 Manufacturer, Hardware platform, derivative 
There are no dependencies between manufacturer, hardware platform and derivative according to this problem. 
1.2 Problem Description 
After the transmission path of the IL was started ( IlTxStart() ) the transmission of cyclic message takes place. 
Nothing further is needed to be done to keep the transmission running. The cycle time must be pre-configured in 
the network database at compile time. Some applications need to stop and restart the periodic transmission for 
individual messages. 
1.3 Problem Solution 
The periodical transmission can be stopped and restarted by the application optionally. Therefore the Interaction 
Layer provides some additional service functions. The function IlStopCycle(<IlMessageHandle>) stops the periodic 
transmission of a message, the function IlStartCycle(<IlMessageHandle>) restarts the periodic transmission. 
Each call of the function IlTxStart() starts the cyclic transmission. In some cases it might be necessary to avoid the 
cyclic transmission after IlTxStart(). Therefore it is possible to call the function IlStopCycle(<IlMessageHandle>) 
within the callback function ApplIlTxStart(). This disables the cyclic transmission of a message immediately after 
IlTxStart(). In this case the cyclic transmission will not be started for this message. 
 
 
Caution 
This API shall never be performed on Messages containing multiplexed signals. 
 

 Start Stop Periodic Transmission with IL 
 
 
 
 
 2 
Application Note AN-ISC-2-1035 
 
 
 
1.3.1 Additional Configuration of the Interaction Layer in CANgen 
 
Figure 1 - Configuration of the Interaction Layer in the Generation Tool 
 
Figure 1 shows a screen shot of the configuration tool CANgen. Within the tab IL options the Interaction Layer 
could be configured. The relevant option on this tab is shown in the table below. 
Parameter Value Meaning Reference 
Use start/stop 
of periodic 
messages 
On/Off This option is necessary if periodic transmission should 
be stopped and restarted during runtime. 
 
Table 1 – Il options tab 

 Start Stop Periodic Transmission with IL 
 
 
 
 
 3 
Application Note AN-ISC-2-1035 
 
 
1.3.2 Configuration of the Interaction Layer in GENy 
 
Figure 2 – Start/Stop API in GENy 
 
Figure 2 shows a screen shot of the configuration tool GENy. On the configuration view of Il Vector the Interaction 
Layer could be configured. The Start/Stop API is the relevant option you have to activate if periodic transmission 
should be stopped and restarted during runtime. 
1.3.3 Additional Functions Provided by the Interaction Layer Kernel 
Name: IlStartCycle 
Standard 
Prototype: 
void IlStartCycle (IlTransmitHandle ilTxHnd); 
Multi Channel 
Prototype: 
void IlStartCycle_X(IlTransmitHandle ilTxHnd); 
with X = 0... Number of CAN channel 
Indexed 
Prototype: 
void IlStartCycle (IlTransmitHandle ilTxHnd); 
Argument(s): ilTxHandle IL Handle of the mess ages for with the cyclic transmitted 
 should be restarted 
 The generated <IlMessageHandle> shall be used: 
In CANgen (ilpar.h): 
 _ILTx<MessageName> 
In GENy (il_par.h): 
 IlTxMsgHnd<MessageName> 
Return: None 
Description: This function restarts the periodica l transmission of a message and shall be called 
on task level. Due to this that all timing counters are set in the state transition tx start 
the callback function ApplIlTxStart may be used to implement the changed cycle 
time behavior. 
Table 2 – Description of IlStartCycle 
 
Name: IlStopCycle 
Standard 
Prototype: 
void IlStopCycle (IlTransmitHandle ilTxHnd); 

 Start Stop Periodic Transmission with IL 
 
 
 
 
 4 
Application Note AN-ISC-2-1035 
 
 
Multi Channel 
Prototype: 
void IlStopCycle_X(IlTransmitHandle ilTxHnd); 
with X = 0... Number of CAN channel 
Indexed 
Prototype: 
void IlStopCycle (IlTransmitHandle ilTxHnd); 
Argument(s): ilTxHandle IL Handle of the mess ages for with the cyclic transmitted 
 should be stopped 
 The generated <IlMessageHandle> shall used: 
In CANgen (ilpar.h): 
 _ILTx<MessageName> 
In GENy (il_par.h): 
 IlTxMsgHnd<MessageName> 
Return: None 
Description: This function stops the periodica l transmission of a message and shall be called on 
task level. 
Table 3 – Description of IlStopCycle 
 

 Start Stop Periodic Transmission with IL 
 
 
 
 
 5 
Application Note AN-ISC-2-1035 
 
 
2.0 Contacts 
 
 
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
Lindholmspiren 5 
402 78 Göteborg 
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
J-140-0002 Tokyo 
Tel.: +81 3 5769 6970 
Fax: +81 3 5769 6975 
Email: [email redacted]
```

## Original file

- Repository path: `/Doc/ApplicationNotes/AN-ISC-2-1035_Start_Stop_Periodic_Transmission_IL.pdf`

[Back to top](#_top)
