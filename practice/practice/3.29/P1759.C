//
//  P1759.分组背包，多维限制
//  practice
//
//  Created by 王钰童 on 2026/3/29.
//

#include <stdio.h>

typedef struct tool{
    int we;
    int fo;
    int t;
}tool;
int time_count[105][205][205]={0};
tool tools[105];

int main(void){
    int W,f,n;
    scanf("%d %d %d",&W,&f,&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&tools[i].we,&tools[i].fo,&tools[i].t);
    }
    
    
    int choose[105]={0};

    for(int i=1;i<=n;i++){
        for(int a1=0;a1<=W;a1++){
            for(int b1=0;b1<=f;b1++){
                if(a1>=tools[i].we&&b1>=tools[i].fo&&time_count[i-1][a1][b1]<=(time_count[i-1][a1-tools[i].we][b1-tools[i].fo]+tools[i].t)){
                    time_count[i][a1][b1]=(time_count[i-1][a1-tools[i].we][b1-tools[i].fo]+tools[i].t);
                }
                else
                    time_count[i][a1][b1]=time_count[i-1][a1][b1];
            }
        }
    }
    printf("%d\n",time_count[n][W][f]);
    int a1=W,b1=f;
    //turn back to found if we choose the tool
    for(int i=n;i>0;i--){
        if(a1>=tools[i].we&&b1>=tools[i].fo&&time_count[i][a1][b1]==(time_count[i-1][a1-tools[i].we][b1-tools[i].fo]+tools[i].t)&&time_count[i][a1][b1]!=time_count[i-1][a1][b1]){
            choose[i]=1;
            a1=a1-tools[i].we;
            b1=b1-tools[i].fo;
        }
        
    }
    for(int i=1;i<=n;i++){
        if(choose[i]==1){
            printf("%d ",i);
        }
    }
}

