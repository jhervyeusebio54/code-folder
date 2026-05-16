//EUSEBIO, JOHN JHERVY G.
//MACHINE PROBLEM
//ARRAY OF STRUCTURES IMPLEMENTATION
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef struct record {
   char name[31];
   int age,q1, q2, q3;
} REC;

//Global variables
//Array of structures
REC st[MAX]; //Array of structure
int last;

//UDFs
void init();
int isfull();
int isempty();
int locate(char n[]);
void del(char n[]);
void add(REC x);
void updateRecord(char n[]);
void display();
int isAdult(int ag);
void upload();
void download();
float computeAverage(int g1, int g2, int g3);
int menu();
int locatePosition(int ag);

int main() {
    REC data;
    init(); //initialize the array
    download(); //populate the array with the data from the file

    while(1) {
        switch(menu()) {
            case 1: system("cls");
                    printf("Input Name: ");scanf(" %[^\n]", data.name);
                    printf("Input Age: ");scanf("%d", &data.age);
                    printf("Input Quiz 1: ");scanf("%d", &data.q1);
                    printf("Input Quiz 2: ");scanf("%d", &data.q2);
                    printf("Input Quiz 3: ");scanf("%d", &data.q3);
                    add(data);
                    break;
            case 2: system("cls");
                    printf("Input name to update: ");scanf(" %[^\n]", data.name);
                    updateRecord(data.name);
                    break;
            case 3: system("cls");
                    printf("Input Name: ");scanf(" %[^\n]", data.name);
                    del(data.name);
                    break;
            case 4: display();
                    break;
            case 5: upload();
                    exit(0); //save and exit
            default: printf("1 to 5 only.\n"); system("pause");
        }
    }

    return 0;
}

//Define UDFs
void init() {
    last = -1;
}

int isfull() {
    /*if (last==MAX-1)
        return 1;
    else
        return 0;*/
    return (last==MAX-1);
}

int isempty() {
    return (last==-1);
}

int locate(char n[]) {
    int i;
    for (i=0; i<=last; i++) {
        if (strcmp(n, st[i].name)==0)
            return i;
    }
    return -1;
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
                /*strcpy(name[i], name[i+1]);
                age[i] = age[i+1];*/
                st[i] = st[i+1];
            }
            last--;
            printf("Record of %s is successfully deleted.\n", n);
            system("pause");
        }
    }
}

void add(REC x) {
    int p, i;
    if (isfull()) {
        printf("Array is full.\n");
       system("pause");
    }
    else {
        p = locatePosition(x.age);
        for (i = last; i >= p; i--) {
            /*strcpy(name[i+1], name[i]);
            age[i+1] = age[i];*/
            st[i+1] = st[i];
        }
        /*strcpy(name[p], n);
        age[p] = ag;*/
        st[p] = x;
        last++;
        //system("pause");
    }
}

void updateRecord(char n[]) {
    int loc = locate(n);
    if (loc >= 0) {
        int quizUR;

        while (1) {
            system("cls");
            float average = computeAverage(st[loc].q1, st[loc].q2, st[loc].q3);
            printf("    NAME\t QUIZ 1\t QUIZ 2\t QUIZ 3\t AVERAGE\t\n");
            printf("%d. %s\t %d\t %d\t %d\t %6.2f\t\n", loc+1, st[loc].name, st[loc].q1, st[loc].q2, st[loc].q3, average);
            printf("1. Quiz 1\n2. Quiz 2\n3. Quiz 3\n4. Return to Main Menu\n");
            printf("Enter quiz # to update: ");scanf("%d", &quizUR);
            switch (quizUR) {
                case 1: printf("Enter new score for Quiz 1: ");
                        scanf("%d", &st[loc].q1);
                        break;
                case 2: printf("Enter new score for Quiz 2: ");
                        scanf("%d", &st[loc].q2);
                        break;
                case 3: printf("Enter new score for Quiz 3: ");
                        scanf("%d", &st[loc].q3);
                        break;
                case 4: return;
                default: printf("Enter 1 to 4 only.\n");
                system("pause");
            }
        }
    }
    else
        printf("No record of given name is found.\n");
    system("pause");
}

int menu() {
    int op;
    system("cls");
    printf("\nMenu\n");
    printf("1. Add a Record\n");
    printf("2. Update a Record\n");
    printf("3. Delete a Record\n");
    printf("4. Display All\n");
    printf("5. Save and Exit\n");
    printf("\nSelect(1-5): ");scanf("%d",&op);
    return op;
}

void display() {
    int i;
    system("cls");
    printf(" NAME\t\t\tAGE\tQ1\tQ2\tQ3\tAVG\tREMARKS\n");
    for (i=0; i<=last; i++) {
        float avg = computeAverage(st[i].q1, st[i].q2, st[i].q3);
        printf("%d.) %s\t\t%d\t%d\t%d\t%d\t%.2f\t%s\n",
               i+1, st[i].name, st[i].age, st[i].q1, st[i].q2, st[i].q3, avg,
               isAdult(st[i].age) ? "ADULT" : "MINOR");
    }
    system("pause");
}

int isAdult(int a) {
    return (a>=18);
}

void upload() {
    FILE *fp;
    int i;
    fp = fopen("bsit1b25.txt", "w+");
    if (fp==NULL) {
        printf("File error//Error 404\n");
        system("pause");
    }
    else {
        for (i=0; i<=last; i++)
            fprintf(fp, "%s\n%d\n%d\n%d\n%d\n", st[i].name, st[i].age, st[i].q1, st[i].q2, st[i].q3);
    }
    fclose(fp);
}

void download() {
    FILE *fp;
    REC r;
    fp = fopen("bsit1b25.txt", "r+");
    if (fp==NULL) {
        printf("File error//Error 404\n");
        system("pause");
    }
    else {
        while (!feof(fp)) {
            fscanf(fp, " %[^\n]\n%d\n%d\n%d\n%d\n", r.name, &r.age, &r.q1, &r.q2, &r.q3);
            add(r);
        }
        fclose(fp);
    }
}

int locatePosition(int ag) {
    int i;
    for (i = 0; i <= last; i++) {
        if (ag > st[i].age)
            return i;
    }
    return i; // i = last + 1
}

float computeAverage(int g1, int g2, int g3) {
    return (g1 + g2 + g3) / 3.0;
    }
