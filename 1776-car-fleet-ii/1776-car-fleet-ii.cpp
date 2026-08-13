class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        stack<int>st;
        int n=cars.size();
        vector<double>tame(cars.size(),INT_MAX);
        for(int i=n-1;i>=0;i--){
            double temp=1.0*INT_MAX;
            while(!st.empty()){
                int indx=st.top();
                int d1=cars[indx][0];
                int d2=cars[i][0];
                int s1=cars[indx][1];
                int s2=cars[i][1];
                if(s1>=s2){
                    st.pop();
                }
                else{
                    double cal=(1.0*d1-d2)/(s2-s1);
                    temp=min(temp,cal);
                    if(cal<=tame[indx]){
                        break;
                    }
                    st.pop();
                }
            }
            tame[i]=temp;
            st.push(i);
        }
        for(auto &it:tame){
            if(it==1.0*INT_MAX)
            it=-1;
        }
        return tame;
    }
};