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
    int f(TreeNode* node,int &mx){
        int left=0;
        int right=0;
        int sum=node->val;
        if(node->left!=NULL)
        left+=f(node->left,mx);
        if(node->right!=NULL)
        right+=f(node->right,mx);
        int total=sum+left+right;
        sum=max({0,sum+left,sum+right});
        mx=max(mx,total);
        return sum;
    }
    int maxPathSum(TreeNode* root) {
        int mx=-1001;
        f(root,mx);
        return mx;
    }
};