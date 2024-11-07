#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

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

typedef struct _person
{
    char name[TWENTY_SIZE];
    char surname[TWENTY_SIZE];
    char lastname[TWENTY_SIZE];
    struct workp infwork;
    struct connectfp infconn;
}person;

typedef struct _person_node_tree
{
    person pn;
    struct _person_node_tree* left;
    struct _person_node_tree* right;
    struct _person_node_tree* parent;



}person_node_tree;

bool checkonvoidstr(char str[20]);
person createPerson();
person_node_tree* createNode();
person_node_tree* insertNode();
