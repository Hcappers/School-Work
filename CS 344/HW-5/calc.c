#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

float calculations(float, float, char);

int main(int argc, char *argv[]){
    if(argc != 4){
        printf("Error: Please enter 3 arguments\n");
        return 0;
    }
    float x = atof(argv[1]);
    float y = atof(argv[3]);
    char operator = argv[2][0];
    float result = calculations(x, y, operator);
    printf("%.4f %c %.4f = %.4f\n", x, operator, y, result);
    return 0;
}
float calculations(float x, float y, char operator){
    float result = 0;
    switch(operator){
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            if(y == 0){
                printf("Undefined: You cannot have 0 as a divisor\n");
                exit(1);
            }
            result = x / y;
            break;
        default:
            printf("Error: Invalid operator\n");
            break;
    }
    return result;
}