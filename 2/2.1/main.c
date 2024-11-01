#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include <locale.h> //Для Винды
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
    printf("\nЗаполненность журнала: %d из 50\n", *count);
    for(int i=0; i<*count; i++)
    {
        printf("\nКонтакт №%d из %d\n", i+1, *count);
        printf("Полное имя:\n Ф: %s И: %s О: %s", p[i].surname, p[i].name, p[i].lastname);
        printf("Место работы: %s", p[i].infwork.placewp);
        printf("Должность: %s", p[i].infwork.postp);
        printf("Мобильный телефон: %s", p[i].infconn.mobphonep);
        printf("Email: %s", p[i].infconn.addressemailp);
        printf("Ссылка на соц.сеть: %s", p[i].infconn.linksnp);
    }
}

void addpers(struct person p[], int *count){
    char clean[2];
    char nameonf[TWENTY_SIZE];
    char surnameof[TWENTY_SIZE];
    
    fgets (clean, 2 ,stdin);
    
    printf("\nВведите фамилию: ");
    fgets(surnameof, TWENTY_SIZE, stdin);
    
    printf("Введите имя: ");
    fgets(nameonf, TWENTY_SIZE, stdin);
    
    if (!checkonvoidstr(nameonf) || !checkonvoidstr(surnameof))
    {
        printf("Поля фамилия и имя не могут быть пустыми! Возврат в меню\n");
        return;
    }
    strcpy(p[*count].name, nameonf);
    strcpy(p[*count].surname, surnameof);
    
    printf("Введите отчество или пропустите(enter): ");
    fgets(p[*count].lastname, TWENTY_SIZE, stdin);
    
    printf("Введите место работы или пропустите(enter): ");
    fgets(p[*count].infwork.placewp, FIFTY_SIZE, stdin);
    
    printf("Введите занимаемую должность или пропустите(enter): ");
    fgets(p[*count].infwork.postp, THIRTY_SIZE, stdin);
    
    printf("Введите номер мобильного телефона в формате 89********* или пропустите(enter): ");
    fgets(p[*count].infconn.mobphonep, 12, stdin);
    
    printf("Введите email или пропустите(enter): ");
    fgets( p[*count].infconn.addressemailp, THIRTY_SIZE, stdin);
    
    printf("Введите ссылку на соц.сеть или пропустите(enter): ");
    fgets( p[*count].infconn.linksnp, 200, stdin);
    
    *count = *count +1;
}

void editpers(struct person p[], int *count){
    char clean[2];
    char nameonf[TWENTY_SIZE];
    char surnameof[TWENTY_SIZE];
    
    fgets (clean, 2 ,stdin);
    printf("Введите фамилию и имя того, чей контакт необходимо отредактировать.\n");
    printf("Фамилия: ");
    fgets(surnameof, TWENTY_SIZE, stdin);
    
    printf("Имя: ");
    fgets(nameonf, TWENTY_SIZE, stdin);
    
    if (!checkonvoidstr(nameonf) || !checkonvoidstr(surnameof))
    {
        printf("Поля фамилия и имя не могут быть пустыми! Возврат в меню\n");
        return;
    }
    
    for(int i=0; i<*count; i++)
    {
        if(!strcmp(surnameof, p[i].surname) && !strcmp(nameonf, p[i].name))
        {
            bool workonf=1; int cmdonf;
            while(workonf){
                printf("\nРедактировать фамилию-1,\n Редактировать имя-2,\n Редактировать отчество-3,\n Редактировать место работы-4,\n Редактировать должность-5,\n Редактировать номер мобильного телефона-6,\n Редактировать email-7,\n Редактировать ссылку на соц.сеть-8,\n Выйти-9\n: ");
                scanf("%d", &cmdonf);
                switch(cmdonf)
                {
                    case 1: 
                        printf("\nВведите фамилию: ");
                        fgets (clean, 2 ,stdin);
                        fgets(surnameof, TWENTY_SIZE, stdin);
                        if (!checkonvoidstr(surnameof))
                        {
                            printf("Поля фамилия и имя не могут быть пустыми! Возврат в меню\n");
                            break;
                        }
                        strcpy(p[i].surname, surnameof);
                        break;
                    case 2: 
                        printf("\nВведите имя: ");
                        fgets (clean, 2 ,stdin);
                        fgets(nameonf, TWENTY_SIZE, stdin);
                        if (!checkonvoidstr(nameonf))
                        {
                            printf("Поля фамилия и имя не могут быть пустыми! Возврат в меню\n");
                            break;
                        }
                        strcpy(p[i].name, nameonf);
                        break;
                    case 3: 
                        printf("\nВведите отчество: ");
                        fgets (clean, 2 ,stdin);
                        fgets(p[i].lastname, TWENTY_SIZE, stdin);
                        break;
                    case 4: 
                        printf("\nВведите место работы: ");
                        fgets (clean, 2 ,stdin);
                        fgets(p[i].infwork.placewp, FIFTY_SIZE, stdin);
                        break;
                    case 5: 
                        printf("\nВведите должность: ");
                        fgets (clean, 2 ,stdin);
                        fgets(p[i].infwork.postp, THIRTY_SIZE, stdin);
                        break;
                    case 6: 
                        printf("\nВведите номер телефона: ");
                        fgets (clean, 2 ,stdin);
                        fgets(p[i].infconn.mobphonep, 12, stdin);
                        break;
                    case 7: 
                        printf("\nВведите email: ");
                        fgets (clean, 2 ,stdin);
                        fgets( p[i].infconn.addressemailp, THIRTY_SIZE, stdin);
                        break;
                    case 8: 
                        printf("\nВведите ссылку на соц.сеть: ");
                        fgets (clean, 2 ,stdin);
                        fgets( p[i].infconn.linksnp, 200, stdin);
                        break;
                    case 9:
                        workonf=0;
                        break;
                    default: 
                        printf("\nКоманда не найдена \n");
                        break;
                }
            }
            return;
        }
    }
    printf("Контакт не найден\n");
}

void deletepers(struct person p[], int *count){
    char clean[2];
    char nameonf[TWENTY_SIZE];
    char surnameof[TWENTY_SIZE];
    bool flagfind=0;
    
    fgets (clean, 2 ,stdin);
    printf("Введите фамилию и имя того, чей контакт необходимо удалить.\n");
    printf("Фамилия: ");
    fgets(surnameof, TWENTY_SIZE, stdin);
    
    printf("Имя: ");
    fgets(nameonf, TWENTY_SIZE, stdin);
    
    if (!checkonvoidstr(nameonf) || !checkonvoidstr(surnameof))
    {
        printf("Поля фамилия и имя не могут быть пустыми! Возврат в меню\n");
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
    char *locale = setlocale(LC_ALL, ""); //Для Винды
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);

    struct person phdir[FIFTY_SIZE];
    int countpers=0;
    
    bool work=1; int cmd;
    while(work){
        printf("\nВывести список контактов-1, Добавить пользователя-2, Редактировать-3, Удалить-4, Завершить работу-5: ");
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
                printf("\nКоманда не найдена \n");
                break;
        }
    }
    
    return 0;
}