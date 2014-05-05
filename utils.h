/******************************************************************************
 * A visual 2D array management interface a.k.a. - spreadsheet.               *
 * @author      Tautvydas Gricius                                             *
 * @version     1                                                             *
 * @modified    2014.04.23                                                    *
 * @task        2                                                             *
 ******************************************************************************/

#ifndef UTILS_H
#define UTILS_H

#include <math.h>
#include <unistd.h>
#include <termios.h> // Unix API for terminal I/O
#include <sys/ioctl.h>
#include <limits.h>

/*
 * utils.[ch] - utility type/function library
 */

// Utility functions
unsigned int absu(int value);
unsigned int maxu(unsigned int a, unsigned int b);
unsigned int fact(unsigned int number);
int power(int number, int power);
int digitCount(unsigned int value);
char getChar();

// Environment functions
typedef struct Env {
    int     w,  // Will hold the width of the terminal window and the
            h;  // Height
} Env;

Env     envGet();

#endif /* UTILS_H */
