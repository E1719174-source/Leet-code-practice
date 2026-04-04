//
//  P1063.C
//  practice
//
//  Created by 王钰童 on 2026/4/1.
//


#include <stdio.h>

typedef struct node{
    int head;
    int tail;
}node;
node necklace[405];
long long dp[405][405]={0};

int energy(int i,int j,int k){
    int energy=0;
    //k is the end point (i.head,k.tail) and (k+1.tail,j.tail)...therefore k must greater than i and smaller than j-1
    energy=necklace[i].head*necklace[k].tail*necklace[j].tail;
    return energy;
}

int max(int i,int j){
    int k;
    int max=0;
    for(k=i;k<j;k++){
        if(max<(dp[i][k]+dp[k+1][j]+energy(i,j,k)))
            max=dp[i][k]+dp[k+1][j]+energy(i,j,k);
    }
    return max;
}

int main(void){
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        
        scanf("%d",&necklace[i].head);
        necklace[i-1].tail=necklace[i].head;
    }
    necklace[N].tail=necklace[1].head;
    //copy to deal with loop
    for(int i=N+1;i<=2*N;i++){
        necklace[i]=necklace[i-N];
    }
    for(int i=1;i<=N;i++){
        int j=i;
        dp[i][j]=0;
    }
    for(int k=1;k<N;k++){
        //区间大小
        for(int i=1;i<=2*N;i++){
            int j=i+k;
            if(j>2*N)
                break;
            else{
                dp[i][j]=max(i,j);
            }
        }
    }
    
    int max_energy=0;
    for(int i=1;i<=N;i++){
        if(dp[i][i+N-1]>max_energy)
            max_energy=dp[i][i+N-1];
    }
    printf("%lld",max_energy);
    
    
}
