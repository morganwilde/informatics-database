#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void uiOptions()
{
	printf("\n");
	printf("Command list: 'e' - exit; 'q' - query\n");
}
char *uiQuery()
{
	// Prompt
	printf("Enter a formatted query below\n");
	printf(">>> ");
	fflush(stdout);
	// Storage
	char *query = calloc(256, sizeof(char));
	char c = getChar();
	// Read the query string char by char
	printf("%c", c);
	fflush(stdout);
	int i = 0;
	while (c != '\n') {
		query[i] = c;
		c = getChar();
		printf("%c", c);
		fflush(stdout);
		i++;
	}
	query[i] = '\0';
	printf("strlen(query) = %zu\n", strlen(query));
	return query;
}
