
//Using User-defined Functios and local Variables
#include <stdio.h>
#include <stdlib.h>
#define MAX 2


//Declare the UDFs
void getRecord(char name[MAX][31],int i,int q1[MAX],int q2[MAX],int q3[MAX]);
void display(char name[MAX][31],int i,int q1[MAX],int q2[MAX],int q3[MAX],float ave);
float avg(int x, int y, int z);

int main(){
 char name[MAX][31];
 int i,q1[MAX],q2[MAX],q3[MAX];
 float ave;
getRecord(name, i, q1,q2,q3);
display(name, i, q1,q2,q3,ave);
return 0;
}
//Define UDFs
void getRecord(char name[MAX][31],int i,int q1[MAX],int q2[MAX],int q3[MAX]){
for (i=0;i<MAX;i++){
    printf("Input name: ");
    scanf(" %[^\n]",name[i]);
    printf("Input Quiz1: ");
    scanf("%d",&q1[i]);
    printf("Input Quiz2: ");
    scanf("%d",&q2[i]);
    printf("Input Quiz3: ");
    scanf("%d",&q3[i]);
    //flush input buffer
    //getchar();
 }
}
void display(char name[MAX][31],int i,int q1[MAX],int q2[MAX],int q3[MAX],float ave){
system("cls");
printf("  NAME\t\t\tQUIZ1\tQUIZ2\tQUIZ3\tAVERAGE\tREMARKS\n");
for (i=0;i<MAX;i++){
    ave =avg(q1[i],q2[i],q3[i]);//type casting
    printf("%d.) %s\t\t%d\t%d\t%d\t%6.2f\t",i+1,name[i],q1[i],q2[i],q3[i],ave);//***.**
    if (ave>=75)
        printf("PASSED.\n");
    else
        printf("FAILED.\n");
 }

}
float avg(int x, int y, int z){
    return (x+y+z)/3.0;
}
