#include "CookBook.h"
#include "Directions.h"
#include "Ingredients.h"
#include "Recipe.h"
// prog 71985 - Group 4 (Julian, Marko and Luke) - Winter 2023 - Group assignment: Recipe manager
// Source file where program is run


int main(void) 
{
	RECIPE Book[MAX_COUNT] = { 0 }; //Creates array of recipes
	FILE* fp = fopen(FILENAME, "r"); 
	if (!fp) // If file does not exist/is not found
	{
		for (int i = 0; i < MAX_COUNT; i++)
		{
			WriteRecipeToFile(CreateNewRecipe(i + 1)); // Write blank slate of recipes to file
		}
	}
	if (fp)
		fclose(fp);
	FILE* fp2 = fopen(FILENAME, "r");
	for (int i = 0; i < MAX_COUNT; i++)
	{
		Book[i] = ReadRecipeFromFile(fp2); // Read recipes from file into array in program
	}
	fclose(fp2);
	

	printTitle();
	bool programcontinue = true; // Program loop will run until this is false
	while (programcontinue) {
		printMenuOptions();
		int caseinput = getUserMenuInput();

		switch (caseinput) {
			case 0: //Quit
			{
				programcontinue = false;
				break;
			}
			case 1: //Add a new recipe
			{
				int i = 0;
				int indexNumber = -1;
				while (i < MAX_COUNT) //Finds first empty recipe
				{
					if (strcmp(Book[i].Name, "EMPTY") == 0 && indexNumber == -1)
						indexNumber = i;
					i++;
				}
				if (indexNumber != -1)
				{
					printf("Please enter the name of the recipe, or 0 to cancel:\n"); //Gets user input and assigns it the values in array
					char name[MAXSTR];
					getchar();
					fgets(name, MAXSTR, stdin);
					if (!strcmp(name, "0"))
					{
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
							for (int i = 0; i < ingcount; i++) //Assigns input to directions/instructions with loop
							{
								printf("Enter ingredient #%d: ", i + 1);
								char ingredient[MAXSTR];
								fgets(ingredient, MAXSTR, stdin);
								removenewline(ingredient);
								if (!SetRecipeIngredient(&Book[indexNumber], ingredient))
									printf("\nMax number of ingredients reached.");
							}
							for (int i = 0; i < dircount; i++)
							{
								printf("Enter direction #%d: ", i + 1);
								char direction[MAXSTR];
								fgets(direction, MAXSTR, stdin);
								removenewline(direction);
								if (!SetRecipeDirection(&Book[indexNumber], direction))
									printf("\nMax number of directions reached.");
							}
						}
					}
					else
						printf("Returning to main menu...\n");
				}
				else
					printf("\nSorry, no recipe slots empty.");
				break;
			}
			case 2: //Delete a recipe
			{
				bool recipeExists = false;
				for (int i = 0; i < MAX_COUNT; i++) //Check if any recipes exist to be deleted
				{
					if (strcmp(Book[i].Name, "EMPTY"))
						recipeExists = true;
				}
				if (recipeExists)
				{
					printf("Enter the number of the recipe you would like to delete, or enter 0 to cancel.\n");
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
						if (!delete == 0)
						{
							delete--; //Arrays start at 0, not 1
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
						else
							printf("Returning to main menu...\n");
					}
				}
				else
					printf("These is no recipe to delete.\n");
				break;
			}
			case 3: //Edit a recipe
			{
				bool recipeExists = false;
				for (int i = 0; i < MAX_COUNT; i++) //Check if any recipes exist to be edited
				{
					if (strcmp(Book[i].Name, "EMPTY"))
						recipeExists = true;
				}
				if (recipeExists)
				{
					printf("Enter the number of the recipe you would like to edit.\n");
					int recipeEditNumber = 1;
					for (int i = 0; i < MAX_COUNT; i++)
					{
						if (strcmp(Book[i].Name, "EMPTY")) //Displays existing recipes
						{
							printf("%d) %s\n", Book[i].Indexnum, Book[i].Name);
							recipeEditNumber++;
						}
					}
					int recipeEditIndex;
					if (scanf("%d", &recipeEditIndex) && strcmp(Book[recipeEditIndex -1].Name, "EMPTY") && getchar()) //Input validity check
					{
						printf("Which part of the recipe would you like to edit?\n");
						printf("1) Name\n");
						printf("2) Ingredients\n");
						printf("3) Directions\n");
						int recipeEditType;
						if (!scanf("%d", &recipeEditType) || recipeEditType < 1 || recipeEditType > 3)
						{
							printf("Invalid response, please try again.\n");
							break;
						}
						switch (recipeEditType) //Gets input and changes value in araay
							{
							case 1: //Edit name
							{
								printf("Please enter the new name of the recipe:\n");
								char name[MAXSTR];
								getchar();
								fgets(name, MAXSTR, stdin);
								removenewline(name);
								SetRecipeName(&Book[recipeEditIndex - 1], name);
								printf("Name entered successfully\n");
								break;
							}
							case 2: //Edit ingredients
							{
								printf("Which ingredient would you like to edit?\n");

								for (int i = 0; i < Book[recipeEditIndex - 1].Ingcount; i++)
								{
									printf("%d) %s\n", i+1, Book[recipeEditIndex - 1].ingredients[i].Ingredient);
								}
								int ingredientEdit;
								if (scanf("%d", &ingredientEdit) && ingredientEdit <= Book[recipeEditIndex - 1].Ingcount)
								{
									getchar();
									printf("Enter new ingredient: ");
									char ingredient[MAXSTR];
									fgets(ingredient, MAXSTR, stdin);
									removenewline(ingredient);
									strcpy(Book[recipeEditIndex - 1].ingredients[ingredientEdit - 1].Ingredient, ingredient);
									printf("Ingredient entered successfully\n");
								}
								else
									printf("Invalid response, please try again.\n");
								break;
							}
							case 3: //Edit directions
							{
								printf("Which direction would you like to edit?\n");

								for (int i = 0; i < Book[recipeEditIndex - 1].Dircount; i++)
								{
									printf("%d) %s\n", i + 1, Book[recipeEditIndex - 1].directions[i].Direction);
								}
								int directionEdit;
								if (scanf("%d", &directionEdit) && directionEdit <= Book[recipeEditIndex - 1].Dircount)
								{
									getchar();
									printf("Enter new direction: ");
									char direction[MAXSTR];
									fgets(direction, MAXSTR, stdin);
									removenewline(direction);
									strcpy(Book[recipeEditIndex - 1].directions[directionEdit - 1].Direction, direction);
									printf("Direction entered successfully\n");
								}
								else
									printf("Invalid response, please try again.\n");
								break;
							}
						}
					}
					else
						printf("That recipe doesn't exist. Please try again.\n");
				}
				else
					printf("These is no recipe to edit.\n");
				break;
			}
			case 4: //Display one
			{

				break;
			}
			case 5: //Display range
			{

				break;
			}
			case 6: //Display all
			{

				break;
			}
			case 7: //Search
			{
				char input[MAXSTR];
				printf("\nPlease enter the name of the recipe you are looking for: ");
				getchar(); // Grabs newline left over from scanf when choosing option
				fgets(input, MAXSTR, stdin);
				removenewline(input); 
				converttolowercase(input); // Converts input from user into all lowercase
				int found = -1;
				for (int i = 0; i < MAX_COUNT; i++)
				{
					char search[MAXSTR];
					strcpy_s(search, sizeof(Book[i].Name), Book[i].Name); // Loads each recipe name into a temporary array
					converttolowercase(search);
					if (strcmp(search, input) == 0) // If user input matches recipe name, set value of found to current value of i
						found = i;
				}
				if (found != -1)
					DisplayRecipe(Book[found]); // Display recipe searched for if found
				else
					printf("\nNo recipe found."); // Display this message if recipe not found/doesnt exist
				break;
			}
			case 8: //Give rating
			{
				int sel = 1;
				printf("\nWhich recipe would you like to rate? (Enter index number): ");
				if (!scanf("%d", &sel) && getchar() && sel <= 25 && sel >= 1) // Checks that recipe index is correct
					printf("\nInvalid recipe index entered.");
				else if (strcmp(Book[sel - 1].Name, "EMPTY") == 0) // Checks that recipe index is not empty
					printf("\nNo recipe in that index.");
				else
				{
					int rating;
					printf("\nEnter a rating, from 1 to 5: ");
					if (!scanf("%d", &rating) && getchar() && rating < 6 && rating > 0) // Checks that rating is between 1 and 5 
						printf("\nIncorrect rating value entered.");
					else
						RateRecipe(&Book[sel - 1], rating); // Once all parameters are satisfied, rate chosen recipe with rating input
				}
				break;
			}
			// still need a default case, for if a letter or a string is entered
		}
	}

	FILE* fp3 = fopen(FILENAME, "w"); // Overwrites previous file
	fclose(fp3);
	for (int i = 0; i < MAX_COUNT; i++)
	{
		WriteRecipeToFile(Book[i]); // Writes updated information into file
	}
	return 0;
}