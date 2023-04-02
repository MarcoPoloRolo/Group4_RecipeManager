#pragma once
// header file for ingredient ADT
#include "CookBook.h"


typedef struct Ingredients {
	int Ingscount;
	char* Ingredient;
} INGREDIENTS;

void displayIngredients(INGREDIENTS);

INGREDIENTS GetIngredient(RECIPE);


