//
//  P1216.C
//  practice
//
//  Created by 王钰童 on 2026/3/28.
//状态：num[i][j] 在计算前是原始值，计算后代表“从这一格出发，到底部的最大路径和”。
//转移方程：num[i][j] = num[i][j] + max(num[i+1][j], num[i+1][j+1])。
//无后效性：当你算第 i 层时，你只关心第 i+1 层的结果，而不关心 i+1 层是怎么算出来的。

#include <stdio.h>
#include <stdlib.h>

int num[1001][1001]={0};

int main(void){
    int r;
    scanf("%d",&r);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=i;j++){
            scanf("%d",&num[i][j]);
        }
    }
    
    //start caculate
    for(int i=r-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            int max= (num[i+1][j]>num[i+1][j+1]?num[i+1][j]:num[i+1][j+1]);
            num[i][j]+=max;
        }
    }
    printf("%d",num[1][1]);
    
    
}
