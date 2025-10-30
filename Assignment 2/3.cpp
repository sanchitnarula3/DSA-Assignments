#include <iostream>
using namespace std;

int linearMissing(int arr[], int n)
{
    for (int i = 1; i <= n + 1; i++)
    {
        bool found = false;
        for (int j = 0; j < n; j++)
            if (arr[j] == i)
                found = true;
        if (!found)
            return i;
    }
    return -1;
}

int binaryMissing(int arr[], int n)
{
    int a = 0, b = n - 1;
    while (a <= b)
    {
        int mid = (a + b) / 2;
        if (arr[mid] != mid + 1)
            b = mid - 1;
        else
            a = mid + 1;
    }
    return a + 1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 6}, n = 5;
    cout << "Linear: " << linearMissing(arr, n) << "\n";
    cout << "Binary: " << binaryMissing(arr, n) << "\n";
    return 0;
}