class Solution {
public:
    int f(vector<int>&v){
        int n=v.size();
        stack<int>st;
        int ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty()){
                int indx=st.top();
                if(v[indx]<v[i]){
                    break;
                }
                else{
                    st.pop();
                    int tind=-1;
                    if(st.size()>0){
                        tind=st.top();
                    }
                    int cal=(i-tind-1)*v[indx];
                    ans=max(ans,cal);
                }
            }
            st.push(i);
        }
        while(!st.empty()){
            int indx=st.top();
            st.pop();
            if(st.size()>0){
                int cal=(n-st.top()-1)*v[indx];
                ans=max(ans,cal);
            }
            else{
                int cal=(n)*v[indx];
                ans=max(ans,cal);
            }
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix[0].size();
        int m=matrix.size();
        vector<int>temp(n,0);
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    temp[j]++;
                }
                else{
                    temp[j]=0;
                }
            }
            ans=max(ans,f(temp));
        }
        return ans;
    }
};