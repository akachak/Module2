#include "persontreelist.h"

bool checkonvoidstr(char str[20]){
    if (strcmp(str, "\n\0")==0)
    {
        return false;
    }
    
    return true;
}

person createPerson(){
    char clean[2];
    char nameonf[TWENTY_SIZE];
    char surnameof[TWENTY_SIZE];
    person tmp;
    bool workonf = 1;

    fgets (clean, 2 ,stdin);
    while(workonf)
    {
        printf("\nEnter surname: ");
        fgets(surnameof, TWENTY_SIZE, stdin);
        
        printf("Enter name: ");
        fgets(nameonf, TWENTY_SIZE, stdin);
        
        if (!checkonvoidstr(nameonf) || !checkonvoidstr(surnameof))
        {
            printf("The surname and name fields cannot be empty! Try again\n");
        }
        else{workonf=0;}
    }
    
    strcpy(tmp.name, nameonf);
    strcpy(tmp.surname, surnameof);

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

    return tmp;
}

person_node_tree* createNode(){
    person_node_tree* newNode = (person_node_tree*)malloc(sizeof(person_node_tree));
    newNode->pn = createPerson();
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}