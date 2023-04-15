#pragma once
#include "CookBook.h"
#include "Directions.h"
#include "Ingredients.h"
// prog 71985 - Group 4 (Julian, Marko and Luke) - Winter 2023 - Group assignment: Recipe manager

typedef struct Rating {
	int rating;
}RATING;

typedef struct Recipe {
	int Indexnum;
	char Name[MAXSTR];
	int Ingcount;
	int Dircount;
	RATING rating;
	DIRECTIONS directions[MAX_COUNT];
	INGREDIENTS ingredients[MAX_COUNT];
} RECIPE;

RECIPE CreateNewRecipe(int);

void DisplayRecipe(RECIPE);			// 4)

void DisplayRecipes(RECIPE*, int, int);		// 6)

void RateRecipe(RECIPE*, int);			// 8)

bool SetRecipeIngredient(RECIPE*, char*);

bool SetRecipeDirection(RECIPE*, char*);

void SetRecipeName(RECIPE*, char*);

void removenewline(char*);

bool WriteRecipeToFile(RECIPE);

RECIPE ReadRecipeFromFile(FILE*);

void converttolowercase(char*);

void PrintRating(int);