#include "userinterface.h"

bool checkonvoidstr(char str[20]){
    if (strcmp(str, "\n\0")==0)
    {
        return false;
    }
    
    return true;
}

int generatekey(int *basecount, char surnameof[]){
    int size_tree = 1000;
    int key = toupper(surnameof[0]) * size_tree + *basecount;
    *basecount = *basecount + 1;
    return key;
}

person enternamesurname(){
    person fpers;
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

person createPerson(int *basecount){

    person tmp = enternamesurname();

    printf("Enter midname or skip(enter): ");
    fgets(tmp.lastname, TWENTY_SIZE, stdin);
    
    printf("Enter place of work or skip(enter): ");
    fgets(tmp.infwork.placewp, FIFTY_SIZE, stdin);
    
    printf("Enter post or skip(enter): ");
    fgets(tmp.infwork.postp, THIRTY_SIZE, stdin);
    
    printf("Enter mobile phone in format 89********* or skip(enter): ");
    fgets(tmp.infconn.mobphonep, 12, stdin);
    
    printf("Enter email or skip(enter): ");
    fgets( tmp.infconn.addressemailp, THIRTY_SIZE, stdin);
    
    printf("Enter link on social network or skip(enter): ");
    fgets( tmp.infconn.linksnp, 200, stdin);

    tmp.keyfortree = generatekey(basecount, tmp.surname);

    return tmp;
}

void print_in_order(person_node_tree *node)
{
  if(node != NULL)
  {
    print_in_order(node->left);
    printf("key: %d\n ",node->pn.keyfortree);
        printf("Full name:\n S: %s N: %s L: %s", node->pn.surname, node->pn.name, node->pn.lastname);
        printf("Place of work: %s", node->pn.infwork.placewp);
        printf("Post: %s", node->pn.infwork.postp);
        printf("Mobile phone: %s", node->pn.infconn.mobphonep);
        printf("Email: %s", node->pn.infconn.addressemailp);
        printf("Link on sn: %s", node->pn.infconn.linksnp);
        printf("\n");
    print_in_order(node->right);
  }
}

person* nodeInTree(person_tree* tree, person* fpers, int *count_node){
    int size_tree = 1000;
    int st_search = toupper(fpers->surname[0]) * size_tree;
    int end_search = *count_node + st_search;
    person* tmp = (person*)malloc(sizeof(person));
    for (st_search; st_search < end_search; st_search++)
    {
        tmp = searchNode(tree->root, &st_search);
        if(tmp != NULL && !strcmp(tmp->surname, fpers->surname) && !strcmp(tmp->name, fpers->name))
        {   
            return tmp;
        }
            
    }
    return NULL;

}

void deleteperson(person_tree *tree, int *count_node){
    person fpers = enternamesurname();
    person* ressearching = nodeInTree(tree, &fpers, count_node);
    if(ressearching != NULL)
    {
        tree->root = deleteNode(tree->root, ressearching->keyfortree);
    }
    else
    {
        printf("Person not found\n");
    }

}

void editperson(person_tree *tree, int *count_node){
    bool workonf=1; int cmdonf;
    char clean[2];
    char twenty[TWENTY_SIZE];
    char thirty[THIRTY_SIZE];
    char fifgty[FIFTY_SIZE];
    char twenteen[12];
    char twohund[200];
    
    person fpers = enternamesurname();
    person* ressearching = nodeInTree(tree, &fpers, count_node);
    if(ressearching != NULL)
    {
        while(workonf){
                printf("\nEdit surname-1,\n Edit name-2,\n Edit midname-3,\n Edit place of work-4,\n Edit post-5,\n Edit mobile phone number-6,\n Edit email-7,\n Edit link on sn-8,\n Exit-9\n: ");
                scanf("%d", &cmdonf);
                switch(cmdonf)
                {
                    case 1: 
                        person tmp = *ressearching;
                        printf("\nEnter surname: ");
                        fgets (clean, 2 ,stdin);
                        fgets(twenty, TWENTY_SIZE, stdin);
                        if (!checkonvoidstr(twenty))
                        {
                            printf("The surname and name fields cannot be empty! Return to the menu\n");
                            break;
                        }
                        strcpy(tmp.surname, twenty);
                        tree->root = deleteNode(tree->root, ressearching->keyfortree);
                        tmp.keyfortree = generatekey(count_node, tmp.surname);
                        tree->root = insertNode(tree->root, tmp);
                        workonf=0;
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
                        strcpy(ressearching->name, twenty);
                        break;
                    case 3: 
                        printf("\nEnter midname: ");
                        fgets (clean, 2 ,stdin);
                        fgets(twenty, TWENTY_SIZE, stdin);
                        strcpy(ressearching->lastname, twenty);
                        break;
                    case 4: 
                        printf("\nEnter place of work: ");
                        fgets (clean, 2 ,stdin);
                        fgets(fifgty, FIFTY_SIZE, stdin);
                        strcpy(ressearching->infwork.placewp, fifgty);
                        break;
                    case 5: 
                        printf("\nEnter post: ");
                        fgets (clean, 2 ,stdin);
                        fgets(thirty, THIRTY_SIZE, stdin);
                        strcpy(ressearching->infwork.postp, thirty);
                        break;
                    case 6: 
                        printf("\nEnter mobile phone number: ");
                        fgets (clean, 2 ,stdin);
                        fgets(twenteen, 12, stdin);
                        strcpy(ressearching->infconn.mobphonep, twenteen);
                        break;
                    case 7: 
                        printf("\nEnter email: ");
                        fgets (clean, 2 ,stdin);
                        fgets(thirty, THIRTY_SIZE, stdin);
                        strcpy(ressearching->infconn.addressemailp, thirty);
                        break;
                    case 8: 
                        printf("\nEnter link on sn: ");
                        fgets (clean, 2 ,stdin);
                        fgets(twohund, 200, stdin);
                        strcpy(ressearching->infconn.linksnp, twohund);
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
    else
    {
        printf("Person not found\n");
    }
            
}