#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   void combinations(int st,vector<vector<int>>&res, vector<int>&ans, int n , int k){
    if(ans.size()==k){
        res.push_back(ans);
        return;
    }
    for(int i = st; i<= n; i++ ){
        ans.push_back(i);
        combinations(i+1, res, ans,n , k);
        ans.pop_back();
    }
   }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>ans;
        combinations( 1,res,ans, n, k);
        return res;
    }
};