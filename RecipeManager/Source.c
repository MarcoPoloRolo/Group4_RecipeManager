#include "CookBook.h"
#include "Directions.h"
#include "Ingredients.h"
#include "Recipe.h"



int main(void) 
{
	RECIPE Book[MAX_COUNT] = { 0 }; //MAX_COUNT is currently set to 25. Can be changed later but right now, it's just to avoid errors
	FILE* fp = fopen(FILENAME, "r");
	if (!fp)
	{
		for (int i = 0; i < MAX_COUNT; i++)
		{
			WriteRecipeToFile(CreateNewRecipe(i + 1));
		}
	}
	if (fp)
		fclose(fp);
	FILE* fp2 = fopen(FILENAME, "r");
	for (int i = 0; i < MAX_COUNT; i++)
	{
		Book[i] = ReadRecipeFromFile(fp2);
	}
	fclose(fp2);
	

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
				fgets(input, MAXSTR, stdin);
				removenewline(input);
				converttolowercase(input);
				int found = -1;
				for (int i = 0; i < MAX_COUNT; i++)
				{
					char search[MAXSTR];
					strcpy_s(search, sizeof(Book[i].Name), Book[i].Name);
					converttolowercase(search);
					if (strcmp(search, input) == 0)
						found = i;
				}
				if (found != -1)
					DisplayRecipe(Book[found]);
				else
					printf("\nNo recipe found.");
				break;
			}
				
			case 8:
			{
				int sel = 1;
				printf("\nWhich recipe would you like to rate? (Enter index number): ");
				if (!scanf("%d", &sel) && getchar() && sel <= 25 && sel >= 1 || Book[sel-1].Name == "EMPTY")
					printf("\nInvalid recipe index entered.");
				else
				{
					int rating;
					printf("\nEnter a rating, from 1 to 5: ");
					if (!scanf("%d", &rating) && getchar() && rating < 6 && rating > 0)
						printf("\nIncorrect rating value entered.");
					else
						RateRecipe(&Book[sel - 1], rating);
				}
				break;
			}
				
		}
	}

	FILE* fp3 = fopen(FILENAME, "w");
	fclose(fp3);
	for (int i = 0; i < MAX_COUNT; i++)
	{
		WriteRecipeToFile(Book[i]);
	}
	return 0;
}