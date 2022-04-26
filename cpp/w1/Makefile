EXE = main
OBJS = main.o Cube.o
CLEAN_RM =

include ../genMake.mk

## notes


g++ -c classfiles
g++ main.cpp *.0 files


stack grows from big to small address
heap grows from small to big address

int *p is a pointer, stores address. &p gives value at address.
int *x = new int ------------ this is used to initialise int at heap memory
at start, it contains some random value. you can set value with *x = value

int &y = *x -------alias to value stored at heap location x
which means y = val2 changes value to val2

important to delete x after using (heap)
or set to nullptr

scoping ----- local and global copies
inside loops it is a local copy of variable looped over if no operations are made
to get to global copy, use &x

class automatically takes default constructor if there is no constructor
if even one constructor is present, class takes that. might lead to segfaults and such.

copy constructor syntax
in classdef:
	classname & operator=(const classname &objname)
in functiondef:
	classname & classname::operstor=(const classname &objname)

variables can be passed around by value, by pointer *, by reference &
by reference is an alias, doesn't create new copy
by pointer can point to alias, in which case no new copy is created
otherwise it will create a copy (CHECK THIS)

custom constructor, copy constructor, assignment constructor
custom destructor -  necessary whenever resources are shared, for example, when classes are used in heap memory