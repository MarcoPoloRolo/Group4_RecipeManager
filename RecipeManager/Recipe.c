#include "Recipe.h"
// prog 71985 - Group 4 (Julian, Marko and Luke) - Winter 2023 - Group assignment: Recipe manager
RECIPE CreateNewRecipe(int index) // Creates empty recipe
{
	RECIPE r; 
	r.Indexnum = index;
	SetRecipeName(&r, "EMPTY"); // sets name to default value checked in main as "EMPTY" if no recipe has been set 
	r.Dircount = 0; // all other values set to 0
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

void RateRecipe(RECIPE *r, int rating) // sets given recipe rating to a value between 1 and 5
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
	if (!fp) // Checks that file exists/can be opened
		return false; // If file error occurs, return false
	fprintf(fp, "\n%d\n%d\n%d\n%d\n%s", r.Indexnum, r.Ingcount, r.Dircount, r.rating.rating, r.Name); // Print first four values (all ints)
	for (int i = 0; i < r.Ingcount; i++) // Prints each ingredient in order, each on its own line
	{
		fprintf(fp, "\n%s", r.ingredients[i].Ingredient);
	}
	for (int i = 0; i < r.Dircount; i++) // Same as ingredients, but with directions
	{
		fprintf(fp, "\n%s", r.directions[i].Direction);
	}
	fclose(fp); // Close file when finished
	return true;
}

bool SetRecipeIngredient(RECIPE *r, char* ingredient)
{
	if (r->Ingcount == MAX_COUNT) // If ingredient limit reached, return false
		return false;
	strcpy(r->ingredients[r->Ingcount].Ingredient, ingredient);  // Copy ingredient into recipe, incriment ingcount, then set next ingredient to "\0"
	r->Ingcount++;
	strcpy(r->ingredients[r->Ingcount].Ingredient, "\0");
	return true;
}

bool SetRecipeDirection(RECIPE *r, char* direction)
{
	if (r->Dircount == MAX_COUNT) // If direction limit reached, return false
		return false;
	strcpy(r->directions[r->Dircount].Direction, direction); // Copy direction into recipe, incriment dircount, then set next direction to "\0"
	r->Dircount++;
	strcpy(r->directions[r->Dircount].Direction, "\0");
	return true;
}

void SetRecipeName(RECIPE *r, char* name) // Sets recipe name to string given
{
	strcpy(r->Name, name);
}

RECIPE ReadRecipeFromFile(FILE* fp)
{
	int indexnum, ingcount, dircount, rating; // declare local variables to temporarily hold on to read values from file
	char newline[MAXSTR];
	char name[MAXSTR];
	char ingredient[MAXSTR];
	char direction[MAXSTR];
	fscanf_s(fp, "\n%d\n%d\n%d\n%d", &indexnum, &ingcount, &dircount, &rating); // read first 4 elements
	fgets(newline, MAXSTR, fp); 
	fgets(name, MAXSTR, fp);
	removenewline(name); // reads recipe name
	RECIPE r = CreateNewRecipe(indexnum); // create empty recipe
	SetRecipeName(&r, name);
	RateRecipe(&r, rating);
	for (int i = 0; i < ingcount; i++) // Fills in each ingredient slot in correct order in recipe
	{
		fgets(ingredient, MAXSTR, fp);
		removenewline(ingredient);
		if (!SetRecipeIngredient(&r, ingredient))
			fprintf(stderr, "Error reading from file.");
	}
	for (int i = 0; i < dircount; i++) // Same as ingredients, but with directions
	{
		fgets(direction, MAXSTR, fp);
		removenewline(direction);
		if (!SetRecipeDirection(&r, direction))
			fprintf(stderr, "Error reading from file.");
	}

	return r;
}

void converttolowercase(char *input) // converts each element in given string to lowercase for searching
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