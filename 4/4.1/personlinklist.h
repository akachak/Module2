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

struct person
{
    char name[TWENTY_SIZE];
    char surname[TWENTY_SIZE];
    char lastname[TWENTY_SIZE];
    struct workp infwork;
    struct connectfp infconn;
};

typedef struct _person_node
{
    struct person pers;
    struct _person_node *next;
    struct _person_node *prev; 
} person_node;


typedef struct _person_linked_list {
    size_t size;
    person_node *head;
    person_node *tail;
} person_linked_list;

person_linked_list* createpll();
void deletepll(person_linked_list **list);
int sortfrontpll(person_linked_list *list);
void pushfrontpll(person_linked_list *list, person_node *newnode);
void editfrontpll(person_linked_list *list, char nameonf[], char surnameof[], int cmdonf, char newfield[]);
void deletefrontpll(person_linked_list *list, char nameonf[], char surnameof[]);