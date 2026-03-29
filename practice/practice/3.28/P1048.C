//
//  P1048.C 0-1背包问题
//  practice
//
//  Created by 王钰童 on 2026/3/28.
//以后见到任何 DP 题，问自己三个问题：
//1.我的存档存什么？（状态定义）：当下在这个时间这个草药最大的价值
//2.我要看哪个旧存档？（状态转移）：（1）当下时间原来的价值（2）减去采新药的时间的时候的价值加上新药的价值
//3.我是不是只看了旧存档，没管未来？（无后效性）：对，只判断这一株采与不采会不会牺牲上一株，如果牺牲了，利大于弊还是弊大于利

//二维->一维的压缩：二维数组：是静态存储了整个线性变换的历史轨迹。一维数组：是动态模拟了线性变换的当前波前（Wavefront）。之所以能压缩，是因为 DP 满足无后效性：一旦第 i 行算完，第 i−1 行就成了“死信息”，不再对未来的 i+1,i+2… 产生独立贡献。在线性代数里，这意味着我们可以不断地把旧向量投影到新向量上，然后擦掉旧向量。

#include <stdio.h>
#include <stdlib.h>


typedef struct herbal {
    int picktime;
    int price;
}herbal;

herbal herbs[105];

int main(void){
    int time, herb_num;
    scanf("%d %d",&time,&herb_num);
    for(int i=1;i<=herb_num;i++){
        scanf("%d %d",&herbs[i].picktime,&herbs[i].price);
    }
    int price_count[105][1005]={0};
    int i,j;
    for(i=1;i<=herb_num;i++){
        for(j=1;j<=time ;j++){
            if(j-herbs[i].picktime<0){
                price_count[i][j]=price_count[i-1][j];
                continue;
            }
            price_count[i][j]=(price_count[i-1][j]>(price_count[i-1][j-herbs[i].picktime]+herbs[i].price)?price_count[i-1][j]:(price_count[i-1][j-herbs[i].picktime]+herbs[i].price));
        }
    }
    printf("%d",price_count[herb_num][time]);
   
}
