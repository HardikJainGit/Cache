#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet {
    vector<int> v;
    unordered_map<int,int> mp;
public:
   
    RandomizedSet() {
    }

    bool search(int val){
         if(mp.find(val)!=mp.end()) // O(1)
            return true;
         return false;
    }

    bool insert(int val) {
        if(search(val))
            return false;

        v.push_back(val);
        mp[val] = v.size()-1; //index
        return true;
    }
    
    bool remove(int val) {

        if(!search(val))
            return false;

        auto it = mp.find(val); 

        int index = it->second;
        int last_element = v.back();

        v[index] = last_element;
        v.pop_back();

        mp[v[index]] = index; // this is no longer at last it is now at index

        mp.erase(val);

        return true;
    }
   
    int getRandom() {

        return v[rand()%v.size()]; //get any random number %sz(v)
    }
};

/* Line:118 [mp] = [{(5,4),(1,0),(2,1),(3,2),(4,3)}]
Line:127 [it->second] = [2]
Line:128 [v.back()] = [5]
Line:129 [v] = [{1,2,3,4,5}]
Line:133 [v.back()] = [5]
Line:134 [v] = [{1,2,5,4,5}]
Line:138 [v] = [{1,2,5,4}]
Line:139 [mp] = [{(5,4),(1,0),(2,1),(3,2),(4,3)}]
Line:142 [mp] = [{(5,2),(1,0),(2,1),(3,2),(4,3)}]
Line:144 [mp] = [{(5,2),(1,0),(2,1),(4,3)}]
 */