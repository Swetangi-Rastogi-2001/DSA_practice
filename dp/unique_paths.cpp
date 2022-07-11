/*There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.*/



//RECURSION T(O)= 2^m*n S(c)= path length
class Solution {
public:
    
    int f(int i, int j){
        if(i==0&&j==0){
            return 1;
        }
        if(i<0||j<0){
            return 0;
        }
        int up= f(i-1,j);
        int left= f(i, j-1);
        
        return up+left;
    }
    int uniquePaths(int m, int n) {
        return f(m-1,n-1);
    }
};


//MEMOIZATION
class Solution {
public:
    
    int f(int i, int j, vector<vector<int>> &dp ){
        if(i==0&&j==0){
            return 1;
        }
        if(i<0||j<0){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up= f(i-1,j, dp);
        int left= f(i, j-1, dp);
        
        return dp[i][j]=up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1, dp);
    }
};


//DP
class Solution {
public:
    
   
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        for(int j=0;j<n;j++){
            dp[0][j]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int up=dp[i-1][j];
                int left= dp[i][j-1];
                dp[i][j]= up+left;
            }
        }
        
        return dp[m-1][n-1];
    }
};

//SPACE OPTIMIZATION
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> temp(n, 0);
            for(int j=0;j<n;j++){
                if(i==0||j==0){
                    temp[j]=1;
                }
                else{
                    int up= prev[j];
                    int left= temp[j-1];
                    temp[j]= up+left;
                }
            }
            prev=temp;
        }
        
        return prev[n-1];
    }
};
