#pragma once
#define MAX_RECIPE_COUNT 50
#include "CookBook.h"
#include "Directions.h"
#include "Ingredients.h"


typedef struct Rating {
	int rating;
}RATING;

typedef struct Recipe {
	int Indexnum;
	char Name;
	RATING rating;
	DIRECTIONS directions[MAX_COUNT];
	INGREDIENTS ingredients[MAX_COUNT];
} RECIPE;

RECIPE CreateRecipe(int, char*);	// 1)

void DeleteRecipe(RECIPE);			// 2)

void UpdateRecipe(RECIPE);			// 3)

void DisplayRecipe(int);			// 4)

void DisplayMultipleRecipes(void);	// 5)

void DisplayAllRecipes(void);		// 6)

RECIPE SeerchForRecipe(char*);		// 7)

RECIPE RateRecipe(RECIPE);			// 8)

bool WriteRecipeToFile(RECIPE);

RECIPE ReadRecipeFromFile(FILE*);

void converttolowercase(char*);