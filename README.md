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
for linux

```bash
gcc -o main api.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```

for windows 

```bash
gcc -o main.exe api.c -lraylib -lgdi32 -lwinmm -lm -lpthread
```

for MacOS

```bash
gcc -o main api.c -lraylib -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
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

Benchmarks will be updated as the engine matures.

## Will Arc Have a GUI Editor? And Will It Work Without a GUI?

### GUI Editor

**Yes** — a GUI editor is planned for Arc Engine.

It will be a separate tool built with **Electron** or a similar web‑based framework, designed to work alongside the engine. The editor will allow you to:

- Place and arrange objects visually
- Edit properties in real time
- Build levels and scenes without writing code

> **Note:** The editor is a **future feature**. The current focus is on stabilising the core engine and API.

### Working Without a GUI (Headless Mode)

**Yes** — Arc Engine is designed to run without a graphical interface.

This is useful for:

- **Server‑side game logic** — running game simulations on a remote server
- **Automated testing** — running tests without a display
- **Dedicated servers** — hosting multiplayer games without a GPU or window

> **Important:** Headless mode is planned but not yet implemented. It will be introduced in a future release.

### Honest Note

Arc is still in **active development**. Some functions may change, and performance will improve over time.  
The benchmarks above reflect the **current state** of the engine — not its final form.

Why No Docs Yet?
Documentation is coming soon — but the API is still evolving. Writing docs now would mean rewriting them as features change. Once the API stabilizes, full documentation will be released.

In the meantime, The api.c file contains all the functions and their usage.



## 🚧 What's Coming

### Garbage Collector (In Development)

Arc Engine is getting a built‑in **Garbage Collector (GC)** — designed to automatically manage memory for you.

#### How It Works

The GC will track memory allocated through Arc's own functions (`arc_create_string()`, `arc_create_sprite()`, etc.) and through a new function — **`arc_allocate()`** — and automatically free it when it's no longer in use.

#### When to Use It (And When Not To)

The GC is great for:

- Long‑lived objects (players, enemies, persistent game data)
- Assets that are loaded once and used throughout the game
- Situations where manual memory management is tedious and error‑prone

However, the GC is **not** recommended for:

- Short‑lived objects (e.g., creating a string, using it immediately, and freeing it)
- High‑frequency allocations inside a tight loop
- Scenarios where you need memory to be freed *exactly* when you say so

> **Note:** The GC runs periodically — not instantly. If you create and destroy objects every frame, the GC might not keep up, and you'll see memory usage grow until the next collection cycle. For these cases, manual `malloc()`/`free()` is still the better choice.

#### What the GC Covers

| What the GC Covers | What It Doesn't |
|--------------------|-----------------|
| `arc_create_string()` | `malloc()` |
| `arc_create_sprite()` | `calloc()` |
| `arc_create_counter()` | `realloc()` |
| `arc_allocate()` | Manual `free()` still needed for these |

#### The New `arc_allocate()` Function

A new function — **`arc_allocate()`** — will be introduced alongside the GC. Any memory allocated with `arc_allocate()` will be tracked and automatically freed by the GC.

```c
void* ptr = arc_allocate(1024);  // Allocated and tracked by GC
// No need to free — the GC will handle it
```

This makes it easier to use dynamic memory without worrying about manual cleanup — but as noted above, it's not suitable for all use cases.

#### GC + Agent Integration

The Agent will also warn you if:

- The GC is struggling to keep up with allocations
- You're allocating memory in a tight loop without freeing
- Memory usage is growing unexpectedly

---

### Objects (Coming Soon)

Alongside the GC, a new **Objects** system is being developed.

#### What It Will Do

Objects will provide a higher‑level way to manage rendering — allowing you to create, update, and draw objects without manually handling textures, positions, and drawing calls every frame.

#### Key Features (Planned)

- Create objects with a single function call
- Automatically manage sprite loading and unloading
- Built‑in position, rotation, and scaling
- Layer support for draw order
- Optional GC integration — objects can be automatically freed when no longer needed

#### Why This Matters

Objects will simplify common 2D game tasks:

```c
// Instead of manually loading textures and drawing every frame:
arc_object player = arc_create_object("player.png", 100, 200);
arc_draw_object(&player);
```

Objects will also integrate with the GC — so when an object is no longer referenced, it will be cleaned up automatically.

## CamelCase API (Coming in v0.0.3)

v0.0.3 will introduce the **CamelCase API** — a new variant of the Arc Engine API that uses `camelCase` naming conventions alongside the existing `snake_case`.

```c
// snake_case (current)
arc_create_game_window(800, 600, "My Game");

// camelCase (coming in v0.0.3)
arcCreateGameWindow(800, 600, "My Game");
```

#### Status

Both features are actively in development and are planned for **v0.0.3**.

## Version

**v0.0.2.8.5** — Alpha development release.  
The API is actively being built and refined. Everything is subject to change.

## Why I'm Building Arc Engine

Millions of developers still enjoy writing C — the language that built the world.

I'm one of them. I love C for its simplicity, transparency, and control. But when I looked for a 2D game engine that was:

- Written in **pure C**
- **Fast** and **lightweight**
- **Transparent** — no hidden magic
- **Easy to use** — even for beginners

…I couldn't find one.

So I built Arc Engine.

Arc is for **me** — and for anyone who loves C. But it's also designed to be **approachable**. The API is clean, the Agent catches common mistakes, and the documentation (when it's ready) will be beginner‑friendly.

You don't need to be a C expert to use Arc. You just need to be willing to learn.

License
MIT — free to use, modify, and distribute.
