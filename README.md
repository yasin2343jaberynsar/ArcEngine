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

## Agent Safety System

Arc Engine includes a built-in **Agent** — a system designed to catch common mistakes and help you debug faster.

The Agent:

- **Detects common errors** — like invalid window sizes, negative FPS, or out-of-bounds array access
- **Warns you** — without stopping your game (so you can keep testing)
- **Fixes simple issues automatically** — when it makes sense (e.g., defaulting to 60 FPS if you pass an invalid value)
- **Can be turned off** — when you're ready for production or want to test edge cases

### Why The Agent Exists

Game development is hard. Bugs happen. The Agent is there to:

- **Save you time** — catch mistakes early
- **Reduce crashes** — handle invalid input gracefully
- **Help you learn** — clear warnings that explain what went wrong

### Agent vs Production

The Agent is designed for **development**, not shipping.

> "The Agent isn't the tool that delivers your games. It can help, but it's always recommended to turn it off at the final stages of your project, fix the bugs, and ship a clean product."

### Turning The Agent Off

```c
arc_turn_agent_off();  // Disable Agent
arc_turn_agent_on();   // Re-enable Agent (default)
```

## Built With

Arc Engine is built on top of [Raylib](https://www.raylib.com/), a lightweight and efficient game development library.

A huge thank you to **raysan5** and the entire Raylib team for their incredible work — Arc Engine wouldn't exist without their foundation.

## What Arc Engine Is Not

Arc Engine is **not** a simple wrapper around Raylib.

While Raylib provides the foundation (rendering, input, and window management), Arc Engine adds:

- A **complete game API** with systems for math, strings, hardware detection, and randomness
- A built‑in **Agent** that catches common mistakes and helps you debug
- **7 API styles** (snake_case, camelCase, PascalCase, and more)
- **Optimized algorithms** designed specifically for games
- **Counters** with edit tracking and power operations
- **Hardware-aware features** (OS, GPU, monitor detection)

Raylib is the foundation — Arc Engine is the house built on top of it.

## Quick Example

```c
#include "api.h"

int main() {
    arc_create_game_window(800, 600, "My Game");
    arc_set_fps(60);

    arc_string title = arc_create_string("Arc Engine");
    arc_position pos = arc_create_position(400, 300);

    while (arc_game_running()) {
        BeginDrawing(); // Raylib function (wrapper actively in development)
        EndDrawing(); // Raylib function (wrapper actively in development)
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

### Garbage Collector (In Development)

Arc Engine is getting a built‑in **Garbage Collector** — designed to automatically manage memory for you.

> **Note:** The GC will only manage memory allocated through Arc's own functions (e.g., `arc_create_string()`, `arc_create_sprite()`). It will **not** manage memory allocated with `malloc()` or `calloc()` — you'll still need to free those manually.

**Why a GC in C?**
- No more manual `free()` for Arc objects
- Reduces memory leaks — especially for beginners
- Optional — you can still manage memory manually if you prefer

**Status:** Actively in development — not yet available in the current release.

**Planned release:** v0.0.3

## Version

**v0.0.2.8.5** — Alpha development release.  
The API is actively being built and refined. Everything is subject to change.

License
MIT — free to use, modify, and distribute.
