
/*https://www.codingninjas.com/codestudio/problems/can-you-make_4244510?leftPanelTab=0*/

int canYouMake(string &str, string &ptr)
{
    // Write your code here.
    int n= str.length();
    int m= ptr.length();
    
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for(int index1=1;index1<=n;index1++){
        for(int index2=1;index2<=m;index2++){
            if(str[index1-1]==ptr[index2-1]){
                dp[index1][index2]= 1+ dp[index1-1][index2-1];
            }
            else{
                dp[index1][index2]= max(dp[index1-1][index2], dp[index1][index2-1]);
            }
        }
        
    }
    int maxi= dp[n][m];
    
    return n+m-2*maxi;
    
    
}
