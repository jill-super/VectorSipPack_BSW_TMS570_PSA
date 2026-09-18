---
title: "Vector vs custom code"
description: "How to tell Vector SIP files apart from in-house code, and how templates must be handled."
---

import { Badge, Aside } from '@astrojs/starlight/components';

## Rule of thumb

**Everything under `BSW/`, `Doc/`, `Generators/` and `Misc/Diagnostics` in
this delivery is Vector-provided.** There is currently **no in-house custom
code** in the repository — custom code lives downstream (ECU application,
`_xcp_appl`-style callbacks, generated `GenData`).

## How origin was determined

Each `BSW` source/header carries a Vector copyright banner, e.g.:

```text
|   Copyright (c) 2012 by Vector Informatik GmbH.   All rights reserved.
|   This software is copyright protected and proprietary to
|   Vector Informatik GmbH. ...
```

Additional markers found during the audit:

- `Project Name:` banners (`DrvCan_TMS470Dcan`, `Tp_Iso15765`, `XCP Protocol Layer`, …)
- `ESCAN…` revision-history entries (Vector issue tracker IDs)
- `Generators/Components/version.info` (SIP 05.00.17 component manifest)
- GENy/GenData references in `_can_inc.h`, `_il_inc.h`, `INM_Osek.*`
  (generated-configuration includes)

## Origin classes used in this documentation

| Badge | Meaning | Handling |
| ----- | ------- | -------- |
| <Badge text="Vector-provided" variant="note" /> | Ships as-is from the SIP; do not edit | Update only via a new Vector delivery |
| <Badge text="Vector template — customise" variant="caution" /> | Ships as `_`-prefixed template; **must** be copied/adapted | Copy to your project, rename (drop `_`), adapt, remove `#error` stubs |
| <Badge text="Vector tooling" variant="note" /> | Generator / diagnostics tool, not target code | Version with the SIP; keep `version.info` in sync |

## Files by origin

| File(s) | Origin |
| ------- | ------ |
| `BSW/Can/can_drv.c`, `can_def.h` | <Badge text="Vector-provided" variant="note" /> |
| `BSW/Il/il.c`, `il_def.h` | <Badge text="Vector-provided" variant="note" /> |
| `BSW/Nm/INM_Osek.c/.h`, `Stat_mgr.c/.h` | <Badge text="Vector-provided" variant="note" /> |
| `BSW/Nm/_Generic_precopy.c` | <Badge text="Vector template — customise" variant="caution" /> (Station Manager precopy template; see delivery `Readme_CBD1300660.txt`) |
| `BSW/Tp/tpmc.c/.h` | <Badge text="Vector-provided" variant="note" /> |
| `BSW/VStdLib/vstdlib.*`, `vstdlib_lib.asm` | <Badge text="Vector-provided" variant="note" /> |
| `BSW/Xcp/XcpProf.c/.h`, `xcp_can.c/.h` | <Badge text="Vector-provided" variant="note" /> |
| `BSW/Xcp/_xcp_appl.c` | <Badge text="Vector template — customise" variant="caution" /> (application callbacks — flash/EEPROM/paging stubs) |
| `BSW/_Common/v_def.h` | <Badge text="Vector-provided" variant="note" /> |
| `BSW/SipVersionCheck/sip_vers.*` | <Badge text="Vector-provided" variant="note" /> (project-stamped: CBD1300660 / Nexteer / TMS570) |
| `BSW/Can/_can_inc.h`, `BSW/Il/_il_inc.h` | <Badge text="Vector-provided" variant="note" /> placeholders — replaced by GENy output |
| `Generators/Components/*.dll`, `*.pco`, `version.info` | <Badge text="Vector tooling" variant="note" /> |
| `Misc/Diagnostics/*` | <Badge text="Vector tooling" variant="note" /> |

<Aside type="caution" title="Licensing">
  Vector files remain under Vector's proprietary licence (see the banners and
  the [licence addendum](/general/delivery/license-addendum_cbd1300660/)).
  The repository-level MIT licence
  covers **this documentation and any in-house additions** — it does not
  re-licence Vector's SIP sources. Keep the two apart when reusing files.
</Aside>

[Back to top](#_top)
