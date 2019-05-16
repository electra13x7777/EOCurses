# EOCurses
## Etrian Odyssey port to curses

### Etrian Odyssey Curses
EOCurses aims to be a near 1:1 port of Etrian Odyssey for Nintendo DS to Curses in the UNIX shell.

### Development
* Simple curses based battle simulation with music is now playable by running *pkg/eocurses*
* Game functionality is still under development so included is binary with a test suite to test the current functionality of EOCurses *pkg/eoctest*

### Binaries
Files found in the *pkg* directory use *.eoc* as a filetype and currently can be run like any binary built from a GCC toolchain: `$ ./NAME_OF_FILE.eoc`
* *eocurses.eoc*: Runs a simple battle simulation in curses with battle music
* *eoctest.eoc*: Interactive test suite

### Build From Source
* Makefile included to build binary in *pkg/* from files in *src/*
* Run `make` in main repo folder
* Build completion should print `************* EOCurses Build Successful *************`

*NOTE*: All commits of EOCurses should build binaries correctly however if this not the case please make a new [issue](https://github.com/electra13x7777/EOCurses/issues) and I will make sure that any problems are resolved as soon as I can

### Test Procedure
EOCurses includes a binary for testing purposes: *pkg/eoctest.eoc*. Running the file will provide you with a series of tests to evaluate the current functionality of the codebase.
* Run the binary with `$ ./eoctest.eoc`
* Enter the integer corresponding to the test you would like to preform
* Check memory allocation with `$ valgrind ./eoctest.eoc`. For this run a single test and then close the program by entering *0* when the test finishes
* `test_all()` - Included in the testing program is a function that preforms all relevant tests and returns whether they pass or fail as well as the individual runtimes of each test. It will print out a lot of information from each test so a good idea when running this is to redirect the program output to a file. Redirecting terminal output will not print out to the terminal so make sure you run it like so:

```
$ ./eoctest.eoc > testallout.txt
14
0
```

*NOTE*: If a test results in a *SEGFAULT* please make a new [issue](https://github.com/electra13x7777/EOCurses/issues) so that I can figure out the problem and get it fixed. If you have relevant test output make sure to include that too.

### Documentation
Codebase design and documentation can be found [here](https://github.com/electra13x7777/EOCurses/blob/master/src/utils/EOCBIBLE.md). If you are interested in contributing code please consult this markdown file since it goes through how the program is structured.

### Features

#### Developed (What is currently working but may be reworked)
* *attack* - simple attack algorithm (not final)
* *enemy* - definition of an enemy
* *equip* - definition of in game equipment
* *class* - definition of the 9 classes in the game (free is broken)
* *party* - defines the structure of a 5 class party in the game (free is broken)
* *class skill tree* - skill point investment logic is almost fully implemented
* *skills* - function definitions of all the skills are very early in development

#### Future Goals
* *READONLY FILES* - need to be updated to have full parity with the data from the game
* Fully fleshed out game logic needs to be implemented
* Formal definition of Items
* Define how the package will parse a dungeon map (most likely a grid of 0s for travelable tiles and 1s for walls)
* *ASCII Graphics in Curses* - create something similar to the style of the virtual battler in SMTII
* Finish the full curses implementation

### Screencaps

#### Battle Graphics
![Battle](https://i.imgur.com/cqixGQ5.png)

#### Test Output
![Test](https://i.imgur.com/GhUwuy4.png)

### Contact Information
[Website](http://www.alexbarney.xyz/)

[Email](mailto:alex@alexbarney.xyz)

[Stream](https://www.twitch.tv/electra13x7777)

### Author's Note
EOCurses is in no way affiliated with Atlus. No source code is taken from the original game. This is a fan creation developed out of appreciation for the original game. This is 100% free software and no profit will be generated directly from EOCurses. Please support the official release.
