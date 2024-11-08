#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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
    int keyfortree;
}person;

typedef struct _person_node_tree
{
    person pn;
    struct _person_node_tree* left;
    struct _person_node_tree* right;
    struct _person_node_tree* parent;
}person_node_tree;

typedef struct _person_tree{
    person_node_tree* root;
}person_tree;

void initTree(person_tree *newtree);
person_node_tree* createNode(person npn);
person_node_tree *insertNode(person_node_tree *newnode, person pers);
person_node_tree* balanceTree(person_node_tree *temp);
person *searchNode(person_node_tree *searchnode, int *key);
void destroyTree(person_node_tree *node);
char height(person_node_tree *node);
char diff(person_node_tree *node);
person_node_tree* ll_rotation(person_node_tree *node);
person_node_tree* rr_rotation(person_node_tree *node);
person_node_tree* lr_rotation(person_node_tree *node);
person_node_tree* rl_rotation(person_node_tree *node);
void pi_print_in_order(person_node_tree *node);
void bt_in_order_print(person_tree *apTree);