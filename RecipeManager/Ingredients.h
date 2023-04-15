#pragma once
// header file for ingredient ADT
#include "CookBook.h"
// prog 71985 - Group 4 (Julian, Marko and Luke) - Winter 2023 - Group assignment: Recipe manager

typedef struct Ingredients {
	char Ingredient[MAXSTR];
} INGREDIENTS;

void displayIngredients(INGREDIENTS);

INGREDIENTS GetIngredient(RECIPE);


