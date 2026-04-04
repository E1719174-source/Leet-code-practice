//
//  P4170.C
//  practice
//
//  Created by 王钰童 on 2026/4/2.
//区间 DP 特征：
//特征 1：问题可以分解为对一段连续区间的处理。
//特征 2：大区间的答案依赖于切开后的两个小区间的合并。
//特征 3：数据范围 N 通常在 50 到 400 之间（因为 O(N*N*N) 的暴力极限就在这）。
#include <stdio.h>
#include <string.h>
char target[55];
int dp[55][55]={0};


int found_min(int i,int j){
    int k;
    int min=0x3f3f;
    for(k=i;k<j;k++){
        if(min>(dp[i][k]+dp[k+1][j]))
            min=(dp[i][k]+dp[k+1][j]);
    }
    return min;
}
int min(int a,int b){
    if(a>b)
        return b;
    else
        return a;
}


int main(void){
    scanf("%s",target);
    int n=(int)strlen(target);
    for(int i=1;i<n;i++){
        dp[i][i]=1;
        int j=i+1;
        if(target[i-1]==target[j-1])
            dp[i][j]=1;
        else
            dp[i][j]=2;
    }
    dp[n][n]=1;
    for(int k=2;k<n;k++){
        for(int i=1;i<=n;i++){
            int j=i+k;
            if(j>n)
                break;
            else{
                if(target[i-1]==target[j-1]){
                    dp[i][j]=min(dp[i+1][j],dp[i][j-1]);
                }
                else{
                    dp[i][j]=found_min(i,j);
                }
            }
        }
    }
    printf("%d",dp[1][n]);
    
}

