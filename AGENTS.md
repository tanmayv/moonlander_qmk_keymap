# Agent Notes: Moonlander QMK

## Moonlander keymap location

The active Moonlander keymap is:

- `keyboards/zsa/moonlander/keymaps/default/keymap.c`

This repo uses the Moonlander revision target. Do not compile the generic
`zsa/moonlander` target; use `zsa/moonlander/reva`.

## This physical board is reva (important)

The actual hardware here is the **reva** revision, NOT revb. Confirmed by:

- DFU bootloader enumerates as the STM32 built-in ROM DFU `0483:df11`
  (STMicroelectronics), not the ZSA custom bootloader `3297:2003` that revb
  uses.
- DFU flash map reports `@Internal Flash /0x08000000/128*0002Kg` — the full
  128 KB from `0x08000000` with no reserved bootloader region. revb reserves
  the first 8 KB and links firmware at `0x08002000`.

Symptom if flashed with the wrong (revb) target: it works immediately after
flashing (because `dfu-util ...:leave` jumps directly to `0x08002000`), but on
any power cycle the CPU boots from `0x08000000` (empty on this board) and the
keyboard is dead until you reset + reflash. Use `reva` and this does not happen.

Note: the USB PID reported by the running firmware (e.g. `0x1972`) reflects the
firmware that was flashed, not the hardware — do not use it to identify the
revision. Identify the revision from the DFU bootloader descriptor instead.

## Build with Nix

From the repository root:

```sh
nix shell nixpkgs#qmk -c qmk compile -kb zsa/moonlander/reva -km default
```

Successful builds produce firmware such as:

- `.build/zsa_moonlander_reva_default.bin`
- `.build/zsa_moonlander_reva_default.hex`
- `./zsa_moonlander_reva_default.bin`

## Flash with Nix

Put the keyboard into bootloader/DFU mode first, then run:

```sh
nix shell nixpkgs#qmk -c qmk flash -kb zsa/moonlander/reva -km default
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
