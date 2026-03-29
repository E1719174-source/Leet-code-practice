//
//  P2278.C
//  practice
//
//  Created by 王钰童 on 2026/3/25.


#include <stdio.h>
#include <stdlib.h>

typedef struct task{
    int index;
    int arrive;
    int work;
    int priority;
}task;

task tasklist[15005];
int size;


void swap(task *a,task *b){
    task tempt;
    tempt=*a;
    *a=*b;
    *b=tempt;
}

void push (task x){
    tasklist[size++]=x;
    int curr=size-1;
    while(curr>0){
        if((tasklist[curr].priority>tasklist[(curr-1)/2].priority)||(tasklist[curr].priority==tasklist[(curr-1)/2].priority&&tasklist[curr].arrive<tasklist[(curr-1)/2].arrive)){
            swap(&tasklist[curr],&tasklist[(curr-1)/2]);
            curr=(curr-1)/2;
        }
       
        else break;
        }
        
    }
    



void pop(void) {
    if (size <= 0) return;
    // 1. 把末尾提到堆顶，并减小 size
    tasklist[0] = tasklist[--size];
    if (size == 0) return;

    int curr = 0;
    while (curr * 2 + 1 < size) {
        int left = curr * 2 + 1;
        int right = curr * 2 + 2;
        int target = left; // 假设左孩子更牛

        // 2. 如果有右孩子，且右孩子优先级更高（或同级但更早到）
        if (right < size) {
            if (tasklist[right].priority > tasklist[left].priority ||
               (tasklist[right].priority == tasklist[left].priority && tasklist[right].arrive < tasklist[left].arrive)) {
                target = right;
            }
        }

        
        if (tasklist[target].priority > tasklist[curr].priority ||
           (tasklist[target].priority == tasklist[curr].priority && tasklist[target].arrive < tasklist[curr].arrive)) {
            swap(&tasklist[curr], &tasklist[target]);
            curr = target;
        } else {
            break;
        }
    }
}

int main(void){
    size=0;
    task ptr;
    long long time=0;
    //firstly check the session( non-time ) when tasks are adding
    //the while loop shows time flows. the time will be updated to ptr's arrival
    while(fscanf(stdin,"%d %d %d %d",&ptr.index,&ptr.arrive,&ptr.work,&ptr.priority)==4){
        
        if(size==0){
            push(ptr);
            time=ptr.arrive;
            continue;
        }
        else{
            //session 1:before ptr arrive, what happened:
            //situation of session 1: head task is done before ptr arrived
            while(size>0&&time+tasklist[0].work<=ptr.arrive){
                time+=tasklist[0].work;
                printf("%d %lld\n",tasklist[0].index,time);
                pop();
                
            }
            //session 2:when ptr arrived ,what happened:
            //if their is a head task still working, meaning the arrival of ptr disrupt it
            if(size>0){
               
                //what current head task's work time had changed in work because of time flows
                tasklist[0].work -= (ptr.arrive - time);

            }
            //时间流动的锚定
            time=ptr.arrive;
            push(ptr);
            
        }
           
        }
    
    //then clear the buffer tasks：this is very easy as the priority will never change and we just need to consider timeflow and print them out
    while(size>0){
        time=time+tasklist[0].work;
        printf("%d %lld\n",tasklist[0].index,time);
        pop();
        
    }
    
    
    
}
