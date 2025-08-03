#ifndef CSV_IO_H
#define CSV_IO_H
#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <string.h>

int CSV_getInt(const char *key);
char* CSV_getString(const char *key);
void CSV_setInt(const char *key, int value);



#endif