#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5
//Global variables
char name[MAX][31];
int i,q1[MAX],q2[MAX], q3[MAX];
int age[MAX];
int last;
float ave;
//UDFs
void init();
int isfull();
int isempty();
int locate(char n[]);
void del(char n[]);
int add(char n[],int ag);
void display();
int isAdult(int ag);
void upload();
void download();
int menu();
int dupli();
void quizadd();
void update_record();
void display_record();
float calculate_ave();

int main(){
int a;
char nm[31];
init();//initialize the array
download();//populate the parallel arrays with the data from the file
while(1){
    switch(menu()){
    case 1 : system("cls");printf("Input Name: ");scanf(" %[^\n]",nm);
             printf("Input Age: ");scanf("%d",&a);if (add(nm, a)) {
                quizadd();
            };break;
    case 2 : update_record();break;
    case 3 : system("cls");printf("Input Name: ");scanf(" %[^\n]",nm);del(nm);break;
    case 4 : display();break;
    case 5 : display_record();break;
    case 6 : upload();exit(0);//save and exit
    default: printf("1 to 6 only.\n");system("pause");
    }
}

return 0;
}
//Define UDFs
void init(){
 last = -1;
}
int isfull(){
/*if (last==MAX-1)
    return 1;
else
    return 0;*/
return (last==MAX-1);
}
int isempty(){
return (last==-1);
}
int locate(char n[]){
int i;
for (i=0;i<=last;i++){
    if (strcmp(n,name[i])==0)
        return i;
  }
return -1;
}
void quizadd(){

    printf("Input Quiz1: ");
    scanf("%d", &q1[last]);
    printf("Input Quiz2: ");
    scanf("%d", &q2[last]);
    printf("Input Quiz3: ");
    scanf("%d", &q3[last]);
}
void del(char n[]) {
    int p, i;
    if (isempty()) {
        printf("Array is empty.\n");
        system("pause");
    }
    else {
        p = locate(n);
        if (p<0) {
            printf("Not found.\n");
            system("pause");
        }
        else {
            for (i=p; i<last; i++) {
                strcpy(name[i], name[i+1]);
                age[i] = age[i+1];
                q1[i] = q1[i+1];
                q2[i] = q2[i+1];
                q3[i] = q3[i+1];
            }
            last--;
            printf("Record of %s is successfully deleted.\n",n);
            system("pause");
        }
    }
}
int add(char n[],int ag){

if (isfull()){
    printf("Array is full.\n");
    system("pause");
    return 0;
}
 else if (dupli(n)) {//  To check if the name already exists
        printf("Error: The name '%s' already exists.\n", n);
        system("pause");
        return 0;
 }
else {
    last++;
    strcpy(name[last],n);
    age[last] = ag;
    return 1;
    //printf("Record of %s is successfully added to the Parallel arrays.\n",n);
    //system("pause");
 }
}
int menu(){
int op;
system("cls");
printf("Menu\n");
printf("1. Add a Record\n");
printf("2. Update a Record\n");
printf("3. Delete a Record\n");
printf("4. Display All\n");
printf("5. Display a Record\n");
printf("6. Save and Exit\n");
printf("\nSelect(1-6): ");
scanf("%d",&op);
return op;
}
void display() {
    int i;
    float student_avg;
    system("cls");
    printf(" NAME\t\t\tAGE\tREMARKS\tQUIZ1\tQUIZ2\tQUIZ3\tAVERAGE\n");
    for (i = 0; i <= last; i++) {
        student_avg = calculate_ave(q1[i], q2[i], q3[i]);
        printf("%d.) %s\t\t%d\t%s\t%d\t%d\t%d\t%.2f\t\n",
               i+1, name[i], age[i], isAdult(age[i]) ? "ADULT" : "MINOR", q1[i], q2[i], q3[i], student_avg);

    }
    system("pause");
}
int isAdult(int a){
  return (a>=18);
}
void upload(){
FILE *fp;
int i;
fp = fopen("bsit1b25.txt","w+");
if (fp==NULL){
    printf("File error//Error 404\n");
    system("pause");
}
else {
    for (i=0;i<=last;i++)
        fprintf(fp,"%s\n%d\n%d\n%d\n%d\n",name[i],age[i], q1[i], q2[i], q3[i]);
}
fclose(fp);
}

