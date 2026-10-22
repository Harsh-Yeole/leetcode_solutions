class Solution {
public:
    int totalFruit(vector<int>& v) {
        int one=-1,two=-1;
        int n=v.size();
        int l=0,r=0,ans=0;
        while(r<n){
            if(one==-1 && two==-1){
                one=r;
                r++;
            }
            else if(v[r]!=v[one] && two==-1){
                two=r;
                r++;
            }
            else{
                if(v[r]==v[one] || v[r]==v[two]){
                    if(v[r]==v[one])
                    one=r;
                    else
                    two=r;
                }
                else{
                    l=min(one,two)+1;
                    if(one<two)
                    one=r;
                    else
                    two=r;
                }
                r++;
            }
            ans=max(ans,r-l);
        }
        return ans;
    }
};