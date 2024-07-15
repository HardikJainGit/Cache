#include<bits/stdc++.h>
using namespace std;

// 	https://leetcode.com/problems/roman-to-integer/

class Solution {
public : 

int romanToInt(const std::string& s) 
{
    unordered_map<char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int total = 0;
    int n = s.length();

    for (int i = 0; i < n - 1; i++) 
    {
        if (romanMap[s[i]] < romanMap[s[i + 1]]) 
        {
            total -= romanMap[s[i]];
        } 
        else 
        {
            total += romanMap[s[i]];
        }
    }

    total += romanMap[s[n-1]];

    return total;
}
};

// stoi : ans=ans*10+(s[i]-'0'); 