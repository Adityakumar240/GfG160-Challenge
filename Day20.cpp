#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if two strings are rotations of each other or not.
// There are 3 approaches to solve this problem
// Brute force approach - use the rotate function to check after each iteration. Time complexity: O(n square)
// Efficient approach - Concatenate and check substring - this approach works well for this type of problem
// Optimized approach - Using KMP algorithm



// Better approach
bool areRotations(string &s1, string &s2) {
    // Concatenate and check substring
    if(s1.length() != s2.length()){
        return false;
    }
    // Concatenate the string with itself
    string temp = s1 + s1;
    return temp.find(s2) != string::npos; // Check if s2 a substring
}


int main(){
    string s1 = "ABCD", s2 = "CDAB";
    cout << (areRotations(s1,s2) ? "Yes" : "No") << endl;

    return 0;
}