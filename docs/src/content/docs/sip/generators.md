---
title: "Generator components (GENy)"
description: "GENy/DaVinci-era generator plugins, PreConfig and version manifest in Generators/Components."
---

`Generators/Components/` holds the Windows GENy toolchain plugins used to
configure and generate this SIP (60+ `*.dll`, plus `PreConfig_PSA_SLP4.pco`,
`StandardECU.pcu` and the `version.info` manifest). They are **host tools** —
never compiled into the ECU.

## Plugin → target-module map (from `version.info`)

| Generator plugin | Target | Delivered version |
| ---------------- | ------ | ----------------- |
| `Il_Vector.dll` | Interaction Layer | Gen 1.17.00 / Impl 5.09.00 |
| `Tp_Iso15765.dll` | Transport Protocol | Gen 2.34.00 / Impl 3.08.01 |
| `DrvCan_Tms470DcanHll.dll` + `DrvCan__base*.dll` | CAN driver | HLL Gen 1.05.00 / Impl 1.15.00 |
| `Hw_Tms470Cpu.dll`, `Hw_Tms470DcanCpuCan.dll`, `Hw__baseCpuCan.dll` | CPU/CAN hardware description | e.g. 2.13.01 / 1.15.00 |
| `Nm_IndOsek.dll`, `Nm_StMgrIndOsek_Ls.dll` | NM + Station Manager | 2.00.00 / 1.00.00 (impl 3.00.00 / 3.03.01) |
| `Cp_Xcp.dll`, `Cp_XcpOnCan.dll` | XCP | 2.20.06 / 1.08.02 (impl 1.29.00 / 1.07.03) |
| `VStdLib__base.dll` | VStdLib | 1.01.02 (impl 2.02.01 ARM7) |
| `CANdelaGen.dll`, `Diag_CanDesc__core(Base).dll`, `DiagConfig*.dll` | CANdesc / diagnostics | coreBase impl 5.07.44 |
| `GenTool_GenyDriverBase.dll`, `GenTool_GenyObjectModel.dll`, … | GENy framework | various (see manifest) |
| `PreConfig_PSA_SLP4.pco`, `StandardECU.pcu` | Project pre-configuration | 5.00.02 |

Full manifest:
`Generators/Components/version.info`
(SIP 05.00.17, created 2014-03-31, delivery 2014-03-18).

## Notes

- The `_can_inc.h` / `_il_inc.h` placeholders in `BSW/` are replaced by the
  output of these plugins during integration.
- `Misc/Diagnostics/PSA-UDS-1.1.7.cddt` is the CANdesc diagnostics
  description consumed by the `Diag_*` plugins; `SetupPersistorsXP.exe`
  installs the persistor add-on.
- Keep generator DLLs and `BSW/` sources at the SIP-matched versions —
  `BSW/SipVersionCheck/sip_vers.c` fails the build on mismatch by design.

[Back to top](#_top)
