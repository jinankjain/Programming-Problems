//
//  reverse_word.c
//  ReverseWord
//
//  Created by Muhammad Hussein Nasrollahpour on 4/4/14.
//  Copyright (c) 2014 Chocolate. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLENGTH 1000
typedef int bool;

void makeEmptyArray(char *ary, int length, bool is2d, char ary2d[MAXLENGTH][MAXLENGTH]);
void output(char ary[MAXLENGTH][MAXLENGTH], int j, int _case);

int main(int argc, const char * argv[])
{
	int N = 0;
	scanf("%d", &N);

	char words[MAXLENGTH];
	makeEmptyArray(words, MAXLENGTH, 0, NULL);
	char allWords[MAXLENGTH][MAXLENGTH];
	bool fix = 0;
	int j = 0;
	int _case = 1;
	while (fgets(words, MAXLENGTH, stdin)) {
		if (!fix) {
			fgets(words, MAXLENGTH, stdin);
		}
		
		fix = 1;
		
		const char *newWords = words;
		
		while ('\0' != *newWords) {
			char word[MAXLENGTH] = {'\0'};
			// makeEmptyArray(word, MAXLENGTH);
			int i = 0;
			
			while (!isspace(*newWords)) {
				word[i] = *newWords;
								
				newWords++;
				i++;
			}
						
			if (isspace(*newWords)) newWords++;
			
			strcpy(allWords[j], word);
			
			j++;
		}
		
		output(allWords, j, _case);
		
		if (N <= 1) break;
		
		N--;
		_case++;
		makeEmptyArray(NULL, MAXLENGTH, 1, allWords);
	}
	
    return 0;
}

void makeEmptyArray(char *ary, int length, bool is2d, char ary2d[MAXLENGTH][MAXLENGTH])
{
	if (!is2d)
		for (int i = 0; i <= length; i++)
			ary[i] = '\0';
	
	if (is2d)
		for (int i = 0; i <= length; i++)
			for (int j = 0; j <= length; j++)
				ary2d[i][j] = '\0';
}

void output(char ary[MAXLENGTH][MAXLENGTH], int j, int _case)
{
	printf("Case #%d: ", _case);
	for (int i = j; i >= 0; i--) {
		printf("%s ", ary[i]);
	}
	printf("\n");
}


