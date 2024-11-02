#include "personlinklist.h"

int main(){

    person_linked_list *list = createpll();

    int countpers=0;
    
    bool work=1; int cmd;
    while(work){
        printf("\nPrint list-1, Add person-2, Edit person-3, Delete person-4, Complete the work-5: ");
        scanf("%d", &cmd);
        switch(cmd)
        {
            case 1: 
                printpll(list);
                break;
            case 2: 
                pushfrontpll(list);
                break;
            case 3: 
                editfrontpll(list);
                break;
            case 4: 
                deletefrontpll(list);
                break;
            case 5:
                work=0;
                break;
            default: 
                printf("\nCommand not found \n");
                break;
        }
    }
    
    deletepll(&list);
    return 0;
}