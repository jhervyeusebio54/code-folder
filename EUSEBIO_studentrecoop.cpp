//C++ as Object Oriented Programming Language
/* Eusebio, John Jhervy G.
BSIT-1B
*/#include <iostream>
#include <iomanip>
#include <fstream>//ofstream for writing to file,ifstream for reading from file
#define MAX 20
using namespace std;

struct Record{
string name;
int q1,q2,q3;
};
class Person{
private:
    Record student[MAX];
    int last;
    bool isfull();
    bool isempty();
    int locate(string n);
public:
    void init();
    void add(Record rec);
    void update(string n);
    void del(string n);
    void display();
    void save();
    void retrieve();
};

int menu();//ordinary function
int main(){
Record data;
Person it1b;
it1b.init();
it1b.retrieve();
while(true){
    switch(menu()){
    case 1 : system("cls");cout<<"Input name: ";cin.ignore();getline(cin,data.name);
             cout<<"Input quiz1: ";cin>>data.q1;cout<<"Input quiz2: ";cin>>data.q2;cout<<"Input quiz3: ";cin>>data.q3; it1b.add(data);break;
    case 2 : system("cls");cout<<"Input name to update: ";cin.ignore();getline(cin,data.name);it1b.update(data.name);break;    case 3 : system("cls");cout<<"Input name: ";cin.ignore();getline(cin,data.name);it1b.del(data.name);break;
    case 4 : it1b.display();break;
    case 5 : it1b.save();exit(0);
    default: cout<<"Invalid input.\n";system("pause");
    }


}

}
//class methods definitions
void Person::init(){
  last = -1;
}
void Person::add(Record rec){
if (isfull()){
    cout<<"Array is full.\n";system("pause");
}
else {
    last++;
    student[last] = rec;
}

}
void Person::update(string n){
int index = locate(n);
    if (index >= 0){
        cout<<"Updating record for "<<student[index].name<<endl;
        cout<<"Input new quiz1: ";cin>>student[index].q1;cout<<"Input new quiz2: ";cin>>student[index].q2;cout<<"Input new quiz3: ";cin>>student[index].q3;}
    else{
        cout << "Record not found.\n";
        system("pause");}
}

void Person::del(string n){
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
        cout << "Record deleted\n" << endl;
    }

}

}
void Person::display(){
system("cls");
cout<<setw(10)<<right<<"NAME"<<setw(10)<<right<<"QUIZ1"<<setw(10)<<right<<"QUIZ2"<<setw(10)<<right<<"QUIZ3"<<setw(15)<<right<<"AVERAGE"<<setw(10)<<right<<"REMARKS"<<endl;
for (int i=0;i<=last;i++){
float ave = (student[i].q1+student[i].q2+student[i].q3)/3.0;
        cout<<i+1<<".) "<<setw(15)<<left<<student[i].name<<setw(10)<<left<<student[i].q1<<setw(10)<<left<<student[i].q2<<setw(10)<<left<<student[i].q3<<setw(10)<<left<<fixed<<setprecision(2)<<ave<<setw(10)<<left<<(ave>=75? "Passed":"Failed")<<endl;
}
system("pause");
}
bool Person::isfull(){
 return (last==MAX-1);
}
bool Person::isempty(){
 return (last==-1);
}
int Person::locate(string n){
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
cout <<"2. Update a Record\n";
cout <<"3. Delete a record\n";
cout <<"4. Display\n";
cout <<"5. Exit\n";
cout <<"Select(1-5): ";
cin >> op;
return op;
}
void Person::save(){
ofstream fp("it1bfile.txt");//open the file for writing
if (!fp){
    cout<<"File error.\n";
    system("pause");
}
else {
    for (int i=0;i<=last;i++){
        fp<<student[i].name<<endl<<student[i].q1<<endl<<student[i].q2<<endl<<student[i].q3<<endl;
    }
}
fp.close();
}
void Person::retrieve(){
ifstream fp("it1bfile.txt");//open the file for reading
if (!fp){
    cout<<"File error.\n";
    system("pause");
}
else {
    Record sr;
    while(getline(fp,sr.name) && fp>>sr.q1 && fp>>sr.q2 && fp>>sr.q3){
       fp.ignore();
       add(sr);
    }
}
fp.close();
}
    