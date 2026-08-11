class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int n=asteroids.size();
        for(int i=n-1;i>=0;i--){
            bool flag=true;
            while(!st.empty()){
                int ele=st.top();
                if(asteroids[i]<0)
                break;
                else if((asteroids[i]*ele)>0)
                break;
                else{
                    if(abs(ele)>abs(asteroids[i])){
                        flag=false;
                        break;
                    }
                    else if(abs(ele)==abs(asteroids[i])){
                        st.pop();
                        flag=false;
                        break;
                    }
                    else{
                        st.pop();
                    }
                }
            }
            if(flag){
                st.push(asteroids[i]);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            int ele=st.top();
            ans.push_back(ele);
            st.pop();
        }
        return ans;
    }
};