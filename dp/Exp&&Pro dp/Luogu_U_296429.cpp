#include <bits/stdc++.h>
using namespace std;
const int N = 15;
const int INF = 0x3f3f3f3f;
double f[N][N][N][N][5][5];
int A, B, C, D;

// 如果大小王翻出来放1里，则a++,放2里b++,...
void add(int &a, int &b, int &c, int &d, int x) {
    if (x == 1) a++;
    if (x == 2) b++;
    if (x == 3) c++;
    if (x == 4) d++;
}

/*
功能：计算当前状态f(a,b,c,d,x,y)下的期望值
*/
double dfs(int a, int b, int c, int d, int x, int y) {
    // 记忆化搜索
    if (f[a][b][c][d][x][y] > 0) return f[a][b][c][d][x][y];

    // 递归出口：当前状态是否到达目标状态，目标状态的期望值是0
    int ta = a, tb = b, tc = c, td = d;                     // 抄出来
    add(ta, tb, tc, td, x), add(ta, tb, tc, td, y);         // 大王小王会改变四个花色的数量
    if (ta >= A && tb >= B && tc >= C && td >= D) return 0; // 如果条件全满足就是终止状态

    // 当前状态下的剩余牌数量
    int rst = 54 - ta - tb - tc - td;
    if (rst <= 0) return INF; // 还没有完成目标，没有剩余的牌了，无解

    // 当前状态可以向哪些状态转移
    double v = 1;
    if (a < 13) // 黑桃有剩余，可能选出的是黑桃
        v += dfs(a + 1, b, c, d, x, y) * (13 - a) / rst;
    if (b < 13) // 红桃有剩余，可能选出的是红桃
        v += dfs(a, b + 1, c, d, x, y) * (13 - b) / rst;
    if (c < 13) // 梅花有剩余，可能选出的是梅花
        v += dfs(a, b, c + 1, d, x, y) * (13 - c) / rst;
    if (d < 13) // 方块有剩余，可能选出的是方块
        v += dfs(a, b, c, d + 1, x, y) * (13 - d) / rst;

    // 如果小王没有被选出
    if (x == 0)
        v += min(min(dfs(a, b, c, d, 1, y), dfs(a, b, c, d, 2, y)), min(dfs(a, b, c, d, 3, y), dfs(a, b, c, d, 4, y))) / rst;

    // 如果大王没有被选出
    if (y == 0)
        v += min(min(dfs(a, b, c, d, x, 1), dfs(a, b, c, d, x, 2)), min(dfs(a, b, c, d, x, 3), dfs(a, b, c, d, x, 4))) / rst;

    return f[a][b][c][d][x][y] = v;
}

int main() {
    cin >> A >> B >> C >> D;

    double res = dfs(0, 0, 0, 0, 0, 0); // 四种花色、大小王都还没有被抽取

    if (res > INF / 2) // 因为是浮点数，不能用等号判断是不是相等，简单的办法就是INF/2
        puts("-1.000");
    else
        printf("%.3f\n", res);
    return 0;
}
