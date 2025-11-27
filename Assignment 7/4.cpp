#include <iostream>
using namespace std;

void mergeArrays(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int a[n1], b[n2];

    
    for(int i = 0; i < n1; i++)
        a[i] = arr[left + i];
    for(int i = 0; i < n2; i++)
        b[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    
    while(i < n1 && j < n2) {
        if(a[i] < b[j])
            arr[k++] = a[i++];
        else
            arr[k++] = b[j++];
    }

    
    while(i < n1)
        arr[k++] = a[i++];
    while(j < n2)
        arr[k++] = b[j++];
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        mergeArrays(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {7, 4, 1, 5};
    int n = 4;

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
