// Task 7 (Bonus) - Magic Number
// DSA Lab 10 - Recursion
//
// Magic number = largest number in array that can be formed
// as sum of any subset of the remaining numbers.
// All logic is recursive (no loops).

#include <iostream>
using namespace std;

// ─── FIND MAX AMONG UNUSED ───────────────────────────────────────────────────
void findMaxAmongUnused(int arr[], bool used[], int size, int index,
                        int& maxVal, int& maxIndex) {
    if (index == size)
        return;

    if (!used[index] && arr[index] > maxVal) {
        maxVal = arr[index];
        maxIndex = index;
    }
    findMaxAmongUnused(arr, used, size, index + 1, maxVal, maxIndex);
}

// ─── SUBSET SUM (skipping candidate and used elements) ───────────────────────
bool subsetSumWithUsed(int arr[], bool used[], int size, int index,
                       int skipIndex, int target) {
    if (target == 0)
        return true;
    if (index >= size || target < 0)
        return false;

    // Skip the candidate itself and already-excluded elements
    if (index == skipIndex || used[index])
        return subsetSumWithUsed(arr, used, size, index + 1, skipIndex, target);

    // Include or exclude arr[index]
    return subsetSumWithUsed(arr, used, size, index + 1, skipIndex, target - arr[index]) ||
           subsetSumWithUsed(arr, used, size, index + 1, skipIndex, target);
}

// ─── MAGIC NUMBER FINDER ─────────────────────────────────────────────────────
int findMagicNumber(int arr[], bool used[], int size, int remaining) {
    if (remaining == 0)
        return -1;

    // Find the largest unused element
    int maxVal = -1, maxIndex = -1;
    findMaxAmongUnused(arr, used, size, 0, maxVal, maxIndex);

    if (maxIndex == -1)
        return -1;

    cout << "Checking if " << maxVal << " is a magic number..." << endl;

    // Check if maxVal can be subset-summed from remaining unused elements
    if (subsetSumWithUsed(arr, used, size, 0, maxIndex, maxVal)) {
        cout << maxVal << " CAN be formed as a subset sum!" << endl;
        return maxVal;
    }

    // Remove this candidate and try the next largest
    cout << maxVal << " cannot be formed. Removing and trying next..." << endl;
    used[maxIndex] = true;
    return findMagicNumber(arr, used, size, remaining - 1);
}

// ─── MAIN ────────────────────────────────────────────────────────────────────
int main() {
    // Test 1: Expected magic number = 13 (5 + 8 = 13)
    int arr1[] = {2, 3, 5, 8, 13};
    int size1 = 5;
    bool used1[5] = {false};

    cout << "=== Test 1 ===" << endl;
    cout << "Input: [2, 3, 5, 8, 13]" << endl << endl;
    int magic1 = findMagicNumber(arr1, used1, size1, size1);
    cout << "\nMagic Number: " << (magic1 != -1 ? magic1 : -1) << endl;

    // Test 2: 7 = 3 + 4, but 4 not in array — try 4 (not there), 2+1=3 no... -1
    cout << "\n=== Test 2 ===" << endl;
    int arr2[] = {1, 2, 3, 10};
    int size2 = 4;
    bool used2[4] = {false};

    cout << "Input: [1, 2, 3, 10]" << endl << endl;
    int magic2 = findMagicNumber(arr2, used2, size2, size2);
    cout << "\nMagic Number: " << (magic2 != -1 ? magic2 : -1) << endl;

    return 0;
}
