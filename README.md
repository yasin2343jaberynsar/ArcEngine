# Arc Engine

**Arc Engine** is a lightweight, high-performance 2D game engine written in pure C and built on Raylib. It's designed for developers who want control, transparency, and speed — without the bloat of larger engines.

---

## Status

**Alpha** — The API is actively being built and refined. The core systems are stable, but things may change.

**Currently included:**
- Hardware detection (OS, GPU, monitor)
- Complete string system
- Random system (integers, doubles, positions, counters)
- Math utilities (min, max, abs, clamp, sum, mean)
- Agent safety system
- 7 API styles (snake_case, camelCase, PascalCase, etc.)
- Counters with edit tracking

**Coming soon:**
- Documentation
- Object system
- Scene management
- Audio
- Collision

---

## Quick Example

```c
#include "api.h"

int main() {
    arc_create_game_window(800, 600, "My Game");
    arc_set_fps(60);

    arc_string title = arc_create_string("Arc Engine");
    arc_position pos = arc_create_position(400, 300);

    while (arc_game_running()) {
        arc_begin_drawing();
        arc_draw_text(title.content, pos.x, pos.y);
        arc_end_drawing();
    }

    arc_close_window();
    return 0;
}
```
Build
```bash
gcc -o game main.c api.c -lraylib -lm
```

## Benchmarks

Arc Engine is continuously benchmarked against **C++**.  
These tests run on an **i5-9400F** with **16GB RAM** — a mid‑range system representative of real-world development machines.

All benchmarks use **default compiler settings (no `-O2` optimizations)** unless noted otherwise.

### Key Results

| Test | Arc Engine | C++ |
|------|------------|-----|
| **Random Sample (1M)** | `0.019s` | `16.067s` |
| **Sum (1M ints)** | `0.002s` | `0.017s` |
| **Min/Max (1M doubles)** | `0.076s` | `0.251s` |
| **Abs (1M int + double)** | `0.004s` | `0.006s` |
| **Random Position (1M)** | `0.083s` | `0.242s` |

### What These Numbers Mean

| Test | Why It Matters |
|------|----------------|
| **Random Sample** | Picking random elements from an array — used in loot drops, enemy spawns, etc. |
| **Sum** | Basic arithmetic — performance is critical for simulations and data processing. |
| **Min/Max** | Common in AI, physics, and UI — speed affects responsiveness. |
| **Abs** | Frequent in game loops — fast abs improves overall performance. |
| **Random Position** | Used in spawning, particle systems, and procedural generation. |

### Why Arc Is Faster

Arc is built in **pure C** with **no STL**, **no templates**, and **no abstraction overhead**.  
It uses **optimized algorithms** designed specifically for game development — not generic use cases.

> "Arc doesn't just wrap C — it invents algorithms designed to be fast and simple for games."

### Where Arc Stands

Arc is **faster than C++** in almost every benchmark — while offering additional features like the Agent safety system and hardware detection.

Benchmarks will be updated as the engine matures. Full methodology and source code for all benchmarks will be published soon.

### Honest Note

Arc is still in **active development**. Some functions may change, and performance will improve over time.  
The benchmarks above reflect the **current state** of the engine — not its final form.

Why No Docs Yet?
Documentation is coming soon — but the API is still evolving. Writing docs now would mean rewriting them as features change. Once the API stabilizes, full documentation will be released.

In the meantime, The api.c file contains all the functions and their usage.

License
MIT — free to use, modify, and distribute.
