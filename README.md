<div align="center">
  <picture>
    <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/solongm.png" alt="42 so_long badge">
  </picture>

  <p><a href="https://www.hive.fi/en/curriculum">Hive (42 School Network)</a> core curriculum project</p>
  <h1>so_long</h1>
</div>

**so_long** is a basic 2D top-down game built in C using the MiniLibX graphics library.  
The player navigates through a map, collects items, and exits when all collectibles are gathered.

---

## 🎮 Game Overview

- You control a player (`P`) on a map made of:
  - `1` — Wall (non-walkable)
  - `0` — Empty floor (walkable)
  - `C` — Collectibles (must collect all)
  - `E` — Exit (accessible only after collecting all `C`)
  - Bonus: `H` — Enemy (causes game over if touched)
- Movement is controlled via keyboard (`W`, `A`, `S`, `D` or arrows)
- Player step count is displayed in the terminal
- Game ends when the player reaches the exit after collecting all items

---

## 🚀 Core Concepts & Technical Skills

### 📦 1. **2D Game Rendering with MiniLibX**
- Created a window and rendered tile-based maps using `.xpm` images
- Implemented image drawing via `mlx_put_image_to_window()`
- Loaded assets (player, walls, items) dynamically

### 🧭 2. **Map Parsing & Validation**
- Parsed `.ber` map files and validated:
  - Enclosed by walls
  - Contains exactly 1 player, at least 1 collectible, and 1 exit
  - All required tiles are reachable using flood-fill path validation

### 🎯 3. **Keyboard Input & Event Loop**
- Used `mlx_hook()` to bind keys and window events
- Real-time movement and game state update loop
- Used keycodes to track directional movement and ESC to exit

### 🚧 4. **Game Logic & Mechanics**
- Step counter display in terminal
- Collision detection against walls
- Win/lose conditions
- Bonus: animated sprites, patrol enemies, or game over state

### 💡 5. **Memory & Resource Management**
- Manual memory handling: map allocation and cleanup
- Closed file descriptors, destroyed MLX images and windows
- Error handling with clear messages

---

## 📁 Project Structure

```
so_long/
├── include/
│   └── so_long.h         # Structs & function prototypes
├── src/
│   ├── main.c            # Game initialization & loop
│   ├── map_parser.c      # Map reading and validation
│   ├── render.c          # Drawing the map and assets
│   ├── events.c          # Keyboard input and actions
│   └── utils.c           # Helper and memory functions
├── maps/                 # Sample .ber maps
├── assets/               # XPM textures (player, wall, collectible, etc.)
├── Makefile
└── README.md
```

---

## ⚙️ How to Build & Play

### 🧰 1. Install dependencies (if needed)
- **Linux:** Install MiniLibX and X11 libraries (`libxext-dev`, `libx11-dev`, `zlib1g-dev`)
- **macOS:** Provided by 42’s mlx or linked against AppKit/OpenGL

### 🔨 2. Compile
```bash
make        # builds mandatory version
make bonus  # builds bonus (if available)
```

### 🕹️ 3. Launch the game
```bash
./so_long maps/map.ber
```

---

## 🎓 Learning Highlights

- 🖼️ Learned to build a **2D tile-based rendering engine** using low-level graphics API (MiniLibX)
- 🔎 Gained experience in **file parsing and data validation** (custom map format)
- 🎮 Implemented **real-time input handling** and **game loop logic**
- 🧱 Built **collision and event systems** to handle interactive game objects
- 🧠 Managed manual memory allocation, cleanup, and modular architecture in C

---

**Developed by [Your Name]**  
[GitHub](https://github.com/Lin-0096)
