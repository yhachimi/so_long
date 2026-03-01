# 🎮 so_long – 1337 Project

## 👤 Author

**Login:** yhachimi
**School:** 1337 Coding School

---

## 📖 Description

**so_long** is a 2D dungeon RPG-style game developed in C as part of the 1337 curriculum.

The game is built using the MiniLibX graphics library and focuses on:

* Window & event management
* Map parsing & validation
* 2D rendering
* Game logic implementation
* Animations (Bonus)

You explore a dungeon, collect items, avoid enemies, and reach the exit to win.

---

# 🗺️ Mandatory Part

## 🎯 Objective

* Collect all collectibles (`C`)
* Reach the exit (`E`)
* Avoid walls (`1`)

The game only allows exiting after collecting all collectibles.

---

## 🧱 Map Rules

The map must:

* Be rectangular
* Be surrounded by walls (`1`)
* Contain:

  * `1` → Wall
  * `0` → Empty space
  * `P` → Player
  * `C` → Collectible
  * `E` → Exit
* Have at least:

  * 1 Player
  * 1 Exit
  * 1 Collectible
* Be solvable (valid path required)

Example:

```text
111111
1P0C01
100001
1C0E11
111111
```

---

# ⭐ Bonus Part

## 👾 Enemy System

In the bonus version, a new map element is introduced:

* `M` → Enemy (Slime)

### 🟢 Slime Enemy

The enemy is a **Slime monster** that:

* Appears when `M` is present in the map
* Has animated movement
* Attacks the player
* Ends the game if it hits the player

---

## 🎞️ Animations

### 🔄 Idle Animation

The slime has an animated idle effect:

* Moves visually **up and down**
* Creates a floating/sliding slime effect
* Frame-based animation using multiple textures

### 💥 Attack Animation

When the slime attacks:

* A **bomb attack animated effect** is displayed
* Explosion-style frames are shown
* If the player is hit → Game Over

---

# 🎮 Controls

* `W` / `↑` → Move Up
* `S` / `↓` → Move Down
* `A` / `←` → Move Left
* `D` / `→` → Move Right
* `ESC` → Exit Game

---

# 🛠️ Technologies Used

* C Language
* MiniLibX
* Makefile
* Linux / macOS

---

# 🚀 Compilation

```bash
make
```

Clean object files:

```bash
make clean
```

Remove everything:

```bash
make fclean
```

Recompile:

```bash
make re
```

Compile BONUS PART:

```bash
make bonus
```


# ▶️ Usage

```bash
./so_long map.ber
```

Example:

```bash
./so_long maps/dungeon_bonus.ber
```

---

# 🧠 What I Learned

* 2D game rendering with MiniLibX
* Frame-based sprite animation
* Enemy AI basics
* Event loops & timing control
* Memory management
* Map validation & path checking
* Game over & win conditions

---

# 🏁 Project Status

✅ Mandatory part completed
✅ Bonus part completed (Enemy + Animation + Attack Effect)

---
