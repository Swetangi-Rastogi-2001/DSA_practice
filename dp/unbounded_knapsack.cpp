/*https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?leftPanelTab=1*/


//RECURSION
int f(int index, int W, vector<int> val, vector<int> wt){
    if(index==0){
        return int(W/wt[0])*val[0];
    }
    
    int nottake= f(index-1, W, val, wt);
    int take= -1e8;
    if(W>=wt[index]){
        take= val[index]+f(index, W-wt[index], val, wt);
    }
    
    return max(take, nottake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    
    return f(n-1, w, profit, weight);
}



//MEMOIZATION
int f(int index, int W, vector<int> val, vector<int> wt, vector<vector<int>> &dp){
    if(index==0){
        return int(W/wt[0])*val[0];
    }
    if(dp[index][W]!=-1){
        return dp[index][W];
    }
    int nottake= f(index-1, W, val, wt, dp);
    int take= -1e8;
    if(W>=wt[index]){
        take= val[index]+f(index, W-wt[index], val, wt, dp);
    }
    
    return dp[index][W]= max(take, nottake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int> (w+1, -1));
    return f(n-1, w, profit, weight, dp);
}



//DP
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int> (w+1, 0));
    
    for(int j=0;j<=w;j++){
        dp[0][j]= int(j/weight[0])*profit[0];
    }
    for(int index=1;index<n;index++){
        for(int j=0;j<=w;j++){
            int nottake= dp[index-1][j];
            int take= -1e8;
            if(j>=weight[index]){
                take= profit[index]+dp[index][j-weight[index]];
            }

            dp[index][j]= max(take, nottake);
        }
    }
    return dp[n-1][w];
}


//SPACE OPTIMIZATION 2 Array
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<int> dp(w+1, 0), temp(w+1, 0);
    
    for(int j=0;j<=w;j++){
        dp[j]= int(j/weight[0])*profit[0];
    }
    for(int index=1;index<n;index++){
        for(int j=0;j<=w;j++){
            int nottake= dp[j];
            int take= -1e8;
            if(j>=weight[index]){
                take= profit[index]+temp[j-weight[index]];
            }

            temp[j]= max(take, nottake);
        }
        dp=temp;
    }
    return dp[w];
}


//SPACE OPTIMIZATION 1 array
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<int> dp(w+1, 0);
    
    for(int j=0;j<=w;j++){
        dp[j]= int(j/weight[0])*profit[0];
    }
    for(int index=1;index<n;index++){
        for(int j=0;j<=w;j++){
            int nottake= dp[j];
            int take= -1e8;
            if(j>=weight[index]){
                take= profit[index]+dp[j-weight[index]];
            }

            dp[j]= max(take, nottake);
        }
    }
    return dp[w];
}





