//
//  luogu.c
//  practice
//
//  Created by 王钰童 on 2026/3/16.
//


#include <stdio.h>
#include <stdlib.h>
#define MAX 1000002
//开始创建哈希map
typedef struct data{
    long key;
    int number;
    struct data *next;
}DATA ;

//key 是原数字，number是这个原数字重复出现的个数，next指向下一个取余后等于原来数组下标的key
DATA* map[MAX]={NULL};


//创建map
void create_hash_map(long x){
    int h=x%MAX;
    DATA *p=map[h];
    if(map[h]==NULL){
        p=(DATA*)malloc(sizeof(DATA));
        p->key=x;
        p->number=1;
        p->next=NULL;
        map[h]=p;
        return;
    }
    else{
        DATA *pre=NULL;
        while(p!=NULL){//便利完整个链表：不可以写成p->next！=NULL
            if(p->key==x){
                p->number++;
                return ;
            }
           pre=p;
            p=p->next;//检查完整个链表
        }
            DATA *ptr;
            ptr=(DATA *)malloc(sizeof(DATA));
            ptr->key=x;
            ptr->number=1;
            ptr->next=NULL;
            pre->next=ptr;
        }
    
}

//查找数据
int search(long x){
    int point=x%MAX;
    DATA *p=map[point];
    if(p==NULL){
        return 0;
    }
    else{
        while(p!=NULL){
            if(p->key==x)
                return p->number;
            p=p->next;
        }
    }
    return 0;
}




int main(void){
    int N;
    int num[200000];
    scanf("%d",&N);
    int sub;
    int i=N;
    int j=0;
    scanf("%d",&sub);
    while(N--){
        
        int number;
        scanf("%d",&number);
        num[j]=number;
        create_hash_map(number);
        j++;
    }
    int answer=0;
    for( j=0;j<i;j++){
        if(search(num[j]+sub)){
            answer+=search(num[j]+sub);
          
        }
    }
    printf("%d",answer);
    return 0;
}
