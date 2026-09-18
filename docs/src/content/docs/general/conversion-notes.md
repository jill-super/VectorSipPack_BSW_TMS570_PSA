---
title: "Conversion notes & limits"
description: "How the PDFs/HTML/TXT were converted, what was preserved, and what was not."
---

## Method

- **PDFs:** text extracted with `pypdf` (`PdfReader.extract_text()`), per page, concatenated in page order.
  Document metadata (title/author/version/category) was kept as a table.
- **HTML:** tags stripped to Markdown headings/lists/tables (abridged to
  15 000 characters for the two delivery reports).
- **TXT:** reproduced verbatim in a code block.

Each converted page names its source file and links to the original on
GitHub. No `.doc`/`.docx` files exist in the repository, and there are no
`doc/` folders inside module directories — the inventory above is complete
(26 PDFs + 2 HTML + 1 TXT).

## What is preserved

- Document identity (title, authors, version, date, category)
- Reading order of the body text (first ~12 000 characters shown per PDF)
- PDF bookmark outlines where present, plus heuristically detected section
  headings

## What is NOT preserved

- Exact headings hierarchy, lists, tables, footnotes, headers/footers
- Figures, screenshots, timing diagrams, schematics and all images
- Fonts, colours, page layout and cross-reference page numbers
- Scanned-image content (none of these PDFs are scanned, so text recall is
  good, but ligatures/hyphenation artefacts remain)

Large references (CAN driver, TP, IL, CANdesc, user manuals) are therefore
**abridged**: the beginning of the text is shown with a truncation marker and
character counts. **Always cite the original PDF**, never the extraction.

## Verification

`python3` + `pypdf` extraction ran over all 26 PDFs without failures; page
counts in the tables above come from the files themselves. Re-run:

```sh
python3 - <<'EOF'
from pypdf import PdfReader
import glob
for pdf in sorted(glob.glob('Doc/**/*.pdf', recursive=True)):
    print(pdf, len(PdfReader(pdf).pages))
EOF
```

[Back to top](#_top)
