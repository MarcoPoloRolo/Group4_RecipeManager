#pragma once
#define MAX_MENU_OPTION 8
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define MAX_MENU_OPTION 8
#include "Directions.h"
#include "Ingredients.h"
#include "Recipe.h"

void printTitle();
void printMenuOptions();
int getUserMenuInput();
