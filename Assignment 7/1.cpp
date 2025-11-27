#include <iostream>

using namespace std;

int main() {
    int n = 5;
    
    int arr[]={3,5,8,1,2};
    for (int i = 0; i < n-1; i++)
    {
        int MinIndex = i;

        for (int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[MinIndex])
            MinIndex = j;
        }

        
        
        swap(arr[MinIndex],arr[i]);
        
        
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    
    return 0;
}