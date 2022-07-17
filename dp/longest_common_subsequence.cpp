/*https://leetcode.com/problems/longest-common-subsequence/*/


//RECURSION
class Solution {
public:
    
    int f(int index1, int index2, string str1, string str2){
        if(index1<0||index2<0){
            return 0;
        }
        
        if(str1[index1]==str2[index2]){
            return 1+f(index1-1, index2-1, str1, str2);
        }
        
        return max(f(index1-1, index2, str1, str2), f(index1, index2-1,str1, str2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        return f(text1.length()-1, text2.length()-1, text1, text2);
    }
};


//MEMOIZATION
class Solution {
public:
    int f(int index1, int index2, string str1, string str2, vector<vector<int>> &dp){
            if(index1<0||index2<0){
                return 0;
            }

            if(dp[index1][index2]!=-1){
                return dp[index1][index2];
            }

            if(str1[index1]==str2[index2]){
                return 1+f(index1-1, index2-1, str1, str2, dp);
            }

            return dp[index1][index2]=max(f(index1-1, index2, str1, str2, dp), f(index1, index2-1,str1, str2, dp));
        }
        int longestCommonSubsequence(string text1, string text2) {
            vector<vector<int>> dp(text1.length(), vector<int> (text2.length(), -1));
            return f(text1.length()-1, text2.length()-1, text1, text2, dp);
        }
};


//DP
class Solution {
public:
    
    int longestCommonSubsequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int index1=0;index1<=n;index1++){
            for(int index2=0;index2<=m;index2++){
                if(index1==0||index2==0){
                    dp[index1][index2]=0;
                }
                else{
                    if(str1[index1-1]==str2[index2-1]){
                        dp[index1][index2]= 1+dp[index1-1][index2-1];
                    }
                    else{
                        dp[index1][index2]=max(dp[index1-1][index2],dp[index1][index2-1]);

                    }
                }
            }
        }
        return dp[n][m];
    }
};


//SPACE OPTIMIZATION
class Solution {
public:
    
    int longestCommonSubsequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        vector<int> dp(m+1, 0), temp(m+1, 0);
        
        for(int index1=0;index1<=n;index1++){
            for(int index2=0;index2<=m;index2++){
                if(index1==0||index2==0){
                    temp[index2]=0;
                }
                else{
                    if(str1[index1-1]==str2[index2-1]){
                        temp[index2]= 1+dp[index2-1];
                    }
                    else{
                        temp[index2]=max(dp[index2],temp[index2-1]);

                    }
                }
            }
            dp=temp;
        }
        return dp[m];
    }
};
