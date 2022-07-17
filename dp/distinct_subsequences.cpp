/*https://leetcode.com/problems/distinct-subsequences/*/



//RECURSION

class Solution {
public:
    
    int f(int i, int j, string str1, string str2){
        if(j<0) return 1;
        if(i<0) return 0;
        
        if(str1[i]==str2[j]){
            return f(i-1, j-1, str1, str2)+f(i-1,j, str1, str2);
        }
        else{
            return f(i-1, j, str1, str2);
        }
    }
    
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        return f(n-1, m-1, s, t);
    }
};


//MEMOIZATION
class Solution {
public:
    
    int f(int i, int j, string &str1, string &str2, vector<vector<int>> &dp){
        if(j<0) return 1;
        if(i<0) return 0;
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(str1[i]==str2[j]){
            return dp[i][j]=f(i-1, j-1, str1, str2, dp)+f(i-1,j, str1, str2, dp);
        }
        else{
            return dp[i][j]=f(i-1, j, str1, str2, dp);
        }
    }
    
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>> dp(n , vector<int> (m,-1));
        return f(n-1, m-1, s, t, dp);
    }
};




//DP
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<double>> dp(n+1, vector<double> (m+1,0));
        
        
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]= dp[i-1][j-1]+dp[i-1][j];
                }
                else{
                    dp[i][j]= dp[i-1][j];
                }
            }
        }
        
        return int(dp[n][m]);
        
    }
};



//SPACE OPTIMIZATION
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<double> dp(m+1,0), temp(m+1, 0);
        
        
        dp[0]=temp[0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    temp[j]= dp[j-1]+dp[j];
                }
                else{
                    temp[j]= dp[j];
                }
            }
            dp=temp;
        }
        
        return int(dp[m]);
        
    }
};


//SPACE OPTIMIZATION -2
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<double> dp(m+1,0);
        
        
        dp[0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1]){
                    dp[j]= dp[j-1]+dp[j];
                }
                else{
                    dp[j]= dp[j];
                }
            }
        }
        
        return int(dp[m]);
        
    }
};
