📄 Framed Question

Problem Statement:
Given a binary string s, return the number of non-empty substrings that have the same number of 0’s and 1’s, and all the 0’s and all the 1’s in these substrings are grouped consecutively.

Two substrings are different if they occur at different positions in s, even if they are identical in content.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        // Store the counts of consecutive characters
        vector<int> groups;
        int count = 1;
        
        // Count consecutive characters
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1]) {
                count++;
            } else {
                groups.push_back(count);
                count = 1;
            }
        }
        groups.push_back(count);  // Don't forget the last group
        
        // Count valid substrings
        int result = 0;
        for (int i = 1; i < groups.size(); i++) {
            result += min(groups[i-1], groups[i]);
        }
        
        return result;
    }
};


Another Example: "111000101"
Step 1: Identify Groups
String: "111000101"

Group 1: "111" → 3 ones
Group 2: "000" → 3 zeros
Group 3: "1" → 1 one
Group 4: "0" → 1 zero
Group 5: "1" → 1 one
Groups array: [3, 3, 1, 1, 1]
