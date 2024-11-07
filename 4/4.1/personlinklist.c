#include "personlinklist.h"

person_linked_list* createpll(){//Создание пустого экземпляра списка
    person_linked_list *tmp = (person_linked_list*) malloc(sizeof(person_linked_list));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
 
    return tmp; 
}

void deletepll(person_linked_list **list){//Удаление списка
    person_node *tmp = (*list)->head;
    person_node *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
}

int sortfrontpll(person_linked_list *list){//Сортировка через начало по алфавиту
    person_node *curr = (person_node*) malloc(sizeof(person_node));
    if (curr == NULL) {
        exit(1);
    }
    person_node *swap = (person_node*) malloc(sizeof(person_node));
    if (swap == NULL) {
        exit(1);
    }
    person_node *last = NULL;
    int swapped;
    do {
        swapped = 0;
        curr = list->head;

        while (curr->next != last) {
            if ((toupper(curr->pers.surname[0]) > toupper(curr->next->pers.surname[0]))) {
                if(curr->next == list->tail)
                {
                    swap = list->tail->prev;
                    list->tail->prev->next = NULL;
                    list->tail->next = list->head;
                    list->tail->prev = NULL;
                    list->head->prev = list->tail;
                    list->head = list->tail;
                    list->tail = swap;
                    return 1;
                }
                swap->next = curr->next->next;
                swap->prev = curr->next;
                if (curr != list->head)
                {
                    curr->prev->next = curr->next;
                }
                else
                {
                    list->head = curr->next;
                }
                if (curr->next->next != NULL)
                {
                    curr->next->next->prev = curr;
                }
                else
                {
                    list->tail = curr;
                }
                curr->next->prev = curr->prev;
                
                curr->next->next = curr;
                curr->prev = swap->prev;
                curr->next = swap->next;
                swapped = 1;
            }
            curr = curr->next;
        }
        last = curr;
    } while (swapped);
    return 0;
}

void pushfrontpll(person_linked_list *list, person_node *newnode){//Добавление через начало списка по алфавиту
    person_node *tmp = list->head;

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
        if( tmp->next != NULL && (toupper(tmp->pers.surname[0]) < toupper(newnode->pers.surname[0])))
        {
            tmp = tmp->next;
        }
        else if (tmp->next == NULL && (toupper(tmp->pers.surname[0]) < toupper(newnode->pers.surname[0])))
        {
            tmp->next = newnode;
            newnode->next = NULL;
            newnode->prev = tmp;
            list->tail = newnode;
            break;
        }
        else
        {
            if (list->head == tmp)
            {
                list->head = newnode;
                newnode->prev = tmp->prev;
                newnode->next = tmp;
                tmp->prev = newnode;
            }
            else
            {
                newnode->prev = tmp->prev;
                newnode->next = tmp;
                tmp->prev->next = newnode;
                tmp->prev = newnode;
            }
            
            break;
        }
    }
    list->size++;
}

void editfrontpll(person_linked_list *list, char nameonf[], char surnameof[], int cmdonf, char newfield[]){//Редактирование через начало списка
    
    person_node *search = list->head;

    while (search != NULL) {
        if (!strcmp(search->pers.name, nameonf) && !strcmp(search->pers.surname, surnameof))
        {
            switch(cmdonf)
            {
                case 1: 
                    strcpy(search->pers.surname, newfield);
                    if (sortfrontpll(list) == 1){sortfrontpll(list);}
                    break;
                case 2: 
                    strcpy(search->pers.name, newfield);
                    break;
                case 3: 
                    strcpy(search->pers.name, newfield);
                    break;
                case 4: 
                    strcpy(search->pers.infwork.placewp, newfield);
                    break;
                case 5: 
                    strcpy(search->pers.infwork.postp, newfield);
                    break;
                case 6: 
                    strcpy(search->pers.infconn.mobphonep, newfield);
                    break;
                case 7: 
                    strcpy(search->pers.infconn.addressemailp, newfield);
                    break;
                case 8: 
                    strcpy(search->pers.infconn.linksnp, newfield);
                    break;
            }
        }
        search = search->next;
    }
}

void deletefrontpll(person_linked_list *list, char nameonf[], char surnameof[]){//Удаление через начало списка

    person_node *search = list->head;

    while (search != NULL) {
        if (!strcmp(search->pers.name, nameonf) && !strcmp(search->pers.surname, surnameof))
        {
            if (list->size == 1)
            {
                list->head = NULL;
                list->tail = NULL;
                free(search);
                list->size--;
                break;
            }

            if(search->next != NULL && search != list->head)
            {
                search->next->prev = search->prev;
                search->prev->next = search->next;
            }
            else if (search->next == NULL)
            {
                search->prev->next = NULL;
                list->tail = search->prev;
            }
            else
            {
                search->next->prev = NULL;
                list->head = search->next;
            }
            free(search);
            list->size--;
            break;
        }
        search = search->next;
    }
}