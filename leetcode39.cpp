
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   void combinations(int idx,vector<int>& candidates, int target,vector<vector<int>>&result,vector<int>&ans){
    if(target ==0){
        result.push_back(ans);
        return;
    }
    int n = candidates.size();
    for(int i = idx; i< n ; i++ ){
        ans.push_back(candidates[i]);
        if((target-candidates[i])>=0){
            combinations(i, candidates, target- candidates[i], result, ans);
        }
        ans.pop_back();
    }

   }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>ans;
        combinations(0,candidates,target,result,ans);
        return result;
    }
};