#include <iostream>
using namespace std;

// Approach 1
void leftRotateArray(int arr[], int n, int d) {
        d = d % n;
        int temp[d] = {0};
        for(int i = 0; i < d; i++){
            temp[i] = arr[i];
        }
        
        for(int i = d; i < n; i++){
            arr[i-d] = arr[i];
        }
        for(int i = 0; i < d; i++){
            arr[n-d+i] = temp[i];
        }
}

// Approach 2
void reverse(int arr[], int low, int high){
    while(low < high){
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}
void rotateArr(int arr[], int n, int d) {
    d = d % n;
    reverse(arr, 0, d-1);
    reverse(arr,d, n-1);
    reverse(arr,0, n-1);
        
}


int main(){
    int arr[] = {1,2,3,4,5};

    // leftRotateArray(arr, 5, 2);
    rotateArr(arr,5,2);
    
    cout << " Array after rotation: ";
    for(int num : arr){
        cout << num << " ";
    }
}