

// Eusebio, JOhn Jhervy G. Bsit-1B


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int iPalindrome(int num);
int reverseNumber(int num, int reversed);
int rPalindrome(int num);
void idectoBinary(int n);
void rdectoBinary(int n);
int iSearch(int arr[], int size, int loc);
int rSearch(int arr[], int size, int loc, int index);
int ifindlargest(int arr[], int size);
int rfindlargest(int arr[], int size, int index);
void printArr(int arr[], int size, const char* i);
int main() {

    int num = 12321;
    int num1 = 1231;
     printf("example num %d\n",num);
    int iPalindromeres= iPalindrome(num);
    printf("Is %d a palindrome? (Iterative): ", num, iPalindrome(num));
     if (iPalindromeres == 1) {printf("yes\n");}
    else {printf("no\n");}
   int rPalindromeres= rPalindrome(num);
    printf("Is %d a palindrome? (Recursive): ", num, rPalindrome(num));
    if (rPalindromeres == 1) {printf("yes\n\n");}
    else {printf("no\n\n");}
    
    printf("2nd example num %d\n",num1);
    int iPalindromeres1= iPalindrome(num1);
    printf("Is %d a palindrome? (Iterative): ", num1, iPalindrome(num1));

     if (iPalindromeres1 == 1) {printf("yes\n");}
    else {printf("no\n");}
   int rPalindromeres1= rPalindrome(num1);
    printf("Is %d a palindrome? (Recursive): ", num1, rPalindrome(num1));
    if (rPalindromeres1 == 1) {printf("yes\n\n");}
    else {printf("no\n\n");}
    
    int decimal = 42;
    printf("example num %d\n",decimal);
    printf("Binary representation of %d (Iterative): ", decimal);
    idectoBinary(decimal);
    printf("\n");

    printf("Binary representation of %d (Recursive): ", decimal);
    rdectoBinary(decimal);
    printf("\n\n");


    int arr[] = {5, 2, 8, 1, 9, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int loc = 7;
    int loc1 = 8;
    printf("Array contents: ");
    printArr(arr, size, "%d ");

    int Iresult= iSearch(arr, size, loc);
    printf("Is %d present in the array? (Iterative): ", loc, Iresult);
    if (Iresult == 1) {printf("yes\n");}
    else {printf("no\n");}
    int Ires1= iSearch(arr, size, loc1);
    printf("Is %d present in the array? (Iterative): ", loc1, Iresult);
    if (Ires1== 1) {printf("yes\n");}
    else {printf("no\n");}

    int Rresult = rSearch(arr, size, loc, 0);
    printf("Is %d present in the array? (Recursive): ", loc, Rresult);
    if (Rresult == 1) { printf("yes\n"); }
    else { printf("no\n"); }
     int Rres1 = rSearch(arr, size, loc1, 0);
    printf("Is %d present in the array? (Recursive): ", loc1, Rresult);
    if (Rres1 == 1) { printf("yes\n\n"); }
    else { printf("no\n\n"); }


    printf("LArgest element in the array (Iterative): %d\n", ifindlargest(arr, size));
    printf("Largest element in the array (Recursive): %d\n\n", rfindlargest(arr, size, 0));

    return 0;
}



int iPalindrome(int num) {
    if (num < 0) return 0;
    int temp = num;
    int digits = 0;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    temp = num;
    int reversed = 0;
    while (temp > 0) {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }

    return (reversed == num);
}

int reverseNumber(int num, int reversed) {
    if (num == 0) return reversed;
    return reverseNumber(num / 10, reversed * 10 + num % 10);
}

int rPalindrome(int num) {
    if (num < 0) return 0;

    int reversed = reverseNumber(num, 0);
    return (reversed == num);
}




void idectoBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    int temp = n;
    int bits = 0;
    while (temp > 0) {
        bits++;
        temp >>= 1;
    }
    int *binary = (int*)malloc(bits * sizeof(int));
    temp = n;
    int i = 0;
    while (temp > 0) {
        binary[i++] = temp % 2;
        temp /= 2;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    free(binary);
}


void rdectoBinary(int n) {
    if (n == 0) return;

    rdectoBinary(n / 2);
    printf("%d", n % 2);
}


int iSearch(int arr[], int size, int loc) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == loc) {
            return 1;
        }
    }
    return 0;
}


int rSearch(int arr[], int size, int loc, int index) {
    if (index >= size) {
        return 0;
    }
    if (arr[index] == loc) {
        return 1;
    }

    return rSearch(arr, size, loc, index + 1);
}

int ifindlargest(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty\n");
        return -1;
    }

    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}


int rfindlargest(int arr[], int size, int index) {

    if (index == size - 1) {
        return arr[index];
    }
    int MAX = rfindlargest(arr, size, index + 1);
    return (arr[index] > MAX) ? arr[index] : MAX;
}

void printArr(int arr[], int size, const char* format) {
    for (int i = 0; i < size; i++) {
        printf(format, arr[i]);
    }
    printf("\n");
}
