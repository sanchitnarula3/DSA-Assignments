#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int a = 0, b = n - 1;
    while (a <= b)
    {
        int mid = (a + b) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            a = mid + 1;
        else
            b = mid - 1;
    }
    return -1;
}

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50}, n = 5, key;
    cout << "Enter element: ";
    cin >> key;
    cout << "Linear Search: " << linearSearch(arr, n, key) << "\n";
    cout << "Binary Search: " << binarySearch(arr, n, key) << "\n";
    return 0;
}