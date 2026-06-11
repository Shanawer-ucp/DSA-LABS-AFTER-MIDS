// Task 3 - Recursive Maximum Element in Array
// DSA Lab 10 - Recursion

#include <iostream>
using namespace std;

// Base case: only one element left, that is the max
// Recursive case: compare first element with max of rest
int findMax(int arr[], int size) {
    if (size == 1)
        return arr[0];

    int maxOfRest = findMax(arr + 1, size - 1);
    return (arr[0] > maxOfRest) ? arr[0] : maxOfRest;
}

int main() {
    int arr[] = {12, 5, 18, 7, 3};
    int size = 5;

    cout << "Array elements: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Maximum element: " << findMax(arr, size) << endl;

    return 0;
}
