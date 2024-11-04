#include "queue.h"

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

struct task createtask(int *cgr){
    struct task tmp;
    char clean[2];
    
    tmp.priority = enterprior();
    fgets (clean, 2 ,stdin);
    printf("Enter msg task: ");
    fgets(tmp.msg, 100, stdin);

    tmp.id = *cgr;
    return tmp;
}

struct task createrandomtask(int *cgr){
    struct task tmp;

    tmp.id = *cgr;
    tmp.priority = rand() % (256);
    int msg_rnd = rand();
    
    char str_d[100] = "Random msg-";
    char str[20]; sprintf(str, "%d", msg_rnd);
    char* result = strcat(str_d, str);
    result = strcat(str_d, "\n");
    strcpy(tmp.msg, str_d);

    return tmp;
}

task_linked_list* createtll(){//Создание пустого экземпляра списка
    task_linked_list *tmp = (task_linked_list*) malloc(sizeof(task_linked_list));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
    return tmp; 
}

void deletetll(task_linked_list **list){//Удаление списка
    task_node *tmp = (*list)->head;
    task_node *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
}

void pushbacktll(task_linked_list *list, bool checkrandom, int *cgr, int *count_r){//Добавление через конец очереди по приоритету
    task_node *newnode = (task_node*) malloc(sizeof(task_node));
    if (newnode == NULL) {
        exit(1);
    }

    if(checkrandom)
    {
        newnode->nodetask = createrandomtask(cgr);
        *cgr =*cgr + 1;
    }
    else
    {
        newnode->nodetask = createtask(cgr);
        *cgr =*cgr + 1;
    }
    task_node *tmp = list->tail;

    if (list->size == 0) {
        list->head = newnode;
        list->tail = newnode;
        newnode->next = NULL;
        newnode->prev = NULL;
        list->size++;
        if(*count_r != 0)
        {
            *count_r = *count_r - 1;
            pushbacktll(list, true, cgr, count_r);
        }
        return;
    }

    while(true)
    {
        if( tmp->prev != NULL && tmp->nodetask.priority > newnode->nodetask.priority)
        {
            tmp = tmp->prev;
        }
        else if (tmp->prev == NULL && tmp->nodetask.priority > newnode->nodetask.priority)
        {
            tmp->prev = newnode;
            newnode->prev = NULL;
            newnode->next = tmp;
            list->head = newnode;
            break;
        }
        else
        {
            if (list->tail == tmp)
            {
                list->tail = newnode;
                newnode->next = tmp->next;
                newnode->prev = tmp;
                tmp->next = newnode;
            }
            else
            {
                newnode->next = tmp->next;
                newnode->prev = tmp;
                tmp->next->prev = newnode;
                tmp->next = newnode;
            }
            
            break;
        }
    }
    list->size++;
    if(*count_r != 0)
    {
        *count_r = *count_r - 1;
        pushbacktll(list, true, cgr, count_r);
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

int getprintfronttll(task_linked_list *list, bool checkcmd, int prior)
{
    task_node *tmp = list->head; bool flag_scn = 0;

    if(checkcmd)
    {
        while (tmp != NULL) {
            if(tmp->nodetask.priority == prior && tmp->next->nodetask.priority == prior)
            {
                printf("\n--------------------------------------------------]\n");
                printf("Inf:\n Id: %d \n Priority: %d  <-- Sorted by this field ", tmp->nodetask.id, tmp->nodetask.priority);
                printf("\nMsg: %s", tmp->nodetask.msg);
                flag_scn = 1;
            }
            else if(tmp->nodetask.priority == prior && flag_scn)
            {
                printf("\n--------------------------------------------------]\n");
                printf("Inf:\n Id: %d \n Priority: %d  <-- Sorted by this field ", tmp->nodetask.id, tmp->nodetask.priority);
                printf("\nMsg: %s", tmp->nodetask.msg);
                flag_scn = 1;
            }
            else if(flag_scn)
            {
                printf("***Enter id for choose\n--------------------------------------------------]\n");
                return 0;
            }
            else if(tmp->nodetask.priority == prior && !flag_scn)
            {
                return tmp->nodetask.id;
            }
            tmp = tmp->next;
        }
    }
    else
    {
        while (tmp != NULL) {
            if(tmp->nodetask.priority <= prior)
            {
                printf("\n--------------------------------------------------]\n");
                printf("Inf:\n Id: %d \n Priority: %d  <-- Sorted by this field ", tmp->nodetask.id, tmp->nodetask.priority);
                printf("\nMsg: %s", tmp->nodetask.msg);
                tmp = tmp->next;
            }
            else
            {
                printf("***Enter id for choose\n--------------------------------------------------]\n");
                return 0;
            }
        }
    }
    
}

bool checkbyid(task_linked_list *list, int checkid){
    task_node *tmp = list->head;

    while (tmp != NULL) {
        if(tmp->nodetask.id == checkid)
        {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

struct task gettaskbyid (task_linked_list *list, int getid){//Принт с начала списка
    task_node *tmp = list->head;
    struct task gettsk;

    while (tmp != NULL) {
        if(tmp->nodetask.id == getid)
        {
            gettsk = tmp->nodetask;
            return gettsk;
        }
        tmp = tmp->next;
    }
}

void deletetaskbyid(task_linked_list *list, int delid){
    task_node *tmp = list->head;
    while (tmp != NULL) {
        if (tmp->nodetask.id == delid)
        {
            if(list->head == tmp)
            {
                if (list->size > 1)
                {
                    list->head->next->prev = NULL;
                    list->head = list->head->next;
                    list->size--;
                }
                else
                {
                    list->head = NULL;
                    list->tail = NULL;
                    list->size--;
                }
            }
            else if(list->tail == tmp)
            {
                if (list->size > 1)
                {
                    list->tail->prev->next = NULL;
                    list->tail = list->tail->prev;
                    list->size--;
                }
                else
                {
                    list->head = NULL;
                    list->tail = NULL;
                    list->size--;
                }
            }
            else
            {
                tmp->next->prev = tmp->prev;
                tmp->prev->next = tmp->next;
                list->size--;
            }
        }
        tmp = tmp->next;
    }
}

struct task getfronttll(task_linked_list *list){
    struct task retget;
    bool work=1; int cmd; int pr; int sid; int gid;
    while(work){
        printf("\nGet first task in queue-1, Get task by priority-2, Get task not lower priority-3, Exit-4: ");
        scanf("%d", &cmd);
        switch(cmd)
        {
            case 1:
                retget = list->head->nodetask;
                deletetaskbyid(list, list->head->nodetask.id);
                return retget;
            case 2: 
                printf("\nEnter priority: ");
                scanf("%d", &pr);
                sid = getprintfronttll(list, true, pr);
                if(sid != 0)
                {
                    retget = gettaskbyid(list, sid);
                    deletetaskbyid(list, sid);
                    return retget;
                }
                else
                {
                    printf(": ");
                    scanf("%d", &gid);
                    if(checkbyid(list, gid))
                    {
                        retget = gettaskbyid(list, gid);
                        deletetaskbyid(list, gid);
                    }
                    else
                    {
                        printf("\nError\n");
                        break;
                    }
                    
                    return retget;
                }
                break;
            case 3: 
                printf("\nEnter priority: ");
                scanf("%d", &pr);
                sid = getprintfronttll(list, false, pr);
                printf(": ");
                scanf("%d", &gid);
                if(checkbyid(list, gid))
                {
                    retget = gettaskbyid(list, gid);
                    deletetaskbyid(list, gid);
                }
                else
                {
                    printf("\nError\n");
                    break;
                }
                return retget;
                break;
            case 4:
                work=0;
                break;
        }
    }
}