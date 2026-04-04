//  P3847
//  practice
//1 5 2 3 4
//  Created by 王钰童 on 2026/4/3.
//1、在队伍左或右边加一个人（衣服颜色依要求而定）；
//2、在队伍中任两个人中间插入一个人（衣服颜色依要求而定）；
//3、剔掉一个人；
//4、让一个人换衣服颜色；

#include <stdio.h>


int st[3005];
int dp[3005][3005]={0x3f3f3f};


int min(int a,int b,int c){
    if(a<b){
        if(c<a)
            return c;
        else
            return a;
    }
        else{
            if(b<c)
                return b;
            else
                return c;
        }
}
int main(void){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&st[i]);
    
    for(int i=1;i<n;i++){
        if(st[i]==st[i+1])
            dp[i][i+1]=0;
        else{
            dp[i][i+1]=1;
        }
        dp[i][i]=0;
    }
    dp[n][n]=0;
    for(int k=2;k<n;k++){
        for(int i=1;i<=n;i++){
            int j=i+k;
            if(j>n)
                break;
            else{
                if(st[j]==st[i]){
                    dp[i][j]=dp[i+1][j-1];
                }
                else{
                    dp[i][j]=min(dp[i+1][j],dp[i][j-1],dp[i+1][j-1])+1;
                    
                }
            }
        }
    }
    printf("%d",dp[1][n]);
    
    
}
