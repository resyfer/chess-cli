#include <iostream>
#include <stdlib.h>
#include <array>
#include <vector>
#include <string>
#include <limits.h>

#define WHITE 0
#define BLACK 1
#define NO_COLOR 2


//Defining CLEAR command for various OSes
#ifdef _WIN32
#define CLEAR system("cls")
#else
#define CLEAR system("clear")
#endif
