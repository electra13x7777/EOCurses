# EOCBIBLE
## EOCurses Program Structure/Design Philosophy
###### Author: Alex Barney

### Preface
This document will detail the general design philosophy of the codebase. For the most part, the codebase follows a data oriented approach to its design. I will go more into specific design details below.

### Current Data Structures
Current data structures found in the codebase:

* enemy - contains members of an enemy/relevant state
* equip - contains stats, name, type, and classes that can equip it
* class - contains stats, equipment, state info
	* equipment - sub structure used to contain a class' equipment
* party - contains 5 class structures
	* pmap - sub structure used to contain a class and its position

### Data Structures and Corresponding Files
Each main struct is prototyped in a header file of the same name (EX: struct enemy is prototyped in enemy.h). Header files generally will follow this format:

* struct prototypes
* enumerations
* function prototypes

### Functions and Data Structures
Functions prototyped in files that also prototype structs will generally be as follows:

* initialization function
* file parsing function
* deallocation function
* misc. testing functions
* print function
* other functions specific to the needs of a struct

Functions and data structures are designed to be self contained. The idea is that a structure's member data and state can only be mutated by its own related functions. For example, a class struct can contain members of an equip struct, but a class struct cannot mutate any data contained in the equip struct. Let's also examine the relation between the equip struct and the class struct. Equip structs are used to update the stat values of a class struct. The equip struct should have absolutely no idea what a class structure is. Updating a class structure's state should be solely the resposability of the functions that mutate a class structure. This avoids problems with unintended state mutation and data obfuscation. Clear boundries are errected so that there is no ambiguity as far as where data can and cannot be mutated.

### Standard Functions

Initialization Functions: A Data Structure will be allocated on the heap and given default values if necessary.

File Parsing Functions: Rather than have one big generic parser that handles all of the program's parsing, each data structure defining file should be able parse its own struct.

Deallocation Functions: Free the structure as well as any members that require deallocation. These may be nested in other structure's functions in order to prevent direct state manipulation from unrelated funtions and structures.

### Dependencies
EOCurses has a few libraries that it depends on:

   Library    |    GCC flag
------------- | --------------
Math Library  | -lm
POSIX Threads | -lpthread
OpenAL        | -lopenal
NCURSES       | -lncurses

Building the binaries requires that you have these on your local machine.

### Style Guide

##### Variables

```c
int an_integer;
char *str;
struct name_of_struct *n;

```

##### Loops

```c
while(condition)
{

}

for(cond1; cond2; cond3)
{

}

do
{

}
while(condition);
```

##### Functions

```c
// Function: name_of_func
// Return: return_type
// Description: brief description of function
return_type name_of_func(type param1)
{
	// STUFF
}
```

##### Structs/Enums

```c
struct name_of_struct
{
	type member;
	type *another_member;
};

enum
{
	FIRST_VAL,
	SECOND_VAL = 1,
	Thirdval_e
};
```
