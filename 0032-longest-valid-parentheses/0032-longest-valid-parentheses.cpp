class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0,o=0,c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
            o++;
            else{
                c++;
                int cal=2*min(o,c);
                if(o==c)
                ans=max(ans,cal);
                if(c>o){
                    o=0;
                    c=0;
                }
            }
        }
        o=0,c=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')')
            c++;
            else{
                o++;
                int cal=2*min(o,c);
                if(o==c)
                ans=max(ans,cal);
                if(o>c){
                    o=0;
                    c=0;
                }
            }
        }
        return ans;
    }
};