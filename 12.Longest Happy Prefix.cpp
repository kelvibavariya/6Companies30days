/*12.Longest Happy Prefix
A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).
Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.*/

//KMP algorithm
class Solution {
public:
    string longestPrefix(string s) {
        int n=s.length();
        if(n==0)return "";
        vector<int> v(n,0);
        int i,j;
        for(i=0,j=1;j<n;){
            if(s[i]==s[j]){
                v[j++]=i+1;
                i++;
            }
            else{
                if(i==0)j++;
                else i=v[i-1];
            }
        }
        return s.substr(0,i);
    }
};
