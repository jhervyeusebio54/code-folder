/*
Eusebio, John Jhervy G.
BSIT-1b

A simple Arithmetic Practice Program with the following features:
1. Log/Sign in feature - Log in if the player has an existing account.
Sign in if first time to play. (username, password)
2. Leader Board - upon log in, the overall leader board  will be shown. Optionally,
the user may also view the leaderboard per operation.
3. Use parallel arrays to store player records
that will be stored into a file upon exit.
Turn in the following:
The source code of the program
Video recording of the Demo/Presentation of the program explaining the the features and code of the program.
 (Maximum video time 15 minutes)
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 5


char name[MAX][50];
int menu();
int addition();
int subtraction();
int multiplication();
int division();
void login();
void display();
void save();
void account();


int main(){
login();
switch(menu()){
case 1: system("cls");


    break;
case 2: system("cls");


    break;
case 3: system("cls");


    break;
case 4: system("cls");


    break;
case 5: system("cls");


    break;






}




return 0;
}
int menu(){
 int op;
    system("cls");
    printf("\nMenu\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Save and Exit\n");
    printf("\nSelect(1-5): ");scanf("%d",&op);
    return op;
}
int addition(){


}
int subtraction(){

}
int multiplication(){

}
int division(){

}
void login(){
char acc[50];
char pass[10];
printf("Enter Username:");
scanf("%s",acc);
printf("Enter Password:");
scanf("%s", pass);

}
void display(){

}
void save(){

}
void account(){

}
