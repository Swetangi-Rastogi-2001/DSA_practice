


//TABULATION
int lcs(string &str1, string &str2){
    
    int n= str1.length();
    int m= str2.length();
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    int maxi=0;
    for(int index1=0; index1<=n;index1++){
        for(int index2=0;index2<=m; index2++){
            if(index1==0||index2==0){
                dp[index1][index2]=0;
            }
            else{
                if(str1[index1-1]==str2[index2-1]){
                    dp[index1][index2]= 1+dp[index1-1][index2-1];
                    maxi= max(maxi, dp[index1][index2]);
                }
                
                else{
                    dp[index1][index2]=0;
                }
            }
        }
    }
    
    return maxi;
}

//SPACE OPTIMIZATION 2 Array
int lcs(string &str1, string &str2){
    
    int n= str1.length();
    int m= str2.length();
    
    vector<int> dp(m+1, 0), temp(m+1, 0);
    int maxi=0;
    for(int index1=0; index1<=n;index1++){
        for(int index2=0;index2<=m; index2++){
            if(index1==0||index2==0){
                temp[index2]=0;
            }
            else{
                if(str1[index1-1]==str2[index2-1]){
                    temp[index2]= 1+dp[index2-1];
                    maxi= max(maxi, temp[index2]);
                }
                
                else{
                    temp[index2]=0;
                }
            }
        }
        dp=temp;
    }
    
    return maxi;
}
