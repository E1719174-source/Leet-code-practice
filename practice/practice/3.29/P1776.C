//
// P1776 多重背包：二进制打包：将n个一模一样的背包通过二进制变成log2n个背包，然后再用0，1背包处理
//  practice
//
//  Created by 王钰童 on 2026/3/29.
//


#include <stdio.h>

typedef struct treasure{
    int va;
    int we;
    int m;
    
}node;
typedef struct packed{
    int va;
    int we;
}node2;
node2 trea_packed[100002];

node trea[105];

int main(void){
    int n,W;
    scanf("%d %d",&n,&W);
    for(int i=1;i<=n;i++)
        scanf("%d %d %d",&trea[i].va,&trea[i].we,&trea[i].m);
     //二进制打包形成0，1 背包问题
    int j=1;
    for(int i=1;i<=n;i++){
        if(trea[i].m>1){
            //need pack;
            int k;
            for(k=1;k<=trea[i].m;k*=2){
                trea_packed[j].va=(trea[i].va)*k;
                trea_packed[j].we=(trea[i].we)*k;
                j++;
                trea[i].m-=k;
            }
            if(trea[i].m>0){
                trea_packed[j].va=(trea[i].va)*(trea[i].m);
                trea_packed[j].we=(trea[i].we)*(trea[i].m);
                j++;
            }
        }
        else{
            trea_packed[j].va=(trea[i].va);
            trea_packed[j].we=(trea[i].we);
            j++;
        }
    }
    int new_pack=j-1;
    //开始0，1背包问题
    int price_count[40005]={0};
    for(int i=1;i<=new_pack;i++){
        for(int k=W;k>=trea_packed[i].we;k--){
            if(price_count[k]<(price_count[k-trea_packed[i].we]+trea_packed[i].va)){
                price_count[k]=price_count[k-trea_packed[i].we]+trea_packed[i].va;
            }
        }
    }
    printf("%d",price_count[W]);
    
}
