
//https://leetcode.com/problems/balanced-binary-tree/

//TC-> O(n^2)   SC-> O(n)

class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        int lh= height(root->left);
        int rh= height(root->right);
    
        return 1+ max(lh, rh);
        
    }
    
    
    bool isBalanced(TreeNode* root) {
        
        if(root==NULL){
            return true;
        }
        
        
        int lh= height(root->left);
        int rh= height(root->right);
        
        
        if( abs(lh-rh)>1)
            return false;
        
        bool lbst= isBalanced(root->left);
        bool rbst= isBalanced(root->right);
        
        return lbst&&rbst;
        
        
        
    }
};




////TC-> O(n)   SC-> O(n)

class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        int lh= height(root->left);
        if(lh==-1){
            return -1;
        }
        
        int rh= height(root->right);
        if(rh==-1){
            return -1;
        }
        
        
        
        if(abs(lh-rh)>1){
            return -1;
        }
        
    
        return 1+ max(lh, rh);
        
    }
    
    
    bool isBalanced(TreeNode* root) {
        
        int ans= height(root);
        if(ans==-1){
            return false;
        }
        
        return true;
        
    }
};
