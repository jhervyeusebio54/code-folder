//Pointer implementation of lists using Link list
#include <iostream>
#include <cstdlib>
using namespace std;

 struct node {
int data;
node *next;
};

class List{
private:
node* head;

public:
void makenull();
void add(int x);
void del(int x);
void display();
int menu();
};

int main(){
List l;
l.makenull();
int x;
while(true){
    switch(l.menu()){
    case 1: system("cls");
            cout<<"Insert Mode\n";
            cout<<"Input x: ";
            cin>>x;
            l.add(x);
            break;
    case 2: system("cls");
            cout<<"Delete Mode\n";
            cout<<"Input x: ";
            cin>>x;
            l.del(x);
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
    head = NULL;
}

void List::add(int x){
node* newnode= new node;
newnode->data = x;
newnode->next = nullptr;
    if (head == nullptr) {
        head = newnode;}
    else {
        node* p = head;
        while (p->next != nullptr) {
        p = p->next;}
        p->next = newnode;
    }
}

void List::del(int x){
node*p=head;
node*q=nullptr;
while(p!=nullptr && p->data!=x){
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
while (p!=nullptr){
   cout<<i++<<".) "<<p->data<<endl;
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
cout<<"1. Insert data\n";
cout<<"2. Delete data\n";
cout<<"3. Display\n";
cout<<"4. Exit\n";
cout<<"Select(1-4): ";
cin>> op;
return op;

}
