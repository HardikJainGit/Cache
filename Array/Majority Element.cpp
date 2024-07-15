#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {

    //Some weird voting algorithm that pays me 1 Lpm huhu
        
    int n = nums.size();
    int cnt = 0; // count
    int el; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        // change only if count is zero
        if (cnt == 0) {
            cnt = 1;
            el = nums[i]; //initialise with the next element following the count 0 cancellation
        }
        else if (el == nums[i]) cnt++;
        else cnt--;
    }

    //checking if the stored element
    // is the majority element:
    // int cnt1 = 0;
    // for (int i = 0; i < n; i++) {
    //     if (nums[i] == el) cnt1++;
    // }

    // if (cnt1 > (n / 2)) return el;
    // return -1;

    return el;
    
}
};

// https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

    //Some weird voting algorithm that pays me 1 Lpm
        
    int n = nums.size();
    int cnt1 = 0;
    int cnt2 = 0; // count
    int el2 = INT_MIN; int el1=INT_MIN; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && nums[i]!=el2) { //modification to check if it's not el2
            cnt1 = 1;
            el1 = nums[i]; //initialise with the next element following the count 0 cancellation
        }
        else if (cnt2 == 0 && nums[i]!=el1) {
            cnt2 = 1;
            el2 = nums[i];
        }
        else if (el1 == nums[i]) cnt1++;
        else if (el2 == nums[i]) cnt2++;
        else {cnt1--;cnt2--;}
    }

    vector<int> l; // list of answers

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == el1) cnt1++;
        if (nums[i] == el2) cnt2++;
    }

    int reqd = int(n / 3) + 1;
    if (cnt1 >= reqd) l.push_back(el1);
    if (cnt2 >= reqd) l.push_back(el2);

    // Uncomment the following line
    // if it is told to sort the answer array:
    // sort(l.begin(), l.end()); //TC --> O(2*log2) ~ O(1);

    if(sz(l)==2 && l[0]==l[1])
    {
        l.pop_back();
        return l;
    }

    return l;
    
}
};