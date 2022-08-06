
/*https://www.codingninjas.com/codestudio/problems/number-of-longest-increasing-subsequence_3751627?leftPanelTab=0*/

int findNumberOfLIS(vector<int> &arr)
{
    // Write your code here.
    int n=arr.size();
    vector<int> dp(n,1), count(n, 1);
    int maxi=1;
    for(int index=1;index<n;index++){
        for(int prev=0;prev<index;prev++){
            if(arr[index]>arr[prev]&&dp[index]<dp[prev]+1){
                dp[index]= dp[prev]+1;
                count[index]= count[prev];
            }
            else if(arr[index]>arr[prev]&&dp[index]==dp[prev]+1){
                count[index]+=count[prev];
            }
        }
        maxi= max(maxi, dp[index]);
    }
    
    int nos=0;
    for(int i=0;i<n;i++){
        if(maxi==dp[i]){
            nos+=count[i];
        }
    }
    
    return nos;
    
}
