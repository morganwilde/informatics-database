#include "query.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

QueryAction findAction(const char *query, char **details)
{
    QueryAction action = INVALID;
    char *word = calloc(ACTION_LENGTH, sizeof(char));
    memcpy(word, query, ACTION_LENGTH);
    // Check which name fits
    if (strcmp(NAME_SELECT, word) == 0) {
        action = SELECT;
    } else if (strcmp(NAME_INSERT, word) == 0) {
        action = INSERT;
    } else if (strcmp(NAME_UPDATE, word) == 0) {
        action = UPDATE;
    } else if (strcmp(NAME_DELETE, word) == 0) {
        action = DELETE;
    }
    // Extract the details if action is valid
    if (action != INVALID) {
        // TODO refactor this functionality into strings.h
        *details = realloc(*details, strlen(query)-ACTION_LENGTH+1);
        int i, j;
        for (i = 0, j = ACTION_LENGTH; j < strlen(query); i++, j++) {
            (*details)[i] = query[j];
        }
        (*details)[i+1] = '\0';
    }
    
    return action;
}
Data *interpretQuery(const char *query, int *resultsCount)
{
    char *details = malloc(sizeof(char));
    QueryAction action = findAction(query, &details);
    // If the action is valid, do it; else inform the user
    switch (action) {
        case SELECT:
            // Interpret the rest of the statement in stages
            return interpretSelect(details, resultsCount);
            break;
        default:
            printf("The query \"%s\" is malformed.\n", query);
            break;
    }
    *resultsCount = 0;
    return NULL;
}
Data *interpretSelect(const char *details, int *resultsCount)
{
    // The storage containers for output
    Data entry;// = {0, 0, 0, ""};
    Data *entries = malloc(sizeof(Data));
    int entryCount = 0;
    // Local storage
    char **tokens = NULL;
    int tokensCount = 0;
    tokenizer(details, &tokens, &tokensCount, " ");
    if (tokensCount) {
        if ((tokensCount >= 1) && (strcmp(tokens[0], "*"))) {
            // Read everything from the database table
            FILE *table = fopen("data.db", "rb");
            fseek(table, 0, SEEK_SET);
            if (table) {
                while (fread(&entry, sizeof(entry), 1, table)) {
                    entries[entryCount++] = entry;
                    entries = realloc(entries, sizeof(Data) * (entryCount+1));
                }
            }
        }
        int i;
        for (i = 0; i < tokensCount; i++) {
            //printf("tokens[%d] = \"%s\"\n", i, tokens[i]);
        }
    } else {
        free(entries);
        entries = NULL;
        printf("Field identifier missing.\n");
    }
    *resultsCount = entryCount;
    return entries;
}
void printDataResult(Data *results, int resultsCount)
{
    int i;
    for (i = 0; i < resultsCount; i++) {
        printf("result:\n");
    }
}
