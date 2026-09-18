---
title: "Transport Protocol (ISO 15765-2)"
description: "Multi-connection CAN transport protocol — segmentation, flow control, timing and CANdesc coupling."
---

import { Badge } from '@astrojs/starlight/components';

<Badge text="Vector-provided" variant="note" />

## Purpose

ISO 15765-2 transport layer, multi-connection variant (3.08.01): segments Tx
payloads into First/Consecutive Frames, reassembles Rx, handles Flow Control,
N_Ar/N_As/N_Br/N_Bs/N_Cr timeouts and parallel diagnostic/physical
connections. (~5.8 kLOC `tpmc.c`, ~2.1 kLOC `tpmc.h`.)

## Key files

| File | Role |
| ---- | ---- |
| `BSW/Tp/tpmc.c` | Segmentation/reassembly engine, timers, queues |
| `BSW/Tp/tpmc.h` | Channel config, addressing modes (normal/fixed/extended), app callbacks |

## Public API (selection)

- Lifecycle/tasks: `TpInitPowerOn`, `TpTask`, `TpTxTimerTask`, `TransmissionTask`
- Data path: `TpTxQueueCheck`, `__ApplTpPreCopyCheckFunction`,
  `ApplTpCheckTA`, `AppltpTxErrorFunction`, `TpXxResetChannel`
- Addressing: normal / fixed / extended; DLC handling notes in the TechRef

## Usage example

```c
#include "tpmc.h"

TpInitPowerOn();
for (;;) {
  TpTask();          /* drive timers + state machines */
  TpTxTimerTask();   /* N_As / N_Bs handling */
}
```

## Dependencies

`Can` (frames), `VStdLib` (`VStdRamMemCpy`), `v_def.h`, CANdesc-generated
connection tables (`Misc/Diagnostics/PSA-UDS-1.1.7.cddt`).

## Converted documentation

- [Technical Reference: TP ISO 15765-2](/general/technical-references/technicalreference_transportprotocolmulticonnection/) (177 pp., v3.14.00)

[Back to top](#_top)
