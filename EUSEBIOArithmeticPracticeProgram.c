
//EUSEBIO, JOHN JHERVY G. BSIT 1B

#include <stdio.h>
#include <stdlib.h>

void addition();
void subtraction();
void division();
void multiplication();
int menu();

int main() {
    while (1) {
        switch (menu()) {
            case 1: addition(); break;
            case 2: subtraction(); break;
            case 3: division(); break;
            case 4: multiplication(); break;
            case 5: exit(0);
            default: printf("Enter 1 to 5 only.\n\n");
        }
        system("pause");
    }
    return 0;
}

int menu() {
    system("cls");
    int xp;
    printf("Menu\n");
    printf("\n1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Division\n");
    printf("4. Multiplication\n");
    printf("5. Exit\n");
    printf("\nSelect(1-5): ");
    scanf("%d", &xp);
    return xp;
}

void addition() {
    float num, sum = 0;
    int co= 0;
    system("cls");
    printf("Enter numbers to add (enter 0 to stop):\n");
    while (1) {
        printf("Enter a number: ");
        scanf("%f", &num);
        if (num == 0) break;
        sum += num;
        co++;
    }
    if (co > 0) {
        printf("The sum of the %d numbers is: %.2f\n\n", co, sum);
    } else {
        printf("No numbers were entered.\n\n");
    }

}

void subtraction() {
    float num, result;
    int co = 0;
    system("cls");
    printf("Enter numbers to subtract (enter 0 to stop):\n");
    printf("Enter the first number: ");
    scanf("%f", &result);
    while (1) {
        printf("Enter a number: ");
        scanf("%f", &num);
        if (num == 0) break;
        result -= num;
        co++;
    }
    if (co > 0) {
        printf("The result after subtracting %d numbers is: %.2f\n\n", co, result);
    } else {
        printf("No additional numbers were entered.\n\n");
    }
}

void division() {
    float num, result;
    int co = 0;
    system("cls");
    printf("Enter numbers to divide (enter 0 to stop):\n");
    printf("Enter the first number: ");
    scanf("%f", &result);
    while (1) {
        printf("Enter a number: ");
        scanf("%f", &num);
        if (num == 0) break;
        if (num != 0) {
            result /= num;
            co++;
        } else {
            printf("Error! You Can't Divide by Zero. Skipping this number.\n");
        }
    }
    if (co> 0) {
        printf("The result after dividing by %d numbers is: %.2f\n\n", co, result);
    } else {
        printf("No additional numbers were entered.\n\n");
    }

}

void multiplication() {
    float num, result = 1;
    int co = 0;
    system("cls");
    printf("Enter numbers to multiply (enter 0 to stop):\n");
    while (1) {
        printf("Enter a number: ");
        scanf("%f", &num);
        if (num == 0) break;
        result *= num;
        co++;
    }
    if (co > 0) {
        printf("The product of the %d numbers is: %.2f\n\n", co, result);
    } else {
        printf("No numbers were entered.\n\n");
    }

}
