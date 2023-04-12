#pragma once
// header file for directions ADT
#include "CookBook.h"


typedef struct Directions {
	char Direction[MAXSTR];
} DIRECTIONS;

void displayDirections(DIRECTIONS);

DIRECTIONS GetDirections(RECIPE);


