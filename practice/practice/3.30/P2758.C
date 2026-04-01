//
//  P1439.C
//  practice
//
//  Created by 王钰童 on 2026/3/29.
//

#include <stdio.h>


int main(void){
    int m;
    scanf("%d",&m);
    int A[100002],B[100002];
    for(int i=0;i<m;i++)
        scanf("%d",&A[i]);
    
    for(int i=0;i<m;i++)
        scanf("%d",&B[i]);
    
    
    //rename B
    int B1[100002];
    int map[100002];
    for(int i=0;i<m;i++){
        map[A[i]]=i;//map array 储存了该下标对应的编号
    }
    for(int i=0;i<m;i++){
        B1[i]=map[B[i]];//将B数组对应的编号一一填入B1数组里
    }
    
    //现在B1数字即使把B数组中A数组内容的出现顺序映射了过来，因此找公共子序列即使找B数组的最长单增子序列
    
    int dp[100002]={0};
    
    int j=0;
    for(int i=0;i<m;i++){
        if(i==0){
            dp[j]=B1[i];
            j++;
        }
        else{
            if(B1[i]>dp[j-1]){
                dp[j]=B1[i];
                j++;
            }
            else{
                //二分找到第一个大于B1【i】的下标
                int l=0,r=j-1;
                while(l<r){
                    int mid=(l+r)/2;
                    if(dp[mid]<B1[i])
                        l=mid+1;
                    else
                        r=mid;
                }
                dp[l]=B1[i];
                    
            }
        }
    }
    printf("%d",j);
    
    
    
}
