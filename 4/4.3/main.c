#include "userinterface.h"

int main(){
    int count = 0;
    person_tree* treelist = (person_tree*)malloc(sizeof(person_tree));
    initTree(treelist);person tmp;

    bool work=1; int cmd;
    while(work){
        printf("\nPrint list-1, Add person-2, Edit person-3, Delete person-4, Complete the work-5: ");
        scanf("%d", &cmd);
        switch(cmd)
        {
            case 1: 
                print_in_order(treelist->root);      
                break;
            case 2:
                tmp = createPerson(&count);
                treelist->root = insertNode(treelist->root, tmp);
                break;
            case 3: 
                editperson(treelist, &count);
                break;
            case 4: 
                deleteperson(treelist, &count);
                break;
            case 5:
                work=0;
                break;
            default: 
                printf("\nCommand not found \n");
                break;
        }
    }
    
    destroyTree(treelist->root);
    return 0;
}
