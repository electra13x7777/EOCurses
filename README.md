# EOCurses
## Etrian Odyssey port to curses

### Development
* Game functionality is still under development so included is binary with a test suite to test the current functionality of EOCurses *pkg/eoctest*

### Binary
* Binary runs a simple battle simulation as a test of current calculation algorithms

### Build From Source
* Makefile included to build binary in *pkg/* from files in *src/*
* run *make* in main repo folder

### Features

#### Developed (What is currently working but may be reworked)
* *attack* - simple attack algorithm (not final)
* *enemy* - definition of an enemy
* *equip* - definition of in game equipment
* *class* - definition of the 9 classes in the game
* *party* - defines the structure of a 5 class party in the game (free is broken)

#### Future Goals
* *READONLY FILES* - need to be updated to have full parity with the data from the game
* Fully fleshed out game logic needs to be implemented
* Formal definition of Items
* Define how the package will parse a dungeon map (most likely a grid of 0s for travelable tiles and 1s for walls)
* *ASCII Graphics in Curses* - create something similar to the style of the virtual battler in SMTII
* Finish the full curses implementation
