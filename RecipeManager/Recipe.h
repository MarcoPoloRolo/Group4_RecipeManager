#pragma once
#include "CookBook.h"
#include "Directions.h"
#include "Ingredients.h"


typedef struct Rating {
	int rating;
}RATING;

typedef struct Recipe {
	int Indexnum;
	char* Name;
	RATING rating;
	DIRECTIONS directions;
	INGREDIENTS ingredients;
} RECIPE;

void DisplayRecipe(RECIPE);

RECIPE CreateRecipe(int, char*);