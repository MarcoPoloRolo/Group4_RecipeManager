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

void DisplayRecipe(RECIPE ds) {//Marko does all display functions
	if (!strcmp(ds.Name, "EMPTY")) {
		printf("Recipe is empty!\n");
	}
	else {
		printf("----------------------------\n");
		printf("Recipe: %s\n", ds.Name);
		printf("----------------------------\n");
		PrintRating(ds.rating.rating);

		printf("Ingredients: \n");
		for (int ingredientCount = 0; ingredientCount != ds.Ingcount; ingredientCount++) {
			printf("%s\n", ds.ingredients[ingredientCount].Ingredient);
		}
		printf("\n");
		printf("Directions: \n");
		for (int directionsCount = 0; directionsCount != ds.Dircount; directionsCount++) {
			printf("%s\n", ds.directions[directionsCount].Direction);
		}

	}
}

void DisplayRecipes(RECIPE* dr, int lowlimit, int upplimit) {
	lowlimit--;
	upplimit--;
	for (int count = lowlimit; count <= upplimit; count++) {
		if (strcmp(dr[count].Name, "EMPTY")) {
			printf("----------------------------\n");
			printf("Recipe: %s\n", dr[count].Name);
			printf("----------------------------\n");
			PrintRating(dr[count].rating.rating);

			printf("Ingredients: \n");
			for (int ingredientCount = 0; ingredientCount != dr[count].Ingcount; ingredientCount++) {
				printf("%s\n", dr[count].ingredients[ingredientCount].Ingredient);
			}
			printf("\n");
			printf("Directions: \n");
			for (int directionsCount = 0; directionsCount != dr[count].Dircount; directionsCount++) {
				printf("%s\n", dr[count].directions[directionsCount].Direction);
			}
			printf("\n");
		}
	}
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
	for (int i = 0; i < ingcount; i++)
	{
		fgets(ingredient, MAXSTR, fp);
		removenewline(ingredient);
		if (!SetRecipeIngredient(&r, ingredient))
			fprintf(stderr, "Error reading from file.");
	}
	for (int i = 0; i < dircount; i++)
	{
		fgets(direction, MAXSTR, fp);
		removenewline(direction);
		if (!SetRecipeDirection(&r, direction))
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

void PrintRating(int rating) {
	printf("Rating:\n");
	for (int ratingCount = 1; ratingCount <= 5; ratingCount++) {
		if (ratingCount <= rating) {
			printf("*");
		}
	}
	printf("(%d/5)\n", rating);
	printf("\n");
}