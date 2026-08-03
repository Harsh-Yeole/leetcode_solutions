/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* f(TreeNode* node,TreeNode* p,TreeNode* q){
        if(node==NULL)
        return node;
        if(node==p || node==q)
        return node;
        TreeNode* left=f(node->left,p,q);
        TreeNode* right=f(node->right,p,q);
        if(left==NULL && right==NULL)
        return NULL;
        else if(left!=NULL && right!=NULL)
        return node;
        else if(left!=NULL)
        return left;
        else 
        return right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root,p,q);
    }
};