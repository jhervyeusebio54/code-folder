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
#include<string.h>
#include<time.h>
#define MAX 5

char name[MAX][50];
char key[MAX][10];
int scores[MAX] = {0};
int playeri = -1;

int menulogsign();
void login();
void signin();
int menu();
int addition();
int subtraction();
int multiplication();
int division();
void display();
void save();
void load();


int main() {
load();
srand(time(NULL));
system("cls");
while(1){
switch (menulogsign()) {
    case 1: system("cls");login();system("pause");system("cls"); break;
    case 2: system("cls");signin();system("pause");system("cls"); break;
    case 3: exit(0);
    default: printf("1 to 3 only.\n"); system("pause");system("cls");
}
}

return 0;

}
int menulogsign() {
int o;
printf("\nMenu\n");
printf("1. Login\n");
printf("2. Sign in\n");
printf("3. Exit\n");
printf("\nSelect(1-3): ");
scanf("%d", &o);
return o;
}
void login() {
char uname[50], pword[10];
printf("Login\n");
printf("Enter your Username: ");
scanf(" %s", uname);
printf("Enter your Password: ");
scanf("%s", pword);

for (int i = 0; i < MAX; i++) {
    if (strcmp(name[i], uname) == 0 && strcmp(key[i], pword) == 0) {
        printf("Login successful!\n");
        playeri = i;
        system("pause");system("cls");
        int d;
    while ((d = menu()) != 6) {
        switch (d) {
            case 1: system("cls");addition();system("pause");system("cls"); break;
            case 2: system("cls");subtraction(); system("pause");system("cls");break;
            case 3: system("cls");multiplication();system("pause");system("cls"); break;
            case 4: system("cls"); division();system("pause"); system("cls");break;
            case 5: system("cls");display(); system("pause");system("cls");break;
            default: printf("1 to 7 only.\n"); system("pause");
        }
    }
save();
        return;
    }
}
printf("Invalid credentials.\n");

 }

void signin() {
char uname[50], pword[10];
printf("Sign in\n");
printf("Enter a Username: ");
scanf(" %s", uname);
printf("Enter a Password: ");
scanf("%s", pword);

for (int i = 0; i < MAX; i++) {
    if (name[i][0] == '\0') {
        strcpy(name[i], uname);
        strcpy(key[i], pword);
        scores[i] = 0;
        playeri = i;
        printf("Account created successfully!\n");
        return;
    }
}
printf("Max users reached!\n");


}

int menu() {
int op;
printf("\nPLAY\n");
printf("1. Addition\n");
printf("2. Subtraction\n");
printf("3. Multiplication\n");
printf("4. Division\n");
printf("5. Leaderboards\n");
printf("6. Save & Exit\n");
printf("\nSelect(1-6): ");
scanf("%d", &op);
return op;
}

int addition() {
int num1 = rand() % 100 + 1;
int num2 = rand() % 100 + 1;
int answer;
printf("%d + %d = ? \n", num1, num2);
scanf("%d", &answer);

if (answer == num1 + num2) {
    printf("Correct!\n");
    scores[playeri]++;
} else {
    printf("Wrong! The answer is %d\n", num1 + num2);
}
return 0;

}

int subtraction() {
int num1 = rand() % 100 + 1;
int num2 = rand() % 100 + 1;
if (num1 < num2) {
int temp = num1; num1 = num2; num2 = temp; }
int answer;
printf("%d - %d = ? \n", num1, num2);
scanf("%d", &answer);

if (answer == num1 - num2) {
    printf("Correct!\n");
    scores[playeri]++;
} else {
    printf("Wrong! The answer is %d\n", num1 - num2);
}
return 0;

}

int multiplication() {
int num1 = rand() % 10 + 1;
int num2 = rand() % 10 + 1;
int answer;
printf("%d * %d = ? \n", num1, num2);
scanf("%d", &answer);

if (answer == num1 * num2) {
    printf("Correct!\n");
    scores[playeri]++;
} else {
    printf("Wrong! The answer is %d\n", num1 * num2);
}
return 0;

}

int division() {
int num1 = (rand() % 10 + 1) * (rand() % 10 + 1);
int num2 = rand() % 10 + 1;
int answer;
printf("%d / %d = ? (integer division) \n", num1, num2);
scanf("%d", &answer);

if (answer == num1 / num2) {
    printf("Correct!\n");
    scores[playeri]++;
} else {
    printf("Wrong! The answer is %d\n", num1 / num2);
}
return 0;

}

void display()
    for (int i = 0; i < MAX - 1; i++) {
        for (int j = 0; j < MAX - i - 1; j++) {
            if (scores[j] < scores[j + 1]) {
                int tempScore = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = tempScore;

                char tempName[50];
                strcpy(tempName, name[j]);
                strcpy(name[j], name[j + 1]);
                strcpy(name[j + 1], tempName);

                char tempKey[10];
                strcpy(tempKey, key[j]);
                strcpy(key[j], key[j + 1]);
                strcpy(key[j + 1], tempKey);
            }
        }
    }
printf("\n\tLeaderboards\n");
printf("===========================\n");
printf("NAME\t\tSCORES\n");
for (int i = 0; i < MAX; i++) {
 if (name[i][0] != '\0') {
 printf("%d.) %s\t\t     %d\n",i+1, name[i], scores[i]);
   }
  }
 }

void save() {
FILE *file = fopen("scores.txt", "w");
for (int i = 0; i < MAX; i++) {
if (name[i][0] != '\0') {
fprintf(file, " %s %s %d\n", name[i], key[i], scores[i]);
  }
 }
 fclose(file);
 }

void load() {
 FILE *file = fopen("scores.txt", "r");
  if (!file) return;
  for (int i = 0; i < MAX; i++) {
fscanf(file, "%s %s %d", name[i], key[i], &scores[i]);
    }
  fclose(file); }


