#include <stdio.h>

int main() {
    float a, b;
    char op;

    printf("Enter expression (example: 5 + 2): ");
    scanf("%f %c %f", &a, &op, &b);

    switch(op) {
        case '+':
            printf("Result: %.2f\n", a + b);
            break;
        case '-':
            printf("Result: %.2f\n", a - b);
            break;
        case '*':
            printf("Result: %.2f\n", a * b);
            break;
        case '/':
            if(b != 0)
                printf("Result: %.2f\n", a / b);
            else
                printf("Cannot divide by zero\n");
            break;
        default:
            printf("Invalid operator\n");
    }

    return 0;
}