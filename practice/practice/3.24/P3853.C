//
//P3853
//  practice
//
//  Created by 王钰童 on 2026/3/24.
//
#include <stdio.h>



int mark[100002]={0};


int isanswer(int tempt,int K,int N){
    int i=0;
    int count=0;int add=0;
    while(i<=N+1){
        if(mark[i+1]-mark[i]<=tempt){
            i++;
        }
        else{
            add++;
            count++;
            if(count>K)return 0;
            if((mark[i+1]-mark[i])<=(add+1)*tempt){
                i++;
                add=0;
            }
        }
    }
    return 1;
    
}
int main(void){
    int L,N,K;
    scanf("%d %d %d",&L,&N,&K);
    for(int i=1;i<=N;i++){
        scanf("%d",&mark[i]);
    }
    mark[N+1]=L;
    int answer=L,tempt=L;
    int l=0,r=L;
    do{
        tempt=(l+r+1)/2;
        if(isanswer(tempt,K,N)){
            answer=tempt;
            r=tempt-1;
        }
        else{
            l=tempt;
        }
    }while(l<r);
    printf("%d",answer);
}
