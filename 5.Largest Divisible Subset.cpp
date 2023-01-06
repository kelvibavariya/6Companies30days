/*5.Largest Divisible Subset
Given a set of distinct positive integers nums, return the
largest subset answer such that every pair (answer[i], answer[j])
of elements in this subset satisfies:
answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.*/
class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size(),ele=-1,ind;
        if(n==0 || n==1)return nums;
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1),ans,v(n,-1);
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]%nums[j]==0 && dp[i]<=dp[j])
                {
                    dp[i]=dp[j]+1;
                    v[i]=j;
                }
            }
            if(dp[i]>ele){ele=dp[i];ind=i;}
        }
        while(ind>=0)
        {
            ans.push_back(nums[ind]);
            ind=v[ind];
        }

        return ans;
    }
};
