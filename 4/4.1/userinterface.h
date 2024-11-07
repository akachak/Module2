#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "personlinklist.h"

bool checkonvoidstr(char str[20]);
person_node* createperson();
struct person enternamesurname();
void editperson(person_linked_list *list);
void deleteperson(person_linked_list *list);
void pushperson(person_linked_list *list);
void printpersons(person_linked_list *list);