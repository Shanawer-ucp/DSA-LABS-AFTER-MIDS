#include <iostream>
using namespace std;

int findLargest(int arr[], int size, int index, int max)
{
    if (index == size)
    {
        return max;
    }

    if (arr[index] > max)
    {
        max = arr[index];
    }

    return findLargest(arr, size, index + 1, max);
}

bool subsetSum(int arr[], int size, int index, int target)
{
    if (target == 0)
    {
        return true;
    }

    if (index == size || target < 0)
    {
        return false;
    }

    return subsetSum(arr, size, index + 1, target - arr[index]) ||
        subsetSum(arr, size, index + 1, target);
}

void removeElement(int arr[], int& size, int value, int index)
{
    if (index == size)
    {
        return;
    }

    if (arr[index] == value)
    {
        arr[index] = arr[size - 1];
        size--;
        return;
    }

    removeElement(arr, size, value, index + 1);
}

int magicNumber(int arr[], int size)
{
    if (size == 0)
    {
        return -1;
    }

    int largest = findLargest(arr, size, 0, arr[0]);

    int temp[100];

    for (int i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }

    int newSize = size;

    removeElement(temp, newSize, largest, 0);

    if (subsetSum(temp, newSize, 0, largest))
    {
        return largest;
    }

    removeElement(arr, size, largest, 0);

    return magicNumber(arr, size);
}

int main()
{
    int arr[] = { 2, 3, 5, 8, 13 };
    int size = 5;

    int result = magicNumber(arr, size);

    cout << "Magic Number: " << result;

    return 0;
}