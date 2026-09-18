# BSW_TMS570_PSA

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Language: C](https://img.shields.io/badge/language-C-blue.svg)](BSW/)
[![SIP 05.00.17](https://img.shields.io/badge/SIP-05.00.17-green.svg)](docs/src/content/docs/sip/index.md)
[![MCU: TMS570](https://img.shields.io/badge/MCU-TI%20TMS570-red.svg)](docs/src/content/docs/overview/build.md)

Automotive Basic Software (BSW) for the Texas Instruments **TMS570**
(`0812BPGEQQ1`), tailored for **PSA SLP4** — a Vector CANbedded Software
Integration Package (**SIP 05.00.17**, licence **CBD1300660**): CAN
communication, ISO transport protocol, network management + PSA Station
Manager, XCP calibration, GENy generator plugins and the full delivery
documentation.

📖 **Documentation site (Astro/Starlight, GitHub Pages):**
built from [`docs/`](docs/) and published to this repository's
`github.io/BSW_TMS570_PSA` project path.

## Table of contents

- [Delivery fingerprint](#delivery-fingerprint)
- [Repository structure](#repository-structure)
- [AUTOSAR layers & module catalogue](#autosar-layers--module-catalogue)
- [Vector vs custom code](#vector-vs-custom-code)
- [Build & integrate](#build--integrate)
- [Documentation \& converted PDFs](#documentation--converted-pdfs)
- [Contributing docs](#contributing-docs)
- [License](#license)

## Delivery fingerprint

| Field | Value |
| ----- | ----- |
| Licence (CBD) | CBD1300660 |
| SIP | 05.00.17, Delivery D01, Release 01 |
| Customer / package | Nexteer Automotive — CBD PSA SLP4 |
| MCU / CAN cell | TI TMS570 `0812BPGEQQ1` (TMSx70 / DCAN) |
| Compiler | Texas Instruments 4.9.5 |
| Test verdict | Passed (2014-04-02) |

## Repository structure

```text
BSW/            C sources (CAN, IL, TP, NM/StationMgr, XCP, VStdLib, common, version check)
Doc/            Original Vector documents (26 PDFs + 2 HTML + 1 TXT)
Generators/     GENy/DaVinci-era generator plugins + PreConfig + version.info
Misc/           PSA UDS diagnostics description (.cddt) + tooling
docs/           Astro Starlight documentation site (this README's 📖 link)
```

## AUTOSAR layers & module catalogue

<details>
<summary><strong>Layer map (click to expand)</strong></summary>

| Module | Directory | AUTOSAR-style layer | Origin |
| ------ | --------- | ------------------- | ------ |
| CAN driver (DCAN) | `BSW/Can` | MCAL | Vector-provided |
| VStdLib | `BSW/VStdLib` | MCAL library | Vector-provided |
| Interaction Layer (Il_Vector) | `BSW/Il` | ECU Abstraction (COM) | Vector-provided |
| Transport Protocol (ISO 15765-2) | `BSW/Tp` | Communication Services | Vector-provided |
| NM (IndOsek) + PSA Station Manager | `BSW/Nm` | Communication Services | Vector-provided (+1 template) |
| XCP + XCP-on-CAN | `BSW/Xcp` | Services | Vector-provided (+1 template) |
| `v_def.h` common types | `BSW/_Common` | Common | Vector-provided |
| SIP version check | `BSW/SipVersionCheck` | Common | Vector-provided |
| CANdesc / UDS-PSA | `Misc/Diagnostics` + GENy plugins | Diagnostics tooling | Vector-provided |

No Application Software (ASW), Complex Drivers (CDD), RTE or OS ship in this
delivery — those live downstream. Full per-module pages (purpose, key files,
API, usage, dependencies): [SIP overview](docs/src/content/docs/sip/index.md).

</details>

## Vector vs custom code

- **All `BSW/` sources are Vector-provided** (Vector copyright banners,
  `ESCAN` history, SIP manifest `Generators/Components/version.info`).
- **Two files are customisation templates** (copy → rename → adapt, clear the
  `#error` stubs): `BSW/Nm/_Generic_precopy.c` and `BSW/Xcp/_xcp_appl.c`.
- **No in-house code** is in the repo today; `BSW/*/_*_inc.h` files are
  placeholders replaced by GENy output.

> ⚠️ Vector files stay under Vector's proprietary licence — the MIT licence
> below covers this repo's docs/workflows/additions, not the SIP sources.
> See [LICENSE](LICENSE) and the [origin page](docs/src/content/docs/overview/origin.md).

## Build & integrate

No Makefile/CMake here — build = GENy generation + TI compilation:

1. Configure in GENy (`Generators/Components/PreConfig_PSA_SLP4.pco`), generate.
2. Adapt the `_Generic_precopy.c` / `_xcp_appl.c` templates into your project.
3. Compile `BSW/` with TI 4.9.5 for `C_COMP_TMS470_DCAN` (incl. `vstdlib_lib.asm`).
4. Schedule the cyclic tasks (`CanRxTask`, `IlTxTimerTask`, `TpTask`, `SmTask`, `XcpCanBackground`, …).

Details: [overview/build](docs/src/content/docs/overview/build.md) ·
[first steps: Startup with PSA](docs/src/content/docs/general/user-manuals/Startup_PSA_CANbedded.md).

## Documentation & converted PDFs

- 📖 Site: built from [`docs/`](docs/) — see the local preview below
- All **26 PDFs + 2 HTML + 1 TXT** from `Doc/` are converted to searchable
  Markdown under [`docs/src/content/docs/general/`](docs/src/content/docs/general/index.md)
  (9 Technical References, 6 Application Notes, 6 User Manuals, 5 delivery docs).
- No `.doc`/`.docx` files and no module-level `doc/` folders exist — `Doc/`
  is the complete inventory. Conversion method/limits:
  [`general/conversion-notes`](docs/src/content/docs/general/conversion-notes.md).

<details>
<summary><strong>Preview the docs locally</strong></summary>

```sh
cd docs
npm ci
npm run dev     # local preview (URL is printed by the dev server)
npm run build   # production build -> docs/dist/
```

</details>

## Contributing docs

- Curated pages live in `docs/src/content/docs/` (Starlight front matter:
  `title` + `description`); sidebar order is set in `docs/astro.config.mjs`.
- Converted PDFs are snapshots — re-extract with `pypdf`, don't hand-edit
  beyond the header notice.
- Verify locally with `npm run build` in `docs/` before pushing.

## License

MIT for this repository's own content — see [LICENSE](LICENSE) — **except**
`BSW/`, `Doc/`, `Generators/`, `Misc/Diagnostics`, which remain under
Vector's proprietary licence (delivery CBD1300660).
