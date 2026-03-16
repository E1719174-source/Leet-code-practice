#include<stdio.h>
#include <string.h>
#include <stdlib.h>


int a[2626][2626]={0};

int main(void){
    int N;
    scanf("%d",&N);
    int answer=0;
    while(N--){
        char city[11];
        char state[3];
        scanf("%*c%s%*c%s",city,state);
        int row_city,col_state;
        row_city = (city[0]-'A') * 26 + (city[1]-'A');
        col_state = (state[0]-'A') * 26 + (state[1]-'A');
        //如果city的前两个字母和state的前两个字母重合，那这个City对应的City也必然在这个state，和题目不符，所以可以直接不考虑
        if(row_city!=col_state){
            a[row_city][col_state]++;}
        //仅仅针对你目前输入的这个city和state，会有多少answer增加
        if(a[col_state][row_city]!=0){
            answer+=a[col_state][row_city];
        }
    }
    printf("%d\n",answer);
    
}

