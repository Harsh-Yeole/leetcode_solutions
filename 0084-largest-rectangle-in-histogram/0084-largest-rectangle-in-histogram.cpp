class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>stl,str;
        int n=heights.size();
        vector<int>left(n,0),right(n,0);
        for(int i=0;i<n;i++){
            while(!stl.empty()){
                int indx=stl.top();
                if(heights[indx]>=heights[i]){
                    stl.pop();
                }
                else{
                    left[i]=indx;
                    break;
                }
            }
            if(stl.empty()){
                left[i]=-1;
            }
            stl.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!str.empty()){
                int indx=str.top();
                if(heights[indx]>=heights[i]){
                    str.pop();
                }
                else{
                    right[i]=indx;
                    break;
                }
            }
            if(str.empty()){
                right[i]=n;
            }
            str.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int cal=(right[i]-left[i]-1)*heights[i];
            ans=max(ans,cal);
        }
        return ans;
    }
};