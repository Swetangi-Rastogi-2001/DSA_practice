/*There is a frog on the 1st step of an N stairs long staircase. The frog wants to reach the Nth stair. HEIGHT[i] is the height of the (i+1)th stair.If Frog jumps from ith to jth stair, the energy lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.In the Frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair. Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.*/


//DP SOLUTION

#include<bits/stdc++.h>
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n);
    dp[0]=0;
    for(int i=1;i<n;i++){
        
        int left= dp[i-1]+abs(heights[i-1]-heights[i]);
        int right=INT_MAX;
        if(i>1){
            right= dp[i-2]+abs(heights[i-2]-heights[i]);
        }
        dp[i]= min(left,right);
        
    }
    
    return dp[n-1];
}

//OPTIMIZED
#include<bits/stdc++.h>
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n);
    dp[0]=0;
    int prev=0;
    int prev2=0;
    int curr=0;
    for(int i=1;i<n;i++){
        curr=prev+abs(heights[i-1]-heights[i]);
        if(i>1)
        curr= min( curr, prev2+abs(heights[i-2]-heights[i]));
        prev2= prev;
        prev=curr;
        
    }
    return curr;
}
