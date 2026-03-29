//
//  P1616.C
//  practice
//
//  Created by 王钰童 on 2026/3/28.
//完全背包：选择变成了选上一轮剩下的or 本轮pick time之前时间时刻+现在采的草药的value
//一维压缩+t从0到time：这样比较的valuecount【t-picktime】就是本轮该时刻的最大值^^(另：注意哈，比较是空间上的，外层循环即是草药种类迭代的体现)

#include <stdio.h>

typedef struct herbs{
    int picktime;
    int value;
}herbs;
herbs herb[10005];
long long value_count[10000005]={0};
int main(void){
    int num_herbs,time;
    scanf("%d %d",&time,&num_herbs);
    for(int i=1;i<=num_herbs;i++){
        scanf("%d %d",&herb[i].picktime,&herb[i].value);
    }
    
    for(int i=1;i<=num_herbs;i++){
        for(int t=1;t<=time;t++){
            if(t-herb[i].picktime<0){
                continue;
            }
            value_count[t]=(value_count[t]>(value_count[t-herb[i].picktime]+herb[i].value)?value_count[t]:(value_count[t-herb[i].picktime]+herb[i].value));
            
        }
    }
    printf("%lld",value_count[time]);
}
