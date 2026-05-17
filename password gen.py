import random
import string

def generate_password(length=12, use_symbols=True):
    characters = string.ascii_letters + string.digits

    if use_symbols:
        characters += string.punctuation

    password = ''.join(random.choice(characters) for _ in range(length))
    return password

def save_password(password):
    with open("passwords.txt", "a") as file:
        file.write(password + "\n")

def main():
    print("=== PASSWORD GENERATOR ===")

    try:
        length = int(input("Enter password length: "))
    except ValueError:
        print("Invalid input. Using default length = 12")
        length = 12

    symbol_choice = input("Include symbols? (y/n): ").lower()
    use_symbols = symbol_choice == "y"

    password = generate_password(length, use_symbols)

    print("\nGenerated Password:")
    print(password)

    save_choice = input("\nSave password to file? (y/n): ").lower()

    if save_choice == "y":
        save_password(password)
        print("Password saved to passwords.txt")

if __name__ == "__main__":
    main()