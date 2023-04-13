#include "Recipe.h"

RECIPE CreateNewRecipe(int index)
{
	RECIPE r;
	r.Indexnum = index;
	SetRecipeName(&r, "EMPTY");
	r.Dircount = 0;
	r.Ingcount = 0;
	r.rating.rating = 0;

	return r;
}


void DeleteRecipe(RECIPE) //Luke's function
{

}

void UpdateRecipe(RECIPE) //Luke's function
{

}

void DisplayRecipe(RECIPE) //Marko does all display functions
{

}

//I think Julian is doing both search and rate a recipe

void RateRecipe(RECIPE *r, int rating)
{
	r->rating.rating = rating;
}

void removenewline(char* buffer) // removes newline to prevent errors reading and displaying data
{
	for (int i = 0; i < strlen(buffer); i++)
		if (buffer[i] == '\n')
			buffer[i] = '\0';
}

bool WriteRecipeToFile(RECIPE r)
{
	FILE* fp = fopen(FILENAME, "a");
	if (!fp)
		return false; // If file error occurs, return false
	fprintf(fp, "\n%d\n%d\n%d\n%d\n%s", r.Indexnum, r.Ingcount, r.Dircount, r.rating.rating, r.Name);
	for (int i = 0; i < r.Ingcount; i++)
	{
		fprintf(fp, "\n%s", r.ingredients[i].Ingredient);
	}
	for (int i = 0; i < r.Dircount; i++)
	{
		fprintf(fp, "\n%s", r.directions[i].Direction);
	}
	fclose(fp);
	return true;
}

bool SetRecipeIngredient(RECIPE *r, char* ingredient)
{
	if (r->Ingcount == MAX_COUNT)
		return false;
	strcpy(r->ingredients[r->Ingcount].Ingredient, ingredient);
	r->Ingcount++;
	strcpy(r->ingredients[r->Ingcount].Ingredient, "\0");
	return true;
}

bool SetRecipeDirection(RECIPE *r, char* direction)
{
	if (r->Dircount == MAX_COUNT)
		return false;
	strcpy(r->directions[r->Dircount].Direction, direction);
	r->Dircount++;
	strcpy(r->directions[r->Dircount].Direction, "\0");
	return true;
}

void SetRecipeName(RECIPE *r, char* name)
{
	strcpy(r->Name, name);
}

RECIPE ReadRecipeFromFile(FILE* fp)
{
	int indexnum, ingcount, dircount, rating;
	char newline[MAXSTR];
	char name[MAXSTR];
	char ingredient[MAXSTR];
	char direction[MAXSTR];
	fscanf_s(fp, "\n%d\n%d\n%d\n%d", &indexnum, &ingcount, &dircount, &rating);
	fgets(newline, MAXSTR, fp);
	fgets(name, MAXSTR, fp);
	removenewline(name);
	RECIPE r = CreateNewRecipe(indexnum);
	SetRecipeName(&r, name);
	RateRecipe(&r, rating);
	for (int i = 0; i < dircount; i++)
	{
		fgets(direction, MAXSTR, fp);
		removenewline(direction);
		if (!SetRecipeDirection(&r, direction))
			fprintf(stderr, "Error reading from file.");
	}
	for (int i = 0; i < ingcount; i++)
	{
		fgets(ingredient, MAXSTR, fp);
		removenewline(ingredient);
		if (!SetRecipeIngredient(&r, ingredient))
			fprintf(stderr, "Error reading from file.");
	}
	return r;
}

void converttolowercase(char *input)
{
	for (int i = 0; i < strlen(input); i++)
	{
		input[i] = tolower(input[i]);
	}
}

