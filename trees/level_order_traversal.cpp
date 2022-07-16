/*https://leetcode.com/problems/binary-tree-level-order-traversal/*/


#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        
        
        while(!q.empty()){
            int size= q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                TreeNode* front= q.front();
                q.pop();
                
                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
                
                temp.push_back(front->val); 
            }
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};
