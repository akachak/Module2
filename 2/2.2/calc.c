#include "calc.h"

double sum(const int count, ...) {
    va_list arg;
    va_start(arg, count);

    double result = 0.0;

    for(int i = 0; i < count; ++i) {
        result += va_arg(arg, double);
    }

    va_end(arg);
    return result;
}

double sub(const int count, ...) {
    va_list arg;
    va_start(arg, count);

    double result = va_arg(arg, double);

    for (int i = 1; i < count; ++i) {
        result -= va_arg(arg, double);
    }

    va_end(arg);
    return result;
}

double mult(const int count, ...) {
    va_list arg;
    va_start(arg, count);

    double result = va_arg(arg, double);
    if(result == 0.0){return 0.0;}
    for (int i = 1; i < count; i++) {
        result *= va_arg(arg, double);
    }

    va_end(arg);
    return result;
}

double div(const int count, ...) {
    va_list arg;
    va_start(arg, count);

    double result = va_arg(arg, double);
    double tmpdiv;
    if(result == 0.0){return 0.0;}
    for (int i = 1; i < count; i++) {
        tmpdiv = va_arg(arg, double);
        if(tmpdiv != 0.0)
        {
            result /= tmpdiv;
        }
    }

    va_end(arg);
    return result;
}

void enterargs(double num[SIZE], int *count){
    int cnt;
    printf("Enter count numbers: ");
    scanf("%d", &cnt);
    if(cnt > 10 || cnt < 0)
    {
        printf("Error\n");
        return;
    }
    printf("Enter numbers:\n");
    for (int i = 0; i < cnt; i++) 
    {
        printf("Number %d: ", i + 1);
        scanf("%lf", &num[i]);
    }
    *count = cnt;
}
