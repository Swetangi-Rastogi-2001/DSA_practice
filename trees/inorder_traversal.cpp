/*https://leetcode.com/problems/binary-tree-inorder-traversal/*/

//RECURSIVE
class Solution {
public:
    
    void f(TreeNode* root, vector<int> &a){
        
        if(root==NULL){
            return;
        }
        
        f(root->left, a);
        a.push_back(root->val);
        f(root->right, a);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> a;
        f(root, a);
        return a;
    }
};



