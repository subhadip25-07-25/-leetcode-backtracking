
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   void subsetfinder(vector<int>&nums, int i ,vector<int>&ans ,vector<vector<int>>&result){
        int n = nums.size();
        if(i==n){
        result.push_back(ans);
        return; }
        ans.push_back(nums[i]);
        subsetfinder(nums, i+1, ans, result);
        ans.pop_back();
         subsetfinder(nums, i+1, ans, result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>result;
       subsetfinder (nums, 0 , ans,result);
        return result;

    }
};