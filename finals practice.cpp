/*Write a  program  using classes in 1.) C++ and 2.) Python with the following methods:
iterative method to determine if the given array is sorted in descending order.
recursive method to count the occurrence of a number in an array
iterative method to find the smallest element in an array
recursive method to find the smallest element in an array
iterative method to check if the array is PALINDROME
recursive method to check if the array is PALINDROME*/


//Eusebio, John Jhervy G.
#include<iostream>
using namespace std;

class prac{
public:

    void Iissorted(int arr[],int size);
    void Roccurrence(int arr[],int size, int t, int c=0);
    int Ismallest(int arr[],int size);
    int Rsmallest(int arr[],int size);
    bool Ipalindrome(int arr[],int size);
    bool Rpalindrome(int arr[],int size);
    bool Rpalindrome(int arr[],int s, int e);
    void printarr(int arr[],int size);

};


int main(){
prac func;
int arr[]={29,16,15,9,7,6,5};
int size= sizeof(arr)/sizeof(arr[0]);

int arr1[]={2,3,4,5,6,1,1,2,1,4};
int size1= sizeof(arr)/sizeof(arr[0]);
int target= 1;

cout<<"Determine if the given array is sorted in descending order.\n";
cout<<"The initial array is: ";
func.printarr(arr,size);
func.Iissorted(arr,size);

cout<<"Count the occurrence of a number in an array\n";
cout<<"The initial array is: ";
func.printarr(arr1,size1);
func.Roccurrence(arr1,size1,target);

cout<<"Find the smallest element in an array(iterative)\n";
cout<<"The initial array is: ";
func.printarr(arr,size);
func.Ismallest(arr,size);

cout<<"Find the smallest element in an array(recursive)\n";
cout<<"The initial array is: ";
func.printarr(arr,size);
cout<<"The smallest num in the array is:(recursive)? ";
cout << func.Rsmallest(arr,size);
cout<<"\n\n";

cout<<"Check if the array is PALINDROME(iterative)\n";
cout<<"The initial array is: ";
func.printarr(arr1,size1);
if(func.Ipalindrome(arr1,size1)) {
        cout << "Array is a palindrome (iterative)\n\n";
    } else {
        cout << "Array is not a palindrome (iterative)\n\n";
    }

cout<<"Check if the array is PALINDROME(recursive)\n";
cout<<"The initial array is: ";
func.printarr(arr1,size1);
if(func.Rpalindrome(arr1,size1)) {
        cout << "Array is a palindrome (recursive)\n\n";
    } else {
        cout << "Array is not a palindrome (recursive)\n\n";
    }

}

void prac::Iissorted(int arr[], int size){
for (int i = 0; i < size - 1; i++) {
            if (arr[i] < arr[i + 1]) {
               cout << "array is not in descensing order\n\n";
                return;
            }
        }
       cout << "array is in descensing order\n\n";
    }

void prac::Roccurrence(int arr[],int size, int t, int c){
   if (size == 0) {
        cout << "How many times did " << t << " occur in the array? " << c << "\n\n";
        return;
    }
    if (arr[0] == t) {
        Roccurrence(arr + 1, size - 1, t, c + 1);
    } else {
        Roccurrence(arr + 1, size - 1, t, c);
    }
}
int prac::Ismallest(int arr[],int size){
 int smallest = arr[0];
        for (int i = 1; i < size; ++i) {
            if (arr[i] < smallest) {
                smallest = arr[i];
            }
        }
        cout << "The smallest num in the array is:(Iterative)? " << smallest<<"\n\n";
    }




int prac::Rsmallest(int arr[],int size){
if (size == 1) {
        return arr[0];
    }
    int small = Rsmallest(arr + 1, size - 1);

    if (arr[0] < small) {
        return arr[0];
    } else {
    return small;
    }
}

bool prac::Ipalindrome(int arr[],int size){
    for(int i = 0; i < size/2; i++) {
        if(arr[i] != arr[size-1-i]) {
            return false;
        }
    }
    return true;
}

bool prac::Rpalindrome(int arr[], int s, int e){
    if(s >= e) {
        return true;
    }
    if(arr[s] != arr[e]) {
        return false;
    }
    return Rpalindrome(arr, s + 1, e - 1);
}
bool prac::Rpalindrome(int arr[],int size){
    return Rpalindrome(arr, 0, size - 1);
}

void prac::printarr(int arr[],int size){
for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

    }
