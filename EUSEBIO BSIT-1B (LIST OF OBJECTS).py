#Eusebio, John Jhervy G.
#BSIT-1B
import os

MAX = 5

class studentrec:
    def __init__(self, name, q1, q2, q3):
        self.name = name
        self.q1 = float(q1)
        self.q2 = float(q2)
        self.q3 = float(q3)
        self.ave = round((self.q1 + self.q2 + self.q3) / 3, 2)
        
    def __str__(self):
        return f"{self.name} | {self.q1} | {self.q2} | {self.q3} | {self.ave}"

    def to_csv(self):
        return f"{self.name},{self.q1},{self.q2},{self.q3},{self.ave}"

    @staticmethod
    def from_csv(line):
        parts = line.strip().split(',')
        if len(parts) == 5:
            name, q1, q2, q3, ave = parts
            return studentrec(name, q1, q2, q3)
        return None

class studentlist:
    def __init__(self, filename="studentrec.txt"):
        self.accounts = []
        self.filename = filename
        self.load_rec()

    def find_rec(self, name):
        for i, acc in enumerate(self.accounts):
            if acc.name == name:
                return i
        return -1

    def is_full(self):
        return len(self.accounts) >= MAX

    def append_rec(self, name, q1, q2, q3):
        if self.is_full():
            print("Student record is full.")
        elif self.find_rec(name) != -1:
            print("Student already exists.")
        else:
            self.accounts.append(studentrec(name, q1, q2, q3))
            print("Student added.")
            self.save_rec()

    def delete_rec(self, name):
        index = self.find_rec(name)
        if index == -1:
            print("Student not found.")
        else:
            del self.accounts[index]
            print("Student deleted.")
            self.save_rec()

    def display_rec(self):
        os.system('cls' if os.name == 'nt' else 'clear')
        print("Student List:")
        print("Name | quiz1 | quiz2 | quiz3 | Average")
        print("-" * 50)
        for acc in self.accounts:
            print(acc)
        input("Press Enter to continue...")

    def save_rec(self):
        try:
            with open(self.filename, 'w') as file:
                for acc in self.accounts:
                    file.write(acc.to_csv() + '\n')
        except IOError:
            print("Error saving record to file.")

    def load_rec(self):
        try:
            with open(self.filename, 'r') as file:
                for line in file:
                    acc = studentrec.from_csv(line)
                    if acc:
                        self.accounts.append(acc)
        except FileNotFoundError:
            pass
        except IOError:
            print("Error reading record from file.")

def menu():
    print("STUDENT RECORD MENU")
    print("1. Add Student")
    print("2. Delete Student")
    print("3. Display Students")
    print("4. Exit")
    return input("\nSelect (1-4): ")

def main():
    Student = studentlist()
    while True:
        choice = menu()
        if choice == '1':
            try:
                name = input("Enter student name: ")
                q1 = float(input("Enter quiz1: "))
                q2 = float(input("Enter quiz2: "))
                q3 = float(input("Enter quiz3: "))
                Student.append_rec(name, q1, q2, q3)
            except ValueError:
                print("Invalid input. Please enter numeric values for quizzes.")
            input("Press Enter to continue...")
        elif choice == '2':
            name = input("Enter student name to delete: ")
            Student.delete_rec(name)
            input("Press Enter to continue...")
        elif choice == '3':
            Student.display_rec()
        elif choice == '4':
            print("Saving and exiting...")
            Student.save_rec()
            break
        else:
            print("Invalid input.")
            input("Press Enter to continue...")

if __name__ == "__main__":
    main()