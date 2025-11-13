#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
 
const int M = 210;
int wi[M];
int dp[M][M][2];//0回来，1不回来
int n, m;
int len;
 
struct Edge {
    int to, nxt;
} edge[M*2];
 
int head[M];
void add_edge(int u, int v) {
    edge[len].to = v;
    edge[len].nxt = head[u];
    head[u] = len++;
}
 
int vis[M];
 
void dfs(int rt) {
    vis[rt] = 1;
    for(int i = 0; i <= m; i++)
        dp[rt][i][0] = dp[rt][i][1] = wi[rt];
 
    for(int i = head[rt]; i != -1; i = edge[i].nxt) {
        int t = edge[i].to;
        if(vis[t])
            continue;
 
        dfs(t);
        for(int j = m; j >= 1; j--) {
            for(int k = 1; k <= j; k++) {
                /*
                dp[i][j][0]表示从i节点出发最后回到i节点花费最多j步能获得的最大值,
                dp[i][j][1]表示从i节点出发最后不回到i节点花费最多j步能获得的最大值
                dp[root][j][0] = max(dp[root][j-k][0] + dp[son][k-2][0])
                //root->son 和 son->root 共花费2步,j-k是在其他儿子花费的步数
                dp[root][j][1] = max(dp[root][j-k][0] + dp[son][k-1][1])
                dp[root][j][1] = max(dp[root][j-k][1] + dp[son][k-2][0])
                //只需要回到root一次,一种情况是先走其他儿子回到root再走son，
                //另一种情况是先走son这个儿子并回到root再去走其他儿子
                */
                dp[rt][j][0] = max(dp[rt][j][0], dp[rt][j-k][0]+dp[t][k-2][0]);
                dp[rt][j][1] = max(dp[rt][j][1], dp[rt][j-k][0]+dp[t][k-1][1]);
                dp[rt][j][1] = max(dp[rt][j][1], dp[rt][j-k][1]+dp[t][k-2][0]);
            }
        }
    }
}
 
int main() {
    //freopen("data.in", "r", stdin);
    int a, b;
    while(scanf("%d%d", &n, &m) != EOF) {
        memset(dp, 0, sizeof(dp));
        len = 0;
        memset(head, -1, sizeof(head));
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++)
            scanf("%d", &wi[i]);
        for(int i = 1; i <= n-1; i++) {
            scanf("%d%d", &a, &b);
            add_edge(a, b);
            add_edge(b, a);
        }
 
        dfs(1);
        printf("%d\n", max(dp[1][m][0], dp[1][m][1]));
    }
    return 0;
}