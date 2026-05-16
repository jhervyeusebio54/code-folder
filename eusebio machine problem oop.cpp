/*
Eusebio, John Jhervy G.
BSIT-1B
*/
#include<iostream>
#include<fstream>
#include<ctime>
#include<cmath>
#include <cstring>
#define MAX 10
using namespace std;

// Base class: Account (for managing user data)
// Encapsulation
class Account {
protected:
    string name[MAX];
    string key[MAX];
    int playeri = -1;
};
// Inheritance: Game class inherits from Account
// Game class encapsulates all the logic of the math quiz game
class Game : public Account {
private:
// Arrays to store scores for each user by category
    int scores[MAX]; //overall (sum) score
    int scores1[MAX];//addition
    int scores2[MAX];//subtraction
    int scores3[MAX];//multiplication
    int scores4[MAX];//division
public:
   // Constructor
Game() {
for (int i = 0; i < MAX; i++) {
    name[i] = "";
    key[i] = "";
    scores[i] = 0;
    scores1[i] = 0;
    scores2[i] = 0;
    scores3[i] = 0;
    scores4[i] = 0;
    }
}
int menulogsign();
void login();
void signin();
int menu();
//polymorphism
void showScore(int s);
void allScore(int s1, int s2,int s3, int s4);
int addition();
int subtraction();
int multiplication();
int division();

void display();
void display1();
void display2();
void display3();
void display4();
int menu1();
int menu2();
void save();
void load();
};
// Entry point
int main() {
Game g;//
g.load();//load data
srand(time(NULL));//generate random num
while (1) {
    switch (g.menulogsign()) {
        case 1: system("cls"); g.login(); system("pause"); system("cls"); break;
        case 2: system("cls"); g.signin(); system("pause"); system("cls"); break;
        case 3: g.save(); exit(0);
        default: cout << "1 to 3 only.\n"; system("pause"); system("cls");
    }
}
return 0;
}
//menu to choose log,sing in and exit
int Game::menulogsign() {
int o;
cout << "\n\tMenu\n";
cout << "===========================\n";
cout << "1. Login\n";
cout << "2. Sign in\n";
cout << "3. Exit\n";
cout << "\nSelect(1-3): ";
cin >> o;
return o;
}
//menu after login
int Game::menu() {
int op;
cout << "\n\tPLAY\n";
cout << "===========================\n";
cout << "1. Addition\n";
cout << "2. Subtraction\n";
cout << "3. Multiplication\n";
cout << "4. Division\n";
cout << "5. Leaderboards\n";
cout << "6. Save & Exit\n";
cout << "\nSelect(1-6): ";
cin >> op;
return op;
}
//menu for leaderboard options
int Game::menu1() {
int a;
cout << "\n\tMenu\n";
cout << "===========================\n";
cout << "1. Overall Leaderboard\n";
cout << "2. Per Operation Leaderboard\n";
cout << "3. Exit\n";
cout << "Select (1-3): ";
cin >> a;
return a;
}
//operations specific leaderboard
int Game::menu2() {
int b;
cout << "\n\tMenu\n";
cout << "===========================\n";
cout << "1. Addition Leaderboard\n";
cout << "2. Subtraction Leaderboard\n";
cout << "3. Multiplication Leaderboard\n";
cout << "4. Division Leaderboard\n";
cout << "5. Exit\n";
cout << "Select (1-5): ";
cin >> b;
return b;
}
//sign in function
void Game::signin() {
string uname, pword;
cout << "Sign in\n";
cout << "Enter a Username: ";
cin.ignore();
getline(cin, uname);
cout << "Enter a Password: ";
cin >> pword;
for (int i = 0; i < MAX; i++) {
    if (name[i] == "") {
        name[i] = uname;
        key[i] = pword;
        cout << "Account created successfully!\n";
        return;
    }
}
cout << "Max users reached!\n";
}
//log in function
void Game::login() {
string uname, pword;
cout << "Login\n";
cout << "Enter your Username: ";
cin.ignore();
getline(cin, uname);
cout << "Enter your Password: ";
cin >> pword;

for (int i = 0; i < MAX; i++) {
if (name[i] == uname && key[i] == pword) {
    cout << "Login successful!\n";
    playeri = i;
    system("pause");
    system("cls");
    int d;
    //main game loop
    while ((d = menu()) != 6) {
        switch (d) {
            case 1: system("cls"); addition(); system("pause"); system("cls"); break;
            case 2: system("cls"); subtraction(); system("pause"); system("cls"); break;
            case 3: system("cls"); multiplication(); system("pause"); system("cls"); break;
            case 4: system("cls"); division(); system("pause"); system("cls"); break;
            case 5: system("cls");
                int d1;
                while ((d1 = menu1()) != 3) {
                    switch (d1) {
                        case 1: system("cls"); display(); system("pause"); system("cls"); break;
                        case 2: system("cls");
                            int d2;
                            while ((d2 = menu2()) != 5) {
                                switch (d2) {
                                    case 1: system("cls"); display1(); system("pause"); system("cls"); break;
                                    case 2: system("cls"); display2(); system("pause"); system("cls"); break;
                                    case 3: system("cls"); display3(); system("pause"); system("cls"); break;
                                    case 4: system("cls"); display4(); system("pause"); system("cls"); break;
                                    case 5: break;
                                    default: cout << "1 to 5 only.\n"; system("pause"); system("cls"); break;
                                }
                            }
                            system("cls");
                            break;
                        default: cout << "1 to 3 only.\n"; system("pause"); system("cls"); break;
                    }
                }
                system("cls");
                break;
            default: cout << "1 to 6 only.\n"; system("pause"); system("cls"); break;
        }
    }
    // Show final score summary and save progress
allScore(scores1[playeri], scores2[playeri],scores3[playeri],scores4[playeri]);
save();return;
}
}
cout << "Invalid credentials.\n";
}
// Below are the quiz functions for each operation, demonstrating encapsulation
int Game::addition() {
int num1 = rand() % 100 + 1;
int num2 = rand() % 10 + 1;
int answer;
cout << num1 << " + " << num2 << " = ? ";
cin >> answer;
if (answer == num1 + num2) {
    cout << "Correct!\n";
    scores1[playeri]++;
        showScore(scores1[playeri]);
} else {
    cout << "Wrong! The answer is " << (num1 + num2) << "\n";
}
return 0;
}

