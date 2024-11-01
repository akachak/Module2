#include "person.h"

int main() {
    
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