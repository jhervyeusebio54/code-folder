class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BinaryTree:
    def __init__(self):
        self.root = None

    # Traversals
    def preorder(self, node):
        if node is None:
            return
        print(node.data, end=" ")
        self.preorder(node.left)
        self.preorder(node.right)

    def inorder(self, node):
        if node is None:
            return
        self.inorder(node.left)
        print(node.data, end=" ")
        self.inorder(node.right)

    def postorder(self, node):
        if node is None:
            return
        self.postorder(node.left)
        self.postorder(node.right)
        print(node.data, end=" ")

    # Evaluation (assumes numeric operands only)
    def evaluate(self, node):
        if node is None:
            return 0

        # If leaf node, return integer value
        if node.left is None and node.right is None:
            return int(node.data)

        left_val = self.evaluate(node.left)
        right_val = self.evaluate(node.right)

        if node.data == '+':
            return left_val + right_val
        elif node.data == '-':
            return left_val - right_val
        elif node.data == '*':
            return left_val * right_val
        elif node.data == '/':
            return left_val / right_val

        return 0

    # Print operands (leaf nodes)
    def print_operands(self, node):
        if node is None:
            return
        if node.left is None and node.right is None:
            print(node.data, end=" ")
        self.print_operands(node.left)
        self.print_operands(node.right)


def build_sample_tree():
    """
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
    """
    root = Node('1')
    root.left = Node('2')
    root.right = Node('3')
    root.left.left = Node('4')
    root.left.right = Node('5')
    root.right.left = Node('6')
    root.right.right = Node('7')
    return root


def menu():
    print("\nMENU")
    print("1. Infix (Inorder)")
    print("2. Prefix (Preorder)")
    print("3. Postfix (Postorder)")
    print("4. Evaluation")
    print("5. Print Operands")
    print("6. Exit")


def main():
    tree = BinaryTree()
    tree.root = build_sample_tree()

    while True:
        menu()
        choice = input("Enter choice: ")

        if choice == '1':
            print("Infix Expression:")
            tree.inorder(tree.root)
            print()

        elif choice == '2':
            print("Prefix Expression:")
            tree.preorder(tree.root)
            print()

        elif choice == '3':
            print("Postfix Expression:")
            tree.postorder(tree.root)
            print()

        elif choice == '4':
            print("Evaluation Result:")
            print(tree.evaluate(tree.root))

        elif choice == '5':
            print("Operands:")
            tree.print_operands(tree.root)
            print()

        elif choice == '6':
            print("Exiting program.")
            break

        else:
            print("Invalid choice. Try again.")


if __name__ == "__main__":
    main()
