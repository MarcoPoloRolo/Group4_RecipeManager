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
			{
				programcontinue = false;
				break;
			}
			case 1: 
			{
				int i = 0;
				int indexNumber = -1;
				while (i < MAX_COUNT)
				{
					if (strcmp(Book[i].Name, "EMPTY") == 0)
						indexNumber = i;
					i++;
				}
				if (indexNumber != -1)
				{
					printf("Please enter the name of the recipe:\n"); //Gets user input
					char name[MAXSTR];
					getchar();
					fgets(name, MAXSTR, stdin);
					removenewline(name);
					SetRecipeName(&Book[indexNumber], name);
					printf("Please enter the number of ingredients in the recipe (max 25), then the number of directions (max 25):\n");
					int ingcount = -1;
					int dircount = -1;
					if (!scanf("%d", &ingcount) && getchar() && ingcount > 0 && ingcount <= MAX_COUNT)
						printf("\nToo many or not enough ingredients.");
					else if (!scanf("%d", &dircount) && getchar() && dircount > 0 && dircount <= MAX_COUNT)
						printf("\nToo many or not enough directions entered.");
					else
					{
						getchar();
						for (int i = 0; i < ingcount; i++)
						{
							printf(" Enter ingredient %d) ", i + 1);
							char ingredient[MAXSTR];
							fgets(ingredient, MAXSTR, stdin);
							removenewline(ingredient);
							if (!SetRecipeIngredient(&Book[indexNumber], ingredient))
								printf("\nMax number of ingredients reached.");
						}
						for (int i = 0; i < dircount; i++)
						{
							printf(" Enter ingredient %d) ", i + 1);
							char direction[MAXSTR];
							fgets(direction, MAXSTR, stdin);
							removenewline(direction);
							if (!SetRecipeDirection(&Book[indexNumber], direction))
								printf("\nMax number of directions reached.");
						}
					}
				}
				else
					printf("\nSorry, no recipe slots empty.");
				break;
			}
			case 2:
			{
				bool recipeExists = false;
				for (int i = 0; i < MAX_COUNT; i++) //Check if any recipes exist to be deleted
				{
					if (strcmp(Book[i].Name, "EMPTY"))
						recipeExists = true;
				}
				if (recipeExists)
				{
					printf("Enter the number of the recipe you would like to delete.\n");
					int recipeDeleteNumber = 1;
					for (int i = 0; i < MAX_COUNT; i++)
					{
						if (strcmp(Book[i].Name, "EMPTY")) //Displays existing recipes
						{
							printf("%d) %s\n", Book[i].Indexnum, Book[i].Name);
							recipeDeleteNumber++;
						}
					}
					int delete;
					if (scanf("%d", &delete) && getchar()) //Input validity check
					{
						delete--;
						if (strcmp(Book[delete].Name, "EMPTY")) //Check if input corresponds to a valid recipe
						{
							for (int i = 0; i < Book[delete].Ingcount; i++) //Clears data from ingredients and directions
								strcpy(Book[delete].ingredients[i].Ingredient, "");
							for (int i = 0; i < Book[delete].Dircount; i++)
								strcpy(Book[delete].directions[i].Direction, "");
							strcpy(Book[delete].Name, "EMPTY");
							Book[delete].rating.rating = 0;
							Book[delete].Ingcount = 0;
							Book[delete].Dircount = 0;
							printf("Successfully deleted\n");
						}
						else
							printf("That recipe doesn't exist. Please try again.\n");
					}
				}
				else
					printf("These is no recipe to delete.\n");
				break;
			}
			case 3: 
			{

				break;
			}
			case 4: 
			{

				break;
			}
			case 5: 
			{

				break;
			}
			case 6: 
			{

				break;
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