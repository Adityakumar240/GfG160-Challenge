#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals){
    // Step 1: Sort intervals by the start time
    sort(intervals.begin(), intervals.end());

    // Step 2: Merge overlapping intervals
    vector<vector<int>> result;
    for(const auto &interval : intervals){
        // If result is empty or no overlap, add the interval
        if(result.empty() || result.back()[1] < interval[0]){
            result.push_back(interval);
        }else{
            // Merge the current interval with the last interval in the result
            result.back()[1] = max(result.back()[1], interval[1]);
        }
    }

    return result;
}



// Excepted approach (greedy approach) - O(n)
vector<vector<int>> mergeOverlap(vector<vector<int>> &arr){
    int n = arr.size();

    // Sort the intervals based on the start time
    sort(arr.begin(), arr.end());

    vector<vector<int>> res;
    // Iterate through the sorted intervals
    for(int i = 0; i < n; i++){
        if(res.empty() || res.back()[1] < arr[i][0]){
            // If the result is empty or no overlap, simply add the current interval
            res.push_back(arr[i]);
        }else{
            // Merge the current interval with the last one
            res.back()[1] = max(res.back()[1], arr[i][1]);
        }
    }
    return res;
}

// Excepted approach 3 : (in place merged intervals)
vector<vector<int>> mergeOverlap2(vector<vector<int>> &intervals){
    if(intervals.empty()) return {};

    // Step 1: Sort intervals by the start time
    sort(intervals.begin(), intervals.end());

    // Step: Merge intervals in-place
    int index = 0;  // Points to the last merged interval

    for(int i = 0; i < intervals.size(); i++){
        // If the current interval overlaps with the last merged interval
        if(intervals[index][1] >= intervals[i][0]){
            intervals[index][1] = max(intervals[index][1], intervals[i][1]);
        }else{
            // Move to the next interval
            index++;
            intervals[index] = intervals[i];
        }
    }
    // Resize the intervals to keep only merged intervals
    intervals.resize(index + 1);

    return intervals;
}

int main(){
    // Test case 1 for mergeIntervals (Brute force)
    vector<vector<int>> intervals1 = {{1, 3}, {2, 4}, {6, 8}, {9, 10}};
    vector<vector<int>> result1 = mergeIntervals(intervals1);

    cout << "Interval 1 (brute force): ";
    for(const auto &interval : result1){
        cout << "[" << interval[0] << ", " << interval[1] << "]";
    }
    cout << endl;
    
    // Test case 2 for mergeOverlap (Greedy)
    vector<vector<int>> intervals2 = {{7, 8}, {1, 5}, {2, 4}, {4, 6}};
    vector<vector<int>> result2 = mergeOverlap(intervals2);

    cout << "Interval 2 (Optimized) : ";
    for(const auto &interval : result2){
        cout << "[" << interval[0] << ", " << interval[1] << "]";
    }
    cout << endl;

     // Test case 3 for mergeOverlap (In-place merged intervals)
    vector<vector<int>> intervals3 = {{7, 8}, {1, 5}, {2, 4}, {4, 6}};
    vector<vector<int>> result3 = mergeOverlap2(intervals3);

    cout << "Interval 3 (Optimized) : ";
    for(const auto &interval : result3){
        cout << "[" << interval[0] << ", " << interval[1] << "]";
    }
    cout << endl;


    return 0;
}