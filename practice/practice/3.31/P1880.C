//P1880 转移石子 区间DP
//1. 结构转换：破环成链 (Circle to Chain)
//这是处理“环形”问题的通用手术。痛点：环形结构导致 1 和 n 相邻，传统的线性扫描会断开这对关系。良方：将数组翻倍（a[1...n] 变为 a[1...2n]），并令 a[i+n] = a[i]。要点：任何长度为 n 的滑动窗口 [i, i+n-1] 都对应原环的一种断开方式。最终答案要在所有窗口中取最值。
//2. 状态定义：区间即状态不同于线性 DP 的“前 i 个”，区间 DP 的核心是**“从 i 到 j”**。dp[i][j]：表示合并（或处理）区间 [i,j] 的最优解。初始化：长度为 1 的区间（即 i=j）通常代价为 0 或初始值。
//3. 填表顺序：长度优先 (Length First)这是区间 DP 最容易写错的地方。错误写法：按 i,j 顺序嵌套。这会导致计算大区间时，依赖的小区间还没算出来。正确做法：先枚举区间长度 len。从 len = 2 开始，一直到 len = n。这样保证了当你计算 dp[i][j] 时，它内部的所有分割情况（长度一定小于 len）都已经变成了确定的数值。
//4. 转移核心：寻找最优分割点 (The Split)区间 DP 本质上是在做**“二分合并”**的逆向穷举。逻辑：要把 [i,j] 合并，最后一步一定是两块合二为一。动作：枚举分割点 k∈[i,j−1]，将大问题拆解为：dp[i][j]=best{dp[i][k]+dp[k+1][j]}+Cost(i,j)Cost 的优化：在石子合并中，Cost 是区间总和。通过前缀和将 O(n) 的求和降为 O(1)，是防止 TLE 的关键。




#include <stdio.h>
int St[202];
int dpi[202][202]={1000000};
int dpa[202][202]={0};

int sum(int i,int j){
    int sum=0;
    for(int a=i;a<=j;a++){
        sum+=St[a];
    }
    return sum;
}

int min(int i,int j){
    int k;
    int min=0x3f3f3f;
    for(k=i;k<j;k++){
        if(min>dpi[i][k]+dpi[k+1][j])
            min=dpi[i][k]+dpi[k+1][j];
    }
    return min;
}

int max(int i,int j){
    int k;
    int max=0;
    for(k=i;k<j;k++){
        if(max<dpa[i][k]+dpa[k+1][j])
            max=dpa[i][k]+dpa[k+1][j];
    }
    return max;
}


int main(void){
    int N;
    scanf("%d",&N);
    
    for(int i=1;i<=N;i++)
        scanf("%d",&St[i]);
    
    for(int i=N+1;i<=2*N;i++)
        St[i]=St[i-N];
    
    
    
    for(int i=1;i<=2*N;i++){
        int j=i;
        dpi[i][j]=0;
        dpa[i][j]=0;
    }
    for(int k=1;k<N;k++){
        //k is the measurement of area
        for(int i=1;i<=2*N;i++){
            int j=i+k;
            if(j>2*N)
                break;
            else{
                dpi[i][j]=min(i,j)+sum(i,j);
                dpa[i][j]=max(i,j)+sum(i,j);
                
            }
            
        }
    }
    int min_ans = 1e9, max_ans = 0;
    for (int i = 1; i <= N; i++) {
            if (dpi[i][i + N - 1] < min_ans) min_ans = dpi[i][i + N - 1];
            if (dpa[i][i + N - 1] > max_ans) max_ans = dpa[i][i + N - 1];
        }
    
    printf("%d\n%d", min_ans, max_ans);
    
    
    
}
