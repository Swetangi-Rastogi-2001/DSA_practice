
/*https://leetcode.com/problems/wildcard-matching/*/


//MEMOIZATION
class Solution {
public:
    bool f(int i, int j, string &s, string  &p, vector<vector<int>> &dp){
        
        if(i<0&&j<0){
            return true;
        }
        
        if(i<0&&j>=0){
            return false;
        }
        
        if(j<0&&i>=0){
            for(int index=0;index<=i;index++){
                if(s[index]!='*'){
                    return false;
                }
            }
            return true;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==p[j]||s[i]=='?'){
            return dp[i][j]=f(i-1, j-1, s, p, dp);
        }
        
        if(s[i]=='*'){
            return dp[i][j]=f(i-1,j, s, p, dp) || f(i, j-1, s, p, dp);
        }
        
        
        return dp[i][j]=false;
    }
    
    
    
    bool isMatch(string s, string p) {
        int n= s.length();
        int m= p.length();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return f(m-1, n-1, p, s, dp);
    }
};




//DP
class Solution {
public: 
    
    bool isMatch(string s, string p) {
        int n= p.length();
        int m= s.length();
        vector<vector<bool>> dp(n+1, vector<bool> (m+1, 0));
        
        dp[0][0]= true;
        
        
        for(int j=1;j<=m;j++){
            dp[0][j]= false;
        }
        
        for(int i=1;i<=n;i++){
            bool flag=true;
            for(int ii=1;ii<=i;ii++){
                if(p[ii-1]!='*'){
                    flag=false;
                    break;
                }
            }
            dp[i][0]=flag;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                if(p[i-1]==s[j-1]||p[i-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }

                else if(p[i-1]=='*'){
                    dp[i][j]=dp[i-1][j] | dp[i][j-1];
                }
                else
                    dp[i][j]=false;
                
            }
        }
        
        return dp[n][m];
    }
};


//SPACE OPTIMIZATION
class Solution {
public: 
    
    bool isMatch(string s, string p) {
        int n= p.length();
        int m= s.length();
        vector<bool> dp(m+1, 0), temp(m+1, 0);
        
        dp[0]= true;
        
        
        for(int j=1;j<=m;j++){
            dp[j]= false;
        }
        
        
        
        for(int i=1;i<=n;i++){
            
            bool flag=true;
            for(int ii=1;ii<=i;ii++){
                if(p[ii-1]!='*'){
                    flag=false;
                    break;
                }
            }
            temp[0]=flag;
            
            for(int j=1;j<=m;j++){
                
                if(p[i-1]==s[j-1]||p[i-1]=='?'){
                    temp[j]=dp[j-1];
                }

                else if(p[i-1]=='*'){
                    temp[j]=dp[j] | temp[j-1];
                }
                else
                    temp[j]=false;
                
            }
            dp=temp;
        }
        
        return dp[m];
    }
};
