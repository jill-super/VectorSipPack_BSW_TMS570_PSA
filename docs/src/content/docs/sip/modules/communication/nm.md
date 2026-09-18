---
title: "Network Management + PSA Station Manager"
description: "Indirect OSEK NM plus the PSA Low-Speed Fault-Tolerant Station Manager — sleep, bus-off and error-counter supervision."
---

import { Badge, Aside } from '@astrojs/starlight/components';

<Badge text="Vector-provided" variant="note" /> (plus one
<Badge text="Vector template — customise" variant="caution" /> file)

## Purpose

Two cooperating pieces:

- **INM_Osek** (3.00.00, ~1.2 kLOC) — indirect network management: Tx/Rx and
  generic supervision conditions, diag on/off, init/start/stop.
- **Station Manager for PSA Low-Speed Fault-Tolerant Bus** (3.03.01, ~3.1
  kLOC) — PSA-specific network states (`REVEIL`/`NORMAL`/`Veille`/degraded),
  bus-off recovery, `PerteCOM`/`Nerr`/mute/Rx supervision, non-volatile
  counters and sleep management for slave/complete nodes.

## Key files

| File | Role |
| ---- | ---- |
| `BSW/Nm/INM_Osek.c` / `.h` | Indirect-NM core API |
| `BSW/Nm/Stat_mgr.c` / `.h` | Station Manager app interface + states |
| `BSW/Nm/_Generic_precopy.c` | <Badge text="Vector template — customise" variant="caution" /> precopy template — copy, adapt, clear `#error` stubs |

## Public API (selection)

- NM: `InmNmInit/ReInit/Start/Stop`, `InmNmGetStatus`,
  `InmNmTx/Rx/Generic{Ok,TimeOut,DiagOn/Off,Get*Condition}`
- Station Manager: `SmInitPowerOn`, `SmStart`, `SmTask`, `SmTask` supervision
  (`SmTx/RxTimeoutSupervision`), `SmGetStatus`, `SmSet/ReleaseNetworkRequest`,
  `SmSetWakeUpRequest`, `SmTransmitNmMessage`, `SmResetSupervision`,
  volatile/non-volatile counters (`SmGet/SetVolCBoff`, `…PerteCom`, `…Nerr`, …)

## Usage example

```c
#include "Stat_mgr.h"
#include "INM_Osek.h"

SmInitPowerOn();
InmNmInit();
SmStart();
for (;;) {
  SmTask();   /* PSA state machine + supervisions */
}
```

<Aside type="caution" title="Template first">
  `_Generic_precopy.c` is *not* compiled as-is — follow
  [Readme_CBD1300660](/general/delivery/readme_cbd1300660/): adapt the file to
  your DBC/program, then comment out the error lines.
</Aside>

## Dependencies

`Can` (bus-off/sleep primitives), `Il` (message states/timeouts), `VStdLib`,
GENy NM configuration.

## Converted documentation

- [Technical Reference: Nm_IndOsek](/general/technical-references/technicalreference_nm_indosek/) (v1.12)
- [Technical Reference: Station Manager](/general/technical-references/technicalreference_stationmanager/) (v3.05, 35 pp.)

[Back to top](#_top)
