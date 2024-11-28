#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

int myAtoi(char *s) {
    int n = strlen(s); // Get the length of the char* string
    int i = 0;
    // Strep 1: Skip the leading whitespaces
    while(i < n && s[i] == ' '){
        i++;
    }
        
    // Step 2: Check for sign
    int sign = 1;
    if(i < n && (s[i] == '+' || s[i] == '-')){
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
        
    // Step 3: Convert digits to integer
    long long result = 0;   // Use long long to handle overflow during computation
    while(i < n && s[i] >= '0' && s[i] <= '9'){
        int digit = s[i] -'0';  // Convert char to integer
        result = result * 10 + digit;
            
        // Step 4: Check for overflow
        if(result > INT_MAX){
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
            
        i++;
    }
        
    // Step 5: Return the final result with the sign
    return static_cast<int>(result * sign);
}

int main(){
    char s1[] = "-123";
    char s2[] = " -";
    char s3[] = " 12312312312311133";
    char s4[] = "-999999999999";
    char s5[] = "  -0012gfg4";

    cout << myAtoi(s1) << endl;
    cout << myAtoi(s2) << endl;
    cout << myAtoi(s3) << endl;
    cout << myAtoi(s4) << endl;
    cout << myAtoi(s5) << endl;

    return 0;
}