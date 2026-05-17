#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 10  // Maximum records

// Struct for one record
struct Record {
    string name;
    int age;
};

// Struct for the list
struct List {
    Record data[MAX];
    int last;
};

// ADTList class
class ADTList {
private:
    List L;

public:
    ADTList();
    bool isfull();
    bool isempty();
    void add(Record rec);
    void del(Record rec);
    void display();
    int menu();
};

// ==== Main Program ====
int main() {
    ADTList l;
    Record rec;

    while(true) {
    int choice=l.menu();
    cin.ignore(); // clear buffer before getline
        switch(choice) {
            case 1:
                system("cls");
                cout << "Enter full name: ";
                getline(cin, rec.name);
                cout << "Enter age: ";
                cin >> rec.age;
                l.add(rec);
                system("pause");
                break;

            case 2:
                system("cls");
                cout << "Enter name to delete: ";
                getline(cin, rec.name);
                l.del(rec);
                system("pause");
                break;

            case 3:
                system("cls");
                l.display();
                system("pause");
                break;

            case 4:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid choice. 1-4 only" << endl;
        }
    }
}
ADTList::ADTList() {
    L.last = -1;
}

bool ADTList::isfull() {
    return L.last == MAX - 1;
}

bool ADTList::isempty() {
    return L.last == -1;
}

void ADTList::add(Record rec) {
    if(isfull()) {
        cout << "List is full." << endl;
        return;
    }
    L.last++;
    L.data[L.last] = rec;
    cout << "Record added: " << rec.name << ", " << rec.age << endl;
}

void ADTList::del(Record rec) {
    if(isempty()) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    int pos = -1;
    for(int i = 0; i <= L.last; i++) {
        if(L.data[i].name == rec.name) {
            pos = i;
            break;
        }
    }

    if (pos != -1) {
        for(int i = pos; i < L.last; i++) {
            L.data[i] = L.data[i+1];
        }
        L.last--;
        cout << "Deleted record with name: " << rec.name << endl;
    }
    else {
        cout << "Name not found" << endl;
    }
}

void ADTList::display() {
    if(isempty()) {
        cout << "the list is empty." << endl;
        return;
    }
    else{
         cout << "No.\tName\t\tAge\tRemarks\n";
    for(int i = 0; i <= L.last; i++) {
        string remarks = (L.data[i].age >= 18) ? "Adult" : "Minor";
        cout << i+1 << ".\t"<< L.data[i].name << "\t\t"<< L.data[i].age << "\t"<< remarks << endl;
    }
    }

}

int ADTList::menu() {
    int op;
    system("cls");
    cout << "MENU\n";
    cout << "1. Add a Record\n";
    cout << "2. Delete a Record\n";
    cout << "3. Display\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
    cin>>op;
    return op;
}
