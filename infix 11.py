class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class ExpressionTree:
    def __init__(self):
        self.root = None

    def build_tree(self):
        # Expression: (10 + 5) * 10
        self.root = Node("*")
        self.root.left = Node("+")
        self.root.left.left = Node("10")
        self.root.left.right = Node("5")
        self.root.right = Node("10")

    # -------- Traversals --------
    def infix(self, node):
        if node:
            self.infix(node.left)
            print(node.data, end=" ")
            self.infix(node.right)

    def prefix(self, node):
        if node:
            print(node.data, end=" ")
            self.prefix(node.left)
            self.prefix(node.right)

    def postfix(self, node):
        if node:
            self.postfix(node.left)
            self.postfix(node.right)
            print(node.data, end=" ")

    # -------- Evaluation --------
    def evaluate(self, node):
        if node.left is None and node.right is None:
            return int(node.data)

        left = self.evaluate(node.left)
        right = self.evaluate(node.right)

        if node.data == "+":
            return left + right
        if node.data == "-":
            return left - right
        if node.data == "*":
            return left * right
        if node.data == "/":
            return left // right

    # -------- Print Operands --------
    def print_operands(self, node):
        if node:
            self.print_operands(node.left)
            if node.data.isdigit():
                print(node.data, end=" ")
            self.print_operands(node.right)


def main():
    et = ExpressionTree()
    et.build_tree()

    while True:
        print("\n--- EXPRESSION TREE MENU ---")
        print("1. Infix Traversal")
        print("2. Prefix Traversal")
        print("3. Postfix Traversal")
        print("4. Evaluate Expression")
        print("5. Print Operands")
        print("6. Exit")

        choice = input("Enter choice: ")

        if choice == "1":
            print("Infix Expression:")
            et.infix(et.root)
            print()

        elif choice == "2":
            print("Prefix Expression:")
            et.prefix(et.root)
            print()

        elif choice == "3":
            print("Postfix Expression:")
            et.postfix(et.root)
            print()

        elif choice == "4":
            print("Expression evaluates to:", et.evaluate(et.root))

        elif choice == "5":
            print("Operands:")
            et.print_operands(et.root)
            print()

        elif choice == "6":
            print("Program terminated.")
            break

        else:
            print("Invalid choice. Try again.")


if __name__ == "__main__":
    main()
