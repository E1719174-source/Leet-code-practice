//
//  P1090.C
//  practice
//
//  Created by 王钰童 on 2026/3/25.
//
#include <stdio.h>
#include <stdlib.h>


void swap(int *a,int *b){
    int tempt;
    tempt=*a;
    *a=*b;
    *b=tempt;
}

int heap[10005]={0};
int size=0;
void push(int x){
    heap[size++]=x;
    int curr=size-1;
    //parents=(curr-1)/2;
    
    while(curr!=0){
        if(heap[curr]<heap[(curr-1)/2]){
            swap(&heap[curr],&heap[(curr-1)/2]);
            curr=(curr-1)/2;
        }
        else{
            return;
        }
    }
    
}


void pop(){
    //turn the last to the first,the first disappear
    heap[0]=heap[size-1];
    size--;
    int curr=0;
    while(curr*2+1<=size-1){
        int minson,minson_index;
        if(curr*2+2==size){
            if(heap[curr]>heap[curr*2+1])
                swap(&heap[curr],&heap[curr*2+1]);
            return;
        }
        if(heap[curr*2+1]<heap[curr*2+2]){
            minson=heap[curr*2+1];
            minson_index=curr*2+1;
        }
        else{
            minson=heap[curr*2+2];
            minson_index=curr*2+2;
        }
        if(minson<heap[curr]){
            swap(&heap[curr],&heap[minson_index]);
            curr=minson_index;
        }
        else{
            break;
        }
    }
    
    
    
}


int main(void){
    int n;
    scanf("%d",&n);
    int fruit[10005]={0};
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        fruit[i]=num;
    }
    
    long sum=0;
    for(int i=0;i<n;i++){
        push(fruit[i]);
    }
    int sum_now;
    while(size>1){
        sum_now=0;
        sum_now=heap[0];
        pop();
        sum_now+=heap[0];
        pop();
        push(sum_now);
        sum+=sum_now;
    }
    printf("%ld",sum);
   
}




