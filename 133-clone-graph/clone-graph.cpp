/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node,vector<int>&visited,unordered_map<Node*,Node*>&m){
        visited[node->val]=1;
        Node* newnode=new Node(node->val);
        m[node]=newnode;
        for(auto &it:node->neighbors){
            if(visited[it->val]==0){
                dfs(it,visited,m);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)
        return NULL;
        unordered_map<Node*,Node*>m;
        vector<int>v(101,0);
        dfs(node,v,m);
        for(auto &it:m){
            Node* temp=it.first;
            Node* newtemp=it.second;
            for(auto &itr:temp->neighbors){
                newtemp->neighbors.push_back(m[itr]);
            }
        }
        return m[node];
    }
};