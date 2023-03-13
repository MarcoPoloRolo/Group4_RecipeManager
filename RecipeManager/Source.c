#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "CookBook.h"
#include <stdbool.h>

int main(void) {

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