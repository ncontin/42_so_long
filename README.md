# so_long

A simple 2D game project developed as part of the 42 school curriculum. The goal is to create a basic game where a player collects items and reaches an exit while avoiding obstacles.

## Description

This project is a small 2D game using the MinilibX graphics library. The player's goal is to collect all collectibles and reach the exit using the minimal number of movements.

## Features

- Map parsing from `.ber` files
- Player movement using W, A, S, D keys
- Collectible items
- Exit condition
- Movement counter
- Basic error handling

## Requirements

- MinilibX library
- gcc compiler
- make

## Installation

```bash
git clone https://github.com/ncontin/42_so_long.git
cd so_long
make
```

## Usage

```bash
./so_long maps/map.ber
```

## Map Format

Maps must be constructed with these components:

- `1` for walls
- `0` for empty spaces
- `P` for player starting position
- `C` for collectibles
- `E` for exit

Example map:

```
1111111111
1P00000001
100000C001
100000C001
1000E00001
1111111111
```

## Controls

- `W` or `↑`: Move up
- `S` or `↓`: Move down
- `A` or `←`: Move left
- `D` or `→`: Move right
- `ESC`: Close game
