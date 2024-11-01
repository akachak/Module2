#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include <locale.h> //��� �����
#include <Windows.h>

#define TWENTY_SIZE 20
#define THIRTY_SIZE 30
#define FIFTY_SIZE 50

struct workp
{
    char placewp[FIFTY_SIZE];
    char postp[THIRTY_SIZE];
};

struct connectfp
{
    char mobphonep[12];
    char addressemailp[THIRTY_SIZE];
    char linksnp[200];
};

struct person
{
    char name[TWENTY_SIZE];
    char surname[TWENTY_SIZE];
    char lastname[TWENTY_SIZE];
    struct workp infwork;
    struct connectfp infconn;
};

bool checkonvoidstr(char str[20]){
    if (strcmp(str, "\n\0")==0)
    {
        return false;
    }
    
    return true;
}

void printpers(struct person p[], int *count){
    printf("\n������������� �������: %d �� 50\n", *count);
    for(int i=0; i<*count; i++)
    {
        printf("\n������� �%d �� %d\n", i+1, *count);
        printf("������ ���:\n �: %s �: %s �: %s", p[i].surname, p[i].name, p[i].lastname);
        printf("����� ������: %s", p[i].infwork.placewp);
        printf("���������: %s", p[i].infwork.postp);
        printf("��������� �������: %s", p[i].infconn.mobphonep);
        printf("Email: %s", p[i].infconn.addressemailp);
        printf("������ �� ���.����: %s", p[i].infconn.linksnp);
    }
}

void addpers(struct person p[], int *count){
    char clean[2];
    char nameonf[TWENTY_SIZE];
    char surnameof[TWENTY_SIZE];
    
    fgets (clean, 2 ,stdin);
    
    printf("\n������� �������: ");
    fgets(surnameof, TWENTY_SIZE, stdin);
    
    printf("������� ���: ");
    fgets(nameonf, TWENTY_SIZE, stdin);
    
    if (!checkonvoidstr(nameonf) || !checkonvoidstr(surnameof))
    {
        printf("���� ������� � ��� �� ����� ���� �������! ������� � ����\n");
        return;
    }
    strcpy(p[*count].name, nameonf);
    strcpy(p[*count].surname, surnameof);
    
    printf("������� �������� ��� ����������(enter): ");
    fgets(p[*count].lastname, TWENTY_SIZE, stdin);
    
    printf("������� ����� ������ ��� ����������(enter): ");
    fgets(p[*count].infwork.placewp, FIFTY_SIZE, stdin);
    
    printf("������� ���������� ��������� ��� ����������(enter): ");
    fgets(p[*count].infwork.postp, THIRTY_SIZE, stdin);
    
    printf("������� ����� ���������� �������� � ������� 89********* ��� ����������(enter): ");
    fgets(p[*count].infconn.mobphonep, 12, stdin);
    
    printf("������� email ��� ����������(enter): ");
    fgets( p[*count].infconn.addressemailp, THIRTY_SIZE, stdin);
    
    printf("������� ������ �� ���.���� ��� ����������(enter): ");
    fgets( p[*count].infconn.linksnp, 200, stdin);
    
    *count = *count +1;
}

