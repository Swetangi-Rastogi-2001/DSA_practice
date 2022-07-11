/*Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.*/



//RECURSION
int f(int i, int j, vector<vector<int>> triangle, int n){
    if(i==n){
        return triangle[i][j];
    }
    
    int d= f(i+1, j, triangle, n);
    int dia= f(i+1, j+1, triangle, n);
    
    return min(d, dia)+triangle[i][j];
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    return f(0,0,triangle,n-1);
}




//MEMOIZATION
int f(int i, int j, vector<vector<int>> triangle, int n, vector<vector<int>> &dp){
    if(i==n){
        return triangle[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int d= f(i+1, j, triangle, n, dp);
    int dia= f(i+1, j+1, triangle, n, dp);
    
    return dp[i][j]= min(d, dia)+triangle[i][j];
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    
    vector<vector<int>> dp(n , vector<int> (n, -1));
    return f(0, 0, triangle, n-1, dp);
}




//DP
int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>> dp(n , vector<int> (n, 0));
 
    for(int i=0;i<n;i++){
        dp[n-1][i]= triangle[n-1][i];
    }
    
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int d= dp[i+1][j];
            int dia= dp[i+1][j+1];
            dp[i][j]= min(d, dia)+triangle[i][j];
        }
    }
    
    return dp[0][0];
}




//SPACE OPTIMIZATION
int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<int> dp(n, 0);
 
    for(int i=0;i<n;i++){
        dp[i]= triangle[n-1][i];
    }
    
    for(int i=n-2;i>=0;i--){
        vector<int> temp(n, 0);
        for(int j=i;j>=0;j--){
            int d= dp[j];
            int dia= dp[j+1];
            temp[j]= min(d, dia)+triangle[i][j];
        }
        dp=temp;
    }
    
    return dp[0];
}
