class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>st;
        for(auto &it:expression){
            if(it=='(' || it==',')
            continue;
            else if(it!=')')
            st.push(it);
            else {
                bool t=false,f=false;
                while(st.top()=='f' || st.top()=='t'){
                    char c=st.top();
                    st.pop();
                    if(c=='t')
                    t=true;
                    else
                    f=true;
                }
                char c=st.top();
                st.pop();
                if(c=='!')
                st.push(t?'f':'t');
                else if(c=='&')
                st.push(f?'f':'t');
                else 
                st.push(t?'t':'f');
            }
        }
        return st.top()=='t';
    }
};