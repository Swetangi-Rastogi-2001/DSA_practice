/*Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?
You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.
For Example
If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.*/


//Recursion
int f(int index, int day, vector<vector<int>> points){
    if(index==0){
        int maxmerit=0;
        for(int i=0;i<=2; i++){
            if(i!=day){
                maxmerit= max(maxmerit, points[index][i]);
            }
        }
        return maxmerit;
    }
    
    int maxmerit=0;
    for(int i=0;i<=2;i++){
        if(i!=day){
            int pts= points[index][i]+f(index-1, i, points);
            maxmerit= max(maxmerit, pts);
        }
    }
    
    return maxmerit;
}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    return f(n-1, 3, points);
    
}


//MEMOIZATION
int f(int index, int day, vector<vector<int>> points, vector<vector<int>> &dp){
    if(index==0){
        int maxmerit=0;
        for(int i=0;i<=2; i++){
            if(i!=day){
                maxmerit= max(maxmerit, points[index][i]);
            }
        }
        return maxmerit;
    }
    if(dp[index][day]!=-1){
        return dp[index][day];
    }
    
    int maxmerit=0;
    for(int i=0;i<=2;i++){
        if(i!=day){
            int pts= points[index][i]+f(index-1, i, points, dp);
            maxmerit= max(maxmerit, pts);
        }
    }
    
    return dp[index][day]=maxmerit;
}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int> (4, -1));
    return f(n-1, 3, points, dp);
    
}


//DP
#include<bits/stdc++.h>
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int> (4, -1));
    
    dp[0][0]= max(points[0][1], points[0][2]);
    dp[0][1]= max(points[0][0], points[0][2]);
    dp[0][2]= max(points[0][0], points[0][1]);
    dp[0][3]= max(points[0][0], max(points[0][1], points[0][2]));
    
    for(int day=1;day<n;day++){
        for(int task=0;task<=3;task++){
            int maxmerit=0;
            for(int i=0;i<=2;i++){
                if(i!=task){
                    int pt= points[day][i]+dp[day -1][i];
                    maxmerit= max(pt, maxmerit);
                }
            }
            dp[day][task]= maxmerit;             
        }
    }
    return dp[n-1][3];
}


//SPACE OPTIMIZATION
#include<bits/stdc++.h>
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> dp(4, 0);
    
    dp[0]= max(points[0][1], points[0][2]);
    dp[1]= max(points[0][0], points[0][2]);
    dp[2]= max(points[0][0], points[0][1]);
    dp[3]= max(points[0][0], max(points[0][1], points[0][2]));
    
    for(int day=1;day<n;day++){
        vector<int> temp(4,0);
        for(int task=0;task<=3;task++){
            int maxmerit=0;
            for(int i=0;i<=2;i++){
                if(i!=task){
                    int pt= points[day][i]+dp[i];
                    maxmerit= max(pt, maxmerit);
                }
            }
            temp[task]= maxmerit;             
        }
        dp=temp;
    }
    return dp[3];
}
