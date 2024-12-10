#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Brute force approach - Time complexity: O(n square)
vector<vector<int>> bruteForceMerge(vector<vector<int>> &intervals, vector<int> newInterval){
    // Step 1: Insert the new interval
    intervals.push_back(newInterval);

    // Step 2: Merge intervals using brute force
    bool merged = true;
    while(merged) {
        merged = false;
        for(int i = 0; i < intervals.size(); i++){
            for(int j = i + 1; j < intervals.size(); j++){
                // Check if intervals[i] and intervals[j] overlap
                if(intervals[i][1] >= intervals[j][0] && intervals[i][0] < intervals[j][1]){
                    // Merge intervals[i] and intervals[j]
                    intervals[i][0] = min(intervals[i][0], intervals[j][0]);
                    intervals[i][1] = max(intervals[i][1], intervals[j][1]);
                    intervals.erase(intervals.begin() + j); // Remove the merged interval
                    merged = true;
                    break;
                }
            }
            if(merged) break;
        }
    }
    return intervals;
}

// Efficient approach - Time complexity: O(nlogn)
vector<vector<int>> insertAndMergeIntervals(vector<vector<int>> &intervals, vector<int> newInterval){
    // Step 1: Insert the new interval
    intervals.push_back(newInterval);

    // Step 2: Sort the intervals based on the start time
    sort(intervals.begin(), intervals.end());

    // Step 3: Merge intervals
    vector<vector<int>> result;
    for(const auto &interval : intervals){
        if(result.empty() || result.back()[1] < interval[0]){
            result.push_back(interval);
        }else{
            result.back()[1] = max(result.back()[1], interval[1]);
        }
    }
    return result;
}

// Optimized approach - Time complexity: O(n)
vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval) {
    vector<vector<int>> result;
    int i = 0, n = intervals.size();
    
    // Step 1: Add all intervals that come before the new interval
    while(i < n && intervals[i][1] < newInterval[0]){
        result.push_back(intervals[i]);
        i++;
    }
    
    // Step 2: Merge all the overlapping intervals with the new interval
    while(i < n && intervals[i][0] <= newInterval[1]){
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.push_back(newInterval);
    
    // Step 3: Add all intervals that come after the new interval
    while(i < n){
        result.push_back(intervals[i]);
        i++;
    }
    return result;
}


int main(){
     // Input intervals
    vector<vector<int>> intervals1 = {{1, 3}, {6, 9}};
    vector<int> newInterval1 = {2, 5};

    vector<vector<int>> intervals2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval2 = {4, 8};

    // Test Brute Force Approach
    vector<vector<int>> bruteIntervals1 = intervals1; // Make a copy
    vector<vector<int>> resultBrute = bruteForceMerge(bruteIntervals1, newInterval1);
    cout << "Brute Force Result 1: ";
    for (const auto &interval : resultBrute) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    vector<vector<int>> bruteIntervals2 = intervals2; // Make a copy
    vector<vector<int>> resultBrute2 = bruteForceMerge(bruteIntervals2, newInterval2);
    cout << "Brute Force Result 2: ";
    for (const auto &interval : resultBrute2) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    // Test Efficient Approach
    vector<vector<int>> efficientIntervals1 = intervals1; // Make a copy
    vector<vector<int>> resultEfficient = insertAndMergeIntervals(efficientIntervals1, newInterval1);
    cout << "Efficient Result 1: ";
    for (const auto &interval : resultEfficient) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    vector<vector<int>> efficientIntervals2 = intervals2; // Make a copy
    vector<vector<int>> resultEfficient2 = insertAndMergeIntervals(efficientIntervals2, newInterval2);
    cout << "Efficient Result 2: ";
    for (const auto &interval : resultEfficient2) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    // Test Optimized Approach
    vector<vector<int>> optimizedIntervals1 = intervals1; // Make a copy
    vector<vector<int>> resultOptimized = insertInterval(optimizedIntervals1, newInterval1);
    cout << "Optimized Result 1: ";
    for (const auto &interval : resultOptimized) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    vector<vector<int>> optimizedIntervals2 = intervals2; // Make a copy
    vector<vector<int>> resultOptimized2 = insertInterval(optimizedIntervals2, newInterval2);
    cout << "Optimized Result 2: ";
    for (const auto &interval : resultOptimized2) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}