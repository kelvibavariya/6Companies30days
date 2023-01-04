/*2.Combination sum with a twist
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice,
and the combinations may be returned in any order.*/
class Solution {
public:
    void solve(int i,int n,int p,int k,vector<int> &c,vector<int> &v,vector<vector<int>> &ans)
    {

        if(v.size()==k)
        {
            if(n==0)
            ans.push_back(v);
            return;
        }
        if(i>=p)return;
        if(c[i]<=n)
        {
            v.push_back(c[i]);
            solve(i+1,n-c[i],p,k,c,v,ans);
            v.pop_back();

        }
        solve(i+1,n,p,k,c,v,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        vector<vector<int>> ans;
        vector<int> c={1,2,3,4,5,6,7,8,9};
        solve(0,n,c.size(),k,c,v,ans);
        return ans;
    }
};