int Game::subtraction() {
int num1 = rand() % 100 + 1;
int num2 = rand() % 10 + 1;
if (num1 < num2) swap(num1, num2);
int answer;
cout << num1 << " - " << num2 << " = ? ";
cin >> answer;
if (answer == num1 - num2) {
    cout << "Correct!\n";
    scores2[playeri]++;
    showScore(scores2[playeri]);
} else {
    cout << "Wrong! The answer is " << (num1 - num2) << "\n";
}
return 0;
}
int Game::multiplication() {
int num1 = rand() % 10 + 1;
int num2 = rand() % 10 + 1;
int answer;
cout << num1 << " * " << num2 << " = ? ";
cin >> answer;
if (answer == num1 * num2) {
    cout << "Correct!\n";
    scores3[playeri]++;
    showScore(scores3[playeri]);
} else {
cout << "Wrong! The answer is " << (num1 * num2) << "\n";
}
return 0;
}
int Game::division() {
int num2 = rand() % 10 + 1;
int num1 = num2 * (rand() % 10 + 1);
int answer;
cout << num1 << " / " << num2 << " = ? ";
cin >> answer;
if (answer == num1 / num2) {
    cout << "Correct!\n";
    scores4[playeri]++;
    showScore(scores4[playeri]);
} else {
    cout << "Wrong! The answer is " << (num1 / num2) << "\n";
}
return 0;
}
// Leaderboard functions sort scores and display them — demonstrating abstraction
void Game::display() {
for (int i = 0; i < MAX; i++)
    scores[i] = scores1[i] + scores2[i] + scores3[i] + scores4[i];
int sort[MAX];
    for (int i = 0; i < MAX; i++) sort[i] = i;
    for (int i = 0; i < MAX - 1; i++)
        for (int j = 0; j < MAX - i - 1; j++)
            if (scores[sort[j]] < scores[sort[j + 1]])
                swap(sort[j], sort[j + 1]);

cout << "\n  Overall Leaderboards\n";
cout << "===========================\n";
cout << "NAME\t\tSCORES\n";
    for (int i = 0; i < MAX; i++)
        if (!name[sort[i]].empty())
        cout << i + 1 << ".) " << name[sort[i]] << "\t\t" << scores[sort[i]] << "\n";
}

