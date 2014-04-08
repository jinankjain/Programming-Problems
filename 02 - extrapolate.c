//
//  extrapolate.m
//  Extrapolate
//
//  Created by Muhammad Hussein Nasrollahpour on 12/13/13.
//  Copyright (c) 2013 Chocolate. All rights reserved.
//

#include <stdio.h>

#define MAXLENGTH 100

int main(int argc, const char * argv[])
{
	char items[MAXLENGTH];
	char *newItems = NULL;
	short numberOfItem;
	
	// Input
	while (fgets(items, MAXLENGTH, stdin)) {
		newItems = items;
		break;
	}
	
	printf("%s\n", newItems);
	
	short vv = *newItems;
	vv -= 48;
	
	if (0 == vv) {
		printf("Insufficient item.");
		exit(0);
	}
	
	numberOfItem = vv;
	
	short extrapolate[numberOfItem][numberOfItem];
	
	for (int i = 0; i < numberOfItem; i++) {
		for (int j = 0; j < numberOfItem; j++) {
			extrapolate[i][j] = 0;
		}
	}
	
	short index = 0;
	
	newItems++;
	
	while ('\n' != *newItems) {
		if (isspace(*newItems)) {
			newItems++;
		}
		
		short kk = *newItems;
		kk -= 48;
		extrapolate[index][0] = kk;
		
		newItems++;
		index++;
	}
	
	short ii = numberOfItem;
	
	// Column
	for (short column = 0; column < numberOfItem; column++) {
		// Row
		ii -= 1;
		for (short row = 0; row < ii; row++) {
			short difference = abs(extrapolate[row][column] - (int)extrapolate[row + 1][column]);
			extrapolate[row + 1][column + 1] = difference;
			printf("%hd\n", extrapolate[row + 1][column + 1]);
		}
	}
	
	for (short i = 0; i < numberOfItem; i++) {
		for (short j = 0; j < numberOfItem; j++) {
			printf("\n[%hd][%hd] -> %hd\n", i, j, extrapolate[i][j]);
		}
	}
	
	short sum = 0;
	for (short c = numberOfItem - 1; c >= 0; c--) {
		sum = extrapolate[numberOfItem - 1][c] + extrapolate[numberOfItem - 1][c - 1];
	}
	
	// short arrayOfExtrapolate[MAXLENGTH][MAXLENGTH];
	
	printf("%hd\n", sum);
	
	return 0;
}

