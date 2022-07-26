/*https://bit.ly/3rVoIoq*/

//DP
#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    
    for(int index=n-1;index>=0;index--){
        for(int prev= index-1;prev>=-1;prev--){
            int len= dp[index+1][prev+1];
            if(prev==-1||arr[index]>arr[prev]){
                len= max(len, dp[index+1][index+1]+1);
            }
            dp[index][prev+1]=len;
        }
    }
    
    return dp[0][-1+1];
}


//SPACE OPTIMIZATION
#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> dp(n+1, 0), temp(n+1, 0);
    
    for(int index=n-1;index>=0;index--){
        for(int prev= index-1;prev>=-1;prev--){
            int len= dp[prev+1];
            if(prev==-1||arr[index]>arr[prev]){
                len= max(len, dp[index+1]+1);
            }
            temp[prev+1]=len;
        }
        dp=temp;
    }
    
    return dp[-1+1];
}



//TABULATION
#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> dp(n, 1);
    int maxi=1;
    for(int index=1;index<n;index++ ){
        for(int prev=0;prev<index;prev++){
            if(arr[prev]<arr[index]){
                dp[index]= max(dp[index], 1+dp[prev]);
            }
        }
        maxi= max(maxi, dp[index]);
    }
    return maxi;
}



//BINARY SEARCH
#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> temp;
    int len=1;
    temp.push_back(arr[0]);
    for(int index=1;index<n;index++){
        if(arr[index]>temp.back()){
            temp.push_back(arr[index]);
            len++;
        }
        else{
            int ind= lower_bound(temp.begin(), temp.end(), arr[index])-temp.begin();
            temp[ind]= arr[index];
        }
    }
    
    return len;
}
