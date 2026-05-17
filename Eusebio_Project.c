/*
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
#include<string.h>
#include<time.h>
#define MAX 5

char username[MAX][50];
char password[MAX][20];
int overall[MAX];
int addscore[MAX];
int subscore[MAX];
int mulscore[MAX];
int divscore[MAX];
int total = 0;
int current = -1;

int menu();
int addition();
int subtraction();
int multiplication();
int division();
void login();
void display();
void save();
void load();
void account();

int main(){
    int choice;
    srand(time(NULL));
    load();
    login();

    do{
        choice = menu();
        switch(choice){
        case 1:
            addition();
            break;
        case 2:
            subtraction();
            break;
        case 3:
            multiplication();
            break;
        case 4:
            division();
            break;
        case 5:
            save();
            printf("Saved\n");
            break;
        default:
            printf("Invalid\n");

        }
        system("pause");
        system("cls");
    }while(choice!=5);
    return 0;
}

int menu(){
    int op;
    printf("\n1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Save and Exit\n");
    printf("Select: ");
    scanf("%d",&op);
    return op;
}

int addition(){
    int a,b,ans,user;
    a=rand()%50;
    b=rand()%50;
    ans=a+b;
    printf("\n%d + %d = ",a,b);
    scanf("%d",&user);
    if(user==ans){
        printf("Correct\n");
        overall[current]++;
        addscore[current]++;

    }else{
        printf("Wrong Answer: %d\n",ans);

    }
    return 0;
}

int subtraction(){
    int a,b,ans,user;
    a=rand()%100;
    b=rand()%50;
    ans=a-b;
    printf("\n%d - %d = ",a,b);
    scanf("%d",&user);

    if(user==ans){
        printf("Correct\n");
        overall[current]++;
        subscore[current]++;

    }else{
        printf("Wrong Answer: %d\n",ans);
    }
    return 0;
}

int multiplication(){
    int a,b,ans,user;
    a=rand()%12;
    b=rand()%12;
    ans=a*b;
    printf("\n%d * %d = ",a,b);
    scanf("%d",&user);

    if(user==ans){
        printf("Correct\n");
        overall[current]++;
        mulscore[current]++;

    }else{
        printf("Wrong Answer: %d\n",ans);
    }
    return 0;
}

int division(){
    int a,b,ans,user;
    b=(rand()%10)+1;
    ans=(rand()%10)+1;
    a=b*ans;

    printf("\n%d / %d = ",a,b);
    scanf("%d",&user);
    if(user==ans){
        printf("Correct\n");
        overall[current]++;
        divscore[current]++;
    }else{
        printf("Wrong Answer: %d\n",ans);
    }
    return 0;
}

void login(){
    int choice;
    int found=0;
    char acc[50];
    char pass[20];
    printf("1. Login\n");
    printf("2. Sign Up\n");
    printf("Select: ");
    scanf("%d",&choice);
    if(choice==2){
        account();
        return;
    }
    printf("Enter Username: ");
    scanf("%s",acc);
    printf("Enter Password: ");
    scanf("%s",pass);
    for(int i=0;i<total;i++){
        if(strcmp(acc,username[i])==0 &&
           strcmp(pass,password[i])==0){
            current=i;
            found=1;
        }
    }

    if(found){
        printf("Login Success\n");
        display();
    }else{
        printf("Account Not Found\n");
        account();
    }

}

void display(){
    printf("\nLeaderboard\n");
    for(int i=0;i<total;i++){
        printf("\n%s\n",username[i]);
        printf("Overall: %d\n",overall[i]);
        printf("Addition: %d\n",addscore[i]);
        printf("Subtraction: %d\n",subscore[i]);
        printf("Multiplication: %d\n",mulscore[i]);
        printf("Division: %d\n",divscore[i]);

    }

}
void save(){
    FILE *fp;
    fp=fopen("records.txt","w");
    if(fp==NULL){
        return;
    }
    fprintf(fp,"%d\n",total);
    for(int i=0;i<total;i++){
        fprintf(fp,"%s %s %d %d %d %d %d\n",
                username[i],
                password[i],
                overall[i],
                addscore[i],
                subscore[i],
                mulscore[i],
                divscore[i]);

    }
    fclose(fp);
}

void load(){
    FILE *fp;
    fp=fopen("records.txt","r");
    if(fp==NULL){
        return;

    }

    fscanf(fp,"%d",&total);
    for(int i=0;i<total;i++){
        fscanf(fp,"%s %s %d %d %d %d %d",
               username[i],
               password[i],
               &overall[i],
               &addscore[i],
               &subscore[i],
               &mulscore[i],
               &divscore[i]);
    }
    fclose(fp);

}

void account(){
    printf("Enter Username: ");
    scanf("%s",username[total]);
    printf("Enter Password: ");
    scanf("%s",password[total]);
    overall[total]=0;
    addscore[total]=0;
    subscore[total]=0;
    mulscore[total]=0;
    divscore[total]=0;
    current=total;
    total++;  
    printf("Account Created\n");

}