void editpers(struct person p[], int *count){
    char clean[2];
    char nameonf[TWENTY_SIZE];
    char surnameof[TWENTY_SIZE];
    
    fgets (clean, 2 ,stdin);
    printf("������� ������� � ��� ����, ��� ������� ���������� ���������������.\n");
    printf("�������: ");
    fgets(surnameof, TWENTY_SIZE, stdin);
    
    printf("���: ");
    fgets(nameonf, TWENTY_SIZE, stdin);
    
    if (!checkonvoidstr(nameonf) || !checkonvoidstr(surnameof))
    {
        printf("���� ������� � ��� �� ����� ���� �������! ������� � ����\n");
        return;
    }
    
    for(int i=0; i<*count; i++)
    {
        if(!strcmp(surnameof, p[i].surname) && !strcmp(nameonf, p[i].name))
        {
            bool workonf=1; int cmdonf;
            while(workonf){
                printf("\n������������� �������-1,\n ������������� ���-2,\n ������������� ��������-3,\n ������������� ����� ������-4,\n ������������� ���������-5,\n ������������� ����� ���������� ��������-6,\n ������������� email-7,\n ������������� ������ �� ���.����-8,\n �����-9\n: ");
                scanf("%d", &cmdonf);
                switch(cmdonf)
                {
                    case 1: 
                        printf("\n������� �������: ");
                        fgets (clean, 2 ,stdin);
                        fgets(surnameof, TWENTY_SIZE, stdin);
                        if (!checkonvoidstr(surnameof))
                        {
                            printf("���� ������� � ��� �� ����� ���� �������! ������� � ����\n");
                            break;
                        }
                        strcpy(p[i].surname, surnameof);
                        break;
                    case 2: 
                        printf("\n������� ���: ");
                        fgets (clean, 2 ,stdin);
                        fgets(nameonf, TWENTY_SIZE, stdin);
                        if (!checkonvoidstr(nameonf))
                        {
                            printf("���� ������� � ��� �� ����� ���� �������! ������� � ����\n");
                            break;
                        }
                        strcpy(p[i].name, nameonf);
                        break;
                    case 3: 
                        printf("\n������� ��������: ");
                        fgets (clean, 2 ,stdin);
                        fgets(p[i].lastname, TWENTY_SIZE, stdin);
                        break;
                    case 4: 
                        printf("\n������� ����� ������: ");
                        fgets (clean, 2 ,stdin);
                        fgets(p[i].infwork.placewp, FIFTY_SIZE, stdin);
                        break;
                    case 5: 
                        printf("\n������� ���������: ");
                        fgets (clean, 2 ,stdin);
                        fgets(p[i].infwork.postp, THIRTY_SIZE, stdin);
                        break;
                    case 6: 
                        printf("\n������� ����� ��������: ");
                        fgets (clean, 2 ,stdin);
                        fgets(p[i].infconn.mobphonep, 12, stdin);
                        break;
                    case 7: 
                        printf("\n������� email: ");
                        fgets (clean, 2 ,stdin);
                        fgets( p[i].infconn.addressemailp, THIRTY_SIZE, stdin);
                        break;
                    case 8: 
                        printf("\n������� ������ �� ���.����: ");
                        fgets (clean, 2 ,stdin);
                        fgets( p[i].infconn.linksnp, 200, stdin);
                        break;
                    case 9:
                        workonf=0;
                        break;
                    default: 
                        printf("\n������� �� ������� \n");
                        break;
                }
            }
            return;
        }
    }
    printf("������� �� ������\n");
}

void deletepers(struct person p[], int *count){
    char clean[2];
    char nameonf[TWENTY_SIZE];
    char surnameof[TWENTY_SIZE];
    bool flagfind=0;
    
    fgets (clean, 2 ,stdin);
    printf("������� ������� � ��� ����, ��� ������� ���������� �������.\n");
    printf("�������: ");
    fgets(surnameof, TWENTY_SIZE, stdin);
    
    printf("���: ");
    fgets(nameonf, TWENTY_SIZE, stdin);
    
    if (!checkonvoidstr(nameonf) || !checkonvoidstr(surnameof))
    {
        printf("���� ������� � ��� �� ����� ���� �������! ������� � ����\n");
        return;
    }
    
    for(int i=0; i<*count; i++)
    {
        if(!strcmp(surnameof, p[i].surname) && !strcmp(nameonf, p[i].name))
        {
            flagfind=1;
        }
        if (flagfind)
        {
            if (*count!=1 && i!=49)
            {
                strcpy(p[i].surname, p[i+1].surname);
                strcpy(p[i].name, p[i+1].name);
                strcpy(p[i].lastname, p[i+1].lastname);
                strcpy(p[i].infwork.placewp, p[i+1].infwork.placewp);
                strcpy(p[i].infwork.postp, p[i+1].infwork.postp);
                strcpy(p[i].infconn.mobphonep, p[i+1].infconn.mobphonep);
                strcpy(p[i].infconn.addressemailp, p[i+1].infconn.addressemailp);
                strcpy(p[i].infconn.linksnp, p[i+1].infconn.linksnp);
                continue;
            }
            else
            {
                strcpy(p[i].surname, "");
                strcpy(p[i].name, "");
                strcpy(p[i].lastname, "");
                strcpy(p[i].infwork.placewp, "");
                strcpy(p[i].infwork.postp, "");
                strcpy(p[i].infconn.mobphonep, "");
                strcpy(p[i].infconn.addressemailp, "");
                strcpy(p[i].infconn.linksnp, "");
            }
        }
    }
    if (flagfind)
    {
        *count = *count-1;
    }
}

int main() {
    char *locale = setlocale(LC_ALL, ""); //��� �����
    SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);

    struct person phdir[FIFTY_SIZE];
    int countpers=0;
    
    bool work=1; int cmd;
    while(work){
        printf("\n������� ������ ���������-1, �������� ������������-2, �������������-3, �������-4, ��������� ������-5: ");
        scanf("%d", &cmd);
        switch(cmd)
        {
            case 1: 
                printpers(phdir, &countpers);
                break;
            case 2: 
                addpers(phdir, &countpers);
                break;
            case 3: 
                editpers(phdir, &countpers);
                break;
            case 4: 
                deletepers(phdir, &countpers);
                break;
            case 5:
                work=0;
                break;
            default: 
                printf("\n������� �� ������� \n");
                break;
        }
    }
    
    return 0;
}