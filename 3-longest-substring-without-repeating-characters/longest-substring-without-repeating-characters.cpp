class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>m;
        int l=0,r=0,n=s.size(),ans=0;
        while(r<n){
            m[s[r]]++;
            while(l<=r && m[s[r]]>1){
                m[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};