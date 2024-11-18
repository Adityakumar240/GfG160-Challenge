#include <iostream>
using namespace std;

void reverse(int arr[], int n){
    int low = 0, high = n-1;
    while(low < high){
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}
int main(){
    int arr[] = {1,2,3,4,5};
    reverse(arr, 5);
    cout << "After reversing array: " << endl;
    for(int num : arr){
        cout << num << " ";
    }
}