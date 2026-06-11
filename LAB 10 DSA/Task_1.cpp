// Task 1 - Recursive Sum of Array Elements
// DSA Lab 10 - Recursion

#include <iostream>
using namespace std;

// Base case: size 0 means no elements left, return 0
// Recursive case: add first element + sum of remaining array
int recursiveSum(int arr[], int size) {
    if (size == 0)
        return 0;
    return arr[0] + recursiveSum(arr + 1, size - 1);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    cout << "Array elements: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    int total = recursiveSum(arr, size);
    cout << "Sum of array elements: " << total << endl;

    return 0;
}
