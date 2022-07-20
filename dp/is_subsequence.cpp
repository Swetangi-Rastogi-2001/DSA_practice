
/*https://leetcode.com/problems/is-subsequence/*/

//RECURSION
class Solution {
public:
    
    bool f(int ind1, int ind2 , string str, string subs){
        if(ind2<0){
            return true;
        }
        if(ind1<0){
            return false;
        }
        
        if(str[ind1]==subs[ind2]){
            return f(ind1-1,ind2-1, str, subs);
        }
        
        else{
            return f(ind1-1, ind2, str, subs);
        }
    }
    
    
    bool isSubsequence(string s, string t) {
        return f(t.length()-1, s.length()-1, t, s);
    }
};


//MEMOIZATION
class Solution {
public:
    
    bool f(int ind1, int ind2 , string str, string subs, vector<vector<int>> &dp){
        if(ind2<0){
            return true;
        }
        if(ind1<0){
            return false;
        }
        
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        
        if(str[ind1]==subs[ind2]){
            return dp[ind1][ind2]=f(ind1-1,ind2-1, str, subs, dp);
        }
        
        else{
            return dp[ind1][ind2]=f(ind1-1, ind2, str, subs, dp);
        }
    }
    
    
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(t.length(), vector<int> (s.length(), -1));
        return f(t.length()-1, s.length()-1, t, s, dp);
    }
};
