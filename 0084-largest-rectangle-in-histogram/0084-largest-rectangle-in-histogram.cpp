class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>stl;
        int n=heights.size();
        vector<int>left(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            while(!stl.empty()){
                int indx=stl.top();
                if(heights[indx]>=heights[i]){
                    int cal=(i-(left[indx])-1)*heights[indx];
                    ans=max(ans,cal);
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
        while(!stl.empty()){
            int indx=stl.top();
            int cal=(n-left[indx]-1)*heights[indx];
            ans=max(ans,cal);
            stl.pop();
        }  
        return ans;
    }
};