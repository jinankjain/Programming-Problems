//
//  star_war.c
//  StarWar
//
//  Created by Muhammad Hussein Nasrollahpour on 4/4/14.
//  Copyright (c) 2014 Chocolate. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLENGTH 100

typedef struct Ship {
	int x, y, z, p;
}Ship;

void makeEmptyArray(char *array, int length);
float calculatePowerOfCruiser(int c_x, int c_y, int c_z, int x, int y, int z, int p);

int main(int argc, const char * argv[])
{
	int T = 0;
	scanf("%d", &T);
	
	while (T >= 1) {
		int N = 0;
		scanf("%d", &N);
		
		Ship ships[N];
		
		char shipDescription[MAXLENGTH];
		makeEmptyArray(shipDescription, MAXLENGTH);
		
		int shipIndex = 0;
		int fix = 0;
		int Case = 1;
		while (fgets(shipDescription, MAXLENGTH, stdin)) {
			
			if (!fix) fgets(shipDescription, MAXLENGTH, stdin);
			
			fix++;
			
			char *desc = shipDescription;
			int space = 0;
			
			while ('\0' != *desc) {
				char val[MAXLENGTH];
				makeEmptyArray(val, MAXLENGTH);
				int idx = 0;
				
				while (!isspace(*desc)) {
					val[idx] = *desc;
					
					desc++;
					idx++;
				}
				
				if (isspace(*desc)) {
					desc++;
				}
				
				char *value = val;
				int v = atoi(value);
				
				switch (space) {
					case 0:
						ships[shipIndex].x = v;
						break;
					case 1:
						ships[shipIndex].y = v;
						break;
					case 2:
						ships[shipIndex].z = v;
						break;
					case 3:
						ships[shipIndex].p = v;
						break;
						
					default:
						break;
				}
				
				space++;
			}
			
			if (1 == N) break;
			
			N--;

			shipIndex++;
		}
		
		printf("Case #%d: ", Case);
		int powers[N];
		int idx = 0;
		for (int k = 0; k < N; k++) {
			Ship cruiser = ships[k];
			
			int exception = k;
			
			for (int h = 0; h < N; h++) {
				if (exception != h) {
					int power = calculatePowerOfCruiser(cruiser.x, cruiser.y, cruiser.z, ships[h].x, ships[h].y, ships[h].z, ships[h].p);
					
					powers[idx] = power;
					
					idx++;
				}
			}
		}
		
		int min = powers[0];
		for (int k = 0 ; k <= idx; k++) {
			if (min < powers[k]) {
				min = powers[k];
			}
		}
		printf("%d\n", min);
		
		T--;
		Case++;
	}
	
    return 0;
}

void makeEmptyArray(char *array, int length)
{
	for (int i = 0; i < length; i++) {
		array[i] = '\0';
	}
}

float calculatePowerOfCruiser(int c_x, int c_y, int c_z, int x, int y, int z, int p)
{
	return (abs(x - c_x) + abs(y - c_y) + abs(z - c_z) / p);
}
