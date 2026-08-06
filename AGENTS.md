# Agent Notes: Moonlander QMK

## Moonlander keymap location

The active Moonlander keymap is:

- `keyboards/zsa/moonlander/keymaps/default/keymap.c`

This repo uses the Moonlander revision target. Do not compile the generic `zsa/moonlander` target; use `zsa/moonlander/revb`.

## Build with Nix

From the repository root:

```sh
nix shell nixpkgs#qmk -c qmk compile -kb zsa/moonlander/revb -km default
```

Successful builds produce firmware such as:

- `.build/zsa_moonlander_revb_default.bin`
- `.build/zsa_moonlander_revb_default.hex`
- `./zsa_moonlander_revb_default.bin`

## Flash with Nix

Put the keyboard into bootloader/DFU mode first, then run:

```sh
nix shell nixpkgs#qmk -c qmk flash -kb zsa/moonlander/revb -km default
```

The flash command recompiles before flashing.

## Current bootloader key access

Current layout keeps bootloader accessible in two ways:

1. Hold the **Mouse layer** key, then press the **top-right key**.
   - Mouse layer key is the right-side bottom-row key that taps `Backspace` and holds `Mouse`.
2. Hold the **Magic layer** key, then press a boot key.
   - Magic layer key is the left-side bottom alpha-row `Magic` key.
   - On Magic, top-left/top-right are bootloader keys.

## Nix/QMK Python compatibility note

The current `nixpkgs#qmk` package may run under Python 3.14. This repo needed the local compatibility patch in:

- `lib/python/qmk/math.py`

Use `ast.Constant` rather than removed `ast.Num` there, otherwise QMK can fail with:

```text
AttributeError: module 'ast' has no attribute 'Num'
```
