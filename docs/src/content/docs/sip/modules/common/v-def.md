---
title: "Common types (v_def.h)"
description: "Shared Vector type/qualifier header used by every CANbedded module — platform selection and memory mapping."
---

import { Badge } from '@astrojs/starlight/components';

<Badge text="Vector-provided" variant="note" />

## Purpose

Single shared header (`BSW/_Common/v_def.h`, ~1 kLOC, v3.40.00) declaring the
integer types, memory qualifiers (`V_MEMROM*`, `V_DEF_VAR/CONST/FUNC`
families) and compiler/CPU switches for the whole stack. Hardware-specific
settings are baked in — **never mix copies from other platforms**.

## Key file

`BSW/_Common/v_def.h` —
sections: project banner → copyright → per-compiler branches (incl.
`C_COMP_TMS470_DCAN`, Cosmic/GHS/ARM variants) → `V_NULL`, `Bits`,
`V_DEF_*` API → revision history back to 2001.

## Usage example

```c
#include "v_def.h"

/* ROM constant visible to the SIP version check */
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kSipMainVersion;
```

## Dependencies

None (root of the dependency graph). `vstdlib.h` builds on these
qualifiers; every other module includes them transitively.

[Back to top](#_top)