void download() {
    FILE *fp;
    char nm[31];
    int a, quiz1, quiz2, quiz3;
    fp = fopen("bsit1b25.txt","r+");
    if (fp==NULL) {
        printf("File error//Error 404\n");
        system("pause");
    }
    else {
        while (!feof(fp)) {
            fscanf(fp," %[^\n]\n%d\n%d\n%d\n%d\n", nm, &a, &quiz1, &quiz2, &quiz3);
            if (add(nm,a)) {
                q1[last] = quiz1;
                q2[last] = quiz2;
                q3[last] = quiz3;
            }
        }
        fclose(fp);
    }
}
int dupli(char n[]) {// to check if there is duplicate name
    for (int i = 0; i <= last; i++) {
        if (strcmp(name[i], n) == 0) {
            return 1;
        }
    }
    return 0;
}
void update_record() {
    char searchName[31];
    int i, found = 0, new_q1, new_q2, new_q3, choice;
    float avg;

    system("cls");
    printf("Input name to update: ");
    scanf(" %[^\n]", searchName);

    for (i = 0; i <= last; i++) {
        if (strcmp(name[i], searchName) == 0) {
            found = 1;
            avg = (float)(q1[i] + q2[i] + q3[i]) / 3.0;
            printf("\nName: %s\n", name[i]);
            printf("Q1: %d\n", q1[i]);
            printf("Q2: %d\n", q2[i]);
            printf("Q3: %d\n", q3[i]);
            printf("Average: %.2f\n", avg);
            while (choice != 4) {
                printf("\nEnter Quiz# to Update: \n");
                printf("1. Quiz 1\n");
                printf("2. Quiz 2\n");
                printf("3. Quiz 3\n");
                printf("4. Return to Main Menu\n");
                printf("Select (1-4): ");
                scanf("%d", &choice);

                switch(choice) {
                    case 1:
                        printf("\nEnter new Quiz 1 score: ");
                        scanf("%d", &new_q1);
                        q1[i] = new_q1;
                        printf("Quiz 1 score updated successfully.\n");
                        return;
                        break;
                    case 2:
                        printf("\nEnter new Quiz 2 score: ");
                        scanf("%d", &new_q2);
                        q2[i] = new_q2;
                        printf("Quiz 2 score updated successfully.\n");
                        return;
                        break;
                    case 3:
                        printf("\nEnter new Quiz 3 score: ");
                        scanf("%d", &new_q3);
                        q3[i] = new_q3;
                        printf("Quiz 3 score updated successfully.\n");
                        return;
                        break;
                    case 4:
                        return;
                        break;
                    default:
                        printf("\nInvalid choice. Please select between 1 and 4.\n");
                }
            }
            break;
        }
    }
    if (!found) {
        printf("\nStudent not found.\n");
    }
    system("pause");
}
void display_record() {
    char searchName[31];
    int i, found = 0;
    float student_avg;
    system("cls");
    printf("Enter student name: ");
    scanf(" %[^\n]", searchName);
    for (i = 0; i <= last; i++) {
        if (strcmp(name[i], searchName) == 0) {
            found = 1;
            student_avg = calculate_ave(q1[i], q2[i], q3[i]);
            printf("\n NAME\t\t\tAGE\tREMARKS\tQUIZ 1\tQUIZ 2\tQUIZ 3\tAVERAGE\n");
            printf("%d.) %s\t\t%d\t%s\t%d\t%d\t%d\t%.2f\n",
                   i + 1, name[i], age[i],
                   isAdult(age[i]) ? "ADULT" : "MINOR",
                   q1[i], q2[i], q3[i], student_avg);
            break;
        }
    }
    if (!found) {
        printf("\nStudent not found\n");
    }
    system("pause");
}
float calculate_ave(int x, int y, int z) {
    return (float)(x + y + z) / 3.0;1;
}

