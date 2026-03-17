//
//  P3307.C
//  practice
//
//  Created by 王钰童 on 2026/3/17.
//
#include <stdio.h>
#include <stdlib.h>
#define P 131


int com(const void *a,const void *b){
    int  va=*(int *)a;
    int  vb=*(int *)b;
    if(va<vb) return -1;
    else return 1;
}

int main(void){
    int N;
    scanf("%d",&N);
    int hash[10005];
    int j;
    for(j=0;j<N;j++){
        char s[1501];
        scanf("%s",s);
        int i=0;
        int key=0;
        while(s[i]!='\0'){
            key+=key*P+(int )s[i];
            i++;
        }
        hash[j]=key;
    }
    qsort(hash,N,sizeof(int),com);
    int count=0;
   
    for(j=1;j<N;j++){
        if(hash[j]!=hash[j-1])
            count++;
    }
    count++;
    printf("%d\n",count);
    
}
