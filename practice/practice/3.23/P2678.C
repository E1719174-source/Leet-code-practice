//二分答案：二分的对象变成了答案本身.什么时候用到二分思想
//1.关键词：求“最大的最小值”或“最小的最大值”。
//2.单调性（最关键）：随着你“猜”的答案变大，实现它的难度（或者需要的代价）也会单调地增加或减少。以跳石头为例：要求的最短距离越长，需要挪走的石头肯定越多。这就是单调性。答案范围确定：你能轻易知道答案的最小值（比如 1）和最大值（比如 L）。
//3.验证容易，求解难：直接求出答案很难，但如果我给你一个确定的数，让你判断“这个数行不行”，你会觉得很简单。
#include <stdio.h>
#include <string.h>
#define MAX 50005


int judge(int curr,int distance[],int N,int M){

    int count=0;
    int j=0;
    for(int i=1;i<=N+1;i++){
        if((distance[i]-distance[j])<curr){
            count++;
        }
        else{
            j=i;
        }
        if(count>M)
            return 0;
    }
    return 1;
}

int main(void){
    int L,N,M;
    scanf("%d %d %d",&L,&N,&M);
    int distance[MAX]={0};
    int i=0;
    distance[0]=0;
    for(i=1;i<=N;i++){
        scanf("%d",&distance[i]);
    }
    distance[N+1]=L;
    
    
    //二分法找的最大的最小距离

    int left,right;
    left=0;
    right=L;
    int maxmin,answer=0;
    do{
        maxmin=(left+right+1)/2;
        if(judge(maxmin,distance,N,M)==1){
            //current maxmin is valiable
            left=maxmin;
            answer=maxmin;
        }
        else{
            //maxmin needs to be smaller
            right=maxmin-1;
           
        }
    }while(left<right);
    printf("%d",answer);
    
    
}
