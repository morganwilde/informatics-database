#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "query.h"
#include "schema.h"
/*
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
void dataRead(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file) {
        Data data;
        while (fread(&data, sizeof(data), 1, file)) {
            printf("bus=[%d] time=[%d] route=[%d] stop=[%s]\n", data.bus, data.time, data.route, data.stop);
        }
        fclose(file);
    }
}
*/
int main(void)
{
    //dataAdd(database, 1, 600, 0, "stotis");
    //dataRead(database);
    int resultsCount = 0;
    Data *results = interpretQuery("SELECT *", &resultsCount);
    // Print it out
    printDataResult(results, resultsCount);

    return 0;
}
