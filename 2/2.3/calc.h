#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#define SIZE 10

double sum(const int count, ...);
double sub(const int count, ...);
double mult(const int count, ...);
double div(const int count, ...);
void enterargs(double num[SIZE], int *count);