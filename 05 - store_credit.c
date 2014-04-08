//
//  store_credit.c
//  StoreCredit
//
//  Created by Muhammad Hussein Nasrollahpour on 4/4/14.
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
			
			int halfOfCredit = C / 2;
			printf("%d\n", halfOfCredit);
			
			
			
			
			
			
			
			int max = newP[0];
			for (int d = 0; d <= b; d++) {
				if (max < newP[d]) {
					max = newP[d];
					newP[d] = -1;
				}
			}
			
			int newnewP[MAXLENGTH];
			makeEmptyArray(NULL, newnewP, MAXLENGTH, 1);
			int difference = C - max;
			int f = 0;
			for (int e = 0; e <= b; e++) {
				if (newP[e] <= difference) {
					newnewP[f] = newP[e];
					f++;
				}
			}
			
			int differencesMax = newnewP[0];
			if (-1 == differencesMax) {
			s:
				max = newP[0];
				for (int d = 0; d <= b; d++) {
					if (max < newP[d]) {
						max = newP[d];
						newP[d] = -1;
					}
				}
				
				int newnewP[MAXLENGTH];
				makeEmptyArray(NULL, newnewP, MAXLENGTH, 1);
				int difference = C - max;
				int f = 0;
				for (int e = 0; e <= b; e++) {
					if (newP[e] <= difference) {
						newnewP[f] = newP[e];
						f++;
					}
				}
				
				differencesMax =  newnewP[0];
				for (int g = 0; g <= f; g++) {
					if (differencesMax < newnewP[g]) {
						differencesMax = newnewP[g];
					}
				}
				if (-1 == differencesMax) goto s;
			} else {
				for (int g = 0; g <= f; g++) {
					if (differencesMax < newnewP[g]) {
						differencesMax = newnewP[g];
					}
				}
			}
						
			int maxIndex = 0;
			int isFound = 0;
			int differencesMaxIndex = 0;
			for (int h = 0; h <= j; h++) {
				if (max == p[h] && !isFound) {
					maxIndex = h;
					isFound = 1;
				} else if (differencesMax == p[h]) {
					differencesMaxIndex = h;
				}
			}
						
			int lowerIndex = (maxIndex < differencesMaxIndex) ? 1 : 0;
			if (lowerIndex == 1) {
				// printf("Case #%d: %d %d\n", _case, maxIndex + 1, differencesMaxIndex + 1);
			} else {
				// printf("Case #%d: %d %d\n", _case, differencesMaxIndex + 1, maxIndex + 1);
			}
			
			// printf("%d %d\n", max, differencesMax);
			
			// fputs(result, out);
			
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
