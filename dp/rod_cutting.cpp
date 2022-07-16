/*https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?leftPanelTab=1*/



//RECURSION
int f(int index, int N, vector<int> price){
    if(index==0){
        return N*price[0];
    }
    int nottake= f(index-1, N, price);
    int take=-1e8;
    int rodlength= index+1;
    if(rodlength<=N){
        take= price[index]+f(index, N-rodlength, price);
    }
    return max(take, nottake);
}

int cutRod(vector<int> &price, int n)
{
    return f(n-1, n, price);
}


//MEMOIZATION
int f(int index, int N, vector<int> price, vector<vector<int>> &dp){
    if(index==0){
        return N*price[0];
    }
    
    if(dp[index][N]!=-1){
        return dp[index][N];
    }
    int nottake= f(index-1, N, price, dp);
    int take=-1e8;
    int rodlength= index+1;
    if(rodlength<=N){
        take= price[index]+f(index, N-rodlength, price, dp);
    }
    return dp[index][N]=max(take, nottake);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int> (n+1, -1));
    return f(n-1, n, price, dp);
}


//DP
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int> (n+1, 0));
    
    for(int N=0;N<=n;N++){
        dp[0][N]= N*price[0];
    }
    
    for(int index=1;index<n;index++){
        for(int N=0;N<=n;N++){
            int nottake= dp[index-1][N];
            int take=-1e8;
            int rodlength= index+1;
            if(rodlength<=N){
                take= price[index]+dp[index][ N-rodlength];
            }
            
            dp[index][N]= max(nottake, take);
        }
    }
    return dp[n-1][n];
}


// SPACE OPTIMIZATION 2 Array
int cutRod(vector<int> &price, int n)
{
    vector<int> dp(n+1, 0), temp(n+1, 0);
    
    for(int N=0;N<=n;N++){
        dp[N]= N*price[0];
    }
    
    for(int index=1;index<n;index++){
        for(int N=0;N<=n;N++){
            int nottake= dp[N];
            int take=-1e8;
            int rodlength= index+1;
            if(rodlength<=N){
                take= price[index]+temp[ N-rodlength];
            }
            
            temp[N]= max(nottake, take);
        }
        dp=temp;
    }
    return dp[n];
}


//SPACE OPTIMIZATION 1 Array
int cutRod(vector<int> &price, int n)
{
    vector<int> dp(n+1, 0);
    
    for(int N=0;N<=n;N++){
        dp[N]= N*price[0];
    }
    
    for(int index=1;index<n;index++){
        for(int N=0;N<=n;N++){
            int nottake= dp[N];
            int take=-1e8;
            int rodlength= index+1;
            if(rodlength<=N){
                take= price[index]+dp[ N-rodlength];
            }
            
            dp[N]= max(nottake, take);
        }
    }
    return dp[n];
}

