<p align="center">
  <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/so_longm.png" alt="42 so_long badge">
</p>

<p align="center">
  <a href="https://www.hive.fi/en/curriculum">Hive (42 School Network)</a> core curriculum project  
</p>
<h1 align="center">so_long</h1>


**so_long** is a basic 2D game built in C using the modern **MLX42** graphics library.
The player explores a tile-based map, collects all items, and reaches the exit.

---

## 🎮 Game Overview

- You control a player (`P`) on a `.ber` map with:
  - `1` — Wall
  - `0` — Floor
  - `C` — Collectible
  - `E` — Exit
  - `P` — Player starting point
- Bonus maps may include `H` for enemies.
- Player moves with `WASD` or arrow keys.
- Game ends after all collectibles are gathered and the player reaches the exit.

---

## 🚀 Core Concepts & Technical Skills

### 🖼️ 1. **2D Rendering with MLX42 (OpenGL-based)**
- Used MLX42's modern API (`mlx_image_t`, `mlx_texture_t`) for rendering
- Rendered tile maps with textures and dynamic updates
- Managed frame-based rendering and redraw logic

### 🧭 2. **Map Parsing & Validation**
- Read and validated `.ber` maps:
  - Rectangular shape, closed by walls
  - Valid characters, and at least one player, exit, and collectible
- Checked reachability of collectibles and exits using pathfinding (e.g., flood fill)

### ⌨️ 3. **Keyboard Input & Event System**
- Integrated `mlx_key_hook()` and `mlx_loop_hook()` for real-time input
- Implemented smooth movement, key debounce, and ESC quit

### 🎯 4. **Game State & Mechanics**
- Collision handling (cannot walk through walls)
- Collected item tracking and win condition check
- Optional: step counter, enemies, animations

### 🧼 5. **Memory & Resource Management**
- Cleanly loaded and destroyed textures/images
- Handled memory leaks and errors using defensive programming
- Gracefully closed MLX windows and freed map memory

---

## 📁 Project Structure

```
so_long/
├── include/
│   └── so_long.h         # Structures & prototypes
├── libft/                # Helper functions
├── src/
│   ├── main.c            # Game entry & initialization
│   ├── check_path.c      # Map parsing and validation
│   ├── validate_map.c    # Map validation
│   ├── parse_map.c       # Map parsing
│   ├── render_game.c     # MLX42 rendering logic
│   ├── play_game.c       # Keyboard input handling
│   ├── game_utils.c      # Helper functions for running game
│   └── map_utils.c       # Helper functions for checking map
├── maps/                 # Sample .ber maps
├── texture/               # PNG textures
├── Makefile
└── README.md
```

---

## ⚙️ How to Build & Play

### 1. Build the game
```bash
make
```

### 3. Run with a map file
```bash
./so_long maps/example1.ber
```

---

## 🎓 Learning Highlights

- Learned to use a modern C graphics library (MLX42)
- Parsed and validated custom level maps
- Built real-time event-driven logic using key hooks and frame loops
- Managed manual memory, textures, and graceful shutdown
- Applied structured design: separation of game logic, rendering, and input

