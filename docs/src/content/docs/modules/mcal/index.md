---
title: "MCAL layer"
description: "Microcontroller abstraction — CAN driver and VStdLib for TMS470/TMS570 DCAN."
---

Hardware-near software in this delivery: the DCAN driver and the
compiler/CPU abstraction library.

| Module | Sources | Docs |
| ------ | ------- | ---- |
| CAN driver (DCAN HLL 1.15.00) | `BSW/Can/` | [SIP page](/sip/modules/mcal/can/) · [TR: CAN Driver](/general/technical-references/technicalreference_candriver/) · [TR: TMS470 DCAN](/general/technical-references/technicalreference_can_tms470dcan/) · [UM: CanDriver](/general/user-manuals/usermanual_candriver/) |
| VStdLib (ARM7 2.02.01) | `BSW/VStdLib/` | [SIP page](/sip/modules/mcal/vstdlib/) · [TR: VStdLib](/general/technical-references/technicalreference_vstdlib/) · [AN-ISC-2-1081](/general/application-notes/an-isc-2-1081_interrupt_control_vstdlib/) |

No other MCAL drivers (ADC, DIO, FLS, …) ship in this SIP.

[Back to top](#_top)
