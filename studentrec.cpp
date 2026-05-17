#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Student {
    int id;
    char name[50];
    int age;
    char course[50];
};

Student students[100];
int countStudent = 0;


void loadFile() {
    ifstream file("students.txt");

    while(file >> students[countStudent].id) {
        file.ignore();

        file.getline(students[countStudent].name, 50, '|');
        file >> students[countStudent].age;
        file.ignore();

        file.getline(students[countStudent].course, 50);

        countStudent++;
    }

    file.close();
}


void saveFile() {
    ofstream file("students.txt");

    for(int i = 0; i < countStudent; i++) {
        file << students[i].id << " "
             << students[i].name << "|"
             << students[i].age << "|"
             << students[i].course << endl;
    }

    file.close();

    cout << "\nRecords saved successfully.\n";
}


void addStudent() {
    cout << "\nADD STUDENT\n";

    cout << "Enter ID: ";
    cin >> students[countStudent].id;
    cin.ignore();

    cout << "Enter Name: ";
    cin.getline(students[countStudent].name, 50);

    cout << "Enter Age: ";
    cin >> students[countStudent].age;
    cin.ignore();

    cout << "Enter Course: ";
    cin.getline(students[countStudent].course, 50);

    countStudent++;

    cout << "\nStudent added successfully.\n";
}

void showStudents() {
    if(countStudent == 0) {
        cout << "\nNo records found.\n";
        return;
    }

    cout << "\nSTUDENT RECORDS \n";

    for(int i = 0; i < countStudent; i++) {
        cout << "\nRecord #" << i + 1 << endl;
        cout << "ID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Course: " << students[i].course << endl;
    }
}


void editStudent() {
    int id;
    bool found = false;

    cout << "\nEnter Student ID to edit: ";
    cin >> id;
    cin.ignore();

    for(int i = 0; i < countStudent; i++) {
        if(students[i].id == id) {
            found = true;

            cout << "\nEnter New Name: ";
            cin.getline(students[i].name, 50);

            cout << "Enter New Age: ";
            cin >> students[i].age;
            cin.ignore();

            cout << "Enter New Course: ";
            cin.getline(students[i].course, 50);

            cout << "\nRecord updated successfully.\n";
            break;
        }
    }

    if(!found) {
        cout << "\nStudent not found.\n";
    }
}


void deleteStudent() {
    int id;
    bool found = false;

    cout << "\nEnter Student ID to delete: ";
    cin >> id;

    for(int i = 0; i < countStudent; i++) {
        if(students[i].id == id) {
            found = true;

            for(int j = i; j < countStudent - 1; j++) {
                students[j] = students[j + 1];
            }

            countStudent--;

            cout << "\nRecord deleted successfully.\n";
            break;
        }
    }

    if(!found) {
        cout << "\nStudent not found.\n";
    }
}


int main() {
    int choice;

    loadFile();

    do {
        cout << "\n===== STUDENT RECORD SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Show Records\n";
        cout << "3. Edit Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Save Records\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                addStudent();
                break;

            case 2:
                showStudents();
                break;

            case 3:
                editStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                saveFile();
                break;

            case 6:
                saveFile();
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice.\n";
        }

    } while(choice != 6);

    return 0;
}