void Game::display1() {
int sort[MAX];
for (int i = 0; i < MAX; i++) sort[i] = i;
    for (int i = 0; i < MAX - 1; i++)
        for (int j = 0; j < MAX - i - 1; j++)
            if (scores1[sort[j]] < scores1[sort[j + 1]])
                swap(sort[j], sort[j + 1]);

cout << "\n  Addition Leaderboards\n";
cout << "NAME\t\tSCORES\n";
for (int i = 0; i < MAX; i++)
        if (!name[sort[i]].empty())
    cout << i + 1 << ".) " << name[sort[i]] << "\t\t" << scores1[sort[i]] << "\n";
}

void Game::display2() {
int sort[MAX];
for (int i = 0; i < MAX; i++) sort[i] = i;
    for (int i = 0; i < MAX - 1; i++)
        for (int j = 0; j < MAX - i - 1; j++)
            if (scores2[sort[j]] < scores2[sort[j + 1]])
                swap(sort[j], sort[j + 1]);

cout << "\n  Subtraction Leaderboards\n";
cout << "NAME\t\tSCORES\n";
    for (int i = 0; i < MAX; i++)
        if (!name[sort[i]].empty())
        cout << i + 1 << ".) " << name[sort[i]] << "\t\t" << scores2[sort[i]] << "\n";
}

void Game::display3() {
int sort[MAX];
for (int i = 0; i < MAX; i++) sort[i] = i;
    for (int i = 0; i < MAX - 1; i++)
        for (int j = 0; j < MAX - i - 1; j++)
            if (scores3[sort[j]] < scores3[sort[j + 1]])
                swap(sort[j], sort[j + 1]);

cout << "\n  Multiplication Leaderboards\n";
cout << "NAME\t\tSCORES\n";
    for (int i = 0; i < MAX; i++)
    if (!name[sort[i]].empty())
        cout << i + 1 << ".) " << name[sort[i]] << "\t\t" << scores3[sort[i]] << "\n";
}

void Game::display4() {
int sort[MAX];
for (int i = 0; i < MAX; i++) sort[i] = i;
    for (int i = 0; i < MAX - 1; i++)
        for (int j = 0; j < MAX - i - 1; j++)
            if (scores4[sort[j]] < scores4[sort[j + 1]])
                swap(sort[j], sort[j + 1]);

cout << "\n  Division Leaderboards\n";
cout << "NAME\t\tSCORES\n";
    for (int i = 0; i < MAX; i++)
        if (!name[sort[i]].empty())
        cout << i + 1 << ".) " << name[sort[i]] << "\t\t" << scores4[sort[i]] << "\n";
}

// Save user data and scores to a file 
void Game::save() {
    ofstream file("scores.txt");
    for (int i = 0; i < MAX; i++) {
        if (!name[i].empty()) {
            file << name[i] << endl;
            file << key[i] << endl;
            file << scores1[i] << endl;
            file << scores2[i] << endl;
            file << scores3[i] << endl;
            file << scores4[i] << endl;
        }
    }
    file.close();
}
//Load user data and scores from a file
void Game::load() {
    ifstream file("scores.txt");
    int i = 0;
    while (i < MAX && getline(file, name[i]) && getline(file, key[i])
        && file >> scores1[i] >> scores2[i] >> scores3[i] >> scores4[i]) {
        file.ignore(); 
        i++;
    }
    file.close();
}


// Show score after each question
void Game::showScore(int s) {
cout << "Your score: " << s << endl;
}
// Show all scores when user logs out
void Game::allScore(int s1, int s2,int s3,int s4) {
cout << "Score 1: " << s1 << " | Score 2: " << s2 <<" Score 3: " << s3 << " | Score 4: " << s4<< endl;
}

    