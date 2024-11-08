#include "persontreelist.h"

bool checkonvoidstr(char str[20]);
int generatekey(int *basecount, char surnameof[]);
person enternamesurname();
person createPerson(int *basecount);
void print_in_order(person_node_tree *node);
person* nodeInTree(person_tree* tree, person* fpers, int *count_node);
void deleteperson(person_tree *tree, int *count_node);
void editperson(person_tree *tree, int *count_node);
