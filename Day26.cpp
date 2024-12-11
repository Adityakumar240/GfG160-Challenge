#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate the minimum number of intervals to remove to make all intervals non-overlapping
int removeOverlapIntervals(vector<vector<int>>& intervals){
    int n = intervals.size();
    
    // Sort the intervals based on the starting points
    sort(intervals.begin(), intervals.end());

    int count = 0;
    int end = intervals[0][1];  // Initialize the end point of the first interval
    for(int i = 1; i < n; i++){

        // If the current starting point is less than the previous interval's ending point then there is an overlap
        if( end > intervals[i][0]){
            count++;
            end = min(end, intervals[i][0]);    // Update the current interval's start to the minimum end point to reduce further overlaps
        }else{
            // No overlap, update the end to current interval's end
            end = intervals[i][0];
        }
    }
    return count;
}

int main(){
    vector<vector<int>> intervals = {{1, 3}, {2, 4}, {3, 5}, {6, 8}};
    vector<vector<int>> intervals2 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};

    cout << "Minimum intervals to remove in interval 1: " << removeOverlapIntervals(intervals) << endl;
    cout << "Minimum intervals to remove in interval 2: " << removeOverlapIntervals(intervals2) << endl;


    return 0;
}