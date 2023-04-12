#pragma once
#define MAX_MENU_OPTION 8
#define MAX_COUNT 25
#define MAXSTR 200
#define FILENAME "Cookbook.txt"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



void printTitle();
void printMenuOptions();
int getUserMenuInput();
