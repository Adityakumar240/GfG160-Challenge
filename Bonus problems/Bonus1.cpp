#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Split array in three equal sum subarrays

vector<int> findSplit(vector<int> &arr){
    int total = 0;

    // Calculate total sum
    for(int ele : arr){
        total += ele;
    }

    // If the total sum is not divisible by 3, return {-1, -1}
    if(total % 3 !=0){
        return {-1, -1};
    }

    int target = total / 3;  // Each segment's sum
    int currSum = 0;         // Running sum
    int firstSplit = -1;     // First split index
    int secondSplit = -1;    // Second split index

    for(int i = 0; i < arr.size(); i++){
        currSum += arr[i];

        // Mark the first split when the sum equals 'target'
        if(currSum == target && firstSplit == -1){
            firstSplit = i;
        }
        // Mark the second split when the sum equals '2 * target'
        else if(currSum == 2 * target && secondSplit == -1){
            secondSplit = i;
            break;      // No need to continue, as the rest of the array forms the third segment
        }
    }

    // If both splits are found and the third segment is non-empty
    if(firstSplit != -1 && secondSplit != -1 && secondSplit < arr.size() - 1){
        return {firstSplit, secondSplit};
    }

    // No valid split found
    return {-1,-1};
}

int main(){
    vector<int> arr ={1, 3, 4, 0, 4};
    vector<int> res = findSplit(arr);

    if(res[0] == -1){
        cout << "No valid split found" << endl;
    }else{
        cout << "Split incides: " << res[0] << " " << res[1] << endl;
    }

    return 0;
}