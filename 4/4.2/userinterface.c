#include "userinterface.h"

int enterprior(){
    int pr;
    while (true)
    {
        printf("\nEnter priority task: ");
        scanf("%d", &pr);
        if (pr >= 0 && pr <= 255)
        {
            return pr;
        }
        else{printf("\nSorry. Try again.");}
    }
}

void createtask(task_linked_list *list, int *cgr){
    struct task tmp;
    char clean[2];
    
    tmp.priority = enterprior();
    fgets (clean, 2 ,stdin);
    printf("Enter msg task: ");
    fgets(tmp.msg, 100, stdin);

    tmp.id = *cgr;

    *cgr = *cgr + 1;
    pushbacktll(list, tmp);

}

void createrandomtask(task_linked_list *list, int *cgr, int counter){
    struct task tmp;
    char str_d[100];
    char str[20]; 
    for (int i=0; i<counter; i++)
    {
        strcpy(str_d, "Random msg-");
        strcpy(str, "");
        tmp.id = *cgr;
        tmp.priority = rand() % (256);
        int msg_rnd = rand();
        
        sprintf(str, "%d", msg_rnd);
        char* result = strcat(str_d, str);
        result = strcat(str_d, "\n");
        strcpy(tmp.msg, str_d);
        *cgr = *cgr + 1;
        pushbacktll(list, tmp);
    }
}

void printfronttll(task_linked_list *list){//Принт с начала списка
    task_node *tmp = list->head;
    printf("\nQueue list");
    while (tmp != NULL) {
        printf("\n--------------------------------------------------]\n");
        printf("Inf:\n Id: %d \n Priority: %d  <-- Sorted by this field ", tmp->nodetask.id, tmp->nodetask.priority);
        printf("\nMsg: %s", tmp->nodetask.msg);
        tmp = tmp->next;
    }
}

struct task getfrontchoose(task_linked_list *list){
    struct task retget;
    int cmdonf; bool workonf=1; int prior;

    printf("\nGet first task in queue-1, Get task by priority-2, Get task not higher priority-3: ");
    scanf("%d", &cmdonf);
    switch (cmdonf)
    {
    case 1:
        retget = getfrontfirst(list);
        deletetaskbyid(list, retget.id);
        return retget;
        break;
    case 2:
        prior = enterprior();
        retget = getfrontbypr(list, prior);
        deletetaskbyid(list, retget.id);
        return retget;
        break;
    case 3:
        prior = enterprior();
        retget = getfrontnothigh(list, prior);
        deletetaskbyid(list, retget.id);
        return retget;
        break;
    default:
        printf("\nCommand not found \n");
        break;
    }
    
}