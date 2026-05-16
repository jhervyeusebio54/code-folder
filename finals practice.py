class prac:
    
    def Iissorted(self, arr, size):
        for i in range(size - 1):
            if arr[i] < arr[i + 1]:
                print("array is not in descensing order\n")
                return
        print("array is in descensing order\n")

    def Roccurrence(self, arr, size, t, c=0):
        if size == 0:
            print(f"How many times did {t} occur in the array? {c}\n")
            return
        if arr[0] == t:
            self.Roccurrence(arr[1:], size - 1, t, c + 1)
        else:
            self.Roccurrence(arr[1:], size - 1, t, c)

    def Ismallest(self, arr, size):
        smallest = arr[0]
        for i in range(1, size):
            if arr[i] < smallest:
                smallest = arr[i]
        print(f"The smallest num in the array is:(Iterative)? {smallest}\n")

    def Rsmallest(self, arr, size):
        if size == 1:
            return arr[0]
        small = self.Rsmallest(arr[1:], size - 1)
        if arr[0] < small:
            return arr[0]
        else:
            return small

    def Ipalindrome(self, arr, size):
        for i in range(size // 2):
            if arr[i] != arr[size - 1 - i]:
                return False
        return True

    def Rpalindrome(self, arr, s, e):
        if s >= e:
            return True
        if arr[s] != arr[e]:
            return False
        return self.Rpalindrome(arr, s + 1, e - 1)

    def Rpalindrome_wrapper(self, arr, size):
        return self.Rpalindrome(arr, 0, size - 1)

    def printarr(self, arr, size):
        for i in range(size):
            print(arr[i], end=" ")
        print()



if __name__ == "__main__":
    func = prac()   
    arr = [29, 16, 15, 9, 7, 6, 5]
    size = len(arr)
    arr1 = [2, 3, 4, 5, 6, 1, 1, 2, 1, 4]
    size1 = len(arr1)
    target = 1

    print("Determine if the given array is sorted in descending order.")
    print("The initial array is: ", end="")
    func.printarr(arr, size)
    func.Iissorted(arr, size)

    print("Count the occurrence of a number in an array")
    print("The initial array is: ", end="")
    func.printarr(arr1, size1)
    func.Roccurrence(arr1, size1, target)

    print("Find the smallest element in an array(iterative)")
    print("The initial array is: ", end="")
    func.printarr(arr, size)
    func.Ismallest(arr, size)

    print("Find the smallest element in an array(recursive)")
    print("The initial array is: ", end="")
    func.printarr(arr, size)
    print("The smallest num in the array is:(recursive)?", func.Rsmallest(arr, size), "\n")

    print("Check if the array is PALINDROME(iterative)")
    print("The initial array is: ", end="")
    func.printarr(arr1, size1)
    if func.Ipalindrome(arr1, size1):
        print("Array is a palindrome (iterative)\n")
    else:
        print("Array is not a palindrome (iterative)\n")

    print("Check if the array is PALINDROME(recursive)")
    print("The initial array is: ", end="")
    func.printarr(arr1, size1)
    if func.Rpalindrome_wrapper(arr1, size1):
        print("Array is a palindrome (recursive)\n")
    else:
        print("Array is not a palindrome (recursive)\n")
