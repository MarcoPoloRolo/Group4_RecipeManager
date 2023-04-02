#include "CookBook.h"
#include "Directions.h"
#include "Ingredients.h"
#include "Recipe.h"



int main(void) 
{
	RECIPE Book[MAX_RECIPIE_COUNT] = { 0 };
	FILE* fp = fopen(FILENAME, "r");
	if (!fp)
	{
		for (int i = 0; i < MAX_RECIPIE_COUNT; i++)
		{
			if (!WriteRecipeToFile(CreateRecipe(i, " ")))
				fprintf(stderr, "Write error.");
		}
	}
	for (int i = 0; i < MAX_RECIPIE_COUNT; i++)
	{
		fp = fopen(FILENAME, "r");
		Book[i] = ReadRecipieFromFile(fp);
		fclose(fp);
	}
	

	printTitle();
	bool programcontinue = true;
	while (programcontinue) {
		printMenuOptions();
		int caseinput = getUserMenuInput();

		switch (caseinput) {
			case 0: 
				printf("0\n");
				break;
			case 1: 
				printf("1\n");
				break;
			case 2: 
				break;
			case 3: 
				break;
			case 4: 
				break;
			case 5: 
				break;
			case 6: 
				break;
			case 7: 
				break;
			case 8:
				break;
		}
	}
	return 0;
}