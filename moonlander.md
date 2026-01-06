# Moonlander Default Keymap Reference

This doc summarizes the key layout defined in `keyboards/zsa/moonlander/keymaps/default/keymap.c`. Every layer keeps the Moonlander ANSI geometry while mapping the left side to Dvorak-style typing with modifiers, combos, and a number/symbol layer that mirror the same physical positions.

## Base Layer (Layer 0)
- **Top row:** `HYPR(KC_1)` through `HYPR(KC_0)` on the number keys so each tap sends Hyper+digit, while the outer columns keep arrow navigation and bracket access (`keymap.c:25-31`).
- **Home row:** Dvorak characters plus Hyper-related combos: `MT(MOD_LCTL, OSL(HYPER_LAYER))` on the old backspace key makes a tap jump into the Hyper layer and holding still sends Control; `MT(MOD_LALT, KC_SCLN)`/`MT(MOD_LGUI, KC_Q)`/`MT(MOD_RGUI, KC_V)`/`MT(MOD_RALT, KC_Z)` keep the previous home-row mods in place (`keymap.c:26-30`).
- **Layer toggles:** `TG(SYMBOL_LAYER)` on the split space row toggles the symbol layer, `LT(MOUSE_LAYER, KC_S)` holds for the mouse layer, and `LT(NUMBER_LAYER, KC_RIGHT)` lets the right arrow key switch momentarily to the number layer (`keymap.c:27-30`).

## Auxiliary Layers
- **Symbol Layer (Layer 1):** Classic function keys, bracket/arc combos, RGB controls, and media for quick access while `MO(SYMBOL_LAYER)` on the home row holds to stay there (`keymap.c:33-40`).
- **Mouse Layer (Layer 2):** Mouse acceleration, buttons, and media that mirror the original Moonlander mouse layer plus some extra audio controls (`keymap.c:41-47`).
- **Number Layer (Layer 3):** Mirrors the alphabet positions from the base layer with digits `7/8/9`, `4/5/6`, `1/2/3`, and `0/.` plus symbols layered around them (`! @ # $ % ^`, `+ - = _`, `? | * &`). All other keys are transparent to let the base layer bleed through (`keymap.c:49-55`).
- **Hyper Layer (Layer 4):** Activated by tapping the modified backspace (now `OSL(HYPER_LAYER)`), this layer emits `HYPR(KC_...)` for every key in the Dvorak arrangement so you can press any letter with Hyper held without losing your layout orientation (`keymap.c:57-64`).

## Combos
- Escape/backspace combos: `E+U` sends `KC_ESCAPE`, `H+T` sends `KC_BSPC` so the right-hand home row is still useful without reaching for the corners (`keymap.c:67-103`).
- Additional combos mirror the symbol layer: `H+C` ↦ `/`, `. + U` ↦ `\`, `.`+`P` ↦ `[`, `G+C` ↦ `]`, `U+I` ↦ `(`, `D+H` ↦ `)`, `K+X` ↦ `{`, `B+M` ↦ `}` (`keymap.c:67-103`).

## SM-TD Integration
- The `on_smtd_action` handler pulls in `sm_td.h` so `Q`, `;`, `V`, and `Z` keep their dual-role modifiers via `SMTD_MT(...)` definitions, matching the MT patterns already on the physical keys for consistent tap-vs-hold behavior (`keymap.c:1-115`).

Keep this document as the reference for the major layers/combos; the actual layout source includes extra RGB controls, mouse macros, and RGB color functions below the combined section if you need more detail.
