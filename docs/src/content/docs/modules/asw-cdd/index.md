---
title: "ASW / CDD — not in this delivery"
description: "Why there is no application software or complex driver documentation here."
---

This SIP delivery contains **no Application Software (ASW) and no Complex
Device Drivers (CDD)**. Those layers live downstream:

- **ASW** — ECU application, PSA network-application logic, diagnostics
  application callbacks (your copy of `_xcp_appl.c`, `_Generic_precopy.c`).
- **CDD** — any customer-specific hardware handling outside the Vector
  drivers (e.g. transceiver drivers per
  [AN-ISC-2-1029](/general/application-notes/an-isc-2-1029_transceiver_handling/)).

When ASW/CDD files are added to this repository, document each under
`docs/src/content/docs/modules/` with the same structure as the
[SIP module pages](/sip/) and mark them
`Custom` (see [Vector vs custom code](/overview/origin/)).

[Back to top](#_top)
