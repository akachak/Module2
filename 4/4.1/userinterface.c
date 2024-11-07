#include "userinterface.h"

bool checkonvoidstr(char str[20]){
    if (strcmp(str, "\n\0")==0)
    {
        return false;
    }
    
    return true;
}

struct person enternamesurname(){
    struct person fpers;
    char clean[2];
    char nameonf[TWENTY_SIZE];
    char surnameof[TWENTY_SIZE];
    
    fgets (clean, 2 ,stdin);
    while (true)
    {
        printf("\nEnter surname: ");
        fgets(surnameof, TWENTY_SIZE, stdin);
        
        printf("Enter name: ");
        fgets(nameonf, TWENTY_SIZE, stdin);
        
        if (!checkonvoidstr(nameonf) || !checkonvoidstr(surnameof))
        {
            printf("The surname and name fields cannot be empty! Sorry, try again\n");
        }
        else{break;}
    }
    strcpy(fpers.name, nameonf);
    strcpy(fpers.surname, surnameof);
    
    return fpers;

}

person_node* createperson(){

    person_node *newnode = (person_node*) malloc(sizeof(person_node));
    if (newnode == NULL) {
        exit(1);
    }
    struct person fpers = enternamesurname();
    char clean[2];
 
    strcpy(newnode->pers.surname, fpers.surname);
    strcpy(newnode->pers.name, fpers.name);
    
    fgets (clean, 2 ,stdin);
    printf("Enter midname or skip(enter): ");
    fgets(newnode->pers.lastname, TWENTY_SIZE, stdin);
    
    printf("Enter place of work or skip(enter): ");
    fgets(newnode->pers.infwork.placewp, FIFTY_SIZE, stdin);
    
    printf("Enter post or skip(enter): ");
    fgets(newnode->pers.infwork.postp, THIRTY_SIZE, stdin);
    
    printf("Enter mobile phone in format 89********* or skip(enter): ");
    fgets(newnode->pers.infconn.mobphonep, 12, stdin);
    
    printf("Enter email or skip(enter): ");
    fgets( newnode->pers.infconn.addressemailp, THIRTY_SIZE, stdin);
    
    printf("Enter link on social network or skip(enter): ");
    fgets( newnode->pers.infconn.linksnp, 200, stdin);

    return newnode;
}

void editperson(person_linked_list *list){
    bool workonf=1; int cmdonf;
    char clean[2];
    char twenty[TWENTY_SIZE];
    char thirty[THIRTY_SIZE];
    char fifgty[FIFTY_SIZE];
    char twenteen[12];
    char twohund[200];

    struct person fpers = enternamesurname();

            while(workonf){
                printf("\nEdit surname-1,\n Edit name-2,\n Edit midname-3,\n Edit place of work-4,\n Edit post-5,\n Edit mobile phone number-6,\n Edit email-7,\n Edit link on sn-8,\n Exit-9\n: ");
                scanf("%d", &cmdonf);
                switch(cmdonf)
                {
                    case 1: 
                        printf("\nEnter surname: ");
                        fgets (clean, 2 ,stdin);
                        fgets(twenty, TWENTY_SIZE, stdin);
                        if (!checkonvoidstr(twenty))
                        {
                            printf("The surname and name fields cannot be empty! Return to the menu\n");
                            break;
                        }
                        editfrontpll(list, fpers.name, fpers.surname, cmdonf, twenty);
                        break;
                    case 2: 
                        printf("\nEnter name: ");
                        fgets (clean, 2 ,stdin);
                        fgets(twenty, TWENTY_SIZE, stdin);
                        if (!checkonvoidstr(twenty))
                        {
                            printf("The surname and name fields cannot be empty! Return to the menu\n");
                            break;
                        }
                        editfrontpll(list, fpers.name, fpers.surname, cmdonf, twenty);
                        break;
                    case 3: 
                        printf("\nEnter midname: ");
                        fgets (clean, 2 ,stdin);
                        fgets(twenty, TWENTY_SIZE, stdin);
                        editfrontpll(list, fpers.name, fpers.surname, cmdonf, twenty);
                        break;
                    case 4: 
                        printf("\nEnter place of work: ");
                        fgets (clean, 2 ,stdin);
                        fgets(fifgty, FIFTY_SIZE, stdin);
                        editfrontpll(list, fpers.name, fpers.surname, cmdonf, fifgty);
                        break;
                    case 5: 
                        printf("\nEnter post: ");
                        fgets (clean, 2 ,stdin);
                        fgets(thirty, THIRTY_SIZE, stdin);
                        editfrontpll(list, fpers.name, fpers.surname, cmdonf, thirty);
                        break;
                    case 6: 
                        printf("\nEnter mobile phone number: ");
                        fgets (clean, 2 ,stdin);
                        fgets(twenteen, 12, stdin);
                        editfrontpll(list, fpers.name, fpers.surname, cmdonf, twenteen);
                        break;
                    case 7: 
                        printf("\nEnter email: ");
                        fgets (clean, 2 ,stdin);
                        fgets(thirty, THIRTY_SIZE, stdin);
                        editfrontpll(list, fpers.name, fpers.surname, cmdonf, thirty);
                        break;
                    case 8: 
                        printf("\nEnter link on sn: ");
                        fgets (clean, 2 ,stdin);
                        fgets(twohund, 200, stdin);
                        editfrontpll(list, fpers.name, fpers.surname, cmdonf, twohund);
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

void deleteperson(person_linked_list *list){
    struct person fpers = enternamesurname();
    deletefrontpll(list, fpers.name, fpers.surname);
}

void pushperson(person_linked_list *list){
    pushfrontpll(list, createperson());
}

void printpersons(person_linked_list *list){
    int print;
    printf("\nFront print-1, Back print-2: ");
    scanf("%d", &print);
    if (print == 1)
    {
        printfrontpll(list);
    }
    else if (print = 2)
    {
        printbackpll(list);
    } 
}