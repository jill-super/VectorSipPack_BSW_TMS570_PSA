---
title: "VStdLib (MCAL library)"
description: "Vector Standard Library — platform abstraction for memory routines and interrupt control, incl. Cortex-M3 assembly."
---

import { Badge } from '@astrojs/starlight/components';

<Badge text="Vector-provided" variant="note" />

## Purpose

Compiler/CPU abstraction used by **all** CANbedded modules: optimised memory
routines, versioned IRQ suspend/restore, and error hooks. The TMS570 build
uses the ARMv7-M path plus two `PRIMASK` assembly helpers.

## Key files

| File | Role |
| ---- | ---- |
| `BSW/VStdLib/vstdlib.c` (953 lines) | `VStd*` implementation (mem, IRQ nesting, error handling) |
| `BSW/VStdLib/vstdlib.h` (875 lines) | `VSTD_DEF_*` qualifier macros, error codes (`kVStdError…`) |
| `BSW/VStdLib/vstdlib_lib.asm` | `_getPRIMASK` / `_setPRIMASK` for TI compiler + Cortex-M3 |

## Public API (selection)

- Interrupts: suspend/resume-all-interrupts family built on
  `VStdSuspendAllInterrupts` semantics; error codes
  `kVStdErrorIntDisableTooOften`, `kVStdErrorIntRestoreTooOften`
- Memory: `VStdRomMemCpy` and related `VStd*MemCpy/Set/Clear` helpers used by
  TP/IL instead of raw `memcpy`
- Portability: `VSTD_DEF_VAR/CONST/FUNC` + `V_DEF_*` mapping per compiler
  (`C_COMP_TMS470_DCAN`) and memory-model qualifiers

## Usage example

```c
#include "vstdlib.h"

VStdSuspendAllInterrupts();   /* nestable critical section */
/* ... touch driver/IL shared state ... */
VStdRestoreAllInterrupts();   /* restores PRIMASK via vstdlib_lib.asm */
```

## Dependencies

- `BSW/_Common/v_def.h`; no other BSW dependency (everything depends on it).

## Converted documentation

- [Technical Reference: VStdLib](/general/technical-references/technicalreference_vstdlib/) (v1.6.2)
- [AN-ISC-2-1081 Interrupt Control with VStdLib](/general/application-notes/an-isc-2-1081_interrupt_control_vstdlib/)

[Back to top](#_top)
