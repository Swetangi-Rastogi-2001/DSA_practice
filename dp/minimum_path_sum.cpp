/*Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.*/



//MEMOIZATION
class Solution {
public:
    
    int f(int i, int j,vector<vector<int>>& grid, vector<vector<int>>& dp ){
        if(i==0&&j==0){
            return grid[0][0];
        }
        if(i<0||j<0){
            return INT_MAX;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int left= f(i, j-1, grid, dp);
        int right= f(i-1, j, grid, dp);
        
        return dp[i][j]= min(left, right)+grid[i][j];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(),-1));
        return f(grid.size()-1, grid[0].size()-1, grid,dp);
    }
};





//DP
class Solution {
public:
    
    int f(int i, int j,vector<vector<int>>& grid, vector<vector<int>>& dp ){
        if(i==0&&j==0){
            return grid[0][0];
        }
        if(i<0||j<0){
            return INT_MAX;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int left= f(i, j-1, grid, dp);
        int right= f(i-1, j, grid, dp);
        
        return dp[i][j]= min(left, right)+grid[i][j];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(),-1));
        return f(grid.size()-1, grid[0].size()-1, grid,dp);
    }
};






//SPACE OPTIMIZATION
class Solution {
public:
       
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> prev(n,INT_MAX);
        
        
        
        for(int i=0;i<m;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0&&j==0){
                    temp[j]= grid[i][j];
                }
                else{
                    int left= INT_MAX;
                    int up= INT_MAX;
                    
                    if(j>0){
                        left= temp[j-1];
                    }
                    if(i>0){
                        up= prev[j];
                    }
                    
                    temp[j]= min(up, left)+grid[i][j];
                }
            }
            prev= temp;
        }
        return prev[n-1];
        
    }
};
