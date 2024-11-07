#include "userinterface.h"

int main(){
    srand(time(NULL));

    task_linked_list *list = createtll();
    struct task gettask;

    int gen_id=1;
    int count_r;
    bool work=1; int cmd; 
    while(work){
        printf("\nPrint list-1, Add task-2, Get task-3, Random generate task-4, Complete the work-5: ");
        scanf("%d", &cmd);
        switch(cmd)
        {
            case 1: 
                printfronttll(list);             
                break;
            case 2:
                createtask(list, &gen_id);
                break;
            case 3: 
                gettask = getfrontchoose(list);
                printf("\n***Getting task\n--------------------------------------------------]\n");
                printf("Inf:\n Id: %d \n Priority: %d ", gettask.id, gettask.priority);
                printf("\nMsg: %s", gettask.msg);
                printf("\n***Task removed from queue\n--------------------------------------------------]\n");
                break;
            case 4:
                printf("\nEnter count random tasks: ");
                scanf("%d", &count_r);
                if(count_r > 0)
                {
                    createrandomtask(list, &gen_id, count_r);
                }
                else{printf("\nError: need count > 0");}
                break;
            case 5:
                work=0;
                break;
            default: 
                printf("\nCommand not found \n");
                break;
        }
    }
    
    deletetll(&list);
    return 0;
}