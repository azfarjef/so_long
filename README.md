# So_Long

This project aims to create a small 2D game using the C programming language, where a hero collects any valuables before leaving the place. The project uses the miniLibX library for graphics.

## Installation
The project is optimized for WSL2. You can run this on other platform, just edit the `Makefile` in the root directory by following this [guide](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html).

To install the project, clone the repository. Follow this [guide](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#getting-a-screen-on-windows-10-wsl2) to get a screen in WSL2 and navigate to the project directory. Then run the following command in your terminal to compile the miniLibX library:
```bash
cd mlx_linux
make
```
Now go to the root directory and compile the program:
```bash
cd ..
make
```
This will compile the program and create an executable called `so_long`.

## Usage

To run the program, execute the following command in your terminal:
```bash
./so_long tests/6classic2.ber
```
Here, `tests/6classic2.ber` is the path to the map description file. You can use any valid .ber file as input.

The player's goal is to collect all collectibles present on the map and then escape with minimal movement. At every move, the current number of movements is displayed in the shell. The player can move up, down, left, and right using the W, A, S, and D keys respectively.

Pressing the ESC key will close the window and quit the program cleanly, and clicking on the red cross on the window's frame will also close the window and quit the program.

## Demo

![output2](https://user-images.githubusercontent.com/73651474/231317654-e8ff4b8e-2903-4c9e-93d0-1b2ae3d60005.gif)


## Map Format

The map will be constructed with 3 components: walls, collectibles, and free space. The map must be composed of only 5 possible characters:

- 0 for an empty space
- 1 for a wall
- C for a collectible
- E for map exit
- P for the player's starting position.

The map must have at least one exit, one collectible, and one starting position. If any misconfiguration of any kind is encountered in the file, the program will exit properly and return "Error\n" followed by an explicit error message. See the [test](https://github.com/azfarjef/so_long/tree/main/tests) directory for map samples.


## Credit
This project was completed as part of the curriculum of the Ecole 42 program. The instructions for the project were provided by the school.
