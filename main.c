

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

int menu(); 
int addition(); 
int subtraction(); 
int multiplication(); 
int division(); 
int menulogsign(); 
void display(); 
void save(); 
void load(); 
void login(); 
void signin();

int main() { 
load();

switch (menulogsign()) {
    case 1: login(); break;
    case 2: signin(); break;
    case 3: return 0;
}

int choice;
while ((choice = menu()) != 6) {
    switch (choice) {
        case 1: addition(); break;
        case 2: subtraction(); break;
        case 3: multiplication(); break;
        case 4: division(); break;
        case 5: display(); break;
    }
}
save();
return 0;

}

int menu() { 
int op; 
printf("\nPLAY\n"); 
printf("1. Addition\n"); 
printf("2. Subtraction\n"); 
printf("3. Multiplication\n"); 
printf("4. Division\n");
printf("5. Leaderboards\n"); 
printf("6. Save and Exit\n"); 
printf("\nSelect(1-6): "); 
scanf("%d", &op); 
return op; }

int addition() { 
srand(time(NULL)); 
int num1 = rand() % 100 + 1; 
int num2 = rand() % 100 + 1; 
int answer; 
printf("%d + %d = ? ", num1, num2); 
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
srand(time(NULL)); 
int num1 = rand() % 100 + 1; 
int num2 = rand() % 100 + 1; 
if (num1 < num2) { 
int temp = num1; num1 = num2; num2 = temp; } 
int answer; 
printf("%d - %d = ? ", num1, num2); 
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
srand(time(NULL)); 
int num1 = rand() % 10 + 1; 
int num2 = rand() % 10 + 1; 
int answer; 
printf("%d * %d = ? ", num1, num2); 
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
srand(time(NULL)); 
int num1 = (rand() % 10 + 1) * (rand() % 10 + 1); 
int num2 = rand() % 10 + 1; 
int answer; 
printf("%d / %d = ? (integer division) ", num1, num2); 
scanf("%d", &answer);

if (answer == num1 / num2) {
    printf("Correct!\n");
    scores[playeri]++;
} else {
    printf("Wrong! The answer is %d\n", num1 / num2);
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
return o; }

void display() { 
printf("\nLeaderboard:\n"); 
for (int i = 0; i < MAX; i++) {
 if (name[i][0] != '\0') { 
 printf("%s - %d\n", name[i], scores[i]);
   } 
  }
 }

void save() { 
FILE *file = fopen("scores.txt", "w"); 
for (int i = 0; i < MAX; i++) { 
if (name[i][0] != '\0') { 
fprintf(file, "%s %s %d\n", name[i], key[i], scores[i]);
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

void login() {
 char uname[50], pword[10]; 
 printf("Enter your Username: ");
  scanf("%s", uname);
   printf("Enter your Password: ");
    scanf("%s", pword);

for (int i = 0; i < MAX; i++) {
    if (strcmp(name[i], uname) == 0 && strcmp(key[i], pword) == 0) {
        printf("Login successful!\n");
        playeri = i;
        return;
    }
}
printf("Invalid credentials.\n");
exit(0);

}

void signin() { 
char uname[50], pword[10]; 
printf("Enter a Username: "); 
scanf("%s", uname); 
printf("Enter a Password: "); 
scanf("%s", pword);

for (int i = 0; i < MAX; i++) {
    if (name[i][0] == '\0') {
        strcpy(name[i], uname);
        strcpy(key[i], pword);
        playeri = i;
        printf("Account created successfully!\n");
        return;
    }
}
printf("Max users reached!\n");
exit(0);

}

