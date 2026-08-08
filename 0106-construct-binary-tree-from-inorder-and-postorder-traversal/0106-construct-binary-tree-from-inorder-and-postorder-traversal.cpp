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
    TreeNode* f(vector<int>&postorder,vector<int>&inorder,map<int,int>&m,int ps,int pe,int is,int ie){
        if(ps>pe || is>ie)
        return NULL;
        TreeNode* root=new TreeNode(postorder[pe]);
        int indx=m[postorder[pe]];
        int length=indx-is;
        root->left=f(postorder,inorder,m,ps,ps+length-1,is,indx-1);
        root->right=f(postorder,inorder,m,ps+length,pe-1,indx+1,ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return f(postorder,inorder,m,0,postorder.size()-1,0,inorder.size()-1);
    }
};