#define _CRT_SECURE_NO_WARNINGS
#include "CookBook.h"
// prog 71985 - Group 4 (Julian, Marko and Luke) - Winter 2023 - Group assignment: Recipe manager

void printTitle() {
    printf("------------------------------------------------\n");
    printf(" Welcome to Deborah's Dubious Disasterpieces TM\n");
    printf("                 As seen on HBO\n");
    printf("------------------------------------------------\n");
}
void printMenuOptions() {
    printf("\n|Main Menu|\n");
    printf("---------------\n");
    printf("Enter 0 to quit\n");
    printf("Enter 1 to add a new recipe\n");
    printf("Enter 2 to delete a recipe\n");
    printf("Enter 3 to edit an existing recipe\n");
    printf("Enter 4 to display a recipe\n");
    printf("Enter 5 to display multiple recipes\n");
    printf("Enter 6 to display all recipes\n");
    printf("Enter 7 to search for a recipe\n");
    printf("Enter 8 to give a recipe a rating out of 5 stars\n");
    printf("------------------------------------------------\n");
}
int getUserMenuInput() //Bugged - Decimal numbers crash program
{
    int userInput;
    bool successfulInput = false;
    do //Loops until valid input is entered
    {
        if (scanf("%d", &userInput) && userInput >= 0 && userInput <= MAX_MENU_OPTION) //Input check
            successfulInput = true;
        else
            printf("Invalid input. Please enter a number from 0 - %d\n", MAX_MENU_OPTION);
    } while (successfulInput == false); //Loop check

    return (userInput);
}

