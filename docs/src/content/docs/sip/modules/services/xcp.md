---
title: "XCP protocol + XCP-on-CAN"
description: "XCP V1.0 slave — DAQ/STIM measurement, calibration/paging, programming, checksums and the CAN transport adaption."
---

import { Badge, Aside } from '@astrojs/starlight/components';

<Badge text="Vector-provided" variant="note" /> (plus one
<Badge text="Vector template — customise" variant="caution" /> file)

## Purpose

- **XcpProf** (1.29.00, ~4.1 kLOC): XCP V1.0 slave — CONNECT, DAQ lists
  (dynamic allocation, BYTE event/DAQ numbers), STIM, CAL/PAG page switching,
  checksum (block ≤ 0xFFFF), seed/key, session configuration ID.
- **xcp_can** (1.07.03): transport adaption between `XcpProf` and the Vector
  CAN driver (no interleaved mode, no GET_SLAVE_ID scan, no DAQ-ID remapping).
- **_xcp_appl.c** (916 lines):
  <Badge text="Vector template — customise" variant="caution" /> application
  callbacks (flash/EEPROM programming, page switching, checksum, GET_ID).

## Key files

| File | Role |
| ---- | ---- |
| `BSW/Xcp/XcpProf.c` / `.h` | Protocol layer (commands, DAQ, checksum, seed/key) |
| `BSW/Xcp/xcp_can.c` / `.h` | CAN transport (`XcpCanInit/Send/Background`, `XcpTransmit`) |
| `BSW/Xcp/_xcp_appl.c` | Template callbacks (`ApplXcpInitTemplate`, `ApplXcpReadChecksumValue`, `ApplXcpCalibrationRead/Write`, custom CRC, generic GET_ID) |

## Public API (selection)

- Protocol: `XcpSendDto`, `XcpSendCallBack`, `XcpStimEventStatus`, resource
  masks, communication-mode info; limits documented in the file banner
  (MAX_DTO ≤ 255, seed/key ≤ MAX_CTO−2, no ODT optimisation, …)
- Transport: `XcpCanInit`, `XcpCanSend`, `XcpCanSendFlush`,
  `XcpGetCanTransmitHandle`, `XcpCanBackground`
- Application: `ApplXcp*` family (init, page, checksum, calibration,
  programming) — implement in your copy of `_xcp_appl.c`

## Usage example

```c
#include "XcpProf.h"
#include "xcp_can.h"

XcpCanInit();
ApplXcpInit();            /* your adapted _xcp_appl.c */
for (;;) {
  XcpCanBackground();     /* or XcpBackground, per configuration */
}
```

<Aside type="note" title="Known limits">
  See the banner of `XcpProf.c`: dynamic DAQ only, no resume-bit/event
  overload indication, no page/segment info, single event channel per DAQ
  list, default programming format.
</Aside>

## Dependencies

`Can` (frames/handles), `VStdLib`, GENy XCP configuration (`Cp_Xcp*.dll`).

## Converted documentation

- No XCP Technical Reference ships in `Doc/` — the file banners plus the
  [CAN architecture](/general/user-manuals/can-architecture/) and
  [WELCOME to CANbedded](/general/user-manuals/welcometocanbedded/) notes apply.

[Back to top](#_top)
