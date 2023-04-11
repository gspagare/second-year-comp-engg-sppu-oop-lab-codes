//Name - Venkatesh Shamsundar Soni
//Class - SE Computer B
//Roll - 20CO136

/*
Problem Statement - Write a function template selection sort. Write a program that inputs,
                    sorts and outputs an integer array and a float array.
*/


#include<iostream>
using namespace std;

#define size 10
int n;
template<class T>
void selection_sort(T a[size]) {
    int i, j, k, temp;
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if (a[j]<a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        cout << "\nAfter pass" << i+1 << ":";
        for(k = 0; k < n; k++) {
            cout << a[k] << " ";
        }
    }
    for ( i = 0; i < n; i++)
    {
        cout <<"\nAfter sorting is: "<< a[i];
    }
}

int main() {
    int i;
    int a[size];
    float b[size];
    cout << "\nHow many integers: ";
    cin >> n;
    cout << "\nEnter the values: \n";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    selection_sort(a);
    cout << "\nHow many floats: ";
    cin >> n;
    cout << "\nEnter the values: \n";
    for ( i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    selection_sort(b);
    cout << "\n\n";
    return 0;
}