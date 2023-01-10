/*10.Shortest Unsorted Continuous Subarray
Given an integer array nums, you need to find one continuous
subarray that if you only sort this subarray in ascending order,
then the whole array will be sorted in ascending order.
Return the shortest such subarray and output its length.*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> s;
        int n=nums.size();
        int l=n,r=0;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && nums[s.top()]>nums[i])
            {
                l=min(l,s.top());
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && nums[s.top()]<nums[i])
            {
                r=max(r,s.top());
                s.pop();
            }
            s.push(i);
        }
        if(r-l>0)return r-l+1;
        return 0;
    }
};
