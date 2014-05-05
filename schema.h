#ifndef SCHEMA_H
#define SCHEMA_H

typedef struct Data {
    unsigned int    bus;        // 0 - UINT_MAX
    unsigned int    time;       // 0 - 1439 time in minutes
    unsigned char   route;      // 0 - 1 direction 0 = to->from or 1 = from->to
    char            stop[32];   // name of this stop
} Data;

#endif /* SCHEMA_H */
