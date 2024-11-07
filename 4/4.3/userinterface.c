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
