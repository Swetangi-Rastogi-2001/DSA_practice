
/*https://leetcode.com/problems/longest-string-chain/*/


class Solution {
public:
    
    
    static bool comp(string &s1, string &s2){
        return s1.length()<s2.length();
    }
    
    bool check(string &s1, string &s2){
        
        if(s1.length()!= s2.length()+1){
            return false;
        }
        
        int first=0, second=0;
        
        while(first<s1.length()){
            
            if(s1[first]==s2[second]){
                first++;
                second++;
            }
            
            else{
                first++;
            }
        }
        
        if(first==s1.length()&&second==s2.length()){
            return true;
        }
        
        return false;
        
    }
    
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n,1);
        
        int maxi=1;
        
        for(int index=1;index<n;index++){
            for(int prev=0;prev<index; prev++){
                if(check(words[index], words[prev])&&dp[index]<dp[prev]+1){
                    dp[index]= dp[prev]+1;
                }
                
            }
            maxi= max(maxi, dp[index]);
        }
        
        return maxi;
    }
};
