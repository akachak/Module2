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

int sortfrontpll(person_linked_list *list){//Сортировка через начало по алфавиту
    person_node *curr = (person_node*) malloc(sizeof(person_node));
    if (curr == NULL) {
        exit(1);
    }
    person_node *swap = (person_node*) malloc(sizeof(person_node));
    if (swap == NULL) {
        exit(1);
    }
    person_node *swap_two = (person_node*) malloc(sizeof(person_node));
    if (swap == NULL) {
        exit(1);
    }
    person_node *last = NULL;
    int swapped;
    do {
        swapped = 0;
        curr = list->head;

        while (curr->next != last) {
            if ((toupper(curr->surname[0]) > toupper(curr->next->surname[0]))) {
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

void pushfrontpll(person_linked_list *list){//Добавление через начало списка по алфавиту
    person_node *newnode = (person_node*) malloc(sizeof(person_node));
    if (newnode == NULL) {
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
    strcpy(newnode->name, nameonf);
    strcpy(newnode->surname, surnameof);

    printf("Enter midname or skip(enter): ");
    fgets(newnode->lastname, TWENTY_SIZE, stdin);
    
    printf("Enter place of work or skip(enter): ");
    fgets(newnode->infwork.placewp, FIFTY_SIZE, stdin);
    
    printf("Enter post or skip(enter): ");
    fgets(newnode->infwork.postp, THIRTY_SIZE, stdin);
    
    printf("Enter mobile phone in format 89********* or skip(enter): ");
    fgets(newnode->infconn.mobphonep, 12, stdin);
    
    printf("Enter email or skip(enter): ");
    fgets( newnode->infconn.addressemailp, THIRTY_SIZE, stdin);
    
    printf("Enter link on social network or skip(enter): ");
    fgets( newnode->infconn.linksnp, 200, stdin);

    
    person_node *tmp = list->head;

    if (list->size == 0) {
        list->head = newnode;
        list->tail = newnode;
        list->size++;
        return;
    }

    while(true)
    {
        if( tmp->next != NULL && (toupper(tmp->surname[0]) < toupper(newnode->surname[0])))
        {
            tmp = tmp->next;
        }
        else if (tmp->next == NULL && (toupper(tmp->surname[0]) < toupper(newnode->surname[0])))
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

void printfrontpll(person_linked_list *list){//Принт с начала списка
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

void printbackpll(person_linked_list *list){//Принт с конца списка
    person_node *tmp = list->tail;
    printf("Forward List: ");
    while (tmp != NULL) {
        printf("\n");
        printf("Full name:\n S: %s N: %s L: %s", tmp->surname, tmp->name, tmp->lastname);
        printf("Place of work: %s", tmp->infwork.placewp);
        printf("Post: %s", tmp->infwork.postp);
        printf("Mobile phone: %s", tmp->infconn.mobphonep);
        printf("Email: %s", tmp->infconn.addressemailp);
        printf("Link on sn: %s", tmp->infconn.linksnp);
        tmp = tmp->prev;
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
            bool workonf=1; int cmdonf;
            while(workonf){
                printf("\nEdit surname-1,\n Edit name-2,\n Edit midname-3,\n Edit place of work-4,\n Edit post-5,\n Edit mobile phone number-6,\n Edit email-7,\n Edit link on sn-8,\n Exit-9\n: ");
                scanf("%d", &cmdonf);
                switch(cmdonf)
                {
                    case 1: 
                        printf("\nEnter surname: ");
                        fgets (clean, 2 ,stdin);
                        fgets(surnameof, TWENTY_SIZE, stdin);
                        if (!checkonvoidstr(surnameof))
                        {
                            printf("The surname and name fields cannot be empty! Return to the menu\n");
                            break;
                        }
                        strcpy(search->surname, surnameof);
                        if (sortfrontpll(list) == 1)
                        {
                            sortfrontpll(list);
                        }
                        break;
                    case 2: 
                        printf("\nEnter name: ");
                        fgets (clean, 2 ,stdin);
                        fgets(nameonf, TWENTY_SIZE, stdin);
                        if (!checkonvoidstr(nameonf))
                        {
                            printf("The surname and name fields cannot be empty! Return to the menu\n");
                            break;
                        }
                        strcpy(search->name, nameonf);
                        break;
                    case 3: 
                        printf("\nEnter midname: ");
                        fgets (clean, 2 ,stdin);
                        fgets(search->lastname, TWENTY_SIZE, stdin);
                        break;
                    case 4: 
                        printf("\nEnter place of work: ");
                        fgets (clean, 2 ,stdin);
                        fgets(search->infwork.placewp, FIFTY_SIZE, stdin);
                        break;
                    case 5: 
                        printf("\nEnter post: ");
                        fgets (clean, 2 ,stdin);
                        fgets(search->infwork.postp, THIRTY_SIZE, stdin);
                        break;
                    case 6: 
                        printf("\nEnter mobile phone number: ");
                        fgets (clean, 2 ,stdin);
                        fgets(search->infconn.mobphonep, 12, stdin);
                        break;
                    case 7: 
                        printf("\nEnter email: ");
                        fgets (clean, 2 ,stdin);
                        fgets( search->infconn.addressemailp, THIRTY_SIZE, stdin);
                        break;
                    case 8: 
                        printf("\nEnter link on sn: ");
                        fgets (clean, 2 ,stdin);
                        fgets( search->infconn.linksnp, 200, stdin);
                        break;
                    case 9:
                        workonf=0;
                        break;
                    default: 
                        printf("\nCommand not found \n");
                        break;
                }
            }
        }
        search = search->next;
    }
}

void deletefrontpll(person_linked_list *list){//Удаление через начало списка

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

    person_node *search = list->head;

    while (search != NULL) {
        if (!strcmp(search->name, nameonf) && !strcmp(search->surname, surnameof))
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