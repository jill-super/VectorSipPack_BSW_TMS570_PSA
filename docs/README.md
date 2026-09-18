# Astro docs site — dependency & build notes

This folder (`docs/`) is a standalone Astro +
Starlight site. It is **not** part of the
embedded firmware build.

## Develop

```sh
cd docs
npm ci        # or: npm install
npm run dev   # local preview; the dev server prints the URL
```

## Build (same as CI)

```sh
cd docs
npm ci
npm run build # -> docs/dist/
npm run preview
```

## Deploy

Pushes to `main` trigger `.github/workflows/pages.yml`, which builds
`docs/` and deploys `docs/dist` to GitHub Pages (project site
`/BSW_TMS570_PSA/`).

## Content layout

- `src/content/docs/` — all Markdown pages (Starlight front matter:
  `title`, `description`, optional `sidebar`).
- `src/content/docs/general/**` — Markdown converted from the
  `Doc/*.pdf` / `*.html` / `*.txt` delivery documents.
- `src/content/docs/sip/**` — Vector SIP 05.00.17 module pages.
- `src/assets/` — logo and images.
- `public/` — static files copied verbatim to `dist/`.
