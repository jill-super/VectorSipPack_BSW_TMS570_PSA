---
title: "Vector SIP overview (05.00.17)"
description: "Identity, scope and module catalogue of Software Integration Package delivery CBD1300660."
---

import { Badge } from '@astrojs/starlight/components';

The **Software Integration Package (SIP)** is Vector's tested bundle of
CANbedded sources + GENy plugins for one customer project. This repository
holds exactly one such delivery:

| Field | Value |
| ----- | ----- |
| Licence (CBD) | CBD1300660 |
| SIP version | 05.00.17 (Delivery D01, Release 01) |
| Delivery ID | 05.00.17.01.30.06.60.01.00.00 |
| Customer / package | Nexteer Automotive Corporation — CBD PSA SLP4 |
| MCU / CAN cell | TI TMS570 `0812BPGEQQ1` (TMSx70 / DCAN) |
| Compiler | Texas Instruments 4.9.5 |
| OEM / SLP | PSA / CBD PSA SLP4 |
| Release type | Serial production release (fully tested) |
| Test verdict | Passed, 2014-04-02 |
| Maintenance expiry | 2024-03-18 |

## Scope of this SIP

- **Included:** CAN driver (DCAN HLL), Interaction Layer, ISO-TP, indirect
  NM + PSA Station Manager, XCP + XCP-on-CAN, VStdLib, `v_def.h`, SIP version
  check, GENy plugins + PreConfig, CANdesc/UDS-PSA diagnostics description,
  full PDF/HTML delivery documentation.
- **Not included:** application software, RTE/OS, other MCAL drivers,
  generated `GenData` output (produced at integration time by GENy).

## Module catalogue

| Module | Layer | Origin | Docs |
| ------ | ----- | ------ | ---- |
| CAN driver (DCAN) | MCAL | <Badge text="Vector-provided" variant="note" /> | [page](/sip/modules/mcal/can/) |
| VStdLib | MCAL library | <Badge text="Vector-provided" variant="note" /> | [page](/sip/modules/mcal/vstdlib/) |
| Interaction Layer (Il_Vector) | Communication | <Badge text="Vector-provided" variant="note" /> | [page](/sip/modules/communication/il/) |
| Transport Protocol (ISO 15765-2) | Communication | <Badge text="Vector-provided" variant="note" /> | [page](/sip/modules/communication/tp/) |
| NM (IndOsek) + Station Manager | Communication | <Badge text="Vector-provided" variant="note" /> | [page](/sip/modules/communication/nm/) |
| XCP + XCP-on-CAN | Services | <Badge text="Vector-provided" variant="note" /> (+ template) | [page](/sip/modules/services/xcp/) |
| v_def (common types) | Common | <Badge text="Vector-provided" variant="note" /> | [page](/sip/modules/common/v-def/) |
| SIP version check | Common | <Badge text="Vector-provided" variant="note" /> | [page](/sip/modules/common/sip-version-check/) |
| CANdesc / UDS-PSA | Diagnostics tooling | <Badge text="Vector-provided" variant="note" /> | [page](/sip/modules/diagnostics/candesc/) |

Further reading: [Delivery & test report](/sip/delivery/),
[Generator components](/sip/generators/),
[Vector vs custom code](/overview/origin/).

[Back to top](#_top)
