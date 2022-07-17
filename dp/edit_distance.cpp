
/*https://leetcode.com/problems/edit-distance/*/


//RECURSION
class Solution {
public:
    
    int f(int i, int j, string word1, string word2){
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        
        if(word1[i]==word2[j]){
            return f(i-1, j-1, word1, word2);
        }
        else{
            int insert= f(i, j-1, word1, word2);
            int del= f(i-1, j, word1, word2);
            int rep= f(i-1, j-1, word1, word2);
            
            return min(insert, min(del, rep))+1;
        }  
    }
       
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m= word2.size();
        
        return f(n-1, m-1, word1, word2);
    }
};


//MEMOIZATION
class Solution {
public:
    
    int f(int i, int j, string word1, string word2, vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(word1[i]==word2[j]){
            return f(i-1, j-1, word1, word2, dp);
        }
        else{
            int insert= f(i, j-1, word1, word2, dp);
            int del= f(i-1, j, word1, word2, dp);
            int rep= f(i-1, j-1, word1, word2, dp);
            
            return dp[i][j]=min(insert, min(del, rep))+1;
        }  
    }
       
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m= word2.size();
        vector<vector<int>> dp(n , vector<int>(m, -1));
        return f(n-1, m-1, word1, word2, dp);
    }
};


//DP
class Solution {
public:
           
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m= word2.size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1, 0));
        for(int i=0;i<=n;i++){
            dp[i][0]= i;
        }
        
        for(int j=0;j<=m;j++){
            dp[0][j]= j;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]= dp[i-1][j-1];
                }
                else{
                    int insert= dp[i][j-1];
                    int del= dp[i-1][j];
                    int rep= dp[i-1][j-1];
                    
                    dp[i][j]= min(insert, min(del,rep))+1;
                }
            }
        }
        
        return dp[n][m];
    }
};


//SPACE OPTIMIZATION
class Solution {
public:
           
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m= word2.size();
        vector<int> dp(m+1, 0), temp(m+1, 0);
        
        
        
        for(int j=0;j<=m;j++){
            dp[j]= j;
        }
        
        for(int i=1;i<=n;i++){
            temp[0]= i;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    temp[j]= dp[j-1];
                }
                else{
                    int insert= temp[j-1];
                    int del= dp[j];
                    int rep= dp[j-1];
                    
                    temp[j]= min(insert, min(del,rep))+1;
                }
            }
            dp=temp;
        }
        
        return dp[m];
    }
};
