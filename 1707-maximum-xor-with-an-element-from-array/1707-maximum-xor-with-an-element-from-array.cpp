class Solution {
public:
    struct Node{
        vector<Node*>v;
        Node(){
            v.resize(2,NULL);
        }
        bool isthere(int i){
            return v[i]!=NULL;
        }
        void put(int i,Node* node){
            v[i]=node;
        }
        Node* next(int i){
            return v[i];
        }
    };
    void insert(Node* root,int n){
        Node* temp=root;
        for(int i=31;i>=0;i--){
            int num=(n>>i);
            int bit=(num&1);
            if(!temp->isthere(bit)){
                temp->put(bit,new Node());
            }
            temp=temp->next(bit);
        }
    }
    int mxor(int x,Node* root){
        Node* temp=root;
        int ans=0;
        for(int i=31;i>=0;i--){
            int num=(x>>i);
            int bit=(num&1);
            int bitw=(bit^1);
            if(temp->isthere(bitw)){
                ans+=(1<<i);
                temp=temp->next(bitw);
            }
            else{
                temp=temp->next(bit);
            }
        }
        return ans;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>offlinequeries;
        for(int i=0;i<queries.size();i++){
            int x=queries[i][0];
            int m=queries[i][1];
            offlinequeries.push_back({m,x,i});
        }
        vector<int>ans(queries.size(),0);
        sort(offlinequeries.begin(),offlinequeries.end());
        int curr=0;
        Node* root=new Node();
        for(auto &it:offlinequeries){
            int indx=upper_bound(nums.begin(),nums.end(),it[0])-nums.begin();
            if(indx==0){
                ans[it[2]]=-1;
                continue;
            }
            while(curr<indx){
                insert(root,nums[curr]);
                curr++;
            }
            int ret=mxor(it[1],root);
            ans[it[2]]=ret;
        }
        return ans;
    }
};