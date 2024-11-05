#include "calc.h"

int main(void) {
    int count; double result;
    double numbers[SIZE]; 

    bool work=1; int cmd; int print;
    while(work){
        printf("\nFunc sum-1, Func sub-2, Func mult-3, Func div-4, Complete the work-5: ");
        scanf("%d", &cmd);
        switch(cmd)
        {
            case 1: 
                enterargs(numbers, &count);
                result = sum(count, numbers[0], numbers[1], numbers[2], numbers[3], numbers[4],
                                        numbers[5], numbers[6], numbers[7], numbers[8], numbers[9]);
                printf("Sum result: %.2f\n", result);              
                break;
            case 2:
                enterargs(numbers, &count);
                result = sub(count, numbers[0], numbers[1], numbers[2], numbers[3], numbers[4],
                                        numbers[5], numbers[6], numbers[7], numbers[8], numbers[9]);
                printf("Sub result: %.2f\n", result);    
                break;
            case 3:
                enterargs(numbers, &count);
                result = mult(count, numbers[0], numbers[1], numbers[2], numbers[3], numbers[4],
                                        numbers[5], numbers[6], numbers[7], numbers[8], numbers[9]);
                printf("Mult result: %.2f\n", result);   
                break;
            case 4:
                enterargs(numbers, &count);
                result = div(count, numbers[0], numbers[1], numbers[2], numbers[3], numbers[4],
                                        numbers[5], numbers[6], numbers[7], numbers[8], numbers[9]);
                printf("Div result: %.2f\n", result);
                break;
            case 5:
                work=0;
                break;
            default: 
                printf("\nCommand not found \n");
                break;
        }
    }
    
    return 0;
}