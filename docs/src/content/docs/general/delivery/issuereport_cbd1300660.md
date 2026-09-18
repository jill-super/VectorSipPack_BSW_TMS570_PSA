---
title: "Issue Report CBD1300660"
description: "Converted Vector delivery document — searchable text extraction; the original PDF/HTML remains authoritative."
---
<!-- markdownlint-disable MD009 MD012 MD030 MD046 -->

> **Source:** `/Doc/DeliveryInformation/IssueReport_CBD1300660.pdf` — Vector-proprietary PDF, converted automatically to Markdown for browsing.  
> Text was extracted with `pypdf`; headings/lists/tables/images are **not** faithfully preserved. 
> The PDF itself remains the authoritative document.

## Document information

- **Group:** Delivery
- **Pages:** 46
- **PDF Title:** 
- **Author(s):** 
- **Subject:** 
- **Version:** 
- **Category:** 
- **Company:** 
- **Comments:** 

## PDF bookmarks (outline)

- ESCAN00045854 (An incorrect timeout is issued for Flow Control and Consecutive Frame timing supervis
- ESCAN00055528 (Missing call-context limitation in the description of all DescSetStateXXX API)
- ESCAN00056993 (Busoff event incorrectly also causes wakeup event)
- ESCAN00065128 (CANbedded only: multiplex messages are not received correctly)
- ESCAN00066659 (canbedded only: multiplex messages are not received correctly)
- ESCAN00070923 (Overrun occurs with higher probability)
- ESCAN00024492 (API prototypes for InmNmRxGetCondition are not correct)
- ESCAN00039653 (The interrupt lock functions do not work correctly for the user mode)
- ESCAN00047907 (limitation "InmNmTask" (no interrupt context usage))
- ESCAN00049589 (Compile error: direct signal access feature in CANdesc does not consider far memory p
- ESCAN00053779 (Linker error: CanBaseAddressRequest() and CanBaseAddressActivate() are not available)
- ESCAN00055957 (appdesc.c missing line feed (LF) after carraige return (CR) on some lines)
- ESCAN00056617 (Compile error when compiling CanInterruptDisable(): missing ;)
- ESCAN00059562 (Compile error: Size of array CanRxMsgIndirection is zero if index search and no Rx Fu
- ESCAN00062165 (Compiler error: Interrupt control macros prevent can_drv.c from being compiled in THU
- ESCAN00062316 ([canbedded only] Wrong Rx Data Length of message displayed)
- ESCAN00062872 (the function CanLL_HandleIllIrptNumber didn't clear a illegal interrupt)
- ESCAN00063756 (certain extended IDs may not be received after Full CAN overrun ( if extended ID mask
- ESCAN00070517 (Compiler error: missing constant kDescStateSessionDefault)
- ESCAN00071804 (Functions and flags can be added to a Update Bit signal after an dbc update was perfo
- ESCAN00073608 ("Unknown Service Support" feature in GENy is referenced as "Support Generic User Serv
- ESCAN00022682 (Compiler warning statement not reached in DescUsdtNetIsoTpAssertUser)
- ESCAN00027751 (Compiler warning for cast to smaller type for "failedByteMask")
- ESCAN00033658 (Compiler Warning: W549 condition is always true)
- ESCAN00037685 (Compiler Warning: Possible loss of data)
- ESCAN00038038 (Compiler warning: SP debug info incorrect because of optimization or inline assembler
- ESCAN00044044 (Compiler Warning: condition is always false)
- ESCAN00044161 (Compiler Warning: Unused Static Function *ValueChanged)
- ESCAN00047283 (IL flags are declared without the "volatile" keyword.)
- ESCAN00048020 (Compiler warning: Deprecated use of PSR; flag bits not specified, "cf" assumed)

## Detected section headings (heuristic)

- 1.1 Resolving Issues
- 1.2 Issue Classification
- 2.1 Runtime Issues without Workaround: 0
- 2.2 Runtime Issues with Workaround: 6
- 2.3 Apparent Issues: 15
- 2.4 Compiler Warnings: 17
- 1.1 Resolving Issues
- 1.2 Issue Classification
- 2.1 Runtime Issues without Workaround
- 2.2 Runtime Issues with Workaround
- 2.3 Apparent Issues
- 2.4 Compiler Warnings

## Extracted text (beginning of document)

_Showing first 12000 of ~62189 extracted characters across 46 pages._

```text
Issue Report
1
License Number Customer
CBD1300660 Nexteer Automotive Corporation
Package: CBD Psa SLP4
Micro: 0812BPGEQQ1
Compiler: TexasInstruments 4.9.5
Maintenance Expiry Date
2024-03-18
SIP Delivery Date SIP Version
2014-03-18 05.00.17
SLP Delivery Number
CBD Psa SLP4 D01
Report Creation Date
2014-04-02
Contact
In case of questions or the need for an update of the basic software delivery, please contact 
[email redacted] or your Vector contact person.
Table of Contents
1. Introduction
1.1 Resolving Issues
1.2 Issue Classification
2. New Issues
2.1 Runtime Issues without Workaround: 0
2.2 Runtime Issues with Workaround: 6
2.3 Apparent Issues: 15
2.4 Compiler Warnings: 17
3. New Issues for Information: 0
4. Report Legend
5. Quality Management Contact

Issue Report
2
1. Introduction
1.1 Resolving Issues
Reported issues are not necessarily fixed automatically by the next update delivery. If some of the 
reported issues shall be fixed, please contact Vector to establish an agreement about issues that 
shall be fixed in upcoming deliveries. Please note that Vector may fix additional issues without 
explicit request.
1.2 Issue Classification
This Issue Report provides issues that have been detected since the last report. The issues have 
been classified to facilitate the assessment of their impact:
The chapter 'New Issues' lists issues that have been detected since the last report and which could 
not be excluded based on the use-case defined in the questionnaire. The issues are classified as 
follows:
• Runtime Issues without Workaround: Runtime issues without a workaround require an 
update of the basic software delivery in case the issue affects the ECU overall functionality. 
The effect of an issue to the ECU functionality has to be analyzed by the customer as the basic 
software usage and its configuration is not known by Vector. The risk of change has also to be 
taken into account.
• Runtime Issues with Workaround: It is not recommended to update a delivery due to a 
runtime issue with a documented workaround. The effect of an issue to the ECU functionality 
has to be analyzed by the customer as the basic software usage and its configuration is not 
known by Vector. The risk of change has also to be taken into account.
• Compiler Warnings: As a service we report the known compiler warnings. The occurrence of 
a compiler warning may depend on the used configuration and compiler settings.
• Apparent Issues: Apparent issues are detected immediately when using the basic software. 
If an issue does not show up while working with the basic software the ECU project is not 
affected by the issue. Apparent issues may or may not have workarounds.
The chapter 'New Issues for Information' lists issues that are not relevant for the use case that 
has been documented in the questionnaire provided to Vector. The issues may, however, be 
relevant for other use cases. Additionally, issues that have been accepted or are tolerated by the 
OEM (as defined in the questionnaire) are reported here.

Issue Report
3
2. New Issues
2.1 Runtime Issues without Workaround
The lists contain issues that have been detected since the last report and which could not be 
excluded based on the use-cases defined in the questionnaire (see chapter ‘New Issues for 
Information’).
2.2 Runtime Issues with Workaround
It is not recommended to update a delivery due to a runtime issue with a documented 
workaround. The effect of an issue to the ECU functionality has to be analyzed by the customer as 
the basic software usage and its configuration is not known by Vector. Thereby the risk of change 
has also to be taken into account. 
Index
ESCAN00045854 An incorrect timeout is issued for Flow Control and Consecutive Frame timing 
supervision.
Tp_Iso15765@GenTool_Geny
ESCAN00055528 Missing call-context limitation in the description of all DescSetStateXXX API
Diag_CanDesc__coreBase@Doc_TechRef
ESCAN00056993 Busoff event incorrectly also causes wakeup event
DrvCan_Tms470DcanHll@Implementation
ESCAN00065128 CANbedded only: multiplex messages are not received correctly
GenTool_GenyDriverBase@GenTool_Geny
ESCAN00066659 canbedded only: multiplex messages are not received correctly
Hw__baseCpuCan@GenTool_Geny
ESCAN00070923 Overrun occurs with higher probability
DrvCan_Tms470DcanLl@Implementation

Issue Report
4
ESCAN00045854 An incorrect timeout is issued for Flow Control and 
Consecutive Frame timing supervision.
Component@Subcomponent: Tp_Iso15765@GenTool_Geny
First affected version: 2.00.00
Fixed in versions:
Problem Description:
What happens (symptoms):
-------------------------------------------------------------------
An incorrect timeout is issued for Flow Control (TX) and Consecutive Frame (RX) timing 
supervision in case of large timeouts.
When does this happen:
-------------------------------------------------------------------
During runtime at transmission and/or reception of multi frames.
In which configuration does this happen:
-------------------------------------------------------------------
This can only appear if channel specific timing is activated (#if defined 
TP_CHANNEL_SPECIFIC_TIMING)
AND 
the configured timeout values are greater than 255 "ticks".
Please note that the number of "ticks" is calculated by dividing the configured timeout value by 
the configured periodic cycle time of the TP.
 
Resolution Description:
Workaround:
-------------------------------------------------------------------
Use smaller timeouts or increase the call-cycle of the TP task functions.
Resolution:
-------------------------------------------------------------------
The described issue is corrected by modification of all affected work-products. 

Issue Report
5
ESCAN00055528 Missing call-context limitation in the description of 
all DescSetStateXXX API
Component@Subcomponent: Diag_CanDesc__coreBase@Doc_TechRef
First affected version: 1.00.00
Fixed in versions: 3.06.00
Problem Description:
What happens (symptoms):
-------------------------------------------------------------------
Since the technical reference CANdesc does not restrict the call-context of the "DescSetStateXXX" 
API, the application might call it from interrupt context or a task with higher priority than the 
DescTask.
This might result in undefined run time effects.
When does this happen:
-------------------------------------------------------------------
During diagnostic application integration, when using a "DescSetStateXXX" API.
In which configuration does this happen:
-------------------------------------------------------------------
Any configuration.
 
Resolution Description:
Workaround:
-------------------------------------------------------------------
Do not call any of the "DescSetStateXXX" APIs from interrupt context or a task with higher 
priority than the DescTask.
Resolution:
-------------------------------------------------------------------
Call context has been restricted to a task with priority lower or equal to the DescTask.

Issue Report
6
ESCAN00056993 Busoff event incorrectly also causes wakeup event
Component@Subcomponent: DrvCan_Tms470DcanHll@Implementation
First affected version: 1.00.00
Fixed in versions:
Problem Description:
What happens (symptoms):
-------------------------------------------------------------------
When a busoff event is detected (via either CAN interrupt or polling CanTask), the driver executes 
the code to handle the busoff correctly, but it also incorrectly executes the code to handle a 
wakeup event, even though no wakeup event is pending.
When does this happen:
-------------------------------------------------------------------
On the next busoff event, if the last wakeup event was not immediately followed by at least 11 
recessive bits.
In other words, if the bus is "noisy" when CAN wakes up, the next busoff event will cause the 
driver to execute the wakeup routine again.
In which configuration does this happen:
-------------------------------------------------------------------
Configurations where 'Sleep/Wakeup Functionality' is enabled on the DrvCan_Tms470DcanHll 
page in GENy.
 
Resolution Description:
Workaround:
-------------------------------------------------------------------
If global power down mode is configured: In ApplCanWakeUpFromSleepModeRequest, after 
clearing the appropriate PCR bits as documented in the CAN driver technical reference, the 
application must wait for the 'WakeUp Pnd' bit to clear in the DCAN Error and Status register. For 
example:
 while((*(vuint32 *)0xFFF7DC04 /* DCAN1 Error and Status register */) & (vuint32)0x00000200);
 {
 } 
It is also recommended that the application have some sort of timeout for this loop in case the 
bus is permanently disturbed.
Resolution:
-------------------------------------------------------------------
The described issue is corrected by modification of all affected work-products. 

Issue Report
7
ESCAN00065128 CANbedded only: multiplex messages are not 
received correctly
Component@Subcomponent: GenTool_GenyDriverBase@GenTool_Geny
First affected version: 1.00.00
Fixed in versions: 2.09.00
Problem Description:
What happens (symptoms):
-------------------------------------------------------------------
With IL: wrong signal values are received.
The RDS message structs of the multiplexed messages are generated incorrect to the can_par.h 
file.
The Il will access the wrong value as multiplexor signal within the message.
This Issue is fixed together with ESCAN00066659
When does this happen:
-------------------------------------------------------------------
At runtime on access to the multiplexed signals by the application if the described configuration is 
valid for the message of this signal
In which configuration does this happen:
-------------------------------------------------------------------
In configurations in which
- Multiplex messages
AND
- the multiplexor of a multiplexed message is not in the first byte 
AND
- the signals before the multiplexor value are not assigned as receive message for this ECU.
ADN
- Interaction Layer used
 
Resolution Description:
Workaround:
-------------------------------------------------------------------
access the multiplexor signal by using the buffer array access.
or if possible
Add your ECU as receiver of the signals before the multiplexor value.
Resolution:
-------------------------------------------------------------------
The described issue is corrected by modification of all affected work-products. 

Issue Report
8
ESCAN00066659 canbedded only: multiplex messages are not 
received correctly
Component@Subcomponent: Hw__baseCpuCan@GenTool_Geny
First affected version: 2.22.04
Fixed in versions: 2.27.00
Problem Description:
What happens (symptoms):
-------------------------------------------------------------------
With IL: wrong signal values are received.
The message structs of the multiplexed messages are generated incorrect to the drv_par.h file.
The Il will access the wrong value as multiplexor signal within the message.
This Issue is fixed together with ESCAN00065128
When does this happen:
-------------------------------------------------------------------
At runtime on access to the multiplexed signals by the application if the described configuration is 
valid for the message of this signal
In which configuration does this happen:
-------------------------------------------------------------------
In configurations in which
- Multiplex messages
AND
- the multiplexor of a multiplexed message is not in the first byte 
AND
- the signals before the multiplexor value are not assigned as receive message for this ECU.
AND
- Il_Vector is used
 
Resolution Description:
Workaround:
-------------------------------------------------------------------
access the multiplexor signal by using the buffer array access.
or if possible
Add your ECU as receiver of the signals before the multiplexor value.
Resolution:
-------------------------------------------------------------------
The described 

... [truncated — 50189 further characters not shown; see the original PDF] ...
```

## Original file

- Repository path: `/Doc/DeliveryInformation/IssueReport_CBD1300660.pdf`

[Back to top](#_top)
