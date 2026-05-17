import os

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None
        self.counter = 1   # used for numerized output

    def reset_counter(self):
        self.counter = 1

    def insert(self, value):
        new_node = Node(value)
        if not self.root:
            self.root = new_node
            return
        queue = [self.root]
        while queue:
            current = queue.pop(0)
            if not current.left:
                current.left = new_node
                return
            else:
                queue.append(current.left)
            if not current.right:
                current.right = new_node
                return
            else:
                queue.append(current.right)

    def inorder(self, node):
        if node:
            self.inorder(node.left)
            print(f"{self.counter}. {node.data}", end="  ")
            self.counter += 1
            self.inorder(node.right)

    def preorder(self, node):
        if node:
            print(f"{self.counter}. {node.data}", end="  ")
            self.counter += 1
            self.preorder(node.left)
            self.preorder(node.right)

    def postorder(self, node):
        if node:
            self.postorder(node.left)
            self.postorder(node.right)
            print(f"{self.counter}. {node.data}", end="  ")
            self.counter += 1

    def level_order(self, node):
        if not node:
            return
        queue = [node]
        while queue:
            current = queue.pop(0)
            print(f"{self.counter}. {current.data}", end="  ")
            self.counter += 1
            if current.left:
                queue.append(current.left)
            if current.right:
                queue.append(current.right)

    def print_leaves(self, node):
        if node:
            if not node.left and not node.right:
                print(f"{self.counter}. {node.data}", end="  ")
                self.counter += 1
            self.print_leaves(node.left)
            self.print_leaves(node.right)

def clear_screen():
    os.system('cls' if os.name == 'nt' else 'clear')

def main():
    tree = BinaryTree()

    while True:
        clear_screen()
        print("\nMenu")
        print("1) Insert Integer")
        print("2) In Order (Numerized)")
        print("3) Pre Order (Numerized)")
        print("4) Post Order (Numerized)")
        print("5) Level Order (Numerized)")
        print("6) Print Leaves (Numerized)")
        print("7) Exit")

        choice = input("Enter your choice: ")

        if choice == '1':
            value = int(input("Enter integer to insert: "))
            tree.insert(value)

        elif choice == '2':
            tree.reset_counter()
            print("Inorder Traversal:")
            tree.inorder(tree.root)
            input("\nPress Enter to continue...")

        elif choice == '3':
            tree.reset_counter()
            print("Preorder Traversal:")
            tree.preorder(tree.root)
            input("\nPress Enter to continue...")

        elif choice == '4':
            tree.reset_counter()
            print("Postorder Traversal:")
            tree.postorder(tree.root)
            input("\nPress Enter to continue...")

        elif choice == '5':
            tree.reset_counter()
            print("Level Order Traversal:")
            tree.level_order(tree.root)
            input("\nPress Enter to continue...")

        elif choice == '6':
            tree.reset_counter()
            print("Leaf Nodes:")
            tree.print_leaves(tree.root)
            input("\nPress Enter to continue...")

        elif choice == '7':
            print("Exiting...")
            break

        else:
            print("Invalid choice.")
            input("Press Enter to continue...")

if __name__ == "__main__":
    main()
1