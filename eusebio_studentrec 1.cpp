//C++ as a Procedural Programming Language
/*Write the STudent Record Program in C++ procedural programming. Without file handling.

MENU
1.ADD RECORD
2.UPDATE RECORD
3.DELETE RECORD
4.DISPLAY
5.EXIT

*/
//EUSEBIO, JOHN JHERVY G.
#include <iostream>
#include <iomanip>
#define MAX 3
using namespace std;
//GLOBAL VARIABLES
struct Record{
string name;
int q1,q2,q3;
int age;
};
Record student[MAX];//ARRAY OF STRUCTURES
int last;
//Declare UDFs
void init();
void add(Record rec);
void update(string name);
void del(string n);
void display();
bool isfull();//true or false
bool isempty();
int locate(string n);
int menu();

int main(){
Record data;
init();
while(true){
    switch(menu()){
    case 1 : system("cls");cout<<"Input name: ";cin>>data.name;/* cout<<"Input Age: ";cin>>data.age; */
            cout<<"Input quiz1: ";cin >>data.q1;cout<<"Input quiz2: ";cin>>data.q2;cout<<"Input quiz3: ";cin>>data.q3;add(data);
            break;
    case 2 : system ("cls");cout<<"Input name to update:";cin>>data.name;update(data.name);break;// for update
    case 3 : system("cls");cout<<"Input name: ";cin>>data.name;del(data.name);break;
    case 4 : display();break;
    case 5 : exit(0);
    default: cout<<"Invalid input.\n";system("pause");
    }
}

}
//UDFs definitions
void init(){
  last = -1;
}
void add(Record rec){
if (isfull()){
    cout<<"Array is full.\n";system("pause");
}
else {
    last++;
    student[last] = rec;
}

}
void update(string name){
    int index = locate(name);
    if (index >= 0){
        cout<<"Updating record for "<<student[index].name<<endl;
        cout<<"Input new quiz1: ";cin>>student[index].q1;cout<<"Input new quiz2: ";cin>>student[index].q2;cout<<"Input new quiz3: ";cin>>student[index].q3;}
    else{
        cout << "Record not found.\n";
        system("pause");}
}



void del(string n){
int i,p;
if (isempty()){
    cout<<"There's nothing to delete.\n";
    system("pause");
}
else {
    p=locate(n);
    if (p<0){
       cout<<"Record not found.\n";
       system("pause");
    }
    else {
        for (i=p;i<last;i++){
            student[i] = student[i+1];
        }
        last--;
    }

}

}
void display(){
system("cls");
cout<<setw(10)<<right<<"NAME"<<setw(10)<<right<<"Quiz1"<<setw(10)<<right<<"Quiz2"<<setw(10)<<right<<"Quiz3"<<setw(10)<<right<<"AVERAGE"<<setw(10)<<right<<"REMARKS"<<endl;
for (int i=0;i<=last;i++){
        float ave = (student[i].q1+student[i].q2+student[i].q3)/3.0;
    cout<<i+1<<".) "<<setw(10)<<left<<student[i].name<<setw(10)<<left<<student[i].q1<<setw(10)<<left<<student[i].q2<<setw(10)<<left<<student[i].q3<<setw(10)<<left<<fixed<<setprecision(2)<<ave<<setw(10)<<left<<(ave>=75? "PASSED":"FAILED")<<endl;
    //<<setw(10)<<left<<(studestudent[i].q1nt[i].age>=18? "ADULT":"MINOR")<<endl;
}
system("pause");
}
bool isfull(){
 return (last==MAX-1);
}
bool isempty(){
 return (last==-1);
}
int locate(string n){
int i;
for (i=0;i<=last;i++){
    if (n==student[i].name)
         return i;
}
return -1;
}
int menu(){
int op;
system("cls");
cout <<"MENU\n";
cout <<"1. Add a Record\n";
cout <<"2. Update a Record\n";cout <<"3. Delete a Record\n";
cout <<"4. Display\n";
cout <<"5. Exit\n";
cout <<"Select(1-5): ";
cin >> op;
return op;
}
