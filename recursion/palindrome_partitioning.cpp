/*Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
A palindrome string is a string that reads the same backward as forward.

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]*/






class Solution {
public:
    
    bool palindrome(string s, int start, int end){
         
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void helper(string s, int index, int n, vector<string> temp, vector<vector<string>> &ans){
        if(index==n){
            ans.push_back(temp);
            return;
        }
        
        for(int i=index;i<n;i++){
            if(palindrome(s, index, i)){
                temp.push_back(s.substr(index, i-index+1));
                helper(s, i+1, n, temp, ans);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
         vector<string>  temp;
        helper(s, 0, s.length(), temp, ans);
        return ans;
    }
};
