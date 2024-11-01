#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define TWENTY_SIZE 20
#define THIRTY_SIZE 30
#define FIFTY_SIZE 50

struct workp
{
    char placewp[FIFTY_SIZE];
    char postp[THIRTY_SIZE];
};

struct connectfp
{
    char mobphonep[12];
    char addressemailp[THIRTY_SIZE];
    char linksnp[200];
};

struct person
{
    char name[TWENTY_SIZE];
    char surname[TWENTY_SIZE];
    char lastname[TWENTY_SIZE];
    struct workp infwork;
    struct connectfp infconn;
};

bool checkonvoidstr(char str[20]);
void printpers(struct person p[], int *count);
void addpers(struct person p[], int *count);
void editpers(struct person p[], int *count);
void deletepers(struct person p[], int *count);