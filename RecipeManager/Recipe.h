#pragma once
#include "CookBook.h"
#include "Directions.h"
#include "Ingredients.h"


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

RECIPE AddNewRecipe(RECIPE);			// 1)

RECIPE DeleteRecipe(RECIPE);			// 2)

RECIPE UpdateRecipe(RECIPE);			// 3)

void DisplayRecipe(RECIPE);			// 4)

void DisplayMultipleRecipes(void);	// 5)

void DisplayAllRecipes(void);		// 6)

void RateRecipe(RECIPE*, int);			// 8)

bool SetRecipeIngredient(RECIPE*, char*);

bool SetRecipeDirection(RECIPE*, char*);

void SetRecipeName(RECIPE*, char*);

void removenewline(char*);

bool WriteRecipeToFile(RECIPE);

RECIPE ReadRecipeFromFile(FILE*);

void converttolowercase(char*);