#include "userinterface.h"

int main(){
    printf("0\n"); int count = 0;
    person_tree* treelist = (person_tree*)malloc(sizeof(person_tree));
    printf("1\n");
    initTree(treelist); printf("1.5\n");person tmp;
    printf("2\n");
    tmp = createPerson(&count);
    printf("3\n");
    treelist->root = insertNode(treelist->root, tmp);
    printf("4\n");
    tmp = createPerson(&count);
    treelist->root = insertNode(treelist->root, tmp);
    tmp = createPerson(&count);
    treelist->root = insertNode(treelist->root, tmp);
    tmp = createPerson(&count);
    treelist->root = insertNode(treelist->root, tmp);
    tmp = createPerson(&count);
    treelist->root = insertNode(treelist->root, tmp);
    bt_in_order_print(treelist);
    destroyTree(treelist->root);
}
