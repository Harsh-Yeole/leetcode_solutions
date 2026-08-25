class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>m,mr;
        for(int i=0;i<t.size();i++){
            m[t[i]]++;
            mr[t[i]]++;
        }
        int l=0,r=0,n=s.size(),ans=n+1,len=m.size();
        int la=-1,ra=-1;
        while(r<n){
            m[s[r]]--;
            if(m[s[r]]==0)
            len--;
            while(len==0 && l<=r){
                if(r-l+1<ans){
                    ans=r-l+1;
                    la=l;
                    ra=r;
                }
                m[s[l]]++;
                if(m[s[l]]>0){
                    len++;
                }
                l++;
            }
            r++;
        }
        if(la==-1 || ra==-1)
        return "";
        else {
            string ret="";
            while(la<=ra){
                ret+=s[la];
                la++;
            }
            return ret;
        }
    }
};