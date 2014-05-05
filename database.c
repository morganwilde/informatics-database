#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "query.h"
#include "schema.h"
#include "interface.h"
static const char database[] = "data.db";

void dataAdd(const char *filename, const int bus, const int time, const int route, const char *stop)
{
    FILE *file = fopen(filename, "ab");
    if (file) {
        Data data = {bus, time, route, "\0"};
        strcpy(data.stop, stop);
        fwrite(&data, sizeof(data), 1, file);
        fclose(file);
    }
}
int main(void)
{
    dataAdd(database, 3, 900, 1, "uzupis");
    //dataRead(database);
	char *query;
	int resultsCount = 0;
	char command = getc(stdin);
	while (command != 'e') {
		switch (command) {
			case 'q':
				query = uiQuery();
				resultsCount = 0;
				Data *results = interpretQuery(query, &resultsCount);
				break;
			case 'e':
				printf("Shutting down\n");
				break;
			default:
				uiOptions();
				break;
		}
		command = getc(stdin);
	}

    return 0;
}
