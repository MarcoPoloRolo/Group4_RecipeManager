#pragma once
// header file for directions ADT
#include "CookBook.h"
// prog 71985 - Group 4 (Julian, Marko and Luke) - Winter 2023 - Group assignment: Recipe manager

typedef struct Directions {
	char Direction[MAXSTR];
} DIRECTIONS;

void displayDirections(DIRECTIONS);

DIRECTIONS GetDirections(RECIPE);


