#include "queue.h"

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

void pushbacktll(task_linked_list *list, struct task newtask){//Добавление через конец очереди по приоритету
    task_node *newnode = (task_node*) malloc(sizeof(task_node));
    if (newnode == NULL) {
        exit(1);
    }
    newnode->nodetask = newtask;
    task_node *tmp = list->tail;

    if (list->size == 0) {
        list->head = newnode;
        list->tail = newnode;
        newnode->next = NULL;
        newnode->prev = NULL;
        list->size++;
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

struct task getfrontfirst(task_linked_list *list){
    if(list->head != NULL){
        return list->head->nodetask;
    }    
}

struct task getfrontbypr(task_linked_list *list, int prior){
    task_node *tmp = list->head;

    while (tmp != NULL) {
        if(tmp->nodetask.priority == prior)
        {
            return tmp->nodetask;
        }
        tmp = tmp->next;
    } 
}

struct task getfrontnothigh(task_linked_list *list, int prior){
    task_node *tmp = list->head;

    while (tmp != NULL) {
        if(tmp->nodetask.priority >= prior)
        {
            return tmp->nodetask;
        }
        tmp = tmp->next;
    }
}