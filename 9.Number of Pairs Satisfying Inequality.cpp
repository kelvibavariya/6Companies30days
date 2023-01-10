/*9.Number of Pairs Satisfying Inequality
You are given two 0-indexed integer arrays nums1 and nums2,
each of size n, and an integer diff. Find the number of
pairs (i, j) such that:
0 <= i < j <= n - 1 and
nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff.
Return the number of pairs that satisfy the conditions.*/

/*Approach:
nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff
nums1[i] - nums2[i] <= nums1[j] - nums2[j] + diff
v[i] = nums1[i] - nums2[i],
just need to find the number of pair in sequence v,
such that v[i] <= (v[j] + diff) using mergesort*/
class Solution {
public:
    long long cnt;
    void merge(vector<int> &v,int lo,int mid,int hi,int d)
    {

        int p=mid+1;
        for(int i=lo;i<=mid;i++)
        {
            while(p<=hi && v[i]>(v[p]+d))
                p++;
            cnt+=(hi-p+1);
        }
        vector < int > t;
        int left = lo, right = mid + 1;

        while (left <= mid && right <= hi) {

            if (v[left] <= v[right]) {
            t.push_back(v[left++]);
            } else {
            t.push_back(v[right++]);
            }
        }

        while (left <= mid) {
            t.push_back(v[left++]);
        }
        while (right <= hi) {
            t.push_back(v[right++]);
        }

        for (int i = lo; i <= hi; i++) {
            v[i] = t[i - lo];
        }
    }

    void mergesort(vector<int> &v,int lo,int hi,int d)
    {
        if(lo>=hi)return;
        int mid=(lo+hi)/2;
        mergesort(v,lo,mid,d);
        mergesort(v,mid+1,hi,d);
        merge(v,lo,mid,hi,d);
        return;
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n=nums1.size();
        vector<int> v(n);
        cnt=0;
        for(int i=0;i<n;i++)
            v[i]=nums1[i]-nums2[i];
        mergesort(v,0,n-1,diff);
        return cnt;
    }
};
