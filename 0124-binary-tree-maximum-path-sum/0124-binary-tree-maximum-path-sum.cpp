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
    pair<int,int> f(TreeNode* root){
        if(root==NULL)
        return {-1e8,0};
        pair<int,int>left=f(root->left);
        pair<int,int>right=f(root->right);
        int mxleft=left.first;
        int mxright=right.first;
        int sumleft=left.second;
        int sumright=right.second;
        int mx=max(mxleft,mxright);
        int sum=(sumleft+sumright+root->val);
        mx=max(sum,mx);
        sum=max(sumleft,sumright)+root->val;
        sum=max(0,sum);
        return{mx,sum};
    }
    int maxPathSum(TreeNode* root) {
        pair<int,int>ans=f(root);
        return ans.first;
    }
};