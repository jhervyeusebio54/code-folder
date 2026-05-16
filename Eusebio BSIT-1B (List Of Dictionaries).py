#EUSEBIO, JOHN JHERVY G.
#BSIT-1B
import os

MAX = 5

class studentrec:
    def __init__(self, filename="studentrec.txt"):
        self.rec = []
        self.filename = filename
        self.load_rec()

    def find_rec(self, name):
        for i, rec in enumerate(self.rec):
            if rec["name"] == name:
                return i
        return -1

    def is_full(self):
        return len(self.rec) >= MAX

    def append_rec(self, name, q1, q2, q3):
        if self.is_full():
            print("Student record is full.")
        elif self.find_rec(name) != -1:
            print("Student record already exists.")
        else:
            self.rec.append({
                "name": name,
                "q1": float(q1),
                "q2": float(q2),
                "q3": float(q3),
                "ave": round((float(q1) + float(q2) + float(q3)) / 3, 2)
            })
            print("Student added.")
            self.save_rec()

    def delete_rec(self, name):
        index = self.find_rec(name)
        if index == -1:
            print("Student not found.")
        else:
            del self.rec[index]
            print("Student deleted.")
            self.save_rec()

    def display_rec(self):
        os.system('cls' if os.name == 'nt' else 'clear')
        print("STUDENT RECORD:")
        print("NAME | QUIZ1 | QUIZ2 | QUIZ3 | AVERAGE")
        print("-" * 40)
        for rec in self.rec:
            print(f"{rec['name']} | {rec['q1']} | {rec['q2']} | {rec['q3']} | {rec['ave']:.2f}")
        input("Press Enter to continue...")

    def save_rec(self):
        try:
            with open(self.filename, 'w') as file:
                for rec in self.rec:
                    line = f"{rec['name']},{rec['q1']},{rec['q2']},{rec['q3']},{rec['ave']}"
                    file.write(line + '\n')
        except IOError:
            print("Error saving records to file.")

    def load_rec(self):
        try:
            with open(self.filename, 'r') as file:
                for line in file:
                    parts = line.strip().split(',')
                    if len(parts) == 5:
                        name, q1, q2, q3, ave = parts
                        try:
                            self.rec.append({
                                "name": name,
                                "q1": float(q1),
                                "q2": float(q2),
                                "q3": float(q3),
                                "ave": float(ave)
                            })
                        except ValueError:
                            print(f"Skipping invalid record: {line}")
        except FileNotFoundError:
            pass
        except IOError:
            print("Error reading records from file.")

def menu():
    print("STUDENT RECORD")
    print("1. Add student record")
    print("2. Delete student record")
    print("3. Display record")
    print("4. Exit")
    return input("\nSelect (1-4): ")

def main():
    student = studentrec()
    while True:
        choice = menu()
        if choice == '1':
            try:
                name = input("Enter Student Name: ")
                q1 = input("Enter quiz1: ")
                q2 = input("Enter quiz2: ")
                q3 = input("Enter quiz3: ")
                student.append_rec(name, q1, q2, q3)
            except ValueError:
                print("Invalid input.")
            input("Press Enter to continue...")
        elif choice == '2':
            name = input("Enter student name to delete: ")
            student.delete_rec(name)
            input("Press Enter to continue...")
        elif choice == '3':
            student.display_rec()
        elif choice == '4':
            print("Saving and exiting...")
            student.save_rec()
            break
        else:
            print("Invalid input.")
            input("Press Enter to continue...")

if __name__ == "__main__":
    main()