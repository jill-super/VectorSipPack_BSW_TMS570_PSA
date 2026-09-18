---
title: "SIP version check"
description: "Compile-time guard that every compiled component matches SIP 05.00.17, plus ROM version constants."
---

import { Badge } from '@astrojs/starlight/components';

<Badge text="Vector-provided" variant="note" />

## Purpose

Two jobs in one tiny module (`BSW/SipVersionCheck/`):

1. **Fail the build on version mix-ups** — `#if` comparisons of each
   component's `*_VERSION` macros against the SIP 05.00.17 expectations.
2. **Expose the SIP version at runtime** — ROM constants for diagnostics.

## Key files

| File | Role |
| ---- | ---- |
| `BSW/SipVersionCheck/sip_vers.c` (220 lines) | Licence stamp (CBD1300660 / Nexteer / TMS570 / TI 4.9.5) + version `#if` guards |
| `BSW/SipVersionCheck/sip_vers.h` | `kSipMainVersion` / `kSipSubVersion` / `kSipBugFixVersion` declarations |

Stamped values: serial `CBD1300660`, licence date `2014-03-18`.

## If the compiler stops here

1. Check the flagged module is really in your project and its include path
   resolves (a missing header compares as `0`).
2. Check you did not mix a newer/older component into this SIP.
3. Check this is the right `sip_vers.c` for your project (it travels with
   component updates).

Then contact Vector customer support with the delivery ID.

[Back to top](#_top)
