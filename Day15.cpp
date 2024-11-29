#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string addBinary(string& s1, string& s2){
    int i = s1.size() - 1;  // Pointer for s1
    int j = s2.size() -1;   // Pointer for s2
    int carry = 0;          // Initialize carry
    string result = "";     // To store the result

    while(i >= 0 || j >=0 || carry){
        int bit1 = (i >= 0) ? s1[i] - '0' : 0;  // Get bit from s1 or 0 if out of bounds
        int bit2 = (j >= 0) ? s2[j] - '0' : 0;  // Get bit from s2 or 0 if out of bounds

        int sum = bit1 + bit2 + carry;          // Sum the  bits and carry
        result += (sum % 2) + '0';              // Append the current bit to thee result
        carry = sum / 2;                        // Update carry

        i--;    // Move to the next bit in s1
        j--;    // Move to the next bit in s2
    }

    reverse(result.begin(), result.end());      // Reverse the result to correct the order

    // Removing leading zeros if any
    size_t start = result.find_first_not_of('0');
    if(start != string::npos){
        return result.substr(start);
    }
    // If all zeros, return "0"
    return "0";
}

int main(){
    string s1 = "1101", s2 = "111";
    cout << addBinary(s1, s2) << endl;

    s1 = "00100", s2 = "010";
    cout << addBinary(s1, s2) << endl;
}