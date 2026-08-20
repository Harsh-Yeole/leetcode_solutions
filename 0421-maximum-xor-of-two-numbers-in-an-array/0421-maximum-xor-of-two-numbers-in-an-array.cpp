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
    int findMaximumXOR(vector<int>& nums) {
        Node* root=new Node();
        for(auto &it:nums){
            Node* temp=root;
            for(int i=31;i>=0;i--){
                int num=(it>>i);
                int bit=(num&1);
                if(!temp->isthere(bit)){
                    temp->put(bit,new Node());
                }
                temp=temp->next(bit);
            }
        }
        int ans=0;
        for(auto &it:nums){
            Node* temp=root;
            int cal=0;
            for(int i=31;i>=0;i--){
                int num=(it>>i);
                int bit=(num&1);
                int bitw=(bit^1);
                if(temp->isthere(bitw)){
                    cal+=(1<<i);
                    temp=temp->next(bitw);
                }
                else{
                    temp=temp->next(bit);
                }
            }
            ans=max(ans,cal);
        }
        return ans;
    }
};