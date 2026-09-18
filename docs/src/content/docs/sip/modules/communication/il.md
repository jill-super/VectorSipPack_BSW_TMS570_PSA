---
title: "Interaction Layer (Il_Vector)"
description: "Signal-based CAN communication layer — cyclic/event transmission, reception, timeouts and node supervision."
---

import { Badge } from '@astrojs/starlight/components';

<Badge text="Vector-provided" variant="note" />

## Purpose

ECU-Abstraction COM layer (`Il_Vector` 5.09.00): maps application signals to
CAN messages, handles cyclic/event/queued transmission, Rx indication and
timeout supervision, plus node communication-state tracking. (~2.8 kLOC each
in `il.c` / `il_def.h`.)

## Key files

| File | Role |
| ---- | ---- |
| `BSW/Il/il.c` | Tx/Rx engine, timer tasks, precopy/dispatch |
| `BSW/Il/il_def.h` | Handles, Tx-type flags, error codes (`ILERR_…`) |
| `BSW/Il/_il_inc.h` | Placeholder for GENy-generated `il_inc.h` |

## Public API (selection)

- Tasks: `IlTxTimerTask`, `IlRxTimerTask` (call cyclically), `IlRxWait` states
- Tx control: `kTxSendCyclic/Event`, `kTxSendRequest`, `kTxNSendRequest`,
  queue/fast-on-start variants; start/stop of periodic Tx per
  [AN-ISC-2-1035](/general/application-notes/an-isc-2-1035_start_stop_periodic_transmission_il/)
- Rx: `IlRxRelease`, indication callbacks, `IlGetNodeCommActiveState`
- Short-DLC acceptance via `GenMsgMinAcceptLength`:
  [AN-ISC-8-1067](/general/application-notes/an-isc-8-1067_genmsgminacceptlength/)

## Usage example

```c
#include "il_def.h"

/* 10 ms task */
void Task10ms(void) {
  IlTxTimerTask();
  IlRxTimerTask();
}
/* Event/cyclic transmission uses the generated per-message API, e.g.: */
/* IlSendMessage(MSG_Handle);   -- exact names come from GENy, see TechRef */
```

> Generated per-signal/message APIs (`IlPutSignal`, `IlSendMessage`, …) come
> from GENy — see the Technical Reference for the exact names in this
> configuration.

## Dependencies

`Can` (transport), `VStdLib` + `v_def.h`, GENy database (DBC) and generated
`il_inc.h`.

## Converted documentation

- [Technical Reference: Il_Vector](/general/technical-references/technicalreference_geny_interactionlayer/) (115 pp., v2.10.03)
- [User Manual: IL with GENy](/general/user-manuals/usermanual_geny_interactionlayer/)

[Back to top](#_top)
