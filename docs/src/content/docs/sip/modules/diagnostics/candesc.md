---
title: "CANdesc & UDS-PSA diagnostics"
description: "Diagnostics description tooling — CANdesc core, PSA UDS customisation and the PSA .cddt database."
---

import { Badge } from '@astrojs/starlight/components';

<Badge text="Vector-provided" variant="note" /> (tooling — no ECU source in this delivery)

## Purpose

Diagnostics stack description: CANdesc core (2.19.00) plus the PSA-specific
UDS customisation (1.00.00), consumed with the project database
`Misc/Diagnostics/PSA-UDS-1.1.7.cddt` (Diag_DataCddt_Psa 1.00.00) to generate
the TP/Diag configuration. The generated C code itself is **not** part of
this SIP snapshot.

## Key files

| File | Role |
| ---- | ---- |
| `Misc/Diagnostics/PSA-UDS-1.1.7.cddt` | PSA UDS diagnostics description (CANdela/CANdesc database) |
| `Misc/Diagnostics/SetupPersistorsXP.exe` | Persistor add-on installer (Diag_CddPersistors 1.06.00) |
| `Generators/Components/Diag_CanDesc__core*.dll`, `CANdelaGen.dll`, `DiagConfig*.dll` | GENy CANdesc plugins (coreBase impl 5.07.44) |

## Converted documentation

- [Technical Reference: CANdesc](/general/technical-references/technicalreference_candesc/) (117 pp., v2.19.00)
- [Technical Reference: CANdesc UDS PSA](/general/technical-references/technicalreference_candesc_uds_psa/) (v1.00.00)
- [User Manual: CANdesc](/general/user-manuals/usermanual_candesc/)

[Back to top](#_top)
