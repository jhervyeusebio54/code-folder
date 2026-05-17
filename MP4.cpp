//Pointer implementation of lists using Link list
#include <iostream>
#include <cstdlib>
using namespace std;

struct Record{
    string name;
    int age;
};
struct node{
    Record data;
    node *next;
    node(Record x) : data(x), next (nullptr){}
};

class List{
private:
node* head;

public:
void makenull();
void add(Record x);
void del(string name);
void display();
int menu();
};

int main(){
List l;
l.makenull();
Record rec;
while(true){
    switch(l.menu()){
    case 1: system("cls");
            cout << "Enter name: ";
            cin >> rec.name;
            cout << "Enter age: ";
            cin >> rec.age;
            l.add(rec);
            system("pause");
            break;
    case 2: system("cls");
            cout<<"Input name to delete: ";
            cin>>rec.name;
            l.del(rec.name);
            break;
    case 3: l.display();
            break;
    case 4: exit(0);
    default: cout<<"1-4 only\n";
            system("pause");
    }
}
return 0;
}
void List::makenull(){
    head = nullptr;
}
void List::add(Record x){
node* newnode= new node(x);
    if (head == nullptr) {
        head = newnode;
    } else {
        node* p = head;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = newnode;
    }
}

void List::del(string name){
node*p=head;
node*q=nullptr;
while(p!=nullptr && p->data.name!=name){
    q=p;
    p=p->next;
}
if (p==nullptr){
    cout<<"Not found.\n";
    system("pause");
}
else {
    if (p==head)//first element
        head=p->next;
    else
        q->next = p->next;

    delete(p);
}

}
void List::display(){
node* p=head;
int i=1;
system("cls");
if(p!=nullptr){
    cout<<"The List contains:\n";
      cout << "NO.\tName \t\tAge \tRemarks \n";
while (p!=nullptr){
   cout<<i++<<".)\t"<<p->data.name<<"\t\t"<<p->data.age<<"\t"<<(p->data.age <18? "MINOR":"ADULT")<<endl;
    p=p->next;
}
system("pause");
}
else{
    cout<<"the list is empty\n";
    system("pause");
}
}

int List::menu(){
int op;
system("cls");
cout<<"MENU\n";
cout<<"1. Insert Record\n";
cout<<"2. Delete Record\n";
cout<<"3. Display\n";
cout<<"4. Exit\n";
cout<<"Select(1-4): ";
cin>> op;
return op;

}
