class Solution {
public:
    bool checkValidString(string s) {
      stack<int>s1,s2;
      for(int i=0;i<s.size();i++){
        if(s[i]=='(')
        s1.push(i);
        else if(s[i]=='*')
        s2.push(i);
        else{
            if(s1.size()+s2.size()==0){
                return false;
            }
            if(s1.size())
            s1.pop();
            else
            s2.pop();
        }
      }
      while(!s1.empty()){
        if(s2.empty())
        return false;
        int o=s1.top();
        int s=s2.top();
        if(s<o)
        return false;
        s1.pop();
        s2.pop();
      }
      return true;
    }
};