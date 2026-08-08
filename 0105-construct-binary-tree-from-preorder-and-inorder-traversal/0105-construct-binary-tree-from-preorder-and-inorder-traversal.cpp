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
    TreeNode* f(vector<int>& preorder, vector<int>& inorder,map<int,int>&m,int ps,int pe,int is,int ie){
        if(ps>pe || is>ie)
        return NULL;
        TreeNode* root=new TreeNode(preorder[ps]);
        int indx=m[preorder[ps]];
        int length=indx-is;
        root->left=f(preorder,inorder,m,ps+1,ps+length,is,indx-1);
        root->right=f(preorder,inorder,m,ps+length+1,pe,indx+1,ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return f(preorder,inorder,m,0,preorder.size()-1,0,inorder.size()-1);
    }
};