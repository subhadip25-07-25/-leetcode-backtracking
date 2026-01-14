#include<bits/stdc++.h>
using namespace std;
 vector<vector<int>>res;
class Solution {
public:
    // declare global scope
    vector<vector<int>> result;
    void f(vector<int>& c, vector<int>& v, int idx, int t) {
        // base case
        if (t == 0) {
            result.push_back(v);
            return;
        }
        if (idx == c.size()) {
            return;
        }
        // checking include condition
        if (c[idx] <= t) {
            v.push_back(c[idx]);
            f(c, v, idx + 1, t - c[idx]);
            v.pop_back();
        }
        // exclude condition and duplicate
        int j = idx;
        while (  j < c.size()&&c[idx] == c[j]) {
            j++;
        }
        f(c, v, j, t);
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(), c.end());
        result.clear();
        vector<int> v;
        f(c, v, 0, t);
        return result;
    }
};
int main(){
    return 0 ;
}