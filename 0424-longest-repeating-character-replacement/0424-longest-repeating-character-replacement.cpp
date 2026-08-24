class Solution {
public:
    int characterReplacement(string s, int k) {
        int mx=0,l=0,r=0,n=s.size(),ans=0;
        vector<int>v(26,0);
        while(r<n){
            v[s[r]-'A']++;
            mx=max(mx,v[s[r]-'A']);
            while(r-l+1-mx>k){
                v[s[l]-'A']--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};