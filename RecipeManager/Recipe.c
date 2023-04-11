#include "Recipe.h"

RECIPE CreateRecipe(int, char*) //Luke's function
{

}

void DeleteRecipe(RECIPE) //Luke's function
{

}

void UpdateRecipe(RECIPE) //Luke's function
{

}

void DisplayRecipe(int recipeIndex) //Marko does all display functions
{

}

//I think Julian is doing both search and rate a recipe

bool WriteRecipeToFile(RECIPE r)
{

}

RECIPE ReadRecipeFromFile(FILE* fp)
{

}

void converttolowercase(char *input)
{
	for (int i = 0; i < strlen(input); i++)
	{
		input[i] = tolower(input[i]);
	}
}

