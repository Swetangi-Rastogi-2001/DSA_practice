
/*https://leetcode.com/problems/binary-tree-preorder-traversal/*/

//RECURSIVE
class Solution {
public:
    
    void f(TreeNode* root, vector<int> &a){
        
        if(root==NULL){
            return;
        }
        a.push_back(root->val);
        f(root->left, a);
        f(root->right, a);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> a;
        f(root, a);
        return a;
    }
};


//ITERATIVE USING 1 STACK
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        s.push(root);
        while(!s.empty()){
            TreeNode* top= s.top();
            s.pop();
            if(top->right!=NULL){
                s.push(top->right);
            }
            if(top->left!=NULL){
                s.push(top->left);
            }
            ans.push_back(top->val);
        }
        
        return ans;
    }
};
