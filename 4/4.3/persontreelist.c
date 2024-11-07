#include "persontreelist.h"

person_node_tree* createNode(){
    person_node_tree* newNode = (person_node_tree*)malloc(sizeof(person_node_tree));
    newNode->pn = createPerson();
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

