
#include <stdio.h>
#include <stdlib.h>

//qsort(base(the address of the array waiting tobe sorted),number(the number of items waiting tobe sorted), cmp(the function of sorting principle:- means a is ahead of b, vise versa))  【cmp must be int cmp(const void *a,const void *b)then compulsorily transfer the variable to the one you try to sort】
//我针对P1803的总结：贪心就是要找到一个当下最优的性质（如本题里的end time），然后吃准了这个性质去寻找最优解。（本题的思考：早结束意味着更多时间去考，即新一轮起始时间更早，因此这个就是最优性质）
//贪心策略（Greedy Choice Property）：即你说的“当下最优的性质”。在本题中，就是“选择结束最早的任务”。
//最优子结构（Optimal Substructure）：你提到的“新一轮起始时间更早”，其实就是通过局部的最优选择，把原问题变成了一个规模更小的、同样可以用贪心解决的子问题。

typedef struct race{
    int start;
    int end;
    
}race;


int cmp(const void *a,const void *b){
    race *a1=(race *)a;
    race *b1=(race *)b;
    return a1->end-b1->end;
}

int main(void){
    race all[1000005];
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d %d",&all[i].start,&all[i].end);
    }
    qsort(all,N,sizeof(race),cmp);
    int end=-1;
    int count=0;
    for(int i=0;i<N;i++){
        if(all[i].start>=end){
            count++;
            end=all[i].end;
        }
    }
    
    printf("%d",count);
}
