/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            int mx=INT_MIN,mn=INT_MAX;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front().first;
                int level=q.front().second;
                q.pop();
                mx=max(mx,level);
                mn=min(mn,level);
                if(node->left!=NULL){
                    q.push({node->left,(long long)2*level+1});
                }
                if(node->right!=NULL){
                    q.push({node->right,(long long)2*level+2});
                }
            }
            ans=max(ans,mx-mn+1);
        }
        return ans;
    }
};