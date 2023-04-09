# so_long

Small 2D game with basic gameplay.

## How it works

1. The player’s have to collect all collectibles on the map without being caught by the enemies, then he can escape by the door.

2. The player move with WASD and close the game by pressing ESC.

3. Components of map:
   - Player - 'P'
   - Exit - 'E'
   - Wall - '1'
   - Free space - '0'
   - Enemy - 'C' (bonus part)

4. Some map examples are stored in `/maps` folder. Feel free to change them (`.ber` format is required)!

## How to launch the game

1. To compile the program :

   ```sh
   $ make
   ```

   With bonus :

   ```sh
   $ make bonus
   ```
   
2. To start the game :

   ```sh
   $ ./so_long [path_to_valid_map]
   ```
