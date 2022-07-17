/*https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/*/

class Solution {
public:
    int minInsertions(string str1) {
        string str2= str1;
        reverse(str2.begin(), str2.end());
        
        int n=str1.length();
        int m=str2.length();
        
        int maxi=0;
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(int index1=0;index1<=n;index1++){
            for(int index2=0;index2<=m;index2++){
                if(index1==0||index2==0){
                    dp[index1][index2]= 0;
                }
                else{
                    if(str1[index1-1]==str2[index2-1]){
                        dp[index1][index2]= 1+ dp[index1-1][index2-1];
                        maxi= max(maxi, dp[index1][index2]);
                    }
                    else{
                        dp[index1][index2]= max(dp[index1-1][index2], dp[index1][index2-1]);
                    }
                }
            }
        }
        
        return n-maxi;
    }
};
