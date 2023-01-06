/*4.Rotate Function
You are given an integer array nums of length n.
Assume arrk to be an array obtained by rotating nums by k positions clock-wise.
We define the rotation function F on nums as follow:
F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
Return the maximum value of F(0), F(1), ..., F(n-1).
The test cases are generated so that the answer fits in a 32-bit integer.*/
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {

        int s=0,n=nums.size();
        vector<int> dp(n,0);
        for(int i=0;i<n;i++)
        {
            s+=nums[i];
            dp[0]+=(i*nums[i]);
        }

        for(int i=1;i<n;i++)
        {
            dp[i]=s+dp[i-1]-(n*nums[n-i]);
        }
        return *max_element(dp.begin(),dp.end());
    }
};
