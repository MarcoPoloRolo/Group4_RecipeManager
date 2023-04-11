#include "CookBook.h"
#include "Directions.h"
#include "Ingredients.h"
#include "Recipe.h"



int main(void) 
{
	RECIPE Book[MAX_RECIPE_COUNT] = { 0 }; //MAX_RECIPE_COUNT is currently set to 50. Can be changed later but right now, it's just to avoid errors
	FILE* fp = fopen(FILENAME, "r");
	if (!fp)
	{
		for (int i = 0; i < MAX_RECIPE_COUNT; i++)
		{
			if (!WriteRecipeToFile(CreateRecipe(i, " ")))
				fprintf(stderr, "Write error.");
		}
	}
	for (int i = 0; i < MAX_RECIPE_COUNT; i++)
	{
		fp = fopen(FILENAME, "r");
		Book[i] = ReadRecipeFromFile(fp);
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
				
			case 1: 
				printf("1\n");
				
			case 2: 
			{

			}

			case 3: 
			{

			}

			case 4: 
			{

			}

			case 5: 
			{

			}

			case 6: 
			{

			}

			case 7: 
			{
				char input[MAXSTR];
				printf("\nPlease enter the name of the recipe you are looking for: ");
				gets(input);
				converttolowercase(input);
				int i = 0;
				for (i = 0; i < MAX_COUNT;)
				{
					char search[MAXSTR] = Book[i].Name;
					converttolowercase(search);
					if (strcmp(input, search) != 0)
						i++;
					else
					{
						DisplayRecipe(Book[i]);
						break;
					}
				}
				printf("\nNo Recipe Match Found.");
				break;

			}
				
			case 8:
			{

			}
				
		}
	}
	return 0;
}