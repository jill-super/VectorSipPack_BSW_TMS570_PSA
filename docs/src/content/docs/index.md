---
title: "BSW TMS570 PSA Documentation"
description: "AUTOSAR-style Basic Software for TI TMS570 / PSA SLP4 — Vector SIP CBD1300660 (05.00.17)."
template: splash
hero:
  tagline: CANbedded Basic Software for the TI TMS570 (PSA SLP4) — Vector SIP CBD1300660, documented module by module.
  image:
    file: ../../assets/logo.svg
  actions:
    - text: Browse the SIP
      link: /sip/
      icon: right-arrow
    - text: Repository map & layers
      link: /overview/layers/
      icon: open-book
    - text: Converted documents
      link: /general/
      icon: document
      variant: minimal
---

import { Card, CardGrid, Badge } from '@astrojs/starlight/components';

## What is in this repository?

A **Vector CANbedded Software Integration Package (SIP)** delivery —
`CBD1300660`, SIP `05.00.17` — for **Nexteer / PSA SLP4** on the
**TI TMS570** (`0812BPGEQQ1`) with the **Texas Instruments 4.9.5** compiler.
It contains C sources for CAN communication, diagnostics and calibration,
GENy generator plugins, and the original Vector PDF/HTML delivery documents.

<CardGrid stagger>
  <Card title="Vector SIP" icon="package">
    Delivery identity, version check, generator plugins and the full module
    catalogue. Start at [SIP overview](/sip/).
  </Card>
  <Card title="Modules by AUTOSAR layer" icon="layers">
    MCAL, Communication, Services and Common — each module states its origin
    (Vector vs template) with key files and APIs.
  </Card>
  <Card title="Converted documents" icon="document">
    All 26 PDFs + delivery HTML/TXT converted to searchable Markdown under
    [Converted documents](/general/).
  </Card>
  <Card title="Build & integrate" icon="setting">
    No Makefile/CMake here — build with the TI compiler plus GENy-generated
    config. See [Build & integrate](/overview/build/).
  </Card>
</CardGrid>

## Origin at a glance

| Group | Origin | Examples |
| ----- | ------ | -------- |
| `BSW/*` runtime sources | <Badge text="Vector-provided" variant="note" /> | `Can`, `Il`, `Tp`, `Nm`, `Xcp`, `VStdLib`, `_Common` |
| `BSW/Nm/_Generic_precopy.c`, `BSW/Xcp/_xcp_appl.c` | <Badge text="Vector template — customise" variant="caution" /> | Copy, rename and adapt in your project |
| `Generators/`, `Misc/Diagnostics` | <Badge text="Vector tooling" variant="note" /> | GENy DLLs, `.cddt` diagnostics description |
| Application / integration code | — | **Not in this delivery** (downstream) |

Details: [Vector vs custom code](/overview/origin/).

## Delivery fingerprint

- **License / CBD:** CBD1300660 · **SIP:** 05.00.17 · **Delivery:** D01, serial-production release
- **ECU:** TI TMS570 `0812BPGEQQ1` (TMS470/DCAN cell) · **Compiler:** TI 4.9.5
- **OEM/SLP:** PSA / CBD PSA SLP4 · **Customer:** Nexteer Automotive Corporation
- **Test verdict:** Passed (2014-04-02) · **Maintenance expiry:** 2024-03-18

Sources: [Delivery & test report](/sip/delivery/),
DeliveryDescription.

[Back to top](#_top)
