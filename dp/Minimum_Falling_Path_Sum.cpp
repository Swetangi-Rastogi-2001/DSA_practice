/*Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.*/

//RECURSION
class Solution {
public:
    
    int f(int i, int j, vector<vector<int>> matrix){
        
        if(j<0||j>=matrix.size()){
            return 1e9;
        }
        
        
        if(i==0){
            return matrix[i][j];
        }
        
        int s= matrix[i][j]+ f(i-1, j, matrix);
        int l= matrix[i][j]+ f(i-1, j-1, matrix);
        int r= matrix[i][j]+ f(i-1, j+1, matrix);
        
        return min(s, min(l,r));
    }
    
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int minans=INT_MAX;
        int m=matrix.size();
        int n= matrix[0].size();
        
        for(int i=0;i<n;i++){
            minans= min(minans, f(n-1, i, matrix));
        }
        
        return minans;
    }
};


//MEMOIZATION
class Solution {
public:
    
    int f(int i, int j, vector<vector<int>> matrix, vector<vector<int>> &dp){
        
        if(j<0||j>=matrix[0].size()){
            return 1e9;
        }
                
        if(i==0){
            return matrix[i][j];
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int s= matrix[i][j]+ f(i-1, j, matrix, dp);
        int l= matrix[i][j]+ f(i-1, j-1, matrix, dp);
        int r= matrix[i][j]+ f(i-1, j+1, matrix, dp);
        
        return dp[i][j]=min(s, min(l,r));
    }
    
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int minans=INT_MAX;
        int m=matrix.size();
        int n= matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int> (n,-1));
        
        for(int i=0;i<n;i++){
            minans= min(minans, f(m-1, i, matrix, dp));
        }
        
        return minans;
    }
};


//DP
class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n= matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int> (n,0));
        
        for(int j=0;j<n;j++){
                dp[0][j]= matrix[0][j];
        }
        
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int up= dp[i-1][j];
                
                int left= INT_MAX;
                if(j>0){
                    left=dp[i-1][j-1];
                }
                int right= INT_MAX;
                if(j<matrix.size()-1){
                    right=dp[i-1][j+1];
                }
                
                dp[i][j]= min(up, min(left, right))+matrix[i][j];
                
            }
        }
        
        int minans= dp[m-1][0];
        for(int j=0;j<n;j++){
            minans= min(minans, dp[m-1][j]);
        }
        
        return minans;
    }
};

//SPACE OPTIMIZATION
class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n= matrix[0].size();
        
        vector<int> dp(n,0);
        
        for(int j=0;j<n;j++){
                dp[j]= matrix[0][j];
        }
        
        for(int i=1;i<m;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                int up= dp[j];
                
                int left= INT_MAX;
                if(j>0){
                    left=dp[j-1];
                }
                int right= INT_MAX;
                if(j<matrix.size()-1){
                    right=dp[j+1];
                }
                
                temp[j]= min(up, min(left, right))+matrix[i][j];
                
            }
            dp=temp;
        }
        
        int minans= dp[0];
        for(int j=0;j<n;j++){
            minans= min(minans, dp[j]);
        }
        
        return minans;
    }
};
