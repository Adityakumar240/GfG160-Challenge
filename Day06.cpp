#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

    // Function to find the majority elements in the array - using Boyer-Moore Voting algorithm
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0;
        
        // Step 1 : Find the candidate
        for(int num : arr){
            if(candidate1 == num){
                count1++;
            }else if(candidate2 == num){
                count2++;
            }else if(count1 == 0){
                candidate1 = num, count1 = 1;
            }else if(count2 == 0){
                candidate2 = num, count2 = 1;
            }else{
                count1--; count2--;
            }
        }
        
        
        // Step 2 : Validate if the candidates is/are actually  majority (candidates validation)
        count1 = 0, count2 = 0;
        for(int num : arr){
            if(candidate1 == num) count1++;
            else if(candidate2 == num) count2++;
        }
        
        
        // Step 3 : Add the  valid candidate to the result
        vector<int>result;
        if(count1 > n/3){
            result.push_back(candidate1);
        }
        if(count2 > n/3){
            result.push_back(candidate2);
        }
        
        // step 4 : Sort the vector result before returning
        sort(result.begin(), result.end());
        
        
        return result;
    }
int main(){
    vector<int>arr = {2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6};
    vector<int>result = findMajority(arr);

    for(int num : result){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}