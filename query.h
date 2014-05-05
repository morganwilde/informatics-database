#ifndef QUERY_H
#define QUERY_H

#include "schema.h"

#define ACTION_LENGTH (6)
#define NAME_SELECT "SELECT"
#define NAME_INSERT "INSERT"
#define NAME_UPDATE "UPDATE"
#define NAME_DELETE "DELETE"

typedef enum QueryAction {
    INVALID,    // If the query action is malformed
    SELECT,     // Query the data
    INSERT,     // Insert new data
    UPDATE,     // Update an existing entry
    DELETE      // Remove existing entry
} QueryAction;

QueryAction findAction(const char *query, char **details);
Data *interpretQuery(const char *query, int *resultsCount);
Data *interpretSelect(const char *details, int *resultsCount);
void interpretInsert(const char *details);
void printDataResult(Data *results, int resultsCount);

#endif /* QUERY_H */
