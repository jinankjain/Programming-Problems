//
//  store_credit.c
//  StoreCredit
//
//  Created by Muhammad Hussein Nasrollahpour on 4/7/14.
//  Copyright (c) 2014 Chocolate. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLENGTH 3000

void makeEmptyArray(char *ary, int iary[MAXLENGTH], int length, int isNumber);

int main(int argc, const char *argv[])
{
	FILE *in = fopen("/Users/muhammad/Desktop/in.txt", "r");
	FILE *out = fopen("/Users/muhammad/Desktop/out.txt", "w");
	
	char info[MAXLENGTH];
	makeEmptyArray(info, NULL, MAXLENGTH, 0);
	
	__unused char *N = fgets(info, MAXLENGTH, in);
	
	int lock = 1;
	int _case = 1;
	while (fgets(info, MAXLENGTH, in)) {
		char *tempI = info;
		int C;
		int l;
		char tempInfo[MAXLENGTH];
		makeEmptyArray(tempInfo, NULL, MAXLENGTH, 0);
		
		if (1 == lock)
		{
			C = atoi(tempI);
		}
		else if (2 == lock)
		{
			l = atoi(tempI);
		}
		else if (3 == lock)
		{
			strcpy(tempInfo, tempI);
		}
		
		lock += 1;
		
		if (lock >= 4) {
			lock = 1;
			
			char *i = tempInfo;
			int p[MAXLENGTH];
			makeEmptyArray(NULL, p, MAXLENGTH, 1);
			
			int j = 0;
			while('\0' != *i) {
				char word[MAXLENGTH];
				makeEmptyArray(word, NULL, MAXLENGTH, 0);
				int idx = 0;
				
				while (!isspace(*i)) {
					word[idx] = *i;
					
					i++;
					idx++;
				}
				
				if (isspace(*i)) i++;
				
				char *v = word;
				
				int value = atoi(v);
				
				p[j] = value;
				
				j++;
			}
			
			int newP[MAXLENGTH];
			makeEmptyArray(NULL, newP, MAXLENGTH, 1);
			
			int b = 0;
			for (int a = 0; a <= j; a++) {
				if (p[a] <= C) {
					newP[b] = p[a];
					b++;
				}
			}
			
			int found = 0;
			int idxFound = 0;
			int idxA, idxB = 0;
			for (int a = 0; a <= b; a++) {
				int except = newP[a];
				
				for (int d = 0; d <= b; d++) {
					int i = 0;
					if (except + newP[d] == C && !found) {
						found = 1;
						i = d;
						
						for (int h = 0; h <= j; h++) {
							if (except == p[h] && !idxFound) {
								idxA = h;
								idxFound = 1;
							} else if (newP[i] == p[h]) {
								idxB = h;
							}
						}
						
						int lowerIndex = (idxA < idxB) ? 1 : 0;
						if (lowerIndex == 1) {
							printf("Case #%d: %d %d\n", _case, idxA + 1, idxB + 1);
						} else {
							printf("Case #%d: %d %d\n", _case, idxB + 1, idxA + 1);
						}
						
					}
					
					if (found) {
						break;
					}
				}
			}
			
			C = l = 0;
			_case++;
		}
	}
	
	fclose(in);
	fclose(out);
	
	return 0;
}

void makeEmptyArray(char *ary, int iary[MAXLENGTH], int length, int isNumber)
{
	if (!isNumber) {
		for (int a = 0; a < length; a++) {
			ary[a] = '\0';
		}
	} else {
		for (int a = 0; a < length; a++) {
			iary[a] = -1;
		}
	}
}
