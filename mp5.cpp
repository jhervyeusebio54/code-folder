#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;
#define F  "C:\\code\\2nd year\\student record.txt"
#define MAX 10


struct Record {
    string name;
    int age;
};
struct List {
    Record data[MAX];
    int last;
};

class ADTList {
private:
    List L;

public:
    ADTList();
    bool isfull();
    bool isempty();
    void add(Record rec);
    void update(Record rec);
    void del(Record rec);
    void display();
    void save();
    void load();
    int menu();
};

int main() {
    ADTList l;
    Record rec;
    l.load();
    while(true) {
    int choice=l.menu();
    cin.ignore();
        switch(choice) {
            case 1:
                system("cls");
                cout << "Enter full name: ";
                getline(cin, rec.name);
                cout << "Enter age: ";
                cin >> rec.age;
                l.add(rec);
                l.save();
                system("pause");
                break;
            case 2:
                system("cls");
                cout << "Enter the name of the record to update: ";
                getline(cin, rec.name);
                cout << "Enter new age: ";
                cin >> rec.age;
                l.update(rec);
                l.save();
                system("pause");
                break;
            case 3:
                system("cls");
                cout << "Enter name to delete: ";
                getline(cin, rec.name);
                l.del(rec);
                l.save();
                system("pause");
                break;

            case 4:
                system("cls");
                l.display();
                system("pause");
                break;

            case 5:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid choice. 1-5 only" << endl;
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
void ADTList::update(Record rec){
if (isempty()) {
        cout << "List is empty. Nothing to update." << endl;
        return;
    }
    int pos = -1;
    for (int i = 0; i <= L.last; i++) {
        if (L.data[i].name == rec.name) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "Name not found." << endl;
        return;
    }
    L.data[pos] = rec;
    cout << "Record updated successfully." << endl;
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
void ADTList::save(){
 ofstream file(F);
    if (!file) {
        cout << "Error opening file for writing." << endl;
        return;
    }

    for (int i = 0; i <= L.last; i++) {
        file << L.data[i].name << "," << L.data[i].age << "\n";
    }

    file.close();
    cout << "Records saved to file." << endl;
}
void ADTList::load() {
    ifstream infile(F);
    if (!infile) {
        cout << "No saved file found, starting with empty list." << endl;
        return;
    }

    L.last = -1;
    while (!infile.eof() && L.last < MAX - 1) {
        string name;
        int age;
        if (getline(infile, name, ',') && infile >> age) {
            infile.ignore();
            L.last++;
            L.data[L.last].name = name;
            L.data[L.last].age = age;
        } else {
            break;
        }
    }

    infile.close();
    cout << "Records loaded from file." << endl;
}
int ADTList::menu() {
    int op;
    system("cls");
    cout << "MENU\n";
    cout << "1. Add a Record\n";
    cout << "2. Update a Record\n";
    cout << "3. Delete a Record\n";
    cout << "4. Display\n";
    cout << "5. Exit\n";
    cout << "Enter choice: ";
    cin>>op;
    return op;
}
