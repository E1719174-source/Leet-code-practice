#include <stdio.h>
#include <string.h>

#define MAX 1000005
typedef unsigned long long ull;

ull h[MAX], p[MAX];
char s[MAX];
ull base = 131;

// 预计算前缀哈希
void prepare(int n) {
    p[0] = 1;
    h[0] = 0;
    for (int i = 1; i <= n; i++) {
        h[i] = h[i - 1] * base + (s[i-1] - 'A' + 1);
        p[i] = p[i - 1] * base;
    }
}

// O(1) 获取子串哈希
ull get_hash(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    if (scanf("%s", s) == 1) {
        int len = strlen(s);
        prepare(len);

        int N;
        scanf("%d", &N);
        while (N--) {
            int l1, r1, l2, r2;
            scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
            
            // 判断长度是否相等且哈希是否相等
            if ((r1 - l1) == (r2 - l2) && get_hash(l1, r1) == get_hash(l2, r2)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}
