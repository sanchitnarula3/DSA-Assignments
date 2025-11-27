#include<iostream>
using namespace std;

void display(int arr[], int size){
    for(int i=1; i<=size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapify(int i, int arr[], int size) {
    while (true) {
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left > size) break;

        int smallerChild = left;
        if (right <= size && arr[right] < arr[left])
            smallerChild = right;

        if (arr[i] <= arr[smallerChild])
            break;

        swap(arr[i], arr[smallerChild]);
        i = smallerChild;
    }
}

int main() {
    int arr[50], size;
    cout << "enter number of elements" << endl;
    cin >> size;

    cout << "enter the array" << endl;
    for (int i = 1; i <= size; i++) {
        cin >> arr[i];
    }

    // STEP 1: Build min-heap
    for (int i = size/2; i >= 1; i--) {
        heapify(i, arr, size);
    }

    

    // STEP 2: Heap sort
    int heapsize=size;
    while (heapsize > 1) {
        swap(arr[1], arr[heapsize]);  
        heapsize--;
        heapify(1, arr, heapsize);    
    }

    cout << "Sorted array: ";
    display(arr, size);

    return 0;
}