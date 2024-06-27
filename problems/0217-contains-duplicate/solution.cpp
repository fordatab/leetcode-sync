#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> dup(nums.begin(), nums.end());
        return dup.size() != nums.size();
    }
};