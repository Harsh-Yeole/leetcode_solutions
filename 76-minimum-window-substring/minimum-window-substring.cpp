class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>m,mt;
        set<int>st;
        int l=0,r=0,n=s.size(),nt=t.size(),ans=n+1;
        int f=-1,e=-1;
        for(int i=0;i<nt;i++){
            mt[t[i]]++;
        }
        while(r<n){
            m[s[r]]++;
            if(mt.find(s[r])!=mt.end()){
                if(m[s[r]]>=mt[s[r]]){
                    st.insert(s[r]);
                    while(l<=r && st.size()==mt.size()){
                        bool flag=true;
                        if(ans>r-l+1){
                            ans=r-l+1;
                            f=l;
                            e=r;
                        }
                        m[s[l]]--;
                        if(mt.find(s[l])!=mt.end() && m[s[l]]<mt[s[l]]){
                            st.erase(s[l]);
                            flag=false;
                        }
                        l++;
                        if(!flag)
                        break;
                    }
                }
            }
            r++;
        }
        if(ans==n+1)
        return "";
        else{
            string ret="";
            for(int i=f;i<=e;i++)
            ret+=s[i];
            return ret;
        }
    }
};