---
title: "CAN driver (MCAL, DCAN)"
description: "Vector CAN driver for TMS470/TMS570 DCAN — low-level driver plus high-level queue, sleep and bus-off handling."
---

import { Badge } from '@astrojs/starlight/components';

<Badge text="Vector-provided" variant="note" />

## Purpose

MCAL CAN driver for the TMS470/TMS570 **DCAN** cell: initialisation, polled /
interrupt-driven Tx/Rx over hardware mailboxes, Tx queue, bus-off recovery,
sleep/wake-up and CAN-error supervision hooks used by the Station Manager.
(~7.8 kLOC `can_drv.c`, ~2.4 kLOC `can_def.h`.)

## Key files

| File | Role |
| ---- | ---- |
| `BSW/Can/can_drv.c` | Low-level + HLL implementation (mailboxes, Tx queue, Rx task, bus-off) |
| `BSW/Can/can_def.h` | Public API, status codes (`kCanTxOk`, `kCanHwIsBusOff`, …), config includes |
| `BSW/Can/_can_inc.h` | Placeholder for the GENy-generated `can_inc.h` (do not edit — regenerate) |

## Public API (selection)

- Lifecycle: `CanInit`, `CanRxTask`, `CanMsgTransmit`, `CanGetStatus`
- HLL callbacks: `CanHL_ReceivedRxHandle`, `ApplCanMsgTransmitConf`
- Dynamic Tx objects: `CanDynTxObjSetId`, `CanDynTxObjSetExtId`
- Low level: `CanLL_IsMailboxCorrupt`, `Can_LL_TxEnd`
- Status: `kCanTxOn/Off`, `kCanHwIsSleep/BusOff/Warning/Passive`, `kCanTxFailed/Ok`

## Usage example

```c
#include "can_def.h"

CanInit();                 /* power-on init, generated config via can_inc.h */
for (;;) {
  CanRxTask();             /* poll / dispatch received messages */
  /* ... application / IL / TP processing ... */
  if (CanMsgTransmit(txHandle, dataPtr) == kCanTxOk) { /* queued */ }
}
```

## Dependencies

- `BSW/_Common/v_def.h` (types), GENy-generated `can_inc.h`,
  `BSW/VStdLib` (critical sections), transceiver control by the application
  ([AN-ISC-2-1029](/general/application-notes/an-isc-2-1029_transceiver_handling/)).

## Converted documentation

- [Technical Reference: Vector CAN Driver](/general/technical-references/technicalreference_candriver/) (149 pp.)
- [Technical Reference: TMS470 DCAN](/general/technical-references/technicalreference_can_tms470dcan/) (derivative specifics, v1.05.00)
- [User Manual: CAN Driver first steps](/general/user-manuals/usermanual_candriver/)

[Back to top](#_top)
