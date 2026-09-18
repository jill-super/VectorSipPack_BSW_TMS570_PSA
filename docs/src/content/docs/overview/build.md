---
title: "Build & integrate"
description: "How to build and integrate this SIP delivery — compiler, generation flow, and bring-up order."
---

There is **no Makefile / CMake / code project** in this delivery — that is
expected for a SIP of this era. The firmware is built from these sources plus
GENy-generated configuration, compiled with the TI toolchain.

## Prerequisites

| Item | Value (per delivery) |
| ---- | -------------------- |
| MCU / derivative | TI TMS570 `0812BPGEQQ1` (TMS470 family, DCAN cell) |
| Compiler | Texas Instruments 4.9.5 (ARM) |
| Configurator | GENy (see `Generators/Components/`, `PreConfig_PSA_SLP4.pco`) |
| Database | CAN DBC + `Misc/Diagnostics/PSA-UDS-1.1.7.cddt` for diagnostics |
| First read | [Startup with PSA](/general/user-manuals/startup_psa_canbedded/) and [WELCOME to CANbedded](/general/user-manuals/welcometocanbedded/) |

## Generation → compilation flow

1. **Configure in GENy** using `Generators/Components/PreConfig_PSA_SLP4.pco`
   (+ `StandardECU.pcu`); import the CAN database.
2. **Generate** — GENy (plugins `DrvCan_*.dll`, `Il_Vector.dll`,
   `Tp_Iso15765.dll`, `Nm_*.dll`, `Cp_Xcp*.dll`, …) emits the real
   `can_inc.h` / `il_inc.h` family (the `BSW/*/_*_inc.h` files here are
   placeholders) plus checksum/validation artefacts.
3. **Adapt the templates** — copy `BSW/Nm/_Generic_precopy.c` and
   `BSW/Xcp/_xcp_appl.c` into your project, rename, implement the
   application callbacks, and remove the intentional `#error` stubs (see
   [Readme_CBD1300660](/general/delivery/readme_cbd1300660/)).
4. **Compile** all of `BSW/` for `C_COMP_TMS470_DCAN` with TI 4.9.5,
   including `vstdlib_lib.asm` (Cortex-M3 PRIMASK helpers). A version mix-up
   surfaces as a compile error in `BSW/SipVersionCheck/sip_vers.c` — that is
   by design; check include paths and component versions in
   `version.info`.
5. **Integrate cyclic tasks** — call `CanRxTask`/`CanTxTask`-family,
   `IlTxTimerTask`/`IlRxTimerTask`, `TpTask`, `InmNmTask`/`SmTask`,
   `XcpBackground`/`XcpCanBackground` at their configured periods from your
   OS/scheduler (see the [OS application note](/general/application-notes/an-isc-2-1052_canbedded_and_operating_systems/)).

## Bring-up order (recommended)

`v_def.h` → `VStdLib` → `Can` → `Il` → `Tp` → `Nm/Station Manager` →
diagnostics (`CANdesc`) → `Xcp`. Validate each step against its Technical
Reference before enabling the next layer.

## Stack & interrupt notes

- Protect driver/IL critical sections with the `VStdLib` suspend/restore API
  (see [AN-ISC-2-1081](/general/application-notes/an-isc-2-1081_interrupt_control_vstdlib/)).
- Size task stacks using [AN-ISC-8-1056](/general/application-notes/an-isc-8-1056_canbedded_program_stack_usage/).
- Transceiver enable/disable sequencing: [AN-ISC-2-1029](/general/application-notes/an-isc-2-1029_transceiver_handling/).

[Back to top](#_top)
