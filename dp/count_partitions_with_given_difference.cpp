
/*Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their union is the original array. Let the sum of the elements of these two subsets be ‘S1’ and ‘S2’.
Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or equal to ‘S2’ and the difference between ‘S1’ and ‘S2’ is equal to ‘D’. Since the answer may be too large, return it modulo ‘10^9 + 7’.
If ‘Pi_Sj’ denotes the Subset ‘j’ for Partition ‘i’. Then, two partitions P1 and P2 are considered different if:
1) P1_S1 != P2_S1 i.e, at least one of the elements of P1_S1 is different from P2_S2.
2) P1_S1 == P2_S2, but the indices set represented by P1_S1 is not equal to the indices set of P2_S2. Here, the indices set of P1_S1 is formed by taking the indices of the elements from which the subset is formed.
Refer to the example below for clarification.
Note that the sum of the elements of an empty subset is 0.
For Example :
If N = 4, D = 3, ARR = {5, 2, 5, 1}
There are only two possible partitions of this array.
Partition 1: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
Partition 2: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
These two partitions are different because, in the 1st partition, S1 contains 5 from index 0, and in the 2nd partition, S1 contains 5 from index 2.*/



int mod= 1e9+7;
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    
    if(sum-d<0){
        return 0;
    }
    
    if((sum-d)%2){
        return 0;
    }
    
    int tar= (sum-d)/2;
    vector<int> dp(tar+1, 0), temp(tar+1, 0);
    if(arr[0]==0){
        dp[0]=2;
    }
    else{
        dp[0]=1;
    }
    //arr[0]=0
    if(arr[0]<=tar&&arr[0]!=0){
        dp[arr[0]]=1;
    }
    
    for(int index=1;index<n;index++){
        for(int target=0;target<=tar; target++){
            int nottake= dp[target];
            int take=0;
            if(arr[index]<=target){
                take= dp[target-arr[index]];
            }
            temp[target]= (take+nottake)%mod;
        }
        dp=temp;
    }
    
    return dp[tar];
    
}


