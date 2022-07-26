
#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> dp(n, 1), hash(n,0);
    int maxi=1;
    int last=0;
    for(int index=1;index<n;index++ ){
        hash[index]=index;
        for(int prev=0;prev<index;prev++){
            if(arr[prev]<arr[index]&&dp[prev]+1>dp[index]){
                dp[index]= 1+dp[prev];
                hash[index]=prev;
            }
        }
        if(dp[index]>maxi){
            maxi= dp[index];
            last=index;
        }
        
    }
    
    vector<int> ans;
    ans.push_back(arr[last]);
    
    while(hash[last]!=last){
        last= hash[last];
        ans.push_back(arr[last]);
    }
    reverse(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return maxi;
}
