---
title: "Delivery Test Report CBD1300660"
description: "Converted Vector delivery document — searchable text extraction; the original PDF/HTML remains authoritative."
---
<!-- markdownlint-disable MD009 MD012 MD030 MD046 -->

> **Source:** `/Doc/DeliveryInformation/DeliveryTestReport_CBD1300660.html` — Vector delivery HTML, converted to Markdown for browsing.
> Tables/links are simplified; the HTML file remains authoritative.

## Converted content (abridged)

```text
html, body {
 font-family: Verdana, Helvetica, sans-serif;
 font-size: 9pt;
 margin: 10px;
 }

 div.title {
 background: #B70032;
 color: white;
 font-size: 16pt;
 text-align: center;
 padding: 20px 10px 20px 10px;
 }

 h1 {
 background: #DEDEDE;
 font-weight: bold;
 font-size: 12pt;
 margin-top: 30px;
 margin-bottom: 10px;
 padding: 4px;
 border-bottom-style: solid;
 border-bottom-width: thin;
 }

 h2 {
 font-weight: bold;
 font-size: 10pt;
 margin-top: 20px;
 margin-bottom: 10px;
 padding: 2px;
 border-bottom-style: solid;
 border-bottom-width: 2px;
 border-bottom-color: #B70032;
 }

 table {
 width:100%;
 }

 td,th {
 font-size: 9pt;
 }

 td.verdict {
 width: 10em;
 font-weight: bold;
 text-align: center;
 padding: 6px;
 }

 td.passed {
 background: #00FF00;
 }

 td.failed {
 background: #FF0000;
 }

 th {
 width: 20%;
 text-align: right;
 color: #B70032;
 padding-right: 1em;
 padding-top: 2px;
 padding-bottom: 2px;
 } Delivery Test Report CBD1300660 Delivery Test Report CBD1300660 

The content of this delivery and the tested configuration is described in [CBD1300660_DeliveryDescription.html
 ](CBD1300660_DeliveryDescription.html
 ) CBD1300660_DeliveryDescription.html 

# Delivery Information 

## License Information 
| License Information: | Nexteer Automotive Corporation
Package: CBD Psa SLP4
Micro: 0812BPGEQQ1
Compiler: TexasInstruments 4.9.5 | 
| License Number: | CBD1300660 | 
| OEM: | Psa | 
| SLP: | CBD Psa SLP4 | 
| Controller: | Tmsx70 | 
| CanCell: | Dcan | 
| Compiler: | TexasInstruments | 

## Delivery Information 
| Delivery Number: | 01 | 
| SIP Version: | 05.00.17 | 
| Delivery ID: | 05.00.17.01.30.06.60.01.00.00 | 
| Tested Derivative: | 0812BPGEQQ1 | 
| Release Type: | Serial production release (complete functionality, fully tested , full process, incl. serial production release) | 
| Delivery Type: | Initial delivery (based on explicit purchase order) | 
| Delivery Reason: | 5014730-1.0 | 

# Test Verdict 
| Test Verdict | Passed | 
| Test Report Date | 2014-04-02 | 

# Test Activities 

According to Vector’s embedded software development and delivery process, the test activities are assigned to the development phases of the software. The most important development phases for a delivery like this are the Component Test and the Delivery Test. 

## Component Tests 

Each component listed in the section "Detailed Version Information" within the delivery description has been tested during the component development phase before component release independently of this specific delivery. The test activities on component level include: 
- Code inspection and inspection of all work products, e.g. technical references 
- Static and dynamic tests according to the component-specific test specification and test plan 
- MISRA analysis and justification of deviations 
- Code coverage analysis (target: high code coverage of dynamic tests, additional inspection of uncovered code areas) 

## Delivery Tests 

Testing the ordered program ("SLP") on the real hardware with the target compiler and the requested configuration is performed for each delivery ("SIP") in order to detect any delivery specific issues. The test activities on delivery level include: 
- Compile and link test on the real hardware with customer-specific compiler-, assembler- and linker-options (as specified in the questionnaire) 
- Dynamic tests according to the program related delivery test suite 
- Dynamic tests according to the ordered configuration or use-case (depending on the questionnaire or SLP defaults) 
- Optional: manual tests to cover special use-cases 

The results of the delivery specific tests are documented on a summary level within this report. The result of the component specific test is not documented here as it is a prerequisite that the component has passed its release test before being delivered to customers.
 Vector does not distribute all the detailed test results to you. If you are interested in a review of the detailed delivery test results and those of the component specific tests, please contact Vector for more information. 

# Delivery Tests Results 

## Use Case Passed_Compiler_Options 
| IL Transmission Tests Check if messages are send according to configuration | Passed | 
| DUT Configuration and Test Environment Scan Station Manager configuration and used test environment | Passed | 
| Test status machine of life phases Test possible transitions of status machine of current ECU type | Passed | 
| Test wake up by external event Test transitions if DUT is requesting the network due to an external event ( Organtype 1 and 2 only ) | Passed | 
| DUT Configuration and Test Environment Scan Station Manager configuration and used test environment | Passed | 
| Test status machine of life phases Test possible transitions of status machine of current ECU type | Passed | 
| Test wake up by external event Test transitions if DUT is requesting the network due to an external event ( Organtype 1 and 2 only ) | Passed | 
| Read/Write by ID with multi frame | Passed | 
| Change session from default to EXTENDED and back(functional) | Passed | 
| Communication control (physical) | Passed | 
| Periodic Data | Passed | 
| Spontaneous Response (0x85) | Passed | 
| Remote Frames Test Remote Frames | Passed | 
| Acceptance Filter Test Acceptance Filter | Passed | 
| Extended Status Test Extended Status | Passed | 
| Bus Load Test with heavy bus load | Passed | 
| Individual Polling Test Individual Polling | Passed | 
| Cancel Transmit Test Cancel Transmit | Passed | 
| Application Messages Test Rx / Tx ApplMsg, RDS macros, Pretransmit / Precopy | Passed | 
| Lock CAN interrupts Test functionality of CanCanInterruptDisable and CanCanInterruptRestore. | Passed | 
| TP Transmission Tests Test TP data transmission and TP data reception with variable data length | Passed | 
| VStdMemCopy Tests VStdMemCopy Tests | Passed | 
| VStdMemSet Tests VStdMemSet Tests | Passed | 
| VStdMemClr Tests VStdMemClr Tests | Passed | 
| Download/Upload Data Test Upload from RAM and ROM and Download to RAM | Passed |
```

## Original file

- Repository path: `/Doc/DeliveryInformation/DeliveryTestReport_CBD1300660.html`

[Back to top](#_top)
