#include "personlinklist.h"

bool checkonvoidstr(char str[20]){
    if (strcmp(str, "\n\0")==0)
    {
        return false;
    }
    
    return true;
}

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

void pushfrontpll(person_linked_list *list){//Добавление через начало списка
    person_node *tmp = (person_node*) malloc(sizeof(person_node));
    if (tmp == NULL) {
        exit(1);
    }

    char clean[2];
    char nameonf[TWENTY_SIZE];
    char surnameof[TWENTY_SIZE];
    
    fgets (clean, 2 ,stdin);
    
    printf("\nEnter surname: ");
    fgets(surnameof, TWENTY_SIZE, stdin);
    
    printf("Enter name: ");
    fgets(nameonf, TWENTY_SIZE, stdin);
    
    if (!checkonvoidstr(nameonf) || !checkonvoidstr(surnameof))
    {
        printf("The surname and name fields cannot be empty! Return to the menu\n");
        return;
    }
    strcpy(tmp->name, nameonf);
    strcpy(tmp->surname, surnameof);

    printf("Enter midname or skip(enter): ");
    fgets(tmp->lastname, TWENTY_SIZE, stdin);
    
    printf("Enter place of work or skip(enter): ");
    fgets(tmp->infwork.placewp, FIFTY_SIZE, stdin);
    
    printf("Enter post or skip(enter): ");
    fgets(tmp->infwork.postp, THIRTY_SIZE, stdin);
    
    printf("Enter mobile phone in format 89********* or skip(enter): ");
    fgets(tmp->infconn.mobphonep, 12, stdin);
    
    printf("Enter email or skip(enter): ");
    fgets( tmp->infconn.addressemailp, THIRTY_SIZE, stdin);
    
    printf("Enter link on social network or skip(enter): ");
    fgets( tmp->infconn.linksnp, 200, stdin);

    
    person_node *swap = (person_node*) malloc(sizeof(person_node));
    if (swap == NULL) {
        exit(1);
    }

    tmp->next = list->head;
    tmp->prev = NULL;

    if (list->head) {
        list->head->prev = tmp;
    }
    list->head = tmp;
 
    if (list->tail == NULL) {
        list->tail = tmp;
    }

    while(true)
    {
        if( list->size != 0 && tmp->next != NULL && (toupper(tmp->next->surname[0]) < toupper(tmp->surname[0])))
        {
            swap->next = tmp->next->next;

            tmp->next->next = tmp;
            tmp->next->prev = tmp->prev;

            tmp->prev = tmp->next;
            tmp->next = swap->next;
            
            if(swap->next == NULL)
            {
                list->tail = tmp;
            }
            if (tmp->prev->prev == NULL)
            {
                list->head = tmp->prev;
            }

            swap->next = NULL;
        }
        else{break;}
    }
    list->size++;
}

void printpll(person_linked_list *list){//Принт с начала списка
    person_node *tmp = list->head;
    printf("Forward List: ");
    while (tmp != NULL) {
        printf("\n");
        printf("Full name:\n S: %s N: %s L: %s", tmp->surname, tmp->name, tmp->lastname);
        printf("Place of work: %s", tmp->infwork.placewp);
        printf("Post: %s", tmp->infwork.postp);
        printf("Mobile phone: %s", tmp->infconn.mobphonep);
        printf("Email: %s", tmp->infconn.addressemailp);
        printf("Link on sn: %s", tmp->infconn.linksnp);
        tmp = tmp->next;
    }
}

void editfrontpll(person_linked_list *list){//Редактирование через начало списка
    person_node *tmp = (person_node*) malloc(sizeof(person_node));
    if (tmp == NULL) {
        exit(1);
    }

    char clean[2];
    char nameonf[TWENTY_SIZE];
    char surnameof[TWENTY_SIZE];
    
    fgets (clean, 2 ,stdin);
    
    printf("\nEnter surname for edit: ");
    fgets(surnameof, TWENTY_SIZE, stdin);
    
    printf("Enter name for edit: ");
    fgets(nameonf, TWENTY_SIZE, stdin);
    
    if (!checkonvoidstr(nameonf) || !checkonvoidstr(surnameof))
    {
        printf("The surname and name fields cannot be empty! Return to the menu\n");
        return;
    }
    strcpy(tmp->name, nameonf);
    strcpy(tmp->surname, surnameof);

    person_node *search = list->head;

    while (search != NULL) {
        if (!strcmp(search->name, tmp->name) && !strcmp(search->surname, tmp->surname))
        {
            printf("nashel");
        }
        search = search->next;
    }
}

void deletefrontpll(person_linked_list *list){//Удаление через начало списка
    person_node *tmp = (person_node*) malloc(sizeof(person_node));
    if (tmp == NULL) {
        exit(1);
    }

    char clean[2];
    char nameonf[TWENTY_SIZE];
    char surnameof[TWENTY_SIZE];
    
    fgets (clean, 2 ,stdin);
    
    printf("\nEnter surname for delete: ");
    fgets(surnameof, TWENTY_SIZE, stdin);
    
    printf("Enter name for delete: ");
    fgets(nameonf, TWENTY_SIZE, stdin);
    
    if (!checkonvoidstr(nameonf) || !checkonvoidstr(surnameof))
    {
        printf("The surname and name fields cannot be empty! Return to the menu\n");
        return;
    }
    strcpy(tmp->name, nameonf);
    strcpy(tmp->surname, surnameof);

    person_node *search = list->head;

    while (search != NULL) {
        if (!strcmp(search->name, tmp->name) && !strcmp(search->surname, tmp->surname))
        {
            if(search->next != NULL)
            {
                search->next->prev = search->prev;
                search->prev->next = search->next;
            }
            else
            {
                search->prev->next = search->next;
            }
            //free(search);
            break;
        }
        search = search->next;
    }
}