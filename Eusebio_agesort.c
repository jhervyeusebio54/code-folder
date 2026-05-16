// Eusebio, John Jhervy G.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15
//Global variables
char name[MAX][31];
int age[MAX];
int last;
//UDFs
void init();
int isfull();
int isempty();
int locate(char n[]);
void del(char n[]);
void add(char n[],int ag);
void display();
int isAdult(int ag);
void upload();
void download();
int menu();

int main(){
int a;
char nm[31];
init();//initialize the array
download();//populate the parallel arrays with the data from the file
while(1){
    switch(menu()){
    case 1 : system("cls");printf("Input Name: ");scanf(" %[^\n]",nm);
             printf("Input Age: ");scanf("%d",&a);add(nm,a);break;
    case 2 : system("cls");printf("Input Name: ");scanf(" %[^\n]",nm);del(nm);break;
    case 3 : display();break;
    case 4 : upload();exit(0);//save and exit
    default: printf("1 to 4 only.\n");system("pause");
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
void del(char n[]){
int p, i;
if (isempty()){
    printf("Array is empty.\n");
    system("pause");
 }
else {
    p = locate(n);
    if (p<0){
        printf("Not found.\n");
        system("pause");
      }
    else {
        for (i=p;i<last;i++){
            strcpy(name[i],name[i+1]);
            age[i] = age[i+1];
        }
        last--;
        printf("Record of %s is successfully deleted.\n",n);
        system("pause");
    }
}
}

void add(char n[], int ag) {
    if (isfull()) {
        printf("Array is full.\n");
        system("pause");
    } else {
        last++;
        strcpy(name[last], n);
        age[last] = ag;
        int i, j;
        char tempName[31];
        int tempAge;

        for (i = 0; i <= last; i++) {
            for (j = 0; j < last - i; j++) {
                if (age[j] > age[j + 1]) {
                    tempAge = age[j];
                    age[j] = age[j + 1];
                    age[j + 1] = tempAge;

                    strcpy(tempName, name[j]);
                    strcpy(name[j], name[j + 1]);
                    strcpy(name[j + 1], tempName);
                }
            }
        }

        //printf("Record of %s is successfully added to the Parallel arrays.\n", n);
        //system("pause");
    }
}
int menu(){
int op;
system("cls");
printf("Menu\n");
printf("1. Add a Record\n");
printf("2. Delete a Record\n");
printf("3. Display All\n");
printf("4. Save and Exit\n");
printf("\nSelect(1-4): ");
scanf("%d",&op);
return op;
}
void display(){
int i;
system("cls");
printf(" NAME\t\t\tAGE\tREMARKS\n");
for (i=0;i<=last;i++){
    printf("%d.) %s\t\t%d\t",i+1,name[i],age[i]);
    if (isAdult(age[i]))
        printf("ADULT\n");
    else
        printf("MINOR\n");
    }
system("pause");
}
int isAdult(int a){
  return (a>=18);
}
void upload() {
    FILE *fp;
    int i;
    fp = fopen("bsit1b25.txt", "w+");
    if (fp == NULL) {
        printf("File error//Error 404\n");
        system("pause");
    } else {
        for (i = 0; i <= last; i++)
            fprintf(fp, "%s\n%d\n", name[i], age[i]);
    }
    fclose(fp);
}

void download() {
    FILE *fp;
    char nm[31];
    int a;
    fp = fopen("bsit1b25.txt", "r");
    if (fp == NULL) {
        printf("File error//Error 404\n");
        system("pause");
    } else {
        init();
        while (fscanf(fp, " %[^\n]\n%d\n", nm, &a) == 2) {
            add(nm, a);
        }
        fclose(fp);
    }
}
